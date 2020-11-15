 #include<stdio.h>
 
/* 
Author: Ashkan Soleymani
*/
 
unsigned long int f(unsigned long int n,unsigned long int k){
	if ( n == k) return 1;
	if ( k == 0) return 1;
	return f(n - 1, k - 1) + f (n - 1 , k);
}
int main(){
    unsigned long int n;
    scanf("%uld",&n);
//    printf("%d",f(n));
    if (n == 1) printf("1\n1");
    else if (n % 2 == 1) printf("%u\n2",n * (n / 2 + 1));
    else if (n == 2) printf("2\n4");
    else printf("%u\n%u",n * n / 2,f(n , n / 2) * f (n , n / 2));
}
