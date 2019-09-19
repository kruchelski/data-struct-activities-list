//ex2 - contar nós em uma lista encadeada
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct _Lista {
	int info;
	struct _Lista *node;
} Lista;


int empty(Lista *f) {
	return (f == NULL);
}

Lista* create(void) {
	return NULL;
}

Lista* insert(Lista *l, int elem) {
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = elem;
	novo->node = l;
	return novo;
}

void printLista(Lista *l) {
	Lista *atual;
	atual = l;
	while (atual != NULL) {
		printf("%d\t", atual->info);
		atual = atual->node;
	}
}

int conta_nos (Lista *lista) {
	Lista *atual;
	atual = lista;
	int i;
	for (i = 0; atual != NULL; atual = atual->node) {
		i++;
	}
	return i;
}

void clean(Lista* l) {
	Lista* aux = NULL;
	while (l != NULL) {
		aux = l->node;
		free(l);
		l = aux;
	}
}

int main(int argc, char* argv[]) {
	Lista *listinha = NULL;
	int num, limiter, i, j; //limiter é o valor máximo do rand
	num = limiter = 10000;// valores default
	srand(time(0)); // seed do random
	if (argc >= 3) limiter = atoi(argv[2]); 
	if (argc > 1) {
		if (atoi(argv[1])) num = atoi(argv[1]);
		else {
			printf("Entrada de valor incorreta. Finalizando\n");
			exit(0);
		}
	}
	num = rand() % num;	
	printf("num = %d\n", num);
	for (i = 0; i < num; i++) {

		j = rand() % limiter;
		listinha = insert(listinha, j);
	}	
	printf("Imprimindo:\n\n");
	printLista(listinha);
	printf("\n\nQuantidade de nos: %d\n\n", conta_nos(listinha));
	printf("FIM\n\n");
	clean(listinha);
	return 0;
}



