#include <unistd.h>
 
#include <stdlib.h>
 
int main()
 
{
 
    if ((write(1, "Hello\n", 5)) != 5)
 
        write(2, "error\n", 5);
 
    exit(0);
 
}
