#include "EntryPoint.h"
#include "engine/Engine.h"

int main()
{
    FromHeLL::Engine* pEngine = GetApplication( 500, 500, "TIC TAC TOE" );
    
    if( pEngine->Init() )
    {
        pEngine->Run();
    }
    
    return 0;
}
