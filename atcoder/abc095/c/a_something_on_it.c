#include <stdio.h>

int main()
{
  char str[3];
  scanf("%s", str);
  int answer = 700;
  for (int i = 0; i < 3; i++){
    if (str[i] == 'o'){
      answer += 100;
    }
  }
  printf("%d", answer);
}
