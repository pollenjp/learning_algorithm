// d_static_sushi__file_io.c
//--------------------------------------------------------------------------------
//  O(n^3) = O(n) x O(n) x (O(n)+O(n))
//--------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

//--------------------
//  file open
//--------------------
#define LINESIZE 256     // max string per line
#define INFILENAME "../data/sampleIn1"  // input file name
//--------------------
//  Solve
//--------------------
#define NSIZE    100000

int main()
{
  //----------------------------------------
  //  Variable Declaration
  //----------------------------------------
  //--------------------
  //  file open
  //--------------------
  FILE    *fp;
  char    buf[256]; // バッファサイズを指定する
  //--------------------
  //  Solve
  //--------------------
  // signed long int (8 Byte):
  //    - 2^(4*8) > 10^9
  // signed long long int (16 Byte):
  //    - 2^(8*8) > 10^19
  signed long int n;       // 1 <= N < 10^5
  signed long long int c;          // 2 <= C < 10^14
  signed long long int x[NSIZE],
                       oa,
                       ob;   // 1 <= x_i < x_j < C < 10^14 (i<j)
  signed long int v[NSIZE];        // 1 <= v_i <= 10^9
  signed long long int calorie,
                       init_calorie = 0,
                       max_calorie = 0,
                       answer;   // 2 <= N*vmax < 10^14

  x[0] = 0;
  v[0] = 0;

  //----------------------------------------
  //  Input - Scan
  //----------------------------------------
  // file open
  fp = fopen( INFILENAME, "r" );
  if( fp == NULL ) {
    printf( "ERROR: file can't be opened." );
    exit(1);
  }

  fgets( buf, sizeof(buf), fp );
  if( sscanf( buf, "%li %llu", &n, &c ) != 2 ) {
    printf( "WARNING: format does not match.\n" );
  }
  printf("%li %llu\n", n, c);

  for (signed int i = 1; i <= n; i++){
    fgets( buf, sizeof(buf), fp );
    if( sscanf( buf, "%llu %li", &x[i], &v[i] ) != 2 ) {
      printf( "WARNING: format does not match.\n" );
      exit(1);
    }
    printf("%llu %li\n", x[i], v[i]);
    /**  preprocess  **/
    if (x[i] == 0){
      init_calorie += v[i];
      i--;
      n--;
    }
  }
  fclose( fp );


  //--------------------------------------------------------------------------------
  // main
  //--------------------------------------------------------------------------------
  for (signed long int i1 = 0; i1 <= n; i1++){   // O(n)
    oa = x[i1];  // OA
    for (signed long int i2 = i1+1; i2 <= n+1; i2++){    // O(n)
      ob = (c- x[i2 % (n+1)]) % c;  // OB
      calorie = 0;  // init calorie
      printf("calorie : %llu\n", calorie);

      // v_1 + v_2 + ... + v_a
      for (signed long int i3 = 0; i3 <= i1; i3++){    // O(n)
        calorie += v[i3];
        printf("calorie(v_1 + ... + v_a) : %llu\n", calorie);
      }
      // v_b + ... + v_n
      for (signed long int i4 = i2; i4 <= n+1; i4++){    // O(n)
        calorie += v[i4 % (n+1)];
        printf("calorie(v_b + ... + v_n) : %llu\n", calorie);
      }

      // Compare "2OA + OB" and "OA + 2OB"
      if (oa < ob){             // 2OA + OB < OA + 2OB
        calorie -= 2*oa + ob;
      } else {                  // 2OA + OB > OA + 2OB
        calorie -= oa + 2*ob;
      }

      // Update max_calorie
      if (calorie > max_calorie){
        max_calorie = calorie;
      }
      printf("calorie : %llu\n", calorie);
      printf("max_calorie : %llu\n", max_calorie);
    }
  }

  printf("max_calorie : %llu\n", max_calorie);
  printf("init_calorie : %llu\n", init_calorie);
  /*  answer  */
  answer = init_calorie + max_calorie;
  printf("%llu\n", answer);
}
