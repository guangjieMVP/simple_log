#include "doge_log.h"
#include "stdio.h"


void doge_log_lock(void)
{
    printf("lock log\n");
//    pthread_mutex_lock(&mutex);
}

void doge_log_unlock(void)
{
    printf("unlock log\n");
//    pthread_mutex_unlock(&mutex);
}
