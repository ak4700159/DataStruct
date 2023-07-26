#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <stdio.h>


#ifndef DEBUG
#define LOG(...) 
#else
#define LOG(...) do{ printf("LINE:%d/FUNC:%s/FILE:%s:",__LINE__,__func__,__FILE__); printf(__VA_ARGS__); printf("\n"); } while(0)
#endif



#endif
