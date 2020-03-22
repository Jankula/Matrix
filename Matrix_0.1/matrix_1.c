#include <stdio.h>
#include <stdlib.h>

#define MAXMATRIXNAME 11
#define MAXm 20
#define MAXn 20


typedef struct matrix{
	char name[MAXMATRIXNAME];
	int array[MAXm][MAXn];
	int m;
	int n;
	int det;
} Matrix;

void readMatrix(Matrix matrix[]);
void addMatrix(const Matrix const *matrix1, const Matrix const *matrix2, Matrix const *rezult_matrix);
void scaleMatrix(const Matrix const *matrix1, int k, const Matrix const *rezult_matrix);
void mulMatrix(const Matrix const *matrix1, const Matrix const *matrix2, Matrix const *rezult_matrix);
void transposeMatrix(const Matrix const *matrix, Matrix const *rezult_matrix);
void inverseMatrix(const Matrix const *matrix, Matrix const *rezult_matrix);


int main(){
	
	int i;
	char c;
	Matrix matrix[10]; //memory 16.220Bytes
	
	
	
	
	exit(EXIT_SUCCESS);
}


void readMatrix(Matrix matrix[]){
	
	
}

void addMatrix(const Matrix const *matrix1, const Matrix const *matrix2, Matrix const *rezult_matrix){
	
	
}

void scaleMatrix(const Matrix const *matrix1, int k, const Matrix const *rezult_matrix){
	
	
}

void mulMatrix(const Matrix const *matrix1, const Matrix const *matrix2, Matrix const *rezult_matrix){
	
	
}

void transposeMatrix(const Matrix const *matrix, Matrix const *rezult_matrix){
	
	
}

void inverseMatrix(const Matrix const *matrix, Matrix const *rezult_matrix){
	
	
}