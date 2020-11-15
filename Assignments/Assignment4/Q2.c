#include<stdio.h>
/* 
Author: Ashkan Soleymani
*/

int gcd(int a, int b){
	int r = a % b;
	if (r==0) return b;
	return gcd(b , r);
}

int main (void){
	int n = 0 , i = 0;
	int a = 0, b = 0;
	scanf("%d\n",&n);
	for(i = 1;i <= n;i++){
		scanf ("%d %d",&a ,&b);
		printf("%d \n", gcd(a,b));
	}
}
