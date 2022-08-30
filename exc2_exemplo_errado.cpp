#include <stdio.h>
#include <stdlib.h>

void imprimir(int *x, int n)
{
	int i;
	
	for(i=0; i<n;i++)
	{
		printf("%d\n", x[i]);
	}
}

int part (int v[], int p, int r) {
	int q, i, j, t;
	i = p; 
	q = (p + r) / 2; 
	j = r;
	do {
		while (v[i] < v[q]) {
			i++;
		}
		while (v[j] > v[q]){
			j--;
		}
		if (i <= j) {
			t = v[i];
			v[i] = v[j];
			v[j] = t;
			i++;
			j--;
		}
	} while (i <= j);
	return i;
}


void quicksort(int *x, int p, int r){
	int q;
	if(p < r){
		q = part(x, p, r);
		quicksort(x, p,q);
		quicksort(x, q+1, r);
	}
	
}

int main(void){
	int x[10], i;
	
	for(i= 0; i <=9;i++){
		printf("\nDigite o %dº número: ", i+1);
		scanf("%d", &x[i]);
	}
	
	int tam = sizeof(x)/sizeof(int);
	
	imprimir(x, tam);
	
	quicksort(x, 0, tam-1);
	
	printf("-------------------");
	
	imprimir(x, tam);
}

