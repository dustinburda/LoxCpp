#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "../include/Error.h"
#include "../include/Scanner.h"

void run(std::string src) {
    Scanner scanner {src} ;
    std::vector<Token> tokens = scanner.scanTokens();

    for (auto token : tokens)  {
        std::cout << token.toString() << "\n";
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

    if (hadError)
        std::exit(65);
}

void runPrompt() {

    std::string line;
    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, line);

        if (line == "exit" || std::cin.eof())
            return;

        run(line);

        hadError = false;
    }
}


#include "../include/ExprPrinter.h"
#include "../include/Expression.h"

#include "../include/Binary.h"
#include "../include/Grouping.h"
#include "../include/Literal.h"
#include "../include/Unary.h"



int main(int argc, char** argv) {
    auto expr_ptr = std::make_shared<Binary>(
            std::make_shared<Unary>(
                std::make_shared<Literal>(123),
                Token(TokenType::MINUS, "-", "-", 1)
            ),
            Token(TokenType::STAR, "*", "*", 1),
            std::make_shared<Grouping>(
                std::make_shared<Literal>(45.67)
            ));
    ExprPrinter printer;
    std::cout << printer.print(expr_ptr.get());

//    if (argc > 2)
//        std::exit(64);
//    else if (argc == 2)
//        runFile(argv[0]);
//    else
//        runPrompt();
}
