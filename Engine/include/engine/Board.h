#ifndef BOARD_H
#define BOARD_H
#include "iostream"

namespace FromHeLL
{
    
    class Board
    {   private :
            char** m_cBoard;
            
        public :
            Board();
            bool PlaceMark(int iRow, int iColumn, char cMark='-');
            inline  char const* const* getBoard()  const { return m_cBoard;};
            void printBoard();
            void Reset();
            bool Winner() ;
            ~Board();

    };
    
} // namespace FromHeLL







#endif