//
// Created by Alessio Ceccherini on 11/05/25.
//

#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {

    // create a folder
    if (fs::create_directory(R"(/Users/gabrielececcherini/CLionProjects/FileSystem-cpp-tutorial/test/custom-dir)")) {
        std::cout << "Directory created" << std::endl;
    } else {
        std::cout << "Directory not created" << std::endl;
    }

    // create nested folders
    if (fs::create_directories(R"(/Users/gabrielececcherini/CLionProjects/FileSystem-cpp-tutorial/test/custom-nested-dir/sub-dir)")) {
        std::cout << "Nested directory created" << std::endl;
    } else {
        std::cout << "Nested directory not created" << std::endl;
    }

    // copy a file to a different directory
    const fs::path source = R"(/Users/gabrielececcherini/CLionProjects/FileSystem-cpp-tutorial/test/helloworld.txt)";
    const fs::path destination = R"(/Users/gabrielececcherini/CLionProjects/FileSystem-cpp-tutorial/test/custom-dir/helloworld.txt)";

    if (fs::copy_file(source, destination,fs::copy_options::skip_existing)) {
        std::cout << "File copied" << std::endl;
    }else {
        std::cout << "File not copied" << std::endl;
    }

    // copy a directory to a different location
    const fs::path source_dir = R"(/Users/gabrielececcherini/CLionProjects/FileSystem-cpp-tutorial/test/custom-dir)";
    const fs::path destination_dir = R"(/Users/gabrielececcherini/CLionProjects/FileSystem-cpp-tutorial/test/custom-nested-dir)";
    fs::copy(source_dir, destination_dir, fs::copy_options::recursive);

    // remove a directory
    const uintmax_t deleted_files_count = fs::remove_all(R"(/Users/gabrielececcherini/CLionProjects/FileSystem-cpp-tutorial/test/custom-nested-dir)");
    std::cout << "Deleted " << deleted_files_count << " files or directories" << std::endl;

    // rename a directory
    const fs::path path_to_rename = R"(/Users/gabrielececcherini/CLionProjects/FileSystem-cpp-tutorial/test/custom-dir)";
    const fs::path new_name = R"(/Users/gabrielececcherini/CLionProjects/FileSystem-cpp-tutorial/test/custom-dir-renamed)";
    fs::rename(path_to_rename, new_name);
    std::cout << "Directory renamed" << std::endl;

    return 0;
}
