#include <stdio.h>
#include <stdlib.h>
// directives
#define MAX 134217728

extern double asmfunc(double A, double X, double Y);

static double* daxpy(int n, double A, double* X, double* Y, int mode);

int main() {
	const int n = MAX;
	const double A = 2.0;
	double* X = (double*)malloc(n * sizeof(double));
	double* Y = (double*)malloc(n * sizeof(double));

	// Initialize X and Y
	X[0] = 1.0;
	Y[0] = 11.0;

	for (int i = 1; i < n; i++) {
		X[i] = X[i - 1] + 1.0;
		Y[i] = Y[i - 1] + 1.0;
	}

	double* Z1 = daxpy(n, A, X, Y, 0);
	double* Z2 = daxpy(n, A, X, Y, 1);

	for (int i = 0; i < 10; i++) {
		printf("%f\n", Z1[i]);
	}
	free(Z1);

	printf("\n");

	for (int i = 0; i < 10; i++) {
		printf("%f\n", Z2[i]);
	}
	free(Z2);

	return 0;
}

// Function to perform daxpy operation
static double* daxpy(int n, double A, double X[], double Y[], int mode) {
	//static double Z[MAX];
	double* Z = (double*)malloc(n * sizeof(double));

	for (int i = 0; i < n; i++) {

		if (mode == 0) {
			Z[i] = A * X[i] + Y[i];
		}
		else {
			Z[i] = asmfunc(A, X[i], Y[i]);
		}
	}

	return Z;
}