//ex1 numero par/impar e armazenar em filas
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct _fila {
	int info;
	struct _fila *node;
} Fila;


int empty(Fila *f) {
	return (f == NULL);
}

Fila* enqueue(Fila **q, Fila **end, int elem) {
	Fila* novo = (Fila*)malloc(sizeof(Fila));
	Fila* aux;
	novo->info = elem;
	novo->node = NULL;
	if(*q != NULL){
		aux = *end;
		aux->node = novo;
	}else {
		*q = novo;
		*end = *q;
	}
	return novo;
}

int dequeue(Fila **q) {
	if (empty(*q)) {
		printf("fila vazia!");
		return -999;
	}
	int n;
	Fila* aux = (Fila*)malloc(sizeof(Fila));
	aux = (*q)->node;
	n = (*q)->info;
	free(*q);
	*q = aux;
	return n;
}

//função criada apenas para testes
void printFila(Fila **q) {
	while (!empty(*q)) {
		printf("%d\t", dequeue(q));
	}
}

void clean(Fila* q) {
	Fila* aux = NULL;
	while (q != NULL) {
		aux = q->node;
		free(q);
		q = aux;
	}
}

int checkPar(int n) {
	if ((n % 2) == 0) {
		return 1;
	} else {
		return 0;
	}
}

int main(int argc, char* argv[]) {
	Fila *impar, *par;
	Fila *endPar, *endImpar; //apontam para o último elemento 
	par = impar = endPar = endImpar = NULL;
	int num, limiter, i, j; //limiter é o valor máximo do rand
	num = limiter = 10000;// valores default
	srand(time(0)); // seed do random
	printf("pom\n");
	printf("%d\n", argc);
	if (argc >= 3) limiter = atoi(argv[2]); 
	if (argc > 1) {
		if (atoi(argv[1])) num = atoi(argv[1]);
		else {
			printf("Entrada de valor incorreta. Finalizando\n");
			exit(0);
		}
	}	
	for (i = 0; i < num; i++) {
		j = rand() % limiter;
		if (checkPar(j)) endPar = enqueue(&par, &endPar, j);
		else endImpar = enqueue(&impar, &endImpar, j);
	}	
	printf("Pares:\n\n");
	printFila(&par);
	printf("\n\nImpares:\n\n");
	printFila(&impar);
	printf("\n\nFIM\n\n");
	clean(par);
	clean(impar);
	return 0;
}



