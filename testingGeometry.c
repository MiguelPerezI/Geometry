#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include "Vector3D.h"
#include "Matrix.h"
#include "geometry.h"
#include "Pieza.h"
#include "Tablero.h"
#include "chessMeshes.h"

/*Rango de peones 1101 - 1200*/

GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};  /* White diffuse light. */
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};  /* Infinite light location. */

GLfloat delta_1 = 1;
GLfloat radi = 0.8;
GLfloat theta = 0.0;
double r = 0.2;
Vector3D center = {x:0.0, y:0.0, z:0.0};
Vector3D I = {x:1.0, y:0.0, z:0.0};
Vector3D J = {x:0.0, y:1.0, z:0.0};
Vector3D K = {x:0.0, y:0.0, z:1.0};
struct Tablero tablaa;

struct Pieza pawn_01;
struct Pieza pawn_11;
struct Pieza pawn_21;
struct Pieza pawn_31;
struct Pieza pawn_41;
struct Pieza pawn_51;
struct Pieza pawn_61;
struct Pieza pawn_71;

struct Pieza pawn_06;
struct Pieza pawn_16;
struct Pieza pawn_26;
struct Pieza pawn_36;
struct Pieza pawn_46;
struct Pieza pawn_56;
struct Pieza pawn_66;
struct Pieza pawn_76;

struct Selector selector;
bool selection = false;
int counted = 0;
int cursorX = 4;
int cursorY = 3;
int cycle = 0;
double testCode = 1101;

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0, 1.0, 1.0, 1.0);

  if (cycle == 0) {
    selector = inittSelector();
    pawn_01 = initPawn_0(true);
    pawn_76 = initPawn_0(false);
    pawn_11 = initPawn_1(true);
    pawn_66 = initPawn_1(false);
    pawn_21 = initPawn_2(true);
    pawn_56 = initPawn_2(false);
    pawn_31 = initPawn_3(true);
    pawn_46 = initPawn_3(false);
    pawn_41 = initPawn_4(true);
    pawn_36 = initPawn_4(false);
    pawn_51 = initPawn_5(true);
    pawn_26 = initPawn_5(false);
    pawn_61 = initPawn_6(true);
    pawn_16 = initPawn_6(false);
    pawn_71 = initPawn_7(true);
    pawn_06 = initPawn_7(false);
    tablaa = initTablero(1);
  }

  if (cursorX > 7) cursorX = 0;
  if (cursorX < 0) cursorX = 7;

  if (cursorY > 7) cursorY = 0;
  if (cursorY < 0) cursorY = 7;

  moverSelector(&selector, cursorX, cursorY);
  selection = activateSelection(&tablaa, &selector, selection);
  drawSelector(selector, theta);
  drawPieza(tablaa, pawn_01, theta);
  drawPieza(tablaa, pawn_11, theta);
  drawPieza(tablaa, pawn_21, theta);
  drawPieza(tablaa, pawn_31, theta);
  drawPieza(tablaa, pawn_41, theta);
  drawPieza(tablaa, pawn_51, theta);
  drawPieza(tablaa, pawn_61, theta);
  drawPieza(tablaa, pawn_71, theta);

  drawPieza(tablaa, pawn_06, theta);
  drawPieza(tablaa, pawn_16, theta);
  drawPieza(tablaa, pawn_26, theta);
  drawPieza(tablaa, pawn_36, theta);
  drawPieza(tablaa, pawn_46, theta);
  drawPieza(tablaa, pawn_56, theta);
  drawPieza(tablaa, pawn_66, theta);
  drawPieza(tablaa, pawn_76, theta);
  renderTablero(tablaa, r, theta);

  //invertedPlane(0.075, initVector3D(0, 6, 0), theta, 0);
  //invertedPlane(0.075, initVector3D(0, 6, 0), theta, 1);
  //invertedPlane(0.075, initVector3D(6, 0, 0), theta, 2);
  //invertedPlane(0.075, initVector3D(6, 0, 0), theta, 3);
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
  gluLookAt(5.0, 0.0, 4.0,      /* eye is at (0,0,5) */
            0.0, 0.0, 0.0,      /* center is at (0,0,0) */
            0.0, 0.0, 1.0);      /* up is in positive Y direction */

  /* Adjust Board position to be asthetic angle. */
  glTranslatef(0.0, 0.15, -0.0);
  glRotatef(90, 0.0, 0.0, 1.0);

  glEnable(GL_NORMALIZE);
}

void TimerFunction(int value) {
  radi += 0.01;
  theta += 0.01;
  cycle += 1;
  if (theta > 2 * M_PI) theta = 0;
  if (cycle > 100) cycle = 1;
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
      break;

    case 'c':
      testCode = 1176;
      break;
  }

  glutPostRedisplay();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(900, 900);
  glutCreateWindow("Testing Geometry");
  init(theta);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutTimerFunc(20, TimerFunction, 1);

  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}