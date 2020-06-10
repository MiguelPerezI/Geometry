#include <stdbool.h>

#ifndef _VECTOR3D_
#define _VECTOR3D_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _Vector3D_{
	double x;
	double y;
	double z;
}Vector3D;

Vector3D initVector3D(double x, double y, double z);
const Vector3D startVector3D(const double x, const double y, const double z);
void updateVector3D(Vector3D * v, Vector3D w);
void updateVector3D1(Vector3D * v, double , double , double);
void writeVector3D(Vector3D v);
double norma(Vector3D v);

Vector3D add(Vector3D a, Vector3D b);
void updateAdd(Vector3D * a, Vector3D b);

Vector3D sub(Vector3D a, Vector3D b);
void updateSub(Vector3D * a, Vector3D b);

Vector3D scale(double a, Vector3D v);
void updateScale(double a, Vector3D * v);

Vector3D cruz(Vector3D a, Vector3D b);
Vector3D unit(Vector3D a);
void updateUnit(Vector3D * a);

double dot(Vector3D a, Vector3D b);
double distance(Vector3D a, Vector3D b);
bool vencidad(Vector3D x, Vector3D centro, double epsilon);
bool equalVector(Vector3D a, Vector3D b);
Vector3D inversion3D(Vector3D p, double r, Vector3D gamma);
void updateInversion3D(Vector3D * p, double r, Vector3D gamma);

#ifdef __cplusplus
}
#endif

#endif
