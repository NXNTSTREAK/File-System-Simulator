#include <string>
#include <vector>
#include <memory>
#include "VNode.hpp"


class Directory : public VNode{

    private:
        std::vector <std::shared_ptr<VNode>> children;
        std::weak_ptr <Directory> parent;

    public:
        Directory(std::string name, std::weak_ptr<Directory> parent) : VNode(std::move(name)), parent(std::move(parent)){}
        
        bool is_directory() const override{
            return true;
        }

        size_t get_size() const override{
            return children.size();
        }

        //THE CHILD SETTER

        void add_child(std::shared_ptr<VNode> child){
            children.push_back(std::move(child));
        }

        //THE CHILD GETTER
        const std::vector<std::shared_ptr<VNode>>& get_children () const{
            return children;
        }

        //THE PARENT GETTER
        std::weak_ptr<Directory> get_parent() const{
            return parent;
        }

        
};   
