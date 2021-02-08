#include"head.h"
int main()
{
    int flag=1;
    while((startmenu(),next1(choose('3'),&flag)))
    {
        if(flag)
        {
            printf("\t\t\tnext......\n");
        }
    }
    return 0;
}
