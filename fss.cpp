#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

vector<string> history;

class Node{
public:
    string name;
    bool isFile;
    Node* parent;
    vector<Node*> children;
    Node(string name, bool isFile){
        this->name = name;
        this->isFile = isFile;   
        parent = nullptr;
    }
};

//MAKE DIRECTORY



Node* mkdir(Node* parent, string folderName){
    
    for(auto child : parent->children){
        if(child->name == folderName && !child->isFile){
            // cout<<"Directory already exists\n";
            return child;
        }
        if(child->name == folderName && child->isFile){
            cout<<"error: cannot create directory";
            return nullptr;
        }
    }
    
    Node* newFolder = new Node(folderName, false);
    newFolder->parent = parent;
    
    for(auto it = parent->children.begin(); it != parent->children.end(); ++it){
        if(folderName < (*it)->name){
            parent->children.insert(it, newFolder);
            return newFolder;
        }
    }
    
    //when no larger element found
    parent->children.push_back(newFolder);    
    return newFolder;
    
}

void mkdir_path(Node* currDir, string path){
    
    stringstream ss(path);
    string segment;

    Node* current = currDir;

    while(getline(ss,segment,'/')){
        
        if(segment == "") continue;

        Node* next = mkdir(current, segment);
        
        if(next == nullptr) return;

        current = next;

    }
}


//DELETE TREE

void deleteTree(Node* node){

    for(auto child : node->children){
        deleteTree(child);
    }

    node->children.clear();
    delete node;
}


//REMOVE OR DELETE FILES AND FOLDERS

void rm (Node* currDir, string att, string name){

    for(auto it = currDir->children.begin(); it != currDir->children.end(); ++it){
        Node* child = *it;

        if(child->name == name){

            if(child->isFile){
                delete child;
                currDir->children.erase(it);
                return;
            }

            if(att == "-r"){
                deleteTree(child);
                currDir->children.erase(it);
                return;
            }

            cout<<"Cannot remove directory without '-r'\n";
            return;
        }
    }

    cout<<"File or directory not found\n";
}


//MAKE FILE
void touch(Node* parent, string fileName){
    
    for(auto child : parent->children){
        if(child->name == fileName){
            cout<<"Directory already exists\n";
            return;
        }
    }

    Node* newFile =  new Node(fileName,true);
    newFile->parent = parent;

     for(auto it = parent->children.begin(); it != parent->children.end(); ++it){
        if(fileName < (*it)->name){
            parent->children.insert(it, newFile);
            return;
        }
    }

    parent->children.push_back(newFile);

}

//PRINT ALL FILES AND FOLDERS IN A DIRECTORY
void ls(Node* node){

    if(node->children.empty()) return;
    
    for(auto child : node->children) 
    {
        if(child->isFile)
            cout<<child->name<< "\t";
        else 
            cout<<child->name<<"/\t";

        // ls(child);
    }
    cout<<endl;
}

//CHANGE DIRECTORY

void cd(Node*& currDir, Node* root, string name){

    if(name == ""){
        currDir = root;
        return;
    }

    if(name == ".."){
        if(currDir->parent)
            currDir = currDir->parent;
        return;
    }

    for(auto child : currDir->children){
        if(child->name == name){

            if(child->isFile){
                cout<<"cd: not a directory: "<<name<<endl;
                return;
            }

            currDir = child;
            return;
        }
    }
    cout<<"Directory not found\n";
}


void cd_path(Node*& currDir, Node* root, string path){

    if(path == ""){
        currDir = root;
        return;
    }

    stringstream ss(path);
    string segment;

    while(getline(ss, segment, '/')){

        if(segment == "" || segment == ".")
            continue;

        if(segment == ".."){
            if(currDir->parent)
                currDir = currDir->parent;
            continue;
        }

        cd(currDir, root, segment);
    }
}


//PRINT THE WHOLE HIERARCHY TREE

void tree(Node* node, string prefix = "", bool isLast = true){

    cout << prefix;

    if(prefix != ""){
        cout << (isLast ? "└── " : "├── ");
    }

    cout << node->name << (node->isFile ? "" : "/") << endl;

    for(int i = 0; i < node->children.size(); i++){

        bool lastChild = (i == node->children.size() - 1);

        tree(
            node->children[i],
            prefix + (prefix == "" ? "" : (isLast ? "    " : "│   ")),
            lastChild
        );
    }
}

//PRINT THE WHOLE DIRECTORY

void pwd(Node* currDir){
    
    vector<string> path;

    Node* temp = currDir;

    while(temp){
        path.push_back(temp->name);
        temp = temp->parent;
    }

    for(auto it = path.rbegin(); it != path.rend(); ++it){
        cout<<*it<<"/";
    }
    cout<<endl;
}

// GETTING THE PATH (GETPATH)

string getPath(Node* currDir){

    vector<string> path;

    Node* temp = currDir;

    while(temp != nullptr){
        path.push_back(temp->name);
        temp = temp->parent;
    }

    string resPath = "";
    
    for(auto it = path.rbegin(); it != path.rend(); ++it){
        resPath += *it;
        resPath += "/";
    }

    return resPath;
}


//FIND THE FOLDER OR FILE
bool where(Node* node, string name){

    if(node == nullptr)
        return false;

    bool found = false;

    if(node->name == name){
        string path = getPath(node);
        cout<<path<<endl;
        found = true;
    }

    for(auto child : node->children){
        if(where(child, name))
            found = true;
    }

    return found;
}


//MV FUNCTION
void mv(Node* currDir, string oldname, string newname){

    Node* target = nullptr;
    auto pos = currDir->children.end();

    for(auto it = currDir->children.begin(); it != currDir->children.end(); ++it){
        if((*it)->name == oldname){
            target = *it;
            pos = it;
            break;
        }
    }

    if(target == nullptr){                              //check if directory exists or not, in short, check if the loop was successful
        cout<<"mv: file or directory not found\n";
        return;
    }

    for(auto child : currDir->children){                    //if any file with new name exists
        if(child->name == newname){
            cout << "mv: target name already exists\n";
            return;
        }
    }

    currDir->children.erase(pos);                           //erasing the old target as we have saved it in target

    target->name = newname;

     for(auto it = currDir->children.begin(); it != currDir->children.end(); ++it){     //inserting it in alphabetical order
        if(newname < (*it)->name){
            currDir->children.insert(it, target);
            return;
        }
    }

    currDir->children.push_back(target);
}


//MAIN FUNCTION

int main(){

    cout << "=================================\n";
    cout << "        NXNT's Shell\n";
    cout << "  File System Simulator (C++)\n";
    cout << "Type 'help' to see commands\n";
    cout << "=================================\n\n";
    
    string username = "nxnt";

    Node* root = new Node("root",false);
    Node* currDir = root;
     
    while(true){

        cout << username<<":" << getPath(currDir) << " $ ";
        
        string input;
        getline(cin,input);

        if(input == "")continue;

        history.push_back(input);

        stringstream ss(input);

        string cmd;
        ss >> cmd;

        
        if(cmd == "ls")
            ls(currDir);
        
        else if (cmd == "tree") 
            tree(currDir,0);
        
        else if(cmd == "mkdir"){
            string name;
            ss>>name;

            if(name == ""){
                cout<<"mkdir: folder name required\n";
                continue;
            }

            mkdir_path(currDir,name);
        }
        
        else if (cmd == "where"){
            string name;
            ss>>name;

            if(name == ""){
                cout<<"where: target name required\n";
                continue;
            }

            if(!where(root,name))
                cout<<"No such directory found\n";
        }

        else if(cmd == "cd"){
            string name;
            ss >> name;

            cd_path(currDir, root, name);
        }
        
        else if(cmd == "pwd"){
            pwd(currDir);
        }

        else if(cmd == "touch"){
            string name;
            ss >> name;

            if(name == ""){
                cout<<"touch: file already exists\n";
                continue;
            }

            touch(currDir, name);
        }

        else if(cmd == "exit"){
            deleteTree(root);
            break;
        }

        else if(cmd == "rm"){
            string arg1, arg2;
            ss >> arg1 >> arg2;

            if(arg1 == "-r")
                rm(currDir, arg1, arg2);
            else
                rm(currDir, "", arg1);
        }

        

        else if(cmd == "echo"){

            string text;
            getline(ss, text);

            if(text.size() > 0 && text[0] == ' '){
                text.erase(0,1);
            }

            cout << text << endl;
        }

        else if(cmd == "history"){

        for(int i = 0; i < history.size(); i++){
            cout<<i+1<<"  "<<history[i]<<endl;
        }
    }

        else if (cmd == "whoami"){
            cout<<username<<endl;
        }

        else if(cmd == "clear" || cmd == "cls"){
            system("clear");
        }

        else if(cmd == "help"){

            cout << "NXNT's File System Simulator\n";
            cout << "---------------------------------\n";
            cout << "mkdir <dir>        : create directory\n";
            cout << "touch <file>       : create file\n";
            cout << "rm <file>          : remove file\n";
            cout << "rm -r <dir>        : remove directory recursively\n";
            cout << "mv <old> <new>     : rename file or directory\n";
            cout << "cd <dir>           : change directory\n";
            cout << "ls                 : list contents of current directory\n";
            cout << "tree               : show directory tree\n";
            cout << "pwd                : print current directory path\n";
            cout << "where <name>        : search for file or directory in tree\n";
            cout << "echo <text>        : print text\n";
            cout << "whoami             : show current user\n";
            cout << "clear              : clear the screen\n";
            cout << "history            : show command history\n";
            cout << "help               : show this help menu\n";
            cout << "exit               : exit the shell\n";
        }

        else if(cmd == "mv"){
            string oldname, newname;
            ss >> oldname >> newname;

            if(oldname == "" || newname == ""){
                cout << "mv: missing operand\n";
                continue;
            }

            mv(currDir, oldname, newname);
        }

        else if(cmd == "help"){

            cout << "NXNT's File System Simulator\n";
            cout << "---------------------------------\n";
            cout << "mkdir <dir>        : create directory\n";
            cout << "touch <file>       : create file\n";
            cout << "rm <file>          : remove file\n";
            cout << "rm -r <dir>        : remove directory recursively\n";
            cout << "mv <old> <new>     : rename file or directory\n";
            cout << "cd <dir>           : change directory\n";
            cout << "ls                 : list contents of current directory\n";
            cout << "tree               : show directory tree\n";
            cout << "pwd                : print current directory path\n";
            cout << "where <name>        : search for file or directory in tree\n";
            cout << "echo <text>        : print text\n";
            cout << "whoami             : show current user\n";
            cout << "clear              : clear the screen\n";
            cout << "history            : show command history\n";
            cout << "help               : show this help menu\n";
            cout << "exit               : exit the shell\n";
        }


        else  
            cout<<cmd<<": No such command found"<<endl;
    } 

    return 0;
    
}



