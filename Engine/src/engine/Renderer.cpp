#include "engine/Renderer.h"
#include "engine/Board.h"


namespace FromHeLL
{


    float Renderer::m_fXCursorPos=0.f;
    float Renderer::m_fYCursorPos=0.f;
    bool  Renderer::bIsMouseCliked = false;

    Renderer::Renderer(const String& sPath)
    : m_pShader( new Shader( sPath ) )
    , m_uiVBO(0)
    , m_uiVAO(0)
    , m_iWidth(0)
    , m_iHeight(0)
    , m_fxPos(0.0f)
    , m_fyPos(0.0f)
    , m_iRow(0)
    , m_iCol(0)
    , m_cPlayer('X')
    {
        //std::unique_ptr<Shader> o =  std::make_unique<Shader>(sPath); only on c14
        setupGrid();

    }

    void Renderer::setupGrid() 
    {

        float BoardVertices[16] = {
            // Vertical lines
            -0.33f,  1.0f,   -0.33f, -1.0f, 
             0.33f,  1.0f,    0.33f, -1.0f,  
            // Horizontal lines
            -1.0f,  0.33f,    1.0f,  0.33f, 
            -1.0f, -0.33f,    1.0f, -0.33f 
                             };

        glGenVertexArrays(1, &m_uiVAO);
        glGenBuffers(1, &m_uiVBO);

        glBindVertexArray(m_uiVAO);
        glBindBuffer(GL_ARRAY_BUFFER, m_uiVBO);


        glBufferData(GL_ARRAY_BUFFER, sizeof(BoardVertices), BoardVertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

    }

    void Renderer::RenderGame( Board& oBoard, char& cPlayer )
    {
        if ( !GetWindow() )
        {
            std::cout << " RENDERER::WINDOW::NULL" <<std::endl;
            return;
        }
        
        ResetBoard( oBoard, cPlayer );
        SetMouseCallback( GetWindow() );
        if( !getMouseClickedState() )
        {
            setXCursorPos(0.0f);
            setYCursorPos(0.0f);
            ResetNDCoordinate();
        }
        else
        {
            NormalizedDeviceCoordinate() ;
            std::cout <<" NDC :("<< m_fxPos << " " << m_fyPos <<")"<< std::endl;
            int iCol= static_cast<int>( std::floor(  (m_fxPos + 1.0f)*3.0/2.0f  ) );
            int iRow = static_cast<int>( std::floor(  -(m_fyPos - 1.0f)*3.0/2.0f  ) );
            std::cout <<"Grid :("<< iRow << " " << iCol <<")"<< std::endl;
            oBoard.PlaceMark( iRow, iCol, cPlayer);

            if( cPlayer == 'X' )
                cPlayer = 'O';
            else 
                cPlayer = 'X';

            oBoard.printBoard();
            
        }
        
        RenderXandOs( oBoard );
        RenderBoard();
        setMouseClickedState( false );
    }

    void Renderer::RenderXandOs( const Board& oBoard ) 
    {

            const auto& grid = oBoard.getBoard();
            for (size_t row = 0; row < 3; row++)
            {
                for (size_t col = 0; col < 3; col++)
                {   
                    if ( grid[row][col] == '-')
                    {
                        continue;
                    }
                    else if ( grid[row][col] == 'X')
                    {
                        glm::vec2 vPos = GetCellPosition( row, col );
                        RenderX(vPos.x, vPos.y);
                    }
                    else if ( grid[row][col] == 'O')
                    {
                        glm::vec2 vPos = GetCellPosition( row, col );
                        RenderO(vPos.x, vPos.y);
                    }
                }
                
            }
            
    }
    glm::vec2 Renderer::GetCellPosition( int row, int col ) const
    {
        float ratio = 2.0f/3.0f;
        float x = -1.0f + static_cast<float>(col) * ratio;
        float y =  1.0f - static_cast<float>(row) * ratio;
        return glm::vec2(x,y);
    }

    void Renderer::ResetNDCoordinate()
    {
        m_fxPos = 0.0;
        m_fyPos = 0.0;
        m_iRow = 0;
        m_iCol = 0;
    }

    void Renderer::NormalizedDeviceCoordinate() 
    {
        m_fxPos = -1.0f  + 2.0f*getXCursorPos()/(float)m_iWidth;
        m_fyPos =  1.0f  - 2.0f*getYCursorPos()/(float)m_iHeight;
        
    }
    void Renderer::RenderBoard()
    {
        
        m_pShader->Use();
        glBindVertexArray(m_uiVAO);
        glDrawArrays(GL_LINES, 0, 8); // there are 8 vertices in 

    }
    
    void Renderer::RenderO(float x, float y)
    {
       
        constexpr unsigned int iNbSegments = 30;
        constexpr float fDelta    = 0.05f;
        constexpr float fRadius = 1.0f/3.0f;
        float OVertices[iNbSegments * 2];
        
        for ( size_t i = 0; i < iNbSegments; i++ )
        {
            glm::vec2 vCenter(x + fRadius, y - fRadius ) ;
            double fAngle = 2.0f * M_PI * (float)i /(float)iNbSegments;
            OVertices[i*2] = vCenter.x + (fRadius  - fDelta )* std::cos( fAngle ); 
            OVertices[i*2+1] = vCenter.y + (fRadius  - fDelta ) * std::sin( fAngle );
        }

        GLuint VAO, VBO ;
        glCreateVertexArrays(1, &VAO);
        glCreateBuffers(1,&VBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, sizeof(OVertices), OVertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0,2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void *)0 );
        glEnableVertexAttribArray(0);  

        m_pShader->Use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_LINE_LOOP, 0, iNbSegments );

    }
    
    void Renderer::RenderX(float x, float y)
    {
        //std::cout <<"reNDC :("<< x << " " << y <<")"<< std::endl;
        //std::cout << "\n" <<std::endl;

        constexpr float fDelta    = 0.05f;
        constexpr float fCellSize = 2.0f/3.0f;

        float XVertices[]= { 
                                x + fDelta, y - fDelta, 
                                x + fCellSize -fDelta, y - fCellSize + fDelta,
                                x + fCellSize -fDelta, y - fDelta,
                                x + fDelta, y - fCellSize + fDelta,
                           };


        GLuint VAO, VBO;
        glCreateVertexArrays(1, &VAO);
        glCreateBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer( GL_ARRAY_BUFFER, VBO);
        glBufferData( GL_ARRAY_BUFFER, sizeof(XVertices), XVertices, GL_STATIC_DRAW );
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,2*sizeof(float) , (void*)0);
        glEnableVertexAttribArray(0);  
        
        m_pShader->Use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_LINES, 0, 4); // there are 4 vertices in 
        
    }
    
    void Renderer::SetWindowSize(int iWidth, int iHeight)
    { 
        if (this !=NULL && this->m_pShader != NULL) 
        { 
            m_iWidth =  iWidth; 
            m_iHeight = iHeight;
        } 
    }
    void Renderer::SetMouseCallback(GLFWwindow* pWindow) {
        // Set mouse button callback
        glfwSetMouseButtonCallback( pWindow, MouseButtonCallback );
    }
    
    void Renderer::MouseButtonCallback(GLFWwindow* pWindow, int button, int action, int mods) 
    {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            // Get mouse position when the left mouse button is clicked
            double xpos, ypos;
            glfwGetCursorPos(pWindow, &xpos, &ypos);
            
            // Call the mouse click handler
            Renderer* renderer = static_cast<Renderer*>(glfwGetWindowUserPointer(pWindow));
            renderer->HandleMouseClick(xpos, ypos);
        }
        
    }
    
    void Renderer::HandleMouseClick(double xpos, double ypos)
    {
        setXCursorPos( xpos );
        setYCursorPos( ypos );
        setMouseClickedState( true );
        
    }

    void Renderer::ResetBoard( Board& oBoard, char& cPlayer  )
    {

        GLFWwindow* pWindow = GetWindow();
        
        if( glfwGetKey( pWindow, GLFW_KEY_SPACE ) == GLFW_PRESS )
        {
            oBoard.Reset();
            cPlayer = 'X';
        }
        else if ( oBoard.Winner() )
        {
            

            if (cPlayer == 'X')
            {
                cPlayer = 'X';
            }
            else if (cPlayer == 'O')
            {

                cPlayer = 'O';
            }
            oBoard.Reset();
        }
        

    }    Renderer::~Renderer()
    {
       
    }
} // namespace FromHeLL
