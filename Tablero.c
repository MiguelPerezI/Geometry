#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdbool.h>
#include "Vector3D.h"
#include "Matrix.h"
#include "geometry.h"
#include "Pieza.h"
#include "Tablero.h"

struct Tablero initTablero(int testdrive, double R, Vector3D p, struct rotationMats U) {

	if (testdrive == 1) {
		struct Tablero tabla;
		tabla.codigoActualPieza = tableZeroReal(tabla.codigoActualPieza, 8);
		tabla.boolVar = tableZeroReal(tabla.boolVar, 8);
		int i;
		int j;
		double r = 0.2;
		for (i = 0; i < 8; i++)
			for (int j = 0; j < 8; ++j) {
				if (i == 0 && j == 1) {tabla.codigoActualPieza.A[i][j] = 1101; tabla.boolVar.A[i][j] = 1.0;}
				else {
					if (i == 7 && j == 6) {tabla.codigoActualPieza.A[i][j] = 1176;  tabla.boolVar.A[i][j] = 2.0;}
					else {
						if (i == 1 && j == 1) {tabla.codigoActualPieza.A[i][j] = 1111;  tabla.boolVar.A[i][j] = 1.0;}
						else {
							if (i == 6 && j == 6) {tabla.codigoActualPieza.A[i][j] = 1166;  tabla.boolVar.A[i][j] = 2.0;}
							else{
								if (i == 2 && j == 1) {tabla.codigoActualPieza.A[i][j] = 1121;  tabla.boolVar.A[i][j] = 1.0;}
								else {
									if (i == 5 && j == 6) {tabla.codigoActualPieza.A[i][j] = 1156;  tabla.boolVar.A[i][j] = 2.0;}
									else {
										if (i == 3 && j == 1) {tabla.codigoActualPieza.A[i][j] = 1131;  tabla.boolVar.A[i][j] = 1.0;}
										else {
											if (i == 4 && j == 6) {tabla.codigoActualPieza.A[i][j] = 1146; tabla.boolVar.A[i][j] = 2.0;}
											else {
												if (i == 4 && j == 1) {tabla.codigoActualPieza.A[i][j] = 1141; tabla.boolVar.A[i][j] = 1.0;}
												else {
													if (i == 3 && j == 6) {tabla.codigoActualPieza.A[i][j] = 1136; tabla.boolVar.A[i][j] = 2.0;}
													else {
														if (i == 5 && j == 1) {tabla.codigoActualPieza.A[i][j] = 1151; tabla.boolVar.A[i][j] = 1.0;}
														else {
															if (i == 2 && j == 6) {tabla.codigoActualPieza.A[i][j] = 1126; tabla.boolVar.A[i][j] = 2.0;}
															else {
																if (i == 6 && j == 1) {tabla.codigoActualPieza.A[i][j] = 1161; tabla.boolVar.A[i][j] = 1.0;}
																else {
																	if (i == 1 && j == 6) {tabla.codigoActualPieza.A[i][j] = 1116; tabla.boolVar.A[i][j] = 2.0;}
																	else {
																		if (i == 7 && j == 1) {tabla.codigoActualPieza.A[i][j] = 1171; tabla.boolVar.A[i][j] = 1.0;}
																		else{
																			if (i == 0 && j == 6) {tabla.codigoActualPieza.A[i][j] = 1106; tabla.boolVar.A[i][j] = 2.0;}
																			else {
																				if (i == 0 && j == 0) {tabla.codigoActualPieza.A[i][j] = 1200; tabla.boolVar.A[i][j] = 1.0;}
																				else {
																					if (i == 7 && j == 7) {tabla.codigoActualPieza.A[i][j] = 1277; tabla.boolVar.A[i][j] = 2.0;}
																					else {
																						if (i == 0 && j == 7) {tabla.codigoActualPieza.A[i][j] = 1207; tabla.boolVar.A[i][j] = 2.0;}
																						else {
																							if (i == 7 && j == 0) {tabla.codigoActualPieza.A[i][j] = 1270; tabla.boolVar.A[i][j] = 1.0;}
																							else {
																								if (i == 2 && j == 0) {tabla.codigoActualPieza.A[i][j] = 1320; tabla.boolVar.A[i][j] = 1.0;}
																								else{
																									if (i == 5 && j == 7) {tabla.codigoActualPieza.A[i][j] = 1357; tabla.boolVar.A[i][j] = 2.0;}
																									else {
																										if (i == 5 && j == 0) {tabla.codigoActualPieza.A[i][j] = 1350; tabla.boolVar.A[i][j] = 1.0;}
																										else {
																											if (i == 2 && j == 7) {tabla.codigoActualPieza.A[i][j] = 1327; tabla.boolVar.A[i][j] = 2.0;}
																											else {
																												if (i == 4 && j == 0) {tabla.codigoActualPieza.A[i][j] = 1540; tabla.boolVar.A[i][j] = 1.0;}
																												else {
																													if (i == 4 && j == 7) {tabla.codigoActualPieza.A[i][j] = 1547; tabla.boolVar.A[i][j] = 2.0;}
																													else {
																														if (i == 3 && j == 0) {tabla.codigoActualPieza.A[i][j] = 1630; tabla.boolVar.A[i][j] = 1.0;}
																														else {
																															if (i == 3 && j == 7) {tabla.codigoActualPieza.A[i][j] = 1637; tabla.boolVar.A[i][j] = 2.0;}
																															else {
																																if (i == 1 && j == 0) {tabla.codigoActualPieza.A[i][j] = 1710; tabla.boolVar.A[i][j] = 1.0;}
																																else {
																																	if (i == 6 && j == 7) {tabla.codigoActualPieza.A[i][j] = 1767; tabla.boolVar.A[i][j] = 2.0;}
																																	else {
																																		if (i == 6 && j == 0) {tabla.codigoActualPieza.A[i][j] = 1760; tabla.boolVar.A[i][j] = 1.0;}
																																		else {
																																			if (i == 1 && j == 7) {tabla.codigoActualPieza.A[i][j] = 1717; tabla.boolVar.A[i][j] = 2.0;}
																																			else {
																																				tabla.codigoActualPieza.A[i][j] = 1100;
																																				tabla.boolVar.A[i][j] = 0.0;
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}	
														}
													}	
												}	
											}
										}
									}
								}
							}
						}
					}
				} //1st if
			
			}//end for
		tabla.prestado = initVector3D(0, 0, 0);
		tabla.RadioTabla = R;
		tabla.position = p;
		tabla.U = U;
		return tabla;
	} else {
		struct Tablero tabla;
		return tabla;
	}


		 
}


void drawPieza(struct Tablero * tabla, struct Pieza dude, struct Peon peon, struct rotationMats U, double var) {
	
	for (peon.i = 0; peon.i < 8; peon.i++)
		for (peon.j = 0; peon.j < 8; peon.j++) {
			if (dude.code == tabla->codigoActualPieza.A[peon.i][peon.j]) {
				tabla->prestado.x = 2 * tabla->RadioTabla * (peon.i-4) + tabla->position.x;
				tabla->prestado.y = 2 * tabla->RadioTabla * (peon.j-4) + tabla->position.y;
				tabla->prestado.z = 0.25 + tabla->position.z;
				if (1100 < dude.code && dude.code < 1200) renderPawn(peon, tabla->prestado, tabla->U);
				if (1199 < dude.code && dude.code < 1300) renderTorre(peon, tabla->prestado, tabla->U);
				if (1299 < dude.code && dude.code < 1400) renderArfil(peon, tabla->prestado, tabla->U);
				if (1499 < dude.code && dude.code < 1600) renderReina(peon, tabla->prestado, tabla->U, var);
				if (1599 < dude.code && dude.code < 1700) renderRey(peon, tabla->prestado, tabla->U, var);
				if (1699 < dude.code && dude.code < 1800) renderCaballero(peon, tabla->prestado, tabla->U, var);
			}
		}
}

void moverPieza(struct Tablero * tabla, struct Pieza * dude, int i, int j) {
	tabla->codigoActualPieza.A[dude->posX][dude->posY] = 1100;
	dude->posX = i;
	dude->posY = j;
	tabla->codigoActualPieza.A[i][j] = 1101;
}

void moverSelector(struct Selector * dude, int i, int j) {
	dude->posX = i;
	dude->posY = j;
}

bool intervalo(double a, double b, double x) {
	if (a < x && x < b) return true;
	else false;
}

bool activateSelection(struct Tablero * tabla, struct Selector * dude, bool active) {
	
	if (active == true) {

		if (dude->select == false) {
			if (tabla->codigoActualPieza.A[dude->posX + 4][dude->posY + 4] > 1100) {
				dude->selectedX = dude->posX + 4;
				dude->selectedY = dude->posY + 4;
				printf("Seleccionaste Pieza -- (%d, %d)\n\n", dude->selectedX, dude->selectedY);
				dude->select = true;
			}
	
		} else {
			dude->select = false;
			double auxCode = tabla->codigoActualPieza.A[dude->selectedX][dude->selectedY]; 
			double auxColor = tabla->boolVar.A[dude->selectedX][dude->selectedY]; 
			double auxAttack = tabla->boolVar.A[dude->posX + 4][dude->posY + 4]; 
			tabla->codigoActualPieza.A[dude->selectedX][dude->selectedY] = 1100;
			
			if (auxCode > 1100)
				tabla->boolVar.A[dude->selectedX][dude->selectedY] = 0.0;





			///////////////////////
			//					 //
			//	MOVIMIENTO PEON  //
			//					 //
			///////////////////////


			


			
			if (intervalo(1099, 1200, auxCode) == true) {

				if (sqrt((auxColor - 1)*(auxColor - 1)) < 0.001) {
					if (sqrt((auxAttack - 2)*(auxAttack - 2)) < 0.001 || sqrt((auxAttack - 0)*(auxAttack - 0)) < 0.001) {
						printf("\nSelected White Piece\n");
						if (dude->selectedX == 0 || dude->selectedX == 7){
							if (dude->selectedX == 0)
								if ((dude->posX + 4 == dude->selectedX + 1 || dude->posX + 4 == dude->selectedX) && dude->posY + 4 == dude->selectedY + 1) {
									/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									if (dude->posX + 4 == dude->selectedX + 1) {
										if (sqrt((auxAttackX - 2)*(auxAttackX - 2)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									} else {
										if (sqrt((auxAttackX - 2)*(auxAttackX - 2)) >= 0.001 && sqrt((auxAttackX - 1)*(auxAttackX - 1)) >= 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
										
									}
									//////////////////////////////////////////////////////////////////////
								} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;}
		
							if (dude->selectedX == 7)
								if ((dude->posX + 4 == dude->selectedX - 1 || dude->posX + 4 == dude->selectedX) && dude->posY + 4 == dude->selectedY + 1) {
									/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									if (dude->posX + 4 == dude->selectedX - 1) {
										if (sqrt((auxAttackX - 2)*(auxAttackX - 2)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									} else {
										if (sqrt((auxAttackX - 2)*(auxAttackX - 2)) >= 0.001 && sqrt((auxAttackX - 1)*(auxAttackX - 1)) >= 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
										
									}
									//////////////////////////////////////////////////////////////////////
								} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;}
							
						} else {
							
							if ((dude->posX + 4 == dude->selectedX + 1 || dude->posX + 4 == dude->selectedX || dude->posX + 4 == dude->selectedX - 1) && dude->posY + 4 == dude->selectedY + 1) {
								/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									if (dude->posX + 4 == dude->selectedX + 1 || dude->posX + 4 == dude->selectedX - 1) {
										if (sqrt((auxAttackX - 2)*(auxAttackX - 2)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									} else {
										if (sqrt((auxAttackX - 2)*(auxAttackX - 2)) >= 0.001 && sqrt((auxAttackX - 1)*(auxAttackX - 1)) >= 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
										
									}
									//////////////////////////////////////////////////////////////////////
							} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;}
						}
					}else{tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;}///aux attack
				} else {



					if (sqrt((auxColor - 2)*(auxColor - 2)) < 0.001) {
						if (sqrt((auxAttack - 1)*(auxAttack - 1)) < 0.001 || sqrt((auxAttack - 0)*(auxAttack - 0)) < 0.001) {
						printf("\nSelected Black Piece\n");
						if (dude->selectedX == 0 || dude->selectedX == 7){
							if (dude->selectedX == 0)
								if ((dude->posX + 4 == dude->selectedX - 1 || dude->posX + 4 == dude->selectedX) && dude->posY + 4 == dude->selectedY - 1) {
									/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									if (dude->posX + 4 == dude->selectedX - 1) {
										if (sqrt((auxAttackX - 1)*(auxAttackX - 1)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									} else {
										if (sqrt((auxAttackX - 1)*(auxAttackX - 1)) >= 0.001 && sqrt((auxAttackX - 1)*(auxAttackX - 1)) >= 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
										
									}
									//////////////////////////////////////////////////////////////////////
								} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;}
		
							if (dude->selectedX == 7)
								if ((dude->posX + 4 == dude->selectedX + 1 || dude->posX + 4 == dude->selectedX) && dude->posY + 4 == dude->selectedY - 1) {
									/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									if (dude->posX + 4 == dude->selectedX + 1) {
										if (sqrt((auxAttackX - 1)*(auxAttackX - 1)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									} else {
										if (sqrt((auxAttackX - 1)*(auxAttackX - 1)) >= 0.001 && sqrt((auxAttackX - 1)*(auxAttackX - 1)) >= 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
										
									}
									//////////////////////////////////////////////////////////////////////
								} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;}
							
						} else {
							
							if ((dude->posX + 4 == dude->selectedX + 1 || dude->posX + 4 == dude->selectedX || dude->posX + 4 == dude->selectedX - 1) && dude->posY + 4 == dude->selectedY - 1) {
								/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									if (dude->posX + 4 == dude->selectedX + 1 || dude->posX + 4 == dude->selectedX - 1) {
										if (sqrt((auxAttackX - 1)*(auxAttackX - 1)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									} else {
										if (sqrt((auxAttackX - 1)*(auxAttackX - 1)) >= 0.001 && sqrt((auxAttackX - 1)*(auxAttackX - 1)) >= 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
										
									}
									//////////////////////////////////////////////////////////////////////
							} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;}
						}
					} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;}
					} else {
						tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
						printf("\nNo piece selected\n");
					}
				}
			}//end of Peon



			////////////////////////////
			//					      //
			//	MOVIMIENTO CABALLERO  //
			//					      //
			////////////////////////////



			if (intervalo(1699, 1800, auxCode) == true) { //Is It A Knight?

				if (sqrt((auxColor - 1)*(auxColor - 1)) < 0.001) { //Is It White?
					if (sqrt((auxAttack - 2)*(auxAttack - 2)) < 0.001 || sqrt((auxAttack - 0)*(auxAttack - 0)) < 0.001) { //Move Only If Foe or Empty

							///////////////////////////
							//					     //
							// CHECKING RESTRICTIONS //
							//						 //
							///////////////////////////


							if (	
									((dude->posX + 4 == dude->selectedX + 2) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY - 1))
								||	((dude->posX + 4 == dude->selectedX + 1) && (dude->posY + 4 == dude->selectedY + 2 || dude->posY + 4 == dude->selectedY - 2))
								||	((dude->posX + 4 == dude->selectedX - 1) && (dude->posY + 4 == dude->selectedY + 2 || dude->posY + 4 == dude->selectedY - 2))
								||	((dude->posX + 4 == dude->selectedX - 2) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY - 1))	
								) {
									/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									//if (dude->posX + 4 == dude->selectedX + 1) {
										if (sqrt((auxAttackX - 2)*(auxAttackX - 2)) < 0.001 || sqrt((auxAttackX - 0)*(auxAttackX - 0)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									//////////////////////////////////////////////////////////////////////
							} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}


					} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}
				} else {// Then Its Black
					if (sqrt((auxAttack - 1)*(auxAttack - 1)) < 0.001 || sqrt((auxAttack - 0)*(auxAttack - 0)) < 0.001) { //Move Only If Foe or Empty

							///////////////////////////
							//					     //
							// CHECKING RESTRICTIONS //
							//						 //
							///////////////////////////


							if (	
									((dude->posX + 4 == dude->selectedX + 2) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY - 1))
								||	((dude->posX + 4 == dude->selectedX + 1) && (dude->posY + 4 == dude->selectedY + 2 || dude->posY + 4 == dude->selectedY - 2))
								||	((dude->posX + 4 == dude->selectedX - 1) && (dude->posY + 4 == dude->selectedY + 2 || dude->posY + 4 == dude->selectedY - 2))
								||	((dude->posX + 4 == dude->selectedX - 2) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY - 1))	
								) {
									/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									//if (dude->posX + 4 == dude->selectedX + 1) {
										if (sqrt((auxAttackX - 1)*(auxAttackX - 1)) < 0.001 || sqrt((auxAttackX - 0)*(auxAttackX - 0)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									//////////////////////////////////////////////////////////////////////
							} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}


					} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}

				}
			}//end of Knight


			////////////////////////////
			//					      //
			//	 MOVIMIENTO DEL REY   //
			//					      //
			////////////////////////////



			if (intervalo(1599, 1700, auxCode) == true) { //Is It A King?

				if (sqrt((auxColor - 1)*(auxColor - 1)) < 0.001) { //Is It White?
					if (sqrt((auxAttack - 2)*(auxAttack - 2)) < 0.001 || sqrt((auxAttack - 0)*(auxAttack - 0)) < 0.001) { //Move Only If Foe or Empty

							///////////////////////////
							//					     //
							// CHECKING RESTRICTIONS //
							//						 //
							///////////////////////////


							if (	
									((dude->posX + 4 == dude->selectedX - 1) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY || dude->posY + 4 == dude->selectedY - 1))
								||	((dude->posX + 4 == dude->selectedX) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY || dude->posY + 4 == dude->selectedY - 1))
								||	((dude->posX + 4 == dude->selectedX + 1) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY || dude->posY + 4 == dude->selectedY - 1))	
								) {
									/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									//if (dude->posX + 4 == dude->selectedX + 1) {
										if (sqrt((auxAttackX - 2)*(auxAttackX - 2)) < 0.001 || sqrt((auxAttackX - 0)*(auxAttackX - 0)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									//////////////////////////////////////////////////////////////////////
							} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}


					} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}
				} else {// Then Its Black
					if (sqrt((auxAttack - 1)*(auxAttack - 1)) < 0.001 || sqrt((auxAttack - 0)*(auxAttack - 0)) < 0.001) { //Move Only If Foe or Empty

							///////////////////////////
							//					     //
							// CHECKING RESTRICTIONS //
							//						 //
							///////////////////////////


							if (	
									((dude->posX + 4 == dude->selectedX - 1) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY || dude->posY + 4 == dude->selectedY - 1))
								||	((dude->posX + 4 == dude->selectedX) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY || dude->posY + 4 == dude->selectedY - 1))
								||	((dude->posX + 4 == dude->selectedX + 1) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY || dude->posY + 4 == dude->selectedY - 1))	
								) {
									/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									//if (dude->posX + 4 == dude->selectedX + 1) {
										if (sqrt((auxAttackX - 1)*(auxAttackX - 1)) < 0.001 || sqrt((auxAttackX - 0)*(auxAttackX - 0)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									//////////////////////////////////////////////////////////////////////
							} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}


					} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}

				}
			}//end of King




			////////////////////////////
			//					      //
			//	   MOVIMIENTO ARFIL   //
			//					      //
			////////////////////////////



			if (intervalo(1299, 1400, auxCode) == true) { //Is It A ROOK?

				if (sqrt((auxColor - 1)*(auxColor - 1)) < 0.001) { //Is It White?
					if (sqrt((auxAttack - 2)*(auxAttack - 2)) < 0.001 || sqrt((auxAttack - 0)*(auxAttack - 0)) < 0.001) { //Move Only If Foe or Empty

							///////////////////////////
							//					     //
							// CHECKING RESTRICTIONS //
							//						 //
							///////////////////////////


							if (	
									((dude->posX + 4 == dude->selectedX + 1) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY - 1))
								||	((dude->posX + 4 == dude->selectedX + 2) && (dude->posY + 4 == dude->selectedY + 2 || dude->posY + 4 == dude->selectedY - 2))
								||	((dude->posX + 4 == dude->selectedX + 3) && (dude->posY + 4 == dude->selectedY + 3 || dude->posY + 4 == dude->selectedY - 3))
								||	((dude->posX + 4 == dude->selectedX + 4) && (dude->posY + 4 == dude->selectedY + 4 || dude->posY + 4 == dude->selectedY - 4))
								||	((dude->posX + 4 == dude->selectedX + 5) && (dude->posY + 4 == dude->selectedY + 5 || dude->posY + 4 == dude->selectedY - 5))
								||	((dude->posX + 4 == dude->selectedX + 6) && (dude->posY + 4 == dude->selectedY + 6 || dude->posY + 4 == dude->selectedY - 6))
								||	((dude->posX + 4 == dude->selectedX + 7) && (dude->posY + 4 == dude->selectedY + 7 || dude->posY + 4 == dude->selectedY - 7))

								||	((dude->posX + 4 == dude->selectedX - 1) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY - 1))
								||	((dude->posX + 4 == dude->selectedX - 2) && (dude->posY + 4 == dude->selectedY + 2 || dude->posY + 4 == dude->selectedY - 2))
								||	((dude->posX + 4 == dude->selectedX - 3) && (dude->posY + 4 == dude->selectedY + 3 || dude->posY + 4 == dude->selectedY - 3))
								||	((dude->posX + 4 == dude->selectedX - 4) && (dude->posY + 4 == dude->selectedY + 4 || dude->posY + 4 == dude->selectedY - 4))
								||	((dude->posX + 4 == dude->selectedX - 5) && (dude->posY + 4 == dude->selectedY + 5 || dude->posY + 4 == dude->selectedY - 5))
								||	((dude->posX + 4 == dude->selectedX - 6) && (dude->posY + 4 == dude->selectedY + 6 || dude->posY + 4 == dude->selectedY - 6))
								||	((dude->posX + 4 == dude->selectedX - 7) && (dude->posY + 4 == dude->selectedY + 7 || dude->posY + 4 == dude->selectedY - 7))
								) {
									/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									int truthAux = false;
									int i;
									//if (dude->posX + 4 == dude->selectedX + 1) {
										if (sqrt((auxAttackX - 2)*(auxAttackX - 2)) < 0.001 || sqrt((auxAttackX - 0)*(auxAttackX - 0)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									//////////////////////////////////////////////////////////////////////
							} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}


					} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}
				} else {// Then Its Black
					if (sqrt((auxAttack - 1)*(auxAttack - 1)) < 0.001 || sqrt((auxAttack - 0)*(auxAttack - 0)) < 0.001) { //Move Only If Foe or Empty

							///////////////////////////
							//					     //
							// CHECKING RESTRICTIONS //
							//						 //
							///////////////////////////


							if (	
									((dude->posX + 4 == dude->selectedX + 1) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY - 1))
								||	((dude->posX + 4 == dude->selectedX + 2) && (dude->posY + 4 == dude->selectedY + 2 || dude->posY + 4 == dude->selectedY - 2))
								||	((dude->posX + 4 == dude->selectedX + 3) && (dude->posY + 4 == dude->selectedY + 3 || dude->posY + 4 == dude->selectedY - 3))
								||	((dude->posX + 4 == dude->selectedX + 4) && (dude->posY + 4 == dude->selectedY + 4 || dude->posY + 4 == dude->selectedY - 4))
								||	((dude->posX + 4 == dude->selectedX + 5) && (dude->posY + 4 == dude->selectedY + 5 || dude->posY + 4 == dude->selectedY - 5))
								||	((dude->posX + 4 == dude->selectedX + 6) && (dude->posY + 4 == dude->selectedY + 6 || dude->posY + 4 == dude->selectedY - 6))
								||	((dude->posX + 4 == dude->selectedX + 7) && (dude->posY + 4 == dude->selectedY + 7 || dude->posY + 4 == dude->selectedY - 7))

								||	((dude->posX + 4 == dude->selectedX - 1) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY - 1))
								||	((dude->posX + 4 == dude->selectedX - 2) && (dude->posY + 4 == dude->selectedY + 2 || dude->posY + 4 == dude->selectedY - 2))
								||	((dude->posX + 4 == dude->selectedX - 3) && (dude->posY + 4 == dude->selectedY + 3 || dude->posY + 4 == dude->selectedY - 3))
								||	((dude->posX + 4 == dude->selectedX - 4) && (dude->posY + 4 == dude->selectedY + 4 || dude->posY + 4 == dude->selectedY - 4))
								||	((dude->posX + 4 == dude->selectedX - 5) && (dude->posY + 4 == dude->selectedY + 5 || dude->posY + 4 == dude->selectedY - 5))
								||	((dude->posX + 4 == dude->selectedX - 6) && (dude->posY + 4 == dude->selectedY + 6 || dude->posY + 4 == dude->selectedY - 6))
								||	((dude->posX + 4 == dude->selectedX - 7) && (dude->posY + 4 == dude->selectedY + 7 || dude->posY + 4 == dude->selectedY - 7))
								) {
									/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									//if (dude->posX + 4 == dude->selectedX + 1) {
										if (sqrt((auxAttackX - 1)*(auxAttackX - 1)) < 0.001 || sqrt((auxAttackX - 0)*(auxAttackX - 0)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									//////////////////////////////////////////////////////////////////////
							} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}


					} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}

				}
			}//end of Rook

			////////////////////////////
			//					      //
			//	   MOVIMIENTO TORRE   //
			//					      //
			////////////////////////////



			if (intervalo(1199, 1300, auxCode) == true) { //Is It A TOWER?

				if (sqrt((auxColor - 1)*(auxColor - 1)) < 0.001) { //Is It White?
					if (sqrt((auxAttack - 2)*(auxAttack - 2)) < 0.001 || sqrt((auxAttack - 0)*(auxAttack - 0)) < 0.001) { //Move Only If Foe or Empty

							///////////////////////////
							//					     //
							// CHECKING RESTRICTIONS //
							//						 //
							///////////////////////////


							if (	
									((dude->posX + 4 == dude->selectedX) && (
																				dude->posY + 4 == dude->selectedY - 7 ||
																				dude->posY + 4 == dude->selectedY - 6 ||
																				dude->posY + 4 == dude->selectedY - 5 ||
																				dude->posY + 4 == dude->selectedY - 4 ||
																				dude->posY + 4 == dude->selectedY - 3 ||
																				dude->posY + 4 == dude->selectedY - 2 ||
																				dude->posY + 4 == dude->selectedY - 1 ||
																				dude->posY + 4 == dude->selectedY - 0 ||
																				dude->posY + 4 == dude->selectedY + 1 ||
																				dude->posY + 4 == dude->selectedY + 2 ||
																				dude->posY + 4 == dude->selectedY + 3 ||
																				dude->posY + 4 == dude->selectedY + 4 ||
																				dude->posY + 4 == dude->selectedY + 5 ||
																				dude->posY + 4 == dude->selectedY + 6 ||
																				dude->posY + 4 == dude->selectedY + 7
																			))
								||
									(										(
																				dude->posX + 4 == dude->selectedX - 7 ||
																				dude->posX + 4 == dude->selectedX - 6 ||
																				dude->posX + 4 == dude->selectedX - 5 ||
																				dude->posX + 4 == dude->selectedX - 4 ||
																				dude->posX + 4 == dude->selectedX - 3 ||
																				dude->posX + 4 == dude->selectedX - 2 ||
																				dude->posX + 4 == dude->selectedX - 1 ||
																				dude->posX + 4 == dude->selectedX - 0 ||
																				dude->posX + 4 == dude->selectedX + 1 ||
																				dude->posX + 4 == dude->selectedX + 2 ||
																				dude->posX + 4 == dude->selectedX + 3 ||
																				dude->posX + 4 == dude->selectedX + 4 ||
																				dude->posX + 4 == dude->selectedX + 5 ||
																				dude->posX + 4 == dude->selectedX + 6 ||
																				dude->posX + 4 == dude->selectedX + 7
																			)
								&& (dude->posY + 4 == dude->selectedY))
								
								) {
									/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									int truthAux = false;
									int i;
									//if (dude->posX + 4 == dude->selectedX + 1) {
										if (sqrt((auxAttackX - 2)*(auxAttackX - 2)) < 0.001 || sqrt((auxAttackX - 0)*(auxAttackX - 0)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									//////////////////////////////////////////////////////////////////////
							} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}


					} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}
				} else {// Then Its Black
					if (sqrt((auxAttack - 1)*(auxAttack - 1)) < 0.001 || sqrt((auxAttack - 0)*(auxAttack - 0)) < 0.001) { //Move Only If Foe or Empty

							///////////////////////////
							//					     //
							// CHECKING RESTRICTIONS //
							//						 //
							///////////////////////////


							if (	
									((dude->posX + 4 == dude->selectedX) && (
																				dude->posY + 4 == dude->selectedY - 7 ||
																				dude->posY + 4 == dude->selectedY - 6 ||
																				dude->posY + 4 == dude->selectedY - 5 ||
																				dude->posY + 4 == dude->selectedY - 4 ||
																				dude->posY + 4 == dude->selectedY - 3 ||
																				dude->posY + 4 == dude->selectedY - 2 ||
																				dude->posY + 4 == dude->selectedY - 1 ||
																				dude->posY + 4 == dude->selectedY - 0 ||
																				dude->posY + 4 == dude->selectedY + 1 ||
																				dude->posY + 4 == dude->selectedY + 2 ||
																				dude->posY + 4 == dude->selectedY + 3 ||
																				dude->posY + 4 == dude->selectedY + 4 ||
																				dude->posY + 4 == dude->selectedY + 5 ||
																				dude->posY + 4 == dude->selectedY + 6 ||
																				dude->posY + 4 == dude->selectedY + 7
																			))
								||
									(										(
																				dude->posX + 4 == dude->selectedX - 7 ||
																				dude->posX + 4 == dude->selectedX - 6 ||
																				dude->posX + 4 == dude->selectedX - 5 ||
																				dude->posX + 4 == dude->selectedX - 4 ||
																				dude->posX + 4 == dude->selectedX - 3 ||
																				dude->posX + 4 == dude->selectedX - 2 ||
																				dude->posX + 4 == dude->selectedX - 1 ||
																				dude->posX + 4 == dude->selectedX - 0 ||
																				dude->posX + 4 == dude->selectedX + 1 ||
																				dude->posX + 4 == dude->selectedX + 2 ||
																				dude->posX + 4 == dude->selectedX + 3 ||
																				dude->posX + 4 == dude->selectedX + 4 ||
																				dude->posX + 4 == dude->selectedX + 5 ||
																				dude->posX + 4 == dude->selectedX + 6 ||
																				dude->posX + 4 == dude->selectedX + 7
																			)
								&& (dude->posY + 4 == dude->selectedY))
								
								) {
									/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									//if (dude->posX + 4 == dude->selectedX + 1) {
										if (sqrt((auxAttackX - 1)*(auxAttackX - 1)) < 0.001 || sqrt((auxAttackX - 0)*(auxAttackX - 0)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									//////////////////////////////////////////////////////////////////////
							} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}


					} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}

				}
			}//end of Tower

			////////////////////////////
			//					      //
			//	   MOVIMIENTO REINA   //
			//					      //
			////////////////////////////



			if (intervalo(1499, 1600, auxCode) == true) { //Is It A QUEEN?

				if (sqrt((auxColor - 1)*(auxColor - 1)) < 0.001) { //Is It White?
					if (sqrt((auxAttack - 2)*(auxAttack - 2)) < 0.001 || sqrt((auxAttack - 0)*(auxAttack - 0)) < 0.001) { //Move Only If Foe or Empty

							///////////////////////////
							//					     //
							// CHECKING RESTRICTIONS //
							//						 //
							///////////////////////////


							if (	((dude->posX + 4 == dude->selectedX + 1) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY - 1))
								||	((dude->posX + 4 == dude->selectedX + 2) && (dude->posY + 4 == dude->selectedY + 2 || dude->posY + 4 == dude->selectedY - 2))
								||	((dude->posX + 4 == dude->selectedX + 3) && (dude->posY + 4 == dude->selectedY + 3 || dude->posY + 4 == dude->selectedY - 3))
								||	((dude->posX + 4 == dude->selectedX + 4) && (dude->posY + 4 == dude->selectedY + 4 || dude->posY + 4 == dude->selectedY - 4))
								||	((dude->posX + 4 == dude->selectedX + 5) && (dude->posY + 4 == dude->selectedY + 5 || dude->posY + 4 == dude->selectedY - 5))
								||	((dude->posX + 4 == dude->selectedX + 6) && (dude->posY + 4 == dude->selectedY + 6 || dude->posY + 4 == dude->selectedY - 6))
								||	((dude->posX + 4 == dude->selectedX + 7) && (dude->posY + 4 == dude->selectedY + 7 || dude->posY + 4 == dude->selectedY - 7))

								||	((dude->posX + 4 == dude->selectedX - 1) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY - 1))
								||	((dude->posX + 4 == dude->selectedX - 2) && (dude->posY + 4 == dude->selectedY + 2 || dude->posY + 4 == dude->selectedY - 2))
								||	((dude->posX + 4 == dude->selectedX - 3) && (dude->posY + 4 == dude->selectedY + 3 || dude->posY + 4 == dude->selectedY - 3))
								||	((dude->posX + 4 == dude->selectedX - 4) && (dude->posY + 4 == dude->selectedY + 4 || dude->posY + 4 == dude->selectedY - 4))
								||	((dude->posX + 4 == dude->selectedX - 5) && (dude->posY + 4 == dude->selectedY + 5 || dude->posY + 4 == dude->selectedY - 5))
								||	((dude->posX + 4 == dude->selectedX - 6) && (dude->posY + 4 == dude->selectedY + 6 || dude->posY + 4 == dude->selectedY - 6))
								||	((dude->posX + 4 == dude->selectedX - 7) && (dude->posY + 4 == dude->selectedY + 7 || dude->posY + 4 == dude->selectedY - 7))
								
								||	((dude->posX + 4 == dude->selectedX) && (
																				dude->posY + 4 == dude->selectedY - 7 ||
																				dude->posY + 4 == dude->selectedY - 6 ||
																				dude->posY + 4 == dude->selectedY - 5 ||
																				dude->posY + 4 == dude->selectedY - 4 ||
																				dude->posY + 4 == dude->selectedY - 3 ||
																				dude->posY + 4 == dude->selectedY - 2 ||
																				dude->posY + 4 == dude->selectedY - 1 ||
																				dude->posY + 4 == dude->selectedY - 0 ||
																				dude->posY + 4 == dude->selectedY + 1 ||
																				dude->posY + 4 == dude->selectedY + 2 ||
																				dude->posY + 4 == dude->selectedY + 3 ||
																				dude->posY + 4 == dude->selectedY + 4 ||
																				dude->posY + 4 == dude->selectedY + 5 ||
																				dude->posY + 4 == dude->selectedY + 6 ||
																				dude->posY + 4 == dude->selectedY + 7
																			))
								||
									(										(
																				dude->posX + 4 == dude->selectedX - 7 ||
																				dude->posX + 4 == dude->selectedX - 6 ||
																				dude->posX + 4 == dude->selectedX - 5 ||
																				dude->posX + 4 == dude->selectedX - 4 ||
																				dude->posX + 4 == dude->selectedX - 3 ||
																				dude->posX + 4 == dude->selectedX - 2 ||
																				dude->posX + 4 == dude->selectedX - 1 ||
																				dude->posX + 4 == dude->selectedX - 0 ||
																				dude->posX + 4 == dude->selectedX + 1 ||
																				dude->posX + 4 == dude->selectedX + 2 ||
																				dude->posX + 4 == dude->selectedX + 3 ||
																				dude->posX + 4 == dude->selectedX + 4 ||
																				dude->posX + 4 == dude->selectedX + 5 ||
																				dude->posX + 4 == dude->selectedX + 6 ||
																				dude->posX + 4 == dude->selectedX + 7
																			)
								&& (dude->posY + 4 == dude->selectedY))
								
								) {
									/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									int truthAux = false;
									int i;
									//if (dude->posX + 4 == dude->selectedX + 1) {
										if (sqrt((auxAttackX - 2)*(auxAttackX - 2)) < 0.001 || sqrt((auxAttackX - 0)*(auxAttackX - 0)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									//////////////////////////////////////////////////////////////////////
							} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}


					} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}
				} else {// Then Its Black
					if (sqrt((auxAttack - 1)*(auxAttack - 1)) < 0.001 || sqrt((auxAttack - 0)*(auxAttack - 0)) < 0.001) { //Move Only If Foe or Empty

							///////////////////////////
							//					     //
							// CHECKING RESTRICTIONS //
							//						 //
							///////////////////////////


							if (	
									((dude->posX + 4 == dude->selectedX + 1) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY - 1))
								||	((dude->posX + 4 == dude->selectedX + 2) && (dude->posY + 4 == dude->selectedY + 2 || dude->posY + 4 == dude->selectedY - 2))
								||	((dude->posX + 4 == dude->selectedX + 3) && (dude->posY + 4 == dude->selectedY + 3 || dude->posY + 4 == dude->selectedY - 3))
								||	((dude->posX + 4 == dude->selectedX + 4) && (dude->posY + 4 == dude->selectedY + 4 || dude->posY + 4 == dude->selectedY - 4))
								||	((dude->posX + 4 == dude->selectedX + 5) && (dude->posY + 4 == dude->selectedY + 5 || dude->posY + 4 == dude->selectedY - 5))
								||	((dude->posX + 4 == dude->selectedX + 6) && (dude->posY + 4 == dude->selectedY + 6 || dude->posY + 4 == dude->selectedY - 6))
								||	((dude->posX + 4 == dude->selectedX + 7) && (dude->posY + 4 == dude->selectedY + 7 || dude->posY + 4 == dude->selectedY - 7))

								||	((dude->posX + 4 == dude->selectedX - 1) && (dude->posY + 4 == dude->selectedY + 1 || dude->posY + 4 == dude->selectedY - 1))
								||	((dude->posX + 4 == dude->selectedX - 2) && (dude->posY + 4 == dude->selectedY + 2 || dude->posY + 4 == dude->selectedY - 2))
								||	((dude->posX + 4 == dude->selectedX - 3) && (dude->posY + 4 == dude->selectedY + 3 || dude->posY + 4 == dude->selectedY - 3))
								||	((dude->posX + 4 == dude->selectedX - 4) && (dude->posY + 4 == dude->selectedY + 4 || dude->posY + 4 == dude->selectedY - 4))
								||	((dude->posX + 4 == dude->selectedX - 5) && (dude->posY + 4 == dude->selectedY + 5 || dude->posY + 4 == dude->selectedY - 5))
								||	((dude->posX + 4 == dude->selectedX - 6) && (dude->posY + 4 == dude->selectedY + 6 || dude->posY + 4 == dude->selectedY - 6))
								||	((dude->posX + 4 == dude->selectedX - 7) && (dude->posY + 4 == dude->selectedY + 7 || dude->posY + 4 == dude->selectedY - 7))
								
								||	((dude->posX + 4 == dude->selectedX) && (
																				dude->posY + 4 == dude->selectedY - 7 ||
																				dude->posY + 4 == dude->selectedY - 6 ||
																				dude->posY + 4 == dude->selectedY - 5 ||
																				dude->posY + 4 == dude->selectedY - 4 ||
																				dude->posY + 4 == dude->selectedY - 3 ||
																				dude->posY + 4 == dude->selectedY - 2 ||
																				dude->posY + 4 == dude->selectedY - 1 ||
																				dude->posY + 4 == dude->selectedY - 0 ||
																				dude->posY + 4 == dude->selectedY + 1 ||
																				dude->posY + 4 == dude->selectedY + 2 ||
																				dude->posY + 4 == dude->selectedY + 3 ||
																				dude->posY + 4 == dude->selectedY + 4 ||
																				dude->posY + 4 == dude->selectedY + 5 ||
																				dude->posY + 4 == dude->selectedY + 6 ||
																				dude->posY + 4 == dude->selectedY + 7
																			))
								||
									(										(
																				dude->posX + 4 == dude->selectedX - 7 ||
																				dude->posX + 4 == dude->selectedX - 6 ||
																				dude->posX + 4 == dude->selectedX - 5 ||
																				dude->posX + 4 == dude->selectedX - 4 ||
																				dude->posX + 4 == dude->selectedX - 3 ||
																				dude->posX + 4 == dude->selectedX - 2 ||
																				dude->posX + 4 == dude->selectedX - 1 ||
																				dude->posX + 4 == dude->selectedX - 0 ||
																				dude->posX + 4 == dude->selectedX + 1 ||
																				dude->posX + 4 == dude->selectedX + 2 ||
																				dude->posX + 4 == dude->selectedX + 3 ||
																				dude->posX + 4 == dude->selectedX + 4 ||
																				dude->posX + 4 == dude->selectedX + 5 ||
																				dude->posX + 4 == dude->selectedX + 6 ||
																				dude->posX + 4 == dude->selectedX + 7
																			)
								&& (dude->posY + 4 == dude->selectedY))
								
								) {
									/////////////////////////////////////////////////////////////////////
									double auxAttackX = tabla->boolVar.A[dude->posX + 4][dude->posY + 4];
									//if (dude->posX + 4 == dude->selectedX + 1) {
										if (sqrt((auxAttackX - 1)*(auxAttackX - 1)) < 0.001 || sqrt((auxAttackX - 0)*(auxAttackX - 0)) < 0.001) {
											dude->selectedX = dude->posX + 4;
											dude->selectedY = dude->posY + 4;
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										} else {
											tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor;
										}
									//////////////////////////////////////////////////////////////////////
							} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}


					} else {tabla->boolVar.A[dude->selectedX][dude->selectedY] = auxColor; /*Then Do Nothing*/}

				}
			}//end of Queen

			printf("Mover pieza seleccionada a -- (%d, %d) = %lg.\n\n", dude->selectedX, dude->selectedY, tabla->boolVar.A[dude->selectedX][dude->selectedY]);
			tabla->codigoActualPieza.A[dude->selectedX][dude->selectedY] = auxCode;
			
			escMatriz(tabla->boolVar);
		}
	}

	return false;
}

void drawSelector(struct Selector * dude, struct SelectorPiece selectionAux, struct rotationMats U) {
	
	int i;
	int j;
	double r = 0.2;
	for (i =-4; i < 4; i++)
		for (j =-4; j < 4; j++) {
			if (dude->posX == i && dude->posY == j) {
				dude->zentrum.x = 2 * r * i + sqrt(0.2*0.2 + 0.2*0.2);
				dude->zentrum.y =  2 * r * j + sqrt(0.2*0.2 + 0.2*0.2);
				dude->zentrum.z = 1.1;
	        	renderSelectorPiece(selectionAux, dude->zentrum, U);
			}
		}
}