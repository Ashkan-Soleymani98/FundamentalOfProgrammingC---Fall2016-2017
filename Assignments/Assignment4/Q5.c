#include<stdio.h>
 
/* 
Author: Ashkan Soleymani
*/
 
long int isprime(long int n){
    long int i = 1;
    if  ((n == 1) || (n == 2)) return 0;
    for(i = 2 ; i * i <= n ; i++){
        if (n % i == 0) return 0;
    } 
    return 1;
}
long int f(long int a,long int p){
    long int i = 0;
    if (a % p == 0) return 0;
    if (a == 1) return 1;
    if (a == 2) {
        if ((p * p - 1) % 16  == 0) return 1;
        else return -1;
//        return (long int)pow((-1), ((p * p - 1) / 8));
    }
    if (a > p) return f(a % p,p);
    if (isprime (a) == 1) {
            if (((p - 1) * (a - 1)) % 8 == 0) return f(p , a);
            else return -1 * f(p , a);
    }
//            return (long int)pow((-1), ((p - 1)/ 2) * ((a - 1)/ 2)) * f (p , a);
    else{
        for (i = 2 ; (i * i <= a); i++){
            if ( a % i == 0){
                return f(i,p) * f(a / i , p); 
            }
        }
    }
}
int main(void){
    long int n = 0 , a = 0 , p = 0 , i = 0 ;
    scanf("%ld",&n);
    for (i = 1; i <= n; i++){
    	
        scanf("%ld %ld",&a, &p);
        printf("%ld\n" ,f(a,p));
    }
}
