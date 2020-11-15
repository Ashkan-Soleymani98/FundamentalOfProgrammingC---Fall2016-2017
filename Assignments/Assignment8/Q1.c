#include<stdio.h>
#include<stdlib.h>

/*
Author: Ashkan Soleymani
*/

void explosion(int ***place ,int expminex ,int expminey, int m , int n){
	int p , q , cte;
 	int mineexpanse = *(*(*(place + expminex - 1) + expminey - 1));
	*(*(*(place + expminex - 1) + expminey - 1) + 1) = -1;
	
	for(p = expminex - mineexpanse ; p <= expminex + mineexpanse ; p++){
		for(q = expminey - mineexpanse ; q <= expminey + mineexpanse ; q++){
			if( (p >= 1) && (q >= 1) && (p <= m) && (q <= n)){
				cte = *(*(*(place + p - 1) + q - 1) + 1);// place i , j , 2
				*(*(*(place + p - 1) + q - 1) + 1) = -1;
				if( (*(*(*(place + p - 1) + q - 1)) != 0) && (cte != -1)){
					explosion(place , p , q , m , n);
				}
			}
		}
	}	
	return;
}

int main(){
	int ***place;
	int m , n;
	int i , j;
	int a , b , c;
	scanf("%d%d",&m ,&n);
	int minesnumber;
	scanf("%d",&minesnumber);
	place = (int ***)calloc(m , sizeof(int**));
	
	for(i = 0 ; i < m ; i++){
			*(place + i) = (int **)calloc(n , sizeof(int*));
			for(j = 0 ; j < n ; j++){
				*(*(place + i) + j) = (int *)calloc(2 , sizeof(int));
//				*(*(*(place + i) + j)) = 1;
//				printf("%d ", *(*(*(place + i) + j)) );
			}
//			printf("\n");
	}
	
	for(i = 0 ; i < minesnumber ; i++){
		scanf("%d%d%d",&a ,&b ,&c);
		*(*(*(place + a - 1) + b - 1)) = c; 	
	}
	
	int expminex , expminey;
	scanf("%d%d",&expminex ,&expminey);
	if(*(*(*(place + expminex - 1) + expminey - 1)) == 0){
		printf("%d", n * m - 1);
	}
	else{
		explosion(place , expminex , expminey , m , n);
		int sum = 0;
	
		for(i = 0 ; i < m ; i++){
			for(j = 0 ; j < n ; j++){
//				printf("%d ", *((*(*(place + i) + j)) + 1) );
				sum += *((*(*(place + i) + j)) + 1);
			}
//			printf("\n");
		}
	
		printf("%d",n * m + sum);
	}
}
