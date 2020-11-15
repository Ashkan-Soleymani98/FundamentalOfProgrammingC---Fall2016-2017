#include<stdio.h>
#include<math.h>

/*
Author : Ashkan Soleymani
*/

int f (int n){
	int i = 0, sum = 0;
	for (i = 1;i <= n;i++){
		if (n % i == 0) sum += i;
	}
	return sum;
}

int g (int n, int k){
	int sum = 0;
	while(n >= 1){
		sum += (n % k);
		n /= k;
	}
	return sum;
} 

int main(void){
	int n , k;
	scanf("%d %d",&n ,&k);
	int i = 1 , sumt = 0;
	for (i = 1; i <= n; i++){
		if (n % i == 0 ){
			sumt += (f(n / i) * g(i , k));
		}
	}
	printf("%d",sumt);
}
