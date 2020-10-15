#include <iostream>
#include "lexer.cpp"

int main() {
    std::string input = "(2-3.87  *- -> golden (7 +5.765))";

    std::vector<Token>m_tok = Tokenize(input);

    std::cout<<input<<std::endl;
    std::cout<<input.length()<<std::endl;
    for (auto x : m_tok) {
        std::cout << std::left << std::setw(10) << "[" + x.value + "]"<< std::setw(15) << toString(x.type)<< std::setw(10)<< x.location.getLine()<< x.location.getRow()<<std::endl;
        //std::cout <<"["<<x.value<<"]"<< '\t'<<toString(x.type)<< '\t' << x.location.getLine()<< " , "<< x.location.getRow()<<std::endl;
    }


}