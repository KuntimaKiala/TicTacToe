#include "engine/Board.h"

namespace FromHeLL
{
    Board::Board()
    {
        board = new char*[3];
        Reset();
    }

    void Board::Reset()
    {
        for (int i = 0; i < 3; i++)
        {
            board[i] = new char[3] ;
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = '-';
            }
            
        }
        
    }

    bool Board::PlaceMark(int iRow, int iColumn, char cMark /*='-'*/)
    {
        if (board[iRow][iColumn] != '-')
        {
           board[iRow][iColumn] = cMark;
           return true; 
        }
        
        return false;
        
    }

    void Board::printBoard()
    {
        for (int  i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cout << getBoard()[i][j] << " " ;
            }
            std::cout << "\n" << std::endl;
        }
        
    }


    Board::~Board()
    {

        for (int i = 0; i < 3; i++)
        {
            delete [] board[i];
        }
        delete [] board;
    }
} // namespace FromHeLL
