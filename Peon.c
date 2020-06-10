#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdbool.h>
#include "Vector3D.h"
#include "Matrix.h"
#include "Peon.h"
#include "geometry.h"

///////////////
//			 //
//    PEON   //
//           //
///////////////

struct Peon initPeon(int n, Vector3D c, double r, bool w) {
	struct Peon p0 = {
						position : c,
						radius : r,
						numPartition : n,
						white : w,
						i : 0,
						j : 0
					};

	p0.points = creaEspacioMatrixV(6, n + 1);
	p0.mesh = creaMatrixMesh(10, n);

	int j;
	for (j = 0; j < n + 1; j++) {
		p0.points.A[0][j] = initVector3D(r * cos(j * (2 * M_PI) / n) + c.x, r * sin(j * (2 * M_PI) / n) + c.y, c.z);
		p0.points.A[1][j] = initVector3D(0.7*r * cos(j * (2 * M_PI) / n) + c.x, 0.7*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.05);
		p0.points.A[2][j] = initVector3D(0.25*r * cos(j * (2 * M_PI) / n) + c.x, 0.25*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.05);
		p0.points.A[3][j] = initVector3D(0.75*r * cos(j * (2 * M_PI) / n) + c.x, 0.75*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.15);
		p0.points.A[4][j] = initVector3D(0.3*r * cos(j * (2 * M_PI) / n) + c.x, 0.3*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.25);
		p0.points.A[5][j] = initVector3D(0.01*r * cos(j * (2 * M_PI) / n) + c.x, 0.01*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.28);
	}

	for (j = 0; j < n; j++) {
		p0.mesh.A[0][j] = facet(p0.points.A[0][j], p0.points.A[0][j+1], p0.points.A[1][j]);
		p0.mesh.A[1][j] = facet(p0.points.A[0][j+1], p0.points.A[1][j+1], p0.points.A[1][j]);
		p0.mesh.A[2][j] = facet(p0.points.A[1][j], p0.points.A[1][j+1], p0.points.A[2][j]);
		p0.mesh.A[3][j] = facet(p0.points.A[1][j+1], p0.points.A[2][j+1], p0.points.A[2][j]);
		p0.mesh.A[4][j] = facet(p0.points.A[2][j], p0.points.A[2][j+1], p0.points.A[3][j]);
		p0.mesh.A[5][j] = facet(p0.points.A[2][j+1], p0.points.A[3][j+1], p0.points.A[3][j]);
		p0.mesh.A[6][j] = facet(p0.points.A[3][j], p0.points.A[3][j+1], p0.points.A[4][j]);
		p0.mesh.A[7][j] = facet(p0.points.A[3][j+1], p0.points.A[4][j+1], p0.points.A[4][j]);
		p0.mesh.A[8][j] = facet(p0.points.A[4][j], p0.points.A[4][j+1], p0.points.A[5][j]);
		p0.mesh.A[9][j] = facet(p0.points.A[4][j+1], p0.points.A[5][j+1], p0.points.A[5][j]);
	}

	return p0;
}

void updatePawn(struct Peon * peon, Vector3D newPosition) {

	for (peon->j = 0; peon->j < peon->numPartition + 1; peon->j++) {
		peon->points.A[0][peon->j].x = (peon->radius) * cos(peon->j * (2 * M_PI) / peon->numPartition) + newPosition.x;
		peon->points.A[0][peon->j].y = (peon->radius) * sin(peon->j * (2 * M_PI) / peon->numPartition) + newPosition.y;
		peon->points.A[0][peon->j].z =  newPosition.z;
		
		peon->points.A[1][peon->j].x = 0.7*(peon->radius) * cos(peon->j * (2 * M_PI) / peon->numPartition) + newPosition.x;
		peon->points.A[1][peon->j].y = 0.7*(peon->radius) * sin(peon->j * (2 * M_PI) / peon->numPartition) + newPosition.y;
		peon->points.A[1][peon->j].z = newPosition.z + 0.05;

		peon->points.A[2][peon->j].x = 0.25*(peon->radius) * cos(peon->j * (2 * M_PI) / peon->numPartition) + newPosition.x;
		peon->points.A[2][peon->j].y = 0.25*(peon->radius) * sin(peon->j * (2 * M_PI) / peon->numPartition) + newPosition.y;
		peon->points.A[2][peon->j].z = newPosition.z + 0.05;

		peon->points.A[3][peon->j].x = 0.75*(peon->radius) * cos(peon->j * (2 * M_PI) / peon->numPartition) + newPosition.x;
		peon->points.A[3][peon->j].y = 0.75*(peon->radius) * sin(peon->j * (2 * M_PI) / peon->numPartition) + newPosition.y;
		peon->points.A[3][peon->j].z = newPosition.z + 0.15;

		peon->points.A[4][peon->j].x = 0.3*(peon->radius) * cos(peon->j * (2 * M_PI) / peon->numPartition) + newPosition.x;
		peon->points.A[4][peon->j].y = 0.3*(peon->radius) * sin(peon->j * (2 * M_PI) / peon->numPartition) + newPosition.y;
		peon->points.A[4][peon->j].z = newPosition.z + 0.25;

		peon->points.A[5][peon->j].x = 0.01*(peon->radius) * cos(peon->j * (2 * M_PI) / peon->numPartition) + newPosition.x;
		peon->points.A[5][peon->j].y = 0.01*(peon->radius) * sin(peon->j * (2 * M_PI) / peon->numPartition) + newPosition.y;
		peon->points.A[5][peon->j].z = newPosition.z + 0.28;
	}

	peon->position = newPosition;

	for (peon->j = 0; peon->j < peon->numPartition; peon->j++) {
		updateFacet(&peon->mesh.A[0][peon->j],peon->points.A[0][peon->j], peon->points.A[0][peon->j+1], peon->points.A[1][peon->j]);
		updateFacet(&peon->mesh.A[1][peon->j],peon->points.A[0][peon->j+1], peon->points.A[1][peon->j+1], peon->points.A[1][peon->j]);
		updateFacet(&peon->mesh.A[2][peon->j],peon->points.A[1][peon->j], peon->points.A[1][peon->j+1], peon->points.A[2][peon->j]);
		updateFacet(&peon->mesh.A[3][peon->j],peon->points.A[1][peon->j+1], peon->points.A[2][peon->j+1], peon->points.A[2][peon->j]);
		updateFacet(&peon->mesh.A[4][peon->j],peon->points.A[2][peon->j], peon->points.A[2][peon->j+1], peon->points.A[3][peon->j]);
		updateFacet(&peon->mesh.A[5][peon->j],peon->points.A[2][peon->j+1], peon->points.A[3][peon->j+1], peon->points.A[3][peon->j]);
		updateFacet(&peon->mesh.A[6][peon->j],peon->points.A[3][peon->j], peon->points.A[3][peon->j+1], peon->points.A[4][peon->j]);
		updateFacet(&peon->mesh.A[7][peon->j],peon->points.A[3][peon->j+1], peon->points.A[4][peon->j+1], peon->points.A[4][peon->j]);
		updateFacet(&peon->mesh.A[8][peon->j],peon->points.A[4][peon->j], peon->points.A[4][peon->j+1], peon->points.A[5][peon->j]);
		updateFacet(&peon->mesh.A[9][peon->j],peon->points.A[4][peon->j+1], peon->points.A[5][peon->j+1], peon->points.A[5][peon->j]);
	}
}

void renderPawn(struct Peon peon, Vector3D position, struct rotationMats U) {
	
	updatePawn(&peon, position);
	for (peon.j = 0; peon.j < peon.numPartition; peon.j++) {
		if (peon.white == true) {
			renderFacet(peon.mesh.A[0][peon.j], U, 0);
			renderFacet(peon.mesh.A[1][peon.j], U, 0);
			renderFacet(peon.mesh.A[2][peon.j], U, 0);
			renderFacet(peon.mesh.A[3][peon.j], U, 0);
			renderFacet(peon.mesh.A[4][peon.j], U, 0);
			renderFacet(peon.mesh.A[5][peon.j], U, 0);
			renderFacet(peon.mesh.A[6][peon.j], U, 0);
			renderFacet(peon.mesh.A[7][peon.j], U, 0);
			renderFacet(peon.mesh.A[8][peon.j], U, 0);
			renderFacet(peon.mesh.A[9][peon.j], U, 0);
		} else {
			renderFacet(peon.mesh.A[0][peon.j], U, 1);
			renderFacet(peon.mesh.A[1][peon.j], U, 1);
			renderFacet(peon.mesh.A[2][peon.j], U, 1);
			renderFacet(peon.mesh.A[3][peon.j], U, 1);
			renderFacet(peon.mesh.A[4][peon.j], U, 1);
			renderFacet(peon.mesh.A[5][peon.j], U, 1);
			renderFacet(peon.mesh.A[6][peon.j], U, 1);
			renderFacet(peon.mesh.A[7][peon.j], U, 1);
			renderFacet(peon.mesh.A[8][peon.j], U, 1);
			renderFacet(peon.mesh.A[9][peon.j], U, 1);
		}
	}
}


///////////////
//			 //
//   TORRE   //
//           //
///////////////

struct Peon initTorre(int n, Vector3D c, double r, bool w) {
	struct Peon t0 = {
						position : c,
						radius : r,
						numPartition : n,
						white : w,
						i : 0,
						j : 0
					};

	t0.points = creaEspacioMatrixV(6, n + 1);
	t0.mesh = creaMatrixMesh(10, n);

	int j;
	for (j = 0; j < n + 1; j++) {
		t0.points.A[0][j] = initVector3D(r * cos(j * (2 * M_PI) / n) + c.x, r * sin(j * (2 * M_PI) / n) + c.y, c.z);
		t0.points.A[1][j] = initVector3D(0.5*r * cos(j * (2 * M_PI) / n) + c.x, 0.5*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.05);
		t0.points.A[2][j] = initVector3D(0.5*r * cos(j * (2 * M_PI) / n) + c.x, 0.5*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.4);
		t0.points.A[3][j] = initVector3D(0.75*r * cos(j * (2 * M_PI) / n) + c.x, 0.75*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.45);
		t0.points.A[4][j] = initVector3D(0.6*r * cos(j * (2 * M_PI) / n) + c.x, 0.6*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.55);
		t0.points.A[5][j] = initVector3D(0.01*r * cos(j * (2 * M_PI) / n) + c.x, 0.01*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.5);
	}

	for (j = 0; j < n; j++) {
		t0.mesh.A[0][j] = facet(t0.points.A[0][j], t0.points.A[0][j+1], t0.points.A[1][j]);
		t0.mesh.A[1][j] = facet(t0.points.A[0][j+1], t0.points.A[1][j+1], t0.points.A[1][j]);
		t0.mesh.A[2][j] = facet(t0.points.A[1][j], t0.points.A[1][j+1], t0.points.A[2][j]);
		t0.mesh.A[3][j] = facet(t0.points.A[1][j+1], t0.points.A[2][j+1], t0.points.A[2][j]);
		t0.mesh.A[4][j] = facet(t0.points.A[2][j], t0.points.A[2][j+1], t0.points.A[3][j]);
		t0.mesh.A[5][j] = facet(t0.points.A[2][j+1], t0.points.A[3][j+1], t0.points.A[3][j]);
		t0.mesh.A[6][j] = facet(t0.points.A[3][j], t0.points.A[3][j+1], t0.points.A[4][j]);
		t0.mesh.A[7][j] = facet(t0.points.A[3][j+1], t0.points.A[4][j+1], t0.points.A[4][j]);
		t0.mesh.A[8][j] = facet(t0.points.A[4][j], t0.points.A[4][j+1], t0.points.A[5][j]);
		t0.mesh.A[9][j] = facet(t0.points.A[4][j+1], t0.points.A[5][j+1], t0.points.A[5][j]);
	}

	return t0;
}

void updateTorre(struct Peon * torre, Vector3D newPosition) {

	for (torre->j = 0; torre->j < torre->numPartition + 1; torre->j++) {
		torre->points.A[0][torre->j].x = (torre->radius) * cos(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.x;
		torre->points.A[0][torre->j].y = (torre->radius) * sin(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.y;
		torre->points.A[0][torre->j].z =  newPosition.z;
		
		torre->points.A[1][torre->j].x = 0.5*(torre->radius) * cos(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.x;
		torre->points.A[1][torre->j].y = 0.5*(torre->radius) * sin(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.y;
		torre->points.A[1][torre->j].z = newPosition.z + 0.05;

		torre->points.A[2][torre->j].x = 0.5*(torre->radius) * cos(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.x;
		torre->points.A[2][torre->j].y = 0.5*(torre->radius) * sin(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.y;
		torre->points.A[2][torre->j].z = newPosition.z + 0.4;

		torre->points.A[3][torre->j].x = 0.75*(torre->radius) * cos(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.x;
		torre->points.A[3][torre->j].y = 0.75*(torre->radius) * sin(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.y;
		torre->points.A[3][torre->j].z = newPosition.z + 0.45;

		torre->points.A[4][torre->j].x = 0.6*(torre->radius) * cos(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.x;
		torre->points.A[4][torre->j].y = 0.6*(torre->radius) * sin(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.y;
		torre->points.A[4][torre->j].z = newPosition.z + 0.55;

		torre->points.A[5][torre->j].x = 0.01*(torre->radius) * cos(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.x;
		torre->points.A[5][torre->j].y = 0.01*(torre->radius) * sin(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.y;
		torre->points.A[5][torre->j].z = newPosition.z + 0.5;
	}

	torre->position = newPosition;

	for (torre->j = 0; torre->j < torre->numPartition; torre->j++) {
		updateFacet(&torre->mesh.A[0][torre->j],torre->points.A[0][torre->j], torre->points.A[0][torre->j+1], torre->points.A[1][torre->j]);
		updateFacet(&torre->mesh.A[1][torre->j],torre->points.A[0][torre->j+1], torre->points.A[1][torre->j+1], torre->points.A[1][torre->j]);
		updateFacet(&torre->mesh.A[2][torre->j],torre->points.A[1][torre->j], torre->points.A[1][torre->j+1], torre->points.A[2][torre->j]);
		updateFacet(&torre->mesh.A[3][torre->j],torre->points.A[1][torre->j+1], torre->points.A[2][torre->j+1], torre->points.A[2][torre->j]);
		updateFacet(&torre->mesh.A[4][torre->j],torre->points.A[2][torre->j], torre->points.A[2][torre->j+1], torre->points.A[3][torre->j]);
		updateFacet(&torre->mesh.A[5][torre->j],torre->points.A[2][torre->j+1], torre->points.A[3][torre->j+1], torre->points.A[3][torre->j]);
		updateFacet(&torre->mesh.A[6][torre->j],torre->points.A[3][torre->j], torre->points.A[3][torre->j+1], torre->points.A[4][torre->j]);
		updateFacet(&torre->mesh.A[7][torre->j],torre->points.A[3][torre->j+1], torre->points.A[4][torre->j+1], torre->points.A[4][torre->j]);
		updateFacet(&torre->mesh.A[8][torre->j],torre->points.A[4][torre->j], torre->points.A[4][torre->j+1], torre->points.A[5][torre->j]);
		updateFacet(&torre->mesh.A[9][torre->j],torre->points.A[4][torre->j+1], torre->points.A[5][torre->j+1], torre->points.A[5][torre->j]);
	}
}

void renderTorre(struct Peon torre, Vector3D position, struct rotationMats U) {
	
	updateTorre(&torre, position);
	for (torre.j = 0; torre.j < torre.numPartition; torre.j++) {
		if (torre.white == true) {
			renderFacet(torre.mesh.A[0][torre.j], U, 0);
			renderFacet(torre.mesh.A[1][torre.j], U, 0);
			renderFacet(torre.mesh.A[2][torre.j], U, 0);
			renderFacet(torre.mesh.A[3][torre.j], U, 0);
			renderFacet(torre.mesh.A[4][torre.j], U, 0);
			renderFacet(torre.mesh.A[5][torre.j], U, 0);
			renderFacet(torre.mesh.A[6][torre.j], U, 0);
			renderFacet(torre.mesh.A[7][torre.j], U, 0);
			renderFacet(torre.mesh.A[8][torre.j], U, 0);
			renderFacet(torre.mesh.A[9][torre.j], U, 0);
		} else {
			renderFacet(torre.mesh.A[0][torre.j], U, 1);
			renderFacet(torre.mesh.A[1][torre.j], U, 1);
			renderFacet(torre.mesh.A[2][torre.j], U, 1);
			renderFacet(torre.mesh.A[3][torre.j], U, 1);
			renderFacet(torre.mesh.A[4][torre.j], U, 1);
			renderFacet(torre.mesh.A[5][torre.j], U, 1);
			renderFacet(torre.mesh.A[6][torre.j], U, 1);
			renderFacet(torre.mesh.A[7][torre.j], U, 1);
			renderFacet(torre.mesh.A[8][torre.j], U, 1);
			renderFacet(torre.mesh.A[9][torre.j], U, 1);
		}
	}
}

/////////////////
//			   //
//    ARFIL    //
//             //
/////////////////

struct Peon initArfil(int n, Vector3D c, double r, bool w) {
	struct Peon t0 = {
						position : c,
						radius : r,
						numPartition : n,
						white : w,
						i : 0,
						j : 0
					};

	t0.points = creaEspacioMatrixV(6, n + 1);
	t0.mesh = creaMatrixMesh(10, n);

	int j;
	for (j = 0; j < n + 1; j++) {
		t0.points.A[0][j] = initVector3D(r * cos(j * (2 * M_PI) / n) + c.x, r * sin(j * (2 * M_PI) / n) + c.y, c.z);
		t0.points.A[1][j] = initVector3D(0.5*r * cos(j * (2 * M_PI) / n) + c.x, 0.5*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.05);
		t0.points.A[2][j] = initVector3D(0.9*r * cos(j * (2 * M_PI) / n) + c.x, 0.5*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.2);
		t0.points.A[3][j] = initVector3D(0.75*r * cos(j * (2 * M_PI) / n) + c.x, 0.75*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.35);
		t0.points.A[4][j] = initVector3D(0.4*r * cos(j * (2 * M_PI) / n) + c.x, 0.4*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.5);
		t0.points.A[5][j] = initVector3D(0.01*r * cos(j * (2 * M_PI) / n) + c.x, 0.01*r * sin(j * (2 * M_PI) / n) + c.y, c.z + 0.6);
	}

	for (j = 0; j < n; j++) {
		t0.mesh.A[0][j] = facet(t0.points.A[0][j], t0.points.A[0][j+1], t0.points.A[1][j]);
		t0.mesh.A[1][j] = facet(t0.points.A[0][j+1], t0.points.A[1][j+1], t0.points.A[1][j]);
		t0.mesh.A[2][j] = facet(t0.points.A[1][j], t0.points.A[1][j+1], t0.points.A[2][j]);
		t0.mesh.A[3][j] = facet(t0.points.A[1][j+1], t0.points.A[2][j+1], t0.points.A[2][j]);
		t0.mesh.A[4][j] = facet(t0.points.A[2][j], t0.points.A[2][j+1], t0.points.A[3][j]);
		t0.mesh.A[5][j] = facet(t0.points.A[2][j+1], t0.points.A[3][j+1], t0.points.A[3][j]);
		t0.mesh.A[6][j] = facet(t0.points.A[3][j], t0.points.A[3][j+1], t0.points.A[4][j]);
		t0.mesh.A[7][j] = facet(t0.points.A[3][j+1], t0.points.A[4][j+1], t0.points.A[4][j]);
		t0.mesh.A[8][j] = facet(t0.points.A[4][j], t0.points.A[4][j+1], t0.points.A[5][j]);
		t0.mesh.A[9][j] = facet(t0.points.A[4][j+1], t0.points.A[5][j+1], t0.points.A[5][j]);
	}

	return t0;
}

void updateArfil(struct Peon * torre, Vector3D newPosition) {

	for (torre->j = 0; torre->j < torre->numPartition + 1; torre->j++) {
		torre->points.A[0][torre->j].x = (torre->radius) * cos(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.x;
		torre->points.A[0][torre->j].y = (torre->radius) * sin(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.y;
		torre->points.A[0][torre->j].z =  newPosition.z;
		
		torre->points.A[1][torre->j].x = 0.5*(torre->radius) * cos(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.x;
		torre->points.A[1][torre->j].y = 0.5*(torre->radius) * sin(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.y;
		torre->points.A[1][torre->j].z = newPosition.z + 0.05;

		torre->points.A[2][torre->j].x = 0.3*(torre->radius) * cos(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.x;
		torre->points.A[2][torre->j].y = 0.3*(torre->radius) * sin(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.y;
		torre->points.A[2][torre->j].z = newPosition.z + 0.2;

		torre->points.A[3][torre->j].x = 0.65*(torre->radius) * cos(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.x;
		torre->points.A[3][torre->j].y = 0.65*(torre->radius) * sin(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.y;
		torre->points.A[3][torre->j].z = newPosition.z + 0.35;

		torre->points.A[4][torre->j].x = 0.4*(torre->radius) * cos(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.x;
		torre->points.A[4][torre->j].y = 0.4*(torre->radius) * sin(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.y;
		torre->points.A[4][torre->j].z = newPosition.z + 0.5;

		torre->points.A[5][torre->j].x = 0.01*(torre->radius) * cos(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.x;
		torre->points.A[5][torre->j].y = 0.01*(torre->radius) * sin(torre->j * (2 * M_PI) / torre->numPartition) + newPosition.y;
		torre->points.A[5][torre->j].z = newPosition.z + 0.6;
	}

	torre->position = newPosition;

	for (torre->j = 0; torre->j < torre->numPartition; torre->j++) {
		updateFacet(&torre->mesh.A[0][torre->j],torre->points.A[0][torre->j], torre->points.A[0][torre->j+1], torre->points.A[1][torre->j]);
		updateFacet(&torre->mesh.A[1][torre->j],torre->points.A[0][torre->j+1], torre->points.A[1][torre->j+1], torre->points.A[1][torre->j]);
		updateFacet(&torre->mesh.A[2][torre->j],torre->points.A[1][torre->j], torre->points.A[1][torre->j+1], torre->points.A[2][torre->j]);
		updateFacet(&torre->mesh.A[3][torre->j],torre->points.A[1][torre->j+1], torre->points.A[2][torre->j+1], torre->points.A[2][torre->j]);
		updateFacet(&torre->mesh.A[4][torre->j],torre->points.A[2][torre->j], torre->points.A[2][torre->j+1], torre->points.A[3][torre->j]);
		updateFacet(&torre->mesh.A[5][torre->j],torre->points.A[2][torre->j+1], torre->points.A[3][torre->j+1], torre->points.A[3][torre->j]);
		updateFacet(&torre->mesh.A[6][torre->j],torre->points.A[3][torre->j], torre->points.A[3][torre->j+1], torre->points.A[4][torre->j]);
		updateFacet(&torre->mesh.A[7][torre->j],torre->points.A[3][torre->j+1], torre->points.A[4][torre->j+1], torre->points.A[4][torre->j]);
		updateFacet(&torre->mesh.A[8][torre->j],torre->points.A[4][torre->j], torre->points.A[4][torre->j+1], torre->points.A[5][torre->j]);
		updateFacet(&torre->mesh.A[9][torre->j],torre->points.A[4][torre->j+1], torre->points.A[5][torre->j+1], torre->points.A[5][torre->j]);
	}
}

void renderArfil(struct Peon torre, Vector3D position, struct rotationMats U) {
	
	updateArfil(&torre, position);
	for (torre.j = 0; torre.j < torre.numPartition; torre.j++) {
		if (torre.white == true) {
			renderFacet(torre.mesh.A[0][torre.j], U, 0);
			renderFacet(torre.mesh.A[1][torre.j], U, 0);
			renderFacet(torre.mesh.A[2][torre.j], U, 0);
			renderFacet(torre.mesh.A[3][torre.j], U, 0);
			renderFacet(torre.mesh.A[4][torre.j], U, 0);
			renderFacet(torre.mesh.A[5][torre.j], U, 0);
			renderFacet(torre.mesh.A[6][torre.j], U, 0);
			renderFacet(torre.mesh.A[7][torre.j], U, 0);
			renderFacet(torre.mesh.A[8][torre.j], U, 0);
			renderFacet(torre.mesh.A[9][torre.j], U, 0);
		} else {
			renderFacet(torre.mesh.A[0][torre.j], U, 1);
			renderFacet(torre.mesh.A[1][torre.j], U, 1);
			renderFacet(torre.mesh.A[2][torre.j], U, 1);
			renderFacet(torre.mesh.A[3][torre.j], U, 1);
			renderFacet(torre.mesh.A[4][torre.j], U, 1);
			renderFacet(torre.mesh.A[5][torre.j], U, 1);
			renderFacet(torre.mesh.A[6][torre.j], U, 1);
			renderFacet(torre.mesh.A[7][torre.j], U, 1);
			renderFacet(torre.mesh.A[8][torre.j], U, 1);
			renderFacet(torre.mesh.A[9][torre.j], U, 1);
		}
	}
}

/////////////////
//			   //
//    REINA    //
//             //
/////////////////

struct Peon initReina(int n, Vector3D c, double r, bool w) {
	struct Peon t0 = {
						position : c,
						radius : r,
						numPartition : n,
						white : w,
						i : 0,
						j : 0,
						ocilation : 0,
						layers : 12
					};

	t0.points = creaEspacioMatrixV(12, n + 1);
	t0.mesh = creaMatrixMesh(18, n);
	t0.sculpture = creaEspacioMatriz(t0.layers, 2);

	int i;
	int j;
	for (i = 0; i < t0.points.m; i++)
		for (j = 0; j < n + 1; j++) {
			t0.points.A[i][j] = initVector3D(0, 0, 0);
		}

	for (i = 0; i < t0.mesh.m; i++)
		for (j = 0; j < n; j++) {
			t0.mesh.A[i][j] = facet(t0.points.A[0][j], t0.points.A[0][j+1], t0.points.A[1][j]);
		}

	t0.sculpture.A[0][0] = 0.5; t0.sculpture.A[0][1] = 0.0;
	t0.sculpture.A[1][0] = 1.0; t0.sculpture.A[1][1] = 0.1;
	t0.sculpture.A[2][0] = 1.0; t0.sculpture.A[2][1] = 0.2;
	t0.sculpture.A[3][0] = 0.2; t0.sculpture.A[3][1] = 0.15;
	t0.sculpture.A[4][0] = 0.4; t0.sculpture.A[4][1] = 0.3;
	t0.sculpture.A[5][0] = 0.01; t0.sculpture.A[5][1] = 0.4;
	t0.sculpture.A[6][0] = 1.0; t0.sculpture.A[6][1] = 0.4;
	t0.sculpture.A[7][0] = 1.0; t0.sculpture.A[7][1] = 0.475;
	t0.sculpture.A[8][0] = 0.5; t0.sculpture.A[8][1] = 0.55;
	t0.sculpture.A[9][0] = 0.1; t0.sculpture.A[9][1] = 0.7;
	t0.sculpture.A[10][0] = 1.0; t0.sculpture.A[10][1] = 0.7;
	t0.sculpture.A[11][0] = 1.0; t0.sculpture.A[11][1] = 0.8;

	return t0;
}

void auxUpdatePleaseReina(int i, struct Peon * dude, double radio, double altura, Vector3D newPosition, double var) {
	
	if (i == 6 || i == 7) {
			dude->points.A[i][dude->j].x = sin(var) * (dude->radius) * cos(dude->j * (2 * M_PI) / dude->numPartition) + newPosition.x;
			dude->points.A[i][dude->j].y = sin(var) * (dude->radius) * sin(dude->j * (2 * M_PI) / dude->numPartition) + newPosition.y;
			dude->points.A[i][dude->j].z = newPosition.z + altura;
	} else {
		if (i == 10 || i == 11) {
			dude->points.A[i][dude->j].x = cos(var) * (dude->radius) * cos(dude->j * (2 * M_PI) / dude->numPartition) + newPosition.x;
			dude->points.A[i][dude->j].y = cos(var)  * (dude->radius) * sin(dude->j * (2 * M_PI) / dude->numPartition) + newPosition.y;
			dude->points.A[i][dude->j].z = newPosition.z + altura;
		} else {
			dude->points.A[i][dude->j].x = radio * (dude->radius) * cos(dude->j * (2 * M_PI) / dude->numPartition) + newPosition.x;
			dude->points.A[i][dude->j].y = radio * (dude->radius) * sin(dude->j * (2 * M_PI) / dude->numPartition) + newPosition.y;
			dude->points.A[i][dude->j].z = newPosition.z + altura;
		}
	}
		
}

void updateReina(struct Peon * Reina, Vector3D newPosition, double var) {

	for (Reina->j = 0; Reina->j < Reina->numPartition + 1; Reina->j++) {
		for (Reina->i = 0; Reina->i < Reina->layers; Reina->i++) 
			auxUpdatePleaseReina(Reina->i, Reina, Reina->sculpture.A[Reina->i][0], Reina->sculpture.A[Reina->i][1], newPosition, var);
		}

	Reina->position = newPosition;

	for (Reina->j = 0; Reina->j < Reina->numPartition; Reina->j++) {
		updateFacet(&Reina->mesh.A[0][Reina->j],Reina->points.A[0][Reina->j], Reina->points.A[0][Reina->j+1], Reina->points.A[1][Reina->j]);
		updateFacet(&Reina->mesh.A[1][Reina->j],Reina->points.A[0][Reina->j+1], Reina->points.A[1][Reina->j+1], Reina->points.A[1][Reina->j]);
		updateFacet(&Reina->mesh.A[2][Reina->j],Reina->points.A[1][Reina->j], Reina->points.A[1][Reina->j+1], Reina->points.A[2][Reina->j]);
		updateFacet(&Reina->mesh.A[3][Reina->j],Reina->points.A[1][Reina->j+1], Reina->points.A[2][Reina->j+1], Reina->points.A[2][Reina->j]);
		updateFacet(&Reina->mesh.A[4][Reina->j],Reina->points.A[2][Reina->j], Reina->points.A[2][Reina->j+1], Reina->points.A[3][Reina->j]);
		updateFacet(&Reina->mesh.A[5][Reina->j],Reina->points.A[2][Reina->j+1], Reina->points.A[3][Reina->j+1], Reina->points.A[3][Reina->j]);
		updateFacet(&Reina->mesh.A[6][Reina->j],Reina->points.A[3][Reina->j], Reina->points.A[3][Reina->j+1], Reina->points.A[4][Reina->j]);
		updateFacet(&Reina->mesh.A[7][Reina->j],Reina->points.A[3][Reina->j+1], Reina->points.A[4][Reina->j+1], Reina->points.A[4][Reina->j]);
		updateFacet(&Reina->mesh.A[8][Reina->j],Reina->points.A[4][Reina->j], Reina->points.A[4][Reina->j+1], Reina->points.A[5][Reina->j]);
		updateFacet(&Reina->mesh.A[9][Reina->j],Reina->points.A[4][Reina->j+1], Reina->points.A[5][Reina->j+1], Reina->points.A[5][Reina->j]);

		updateFacet(&Reina->mesh.A[10][Reina->j],Reina->points.A[6][Reina->j], Reina->points.A[6][Reina->j+1], Reina->points.A[7][Reina->j]);
		updateFacet(&Reina->mesh.A[11][Reina->j],Reina->points.A[6][Reina->j+1], Reina->points.A[7][Reina->j+1], Reina->points.A[7][Reina->j]);

		updateFacet(&Reina->mesh.A[12][Reina->j],Reina->points.A[5][Reina->j], Reina->points.A[5][Reina->j+1], Reina->points.A[8][Reina->j]);
		updateFacet(&Reina->mesh.A[13][Reina->j],Reina->points.A[5][Reina->j+1], Reina->points.A[8][Reina->j+1], Reina->points.A[8][Reina->j]);

		updateFacet(&Reina->mesh.A[14][Reina->j],Reina->points.A[8][Reina->j], Reina->points.A[8][Reina->j+1], Reina->points.A[9][Reina->j]);
		updateFacet(&Reina->mesh.A[15][Reina->j],Reina->points.A[8][Reina->j+1], Reina->points.A[9][Reina->j+1], Reina->points.A[9][Reina->j]);

		updateFacet(&Reina->mesh.A[16][Reina->j],Reina->points.A[10][Reina->j], Reina->points.A[10][Reina->j+1], Reina->points.A[11][Reina->j]);
		updateFacet(&Reina->mesh.A[17][Reina->j],Reina->points.A[10][Reina->j+1], Reina->points.A[11][Reina->j+1], Reina->points.A[11][Reina->j]);
	}
}

void renderReina(struct Peon Reina, Vector3D position, struct rotationMats U, double var) {
	
	updateReina(&Reina, position, var);
	for (Reina.j = 0; Reina.j < Reina.numPartition; Reina.j++) {
		if (Reina.white == true) {
			for (Reina.i = 0; Reina.i < Reina.mesh.m; Reina.i++)
				renderFacet(Reina.mesh.A[Reina.i][Reina.j], U, 0);
		} else {
			for (Reina.i = 0; Reina.i < Reina.mesh.m; Reina.i++)
				renderFacet(Reina.mesh.A[Reina.i][Reina.j], U, 1);
		}
	}
}

/////////////////
//			   //
//     REY     //
//             //
/////////////////

struct Peon initRey(int n, Vector3D c, double r, bool w) {
	struct Peon t0 = {
						position : c,
						radius : r,
						numPartition : n,
						white : w,
						i : 0,
						j : 0,
						ocilation : 0,
						layers : 18
					};

	t0.points = creaEspacioMatrixV(t0.layers, n + 1);
	t0.mesh = creaMatrixMesh(24, n);
	t0.sculpture = creaEspacioMatriz(t0.layers, 2);

	int i;
	int j;
	for (i = 0; i < t0.points.m; i++)
		for (j = 0; j < n + 1; j++) {
			t0.points.A[i][j] = initVector3D(0, 0, 0);
		}

	for (i = 0; i < t0.mesh.m; i++)
		for (j = 0; j < n; j++) {
			t0.mesh.A[i][j] = facet(t0.points.A[0][j], t0.points.A[0][j+1], t0.points.A[1][j]);
		}

	t0.sculpture.A[0][0] = 1.0; t0.sculpture.A[0][1] = 0.0;
	t0.sculpture.A[1][0] = 0.8; t0.sculpture.A[1][1] = 0.1;
	t0.sculpture.A[2][0] = 0.6; t0.sculpture.A[2][1] = 0.2;
	t0.sculpture.A[3][0] = 0.2; t0.sculpture.A[3][1] = 0.15;
	t0.sculpture.A[4][0] = 0.7; t0.sculpture.A[4][1] = 0.3;
	t0.sculpture.A[5][0] = 0.01; t0.sculpture.A[5][1] = 0.4;
	t0.sculpture.A[6][0] = 1.0; t0.sculpture.A[6][1] = 0.4;
	t0.sculpture.A[7][0] = 1.0; t0.sculpture.A[7][1] = 0.475;
	t0.sculpture.A[8][0] = 0.7; t0.sculpture.A[8][1] = 0.55;
	t0.sculpture.A[9][0] = 0.01; t0.sculpture.A[9][1] = 0.7;
	t0.sculpture.A[10][0] = 1.0; t0.sculpture.A[10][1] = 0.7;
	t0.sculpture.A[11][0] = 1.0; t0.sculpture.A[11][1] = 0.8;
	t0.sculpture.A[12][0] = 0.8; t0.sculpture.A[12][1] = 0.8;
	t0.sculpture.A[13][0] = 0.7; t0.sculpture.A[13][1] = 0.85;
	t0.sculpture.A[14][0] = 0.5; t0.sculpture.A[14][1] = 0.85;
	t0.sculpture.A[15][0] = 0.4; t0.sculpture.A[15][1] = 0.9;
	t0.sculpture.A[16][0] = 0.3; t0.sculpture.A[16][1] = 0.9;
	t0.sculpture.A[17][0] = 0.01; t0.sculpture.A[17][1] = 1.05;

	return t0;
}

void auxUpdatePleaseRey(int i, struct Peon * dude, double radio, double altura, Vector3D newPosition, double var) {
	
	if (i == 4) {
			dude->points.A[i][dude->j].x = sin(var) * (dude->radius) * cos(dude->j * (2 * M_PI) / dude->numPartition) + newPosition.x;
			dude->points.A[i][dude->j].y = sin(var) * (dude->radius) * sin(dude->j * (2 * M_PI) / dude->numPartition) + newPosition.y;
			dude->points.A[i][dude->j].z = newPosition.z + altura;
	} else {
		if (12 < i && i < 18) {
			dude->points.A[i][dude->j].x = cos(var) * radio * (dude->radius) * cos(dude->j * (2 * M_PI) / dude->numPartition) + newPosition.x;
			dude->points.A[i][dude->j].y = cos(var) * radio * (dude->radius) * sin(dude->j * (2 * M_PI) / dude->numPartition) + newPosition.y;
			dude->points.A[i][dude->j].z = newPosition.z + altura;
		} else {
			dude->points.A[i][dude->j].x = radio * (dude->radius) * cos(dude->j * (2 * M_PI) / dude->numPartition) + newPosition.x;
			dude->points.A[i][dude->j].y = radio * (dude->radius) * sin(dude->j * (2 * M_PI) / dude->numPartition) + newPosition.y;
			dude->points.A[i][dude->j].z = newPosition.z + altura + (0.1*sin(var));
		}
	}
}

void updateRey(struct Peon * Rey, Vector3D newPosition, double var) {

	for (Rey->j = 0; Rey->j < Rey->numPartition + 1; Rey->j++) {
		for (Rey->i = 0; Rey->i < Rey->layers; Rey->i++) 
			auxUpdatePleaseRey(Rey->i, Rey, Rey->sculpture.A[Rey->i][0], Rey->sculpture.A[Rey->i][1], newPosition, var);
		}

	Rey->position = newPosition;

	for (Rey->j = 0; Rey->j < Rey->numPartition; Rey->j++) {
		updateFacet(&Rey->mesh.A[0][Rey->j],Rey->points.A[0][Rey->j], Rey->points.A[0][Rey->j+1], Rey->points.A[1][Rey->j]);
		updateFacet(&Rey->mesh.A[1][Rey->j],Rey->points.A[0][Rey->j+1], Rey->points.A[1][Rey->j+1], Rey->points.A[1][Rey->j]);
		updateFacet(&Rey->mesh.A[2][Rey->j],Rey->points.A[1][Rey->j], Rey->points.A[1][Rey->j+1], Rey->points.A[2][Rey->j]);
		updateFacet(&Rey->mesh.A[3][Rey->j],Rey->points.A[1][Rey->j+1], Rey->points.A[2][Rey->j+1], Rey->points.A[2][Rey->j]);
		updateFacet(&Rey->mesh.A[4][Rey->j],Rey->points.A[2][Rey->j], Rey->points.A[2][Rey->j+1], Rey->points.A[3][Rey->j]);
		updateFacet(&Rey->mesh.A[5][Rey->j],Rey->points.A[2][Rey->j+1], Rey->points.A[3][Rey->j+1], Rey->points.A[3][Rey->j]);
		updateFacet(&Rey->mesh.A[6][Rey->j],Rey->points.A[3][Rey->j], Rey->points.A[3][Rey->j+1], Rey->points.A[4][Rey->j]);
		updateFacet(&Rey->mesh.A[7][Rey->j],Rey->points.A[3][Rey->j+1], Rey->points.A[4][Rey->j+1], Rey->points.A[4][Rey->j]);
		updateFacet(&Rey->mesh.A[8][Rey->j],Rey->points.A[4][Rey->j], Rey->points.A[4][Rey->j+1], Rey->points.A[5][Rey->j]);
		updateFacet(&Rey->mesh.A[9][Rey->j],Rey->points.A[4][Rey->j+1], Rey->points.A[5][Rey->j+1], Rey->points.A[5][Rey->j]);

		//updateFacet(&Rey->mesh.A[10][Rey->j],Rey->points.A[6][Rey->j], Rey->points.A[6][Rey->j+1], Rey->points.A[7][Rey->j]);
		//updateFacet(&Rey->mesh.A[11][Rey->j],Rey->points.A[6][Rey->j+1], Rey->points.A[7][Rey->j+1], Rey->points.A[7][Rey->j]);

		updateFacet(&Rey->mesh.A[12][Rey->j],Rey->points.A[5][Rey->j], Rey->points.A[5][Rey->j+1], Rey->points.A[8][Rey->j]);
		updateFacet(&Rey->mesh.A[13][Rey->j],Rey->points.A[5][Rey->j+1], Rey->points.A[8][Rey->j+1], Rey->points.A[8][Rey->j]);

		updateFacet(&Rey->mesh.A[14][Rey->j],Rey->points.A[8][Rey->j], Rey->points.A[8][Rey->j+1], Rey->points.A[9][Rey->j]);
		updateFacet(&Rey->mesh.A[15][Rey->j],Rey->points.A[8][Rey->j+1], Rey->points.A[9][Rey->j+1], Rey->points.A[9][Rey->j]);

		updateFacet(&Rey->mesh.A[16][Rey->j],Rey->points.A[10][Rey->j], Rey->points.A[10][Rey->j+1], Rey->points.A[11][Rey->j]);
		updateFacet(&Rey->mesh.A[17][Rey->j],Rey->points.A[10][Rey->j+1], Rey->points.A[11][Rey->j+1], Rey->points.A[11][Rey->j]);

		updateFacet(&Rey->mesh.A[18][Rey->j],Rey->points.A[12][Rey->j], Rey->points.A[12][Rey->j+1], Rey->points.A[13][Rey->j]);
		updateFacet(&Rey->mesh.A[19][Rey->j],Rey->points.A[12][Rey->j+1], Rey->points.A[13][Rey->j+1], Rey->points.A[13][Rey->j]);

		updateFacet(&Rey->mesh.A[20][Rey->j],Rey->points.A[14][Rey->j], Rey->points.A[14][Rey->j+1], Rey->points.A[15][Rey->j]);
		updateFacet(&Rey->mesh.A[21][Rey->j],Rey->points.A[14][Rey->j+1], Rey->points.A[15][Rey->j+1], Rey->points.A[15][Rey->j]);

		updateFacet(&Rey->mesh.A[22][Rey->j],Rey->points.A[16][Rey->j], Rey->points.A[16][Rey->j+1], Rey->points.A[17][Rey->j]);
		updateFacet(&Rey->mesh.A[23][Rey->j],Rey->points.A[16][Rey->j+1], Rey->points.A[17][Rey->j+1], Rey->points.A[17][Rey->j]);
	}
}

void renderRey(struct Peon Rey, Vector3D position, struct rotationMats U, double var) {
	
	updateRey(&Rey, position, var);
	for (Rey.j = 0; Rey.j < Rey.numPartition; Rey.j++) {
		if (Rey.white == true) {
			for (Rey.i = 0; Rey.i < Rey.mesh.m; Rey.i++)
				renderFacet(Rey.mesh.A[Rey.i][Rey.j], U, 0);
		} else {
			for (Rey.i = 0; Rey.i < Rey.mesh.m; Rey.i++)
				renderFacet(Rey.mesh.A[Rey.i][Rey.j], U, 1);
		}
	}
}

////////////////////
//			      //
//     KNIGHT     //
//                //
////////////////////

struct Peon initCaballero(int n, Vector3D c, double r, bool w) {
	struct Peon t0 = {
						position : c,
						radius : r,
						numPartition : n,
						white : w,
						i : 0,
						j : 0,
						ocilation : 0,
						layers : 10
					};

	t0.points = creaEspacioMatrixV(t0.layers, n + 1);
	t0.mesh = creaMatrixMesh(16, n);
	t0.sculpture = creaEspacioMatriz(t0.layers, 2);

	int i;
	int j;
	for (i = 0; i < t0.points.m; i++)
		for (j = 0; j < n + 1; j++) {
			t0.points.A[i][j] = initVector3D(0, 0, 0);
		}

	for (i = 0; i < t0.mesh.m; i++)
		for (j = 0; j < n; j++) {
			t0.mesh.A[i][j] = facet(t0.points.A[0][j], t0.points.A[0][j+1], t0.points.A[1][j]);
		}

	t0.sculpture.A[0][0] = 1.0; t0.sculpture.A[0][1] = 0.0;
	t0.sculpture.A[1][0] = 0.5; t0.sculpture.A[1][1] = 0.1;
	t0.sculpture.A[2][0] = 0.3; t0.sculpture.A[2][1] = 0.15;
	t0.sculpture.A[3][0] = 0.01; t0.sculpture.A[3][1] = 0.2;
	
	t0.sculpture.A[4][0] = 1.0; t0.sculpture.A[4][1] = 0.2;
	t0.sculpture.A[5][0] = 1.0; t0.sculpture.A[5][1] = 0.3;
	t0.sculpture.A[6][0] = 0.75; t0.sculpture.A[6][1] = 0.3;

	t0.sculpture.A[7][0] = 0.25; t0.sculpture.A[7][1] = 0.3;
	t0.sculpture.A[8][0] = 0.25; t0.sculpture.A[8][1] = 0.4;
	t0.sculpture.A[9][0] = 0.01; t0.sculpture.A[9][1] = 0.6;


	return t0;
}

void auxUpdatePleaseCaballero(int i, struct Peon * dude, double radio, double altura, Vector3D newPosition, double var) {
	
			dude->points.A[i][dude->j].x = radio * (dude->radius) * cos(dude->j * (2 * M_PI) / dude->numPartition) + newPosition.x + (0.1*cos(var));
			dude->points.A[i][dude->j].y = radio * (dude->radius) * sin(dude->j * (2 * M_PI) / dude->numPartition) + newPosition.y + (0.1*sin(var));
			dude->points.A[i][dude->j].z = newPosition.z + altura  + (0.1*sin(var) * cos(var));
}

void updateCaballero(struct Peon * Caballero, Vector3D newPosition, double var) {

	for (Caballero->j = 0; Caballero->j < Caballero->numPartition + 1; Caballero->j++) {
		for (Caballero->i = 0; Caballero->i < Caballero->layers; Caballero->i++) 
			auxUpdatePleaseCaballero(Caballero->i, Caballero, Caballero->sculpture.A[Caballero->i][0], Caballero->sculpture.A[Caballero->i][1], newPosition, var);
		}

	Caballero->position = newPosition;

	for (Caballero->j = 0; Caballero->j < Caballero->numPartition; Caballero->j++) {
		updateFacet(&Caballero->mesh.A[0][Caballero->j],Caballero->points.A[0][Caballero->j], Caballero->points.A[0][Caballero->j+1], Caballero->points.A[1][Caballero->j]);
		updateFacet(&Caballero->mesh.A[1][Caballero->j],Caballero->points.A[0][Caballero->j+1], Caballero->points.A[1][Caballero->j+1], Caballero->points.A[1][Caballero->j]);
		updateFacet(&Caballero->mesh.A[2][Caballero->j],Caballero->points.A[1][Caballero->j], Caballero->points.A[1][Caballero->j+1], Caballero->points.A[2][Caballero->j]);
		updateFacet(&Caballero->mesh.A[3][Caballero->j],Caballero->points.A[1][Caballero->j+1], Caballero->points.A[2][Caballero->j+1], Caballero->points.A[2][Caballero->j]);
		updateFacet(&Caballero->mesh.A[4][Caballero->j],Caballero->points.A[2][Caballero->j], Caballero->points.A[2][Caballero->j+1], Caballero->points.A[3][Caballero->j]);
		updateFacet(&Caballero->mesh.A[5][Caballero->j],Caballero->points.A[2][Caballero->j+1], Caballero->points.A[3][Caballero->j+1], Caballero->points.A[3][Caballero->j]);
		updateFacet(&Caballero->mesh.A[6][Caballero->j],Caballero->points.A[4][Caballero->j], Caballero->points.A[4][Caballero->j+1], Caballero->points.A[5][Caballero->j]);
		updateFacet(&Caballero->mesh.A[7][Caballero->j],Caballero->points.A[4][Caballero->j+1], Caballero->points.A[5][Caballero->j+1], Caballero->points.A[5][Caballero->j]);
		updateFacet(&Caballero->mesh.A[8][Caballero->j],Caballero->points.A[5][Caballero->j], Caballero->points.A[5][Caballero->j+1], Caballero->points.A[6][Caballero->j]);
		updateFacet(&Caballero->mesh.A[9][Caballero->j],Caballero->points.A[5][Caballero->j+1], Caballero->points.A[6][Caballero->j+1], Caballero->points.A[6][Caballero->j]);
		updateFacet(&Caballero->mesh.A[10][Caballero->j],Caballero->points.A[7][Caballero->j], Caballero->points.A[7][Caballero->j+1], Caballero->points.A[8][Caballero->j]);
		updateFacet(&Caballero->mesh.A[11][Caballero->j],Caballero->points.A[7][Caballero->j+1], Caballero->points.A[8][Caballero->j+1], Caballero->points.A[8][Caballero->j]);
		updateFacet(&Caballero->mesh.A[12][Caballero->j],Caballero->points.A[8][Caballero->j], Caballero->points.A[8][Caballero->j+1], Caballero->points.A[9][Caballero->j]);
		updateFacet(&Caballero->mesh.A[13][Caballero->j],Caballero->points.A[8][Caballero->j+1], Caballero->points.A[9][Caballero->j+1], Caballero->points.A[9][Caballero->j]);
		updateFacet(&Caballero->mesh.A[14][Caballero->j],Caballero->points.A[3][Caballero->j], Caballero->points.A[3][Caballero->j+1], Caballero->points.A[7][Caballero->j]);
		updateFacet(&Caballero->mesh.A[15][Caballero->j],Caballero->points.A[3][Caballero->j+1], Caballero->points.A[7][Caballero->j+1], Caballero->points.A[7][Caballero->j]);
	
	}
}

void renderCaballero(struct Peon Caballero, Vector3D position, struct rotationMats U, double var) {
	
	updateCaballero(&Caballero, position, var);
	for (Caballero.j = 0; Caballero.j < Caballero.numPartition; Caballero.j++) {
		if (Caballero.white == true) {
			for (Caballero.i = 0; Caballero.i < Caballero.mesh.m; Caballero.i++)
				renderFacet(Caballero.mesh.A[Caballero.i][Caballero.j], U, 0);
		} else {
			for (Caballero.i = 0; Caballero.i < Caballero.mesh.m; Caballero.i++)
				renderFacet(Caballero.mesh.A[Caballero.i][Caballero.j], U, 1);
		}
	}
}