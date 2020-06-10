#include "list.h"
#include <stdbool.h>
#include "Vector3D.h"

#ifndef _MATRIX_
#define _MATRIX_

#ifdef __cplusplus
extern "C" {
#endif
typedef struct _matriz_{
  int m, n;
  double **A;
}MATRIZ;

int digitCounter(int n);
void space(int n);
int Index(struct lista *pl, int vertex);

MATRIZ creaEspacioMatriz(int m, int n);
int leeMatriz(MATRIZ *mat);
int escMatriz(MATRIZ mat);
MATRIZ tableZeroReal(MATRIZ Table1, int n);
MATRIZ AdjMatrixWeights(int n);
int liberaEspacioMatriz(MATRIZ *mat);
Vector3D matMult3D(MATRIZ mat, Vector3D v);
void addEdgeWW(MATRIZ mat, int m, int n, double weight);
struct lista* vecindadR(MATRIZ mat, struct lista *pl, int s);
void dijkstraW(MATRIZ mat, int s, int f);

typedef struct _matrixV_{
	int m, n;
	Vector3D **A;
}MatrixV;

MatrixV creaEspacioMatrixV(int m, int n);

struct rotationMats{
	double theta;
	MATRIZ rotZ;
	Vector3D aX;
	Vector3D aY;
	Vector3D aZ;
	Vector3D aux;
};

struct rotationMats initRotation(double theta);
void updateRotation(struct rotationMats * U, double theta);
void rot3D(struct rotationMats * U, Vector3D v);

#ifdef __cplusplus
}
#endif

#endif