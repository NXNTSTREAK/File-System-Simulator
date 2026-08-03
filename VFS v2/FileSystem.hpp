#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Directory.hpp"
#include "File.hpp"

class FileSystem{

    private:
        std::shared_ptr<Directory> root;
        std::shared_ptr<Directory> curr_dir;
    
    public:
        FileSystem() 
            : root(std::make_shared<Directory>("root")), curr_dir(root) {}

        void mkdir(const std::string& name){
            auto new_dir = std::make_shared<Directory>(name, curr_dir);
            curr_dir->add_child(new_dir);
        }

        void ls(){
            const auto& children = curr_dir->get_children();

            for (const auto& child : children) {
                std::cout << child->get_name(); 

                if (child->is_directory()) {
                    std::cout << "/";
                }
                std::cout << "\t";
            }
            std::cout << "\n";
        }

        void touch (const std::string& name){
            auto new_file = std::make_shared<File>(name);
            curr_dir->add_child(new_file);
        }

        void cd (const std::string& name){

            if (name == ".."){
                auto parent_ptr = curr_dir->get_parent().lock();

                if(parent_ptr){
                    curr_dir = parent_ptr;
                }
                else{
                    std::cout << "Already in root directory\n";
                }
                return;
            }

            for (const auto& child : curr_dir->get_children()){
                if (child->get_name() == name && child->is_directory()){
                    curr_dir = std::dynamic_pointer_cast<Directory>(child);
                    return;
                }
            }
            
            std::cout << "cd: " << name << ": No such file or directory\n";

        }

};  