// hdoj_1096 A+B for Input-Output Practice (VIII)

#include <stdio.h>
int main(void)
{
    int n, m, a, sum, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &m);
        sum = 0;
        for(j = 0; j < m; j ++)
        {
            scanf("%d", &a);
            sum = sum + a;
        }
        printf("%d\n", sum);
        if(i != n - 1)        //è¿éæ¯è¿éé¢çéç¹
            printf("\n");    
    }
    return 0;
}
