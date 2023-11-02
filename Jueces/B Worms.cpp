#include <iostream>
using namespace std;

int p[10000];


int bin_search(int num, int l, int r){
	int mid; 
    while( l<=r ) {
        mid = (l+r)/2;
    	if(num > p[mid- 1] && num <= p[mid]){
              break;
         }
         
        if(p[mid] >= num) {
            r = mid -1;
        }
        else if(p[mid]< num){
            l = mid+1;
        }
    }
    return mid;
}

int main() {
	// your code goes here
	int n, a, m, q;
	while(scanf("%d ", &n) != EOF){ // Lee el numero de lineas que contendran a las gomitas 
		scanf("%d ", &p[1]); // Crea un array con la cantidad total de gomitas en la primera fila
		for (int i=1; i<n ; i++){ // Pone el total de gomitas por fila = [0, 1, 2, 3 , 4, 5]
			scanf("%d ", &a);     //                                    p[0, 2, 9, 12 ,16,25] 
			p[i+1]= p[i]+a;
		}
		scanf("%d ", &m); //Lee cuantas gomiTas jugosas hay
		while(m--){ // Busca las gomitas jugosas en el array, gomita por gomita
			scanf("%d ", &q);
			printf("%d\n", bin_search(q, 0, n));
		}
	}
	return 0;
}

