#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXMATRIXNAME 11
#define MAXm 20
#define MAXn 20


typedef struct matrix{
	char name[MAXMATRIXNAME];//ime matrice
	int *matrix_p;//pokazivac ka samoj matrici
	int m;//dim
	int n;//dim
	int det;
} Matrix;

int readMatrix(Matrix *matrix);//ucitavanje matrice
int printMatrix(const Matrix const *matrix);//ucitavanje matrice
int addMatrix(const Matrix const *matrix1, const Matrix const *matrix2, Matrix *const rezult_matrix);
int scaleMatrix(const Matrix const *matrix1, int k, const Matrix const *rezult_matrix);
int mulMatrix(const Matrix const *matrix1, const Matrix const *matrix2, Matrix const *rezult_matrix);
int transposeMatrix(const Matrix const *matrix, Matrix const *rezult_matrix);
int inverseMatrix(const Matrix const *matrix, Matrix const *rezult_matrix);

int main(){
	
	int i;
	char c;
	Matrix matrix[3];
	
	
	system("cls");
	readMatrix(&matrix[0]);
	readMatrix(&matrix[1]);
	addMatrix(&matrix[0], &matrix[1], &matrix[2]);
	printMatrix(&matrix[0]);
	printMatrix(&matrix[1]);
	printMatrix(&matrix[2]);
	
	
	free(matrix[1].matrix_p);
	exit(EXIT_SUCCESS);
}


int readMatrix(Matrix *matrix){
	
	int i, j, ind = 0;
	char string[MAXMATRIXNAME + 1];
	
	do{
		if(ind++)
			printf("String too long. Try again: \n");
		printf("Upisite ime matrice: ");
		scanf("%s", string);
	}while(strlen(string) > MAXMATRIXNAME);
	ind = 0;
	strcpy(matrix->name, string);
	do{
		if(ind++)
			printf("n or m are invalid. Try again:\n");
		printf("Unesite dimenzije n i m: ");
		getchar();
		scanf("%d%d", &(matrix->n), &(matrix->m));
	}while(matrix->n < 1 || matrix->n > MAXn || matrix->m < 1 || matrix->m > MAXm);
	
	matrix->matrix_p = malloc(matrix->n * matrix->m * sizeof(int));
	printf("Unesite elemente:\n");
	for(i = 0; i < matrix->n; i++)
		for(j = 0; j < matrix->m; j++){
			if(scanf("%d", matrix->matrix_p + i * matrix->m + j) != 1)
				return -1;
		}
	
	return 1;
}

int printMatrix(const Matrix const *matrix){
	
	int i, j, n, m;
	
	n = matrix->n;
	m = matrix->m;
	printf("Printing matrix %s:\n", matrix->name);
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++)
			printf("%d ", *(matrix->matrix_p + i * m + j));
		putchar('\n');
	}
}

int addMatrix(const Matrix const *matrix1, const Matrix const *matrix2, Matrix *const rezult_matrix){
	
	int i, j, n1, n2, m1, m2;
	
	n1 = matrix1->n;
	n2 = matrix2->n;
	m1 = matrix1->m;
	m2 = matrix2->m;
	if(n1 != n2 || m1 != m2){
		printf("Addition is not possible between %s and %s.\n", matrix1->name, matrix2->name);
		return -1;
	}
	
	rezult_matrix->n = n1;
	rezult_matrix->m = m1;
	
	rezult_matrix->matrix_p = malloc(n1 * m1 * sizeof(int));
	for(i = 0; i < n1; i++)
		for(j = 0; j < m1; j++)
			*(rezult_matrix->matrix_p + i * m1 + j) = *(matrix1->matrix_p + i * m1 + j) + 
			*(matrix2->matrix_p + i * m1 + j);
	
	return 1;
}