#include<stdio.h>

/* 
Author: Ashkan Soleymani
*/
 
long long int min(long long  int a,long long int b){
	if (a < b) return a;
	return b;
}
long long int sqrt(long int t){
	
}

int main(){
	long long int n;
	long long int a , b , c , d;
	long long int i , j , k;
	scanf("%ld",&n);
	long long int array[n][5];
	for(i = 0 ; i < n ; i++){
		scanf("%lld %lld",&a ,&b);
		for(j = 2; j <= min (a , b) ; j++){
			if( (a % j == 0 ) && (b % j == 0) ){
				a /= j;
				b /= j;
			}
		}
		a *= b;
		long long int w;
		for(c = a - 1; c >= 1 ; c--){
			if(a % (c * c) == 0 ) {
				break;
			}
		} 
		if (c == 0) c = 1;
		a /= (c * c) ;
		for(j = 2; j <= min (c , b) && min (c , b) != 1; j++){
			if( (c % j == 0 ) && (b % j == 0) ){
				b /= j;
				c /= j;
			}
		}
		array[i][1] = c;
		array[i][2] = b;
		array[i][3] = a;
		array[i][0] = 0;
	}
	
//	for (i = 0 ; i < n ; i++){
//		printf("0 %d %d %d\n",array[i][1] ,array[i][2] ,array[i][3]);
//	}

	for(j = n - 1 ; j >= 0 ; j--){
		for(i = 0 ; i < j ; i++){
			if( (array[i][3] == array[j][3]) && (array[i][3] != 0) && (array[j][3] != 0)){
				a = array[i][1];
				b = array[i][2];
				c = array[j][1];
				d = array[j][2];
				array[i][3] = 0;
				a = (a * d) + (b * c);
				b = b * d;
				array[j][1] = a;
				array[j][2] = b;
			}
		}
		for (k = 2 ; k <= min (array[j][1],array[j][2])  && (min (array[j][1],array[j][2]) != 1); k++){
			if ( (array[j][1] % k == 0) && (array[j][2] % k == 0)){
		 		array[j][2] /= k;
				array[j][1] /= k;
			}
		}
		array[j][0] = array[j][1] / array[j][2];
		array[j][1] %= array[j][2];
		for (k = 2 ; k <= min (array[j][1],array[j][2]) && (min (array[j][1],array[j][2]) != 1) ; k++){
			if ( (array[j][1] % k == 0) && (array[j][2] % k == 0)){
		 		array[j][2] /= k;
				array[j][1] /= k;
			}
		}
//		if (array[j][3] != 0){
//			for(k = 0 ; k < 4 ; k++){
//				printf("%d ",array[j][k]);
//			}
//			printf("\n");
//		}
	}
	
	long int a1 = 0;
    long int temp; 
    long int coarray[n];
    for(i = 0 ; i < n ; i++){
        array[i][4] = 0;
        coarray[i] = array[i][3];
    }
    
    for(j = n - 1; j >= 0  ; j--){
        for(i = 0 ; i < j ; i++){
            if(coarray[i] > coarray[i + 1]){
                temp = coarray[i + 1];
                coarray[i + 1] = coarray [i];
                coarray[i] = temp;
            }
        }
    }
    for(i = 0 ; i < n ;){
        for(k = 0 ; k < n ; k++){
            if ( (coarray[i] == array[k][3]) && (array[k][4] == 0) && (array[k][3] != 0) ){    
                array[k][4] = 1;
                for (j = 0 ; j < 4 ; j++){
                    printf("%lld ",array[k][j]);
                }
                printf("\n");
                a1 = 1;
                i++;
                break;
            }
        }
        if( a1 == 0) i++;
        a1 = 0;
    } 
}
