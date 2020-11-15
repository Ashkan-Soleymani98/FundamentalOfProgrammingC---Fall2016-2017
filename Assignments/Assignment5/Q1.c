#include<stdio.h>

/*
Author: Ashkan soleymani
*/


int main(){
	int i = 0 , j = 0 , k = 0,min=0, max=0 , a = 0;
	int n , temp;
	scanf("%d\n",&n); 
	int array[n][6];
	int coarray[n];
	for(i = 0 ; i < n ; i++){
		for (j = 0 ; j < 5 ; j++){
			scanf("%d",&array[i][j]);
		}
		array[i][5] = 0;
		coarray[i] = array[i][1];
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
	
//	for(i = 0 ; i < n ; i++){
//		printf("%d ",coarray[i]);
//		printf("\n");
//	}
	
	
	for(i = 0 ; i < n ;){
		for(k = 0 ; k < n ; k++){
			if ( (coarray[i] == array[k][1]) && (array[k][5] == 0) ){	
				array[k][5] = 1;
				for (j = 0 ; j < 5 ; j++){
					printf("%d ",array[k][j]);
				}
				printf("\n");
				a = 1;
				i++;
				break;
			}
		}
		if( a == 0) i++;
		a = 0;
	}	
}
