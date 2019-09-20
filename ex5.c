//ex5 avaliar expressões na forma pós-fixa usando pilha
#include<stdio.h>
#include<stdlib.h>

typedef struct _Pilha {
	int *info;
	int top;
	int size;
} Pilha;

int contaChar(char **v) { // ver o tamanho da expressao pra definir o 
	char *c = v[1];		  // tamanho do vetor
	int i = 0;
	while (*c) {
		if (*c != ' ') {
			i++;
		}
		c++;
	}
	return i;
}
int* criaVetor(int n) {
	int *temp = (int*)malloc(sizeof(int) * n);
	return temp;
}

int empty(Pilha *p) {
	return (p->top == 0);
}

int full(Pilha *p) {
	return (p->top == (p->size - 1));
}

void push(Pilha *p, int elem) {
	if (full(p)) {
		printf("\npilha cheia!\n");
		return;
	} else {
		p->info[p->top] = elem;
		p->top++;
	}
}

int pop(Pilha *p) {
	if (empty(p)) {
		printf("\npilha vazia\n");
		return -999;
	} else {
		p->top--;
		return p->info[p->top];
	}
}

void continhas(Pilha *p, char operador){
	int op1, op2;
	op2 = pop(p);
	op1 = pop(p);
	switch(operador) {
		case('+'):
			push(p, (op1 + op2));
			break;

		case('-'):
			push(p, (op1 - op2));
			break;

		case('*'):
			push(p, (op1 * op2));
			break;

		case('/'):
			if (op2 != 0) push(p, (op1 / op2));
			else push(p, 0);
			break;

		default:
			push(p, -999);
	}
}

void process(Pilha *p, char *v) {
	char *aux;
	aux = v;
	char ch; //TODO se tudo funcionar tirar isso daqui
	while (*aux) {
		if (*aux != ' ') {
			if ((*aux >= '0') && (*aux <= '9')) {
				ch = *aux;
				push(p, (int)(ch - '0'));
			} else {
				ch = *aux;
				continhas(p, ch);
			}
		}
		aux++;
	}
}

void printPilha(Pilha *p) {
	if(empty(p)){
		printf("\n\nERRO! Pilha vazia!\n\n");
	} else {
		while (!empty(p)) {
			printf(".%d.", pop(p));
		}
	}
}

int main(int argc, char *argv[]) {
	Pilha *pila = (Pilha*)malloc(sizeof(Pilha));
	pila->top = 0;
	pila->info = NULL;
	pila->size = contaChar(argv);
	pila->info = criaVetor(pila->size);

	process(pila, argv[1]);
	printf("Resultado: ");
	printPilha(pila);
	printf("\n\nFIM\n\n");

	return 0;
}