#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

/*
【测试数据要求】
（1）A = fxpimu  B = xwrs  d( A, B ) = 5
（2）A = abc  B = cba  d( A, B ) = 2
（3）A = stot  B = stop  d( A, B ) = 1
（4）A = cd  B = abcb  d( A, B ) = 3
*/

int Min(int x, int y, int z)
{
    return ((x < y)?x : y) < z ? ((x < y)?x : y) : z;
}

int CalEditLength(int m,int n,char *A,char *B,int d[][N])
{
    int i, j;

    for (i = 1; i <= m; i++)
        d[i][0] = i;
    for (j = 1; j <= n; j++)
        d[0][j] = j;

    for (i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
        {
            if(A[i-1] == B[j-1])
            {
                d[i][j] = d[i-1][j-1] + 0;
            }
            else
            {
                d[i][j] = Min(d[i][j-1]+1,d[i-1][j]+1,d[i-1][j-1]+1);
            }
        }
    return d[m][n];
}

int main()
{
    char A[N], B[N];
    int m, n;
    int d[N][N] = {0};
    int i, j;

    printf("输入源字符串A:");
    scanf("%s",A);
    printf("输入目的字符串B:");
    scanf("%s",B);

    m = strlen(A);
    n = strlen(B);

    if(m == 0 || n == 0)
        printf("A--->B 的编辑距离为：%d\n",(m > n ? m : n));
    else
        printf("A--->B 的编辑距离为：%d\n",CalEditLength(m, n, A, B, d));
    return 0;
}


