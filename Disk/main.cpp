//
// Created by Alessio Ceccherini on 11/05/25.
//

#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    const auto [capacity, free, available] = fs::space(R"(/Users)");
    constexpr int bytesInGB{1024 * 1024 * 1024};

    std::cout << "Capacity: " << capacity / bytesInGB << "GB" << "\nFree: " << free / bytesInGB << "GB\nAvailable: " << available / bytesInGB << "GB" << std::endl;
    return 0;
}