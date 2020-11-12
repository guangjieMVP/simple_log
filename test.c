#include "stdio.h"
#include "doge_log.h"

int main(int argc, char **argv)
{
    int d = 10;
    
    DOGE_LOG_INFO( "Hello  world");
    DOGE_LOG_TRACE("Hello girl %s", "pretty");
    DOGE_LOG_WARN("Hello  man  %d", 250);
    DOGE_LOG_ERROR("Hello Boy %f", 23.5);
    
    return 0;    
}
