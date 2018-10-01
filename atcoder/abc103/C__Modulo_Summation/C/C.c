// D.c
//  C_Grid_Repainting_2
//    - https://abc096.contest.atcoder.jp/tasks/abc096_c#


# include <stdio.h>


#define HSIZE 50
#define WSIZE 50


void solve(int H, int W, char s[HSIZE][WSIZE]);

int main()
{
  //----------------------------------------
  //  Parameter Declaration
  //----------------------------------------
  int H, W;
  char s[HSIZE][WSIZE];
  char output[3];  // "yes" or "no"

  //----------------------------------------
  //  Input Data
  //----------------------------------------
  scanf("%d %d", &H, &W);
  for (int i=0; i<H; i++){
    scanf("%s", s[i]);
  }

  //----------------------------------------
  //  Run Algorithm
  //----------------------------------------
  solve(H, W, s);
  return 0;
}


//--------------------------------------------------------------------------------
//  solve()
//--------------------------------------------------------------------------------
void solve(int H, int W, char s[HSIZE][WSIZE])
{
  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      if (s[i][j] == '#'){

        // 一つ上のマスを確認
        if ( ( i > 0 ) && (s[i-1][j] == '#') ){
            continue;
        }
        // 一つ下のマスを確認
        if ( ( i < H-1 ) && (s[i+1][j] == '#') ){
            continue;
        }

        // 一つ左のマスを確認
        if ( ( j > 0 ) && (s[i][j-1] == '#') ){
            continue;
        }
        // 一つ右のマスを確認
        if ( (j < W-1) && (s[i][j+1] == '#') ){
            continue;
        }

        printf("%s\n", "No");
        return;
      }
    }
  }
  printf("%s\n", "Yes");
  return;
}

