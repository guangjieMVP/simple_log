/**********************************************************************
  * @file:        xxx.c
  * @author:      guangjieMVP
  * @version:     v1.00.00
  * @date:        2020-xx-xx
  * @github:      https://github.com/guangjieMVP
  * @brief: 
************************************************************************/
#include "doge_log.h"

void doge_log_output(doge_log_level_t level, const char * file, int line, char *str)
{
   printf("%s %s %d\n", str, file, line);
}