#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");
  
  int x[10], n, i, aux, flag;

  for (i = 1; i <= 10; i++) {
    printf("\nDigite o %dº número:", i);
    scanf("%d", &x[i]);
  }
  n = 1;
  flag = 1;
  while (n <= 10 && flag == 1) {
    flag = 0;
    for (i = 1; i <= 9; i++) {
      if (x[i] < x[i + 1]) {
        flag = 1;
        aux = x[i];
        x[i] = x[i + 1];
        x[i + 1] = aux;
      }
    }
    n++;
  }

  for (i = 1; i <= 10; i++) {
    printf("%d\n", x[i]);
  }
}

