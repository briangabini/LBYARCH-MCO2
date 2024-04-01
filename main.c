#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// directives
#define MAX 134217728

extern double asmfunc(double A, double X, double Y);

static double* daxpy(int n, double A, double* X, double* Y, int mode);

int main() {
	int n = 1048576;
	int n1 = 16777216;
	int n2 = 134217728;
	int ctrs = 0;
	
	while (ctrs < 3){
		if (ctrs == 1){
			n = 16777216;
		}
		else if (ctrs == 2){
			n = 134217728;
		}
		printf("VALUE OF n: %d\n", n);
		const double A = 2.0;
		double* X = (double*)malloc(n * sizeof(double));
		double* Y = (double*)malloc(n * sizeof(double));

		// Initialize X and Y
		X[0] = 1.0;
		Y[0] = 11.0;

		double total_time_C = 0.0;
		double total_time_Asm = 0.0;

		for (int ctr = 0; ctr < 30; ctr++) {

			int adder = rand() % (100 + 1);

			for (int i = 1; i < n; i++) {
				X[i] = X[i - 1] + adder;
				Y[i] = Y[i - 1] + adder;
			}

			printf("\nIteration %d\n", ctr + 1);

			clock_t start, end;
			start = clock();
			double* Z1 = daxpy(n, A, X, Y, 0);
			end = clock();
			double time_takenC = ((double)(end - start)) / CLOCKS_PER_SEC;
			total_time_C += time_takenC;

			start = clock();
			double* Z2 = daxpy(n, A, X, Y, 1);
			end = clock();
			double time_takenAsm = ((double)(end - start)) / CLOCKS_PER_SEC;
			total_time_Asm += time_takenAsm;

			if (n >= 10) {
				for (int i = 0; i < 10; i++) {
					printf("%f ", Z1[i]);
				}
				printf("\n");
			}
			else {
				for (int i = 0; i < n; i++) {
					printf("%f ", Z1[i]);
				}
				printf("\n");
			}
			free(Z1);
			printf("Time taken for C code: %f", time_takenC);

			printf("\n");

			if (n >= 10) {
				for (int i = 0; i < 10; i++) {
					printf("%f ", Z2[i]);
				}
				printf("\n");
			}
			else {
				for (int i = 0; i < n; i++) {
					printf("%f ", Z2[i]);
				}
				printf("\n");
			}

			free(Z2);

			printf("Time taken for ASM code: %f\n", time_takenAsm);
		}

		printf("\nTotal time taken for 30 runs (C code): %f seconds\n", total_time_C);
		printf("Total time taken for 30 runs (ASM code): %f seconds\n", total_time_Asm);
		printf("Average time taken for 30 runs (C code): %f seconds\n", total_time_C / 30);
		printf("Average time taken for 30 runs (ASM code): %f seconds\n\n", total_time_Asm / 30);

		free(X);
		free(Y);
		ctrs += 1;
	}
	//const double A = 2.0;
	//double* X = (double*)malloc(n * sizeof(double));
	//double* Y = (double*)malloc(n * sizeof(double));

	//// Initialize X and Y
	//X[0] = 1.0;
	//Y[0] = 11.0;
	//
	//double total_time_C = 0.0;
	//double total_time_Asm = 0.0;

	//for (int ctr = 0; ctr < 30; ctr++) {

	//	int adder = rand() % (100 + 1);

	//	for (int i = 1; i < n; i++) {
	//		X[i] = X[i - 1] + adder;
	//		Y[i] = Y[i - 1] + adder;
	//	}

	//	printf("\nIteration %d\n\n", ctr + 1);

	//	clock_t start, end;
	//	start = clock();
	//	double* Z1 = daxpy(n, A, X, Y, 0);
	//	end = clock();
	//	double time_takenC = ((double)(end - start)) / CLOCKS_PER_SEC;
	//	total_time_C += time_takenC;

	//	start = clock();
	//	double* Z2 = daxpy(n, A, X, Y, 1);
	//	end = clock();
	//	double time_takenAsm = ((double)(end - start)) / CLOCKS_PER_SEC;
	//	total_time_Asm += time_takenAsm;

	//	if (n >= 10) {
	//		for (int i = 0; i < 10; i++) {
	//			printf("%f\n", Z1[i]);
	//		}
	//	}
	//	else {
	//		for (int i = 0; i < n; i++) {
	//			printf("%f\n", Z1[i]);
	//		}
	//	}
	//	free(Z1);
	//	printf("Time taken for C code: %f\n", time_takenC);

	//	printf("\n");

	//	if (n >= 10) {
	//		for (int i = 0; i < 10; i++) {
	//			printf("%f\n", Z2[i]);
	//		}
	//	}
	//	else {
	//		for (int i = 0; i < n; i++) {
	//			printf("%f\n", Z2[i]);
	//		}
	//	}

	//	free(Z2);

	//	printf("Time taken for ASM code: %f\n\n", time_takenAsm);
	//}

	//printf("\nTotal time taken for 30 runs (C code): %f seconds\n", total_time_C);
	//printf("Total time taken for 30 runs (ASM code): %f seconds\n", total_time_Asm);
	//printf("Average time taken for 30 runs (C code): %f seconds\n", total_time_C / 30);
	//printf("Average time taken for 30 runs (ASM code): %f seconds\n", total_time_Asm / 30);

	//free(X);
	//free(Y);

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