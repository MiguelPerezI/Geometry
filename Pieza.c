#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdbool.h>
#include <stdarg.h>
#include "Vector3D.h"
#include "Matrix.h"
#include "geometry.h"
#include "Pieza.h"

struct Pieza initSelector() {
	struct Pieza dude = {
							posX : 4,
							posY : 4
						};
}

struct Selector inittSelector() {
	struct Selector ring = 	{
								posX : 4,
								posY : 4,
								select : false,
								selectedX : -1,
								selectedY : -1
							};
	return ring;
}

struct Pieza initPawn_0(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 0, 
								posY : 1, 
								Pawn_01 : true, 
								code : 1101,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 7, 
								posY : 6, 
								Pawn_76 : true, 
								code : 1176,
								selected : false
							};
		return dude;
	}
}

struct Pieza initPawn_1(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 1, 
								posY : 1, 
								Pawn_11 : true, 
								code : 1111,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 6, 
								posY : 6, 
								Pawn_66 : true, 
								code : 1166,
								selected : false
							};
		return dude;
	}
}

struct Pieza initPawn_2(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 2, 
								posY : 1, 
								Pawn_21 : true, 
								code : 1121,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 5, 
								posY : 6, 
								Pawn_56 : true, 
								code : 1156,
								selected : false
							};
		return dude;
	}
}

struct Pieza initPawn_3(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 3, 
								posY : 1, 
								Pawn_31 : true, 
								code : 1131,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 4, 
								posY : 6, 
								Pawn_46 : true, 
								code : 1146,
								selected : false
							};
		return dude;
	}
}

struct Pieza initPawn_4(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 4, 
								posY : 1, 
								Pawn_41 : true, 
								code : 1141,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 3, 
								posY : 6, 
								Pawn_36 : true, 
								code : 1136,
								selected : false
							};
		return dude;
	}
}

struct Pieza initPawn_5(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 5, 
								posY : 1, 
								Pawn_51 : true, 
								code : 1151,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 2, 
								posY : 6, 
								Pawn_26 : true, 
								code : 1126,
								selected : false
							};
		return dude;
	}
}

struct Pieza initPawn_6(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 6, 
								posY : 1, 
								Pawn_61 : true, 
								code : 1161,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 1, 
								posY : 6, 
								Pawn_16 : true, 
								code : 1116,
								selected : false
							};
		return dude;
	}
}

struct Pieza initPawn_7(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 7, 
								posY : 1, 
								Pawn_71 : true, 
								code : 1171,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 0, 
								posY : 6, 
								Pawn_06 : true, 
								code : 1106,
								selected : false
							};
		return dude;
	}
}

struct Pieza initTower_0(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 0, 
								posY : 0, 
								Tower_00 : true, 
								code : 1200,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 7, 
								posY : 7, 
								Tower_77 : true, 
								code : 1277,
								selected : false
							};
		return dude;
	}
}

struct Pieza initTower_1(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 7, 
								posY : 0, 
								Tower_07 : true, 
								code : 1270,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 0, 
								posY : 7, 
								Tower_70 : true, 
								code : 1207,
								selected : false
							};
		return dude;
	}
}

struct Pieza initArfil_0(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 2, 
								posY : 0, 
								Arfil_20 : true, 
								code : 1320,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 5, 
								posY : 7, 
								Arfil_57 : true, 
								code : 1357,
								selected : false
							};
		return dude;
	}
}

struct Pieza initArfil_1(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 5, 
								posY : 0, 
								Arfil_50 : true, 
								code : 1350,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 2, 
								posY : 7, 
								Arfil_27 : true, 
								code : 1327,
								selected : false
							};
		return dude;
	}
}

struct Pieza initReina_0(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 4, 
								posY : 0, 
								Queen_40 : true, 
								code : 1540,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 4, 
								posY : 7, 
								Queen_47 : true, 
								code : 1547,
								selected : false
							};
		return dude;
	}
}

struct Pieza initRey_0(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 3, 
								posY : 0, 
								King_30 : true, 
								code : 1630,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 3, 
								posY : 7, 
								King_37 : true, 
								code : 1637,
								selected : false
							};
		return dude;
	}
}

struct Pieza initCaballero_0(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 1, 
								posY : 0, 
								Knight_10 : true, 
								code : 1710,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 6, 
								posY : 7, 
								Knight_67 : true, 
								code : 1767,
								selected : false
							};
		return dude;
	}
}

struct Pieza initCaballero_1(bool white) {

	if (white == true) {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 6, 
								posY : 0, 
								Knight_60 : true, 
								code : 1760,
								selected : false
							};
		return dude;
	}
	else {
		struct Pieza dude = {
								muerto : false, 
								blanco : white, 
								posX : 1, 
								posY : 7, 
								Knight_17 : true, 
								code : 1717,
								selected : false
							};
		return dude;
	}
}

void printPieza(struct Pieza dude) {
	
	printf("Atributos:\n");

	if (dude.muerto == true) printf("¿Vivo o muerto? --- Pieza Muerta\n");
	else printf("¿Vivo o muerto? --- Pieza Viva\n");

	if (dude.blanco == true) printf("¿Blanco o negro? --- Color Blanco\n");
	else printf("¿Blanco o negro? --- Color Negro\n");

	printf("Posicion --- (%d, %d)\n", dude.posX, dude.posY);

	if (dude.code == 1101) printf("Pieza --- Peon Blanco codigo 01 \n");
	if (dude.code == 1176) printf("Pieza --- Peon Blanco codigo 76 \n");	
}