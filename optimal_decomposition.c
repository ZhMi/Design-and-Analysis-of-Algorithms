#include <stdio.h>
#include <stdlib.h>

int Optimal_decompositon(int Num, int Array[Num])
{
    int i, index = 0;
    int sum = 0;
    int product = 1;
    int Length = 0;
    int surples;

    if(4 >= Num)
    {
       switch(Num)
       {
        case 1: product = 1; break;
        case 3: product = 2; break;
        case 4: product = 3; break;
        default:  printf("û�����ŷֽ�\n"); exit(0);
       }
       printf("%d �����ŷֽ�ĳ˻�Ϊ: %d\n", Num, product);
       exit(0);
    }

    else
    {
        for(i = 2; Num - sum >= i; i++)
        {
            Array[index] = i;
            Length = Length + 1;
            sum += i;
            index += 1;
        }
        surples = Num - sum;

        if(0 != surples)
        {
            if(surples == Array[index-1])
            {
                Array[Length - 1] += 1;
                surples -= 1;
            }
            for(i = 0; i < surples; i ++)
            {
                Array[Length - 1 - i] += 1;
            }

        }
    }
    return Length;
}

int main()
{
    int Num;
    int Array[Num];
    int Length, i;
    int product = 1;

    printf("��������ֽ�����");
    scanf("%d", &Num);
    Length = Optimal_decompositon(Num, Array);
    printf("���ŷֽ⣺");
    for(i = 0; i < Length; i++)
    {
        printf("%d ",Array[i]);
        product *= Array[i];
    }
    printf("�˻�Ϊ: %d", product);
    return 0;
}
