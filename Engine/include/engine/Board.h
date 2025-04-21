#ifndef BOARD_H
#define BOARD_H
#include "iostream"
#include <vector>

namespace FromHeLL
{
    
    class Cell
        {
            public :
            Cell( int iRow, int iCol  ) : m_iRow(iRow),m_iCol(iCol) {}
            int m_iRow;
            int m_iCol;
        };

    class Board
    {   private :
            char** m_cBoard;
            bool m_bState;
            std::vector<Cell> m_vCells;

        public :
            Board();
            bool PlaceMark(int iRow, int iColumn, char cMark='-');
            inline  char const* const* getBoard()  const { return m_cBoard;};
            void printBoard();
            void Reset();
            void CleanBoard() ;
            bool Winner() ;
            const std::vector<Cell>& WinningMove( ) const { return m_vCells ;  }
            ~Board();

    };
    
} // namespace FromHeLL







#endif