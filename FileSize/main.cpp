//
// Created by gabriele ceccherini on 11/05/25.
//

#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    fs::directory_entry File{R"(/Users/gabrielececcherini/CLionProjects/FileSystem-cpp-tutorial/FileSize/main.cpp)"};
    std::cout << "File Size: " << File.file_size() << " bytes" << std::endl;
    return 0;
}