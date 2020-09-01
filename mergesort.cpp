#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
 v: Vetor a ser ordenado
 p: Posição inicial
 q: Posição do meio
 r: Posição no fim
 */

void merge(int v[], int p, int q, int r) {
	int i = p;
	int j = q;
	int k = 0;
	int w[r-p];


	// Recombina o resultado entre os subconjuntos em w
	while(i < q && j <= r) {
		if(v[i] <= v[j]){
			w[k++] = v[i++];
		}else{
			w[k++] = v[j++];	
		} 
	}

	// Completa os valores que faltam ainda de uma das partes
	while(i<q){
		w[k++] = v[i++];	
	} 

	while(j<=r){
		w[k++] = v[j++];
	} 

	// Copia o resultado do vetor ordenado w para o vetor original
	for(i=p,j=0;i<=r;i++,j++){
		v[i] = w[j];	
	} 
}

void mergesort(int v[], int p, int q) {
	if(p < q){
		int k=(p+q)/2;

		mergesort(v,p,k);
		mergesort(v,k+1,q);
		merge(v,p,k+1,q);
	} 
}

int main() {

	int n = 15;
	int v[] = {9, 10, -1, 3, 6, 2, 1, -3, 1, 0, -2, 15, 8, -7, 0};

	mergesort(v,0,n-1);
	cout << "Vetor ordenado: { ";

	for(int i=0;i<n;i++) {
		cout << v[i] << " ";
	}

	cout << "}" << endl;

	return EXIT_SUCCESS;
}