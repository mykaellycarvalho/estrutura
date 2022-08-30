#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){

	setlocale(LC_ALL, "Portuguese");
	int x[50],x_orig[50], n, i, aux, troca, tam, eleito, j, menor, pos;
	
	int comp_bubble, cont_bubble, comp_insert, cont_insert, comp_select, cont_select;
	
	printf("Digite o tamanho do vetor? \n");
	scanf("%d",&tam);
	
	for(i = 0; i < tam; i++){
		printf("Digite o %dº número do vetor: ", i+1);
		scanf("%d",&x[i]);
		x_orig[i] = x[i];
	}
	
	comp_bubble = 0;
	cont_bubble = 0;
	n = 1;
	troca = 1;
	
	while(n <= tam && troca ==1){
		
		troca = 0;
		for(i = 0; i < tam-1; i ++){
			
			comp_bubble = comp_bubble + 1 ;
			if(x[i] < x[i+1]){
				troca = 1;
				aux = x[i];
				x[i] = x[i+1];
				x[i+1] = aux;
				cont_bubble = cont_bubble + 1;
			}
		}		
		n++;
	}
	
	printf("\n\nBUBBLE SORT");
	printf("\nNúmero de Comparacões: %d", comp_bubble);
	printf("\nNúmero de Trocas: %d", cont_bubble);
	

	comp_insert = 0;
	cont_insert = 0;
	
	for(i = 0; i < tam; i++){
		x[i] = x_orig[i];
	}
	
	for(i = 1; i < tam; i ++){
		eleito = x[i];
		j = i - 1;
		
		comp_insert = comp_insert + 1;
		
		while(j >= 0 && x[j] > eleito){
			x[j+1] = x[j];
			j = j - 1;	
			cont_insert = cont_insert + 1;	
		}
		x[j+1] = eleito;
	} 
	
	printf("\n\nINSERTION SORT");
	printf("\nNúmero de Comparacões: %d", comp_insert);
	printf("\nNúmero de Trocas: %d", cont_insert);
	

	comp_select = 0;
	cont_select = 0;
	
	for(i = 0; i < tam; i++){
		x[i] = x_orig[i];
	}
	
	for(i = 0; i < tam; i++){
		
		eleito = x[i];
		menor = x[i+1];
		pos = i+1;
		
		for(j = i+2; j < tam; j++){
			
			comp_select = comp_select + 1;
			
			if (x[j] < menor){
				menor = x[j];
				pos = j;
				cont_select = cont_select + 1;
			}
		}
		
		comp_select = comp_select + 1;
		
		if (menor < eleito){
			x[i] = x[pos];
			x[pos] = eleito;
			cont_select = cont_select + 1;
		}		
	}
	
	printf("\n\nSELECTION SORT");
	printf("\nNúmero de Comparacões: %d", comp_select);
	printf("\nNúmero de Trocas: %d", cont_select);
	
}
