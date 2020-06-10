#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdbool.h>
#include "Vector3D.h"
#include "Matrix.h"
#include "geometry.h"

#ifndef _MESH_
#define _MESH_

#ifdef __cplusplus
extern "C" {
#endif

///////////////
//			 //
//    PEON   //
//           //
///////////////

	struct Peon{
		Vector3D position;
		MatrixV points;
		double radius;
		int numPartition;
		bool white;
		MatrixMesh mesh;
		int i;
		int j;
		double ocilation;
		int layers;
		MATRIZ sculpture;
	};

	struct Peon initPeon(int n, Vector3D c, double radius, bool w);
	void renderPawn(struct Peon peon, Vector3D position, struct rotationMats U);
	void updatePawn(struct Peon * peon, Vector3D newPosition);


///////////////
//			 //
//   TORRE   //
//           //
///////////////

	struct Peon initTorre(int n, Vector3D c, double r, bool w);
	void updateTorre(struct Peon * torre, Vector3D newPosition);
	void renderTorre(struct Peon torre, Vector3D position, struct rotationMats U);

/////////////////
//			   //
//    ARFIL    //
//             //
/////////////////

	struct Peon initArfil(int n, Vector3D c, double r, bool w);
	void updateArfil(struct Peon * torre, Vector3D newPosition);
	void renderArfil(struct Peon torre, Vector3D position, struct rotationMats U);

/////////////////
//			   //
//    REINA    //
//             //
/////////////////

	struct Peon initReina(int n, Vector3D c, double r, bool w);
	void auxUpdatePleaseReina(int i, struct Peon * dude, double radio, double altura, Vector3D newPosition, double var);
	void updateReina(struct Peon * torre, Vector3D newPosition, double var);
	void renderReina(struct Peon torre, Vector3D position, struct rotationMats U, double var);
	

/////////////////
//			   //
//     REY     //
//             //
/////////////////

	struct Peon initRey(int n, Vector3D c, double r, bool w);
	void auxUpdatePleaseRey(int i, struct Peon * dude, double radio, double altura, Vector3D newPosition, double var);
	void updateRey(struct Peon * torre, Vector3D newPosition, double var);
	void renderRey(struct Peon torre, Vector3D position, struct rotationMats U, double var);


//////////////////s
//			    //
//    KNIGHT    //
//              //
//////////////////

	struct Peon initCaballero(int n, Vector3D c, double r, bool w);
	void auxUpdatePleaseCaballero(int i, struct Peon * dude, double radio, double altura, Vector3D newPosition, double var);
	void updateCaballero(struct Peon * torre, Vector3D newPosition, double var);
	void renderCaballero(struct Peon torre, Vector3D position, struct rotationMats U, double var);


#ifdef __cplusplus
}
#endif

#endif