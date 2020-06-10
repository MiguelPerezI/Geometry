#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdbool.h>
#include <stdarg.h>
#include "Vector3D.h"
#include "Matrix.h"
#include "geometry.h"

struct Vector3DList startVectorSpace(int n) {
	struct Vector3DList ret = {n:n, v:NULL};
	ret.v = (Vector3D *) malloc (n * sizeof(Vector3D));

	return ret;
}

struct Vector3DList VectorSpace(int count, ... ) {
	va_list list;
	struct Vector3DList retList = startVectorSpace(count);

	int i;
	va_start(list, count);

	for (i = 0; i < count; i++) {
		retList.v[i] = va_arg(list, Vector3D);
	}

	va_end(list);

	return retList;
}

void printVectorList(struct Vector3DList lista) {
	int i;
	printf("\n");
	if (lista.v != NULL) {
		for (i = 0; i < lista.n; i++) {
			printf("%d.- ", i);
			writeVector3D(lista.v[i]);
			printf("\n");
		}
	} else {
		printf("\n\n---- List Empty ----\n\n");
	}
}

///////////////////////
//					 //
//     ND FACETS     //
//					 //   
///////////////////////

struct Simplex startSimplex(int dim, struct Vector3DList lista) {

	MATRIZ adjacent;
	adjacent = tableZeroReal(adjacent, dim + 1);
	struct Simplex ret = {dim:dim, vertexSpace:lista, Adj:adjacent};

	return ret;
}

struct Simplex SimplexND(int dim_plus_one, ... ) {
	va_list list;
	struct Vector3DList retList = startVectorSpace(dim_plus_one);

	int i;
	va_start(list, dim_plus_one);

	for (i = 0; i < dim_plus_one; i++) {
		retList.v[i] = va_arg(list, Vector3D);
	}

	va_end(list);

	return startSimplex(retList.n - 1, retList);
}

struct Simplex facet(Vector3D a, Vector3D b, Vector3D c) {
	struct Vector3DList retList = startVectorSpace(3);
	retList.v[0] = a;
	retList.v[1] = b;
	retList.v[2] = c;
	struct Simplex ret = startSimplex(3, retList);

	Vector3D normal = cruz(sub(retList.v[1], retList.v[0]), sub(retList.v[2], retList.v[0]));
  	normal = unit(normal);

  	ret.normal = normal;

  	return ret;
}

void updateFacet(struct Simplex * Facet, Vector3D new_a, Vector3D new_b, Vector3D new_c) {
	
	updateVector3D(&Facet->vertexSpace.v[0], new_a);
	updateVector3D(&Facet->vertexSpace.v[1], new_b);
	updateVector3D(&Facet->vertexSpace.v[2], new_c);

	updateVector3D(&Facet->normal, unit(cruz(sub(Facet->vertexSpace.v[1], Facet->vertexSpace.v[0]), sub(Facet->vertexSpace.v[2], Facet->vertexSpace.v[0]))) );
}

void printSimplexInfo(struct Simplex sim) {
	printf("\n\n-- We have defined the following simplex:");
	printf("-- Simplex dimension: %d\n", sim.dim);
	printf("-- Simplex vertex space:");
	printVectorList(sim.vertexSpace);
	printf("-- Simplex adjecency matrix: \n");
	escMatriz(sim.Adj);
}

void render_2_Simplex(struct Simplex sim, double theta, int ternario) {
 	MATRIZ mat;
 	mat = tableZeroReal(mat, 3);
  	mat.A[0][0] = 1;  mat.A[0][1] = 0;              mat.A[0][2] = 0;
  	mat.A[1][0] = 0;  mat.A[1][1] = cos(theta*1.0); mat.A[1][2] =-sin(theta*1.0);
  	mat.A[2][0] = 0;  mat.A[2][1] = sin(theta*1.0); mat.A[2][2] = cos(theta*1.0);

  	MATRIZ mat1;
  	mat1 = tableZeroReal(mat1, 3);
  	mat1.A[0][0] = cos(theta*1.0);  mat1.A[0][1] =-sin(theta*1.0); mat1.A[0][2] = 0;
  	mat1.A[1][0] = sin(theta*1.0);  mat1.A[1][1] = cos(theta*1.0); mat1.A[1][2] = 0;
  	mat1.A[2][0] = 0;               mat1.A[2][1] = 0;              mat1.A[2][2] = 1;

  	int i;
  	for (i = 0; i < sim.dim + 1; i++) {
  		sim.vertexSpace.v[i] = matMult3D(mat1, sim.vertexSpace.v[i]);
  	}

  	Vector3D normal = cruz(sub(sim.vertexSpace.v[1], sim.vertexSpace.v[0]), sub(sim.vertexSpace.v[2], sim.vertexSpace.v[0]));
  	normal = unit(normal);
  	
  	if (ternario%3 == 0) glColor3ub(200, 200, 200);
  	if (ternario%3 == 1) glColor3ub(200, 0, 0);
  	if (ternario%3 == 2) glColor3ub(0, 200, 0);

	glBegin(GL_TRIANGLES);
	glNormal3f(normal.x, normal.y, normal.z);
	glVertex3f( sim.vertexSpace.v[0].x, sim.vertexSpace.v[0].y, sim.vertexSpace.v[0].z);
	glVertex3f( sim.vertexSpace.v[1].x, sim.vertexSpace.v[1].y, sim.vertexSpace.v[1].z);
	glVertex3f( sim.vertexSpace.v[2].x, sim.vertexSpace.v[2].y, sim.vertexSpace.v[2].z);
	glEnd();
}

void renderFacet(struct Simplex sim, struct rotationMats U, int mod) {
	
  	if (mod%4 == 0) glColor3ub(200, 200, 200);
  	if (mod%4 == 1) glColor3ub(200, 0, 0);
  	if (mod%4 == 2) glColor3ub(0, 200, 0);
  	if (mod%4 == 3) glColor3ub(0, 0, 200);

    rot3D(&U, sim.normal);
  	glBegin(GL_TRIANGLES);
	glNormal3f( U.aux.x, U.aux.y, U.aux.z);
	rot3D(&U, sim.vertexSpace.v[0]);
	glVertex3f( U.aux.x, U.aux.y, U.aux.z);
	rot3D(&U, sim.vertexSpace.v[1]);
	glVertex3f( U.aux.x, U.aux.y, U.aux.z);
	rot3D(&U, sim.vertexSpace.v[2]);
	glVertex3f( U.aux.x, U.aux.y, U.aux.z);
	glEnd();

}

void Cube(double r, Vector3D center, double theta) {
	Vector3D w[8];
	w[0] = initVector3D( r + center.x, r + center.y, r + center.z);
	w[1] = initVector3D(-r + center.x, r + center.y, r + center.z);
	w[2] = initVector3D(-r + center.x,-r + center.y, r + center.z);
	w[3] = initVector3D( r + center.x,-r + center.y, r + center.z);
	w[4] = initVector3D( r + center.x, r + center.y,-r + center.z);
	w[5] = initVector3D(-r + center.x, r + center.y,-r + center.z);
	w[6] = initVector3D(-r + center.x,-r + center.y,-r + center.z);
	w[7] = initVector3D( r + center.x,-r + center.y,-r + center.z);

	//int i;
	//for (i = 0; i < 8; i++) {
	//	w[i] = inversion3D(w[i], 0.8, initVector3D(0, 0, 0));
	//}

	render_2_Simplex(SimplexND(3, w[0], w[1], w[2]), theta, 0);
	render_2_Simplex(SimplexND(3, w[2], w[3], w[0]), theta, 0);
	render_2_Simplex(SimplexND(3, w[4], w[7], w[6]), theta, 0);
	render_2_Simplex(SimplexND(3, w[6], w[5], w[4]), theta, 0);
	render_2_Simplex(SimplexND(3, w[0], w[3], w[7]), theta, 0);
	render_2_Simplex(SimplexND(3, w[7], w[4], w[0]), theta, 0);
	render_2_Simplex(SimplexND(3, w[1], w[5], w[6]), theta, 0);
	render_2_Simplex(SimplexND(3, w[6], w[2], w[1]), theta, 0);
	render_2_Simplex(SimplexND(3, w[0], w[4], w[5]), theta, 0);
	render_2_Simplex(SimplexND(3, w[5], w[1], w[0]), theta, 0);
	render_2_Simplex(SimplexND(3, w[3], w[2], w[6]), theta, 0);
	render_2_Simplex(SimplexND(3, w[6], w[7], w[3]), theta, 0);
}

void invertedCube(double r, Vector3D center, Vector3D after, double theta) {
	Vector3D w[8];
	w[0] = initVector3D( r + center.x, r + center.y, r + center.z);
	w[1] = initVector3D(-r + center.x, r + center.y, r + center.z);
	w[2] = initVector3D(-r + center.x,-r + center.y, r + center.z);
	w[3] = initVector3D( r + center.x,-r + center.y, r + center.z);
	w[4] = initVector3D( r + center.x, r + center.y,-r + center.z);
	w[5] = initVector3D(-r + center.x, r + center.y,-r + center.z);
	w[6] = initVector3D(-r + center.x,-r + center.y,-r + center.z);
	w[7] = initVector3D( r + center.x,-r + center.y,-r + center.z);

	int i;
	for (i = 0; i < 8; i++) {
		w[i] = inversion3D(w[i], 0.8, initVector3D(0, 0, 0));
		w[i] = add(w[i], after);
	}

	render_2_Simplex(SimplexND(3, w[0], w[1], w[2]), theta, 0);
	render_2_Simplex(SimplexND(3, w[2], w[3], w[0]), theta, 0);
	render_2_Simplex(SimplexND(3, w[4], w[7], w[6]), theta, 0);
	render_2_Simplex(SimplexND(3, w[6], w[5], w[4]), theta, 0);
	render_2_Simplex(SimplexND(3, w[0], w[3], w[7]), theta, 0);
	render_2_Simplex(SimplexND(3, w[7], w[4], w[0]), theta, 0);
	render_2_Simplex(SimplexND(3, w[1], w[5], w[6]), theta, 0);
	render_2_Simplex(SimplexND(3, w[6], w[2], w[1]), theta, 0);
	render_2_Simplex(SimplexND(3, w[0], w[4], w[5]), theta, 0);
	render_2_Simplex(SimplexND(3, w[5], w[1], w[0]), theta, 0);
	render_2_Simplex(SimplexND(3, w[3], w[2], w[6]), theta, 0);
	render_2_Simplex(SimplexND(3, w[6], w[7], w[3]), theta, 0);
}

void auxSelectPiece(double r, Vector3D center, double theta) {
	Vector3D w[8];
	w[0] = initVector3D( r + center.x, r + center.y,( 0.2*r) + center.z);
	w[1] = initVector3D(-r + center.x, r + center.y,( 0.2*r) + center.z);
	w[2] = initVector3D(-r + center.x,-r + center.y,( 0.2*r) + center.z);
	w[3] = initVector3D( r + center.x,-r + center.y,( 0.2*r) + center.z);
	w[4] = initVector3D( r + center.x, r + center.y,(-0.2*r) + center.z);
	w[5] = initVector3D(-r + center.x, r + center.y,(-0.2*r) + center.z);
	w[6] = initVector3D(-r + center.x,-r + center.y,(-0.2*r) + center.z);
	w[7] = initVector3D( r + center.x,-r + center.y,(-0.2*r) + center.z);

	render_2_Simplex(SimplexND(3, w[0], w[3], w[7]), theta, 2);
	render_2_Simplex(SimplexND(3, w[7], w[4], w[0]), theta, 2);
	render_2_Simplex(SimplexND(3, w[1], w[5], w[6]), theta, 2);
	render_2_Simplex(SimplexND(3, w[6], w[2], w[1]), theta, 2);
	render_2_Simplex(SimplexND(3, w[0], w[4], w[5]), theta, 2);
	render_2_Simplex(SimplexND(3, w[5], w[1], w[0]), theta, 2);
	render_2_Simplex(SimplexND(3, w[3], w[2], w[6]), theta, 2);
	render_2_Simplex(SimplexND(3, w[6], w[7], w[3]), theta, 2);
}

void invertedPlane(double rad, Vector3D center, double theta, int ternario) {
	int i;
	int j;
	int k;

	for (int j = -6; j < 7; j++)
		for (int k = -6; k < 7; k++) {
			if (j%2 == 0 && k%2 == 0 || j%2 != 0 && k%2 != 0) {
				if (j != 0 && k != 0) {
					if (ternario%4 == 0) invertedCube(0.1, initVector3D((2 * rad * j), 0, (2 * rad * k)), center, theta);
					if (ternario%4 == 1) invertedCube(0.1, initVector3D((2 * rad * j), 0, (2 * rad * k)), scale(-1, center), theta);
					if (ternario%4 == 2) invertedCube(0.1, initVector3D(0, (2 * rad * j), (2 * rad * k)), center, theta);
					if (ternario%4 == 3) invertedCube(0.1, initVector3D(0, (2 * rad * j), (2 * rad * k)), scale(-1, center), theta);
				}
	      	}
		}


}

///////////////////////
//					 //
//    MATRIX MESH    //
//					 //   
///////////////////////


MatrixMesh creaMatrixMesh(int m, int n) {
  MatrixMesh ret = {
                  m : m,
                  n : n, 
                  A : NULL
                };
  int i;
  ret.A = (struct Simplex**) malloc (m * sizeof(struct Simplex*));
  if (ret.A != NULL){
    for(i = 0; i < m; i++){
      ret.A[i] = (struct Simplex *) malloc (n * sizeof(struct Simplex));
      if (ret.A[i] == NULL){
        while(i > 0){
          free(ret.A[--i]);
          ret.A[i] = NULL;
        }
        break;
      }
    }
  }

  return ret;
}

void printMatrixMesh(MatrixMesh mesh) {
	
	int i, j;
	for (i = 0; j < mesh.m; i++) {
		for (j = 0; j < mesh.n; j++) {
			printf("HELLLLO\n");
			printSimplexInfo(mesh.A[i][j]);
			printf("\n\n");
		}
	}
}

///////////////////////
//					 //
//   CUBE GEOMETRY   //
//					 //   
///////////////////////



struct Cube3D initCube3D(double r, Vector3D position) {

	Vector3D w0 = initVector3D( r + position.x, r + position.y, r + position.z);
	Vector3D w1 = initVector3D(-r + position.x, r + position.y, r + position.z);
	Vector3D w2 = initVector3D(-r + position.x,-r + position.y, r + position.z);
	Vector3D w3 = initVector3D( r + position.x,-r + position.y, r + position.z);
	Vector3D w4 = initVector3D( r + position.x, r + position.y,-r + position.z);
	Vector3D w5 = initVector3D(-r + position.x, r + position.y,-r + position.z);
	Vector3D w6 = initVector3D(-r + position.x,-r + position.y,-r + position.z);
	Vector3D w7 = initVector3D( r + position.x,-r + position.y,-r + position.z);

	struct Vector3DList vertices = VectorSpace(8, w0, w1, w2, w3, w4, w5, w6, w7);

	struct Cube3D cube = {
							r : r,
							position : position,
							vertices : vertices
						 };

	cube.mesh = creaMatrixMesh(6, 2);

	cube.mesh.A[0][0] = facet(vertices.v[0], vertices.v[1], vertices.v[2]); 
	cube.mesh.A[0][1] = facet(vertices.v[2], vertices.v[3], vertices.v[0]);

	cube.mesh.A[1][0] = facet(vertices.v[4], vertices.v[7], vertices.v[6]);
	cube.mesh.A[1][1] = facet(vertices.v[6], vertices.v[5], vertices.v[4]);

	cube.mesh.A[2][0] = facet(vertices.v[0], vertices.v[3], vertices.v[7]);
	cube.mesh.A[2][1] = facet(vertices.v[7], vertices.v[4], vertices.v[0]);

	cube.mesh.A[3][0] = facet(vertices.v[1], vertices.v[5], vertices.v[6]);
	cube.mesh.A[3][1] = facet(vertices.v[6], vertices.v[2], vertices.v[1]);

	cube.mesh.A[4][0] = facet(vertices.v[0], vertices.v[4], vertices.v[5]);
	cube.mesh.A[4][1] = facet(vertices.v[5], vertices.v[1], vertices.v[0]);

	cube.mesh.A[5][0] = facet(vertices.v[3], vertices.v[2], vertices.v[6]);
	cube.mesh.A[5][1] = facet(vertices.v[6], vertices.v[7], vertices.v[3]);

	return cube;
}

struct Cube3D initInversive3D(double r, Vector3D position, double invRad, Vector3D gamma) {

	Vector3D w0 = initVector3D( r + position.x, r + position.y, r + position.z);
	Vector3D w1 = initVector3D(-r + position.x, r + position.y, r + position.z);
	Vector3D w2 = initVector3D(-r + position.x,-r + position.y, r + position.z);
	Vector3D w3 = initVector3D( r + position.x,-r + position.y, r + position.z);
	Vector3D w4 = initVector3D( r + position.x, r + position.y,-r + position.z);
	Vector3D w5 = initVector3D(-r + position.x, r + position.y,-r + position.z);
	Vector3D w6 = initVector3D(-r + position.x,-r + position.y,-r + position.z);
	Vector3D w7 = initVector3D( r + position.x,-r + position.y,-r + position.z);

	struct Vector3DList vertices = VectorSpace(8, w0, w1, w2, w3, w4, w5, w6, w7);

	struct Cube3D cube = {
							r : r,
							position : position,
							vertices : vertices,
							invRad : invRad,
							gamma : gamma, 
							counter : 0
						 };

	cube.mesh = creaMatrixMesh(6, 2);

	int i;
	for (i = 0; i < vertices.n; i++)
		vertices.v[i] = inversion3D(vertices.v[i], invRad, gamma);

	cube.mesh.A[0][0] = facet(vertices.v[0], vertices.v[1], vertices.v[2]); 
	cube.mesh.A[0][1] = facet(vertices.v[2], vertices.v[3], vertices.v[0]);
	
	cube.mesh.A[1][0] = facet(vertices.v[4], vertices.v[7], vertices.v[6]);
	cube.mesh.A[1][1] = facet(vertices.v[6], vertices.v[5], vertices.v[4]);

	cube.mesh.A[2][0] = facet(vertices.v[0], vertices.v[3], vertices.v[7]);
	cube.mesh.A[2][1] = facet(vertices.v[7], vertices.v[4], vertices.v[0]);

	cube.mesh.A[3][0] = facet(vertices.v[1], vertices.v[5], vertices.v[6]);
	cube.mesh.A[3][1] = facet(vertices.v[6], vertices.v[2], vertices.v[1]);

	cube.mesh.A[4][0] = facet(vertices.v[0], vertices.v[4], vertices.v[5]);
	cube.mesh.A[4][1] = facet(vertices.v[5], vertices.v[1], vertices.v[0]);

	cube.mesh.A[5][0] = facet(vertices.v[3], vertices.v[2], vertices.v[6]);
	cube.mesh.A[5][1] = facet(vertices.v[6], vertices.v[7], vertices.v[3]);

	return cube;
}

void updateInvCube3D(struct Cube3D * invCube, Vector3D newPosition, Vector3D pos) {

	updateVector3D1(&invCube->vertices.v[0], invCube->r + newPosition.x + pos.x, invCube->r + newPosition.y + pos.y, invCube->r + newPosition.z + pos.z);
	updateVector3D1(&invCube->vertices.v[1],-invCube->r + newPosition.x + pos.x, invCube->r + newPosition.y + pos.y, invCube->r + newPosition.z + pos.z);
	updateVector3D1(&invCube->vertices.v[2],-invCube->r + newPosition.x + pos.x,-invCube->r + newPosition.y + pos.y, invCube->r + newPosition.z + pos.z);
	updateVector3D1(&invCube->vertices.v[3], invCube->r + newPosition.x + pos.x,-invCube->r + newPosition.y + pos.y, invCube->r + newPosition.z + pos.z);
	updateVector3D1(&invCube->vertices.v[4], invCube->r + newPosition.x + pos.x, invCube->r + newPosition.y + pos.y,-invCube->r + newPosition.z + pos.z);
	updateVector3D1(&invCube->vertices.v[5],-invCube->r + newPosition.x + pos.x, invCube->r + newPosition.y + pos.y,-invCube->r + newPosition.z + pos.z);
	updateVector3D1(&invCube->vertices.v[6],-invCube->r + newPosition.x + pos.x,-invCube->r + newPosition.y + pos.y,-invCube->r + newPosition.z + pos.z);
	updateVector3D1(&invCube->vertices.v[7], invCube->r + newPosition.x + pos.x,-invCube->r + newPosition.y + pos.y,-invCube->r + newPosition.z + pos.z);

	for (invCube->counter = 0; invCube->counter < 8; invCube->counter++)
		updateInversion3D(&invCube->vertices.v[invCube->counter], invCube->invRad, invCube->gamma);

	invCube->position = newPosition;

	updateFacet(&invCube->mesh.A[0][0], invCube->vertices.v[0], invCube->vertices.v[1], invCube->vertices.v[2]);
	updateFacet(&invCube->mesh.A[0][1], invCube->vertices.v[2], invCube->vertices.v[3], invCube->vertices.v[0]);
	updateFacet(&invCube->mesh.A[1][0], invCube->vertices.v[4], invCube->vertices.v[7], invCube->vertices.v[6]);
	updateFacet(&invCube->mesh.A[1][1], invCube->vertices.v[6], invCube->vertices.v[5], invCube->vertices.v[4]);
	updateFacet(&invCube->mesh.A[2][0], invCube->vertices.v[0], invCube->vertices.v[3], invCube->vertices.v[7]);
	updateFacet(&invCube->mesh.A[2][1], invCube->vertices.v[7], invCube->vertices.v[4], invCube->vertices.v[0]);
	updateFacet(&invCube->mesh.A[3][0], invCube->vertices.v[1], invCube->vertices.v[5], invCube->vertices.v[6]);
	updateFacet(&invCube->mesh.A[3][1], invCube->vertices.v[6], invCube->vertices.v[2], invCube->vertices.v[1]);
	updateFacet(&invCube->mesh.A[4][0], invCube->vertices.v[0], invCube->vertices.v[4], invCube->vertices.v[5]);
	updateFacet(&invCube->mesh.A[4][1], invCube->vertices.v[5], invCube->vertices.v[1], invCube->vertices.v[0]);
	updateFacet(&invCube->mesh.A[5][0], invCube->vertices.v[3], invCube->vertices.v[2], invCube->vertices.v[6]);
	updateFacet(&invCube->mesh.A[5][1], invCube->vertices.v[6], invCube->vertices.v[7], invCube->vertices.v[3]);

}

void printCube3D(struct Cube3D cube) {
	
	int i;
	printf("\n");
	for (i = 0; i < cube.vertices.n; i++) {
		writeVector3D(cube.vertices.v[i]);
		printf("\n");
	}
	printf("\n%d faces with %d triangles each\n", cube.mesh.m, cube.mesh.n);
}

void renderCube3D(struct Cube3D cube, struct rotationMats U) {

	renderFacet(cube.mesh.A[0][0], U, 0);
	renderFacet(cube.mesh.A[0][1], U, 0);

	renderFacet(cube.mesh.A[1][0], U, 0);
	renderFacet(cube.mesh.A[1][1], U, 0);

	renderFacet(cube.mesh.A[2][0], U, 0);
	renderFacet(cube.mesh.A[2][1], U, 0);

	renderFacet(cube.mesh.A[3][0], U, 0);
	renderFacet(cube.mesh.A[3][1], U, 0);

	renderFacet(cube.mesh.A[4][0], U, 0);
	renderFacet(cube.mesh.A[4][1], U, 0);

	renderFacet(cube.mesh.A[5][0], U, 0);
	renderFacet(cube.mesh.A[5][1], U, 0);
}



////////////////////////////
//					      //
//     SELECTOR PIECE     //
//					      //
////////////////////////////

struct SelectorPiece initSelectorPiece(double r, Vector3D position) {

	Vector3D w0 = initVector3D( r + position.x, r + position.y,( r * 0.2) + position.z);
	Vector3D w1 = initVector3D(-r + position.x, r + position.y,( r * 0.2) + position.z);
	Vector3D w2 = initVector3D(-r + position.x,-r + position.y,( r * 0.2) + position.z);
	Vector3D w3 = initVector3D( r + position.x,-r + position.y,( r * 0.2) + position.z);
	Vector3D w4 = initVector3D( r + position.x, r + position.y,(-r * 0.2) + position.z);
	Vector3D w5 = initVector3D(-r + position.x, r + position.y,(-r * 0.2) + position.z);
	Vector3D w6 = initVector3D(-r + position.x,-r + position.y,(-r * 0.2) + position.z);
	Vector3D w7 = initVector3D( r + position.x,-r + position.y,(-r * 0.2) + position.z);

	struct Vector3DList vertices = VectorSpace(8, w0, w1, w2, w3, w4, w5, w6, w7);

	struct SelectorPiece cube = {
							r : r,
							position : position,
							vertices : vertices
						 };

	cube.mesh = creaMatrixMesh(6, 2);
	int i;
	double dif = sqrt((0.2*0.2) + (0.2*0.2));

	cube.mesh.A[0][0] = facet(vertices.v[0], vertices.v[1], vertices.v[2]); 
	cube.mesh.A[0][1] = facet(vertices.v[2], vertices.v[3], vertices.v[0]);

	cube.mesh.A[1][0] = facet(vertices.v[4], vertices.v[7], vertices.v[6]);
	cube.mesh.A[1][1] = facet(vertices.v[6], vertices.v[5], vertices.v[4]);

	cube.mesh.A[2][0] = facet(vertices.v[0], vertices.v[3], vertices.v[7]);
	cube.mesh.A[2][1] = facet(vertices.v[7], vertices.v[4], vertices.v[0]);

	cube.mesh.A[3][0] = facet(vertices.v[1], vertices.v[5], vertices.v[6]);
	cube.mesh.A[3][1] = facet(vertices.v[6], vertices.v[2], vertices.v[1]);

	cube.mesh.A[4][0] = facet(vertices.v[0], vertices.v[4], vertices.v[5]);
	cube.mesh.A[4][1] = facet(vertices.v[5], vertices.v[1], vertices.v[0]);

	cube.mesh.A[5][0] = facet(vertices.v[3], vertices.v[2], vertices.v[6]);
	cube.mesh.A[5][1] = facet(vertices.v[6], vertices.v[7], vertices.v[3]);

	return cube;
}

void updateSelectorPiece(struct SelectorPiece * selectorAux, Vector3D newPosition) {

	selectorAux->vertices.v[0].x = selectorAux->r + newPosition.x;
	selectorAux->vertices.v[0].y = selectorAux->r + newPosition.y;
	selectorAux->vertices.v[0].z = (selectorAux->r * 0.2) + newPosition.z;

	selectorAux->vertices.v[1].x =-selectorAux->r + newPosition.x;
	selectorAux->vertices.v[1].y = selectorAux->r + newPosition.y;
	selectorAux->vertices.v[1].z = (selectorAux->r * 0.2) + newPosition.z;

	selectorAux->vertices.v[2].x =-selectorAux->r + newPosition.x;
	selectorAux->vertices.v[2].y =-selectorAux->r + newPosition.y;
	selectorAux->vertices.v[2].z = (selectorAux->r * 0.2) + newPosition.z;

	selectorAux->vertices.v[3].x = selectorAux->r + newPosition.x;
	selectorAux->vertices.v[3].y =-selectorAux->r + newPosition.y;
	selectorAux->vertices.v[3].z = (selectorAux->r * 0.2) + newPosition.z;

	selectorAux->vertices.v[4].x = selectorAux->r + newPosition.x;
	selectorAux->vertices.v[4].y = selectorAux->r + newPosition.y;
	selectorAux->vertices.v[4].z =(-selectorAux->r * 0.2) + newPosition.z;

	selectorAux->vertices.v[5].x =-selectorAux->r + newPosition.x;
	selectorAux->vertices.v[5].y = selectorAux->r + newPosition.y;
	selectorAux->vertices.v[5].z =(-selectorAux->r * 0.2) + newPosition.z;

	selectorAux->vertices.v[6].x =-selectorAux->r + newPosition.x;
	selectorAux->vertices.v[6].y =-selectorAux->r + newPosition.y;
	selectorAux->vertices.v[6].z =(-selectorAux->r * 0.2) + newPosition.z;

	selectorAux->vertices.v[7].x = selectorAux->r + newPosition.x;
	selectorAux->vertices.v[7].y =-selectorAux->r + newPosition.y;
	selectorAux->vertices.v[7].z =(-selectorAux->r * 0.2) + newPosition.z;

	selectorAux->position = newPosition;

	updateFacet(&selectorAux->mesh.A[0][0], selectorAux->vertices.v[0], selectorAux->vertices.v[1], selectorAux->vertices.v[2]);
	updateFacet(&selectorAux->mesh.A[0][1], selectorAux->vertices.v[2], selectorAux->vertices.v[3], selectorAux->vertices.v[0]);
	updateFacet(&selectorAux->mesh.A[1][0], selectorAux->vertices.v[4], selectorAux->vertices.v[7], selectorAux->vertices.v[6]);
	updateFacet(&selectorAux->mesh.A[1][1], selectorAux->vertices.v[6], selectorAux->vertices.v[5], selectorAux->vertices.v[4]);
	updateFacet(&selectorAux->mesh.A[2][0], selectorAux->vertices.v[0], selectorAux->vertices.v[3], selectorAux->vertices.v[7]);
	updateFacet(&selectorAux->mesh.A[2][1], selectorAux->vertices.v[7], selectorAux->vertices.v[4], selectorAux->vertices.v[0]);
	updateFacet(&selectorAux->mesh.A[3][0], selectorAux->vertices.v[1], selectorAux->vertices.v[5], selectorAux->vertices.v[6]);
	updateFacet(&selectorAux->mesh.A[3][1], selectorAux->vertices.v[6], selectorAux->vertices.v[2], selectorAux->vertices.v[1]);
	updateFacet(&selectorAux->mesh.A[4][0], selectorAux->vertices.v[0], selectorAux->vertices.v[4], selectorAux->vertices.v[5]);
	updateFacet(&selectorAux->mesh.A[4][1], selectorAux->vertices.v[5], selectorAux->vertices.v[1], selectorAux->vertices.v[0]);
	updateFacet(&selectorAux->mesh.A[5][0], selectorAux->vertices.v[3], selectorAux->vertices.v[2], selectorAux->vertices.v[6]);
	updateFacet(&selectorAux->mesh.A[5][1], selectorAux->vertices.v[6], selectorAux->vertices.v[7], selectorAux->vertices.v[3]);

}

void renderSelectorPiece(struct SelectorPiece cube, Vector3D newPosition, struct rotationMats U) {

	updateSelectorPiece(&cube, newPosition);

	renderFacet(cube.mesh.A[2][0], U, 3);
	renderFacet(cube.mesh.A[2][1], U, 3);

	renderFacet(cube.mesh.A[3][0], U, 3);
	renderFacet(cube.mesh.A[3][1], U, 3);

	renderFacet(cube.mesh.A[4][0], U, 3);
	renderFacet(cube.mesh.A[4][1], U, 3);

	renderFacet(cube.mesh.A[5][0], U, 3);
	renderFacet(cube.mesh.A[5][1], U, 3);
}

////////////////////////////
//					      //
//    3D CUBIC LATTICE    //
//					      //
////////////////////////////


MatrixCube creaMatrixCube(int m, int n) {
  MatrixCube ret = {
                  m : m,
                  n : n, 
                  A : NULL
                };
  int i;
  ret.A = (struct Cube3D**) malloc (m * sizeof(struct Cube3D*));
  if (ret.A != NULL){
    for(i = 0; i < m; i++){
      ret.A[i] = (struct Cube3D *) malloc (n * sizeof(struct Cube3D));
      if (ret.A[i] == NULL){
        while(i > 0){
          free(ret.A[--i]);
          ret.A[i] = NULL;
        }
        break;
      }
    }
  }

  return ret;
}

MatrixCube3 creaMatrix3Cube(int m, int n, int k) {
	MatrixCube3 ret = {
                  m : m,
                  n : n,
                  k : k, 
                  A : NULL
                };
    int i;
    int j;
    ret.A = (struct Cube3D***) malloc (m * sizeof(struct Cube3D**));
    if (ret.A != NULL) {
    	for (i = 0; i < m; i++) {

    		ret.A[i] = (struct Cube3D**) malloc (n * sizeof(struct Cube3D*));
    		if (ret.A[i] != NULL) {
    			for (j = 0; j < n; j++) {
    				ret.A[i][j] = (struct Cube3D*) malloc (k * sizeof(struct Cube3D));
    				
    			}
    		}
    	
    	}
    }

    return ret;
}

//TailMatrixCube tailMatrixCube(int k) {
//	TailMatrixCube ret = {
//                  k : k, 
//                  A : NULL
//                };
//    ret.A = (MatrixCube*) malloc (k * sizeof(MatrixCube));
//}

struct CubicLattice3D initCubicLattice3D(double r, int mod, int color, Vector3D position, int m, int n) {
	
	int i, j;
	int sizeX = 2 * m;
	int sizeY = 2 * n;

	struct CubicLattice3D lattice = {
								r : r,
								position : position,
								mod : mod,
								color : color,
								sizeX : sizeX,
								sizeY : sizeY,
								i1 : 0,
								j1 : 0,
								k1 : 0
							};

	lattice.cubicSpace = creaMatrixCube(sizeX, sizeY);

	for (i = -m; i < m; i++) {
		for (j = -n; j < n; j++) {
			Vector3D primePosition = initVector3D(2 * r * i, 2 * r * j, 0); 
			lattice.cubicSpace.A[i + m][j + n] = initCube3D(r, add(primePosition, position));
		}
	}

	return lattice;
}

struct CubicLattice3D3 initCubicLattice3D3(double r, int mod, int color, Vector3D position, int m, int n, int k) {
	
	int i, j, k0;
	int sizeX = 2 * m;
	int sizeY = 2 * n;
	int sizeZ = 2 * k;

	struct CubicLattice3D3 lattice = {
								r : r,
								position : position,
								mod : mod,
								color : color,
								sizeX : sizeX,
								sizeY : sizeY,
								sizeZ : sizeZ,
								i1 : 0,
								j1 : 0,
								k1 : 0
							};

	lattice.cubicSpace = creaMatrix3Cube(sizeX, sizeY, sizeZ);
	double R = 8;
	R /= 50;
	for (i = -m; i < m; i++) {
		for (j = -n; j < n; j++) {
			for (k0 = -k; k0 < k; k0++) {
				Vector3D primePosition = initVector3D(2 * R * i, 2 * R * j, 2 * R * k0); 
				lattice.cubicSpace.A[i + m][j + n][k0 + k] = initCube3D(R, add(primePosition, position));
			}
		}
	}

	return lattice;
}

struct CubicLattice3D initInvLattice3D(double r, int mod, int color, Vector3D position, int m, int n, double invRad, Vector3D gamma) {
	
	int i, j;
	int sizeX = 2 * m;
	int sizeY = 2 * n;

	struct CubicLattice3D lattice = {
								r : r,
								position : position,
								mod : mod,
								color : color,
								sizeX : sizeX,
								sizeY : sizeY,
								i1 : 0,
								j1 : 0,
								k1 : 0
							};

	lattice.cubicSpace = creaMatrixCube(sizeX, sizeY);

	for (i = -m; i < m; i++) {
		for (j = -n; j < n; j++) {
			Vector3D primePosition = initVector3D(2 * r * i, 2 * r * j, 0); 
			lattice.cubicSpace.A[i + m][j + n] = initInversive3D(r, add(primePosition, position), invRad, gamma);
		}
	}

	return lattice;
}

void renderLattice(struct CubicLattice3D lattice, struct rotationMats U) {

	for (lattice.i1 = 0; lattice.i1 < lattice.sizeX; lattice.i1++) {
		for (lattice.j1 = 0; lattice.j1 < lattice.sizeY; lattice.j1++) {
			if (lattice.i1%2 == 0 && lattice.j1%2 == 0 || lattice.i1%2 != 0 && lattice.j1%2 != 0){
				renderCube3D(lattice.cubicSpace.A[lattice.i1][lattice.j1], U);
			}
		}
	}
}

void renderLattice3(struct CubicLattice3D3 lattice, struct rotationMats U, int mod, double bound) {

	for (lattice.i1 = 0; lattice.i1 < lattice.sizeX; lattice.i1++) {
		for (lattice.j1 = 0; lattice.j1 < lattice.sizeY; lattice.j1++) {
			for (lattice.k1 = 0; lattice.k1 < lattice.sizeZ; lattice.k1++)
				if ((lattice.i1 + lattice.j1 + lattice.k1)%1 == mod)
					if ((lattice.i1 + lattice.j1 + lattice.k1) > -1){
						if ((8 - bound) < norma(lattice.cubicSpace.A[lattice.i1][lattice.j1][lattice.k1].position) && norma(lattice.cubicSpace.A[lattice.i1][lattice.j1][lattice.k1].position) < 8) {
							renderCube3D(lattice.cubicSpace.A[lattice.i1][lattice.j1][lattice.k1], U);
						}
					}
		}
	}
}

void renderInvLattice(struct CubicLattice3D lattice, struct rotationMats U, Vector3D position) {

	for (lattice.i1 = 0; lattice.i1 < lattice.sizeX; lattice.i1++) {
		for (lattice.j1 = 0; lattice.j1 < lattice.sizeY; lattice.j1++) {
			if (lattice.i1%2 == 0 && lattice.j1%2 == 0 || lattice.i1%2 != 0 && lattice.j1%2 != 0)
				if (lattice.i1 != lattice.sizeX/2 && lattice.j1 != lattice.sizeY/2) {
					updateInvCube3D(&lattice.cubicSpace.A[lattice.i1][lattice.j1], lattice.cubicSpace.A[lattice.i1][lattice.j1].position, position);
					renderCube3D(lattice.cubicSpace.A[lattice.i1][lattice.j1], U);
				}
		}
	}
}