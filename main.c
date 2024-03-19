#include <stdio.h>

extern double asmfunc(double A, double X, double Y);

static double* daxpy(double A, double X[], double Y[], int mode);

int main() {
	const double A = 2.0;
	double X[] = {1.0, 2.0, 3.0};
	double Y[] = {4.0, 5.0, 6.0};
	double *Z1 = daxpy(A, X, Y, 0);
	double *Z2 = daxpy(A, X, Y, 1);

	for (int i = 0; i < 3; i++) {
		printf("%f\n", Z1[i]);
	}

	printf("\n");

	for (int i = 0; i < 3; i++) {
		printf("%f\n", Z2[i]);
	}

	return 0;
}

// Function to perform daxpy operation
static double* daxpy(double A, double X[], double Y[], int mode) {

	int size = 3;
	static double Z[3];		// set to static to have a longer lifetime

	for (int i = 0; i < size; i++) {

		if (mode == 0) {
			Z[i] = A * X[i] + Y[i];
		}
		else {
			double tempX = X[i];
			double tempY = Y[i];
			Z[i] = asmfunc(A, tempX, tempY);
		}
	}

	return Z;
}