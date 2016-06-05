#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 29
#define TRUE       1
#define FALSE      0

int CallTimes = 0;

// ���ɰ��� 'N' ��Ӳ������������( �� 1 öα�� ), ������α��λ�� ...
int CreateRandomCoinWeightArray( int *p, int N )
{
  int i, kt;
  int TrueCoinWeight, FakeCoinWeight;
  int IsStop;

  // ������������� ...
  srand( ( unsigned )time( NULL ) );

  // ��������������ֵ( �� 50 �� 100 ֮�� ) ...
  TrueCoinWeight = 50 + rand( ) % ( 100 - 50 );


  // �������α��λ��( �� 0 ~ N-1 ֮�� ) ...
  kt = rand( ) % N;

  // ����������� ...
  for( i = 0; i < N; i++ )
    if ( i != kt )
      *( p + i ) = TrueCoinWeight;

  // ���� 1 ������������α������ֵ ...
  IsStop = FALSE;
  while( !IsStop )
  {
    FakeCoinWeight = 50 + rand( ) % ( 100 - 50 );
	// ��������������α������ֵ ...
	if ( ( TrueCoinWeight > FakeCoinWeight ) && ( TrueCoinWeight - FakeCoinWeight <= 5 ) )
	{
      IsStop = TRUE;

	  *( p + kt ) = FakeCoinWeight;
	}
  }

  // ����α��λ�� ...
  return kt;
}

// ����������Ӳ�������� ...
int CalcCoinTotalWeight( int ArrayData[], int kb, int ke )
{
  int i, TotalWeight = 0;

  for( i = kb; i <= ke; i++ )
    TotalWeight += ArrayData[ i ];

  return TotalWeight;
}

// ���÷��η��ҵ�α��( �ٶ�α��һ��������ֻ�� 1 ö ) ...
// kb - (��)������߽�( begin )
// ke - (��)�����ұ߽�( end )
int FindFakeCoin( int ArrayData[], int kb, int ke, int AverageWeight)
{
  int LWeight, RWeight;
  int Mid = (kb + ke) / 2;
  int BitLength = ke - kb;;
  // �뽫����Ĵ��벹�����, ʹ���������ȷ���� ...
  // ......
  CallTimes++;
  printf( "< �� %d �β��� : %d> \n", CallTimes,ArrayData[Mid] );
  if(ArrayData[Mid] <= AverageWeight)
    return Mid;
  LWeight = CalcCoinTotalWeight(ArrayData, kb, Mid + BitLength % 2 - 1);
  RWeight = CalcCoinTotalWeight(ArrayData, Mid + 1, ke);
  ke = LWeight < RWeight ? Mid : ke;
  kb = LWeight < RWeight ? kb : Mid + 1;
  FindFakeCoin(ArrayData, kb, ke, AverageWeight);
}
// ####################################################################### //
//                                                                         //
//                           ������������ʼ                              //
//                                                                         //
// ####################################################################### //

void main( void )
{
  int ArrayData[ ARRAY_SIZE ];
  int i, k, FakeCoinPos;
  int AverageWeight;

  // ���ɰ��� 'N' ��Ӳ������������( �� 1 öα�� ), ������α��λ�� ...
  k = CreateRandomCoinWeightArray( ArrayData, ARRAY_SIZE );

  // �������������� ...
  printf( "< ���ɵ�Ӳ����������ֵΪ( �� 1 öα�� ) > : \n" );
  for( i = 0; i < ARRAY_SIZE; i++ )
    printf( "%d  ", ArrayData[ i ] );
  printf( "\n" );
  printf( "< �� %d öΪα�� > ", ( k + 1 ) );
  printf( "\n" );

  // ���÷��η��ҵ�α��λ�� ...
  AverageWeight = CalcCoinTotalWeight(ArrayData, 0, ARRAY_SIZE - 1) / ARRAY_SIZE;
  FakeCoinPos = FindFakeCoin( ArrayData, 0, ARRAY_SIZE - 1,AverageWeight);

  printf( "< �ҵ��� %d öΪα�� > \n", ( FakeCoinPos + 1 ) );
  printf( "\n" );

  // �ȴ��û���������һ������ ...
  system( "PAUSE" );
}
