#include "engine/Board.h"
#include <cassert>
namespace FromHeLL
{
    Board::Board()
    {
        m_cBoard = new char*[3];
        m_bState = false;
        m_vCells.reserve(3);
        Reset();
    }

    bool Board::Winner() 
    {
        assert( m_vCells.size() == 0 );
        //CHECK DIAGONAL
        if ( m_cBoard[0][0] == m_cBoard[1][1] &&  m_cBoard[1][1] == m_cBoard[2][2] &&  m_cBoard[2][2] != '-')
        {
            
            m_vCells.push_back( Cell(0,0));
            m_vCells.push_back( Cell(1,1));
            m_vCells.push_back( Cell(2,2));

            m_bState = true;
            return m_bState;
        }
        else if ( m_cBoard[2][0] == m_cBoard[1][1] &&  m_cBoard[1][1] == m_cBoard[0][2]  &&  m_cBoard[0][2] != '-')
        {
            m_vCells.push_back( Cell(2,0));
            m_vCells.push_back( Cell(1,1));
            m_vCells.push_back( Cell(0,2));

            m_bState = true;
            return m_bState;
        }
        
        
        for (size_t i = 0; i < 3; i++)
        {
            //Check Rows
            if ( m_cBoard[i][0] == m_cBoard[i][1] &&  m_cBoard[i][1] == m_cBoard[i][2] &&  m_cBoard[i][2] != '-' )
            {
                m_vCells.push_back( Cell(i,0));
                m_vCells.push_back( Cell(i,1));
                m_vCells.push_back( Cell(i,2));

                m_bState = true;
                break;
            }

            //Check Col
            else if ( m_cBoard[0][i] == m_cBoard[1][i] &&  m_cBoard[1][i] == m_cBoard[2][i]  &&  m_cBoard[2][i] != '-')
            {
                m_vCells.push_back( Cell(0,i));
                m_vCells.push_back( Cell(1,i));
                m_vCells.push_back( Cell(2,i));
                
                m_bState = true;
                break;
            }

            
        }
        
        return m_bState;

    }

    void Board::CleanBoard() 
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
    void Board::Reset( )
    {
        
        CleanBoard();
        m_bState = false;
        m_vCells.clear(); 
      
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
