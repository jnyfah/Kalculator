#include <regex>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

#include "sourcelocation.cpp"


enum class LexerTokenType {

    ParenOpen,
    ParenClose,
    FloatToken,
    IntToken,
    VarToken,

    PlusToken,
    MinusToken,
    MultiplyToken,
    DivideToken,

    ArrowToken,
    SemiColonToken,
    Space,
    Tab,
    NewLine,
    Eof,

    unknown

};


struct Token {
    std::string value;
    LexerTokenType type;
   SourceLocation location;
};



Token tokenizeCharacter(std::string str, unsigned short current, unsigned short row ){
    if(str =="("){
        Token m_token{str, LexerTokenType::ParenOpen, {current,row}};
        return m_token;

    } else if(str ==")") {
        Token m_token{str, LexerTokenType::ParenClose, {current,row}};
        return m_token;

    } else if(str =="+") {
       Token m_token{str, LexerTokenType::PlusToken, {current,row}};
        return m_token;

    } else if(str == "-") {
        Token m_token{str, LexerTokenType::MinusToken, {current,row}};
        return m_token;

    } else if(str == "*") {
        Token m_token{str, LexerTokenType::MultiplyToken, {current,row}};
        return m_token;

    } else if(str == "/"){
        Token m_token{str, LexerTokenType::DivideToken,{current,row}};
        return m_token;

    } else if(str == ";") {
        Token m_token{str, LexerTokenType::SemiColonToken, {current,row}};
        return m_token;

    } else if(str == "*") {
        Token m_token{str, LexerTokenType::MultiplyToken, {current,row}};
        return m_token;

    }else if(str == "/") {
        Token m_token{str, LexerTokenType::DivideToken, {current,row}};
        return m_token;

    } else {
        Token m_token{str, LexerTokenType::unknown, {current,row}};
        return m_token;
    }
}

const char* toString(LexerTokenType t){

    switch(t) {
    case LexerTokenType::ParenOpen:
        return "ParenOpen";
    case LexerTokenType::ParenClose:
        return "ParenClose";
    case LexerTokenType::FloatToken:
        return "FloatToken";
    case LexerTokenType::IntToken:
        return "IntToken";
    case LexerTokenType::VarToken:
        return "VarToken";

    case LexerTokenType::PlusToken:
        return "PlusToken";
    case LexerTokenType::MinusToken:
        return "MinusToken";
    case LexerTokenType::MultiplyToken:
        return "MultiplyToken";
    case LexerTokenType::DivideToken:
        return "DivideToken";

    case LexerTokenType::ArrowToken:
        return "ArrowToken";
    case LexerTokenType::SemiColonToken:
        return "SemiColonToken";
    case LexerTokenType::Space:
        return "Space";
    case LexerTokenType::Tab:
        return "Tab";
    case LexerTokenType::NewLine:
        return "NewLine";
    case LexerTokenType::Eof:
        return "Eof";

    case LexerTokenType::unknown:
        return "unknown";
    default:
        break;

    }
    return "<<BAD TYPE>>";
}






std::vector<Token>Tokenize(std::string input){
    unsigned short current  = 0;
    unsigned short row =0;
    unsigned short location = 0;
    std::string temp;
    int y;
    std::vector<Token>m_tok;

    while(current < input.length()) {

        if (std::isdigit(input[current])) {
            static const std::regex intRegex{ R"(\d+)"};

            temp = input[current];
            location = current;
            current++;

            while(std::isdigit(input[current]) || input[current] == '.') {
                temp += input[current];
                current++;
            }
            if (std::regex_match(temp, intRegex)) {
                m_tok.push_back({temp, LexerTokenType::IntToken, {location,row}});
            }
            else{
                m_tok.push_back({temp, LexerTokenType::FloatToken, {location,row}});
            }
        } else if(std::isalpha(input[current])){
            temp = input[current];
            location = current;
            current++;   
            while(std::isalpha(input[current]) || input[current] == '_') {

                temp += input[current];
                current++;
            }
             m_tok.push_back({temp, LexerTokenType::VarToken, {location ,row}});

        } else if(input[current] == ' '){
            temp = input[current];
            location = current;
            current++;   
            while(input[current] == ' ') {

                temp += input[current];
                current++;
            }
             m_tok.push_back({temp, LexerTokenType::Space, {location ,row}});
           
           
        } else{
            temp = input[current];
            if((input[current] == '-') && (input[current +1] == '>')){
                m_tok.push_back({"->", LexerTokenType::ArrowToken, {current ,row}});
                current+=2;
            }else{
               m_tok.push_back(tokenizeCharacter(temp, current , row));
               current++;
            }
            
        }

    }

    return m_tok;

}






