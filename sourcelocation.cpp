#include <iostream>

class SourceLocation{
  public:
    SourceLocation(unsigned short _line, unsigned short _row): line(_line), row(_row)
    {}

    unsigned getLine(){
      return line;
    }

    unsigned getRow(){
      return row;
    }

    std::string toString() const{
      return "<line:" + std::to_string(line) + ", row:" + std::to_string(row) + ">";
    }
    

  private:
    unsigned short line = 0;
    unsigned short row = 0;
};