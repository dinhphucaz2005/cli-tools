#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

std::string toSnakeCase(const std::string& fileName) {
    std::string name, extension;
    size_t dotPos = fileName.find_last_of('.');

    if (dotPos != std::string::npos) {
        name = fileName.substr(0, dotPos);
        extension = fileName.substr(dotPos);
    } else {
        name = fileName;
    }

    // Chèn dấu _ trước chữ in hoa (trừ chữ đầu tiên)
    name = std::regex_replace(name, std::regex("([a-z])([A-Z])"), "$1_$2");

    // Thay thế dấu - thành _
    std::replace(name.begin(), name.end(), '-', '_');
    std::replace(name.begin(), name.end(), ' ', '_');

    // Chuyển tất cả thành chữ thường
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);

    return name + extension;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string input = argv[1];
    std::string convertedName = toSnakeCase(input);
    std::cout << convertedName << std::endl;

    return 0;
}
