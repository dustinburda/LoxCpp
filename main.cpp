#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>

using Token = std::string;

class Scanner {
public:
    Scanner() = default;
    Scanner(std::string src);

    std::vector<Token> scanTokens() {
        return tokens_;
    }
private:
    std::vector<Token> tokens_;
};


void run(std::string src) {
    Scanner scanner;
    std::vector<Token> tokens = scanner.scanTokens();

    for (auto token : tokens)  {
        std::cout << token << "\n";
    }

}

void runFile(std::filesystem::path path) {
    std::ifstream  file { path };
    if (!file.is_open())
        throw std::logic_error("Failed to open file!");

    auto size = std::filesystem::file_size(path);

    std::string src;
    file.read(src.data(), static_cast<ptrdiff_t>(size));

    run(src);
}

void runPrompt() {

    std::string line;
    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, line);

        if (line == "exit" || std::cin.eof())
            return;

        run(line);
    }
}



int main(int argc, char** argv) {
    if (argc > 2)
        std::exit(64);
    else if (argc == 2)
        runFile(argv[0]);
    else
        runPrompt();
}
