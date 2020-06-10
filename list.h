#ifndef _LISTA_
#define _LISTA_

#ifdef __cplusplus
extern "C" {
#endif

struct lista {
	int a;
	struct lista *sig;
};

struct lista* creaEL(int x);
void impLista(struct lista *pl);
int push(struct lista **pl, int x);
int swap(struct lista **pl, int x);
int flipLista(struct lista **pl);
int lengthLista(struct lista **pl);
int lastLista(struct lista **pl);
int firstLista(struct lista **pl);
int binarySearch(struct lista **pl, int clave);
int getLista(struct lista **pl, int i);
void insertionSort(struct lista **pl);
void heapify(struct lista **pl, int n, int i);
int replaceIntoLista(struct lista **pl, int i, int x);
void heapSort(struct lista **pl);
struct lista* removeSub(struct lista *pl, int x);
int merge(struct lista **pl, int l, int m, int r);
struct lista* cut(struct lista **pl, int m, int n);
int getSmallLista(struct lista *pl, int i);
int replaceIntoSmallLista(struct lista *pl, int i, int x);
void mergeSort(struct lista **pl, int l, int r);
int lengthSub(struct lista *pl);


#ifdef __cplusplus
}
#endif

#endif
