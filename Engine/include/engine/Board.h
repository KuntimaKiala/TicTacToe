#ifndef BOARD_H
#define BOARD_H
#include "iostream"

namespace FromHeLL
{
    
    class Board
    {   private :
            char** board;
            
        public :
            Board();
            bool PlaceMark(int iRow, int iColumn, char cMark='-');
            inline  char const* const* getBoard()  const { return board;};
            void printBoard();
            void Reset();
            ~Board();

    };
    
} // namespace FromHeLL







#endif