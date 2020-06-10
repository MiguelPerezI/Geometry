#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdarg.h>
#include "Vector3D.h"
#include "Matrix.h"
#include "Pieza.h"
#include "Peon.h"
#include "geometry.h"

#ifndef _TABLERO_
#define _TABLERO_

#ifdef __cplusplus
extern "C" {
#endif

	struct Tablero{
		MATRIZ codigoActualPieza;
		MatrixV posVec;
		MATRIZ boolVar;
		Vector3D prestado;
		double RadioTabla;
		Vector3D position;
		struct rotationMats U;
	};

	struct Tablero initTablero(int testdrive, double R, Vector3D p, struct rotationMats U);
	void drawPieza(struct Tablero * tabla, struct Pieza dude, struct Peon peon, struct rotationMats U, double var);
	void moverPieza(struct Tablero * tabla, struct Pieza * dude, int i, int j);
	void moverPiezaAlpha(struct Tablero * tabla, struct Selector * ring, struct Pieza * dude, int i, int j);
	void moverSelector(struct Selector * dude, int i, int j);
	bool activateSelection(struct Tablero * tabla, struct Selector * dude, bool active);
	void drawSelector(struct Selector * dude, struct SelectorPiece selectionAux, struct rotationMats U);
	bool intervalo(double a, double b, double x);
#ifdef __cplusplus
}
#endif

#endif