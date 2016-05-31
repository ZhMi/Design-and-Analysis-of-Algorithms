#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 50


int CalPow(int x, int y)
{
    int num = 1, i;
    for(i = 0; i < y; i++)
        num = num*x;
    return num;
}

int CaculateI(int I[][N], int s, int t, int Num[N])
{
    int i;
    int bitRight = 0;

    I[s][t] = 0;
    for(i = s+t; i > s; i--)
    {
        I[s][t]  = I[s][t] + Num[i-1]*CalPow(10, bitRight);
        bitRight = bitRight + 1;
    }
    return I[s][t];
}

int CaculateMaxI(int maxI[][N], int I[][N], int Num[N], int k, int n)
{
    int i, j, w, Max;

    for(i = 1; i <= n; i++)
    {
        maxI[i][1] = CaculateI(I,0,i,Num);
    }

    for(i = 2; i <= n; i++)
        for(j = 2; j<= k; j++)
        {
            Max = 0;
            for(w = j-1; w<= i; w++)
            {
                I[w][i-w] = CaculateI(I,w,i-w,Num);

                if(maxI[w][j-1]*I[w][i-w] > Max)
                {
                    Max = maxI[w][j-1]*I[w][i-w];
                }
            }
            maxI[i][j] = Max;
        }
        return maxI[n][k];
}

int main()
{
    //int Num[4] = {1,1,2,2};
    int Num[N] = {0};
    int I[N][N] = {0};
    int maxI[N][N] = {0};
    int length = 0, i, k;

    printf("输入数字长度：");
    scanf("%d",&length);
    printf("输入数字：");
    for(i=0; i<length; i++)
        scanf("%d",&Num[i]);
    printf("输入分段数：");
    scanf("%d",&k);

    printf("最大K乘积：%d\n",CaculateMaxI(maxI, I, Num, k, length));

    return 0;
}

