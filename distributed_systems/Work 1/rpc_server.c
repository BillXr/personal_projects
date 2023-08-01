/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "rpc.h"
#include <math.h>

float *
xmeasure_1_svc(nX *argp, struct svc_req *rqstp)
{
	static float  result;
	result = 0;

	// Measure of vector X calculation
	for(int i=0; i<argp->n; i++)
		result += pow((double)argp->X.X_val[i], 2);

	result = sqrt(result);

	// RPC_SERVER PRINTS
	printf("DATA RECEIVED FROM RPC_CLIENT\n");
	printf("n = %d\n", argp->n);
	for(int i=0; i<argp->n; i++)
		printf("X[%d] = %d\n", i, argp->X.X_val[i]);
	printf("DATA SENT TO RPC_CLIENT\n");
	printf("result = %.2f\n", result);
	printf("-------------------------\n\n");

	return &result;
}

int *
xyinnerprod_1_svc(nXY *argp, struct svc_req *rqstp)
{
	static int  result;
	result = 0;

	// Vector inner product calculation
	for(int i=0; i<argp->n; i++)
		result += argp->X.X_val[i] * argp->Y.Y_val[i];

	// RPC_SERVER PRINTS
	printf("DATA RECEIVED FROM RPC_CLIENT\n");
	printf("n = %d\n", argp->n);
	for(int i=0; i<argp->n; i++)
		printf("X[%d] = %d\tY[%d] = %d\n", i, argp->X.X_val[i], i, argp->Y.Y_val[i]);
	printf("DATA SENT TO RPC_CLIENT\n");
	printf("result = %d\n", result);
	printf("-------------------------\n\n");

	return &result;
}

struct float_array *
xyavg_1_svc(nXY *argp, struct svc_req *rqstp)
{
	static struct float_array  result;

	result.arr.arr_len = argp->n;
	result.arr.arr_val = (float *) malloc(2*sizeof(float));

	result.arr.arr_val[0] = 0; // Ex
	result.arr.arr_val[1] = 0; // Ey

	// Average of vectors X, Y calculation
	for(int i=0; i<argp->n; i++){
		result.arr.arr_val[0] += argp->X.X_val[i];
		result.arr.arr_val[1] += argp->Y.Y_val[i];
	}

	result.arr.arr_val[0] = result.arr.arr_val[0] / (float)argp->n;
	result.arr.arr_val[1] = result.arr.arr_val[1] / (float)argp->n;
	
	// RPC_SERVER PRINTS
	printf("DATA RECEIVED FROM RPC_CLIENT\n");
	printf("n = %d\n", argp->n);
	for(int i=0; i<argp->n; i++)
		printf("X[%d] = %d\tY[%d] = %d\n", i, argp->X.X_val[i], i, argp->Y.Y_val[i]);
	printf("DATA SENT TO RPC_CLIENT\n");
	printf("result[0] = %.2f\n", result.arr.arr_val[0]);
	printf("result[1] = %.2f\n", result.arr.arr_val[1]);
	printf("-------------------------\n\n");

	return &result;
}

struct float_array *
xyrprod_1_svc(nXYr *argp, struct svc_req *rqstp)
{
	static struct float_array  result;

	result.arr.arr_len = argp->n;
	result.arr.arr_val = (float *) malloc(argp->n*sizeof(float));

	// Result calculation
	for(int i=0; i<argp->n; i++)
		result.arr.arr_val[i] = argp->r * ((float)argp->X.X_val[i] + (float)argp->Y.Y_val[i]);

	// RPC_SERVER PRINTS
	printf("DATA RECEIVED FROM RPC_CLIENT\n");
	printf("r = %.2f\n", argp->r);
	printf("n = %d\n", argp->n);
	for(int i=0; i<argp->n; i++)
		printf("X[%d] = %d\tY[%d] = %d\n", i, argp->X.X_val[i], i, argp->Y.Y_val[i]);
	printf("DATA SENT TO RPC_CLIENT\n");
	for(int i=0; i<argp->n; i++)
		printf("result[%d] = %.2f\n", i, result.arr.arr_val[i]);

	printf("-------------------------\n\n");

	return &result;
}
