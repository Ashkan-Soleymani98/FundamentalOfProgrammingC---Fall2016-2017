#include<stdio.h>

/* 
Author: Ashkan Soleymani
*/

int f (int sum , int max){
	int i = 0 , counter = 0;
	if (sum == max) {
		return 1;
	}
	for (i = 1 ; (i <= max) & (sum > 0) ; i++){
		counter += f (sum - max , i);
//				printf("a");
	}
	return counter;
}

int main(void){
	int counter = 0 , sum = 0;
	scanf("%d",&sum);
	int i = 1;
	for ( i = 1 ; i <= sum ; i++){
		counter += f(sum , i);
	}
	printf ("%d", counter);
}
