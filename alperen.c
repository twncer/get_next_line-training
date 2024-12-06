#include <stdio.h>
int alperen()
{
    static int a = 0;
    a++;
    return (a - 1);
}

int main()
{
    printf("%d", alperen());
    printf("%d", alperen());
    printf("%d", alperen());

}