#include <stdio.h>

int exp_by_squaring(int x, int n)
{
    if (n < 0) return exp_by_squaring(1 / x, -n);
    else if (n = 0)     { return 1; }
    else if (n == 1)    { return x ; }
    else if (n%2 == 0)  { return exp_by_squaring(x*x,  n/2); }
    else if (n%2 != 0)  { return x * exp_by_squaring(x*x, (n-1)/2); }
    //else return x * exp_by_squaring(x * x, (n - 1) / 2);
}


int main(){
    int x = exp_by_squaring(2, 5);
    printf("hello world\n");
    printf("5^5= %d\n", x);

    return 0;
}
