//
// Created by alessio ceccherini on 11/05/25.
//

#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    const fs::directory_entry dir {R"(/Users/gabrielececcherini/CLionProjects/FileSystem-cpp-tutorial)"};
    if (dir.exists()) {
        std::cout << "The location exists";
    }

    if (dir.is_directory()) {
        std::cout << "\nIt is a directory";
    }

    if (!dir.is_regular_file()) {
        std::cout << "\nIt is not a file";
    }
    return 0;
}
