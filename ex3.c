//ex3 - procurar elemento numa lista
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

Lista* procurar(Lista *lista, int elem) {
	Lista *v = NULL;
	if (lista == NULL) {
		printf("Lista vazia\n\n");
		return NULL;
	}
	for (v = lista; v != NULL; v = v->node) {
		if (v->info == elem) break;
	}
	return v;
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
	Lista * found = NULL;
	int num, limiter, i, j; //limiter é o valor máximo do rand
	num = limiter = 10000;// valores default
	srand(time(0)); // seed do random
	if (argc >= 3) {
		if (atoi(argv[2])) limiter = atoi(argv[2]); // verificar se foi digitado algo maior que 0 no arg 2
	}
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
	j = rand() % limiter; // elemento buscado
	found = procurar(listinha, j);
	printLista(listinha); // impressao da lista é opcional
	printf("\n\n");
	if (found == NULL) {
		printf("elemento: %d nao encontrado. retornado NULL\n\n", j);
	} else {
		printf("elemento: %d encontrado\nno endereco: %X\ninfo do no:%d\n",j, found, found->info);
	}
	printf("FIM\n\n");
	clean(listinha);
	return 0;
}



