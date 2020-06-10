#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdbool.h>
#include "Vector3D.h"
#include "Matrix.h"

#ifndef _PIEZA_
#define _PIEZA_

#ifdef __cplusplus
extern "C" {
#endif

	struct Pieza {
		bool muerto;
		bool blanco;
		int posX;
		int posY;

		bool Pawn_01;
		bool Pawn_11;
		bool Pawn_21;
		bool Pawn_31;
		bool Pawn_41;
		bool Pawn_51;
		bool Pawn_61;
		bool Pawn_71;

		bool Pawn_06;
		bool Pawn_16;
		bool Pawn_26;
		bool Pawn_36;
		bool Pawn_46;
		bool Pawn_56;
		bool Pawn_66;
		bool Pawn_76;

		bool Tower_00;
		bool Tower_77;

		bool Tower_07;
		bool Tower_70;

		bool Arfil_20;
		bool Arfil_57;

		bool Arfil_50;
		bool Arfil_27;

		bool Queen_40;
		bool Queen_47;

		bool King_30;
		bool King_37;

		bool Knight_10;
		bool Knight_17;
		bool Knight_60;
		bool Knight_67;

		double code;
		bool selected;
	};

	struct Pieza initSelector();
	
	struct Pieza initPawn_0(bool color);
	struct Pieza initPawn_1(bool color);
	struct Pieza initPawn_2(bool color);
	struct Pieza initPawn_3(bool color);
	struct Pieza initPawn_4(bool color);
	struct Pieza initPawn_5(bool color);
	struct Pieza initPawn_6(bool color);
	struct Pieza initPawn_7(bool color);

	struct Pieza initTower_0(bool color);
	struct Pieza initTower_1(bool color);

	struct Pieza initArfil_0(bool color);
	struct Pieza initArfil_1(bool white);

	struct Pieza initReina_0(bool white);
	struct Pieza initRey_0(bool white);

	struct Pieza initCaballero_0(bool white);
	struct Pieza initCaballero_1(bool white);

	void printPieza(struct Pieza dude);

	struct Selector {
		int posX;
		int posY;
		bool select;
		int selectedX;
		int selectedY;
		int newSelectedX;
		int newSelectedY;
		Vector3D zentrum;
	};

	struct Selector inittSelector();

#ifdef __cplusplus
}
#endif

#endif