// insertion_sort.c
//--------------------------------------------------------------------------------
//  O(N^2)
//--------------------------------------------------------------------------------

#include <stdio.h>

#define MAXNSIZE 100

//--------------------------------------------------------------------------------
//  main
//--------------------------------------------------------------------------------
int main()
{
  //--------------------
  //  Parameter Declartion
  //--------------------
  int N, i, j;
  int A[MAXNSIZE];

  //----------------------------------------
  //  Input Data
  //----------------------------------------
  scanf("%d", &N);
  for (i=0; i<N; i++) scanf("%d", &A[i]);

  //----------------------------------------
  //  Run Algorithm
  //----------------------------------------
}


//--------------------------------------------------------------------------------
//  trace
//--------------------------------------------------------------------------------
void trace(int A[], int N)
{
  int i, j, val;
  for (i=0; i<N; i++){
    if (i > 0) printf(" ");  // 隣接する要素の間に空白
    print("%d", A[i]);
  }
  printf("\n");
}


//--------------------------------------------------------------------------------
//  Insertion Sort
//--------------------------------------------------------------------------------
void insertionSort



