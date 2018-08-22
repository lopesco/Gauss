#include <stdio.h>
#include <stdlib.h>

double **alocaMatriz(int L, int C){
	/* se houver mem�ria dispon�vel, aloca uma matriz de double com L linhas e C colunas 
	e devolver um ponteiro para a matriz;
	caso contr�rio, devolve um ponteiro nulo. */
	double **m;
	int i, j;
	m = malloc(sizeof(double*)*L);
	if (m==NULL) /* falta de mem�ria */
		{ return NULL; }
	for (i=0; i<L; i++){
		m[i] = malloc(sizeof(double)*C);
		if (m[i]==NULL){
			for (j=0; j<i; j++)
				{ free(m[j]); }
			free(m);
			return NULL;
		}
	}
	return m;
}
/* fim do alocaMatriz */

/* l� valores para uma matriz de double alocada dinamicamente com L linhas e C colunas */
void leMatriz (double **m, int L, int C){
	int i, j;
	for (i=0; i<L; i++){
		for (j=0; j<C; j++){
		printf("m[%d][%d]= ", i+1, j+1);
		scanf("%lf", &m[i][j]);
		}
	}
}
/* fim leMatriz */

void imprimeMatriz(double **m, int L, int C){
	/* imprime o conte�do de uma matriz de uma matriz de double, alocada
	dinamicamente, com L linhas e com C colunas */
	int i, j;
	for (i=0; i<L; i++){
		for (j=0; j<C; j++)
			{ printf("%10.3lf ", m[i][j]);}
		printf("\n");
	}
}
/* fim do imprimeMatriz */

int main(){
	int n;
	double **m;
	printf("Quantidade de variaveis: ");
	scanf("%d", &n);
	m = alocaMatriz(n, n+1);
	if (m==NULL){/* falta de mem�ria */
	printf("Falta de memoria\n");
	return 1;
	}
	leMatriz(m, n, n+1);
	imprimeMatriz(m, n, n+1);
	
	return 0; 	
} 
/* fim main */
