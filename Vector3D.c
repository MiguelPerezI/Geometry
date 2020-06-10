#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "Vector3D.h"

Vector3D initVector3D(double x, double y, double z) {
	
	Vector3D ret;

		ret.x = x;
		ret.y = y;
		ret.z = z;

	return ret;
}

const Vector3D startVector3D(const double x, const double y, const double z) {
	
	Vector3D ret;

		ret.x = x;
		ret.y = y;
		ret.z = z;

	return ret;
}

void updateVector3D(Vector3D * v, Vector3D w) {
	v->x = w.x;
	v->y = w.y;
	v->z = w.z;
}

void updateVector3D1(Vector3D * v, double a, double b, double c) {
	v->x = a;
	v->y = b;
	v->z = c;
}

void writeVector3D(Vector3D v) {
	printf("(%lg, %lg, %lg)", v.x, v.y, v.z);
}

double norma(Vector3D v) {
	return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

Vector3D add(Vector3D a, Vector3D b) {
	Vector3D ret;
	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return ret;
}

void updateAdd(Vector3D * a, Vector3D b) {
	a->x = a->x + b.x;
	a->y = a->y + b.y;
	a->z = a->z + b.z;
}

Vector3D sub(Vector3D a, Vector3D b) {
	Vector3D ret;
	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return ret;
}

void updateSub(Vector3D * a, Vector3D b) {
	a->x = a->x + b.x;
	a->y = a->y + b.y;
	a->z = a->z + b.z;
}

Vector3D scale(double a, Vector3D v) {
	Vector3D ret;
	ret.x = a * v.x;
	ret.y = a * v.y;
	ret.z = a * v.z;
	return ret;
}

void updateScale(double a, Vector3D * v) {
	v->x = a * v->x;
	v->y = a * v->y;
	v->z = a * v->z;
}

//void scale(double a, Vector3D * v) {
//	
//	v->x *= a;
//	v->y *= a;
//	v->z *= a;
//
//}

Vector3D cruz(Vector3D a, Vector3D b) {
	return initVector3D(( a.y * b.z) - ( a.z * b.y),
						(-a.x * b.z) + ( a.z * b.x),
						( a.x * b.y) - ( a.y * b.x));
}

double dot(Vector3D a, Vector3D b) {
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

double distance(Vector3D a, Vector3D b) {
	Vector3D resta = sub(a, b);
	return norma(resta);
}

bool equalVector(Vector3D a, Vector3D b) {
	double epsilon = 0.00000000001;
	bool T;
	
	double d1 = sqrt(sub(a, b).x * sub(a, b).x);
	double d2 = sqrt(sub(a, b).y * sub(a, b).y);
	double d3 = sqrt(sub(a, b).z * sub(a, b).z);
	
	if (d1 < epsilon && d2 < epsilon && d3 < epsilon)
		T = true;
	else
		T = false;

	return T;
}

Vector3D unit(Vector3D a) {
	double d = norma(a);
	Vector3D ret = scale(1/d, a);
	return ret;
}

void updateUnit(Vector3D * a) {
	updateScale(1/sqrt((a->x * a->x) + (a->y * a->y) + (a->z * a->z)), a);	
}

bool vencidad(Vector3D x, Vector3D centro, double epsilon) {
	if (distance(x, centro) < epsilon)
		return true;
	else 
		return false;
}

Vector3D inversion3D(Vector3D p, double r, Vector3D gamma) {
	double d = distance(p, gamma);
	double check = sqrt((d - r) * (d - r));
	if (check < 0.0000001) {return p;}
	else {
		double dd = (r * r)/d;
		Vector3D u = unit(sub(p, gamma));
		u = scale(dd, u);
		u = add(u, gamma);

		return u;
	}
}

void updateInversion3D(Vector3D * p, double r, Vector3D gamma) {
	double d = sqrt(((p->x - gamma.x) * (p->x - gamma.x)) + ((p->y - gamma.y) * (p->y - gamma.y)) + ((p->z - gamma.z) * (p->z - gamma.z)));
	double check = sqrt((d - r) * (d - r));
	if (check < 0.0000001) {;}
	else {
		double dd = (r * r)/d;
		updateSub(p, gamma);
		updateUnit(p);
		updateScale(dd, p);
		updateAdd(p, gamma);
	}
}