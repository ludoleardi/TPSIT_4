#include <stdio.h>
#include <stdio.h>

int main()
{
    int v[10] = {9, 2, 4, 7, 6, 0, 3, 1, 5, 8};
    int *p = v;
    int tmp;

    for(int i = 0; i < 9; i++)
    {
        for(int k = 0; k < 9 - i; k++)
        {
            if(*p > *(p + 1))
            {
                tmp = *p;
                *p = *(p+1);
                *(p+1) = tmp;
            }
            p = p + 1;
        }
        p = v;
    }
    printf("Ordinamento: ");

    p = v;
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", *p);
        p = p + 1;
    }

}