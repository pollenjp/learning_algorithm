#include <stdio.h>

int main()
{
  int n, x;
  int m[100];
  int sum = 0;
  int min_m = 1e5;
  int min_m_num;

  scanf("%d %d", &n, &x);
  //printf("%d %d\n", n, x);

  for (int i = 0; i < n; i++){
    scanf("%d", &m[i]);
    //printf("%d\n", m[i]);
    sum += m[i];
    if (m[i] < min_m){
      min_m = m[i];
    }
  }
  //printf("sizeof(int) = %zu byte\n", sizeof(m[0]));

  min_m_num = (int) (x - sum) / min_m;

  printf("%d\n", n + min_m_num);

  return 0;
}

