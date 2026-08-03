#include <iostream>
#include <string>
#include <sstream>
#include "FileSystem.hpp"

int main() {
    FileSystem fs;
    std::string input_line, command, arg;

    std::cout << "Welcome to your Virtual File System!\n";

    while (true) {
        std::cout << "$ ";
        std::getline(std::cin, input_line);


        std::stringstream ss(input_line);
        ss >> command >> arg;

        if (command == "exit") {
            break;
        }

        else if (command == "ls") {
            fs.ls();
        }

        else if (command == "mkdir") {
           if (arg.empty()) {
               std::cout << "mkdir: missing operand\n";
           } else {
               fs.mkdir(arg);
           }
        }

        else if (command == "touch") {
           if (arg.empty()) {
               std::cout << "touch: missing file operand\n";
           } else {
               fs.touch(arg);
           }
        }

        else if (command == "cd") {
           if (arg.empty()) {
               std::cout << "cd: missing operand\n";
           } else {
               fs.cd(arg);
           }
        }

        else {
            std::cout << "Command not found: " << command << "\n";
        }

        command.clear();
        arg.clear();
    }

    return 0;
}