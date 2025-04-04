#include "engine/Board.h"

namespace FromHeLL
{
    Board::Board()
    {
        m_cBoard = new char*[3];
        Reset();
    }

    bool Board::Winner() 
    {

        //CHECK DIAGONAL
        if ( m_cBoard[0][0] == m_cBoard[1][1] &&  m_cBoard[1][1] == m_cBoard[2][2] &&  m_cBoard[2][2] != '-')
        {
                return true;
        }
        else if ( m_cBoard[2][0] == m_cBoard[1][1] &&  m_cBoard[1][1] == m_cBoard[0][2]  &&  m_cBoard[0][2] != '-')
        {
                return true;
        }
        
        for (size_t i = 0; i < 3; i++)
        {
            //Check Rows
            if ( m_cBoard[i][0] == m_cBoard[i][1] &&  m_cBoard[i][1] == m_cBoard[i][2] &&  m_cBoard[i][2] != '-' )
            {
                return true;
            }

            //Check Col
            else if ( m_cBoard[0][i] == m_cBoard[1][i] &&  m_cBoard[1][i] == m_cBoard[2][i]  &&  m_cBoard[2][i] != '-')
            {
                return true;
            }

            
        }
        
        return false;

    }
    void Board::Reset()
    {
        for (int i = 0; i < 3; i++)
        {
            m_cBoard[i] = new char[3] ;
            for (int j = 0; j < 3; j++)
            {
                m_cBoard[i][j] = '-';
            }
            
        }
        
    }

    bool Board::PlaceMark(int iRow, int iColumn, char cMark /*='-'*/)
    {
        if( m_cBoard[iRow][iColumn] == '-' )
        {
            m_cBoard[iRow][iColumn] = cMark;
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
            delete [] m_cBoard[i];
        }
        delete [] m_cBoard;
    }
} // namespace FromHeLL
