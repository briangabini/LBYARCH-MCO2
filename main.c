#include <stdio.h>

// directives
#define MAX 134217728

extern double asmfunc(double A, double X, double Y);

static double* daxpy(int n, double A, double X[], double Y[], int mode);

int main() {
	const int n = 3;
	const double A = 2.0;
	double X[] = {1.0, 2.0, 3.0};
	double Y[] = {4.0, 5.0, 6.0};
	double *Z1 = daxpy(n, A, X, Y, 0);
	double *Z2 = daxpy(n, A, X, Y, 1);

	for (int i = 0; i < n; i++) {
		printf("%f\n", Z1[i]);
	}

	printf("\n");

	for (int i = 0; i < n; i++) {
		printf("%f\n", Z2[i]);
	}

	return 0;
}

// Function to perform daxpy operation
static double* daxpy(int n, double A, double X[], double Y[], int mode) {
	static double Z[MAX];

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