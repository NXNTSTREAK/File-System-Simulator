#pragma once
#include <string>
#include <vector>




class VNode{
    
    protected:
    std::string name;
    
    public:
    VNode(std::string name) : name(std::move(name)){}
    
    virtual ~VNode() = default;
    
    virtual bool is_directory() const = 0;      
    
    virtual size_t get_size() const = 0;
    
    const std::string& get_name() const {
        return name;
    }
};


//A VNode is just a blank rulebook. It says: "I don't know if I'm a File or a Directory. But whatever I am, I promise I will have a Name, I will know my Size, and I will tell you if I'm a directory."

// const = 0 means it is a blueprint and the classes that will inherit this Abstract class will use these functions according to their needs.

//virtual is C++'s way of saying: "Don't just look at the label on the box; open the box and see what is actually inside."