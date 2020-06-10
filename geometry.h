#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdbool.h>
#include <stdarg.h>
#include "Vector3D.h"
#include "Matrix.h"

#ifndef _GEOMETRY_
#define _GEOMETRY_

#ifdef __cplusplus
extern "C" {
#endif

	struct Vector3DList{
		int n;
		Vector3D * v;
	};

	struct Vector3DList startVectorSpace(int n);
	struct Vector3DList VectorSpace(int count, ... );
	void printVectorList(struct Vector3DList lista);

	struct Simplex{
		int dim;
		struct Vector3DList vertexSpace;
		MATRIZ Adj;
		Vector3D normal;
	};

	struct Simplex startSimplex(int dim, struct Vector3DList lista);
	struct Simplex SimplexND(int dim_plus_one, ... );
	struct Simplex facet(Vector3D a, Vector3D b, Vector3D c);
	void updateFacet(struct Simplex * Facet, Vector3D new_a, Vector3D new_b, Vector3D new_c);
	void renderFacet(struct Simplex sim, struct rotationMats U, int mod);
	void printSimplexInfo(struct Simplex sim);
	void render_2_Simplex(struct Simplex sim, double theta, int ternario);
	void Cube(double r, Vector3D center, double theta);
	void invertedCube(double r, Vector3D center, Vector3D after, double theta);
	void auxSelectPiece(double r, Vector3D center, double theta);
	void invertedPlane(double rad, Vector3D center, double theta, int ternario);

	typedef struct _matrixMesh_{
		int m, n;
		struct Simplex **A;
	} MatrixMesh;

	MatrixMesh creaMatrixMesh(int m, int n);
	void printMatrixMesh(MatrixMesh mesh);

	struct Cube3D {
		double r;
		Vector3D position;
		struct Vector3DList vertices;
		MatrixMesh mesh;
		double invRad;
		Vector3D gamma;
		int counter;
	};

	struct Cube3D initCube3D(double r, Vector3D position);
	void printCube3D(struct Cube3D cube);
	void renderCube3D(struct Cube3D cube, struct rotationMats U);
	void updatedCube3D(struct Cube3D cube, struct rotationMats U, Vector3D position);

	struct Cube3D initInversive3D(double r, Vector3D position, double invRad, Vector3D gamma);

	typedef struct _matrixCube_{
		int m, n;
		struct Cube3D **A;
	} MatrixCube;

	MatrixCube creaMatrixCube(int m, int n);

	typedef struct _matrixCube3_{
		int m, n, k;
		struct Cube3D ***A;
	} MatrixCube3;

	MatrixCube3 creaMatrix3Cube(int m, int n, int k);

	struct CubicLattice3D {
		MatrixCube cubicSpace;
		double r;
		Vector3D position;
		int mod;
		int color;
		int sizeX;
		int sizeY;
		int sizeZ;
		int i1;
		int j1;
		int k1;
	};

	struct CubicLattice3D initCubicLattice3D(double r, int mod, int color, Vector3D position, int m, int n);
	struct CubicLattice3D initInvLattice3D(double r, int mod, int color, Vector3D position, int m, int n, double invRad, Vector3D gamma);
	void renderLattice(struct CubicLattice3D lattice, struct rotationMats U);
	void renderInvLattice(struct CubicLattice3D lattice, struct rotationMats U, Vector3D position);
	void renderDiscreteSphere(struct CubicLattice3D lattice, struct rotationMats U);


	struct CubicLattice3D3 {
		MatrixCube3 cubicSpace;
		double r;
		Vector3D position;
		int mod;
		int color;
		int sizeX;
		int sizeY;
		int sizeZ;
		int i1;
		int j1;
		int k1;
	};

	struct Lattice3D {
		MatrixCube * cubicSpace;
		double r;
		Vector3D position;
		int mod;
		int color;
		int sizeX;
		int sizeY;
		int sizeZ;
		int i1;
		int j1;
		int k1;
	};

	struct CubicLattice3D3 initCubicLattice3D3(double r, int mod, int color, Vector3D position, int m, int n, int k);
	void renderLattice3(struct CubicLattice3D3 lattice, struct rotationMats U, int mod, double bound);

	struct SelectorPiece {
		double r;
		Vector3D position;
		struct Vector3DList vertices;
		MatrixMesh mesh;
	};

	struct SelectorPiece initSelectorPiece(double r, Vector3D position);
	void renderSelectorPiece(struct SelectorPiece cube, Vector3D newPosition, struct rotationMats U);
	void updateSelectorPiece(struct SelectorPiece * selectorAux, Vector3D newPosition);

#ifdef __cplusplus
}
#endif

#endif