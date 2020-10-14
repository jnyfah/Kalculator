#include <iostream>
#include "lexer.cpp"

int main() {
    std::string input = "(2-3.87  *- golden (7 +5.765))";

    std::vector<Token>m_tok = Tokenize(input);

    for (auto x : m_tok) {
        std::cout <<"["<<x.value<<"]"<< '\t'<<toString(x.type)<<std::endl;
    }


}