//ex4 - separar lista apos ocorrencia de um determinado elemento
/* Alunos:
*  André Klingenfus Antunes
*  Cassiano Kruchelski Vidal
*/
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

Lista* separa(Lista *lista, int n) {
	if (lista == NULL) {
		printf("Lista vazia\n\n");
		return NULL;
	}
	Lista *v = NULL;
	Lista *aux = NULL;
	for (v = lista; v != NULL; v = v->node) {
		if (v->info == n) {
			aux = v->node;
			v->node = NULL;
			break;
		}
	}
	return aux;
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
	Lista * nouveau = NULL; //num é o numero máximo possível de elementos
	int num, limiter, i, j; //limiter é o range máximo do rand
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
	printf("num = %d\n", num);
	for (i = 0; i < num; i++) {

		j = rand() % limiter;
		listinha = insert(listinha, j);
	}

	j = rand() % limiter; // elemento que será utilizado para separar

	printf("Lista original:\n\n");
	printLista(listinha);
	nouveau = separa(listinha, j);
	printf("\n\nLista parte 1:\n\n");
	printLista(listinha);
	printf("\n\nLista parte 2 (separada em %d):\n\n", j);
	printLista(nouveau);
	printf("\n\n");
	printf("FIM\n\n");
	clean(listinha);
	clean(nouveau);
	return 0;
}



