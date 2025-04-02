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
    {
        //std::unique_ptr<Shader> o =  std::make_unique<Shader>(sPath); only on c14
        setupGrid();

    }

    void Renderer::setupGrid() 
    {

        float Vertices[16] = {
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


        glBufferData(GL_ARRAY_BUFFER,sizeof(Vertices), Vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

    }

    void Renderer::RenderGame( Board& board )
    {
        if ( !GetWindow() )
        {
            std::cout << " RENDERER::WINDOW::NULL" <<std::endl;
            return;
        }
        
        //board.PlaceMark(1,1, 'O');
        //board.printBoard();
        SetMouseCallback( GetWindow() );
        if( !getMouseClickedState() )
        {
            setXCursorPos(0.0f);
            setYCursorPos(0.0f);
        }
        else
        {
            std::cout << getXCursorPos() << " " << getXCursorPos() << std::endl;
        }
        setMouseClickedState( false );
        RenderBoard();
    }

    
    void Renderer::RenderBoard()
    {
        
        m_pShader->Use();
        glBindVertexArray(m_uiVAO);
        glDrawArrays(GL_LINES, 0, 8); // there are 8 vertices in 

    }
    
    void Renderer::RenderO(float x, float y)
    {
    }
    
    void Renderer::RenderX(float x, float y)
    {
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


    Renderer::~Renderer()
    {
       
    }
} // namespace FromHeLL
