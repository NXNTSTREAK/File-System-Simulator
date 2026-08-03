#pragma once
#include <string>
#include <vector>
#include <optional>
#include "VNode.hpp"

class File : public VNode{

    private:
        std::string content;

    public:
        File(std::string name, std::string content = "") : VNode (std::move(name)), content(std::move(content)){}

        bool is_directory() const override{
            return false;
        }

        size_t get_size() const override{
            return content.size();
        }

        const std::string& read() const{
            return content;             //GETTER;
        }

        void write (std::string new_content){
            content = std::move(new_content);      //SETTER
        }

};