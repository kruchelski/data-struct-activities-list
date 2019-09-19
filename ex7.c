//ex7 busca binaria iterativa
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000000

void preenche(int *v, int limiter) {
	int i, j;
	for (i = 0; i < MAX; i++) {
		j = rand() % limiter;
		*(v + i) = j;
	}
}

void maxHeapfy(int *v, int i, int tam) {
	int maior = i, left = 2 * i + 1, right = 2 * i + 2, temp;
	if (left < tam && v[left] > v[maior]) maior = left;
	if (right < tam && v[right] > v[maior]) maior = right;
	if (maior != i) {
		temp = v[i];
		v[i] = v[maior];
		v[maior] = temp;
		maxHeapfy(v, maior, tam);
	}
}
void buildHeap(int *v, int tam) {
	int i, n, temp;

	for (i = (tam / 2) - 1; i >= 0; i--) {
		maxHeapfy(v, i, tam);
	}
	for (n = tam - 1; n >= 1; n--) {
		temp = v[0];
		v[0] = v[n];
		v[n] = temp;
		maxHeapfy(v, 0, n);
	}
}
void heapSort(int *v, int tam) {
	buildHeap(v, tam);
}

void printVetor(int *v) {
	int i;
	for (i = 0; i < MAX; i++) {
		printf("%d .. ", v[i]);
	}
}

int buscar (int* v, int n, int elem) {
	int left, mid, right;
	left = 0; right = n - 1; mid = n / 2;
	while ((mid > left) && (mid < right)) {
		if (elem == v[mid]) return mid;
		else if (elem < v[mid]) {
			right = mid;
			mid = ((right - left) / 2) + left;
		} else {							
			left = mid;
			mid = ((right - left) / 2) + left;
		}
	}
	return -999;
}

int main(int argc, char* argv[]) {
	srand(time(0));
	int limiter = 100000; //limiter é o valor máximo do rand
	int buscas = 10000;
	int vetor[MAX], i, j, r;

	if (argc >= 3) {
		if (atoi(argv[2])) buscas = atoi(argv[2]); // verificar se foi digitado algo maior que 0 no arg 2
	}
	if (argc > 1) {
		if (atoi(argv[1])) limiter = atoi(argv[1]);
		else {
			printf("Entrada de valor incorreta.\n");
		}
	}

	preenche(vetor, limiter);
	printf("Imprimindo os dados sem ordenar:\n\n");
	printVetor(vetor);
	heapSort(vetor, MAX);
	printf("\n\nImprimindo os dados ordenados\n\n");
	printVetor(vetor);
	printf("\nBuscas\n");

	for (i = 0; i < buscas; i++) {
		j = rand() % limiter;
		r = buscar(vetor, MAX, j);
		(r > 0 ? printf("valor: %d encontrando em: %d (%d)\n", j, r, vetor[r]) : printf("valor: %d nao encontrado...\n", j));
	}

	printf("\n\nFIM\n\n");
	return 0;
}



