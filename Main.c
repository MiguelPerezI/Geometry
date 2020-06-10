#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include "Vector3D.h"
#include "Matrix.h"
#include "geometry.h"
#include "Pieza.h"
#include "Tablero.h"
#include "Peon.h"

/*Rango de peones 1101 - 1200*/

GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};  /* White diffuse light. */
GLfloat light_position[] = {1.0, 1.0, 0.25, 0.0};  /* Infinite light location. */

GLfloat delta_1 = 1;
GLfloat radi = 0.8;
GLfloat theta = 0.0;
GLfloat phi = 0.0;
GLfloat gamma1 = 0.0;
double r = 0.2;
int discreteSpehereCon = 1;
double bound = 0.2;
Vector3D center = {x:0.0, y:0.0, z:0.0};
Vector3D center1 = {x:0.0, y:0.0, z:0.0};
Vector3D * zentrum = &center1;
Vector3D I = {x:1.0, y:0.0, z:0.0};
Vector3D J = {x:0.0, y:1.0, z:0.0};
Vector3D K = {x:0.0, y:0.0, z:1.0};
Vector3D err = {x:-1.4, -1.4, 0};

struct Tablero tablaa;
struct Selector selector;
struct SelectorPiece selectionAux;
struct rotationMats U;
struct rotationMats V;
struct rotationMats W;
struct CubicLattice3D lattice;

struct CubicLattice3D latticeInv_3;
struct CubicLattice3D latticeInv_2;
struct CubicLattice3D latticeInv0;
struct CubicLattice3D latticeInv;
struct CubicLattice3D latticeInv1;
struct CubicLattice3D latticeInv2;
struct CubicLattice3D latticeInv3;
struct CubicLattice3D3 latticeSphere0;

struct Peon peon_01;      struct Pieza pawn_01;
struct Peon peon_11;      struct Pieza pawn_11;
struct Peon peon_21;      struct Pieza pawn_21;
struct Peon peon_31;      struct Pieza pawn_31;
struct Peon peon_41;      struct Pieza pawn_41;
struct Peon peon_51;      struct Pieza pawn_51;
struct Peon peon_61;      struct Pieza pawn_61;
struct Peon peon_71;      struct Pieza pawn_71;

struct Peon peon_06;      struct Pieza pawn_06;
struct Peon peon_16;      struct Pieza pawn_16;
struct Peon peon_26;      struct Pieza pawn_26;
struct Peon peon_36;      struct Pieza pawn_36;
struct Peon peon_46;      struct Pieza pawn_46;
struct Peon peon_56;      struct Pieza pawn_56;
struct Peon peon_66;      struct Pieza pawn_66;
struct Peon peon_76;      struct Pieza pawn_76;

struct Peon torre_00;     struct Pieza tower_00;
struct Peon torre_07;     struct Pieza tower_07;
struct Peon torre_77;     struct Pieza tower_77;
struct Peon torre_70;     struct Pieza tower_70;

struct Peon Arfil_20;     struct Pieza Rook_20;
struct Peon Arfil_57;     struct Pieza Rook_57;
struct Peon Arfil_50;     struct Pieza Rook_50;
struct Peon Arfil_27;     struct Pieza Rook_27;

struct Peon Reina_40;     struct Pieza Queen_40;
struct Peon Reina_47;     struct Pieza Queen_47;

struct Peon Rey_30;       struct Pieza King_30;
struct Peon Rey_37;       struct Pieza King_37;

struct Peon Caballero_10;     struct Pieza Knight_10;
struct Peon Caballero_67;     struct Pieza Knight_67;
struct Peon Caballero_60;     struct Pieza Knight_60;
struct Peon Caballero_17;     struct Pieza Knight_17;

MatrixMesh mesh;

bool selection = false;
int counted = 0;
int cursorX = 0;
int cursorY = 0;
int cycle = 0;
double testCode = 1101;
double var = 0.0;
double var1 = 0.0;
double var2 = 0.0;
int mod = 0;
int numPartitions = 25;
struct Tablero * auxTabla = &tablaa;
struct CubicLattice3D * auxLattice = &lattice;
double dif = sqrt((0.2*0.2) + (0.2*0.2));
int showBoard = 0;
Vector3D ajustarTablero;

//////////////////
//  DRAW HERE   //
//////////////////

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0, 1.0, 1.0, 1.0);

  if (cycle == 0) {
    selector = inittSelector();
    selectionAux = initSelectorPiece(0.2, add(center, initVector3D(0, 0, 0.3)));
    tablaa = initTablero(1, 0.2, center, U);
    U = initRotation(theta);
    V = initRotation(phi);
    W = initRotation(gamma1);
    ajustarTablero = initVector3D(dif, dif, 0.5);
    lattice = initCubicLattice3D(tablaa.RadioTabla, 2, 0, add(center, ajustarTablero), 4, 4);

    latticeInv_3 = initInvLattice3D(0.1, 2, 0, scale(-3, K), 15, 15, 1.1, center);
    latticeInv_2 = initInvLattice3D(0.1, 2, 0, scale(-2, K), 15, 15, 1.1, center);
    latticeInv0 = initInvLattice3D(0.1, 2, 0, scale(-1, K), 15, 15, 1.1, center);
    latticeInv = initInvLattice3D(0.1, 2, 0, center, 15, 15, 1.1, center);
    latticeInv1 = initInvLattice3D(0.1, 2, 0, K, 15, 15, 1.1, center);
    latticeInv2 = initInvLattice3D(0.1, 2, 0, scale(2, K), 15, 15, 1.1, center);
    latticeInv3 = initInvLattice3D(0.1, 2, 0, scale(3, K), 15, 15, 1.1, center);
    
    latticeSphere0 = initCubicLattice3D3(0.01, 2, 0, center, 25, 25, 25);
    

    pawn_01 = initPawn_0(true);
    peon_01 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_01.blanco);
    pawn_11 = initPawn_1(true);
    peon_11 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_11.blanco);
    pawn_21 = initPawn_2(true);
    peon_21 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_21.blanco);
    pawn_31 = initPawn_3(true);
    peon_31 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_31.blanco);
    pawn_41 = initPawn_4(true);
    peon_41 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_41.blanco);
    pawn_51 = initPawn_5(true);
    peon_51 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_51.blanco);
    pawn_61 = initPawn_6(true);
    peon_61 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_61.blanco);
    pawn_71 = initPawn_7(true);
    peon_71 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_71.blanco);

    tower_00 = initTower_0(true);
    torre_00 = initTorre(numPartitions, initVector3D(0, 0, 0.3), 0.2, tower_00.blanco);
    tower_07 = initTower_1(true);
    torre_07 = initTorre(numPartitions, initVector3D(0, 0, 0.3), 0.2, tower_07.blanco);

    Rook_20 = initArfil_0(true);
    Arfil_20 = initArfil(numPartitions, initVector3D(0, 0, 0.3), 0.2, Rook_20.blanco);
    Rook_50 = initArfil_1(true);
    Arfil_50 = initArfil(numPartitions, initVector3D(0, 0, 0.3), 0.2, Rook_50.blanco);

    Queen_40 = initReina_0(true);
    Reina_40 = initReina(numPartitions, initVector3D(0, 0, 0.3), 0.2, true);

    King_30 = initRey_0(true);
    Rey_30 = initRey(numPartitions, initVector3D(0, 0, 0.3), 0.2, true);

    Knight_10 = initCaballero_0(true);
    Caballero_10 = initCaballero(numPartitions, initVector3D(0, 0, 0.3), 0.2, true);
    
    Knight_67 = initCaballero_0(false);
    Caballero_67 = initCaballero(numPartitions, initVector3D(0, 0, 0.3), 0.2, false);

    Knight_17 = initCaballero_1(false);
    Caballero_17 = initCaballero(numPartitions, initVector3D(0, 0, 0.3), 0.2, false);
    
    Knight_60 = initCaballero_1(true);
    Caballero_60 = initCaballero(numPartitions, initVector3D(0, 0, 0.3), 0.2, true);


    pawn_06 = initPawn_7(false);
    peon_06 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_06.blanco);
    pawn_16 = initPawn_6(false);
    peon_16 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_16.blanco);
    pawn_26 = initPawn_5(false);
    peon_26 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_26.blanco);
    pawn_36 = initPawn_4(false);
    peon_36 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_36.blanco);
    pawn_46 = initPawn_3(false);
    peon_46 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_46.blanco);
    pawn_56 = initPawn_2(false);
    peon_56 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_56.blanco);
    pawn_66 = initPawn_1(false);
    peon_66 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_66.blanco);
    pawn_76 = initPawn_0(false);
    peon_76 = initPeon(numPartitions, initVector3D(0, 0, 0.3), 0.2, pawn_76.blanco);

    tower_77 = initTower_0(false);
    torre_77 = initTorre(numPartitions, initVector3D(0, 0, 0.3), 0.2, tower_77.blanco);
    tower_70 = initTower_1(false);
    torre_70 = initTorre(numPartitions, initVector3D(0, 0, 0.3), 0.2, tower_70.blanco);

    Rook_57 = initArfil_0(false);
    Arfil_57 = initArfil(numPartitions, initVector3D(0, 0, 0.3), 0.2, Rook_57.blanco);
    Rook_27 = initArfil_1(false);
    Arfil_27 = initArfil(numPartitions, initVector3D(0, 0, 0.3), 0.2, Rook_27.blanco);

    Queen_47 = initReina_0(false);
    Reina_47 = initReina(numPartitions, initVector3D(0, 0, 0.3), 0.2, false);

    King_37 = initRey_0(false);
    Rey_37 = initRey(numPartitions, initVector3D(0, 0, 0.3), 0.2, false);

    printf("Datos preparados correctamente.\n");
  }

  updateRotation(&W, gamma1);
  
  renderInvLattice(latticeInv0, W, center1);
  renderInvLattice(latticeInv, W, center1);
  renderInvLattice(latticeInv1, W, center1);
  //renderCaballero(Caballero_67, Caballero_67.position, U, var);
  //auxTabla->RadioTabla = 0.2 * cos(var);


  if (showBoard%2 == 1) {

    zentrum->x = 2*cos(var1);
    zentrum->z = cos(M_PI);
    updateRotation(&V, phi);
    updateRotation(&U, theta);
    auxTabla->U = U;
    renderLattice(lattice, U);
    auxTabla->position.x = dif;
    auxTabla->position.y = dif; 
    auxTabla->position.z = 0.06 * cos(var) + 0.6;
    auxLattice->position = auxTabla->position;
    drawPieza(&tablaa, pawn_01, peon_01, U, var);
    drawPieza(&tablaa, pawn_11, peon_11, U, var);
    drawPieza(&tablaa, pawn_21, peon_21, U, var);
    drawPieza(&tablaa, pawn_31, peon_31, U, var);
    drawPieza(&tablaa, pawn_41, peon_41, U, var);
    drawPieza(&tablaa, pawn_51, peon_51, U, var);
    drawPieza(&tablaa, pawn_61, peon_61, U, var);
    drawPieza(&tablaa, pawn_71, peon_71, U, var);
  
    drawPieza(&tablaa, tower_00, torre_00, U, var);
    drawPieza(&tablaa, tower_07, torre_07, U, var);
  
    drawPieza(&tablaa, Rook_20, Arfil_20, U, var);
    drawPieza(&tablaa, Rook_50, Arfil_50, U, var);
  
    drawPieza(&tablaa, Queen_40, Reina_40, U, var);
    drawPieza(&tablaa, King_30, Rey_30, U, var);
  
    drawPieza(&tablaa, Knight_10, Caballero_10, U, var);
    drawPieza(&tablaa, Knight_67, Caballero_67, U, var);
    drawPieza(&tablaa, Knight_17, Caballero_17, U, var);
    drawPieza(&tablaa, Knight_60, Caballero_60, U, var);
  
    drawPieza(&tablaa, pawn_06, peon_06, U, var);
    drawPieza(&tablaa, pawn_16, peon_16, U, var);
    drawPieza(&tablaa, pawn_26, peon_26, U, var);
    drawPieza(&tablaa, pawn_36, peon_36, U, var);
    drawPieza(&tablaa, pawn_46, peon_46, U, var);
    drawPieza(&tablaa, pawn_56, peon_56, U, var);
    drawPieza(&tablaa, pawn_66, peon_66, U, var);
    drawPieza(&tablaa, pawn_76, peon_76, U, var);
  
    drawPieza(&tablaa, tower_77, torre_77, U, var);
    drawPieza(&tablaa, tower_70, torre_70, U, var);
  
    drawPieza(&tablaa, Rook_57, Arfil_57, U, var);
    drawPieza(&tablaa, Rook_27, Arfil_27, U, var);
  
    drawPieza(&tablaa, Queen_47, Reina_47, U, var);
    drawPieza(&tablaa, King_37, Rey_37, U, var);
  
    if (cursorX > 3) cursorX =-4;
    if (cursorX <-4) cursorX = 3;
  
    if (cursorY > 3) cursorY =-4;
    if (cursorY <-4) cursorY = 3;
  
    moverSelector(&selector, cursorX, cursorY);
    drawSelector(&selector, selectionAux, U);
    selection = activateSelection(&tablaa, &selector, selection);
  
  } else {
    zentrum->x = 2*cos(var1);
    //zentrum->y = 2*sin(var1);
    zentrum->z = 4*cos(var1)*sin(var1);
    renderInvLattice(latticeInv_3, W, center1);
    renderInvLattice(latticeInv_2, W, center1);
    renderInvLattice(latticeInv2, W, center1);
    renderInvLattice(latticeInv3, W, center1);
  
  }
  
  
  //renderSelectorPiece(selectionAux, center, U);
  //renderTablero(tablaa, r, theta);

  glutSwapBuffers();
}

void init(double theta)
{
  /* Setup data. */
  GLfloat ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
  GLfloat diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
  GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

  /* Enable a single OpenGL light. */
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);

  /* Use depth buffering for hidden surface elimination. */
  glEnable(GL_DEPTH_TEST);
  glFrontFace(GL_CCW);
  //glEnable(GL_CULL_FACE);

  /*Enable color tracking*/
  glEnable(GL_COLOR_MATERIAL);

  /* Set material properties to follow glColor values*/
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

  /*All materials have high shine*/
  glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
  glMateriali(GL_FRONT, GL_SHININESS, 128);

  /* Setup the view of the cube. */
  glMatrixMode(GL_PROJECTION);
  gluPerspective( /* field of view in degree */ 40.0,
                              /* aspect ratio */ 1.0,
                                    /* Z near */ 0.5, 
                                    /* Z far */ 10000.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(5.0, 0.0, 6.0,      /* eye is at (0,0,5) */
            0.0, 0.0, 0.0,      /* center is at (0,0,0) */
            0.0, 0.0, 1.0);      /* up is in positive Y direction */

  /* Adjust Board position to be asthetic angle. */
  //glTranslatef(0.0, 0.15, -0.0);
  glRotatef(90, 0.0, 0.0, 1.0);

  glEnable(GL_NORMALIZE);
}

void TimerFunction(int value) {
  radi += 0.01;
  //theta += 0.01;
  gamma1 += 0.01;
  var += 0.1;
  var1 += 0.005;
  cycle += 1;

  if (cycle == 1) {
    discreteSpehereCon += 1;
    discreteSpehereCon %= 12;
  }

  if (theta > 2 * M_PI) theta = 0;
  if (var > 2 * M_PI) var = 0;
  if (var1 > 2 * M_PI) var1 = 0;
  if (cycle > 10) cycle = 1;
  if (radi > 2 * M_PI) radi = 0;

  //printf("cycle = %d --- theta = %lg \n", cycle, theta);
  glutPostRedisplay();
  glutTimerFunc(20, TimerFunction, 1);
}

void keyboard(unsigned char key, int x, int y) {
  GLint params[2];

  switch (key) {
    case 'w': 
      cursorY += 1;
      break;
    
    case 'a':
      cursorX -= 1;
      break;
    
    case 'd':
      cursorX += 1;
      break;
    
    case 's':
      cursorY -= 1;
      break;

    case 'p':
      selection = true;
      mod += 1;
      break;

    case 'o':
      selection = true;
      showBoard += 1;
      break;

    case 'c':
      testCode = 1176;
      break;

    case 'r':
      theta += 0.05;
      break;

    case 'R':
      theta -= 0.05;
      break;

    case 'i': 
      cursorY -= 1;
      break;

    case 'l':
      cursorX -= 1;
      break;

    case 'j':
      cursorX += 1;
      break;

    case 'k':
      cursorY += 1;
      break;
  }

  glutPostRedisplay();
}

void ProcessMenu(int value) {
  switch(value) {
    case 1:
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glEnable(GL_BLEND);
      glEnable(GL_POINT_SMOOTH);
      glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
      glEnable(GL_LINE_SMOOTH);
      glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
      glEnable(GL_POLYGON_SMOOTH);
      glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
      break;

    case 2:
      glDisable(GL_BLEND);
      glDisable(GL_LINE_SMOOTH);
      glDisable(GL_POINT_SMOOTH);
      glDisable(GL_POLYGON_SMOOTH);
      break;
    
    default:
      break;
  }

  glutPostRedisplay();
}

int main(int argc, char **argv)
{
  
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1300, 1300);
  glutCreateWindow("Testing Geometry");
  ProcessMenu(1);
  init(theta);

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutTimerFunc(20, TimerFunction, 1);

  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}