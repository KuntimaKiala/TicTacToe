#include "EntryPoint.h"
#include "engine/Engine.h"

int main()
{
    FromHeLL::Engine* pApp = GetApplication( 500, 500, "TIC TAC TOE" );
    
    pApp->Run();
    return 0;
}
