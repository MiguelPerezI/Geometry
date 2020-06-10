#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void impLista(struct lista *pl) {
	struct lista *laux = pl;
	int count = 0;
	while (laux != NULL) {
		printf ("%d.)    %d\n", count, laux->a);
		laux = laux->sig;
		count += 1;
	}
	printf("\n");
}

int getSmallLista(struct lista *pl, int i) {
	
		if (i != 0 && i < lengthSub(pl)) {
			struct lista *laux = pl;
			int count = 0;
			while (count < i) {
				laux = laux->sig;
				count += 1;
			}
			return laux->a;
		} else {
			if (i == 0)
				return pl->a;
			else {
				return -0205;
			}
		}
}

int lengthSub(struct lista *pl) {
	int count;
	if (pl == NULL)
		count = 0;
	else {
		count = 0;
		while (pl != NULL) {
			pl = pl->sig;
			count += 1;
		}
	}
	return count;
}

struct lista* removeSub(struct lista *pl, int x) {
	if (pl == NULL){
		//printf("\n\nYour list is empty.\n\n");
			return NULL;
	} else {



		struct lista *K = pl;
		if (K->a == x) {
			return K->sig;
		}
		else {
			struct lista *aux = creaEL(K->a);
			int u = lengthSub(K->sig);
			int i;
			for (i = 0; i < u; i++) {
				K = K->sig;
				if (K->a != x) {
					//////////begin pushing
					struct lista *AUX0 = creaEL(K->a);
					AUX0->sig = aux;
					aux = AUX0;
					/////////end pushing
					AUX0 = NULL;
				}
			}

			struct lista *ret = creaEL(aux->a);
			u = lengthSub(aux->sig);
			K = aux;

			for (i = 0; i < u; i++) {
				K = K->sig;
				if (K->a != x) {
					//////////begin pushing
					struct lista *AUX0 = creaEL(K->a);
					AUX0->sig = ret;
					ret = AUX0;
					/////////end pushing
					AUX0 = NULL;
				}
			}

			return ret;
		}



	}//end first else
}//end of removeSubLista

int replaceIntoSmallLista(struct lista *pl, int i, int x) {
	if (pl == NULL){
		printf("\n\nYour list is empty.\n\n");
			return -1;
	} else {

		if (i != 0) {
			struct lista *K = pl;
			struct lista *auxiliar = creaEL(K->a);
			
			int count;
			for (count = 0; count < i; count++) {
				K = K->sig;
				//////////begin pushing
				struct lista *AUX0 = creaEL(K->a);
				if (AUX0 == NULL)
					return -1;
				AUX0->sig = auxiliar;
				auxiliar = AUX0;
				/////////end pushing
				AUX0 = NULL;
			}
			auxiliar = auxiliar->sig;
			K->a = x;
			
			for (count = 0; count < i; count++) {
				struct lista *AUX0 = creaEL(auxiliar->a);
				if (AUX0 == NULL)
					return -1;
				AUX0->sig = K;
				K = AUX0;
				auxiliar = auxiliar->sig;
				AUX0 = NULL;
			}
			pl = K;
		} else {
			pl->a = x;
		}

	}//end first else
}

struct lista* creaEL(int x) {
	struct lista *ret;
	ret = (struct lista*)malloc(sizeof(struct lista));
	if (ret != NULL) {
		ret->a = x;
		ret->sig = NULL;
	}

	return ret;
}

int push(struct lista **pl, int x){
	struct lista *pel;

	if (*pl == NULL){
		pel = creaEL(x);
		if (pel == NULL)
			return -1;
		*pl = pel;
		return 0;
	}
	else {
		
		struct lista *AUX = creaEL(x);
		if (AUX == NULL)
			return -1;
		AUX->sig = *pl;
		
		*pl = AUX;
	}
	
	return 0;
}

int replaceIntoLista(struct lista **pl, int i, int x) {
	if (*pl == NULL){
		printf("\n\nYour list is empty.\n\n");
			return -1;
	} else {

		if (i != 0) {
			struct lista *K = *pl;
			struct lista *auxiliar = creaEL(K->a);
			int count;
			for (count = 0; count < i; count++) {
				K = K->sig;
				//////////begin pushing
				struct lista *AUX0 = creaEL(K->a);
				if (AUX0 == NULL)
					return -1;
				AUX0->sig = auxiliar;
				auxiliar = AUX0;
				/////////end pushing
				AUX0 = NULL;
			}
			auxiliar = auxiliar->sig;
			K->a = x;
			
			for (count = 0; count < i; count++) {
				struct lista *AUX0 = creaEL(auxiliar->a);
				if (AUX0 == NULL)
					return -1;
				AUX0->sig = K;
				K = AUX0;
				auxiliar = auxiliar->sig;
				AUX0 = NULL;
			}
			*pl = K;
		} else {
				//////
		struct lista *K = *pl;
		K = K->sig;
		//////////begin pushing
		struct lista *AUX1 = creaEL(x);
			if (AUX1 == NULL)
				return -1;
			AUX1->sig = K;
			K = AUX1;
			/////////end pushing
			*pl = K;
		}

	}//end first else
}

int flipLista(struct lista **pl) {
	struct lista *AUX = *pl;
	struct lista *aux = creaEL((*pl)->a);
	int i;
	for (i = 0; i < lengthLista(pl)-1; i++) {
		AUX = AUX->sig;
		struct lista *AUX0 = creaEL(AUX->a);
		if (AUX0 == NULL)
			return -1;
		AUX0->sig = aux;
		aux = AUX0;
		AUX0 = NULL;
	}
	*pl = aux;
}

int swap(struct lista **pl, int x){
	
	if (*pl == NULL){
			return -1;
	}
	else {
		if (x != 0) {
			//printf("Swap index %d with %d.\n", x, x+1);
		int count;
		struct lista *AUX = creaEL((*pl)->a);
		struct lista *K = *pl;

		
			for (count = 0; count < x - 1; count++) {
				K = K->sig;
				//////////begin pushing
				struct lista *AUX0 = creaEL(K->a);
				if (AUX0 == NULL)
					return -1;
				AUX0->sig = AUX;
				AUX = AUX0;
				/////////end pushing
				AUX0 = NULL;
			}

		struct lista *K1 = K;
		K1 = K1->sig;
		int swap1 = K1->a;
		K1 = K1->sig;
		int swap2 = K1->a;

		K1->a = swap1;
		//////////begin pushing
		struct lista *AUX1 = creaEL(swap2);
			if (AUX1 == NULL)
				return -1;
			AUX1->sig = K1;
			K1 = AUX1;
			/////////end pushing

		for (count = 0; count < x; count++) {
			//////////begin pushing
			struct lista *aux = creaEL(AUX->a);
			if (aux == NULL)
				return -1;
			aux->sig = K1;
			K1 = aux;
			AUX = AUX->sig;
			/////////end pushing
		}

		*pl = K1;
		 K1 = NULL;
		 AUX = NULL;
		 AUX1 = NULL;
		 K = NULL;
		} else {
			//////
		struct lista *K = *pl;
		
		int swap1 = K->a;
		K = K->sig;
		int swap2 = K->a;

		K->a = swap1;
		//////////begin pushing
		struct lista *AUX1 = creaEL(swap2);
			if (AUX1 == NULL)
				return -1;
			AUX1->sig = K;
			K = AUX1;
			/////////end pushing
			*pl = K;
		}

	}
	
	return 0;
}

int lengthLista(struct lista **pl) {
	if (*pl == NULL) {
		return 0;
	} else {
		struct lista *AUX = *pl;
		int count = 0;
		while (AUX != NULL) {
			AUX = AUX->sig;
			count += 1;
		}
		return count;
	}
}

int binarySearch(struct lista **pl, int clave) {
	int central, bajo, alto;
	int valorCentral;
	int b1, c1, a1;
	bajo = firstLista(pl);
	alto = lastLista(pl);
		printf("\n");
		printf("Se revisan los indices:\n");
	while (bajo <= alto) {
		central = (bajo+alto)/2;
		valorCentral = getLista(pl, central);
		printf("%d --------- %d --------- %d\n", bajo, central, alto);
		
		if (clave == valorCentral)
			return central;
		else
			if (clave < valorCentral)
				alto = central - 1;
			else
				bajo = central + 1;
	}
	
	return -1;
}

int lastLista(struct lista **pl) {
	if (*pl == NULL)
		return -1;
	else {
		struct lista *AUX = *pl;
		int count = 0;
		while (count < lengthLista(pl) - 1) {
			AUX = AUX->sig;
			count += 1;
		}

		return AUX->a;
	}
}

int firstLista(struct lista **pl) {
	struct lista *AUX = *pl;
	if (*pl == NULL)
		return -1;
	else {
		return AUX->a;
		}
}

int getLista(struct lista **pl, int i) {
	if (*pl == NULL)
		return -1;
	else {
		if (i != 0) {
			struct lista *AUX = *pl;
			int count = 0;
			while (count < i) {
				AUX = AUX->sig;
				count += 1;
			}
			return AUX->a;
		} else {
			return (*pl)->a;
		}
	}
}

void insertionSort(struct lista **pl) {
	int i;
	int a0, a1;

	int o1 = getLista(pl, 1);
	//printf("\n o1 = %d \n", o1);
	for (i = 0; i < lengthLista(pl); i++) {
		int j = i;
		if (j > 0) {
			while (getLista(pl, j-1) > getLista(pl, j)) {
				swap(pl, j-1);
				j = j - 1;
			}
		}
	}
}//end of insertionSort

void heapify(struct lista **pl, int n, int i) {
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if (l < n && getLista(pl, l) > getLista(pl, largest))
		largest = l;

	if (r < n && getLista(pl, r) > getLista(pl, largest))
		largest = r;

	if (largest != i) {
		int swap = getLista(pl, i);
		replaceIntoLista(pl, i, getLista(pl, largest));
		replaceIntoLista(pl, largest, swap);

		heapify(pl, n, largest);
	}
}

void heapSort(struct lista **pl) {
	int n = lengthLista(pl);
	for (int i = (n/2) - 1; i >= 0; i--)
		heapify(pl, n, i);

	for (int i = n - 1; i > 0; i--) {
		int temp = getLista(pl, 0);
		replaceIntoLista(pl, 0, getLista(pl, i));
		replaceIntoLista(pl, i, temp);
		heapify(pl, i, 0);
	} 
}

struct lista* cut(struct lista **pl, int low, int high) {
	struct lista *K1 = *pl;
	int i;
	for (i = 0; i < low; i++)
		K1 = K1->sig;

	struct lista *R = creaEL(K1->a);

	for (i = 0; i < high - low; i++) {
				K1 = K1->sig;
				//////////begin pushing
				struct lista *AUX0 = creaEL(K1->a);
				
				AUX0->sig = R;
				R = AUX0;
				/////////end pushing
				
				AUX0 = NULL;
			}

	struct lista *ll = creaEL(R->a);
	for (i = 0; i < high - low; i++) {
		R = R->sig;
		struct lista *AUX0 = creaEL(R->a);
		AUX0->sig = ll;
		ll = AUX0;
	}
	R = ll; 
	
	//*pl = R;
	return R;
}

int merge(struct lista **pl, int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	
	struct lista *L = cut(pl, l, l + n1 - 1);
	struct lista *R = cut(pl, m + 1, m + n2);
	
	int i;
	int j;

	i = 0; j = 0;

	int k = l;
	while (i < n1 && j < n2) {
		if (getSmallLista(L, i) <= getSmallLista(R, j)){
			replaceIntoLista(pl, k, getSmallLista(L, i));
			i++;
		} else {
			replaceIntoLista(pl, k, getSmallLista(R, j));
			j++;
		}
		k++;
	}

	while (i < n1) {
		replaceIntoLista(pl, k, getSmallLista(L, i));
			i++;
			k++;
	}

	while (i < n2) {
		replaceIntoLista(pl, k, getSmallLista(R, j));
			j++;
			k++;
	}

}

void mergeSort(struct lista **pl, int l, int r) {
	if (l < r) {
		int m = (l + r)/2;
		mergeSort(pl, l, m);
		mergeSort(pl, m+1, r);
		merge(pl, l, m, r);
	}
}