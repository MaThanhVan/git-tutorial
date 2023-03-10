#include <stdio.h>
#include <stdarg.h>
#include <math.h>


void tong(int sum, ...)
{
    int flag = 0;
    va_list ptr;
    //flag=*ptr;
    va_start(ptr, sum);

    for(int i = 0; i < sum; i++)
    {
        if (ceil(flag) == floor(*ptr))
        {
            
            printf("i = %d\n", va_arg(ptr, int));
        }
        else{
            printf("i = %.2f\n", va_arg(ptr, double));
        }
        
    }
    va_end(ptr);
    return flag;
}

/// @brief 
/// @param argc 
/// @param argv 
/// @return 
int main(int argc, char const *argv[])
{
    tong(5, 7, 2, 8, 6, 9.5);
   
    return 0;
}

