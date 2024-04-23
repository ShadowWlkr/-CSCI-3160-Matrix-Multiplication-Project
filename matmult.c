#include <cblas.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define MATA 128
#define MATB 256
#define MATC 512


FILE *fil;

int im128all1[MATA][MATA], im128all2[MATA][MATA], im128iden[MATA][MATA], im128seq[MATA][MATA];
double fm128all1[MATA][MATA], fm128all2[MATA][MATA], fm128iden[MATA][MATA], fm128seq[MATA][MATA];

int im256all1[MATB][MATB], im256all2[MATB][MATB], im256iden[MATB][MATB], im256seq[MATB][MATB];
double fm256all1[MATB][MATB], fm256all2[MATB][MATB], fm256iden[MATB][MATB], fm256seq[MATB][MATB];

int im512all1[MATC][MATC], im512all2[MATC][MATC], im512iden[MATC][MATC], im512seq[MATC][MATC];
double fm512all1[MATC][MATC], fm512all2[MATC][MATC], fm512iden[MATC][MATC], fm512seq[MATC][MATC];

int intmatmult128_unopt(int A[][MATA], int B[][MATA])
{
	register int i, j, k;
	int C[MATA][MATA];
	
	/* START OPERATION */
	clock_t begin = clock();

	for (i = 0; i < MATA; i++)
	{
		for (j = 0; j < MATA; j++)
		{
			C[i][j] = 0;
			for (k = 0; k < MATA; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
	
		}
	}
	
	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	fprintf(stdout, "Integer Matrix Multiplication of size 128 took %0.5f seconds.\n", time);
	fprintf(fil, "Integer Matrix Multiplication of size 128 took %0.5f seconds.\n", time);

	//verify output
	

/*	for(int i = 0; i < MATA; i++)
	{
		for(int j = 0; j < MATA; j++)
		{
			printf(" %d", B[i][j]);
		}
		printf("\n");*/
}


int intmatmult256_unopt(int A[][MATB], int B[][MATB])
{
	register int i, j, k;
	int C[MATB][MATB];
	
	/* START OPERATION */
	clock_t begin = clock();

	for (i = 0; i < MATB; i++)
	{
		for (j = 0; j < MATB; j++)
		{
			C[i][j] = 0;
			for (k = 0; k < MATB; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
	
		}
	}

	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	fprintf(stdout, "Integer Matrix Multiplication of size 256 took %0.5f seconds.\n", time);
	fprintf(fil, "Integer Matrix Multiplication of size 256 took %0.5f seconds.\n", time);

	return 0;
}

int intmatmult512_unopt(int A[][MATC], int B[][MATC])
{
	register int i, j, k;
	int C[MATC][MATC];
	
	/* START OPERATION */
	clock_t begin = clock();

	for (i = 0; i < MATC; i++)
	{
		for (j = 0; j < MATC; j++)
		{
			C[i][j] = 0;
			for (k = 0; k < MATC; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
	
		}
	}

	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	fprintf(stdout, "Integer Matrix Multiplication of size 512 took %0.5f seconds.\n", time);
	fprintf(fil, "Integer Matrix Multiplication of size 512 took %0.5f seconds.\n", time);


	return 0;
}

int flomatmult128_unopt(double A[][MATA], double B[][MATA])
{
	register int i, j, k;
	double C[MATA][MATA];
	
	/* START OPERATION */
	clock_t begin = clock();
	
	for (i = 0; i < MATA; i++)
	{
		for (j = 0; j < MATA; j++)
		{
			C[i][j] = 0;
			for (k = 0; k < MATA; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
	
		}
	}

	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	fprintf(stdout, "Floating Point Matrix Multiplication of size 128 took %0.5f seconds.\n", time);
	fprintf(fil, "Floating Point Matrix Multiplication of size 128 took %0.5f seconds.\n", time);


	return 0;
}


int flomatmult256_unopt(double A[][MATB], double B[][MATB])
{
	register int i, j, k;
	double C[MATB][MATB];

	/* START OPERATION */
	clock_t begin = clock();

	for (i = 0; i < MATB; i++)
	{
		for (j = 0; j < MATB; j++)
		{
			C[i][j] = 0;
			for (k = 0; k < MATB; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
	
		}
	}

	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	fprintf(stdout, "Floating Point Matrix Multiplication of size 256 took %0.5f seconds.\n", time);
	fprintf(fil, "Floating Point Matrix Multiplication of size 256 took %0.5f seconds.\n", time);


	return 0;
}

int flomatmult512_unopt(double A[][MATC], double B[][MATC])
{
	register int i, j, k;
	double C[MATC][MATC];
	
	/* START OPERATION */
	clock_t begin = clock();

	for (i = 0; i < MATC; i++)
	{
		for (j = 0; j < MATC; j++)
		{
			C[i][j] = 0;
			for (k = 0; k < MATC; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
	
		}
	}

	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	fprintf(stdout, "Floating Point Matrix Multiplication of size 512 took %0.5f seconds.\n", time);
	fprintf(fil, "Floating Point Matrix Multiplication of size 512 took %0.5f seconds.\n", time);


	return 0;
}

/*struct intmats {
	int *mat1;
	int *mat2;
	int *res;
	int size;
};

int intmatmult_opt(struct intmats *mats){
	double *A, *B, *C;

	A = (double *)mats->mat1;
	B = (double *)mats->mat2;
	C = (double *)mats->res;
	int n = mats->size;

	clock_t begin = clock();
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1.0, A, n, B, n, 0.0, C, n);
	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Optimized Integer Matrix Multiplication of size %d took %0.5f seconds.\n", n, time);
	
	return 0;
}*/

int intmatmult128_opt(int A[][MATA], int B[][MATA]){
	double *C[MATA][MATA];

	clock_t begin = clock();
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, MATA, MATA, MATA, 1.0, (double *)A, MATA, (double *)B, MATA, 0.0, (double *)C, MATA);
	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Optimized Integer Matrix Multiplication of size %d took %0.5f seconds.\n", MATA, time);
	fprintf(fil, "Optimized Integer Matrix Multiplication of size 128 took %0.5f seconds.\n", time);


	return 0;
}

int intmatmult256_opt(int A[][MATB], int B[][MATB]){
	double *C[MATB][MATB];

	clock_t begin = clock();
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, MATB, MATB, MATB, 1.0, (double *)A, MATB, (double *)B, MATB, 0.0, (double *)C, MATB);
	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Optimized Integer Matrix Multiplication of size %d took %0.5f seconds.\n", MATB, time);
	fprintf(fil, "Optimized Integer Matrix Multiplication of size 256 took %0.5f seconds.\n", time);


	return 0;
}

int intmatmult512_opt(int A[][MATC], int B[][MATC]){
	double *C[MATC][MATC];

	clock_t begin = clock();
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, MATC, MATC, MATC, 1.0, (double *)A, MATC, (double *)B, MATC, 0.0, (double *)C, MATC);
	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Optimized Integer Matrix Multiplication of size %d took %0.5f seconds.\n", MATC, time);
	fprintf(fil, "Optimized Integer Matrix Multiplication of size 512 took %0.5f seconds.\n", time);


	return 0;
}

int flomatmult128_opt(double A[][MATA], double B[][MATA]){
	double *C[MATA][MATA];

	clock_t begin = clock();
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, MATA, MATA, MATA, 1.0, (double *)A, MATA, (double *)B, MATA, 0.0, (double *)C, MATA);
	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Optimized Integer Matrix Multiplication of size %d took %0.5f seconds.\n", MATA, time);
	fprintf(fil, "Optimized Floating Point Matrix Multiplication of size 128 took %0.5f seconds.\n", time);


	return 0;
}

int flomatmult256_opt(double A[][MATB], double B[][MATB]){
	double *C[MATB][MATB];

	clock_t begin = clock();
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, MATB, MATB, MATB, 1.0, (double *)A, MATB, (double *)B, MATB, 0.0, (double *)C, MATB);
	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Optimized Integer Matrix Multiplication of size %d took %0.5f seconds.\n", MATB, time);
	fprintf(fil, "Optimized Floating Point Matrix Multiplication of size 256 took %0.5f seconds.\n", time);


	return 0;
}

int flomatmult512_opt(double A[][MATC], double B[][MATC]){
	double *C[MATC][MATC];

	clock_t begin = clock();
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, MATC, MATC, MATC, 1.0, (double *)A, MATC, (double *)B, MATC, 0.0, (double *)C, MATC);
	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Optimized Integer Matrix Multiplication of size %d took %0.5f seconds.\n", MATC, time);
	fprintf(fil, "Optimized Floating Point Matrix Multiplication of size 512 took %0.5f seconds.\n", time);


	return 0;
}



void main()
{
	register int n = 0;
	fil = fopen("matmultout.txt", "w");

	//initialize matrices
	printf("Initializing test matrices...\n");
	//initialize size 128 matrices
	for (int i = 0; i < 128; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			n++;
			im128all1[i][j] = 1;
			im128all2[i][j] = 2;
			fm128all1[i][j] = (double)1;
			fm128all2[i][j] = (double)2;
			im128seq[i][j] = n;
			fm128seq[i][j] = (double)n;
			if (i == j) 
			{
				im128iden[i][j] = 1;
				fm128iden[i][j] = (double)1;
			} else {
				im128iden[i][j] = 0;
				fm128iden[i][j] = (double)0;
			}
		}
	}
	n = 0;
	//initialize size 256 matrices
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			n++;
			im256all1[i][j] = 1;
			im256all2[i][j] = 2;
			fm256all1[i][j] = (double)1;
			fm256all2[i][j] = (double)2;
			im256seq[i][j] = n;
			fm256seq[i][j] = (double)n;

			if (i == j) 
			{
				im256iden[i][j] = 1;
				fm256iden[i][j] = (double)1;
			} else {
				im256iden[i][j] = 0;
				fm256iden[i][j] = (double)0;
			}
		}
	}
	n = 0;
	//initialize size 512 matrices
	for (int i = 0; i < 512; i++)
	{
		for (int j = 0; j < 512; j++)
		{
			n++;
			im512all1[i][j] = 1;
			im512all2[i][j] = 2;
			fm512all1[i][j] = (double)1;
			fm512all2[i][j] = (double)2;
			im512seq[i][j] = n;
			fm512seq[i][j] = (double)n;

			if (i == j) 
			{
				im512iden[i][j] = 1;
				fm512iden[i][j] = (double)1;
			} else {
				im512iden[i][j] = 0;
				fm512iden[i][j] = (double)0;
			}
		}
	}
	//test init
	/*for(int i = 0; i < 128; i++)
	{
		for(int j = 0; j < 128; j++)
		{
			printf(" %d", im128seq[i][j]);
		}
		printf("\n");
	}*/

	fprintf(stdout, "\n==================================\n\nStart unoptimized 128 testing, all int 1's*identity matrix...\n");
	fprintf(fil, "\n==================================\n\nStart unoptimized 128 testing, all int 1's*identity matrix...\n");
	intmatmult128_unopt(im128all1, im128iden);	
	fprintf(stdout, "\nNext test, all int 2's*identity matrix...\n");
	fprintf(fil, "\nNext test, all int 2's*identity matrix...\n");
	intmatmult128_unopt(im128all2, im128iden);
	fprintf(stdout, "\nNext test, sequential integers*identity matrix...\n");
	fprintf(fil, "\nNext test, sequential integers*identity matrix...\n");
	intmatmult128_unopt(im128seq, im128iden);
	fprintf(stdout, "\nNext test, all float 1's*identity matrix...\n");
	fprintf(fil, "\nNext test, all float 1's*identity matrix...\n");
	flomatmult128_unopt(fm128all1, fm128iden);
	fprintf(stdout, "\nNext test, all float 2's*identity matrix...\n");
	fprintf(fil, "\nNext test, all float 2's*identity matrix...\n");
	flomatmult128_unopt(fm128all2, fm128iden);
	fprintf(stdout, "\nNext test, sequential floats*identity matrix...\n");
	fprintf(fil, "\nNext test, sequential floats*identity matrix...\n");
	flomatmult128_unopt(fm128seq, fm128iden);
	
	fprintf(stdout, "\nNext test, all int 1's*all int 1's...\n");
	fprintf(fil, "\nNext test, all int 1's*all int 1's...\n");
	intmatmult128_unopt(im128all1, im128all1);	
	fprintf(stdout, "\nNext test, all int 2's*all int 1's...\n");
	fprintf(fil, "\nNext test, all int 2's*all int 1's...\n");
	intmatmult128_unopt(im128all2, im128all1);
	fprintf(stdout, "\nNext test, sequential integers*all int 1's...\n");
	fprintf(fil, "\nNext test, sequential integers*all int 1's...\n");
	intmatmult128_unopt(im128seq, im128all1);
	fprintf(stdout, "\nNext test, all float 1's*all float 1's...\n");
	fprintf(fil, "\nNext test, all float 1's*all float 1's...\n");
	flomatmult128_unopt(fm128all1, fm128all1);
	fprintf(stdout, "\nNext test, all float 2's*all float 1's...\n");
	fprintf(fil, "\nNext test, all float 2's*all float 1's...\n");
	flomatmult128_unopt(fm128all2, fm128all1);
	fprintf(stdout, "\nNext test, sequential floats*all float 1's...\n");
	fprintf(fil, "\nNext test, sequential floats*all float 1's...\n");
	flomatmult128_unopt(fm128seq, fm128all1);

	fprintf(stdout, "\nNext test, all int 1's*all int 2's...\n");
	fprintf(fil, "\nNext test, all int 1's*all int 2's...\n");
	intmatmult128_unopt(im128all1, im128all2);	
	fprintf(stdout, "\nNext test, all int 2's*all int 2's...\n");
	fprintf(fil, "\nNext test, all int 2's*all int 2's...\n");
	intmatmult128_unopt(im128all2, im128all2);
	fprintf(stdout, "\nNext test, sequential integers*all int 2's...\n");
	fprintf(fil, "\nNext test, sequential integers*all int 2's...\n");
	intmatmult128_unopt(im128seq, im128all2);
	fprintf(stdout, "\nNext test, all float 1's*all int 2's...\n");
	fprintf(fil, "\nNext test, all float 1's*all int 2's...\n");
	flomatmult128_unopt(fm128all1, fm128all2);
	fprintf(stdout, "\nNext test, all float 2's*all int 2's...\n");
	fprintf(fil, "\nNext test, all float 2's*all int 2's...\n");
	flomatmult128_unopt(fm128all2, fm128all2);
	fprintf(stdout, "\nNext test, sequential floats*all int 2's...\n");
	fprintf(fil, "\nNext test, sequential floats*all int 2's...\n");
	flomatmult128_unopt(fm128seq, fm128all2);

	int testflag = 0;
	if (testflag == 0){
	fprintf(stdout, "\n==================================\n\nStart unoptimized 256 testing, all int 1's*identity matrix...\n");
	fprintf(fil, "\n==================================\n\nStart unoptimized 256 testing, all int 1's*identity matrix...\n");
	intmatmult256_unopt(im256all1, im256iden);
	fprintf(stdout, "\nNext test, all int 2's*identity matrix...\n");
	fprintf(fil, "\nNext test, all int 2's*identity matrix...\n");
	intmatmult256_unopt(im256all2, im256iden);
	fprintf(stdout, "\nNext test, sequential integers*identity matrix...\n");
	fprintf(fil, "\nNext test, sequential integers*identity matrix...\n");
	intmatmult256_unopt(im256seq, im256iden);
	fprintf(stdout, "\nNext test, all float 1's*identity matrix...\n");
	fprintf(fil, "\nNext test, all float 1's*identity matrix...\n");
	flomatmult256_unopt(fm256all1, fm256iden);
	fprintf(stdout, "\nNext test, all float 2's*identity matrix...\n");
	fprintf(fil, "\nNext test, all float 2's*identity matrix...\n");
	flomatmult256_unopt(fm256all2, fm256iden);
	fprintf(stdout, "\nNext test, sequential floats*identity matrix...\n");
	fprintf(fil, "\nNext test, sequential floats*identity matrix...\n");
	flomatmult256_unopt(fm256seq, fm256iden);
	
	fprintf(stdout, "\nNext test, all int 1's*all int 1's...\n");
	fprintf(fil, "\nNext test, all int 1's*all int 1's...\n");
	intmatmult256_unopt(im256all1, im256all1);
	fprintf(stdout, "\nNext test, all int 2's*all int 1's...\n");
	fprintf(fil, "\nNext test, all int 2's*all int 1's...\n");
	intmatmult256_unopt(im256all2, im256all1);
	fprintf(stdout, "\nNext test, sequential integers*all int 1's...\n");
	fprintf(fil, "\nNext test, sequential integers*all int 1's...\n");
	intmatmult256_unopt(im256seq, im256all1);
	fprintf(stdout, "\nNext test, all float 1's*all float 1's...\n");
	fprintf(fil, "\nNext test, all float 1's*all float 1's...\n");
	flomatmult256_unopt(fm256all1, fm256all1);
	fprintf(stdout, "\nNext test, all float 2's*all float 1's...\n");
	fprintf(fil, "\nNext test, all float 2's*all float 1's...\n");
	flomatmult256_unopt(fm256all2, fm256all1);
	fprintf(stdout, "\nNext test, sequential floats*all float 1's...\n");
	fprintf(fil, "\nNext test, sequential floats*all float 1's...\n");
	flomatmult256_unopt(fm256seq, fm256all1);

	fprintf(stdout, "\nNext test, all int 1's*all int 2's...\n");
	fprintf(fil, "\nNext test, all int 1's*all int 2's...\n");
	intmatmult256_unopt(im256all1, im256all2);
	fprintf(stdout, "\nNext test, all int 2's*all int 2's...\n");
	fprintf(fil, "\nNext test, all int 2's*all int 2's...\n");
	intmatmult256_unopt(im256all2, im256all2);
	fprintf(stdout, "\nNext test, sequential integers*all int 2's...\n");
	fprintf(fil, "\nNext test, sequential integers*all int 2's...\n");
	intmatmult256_unopt(im256seq, im256all2);
	fprintf(stdout, "\nNext test, all float 1's*all float 2's...\n");
	fprintf(fil, "\nNext test, all float 1's*all float 2's...\n");
	flomatmult256_unopt(fm256all1, fm256all2);
	fprintf(stdout, "\nNext test, all float 2's*all float 2's...\n");
	fprintf(fil, "\nNext test, all float 2's*all float 2's...\n");
	flomatmult256_unopt(fm256all2, fm256all2);
	fprintf(stdout, "\nNext test, sequential floats*all float 2's...\n");
	fprintf(fil, "\nNext test, sequential floats*all float 2's...\n");
	flomatmult256_unopt(fm256seq, fm256all2);

	fprintf(stdout, "\n==================================\n\nStart unoptimized 512 testing, all int 1's*identity matrix...\n");
	fprintf(fil, "\n==================================\n\nStart unoptimized 512 testing, all int 1's*identity matrix...\n");
	intmatmult512_unopt(im512all1, im512iden);	
	fprintf(stdout, "\nNext test, all int 2's*identity matrix...\n");
	fprintf(fil, "\nNext test, all int 2's*identity matrix...\n");
	intmatmult512_unopt(im512all2, im512iden);	
	fprintf(stdout, "\nNext test, sequential integers*identity matrix...\n");
	fprintf(fil, "\nNext test, sequential integers*identity matrix...\n");
	intmatmult512_unopt(im512seq, im512iden);	
	fprintf(stdout, "\nNext test, all float 1's*identity matrix...\n");
	fprintf(fil, "\nNext test, all float 1's*identity matrix...\n");
	flomatmult512_unopt(fm512all1, fm512iden);
	fprintf(stdout, "\nNext test, all float 2's*identity matrix...\n");
	fprintf(fil, "\nNext test, all float 2's*identity matrix...\n");
	flomatmult512_unopt(fm512all2, fm512iden);
	fprintf(stdout, "\nNext test, sequential floats*identity matrix...\n");
	fprintf(fil, "\nNext test, sequential floats*identity matrix...\n");
	flomatmult512_unopt(fm512seq, fm512iden);

	fprintf(stdout, "\nNext test, all int 1's*all int 1's...\n");
	fprintf(fil, "\nNext test, all int 1's*all int 1's...\n");
	intmatmult512_unopt(im512all1, im512all1);	
	fprintf(stdout, "\nNext test, all int 2's*all int 1's...\n");
	fprintf(fil, "\nNext test, all int 2's*all int 1's...\n");
	intmatmult512_unopt(im512all2, im512all1);	
	fprintf(stdout, "\nNext test, sequential integers*all int 1's...\n");
	fprintf(fil, "\nNext test, sequential integers*all int 1's...\n");
	intmatmult512_unopt(im512seq, im512all1);	
	fprintf(stdout, "\nNext test, all float 1's*all float 1's...\n");
	fprintf(fil, "\nNext test, all float 1's*all float 1's...\n");
	flomatmult512_unopt(fm512all1, fm512all1);
	fprintf(stdout, "\nNext test, all float 2's*all float 1's...\n");
	fprintf(fil, "\nNext test, all float 2's*all float 1's...\n");
	flomatmult512_unopt(fm512all2, fm512all1);
	fprintf(stdout, "\nNext test, sequential floats*all float 1's...\n");
	fprintf(fil, "\nNext test, sequential floats*all float 1's...\n");
	flomatmult512_unopt(fm512seq, fm512all1);

	fprintf(stdout, "\nNext test, all int 1's*all int 2's...\n");
	fprintf(fil, "\nNext test, all int 1's*all int 2's...\n");
	intmatmult512_unopt(im512all1, im512all2);	
	fprintf(stdout, "\nNext test, all int 2's*all int 2's...\n");
	fprintf(fil, "\nNext test, all int 2's*all int 2's...\n");
	intmatmult512_unopt(im512all2, im512all2);	
	fprintf(stdout, "\nNext test, sequential integers*all int 2's...\n");
	fprintf(fil, "\nNext test, sequential integers*all int 2's...\n");
	intmatmult512_unopt(im512seq, im512all2);	
	fprintf(stdout, "\nNext test, all float 1's*all float 2's...\n");
	fprintf(fil, "\nNext test, all float 1's*all float 2's...\n");
	flomatmult512_unopt(fm512all1, fm512all2);
	fprintf(stdout, "\nNext test, all float 2's*all float 2's...\n");
	fprintf(fil, "\nNext test, all float 2's*all float 2's...\n");
	flomatmult512_unopt(fm512all2, fm512all2);
	fprintf(stdout, "\nNext test, sequential floats*all float 2's...\n");
	fprintf(fil, "\nNext test, sequential floats*all float 2's...\n");
	flomatmult512_unopt(fm512seq, fm512all2);

	}


	fprintf(stdout, "\n==================================\n\nStart optimized 128 testing, all int 1's*identity matrix...\n");
	fprintf(fil, "\n==================================\n\nStart optimized 128 testing, all int 1's*identity matrix...\n");
	intmatmult128_opt(im128all1, im128iden);	
	fprintf(stdout, "\nNext test, all int 2's*identity matrix...\n");
	fprintf(fil, "\nNext test, all int 2's*identity matrix...\n");
	intmatmult128_opt(im128all2, im128iden);
	fprintf(stdout, "\nNext test, sequential integers*identity matrix...\n");
	fprintf(fil, "\nNext test, sequential integers*identity matrix...\n");
	intmatmult128_opt(im128seq, im128iden);
	fprintf(stdout, "\nNext test, all float 1's*identity matrix...\n");
	fprintf(fil, "\nNext test, all float 1's*identity matrix...\n");
	flomatmult128_opt(fm128all1, fm128iden);
	fprintf(stdout, "\nNext test, all float 2's*identity matrix...\n");
	fprintf(fil, "\nNext test, all float 2's*identity matrix...\n");
	flomatmult128_opt(fm128all2, fm128iden);
	fprintf(stdout, "\nNext test, sequential floats*identity matrix...\n");
	fprintf(fil, "\nNext test, sequential floats*identity matrix...\n");
	flomatmult128_opt(fm128seq, fm128iden);

	fprintf(stdout, "\nNext test, all int 1's*all int 1's...\n");
	fprintf(fil, "\nNext test, all int 1's*all int 1's...\n");
	intmatmult128_opt(im128all1, im128all1);	
	fprintf(stdout, "\nNext test, all int 2's*all int 1's...\n");
	fprintf(fil, "\nNext test, all int 2's*all int 1's...\n");
	intmatmult128_opt(im128all2, im128all1);
	fprintf(stdout, "\nNext test, sequential integers*all int 1's...\n");
	fprintf(fil, "\nNext test, sequential integers*all int 1's...\n");
	intmatmult128_opt(im128seq, im128all1);
	fprintf(stdout, "\nNext test, all float 1's*all float 1's...\n");
	fprintf(fil, "\nNext test, all float 1's*all float 1's...\n");
	flomatmult128_opt(fm128all1, fm128all1);
	fprintf(stdout, "\nNext test, all float 2's*all float 1's...\n");
	fprintf(fil, "\nNext test, all float 2's*all float 1's...\n");
	flomatmult128_opt(fm128all2, fm128all1);
	fprintf(stdout, "\nNext test, sequential floats*all float 1's...\n");
	fprintf(fil, "\nNext test, sequential floats*all float 1's...\n");
	flomatmult128_opt(fm128seq, fm128all1);

	fprintf(stdout, "\nNext test, all int 1's*all int 2's...\n");
	fprintf(fil, "\nNext test, all int 1's*all int 2's...\n");
	intmatmult128_opt(im128all1, im128all2);	
	fprintf(stdout, "\nNext test, all int 2's*all int 2's...\n");
	fprintf(fil, "\nNext test, all int 2's*all int 2's...\n");
	intmatmult128_opt(im128all2, im128all2);
	fprintf(stdout, "\nNext test, sequential integers*all int 2's...\n");
	fprintf(fil, "\nNext test, sequential integers*all int 2's...\n");
	intmatmult128_opt(im128seq, im128all2);
	fprintf(stdout, "\nNext test, all float 1's*all int 2's...\n");
	fprintf(fil, "\nNext test, all float 1's*all int 2's...\n");
	flomatmult128_opt(fm128all1, fm128all2);
	fprintf(stdout, "\nNext test, all float 2's*all int 2's...\n");
	fprintf(fil, "\nNext test, all float 2's*all int 2's...\n");
	flomatmult128_opt(fm128all2, fm128all2);
	fprintf(stdout, "\nNext test, sequential floats*all int 2's...\n");
	fprintf(fil, "\nNext test, sequential floats*all int 2's...\n");
	flomatmult128_opt(fm128seq, fm128all2);

	fprintf(stdout, "\n==================================\n\nStart optimized 256 testing, all int 1's*identity matrix...\n");
	fprintf(fil, "\n==================================\n\nStart optimized 256 testing, all int 1's*identity matrix...\n");
	intmatmult256_opt(im256all1, im256iden);	
	fprintf(stdout, "\nNext test, all int 2's*identity matrix...\n");
	fprintf(fil, "\nNext test, all int 2's*identity matrix...\n");
	intmatmult256_opt(im256all2, im256iden);
	fprintf(stdout, "\nNext test, sequential integers*identity matrix...\n");
	fprintf(fil, "\nNext test, sequential integers*identity matrix...\n");
	intmatmult256_opt(im256seq, im256iden);
	fprintf(stdout, "\nNext test, all float 1's*identity matrix...\n");
	fprintf(fil, "\nNext test, all float 1's*identity matrix...\n");
	flomatmult256_opt(fm256all1, fm256iden);
	fprintf(stdout, "\nNext test, all float 2's*identity matrix...\n");
	fprintf(fil, "\nNext test, all float 2's*identity matrix...\n");
	flomatmult256_opt(fm256all2, fm256iden);
	fprintf(stdout, "\nNext test, sequential floats*identity matrix...\n");
	fprintf(fil, "\nNext test, sequential floats*identity matrix...\n");
	flomatmult256_opt(fm256seq, fm256iden);

	fprintf(stdout, "\nNext test, all int 1's*all int 1's...\n");
	fprintf(fil, "\nNext test, all int 1's*all int 1's...\n");
	intmatmult256_opt(im256all1, im256all1);	
	fprintf(stdout, "\nNext test, all int 2's*all int 1's...\n");
	fprintf(fil, "\nNext test, all int 2's*all int 1's...\n");
	intmatmult256_opt(im256all2, im256all1);
	fprintf(stdout, "\nNext test, sequential integers*all int 1's...\n");
	fprintf(fil, "\nNext test, sequential integers*all int 1's...\n");
	intmatmult256_opt(im256seq, im256all1);
	fprintf(stdout, "\nNext test, all float 1's*all float 1's...\n");
	fprintf(fil, "\nNext test, all float 1's*all float 1's...\n");
	flomatmult256_opt(fm256all1, fm256all1);
	fprintf(stdout, "\nNext test, all float 2's*all float 1's...\n");
	fprintf(fil, "\nNext test, all float 2's*all float 1's...\n");
	flomatmult256_opt(fm256all2, fm256all1);
	fprintf(stdout, "\nNext test, sequential floats*all float 1's...\n");
	fprintf(fil, "\nNext test, sequential floats*all float 1's...\n");
	flomatmult256_opt(fm256seq, fm256all1);

	fprintf(stdout, "\nNext test, all int 1's*all int 2's...\n");
	fprintf(fil, "\nNext test, all int 1's*all int 2's...\n");
	intmatmult256_opt(im256all1, im256all2);	
	fprintf(stdout, "\nNext test, all int 2's*all int 2's...\n");
	fprintf(fil, "\nNext test, all int 2's*all int 2's...\n");
	intmatmult256_opt(im256all2, im256all2);
	fprintf(stdout, "\nNext test, sequential integers*all int 2's...\n");
	fprintf(fil, "\nNext test, sequential integers*all int 2's...\n");
	intmatmult256_opt(im256seq, im256all2);
	fprintf(stdout, "\nNext test, all float 1's*all int 2's...\n");
	fprintf(fil, "\nNext test, all float 1's*all int 2's...\n");
	flomatmult256_opt(fm256all1, fm256all2);
	fprintf(stdout, "\nNext test, all float 2's*all int 2's...\n");
	fprintf(fil, "\nNext test, all float 2's*all int 2's...\n");
	flomatmult256_opt(fm256all2, fm256all2);
	fprintf(stdout, "\nNext test, sequential floats*all int 2's...\n");
	fprintf(fil, "\nNext test, sequential floats*all int 2's...\n");
	flomatmult256_opt(fm256seq, fm256all2);

	fprintf(stdout, "\n==================================\n\nStart optimized 512 testing, all int 1's*identity matrix...\n");
	fprintf(fil, "\n==================================\n\nStart optimized 512 testing, all int 1's*identity matrix...\n");
	intmatmult512_opt(im512all1, im512iden);	
	fprintf(stdout, "\nNext test, all int 2's*identity matrix...\n");
	fprintf(fil, "\nNext test, all int 2's*identity matrix...\n");
	intmatmult512_opt(im512all2, im512iden);
	fprintf(stdout, "\nNext test, sequential integers*identity matrix...\n");
	fprintf(fil, "\nNext test, sequential integers*identity matrix...\n");
	intmatmult512_opt(im512seq, im512iden);
	fprintf(stdout, "\nNext test, all float 1's*identity matrix...\n");
	fprintf(fil, "\nNext test, all float 1's*identity matrix...\n");
	flomatmult512_opt(fm512all1, fm512iden);
	fprintf(stdout, "\nNext test, all float 2's*identity matrix...\n");
	fprintf(fil, "\nNext test, all float 2's*identity matrix...\n");
	flomatmult512_opt(fm512all2, fm512iden);
	fprintf(stdout, "\nNext test, sequential floats*identity matrix...\n");
	fprintf(fil, "\nNext test, sequential floats*identity matrix...\n");
	flomatmult512_opt(fm512seq, fm512iden);

	fprintf(stdout, "\nNext test, all int 1's*all int 1's...\n");
	fprintf(fil, "\nNext test, all int 1's*all int 1's...\n");
	intmatmult512_opt(im512all1, im512all1);	
	fprintf(stdout, "\nNext test, all int 2's*all int 1's...\n");
	fprintf(fil, "\nNext test, all int 2's*all int 1's...\n");
	intmatmult512_opt(im512all2, im512all1);
	fprintf(stdout, "\nNext test, sequential integers*all int 1's...\n");
	fprintf(fil, "\nNext test, sequential integers*all int 1's...\n");
	intmatmult512_opt(im512seq, im512all1);
	fprintf(stdout, "\nNext test, all float 1's*all float 1's...\n");
	fprintf(fil, "\nNext test, all float 1's*all float 1's...\n");
	flomatmult512_opt(fm512all1, fm512all1);
	fprintf(stdout, "\nNext test, all float 2's*all float 1's...\n");
	fprintf(fil, "\nNext test, all float 2's*all float 1's...\n");
	flomatmult512_opt(fm512all2, fm512all1);
	fprintf(stdout, "\nNext test, sequential floats*all float 1's...\n");
	fprintf(fil, "\nNext test, sequential floats*all float 1's...\n");
	flomatmult512_opt(fm512seq, fm512all1);

	fprintf(stdout, "\nNext test, all int 1's*all int 2's...\n");
	fprintf(fil, "\nNext test, all int 1's*all int 2's...\n");
	intmatmult512_opt(im512all1, im512all2);	
	fprintf(stdout, "\nNext test, all int 2's*all int 2's...\n");
	fprintf(fil, "\nNext test, all int 2's*all int 2's...\n");
	intmatmult512_opt(im512all2, im512all2);
	fprintf(stdout, "\nNext test, sequential integers*all int 2's...\n");
	fprintf(fil, "\nNext test, sequential integers*all int 2's...\n");
	intmatmult512_opt(im512seq, im512all2);
	fprintf(stdout, "\nNext test, all float 1's*all int 2's...\n");
	fprintf(fil, "\nNext test, all float 1's*all int 2's...\n");
	flomatmult512_opt(fm512all1, fm512all2);
	fprintf(stdout, "\nNext test, all float 2's*all int 2's...\n");
	fprintf(fil, "\nNext test, all float 2's*all int 2's...\n");
	flomatmult512_opt(fm512all2, fm512all2);
	fprintf(stdout, "\nNext test, sequential floats*all int 2's...\n");
	fprintf(fil, "\nNext test, sequential floats*all int 2's...\n");
	flomatmult512_opt(fm512seq, fm512all2);





}
