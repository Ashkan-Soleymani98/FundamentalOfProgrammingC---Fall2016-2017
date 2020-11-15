
#include<stdio.h>

/* 
Author: Ashkan Soleymani
*/

int main(){
	long long int n , m , k;
	scanf("%lld %lld %lld",&n ,&m ,&k);
	long long int boofe[k];
	long long int i , j;
	long long int u;
	
	for ( i = 0 ; i < k ; i++){
		scanf("%lld",&boofe[i]);
	}
	
	if( (n == 0) || (m == 0)){
		printf("0");
		return 0;
	} 
	
	long long int freecounter = 0;
	long long int space[n][m];
	long long int y;
	long long int free[m * n][2];
	
	for( i = 0 ; i < n ; i++){
		for(j = 0 ; j < m ; j++){
			scanf("%lld",&space[i][j]);
			if (space[i][j] == -1){
				free[freecounter][0] = i;
				free[freecounter][1] = j;
				freecounter++;
			}
		}
	}
	
//	for(i = 0 ; i < freecounter ; i++){
//		printf("%d %d \n",free[i][0] , free[i][1]);
//	}
	
	long long int a = 0, b = 0, bf = 0 , af = 0 , t = 0 , q = 0;
	long long int pay1 = 0, paytype = 0, pay = 126000000 , a1 = 0;

	for (t = 0 ; t < freecounter ; t++){
		b = free[t][1];
		a = free[t][0];
		for (y = 0 ; y < free[t][1] ; y++){
			a1 = free[t][0];
			paytype = space[a1][y];
			b = free[t][1];
			a = a1;
			if (paytype <= 0)continue;
			pay1 += boofe[paytype - 1];
		}
		if (pay1 <= pay){
			pay = pay1;
			af = a + 1;
			bf = b + 1;
		}
		pay1 = 0;
		for (y = m - 1 ; y > free[t][1]  ; y--){
			a1 = free[t][0];
			paytype = space[a1][y];
			b = free[t][1];
			a = a1;
			if (paytype <= 0) continue;
			pay1 += boofe[paytype - 1];
		}
		if (pay1 <= pay){
			pay = pay1;
			af = a + 1;
			bf = b + 1;
		}
		pay1 = 0;
	}
	printf("%d %d %d",pay ,bf ,af );
}
