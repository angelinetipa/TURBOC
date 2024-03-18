#include <stdio.h>

long long int fact(long long int);

int main() {
    long long int n;
    clrscr();
    printf("Enter the number to get the factorial (Max: 30):  ");
    scanf("%lld", &n);
    printf("%lld", fact(n));
  getch();
  return 0;
}

long long int fact (long long int n) {
  if (n == 0 || n == 1)
    return 1;
  if (n < 0)
    return -1;
  else
    return n*fact(n-1);
}