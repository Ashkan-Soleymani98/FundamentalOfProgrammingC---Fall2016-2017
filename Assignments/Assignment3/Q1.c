#include<stdio.h>
#include<math.h>
 
/* 
Author: Ashkan Soleymani
*/
 
int primefinder (long int n) {
    long int i;
    for(i = 2 ; i <= sqrt(n); i++){
        if (  n % i == 0 )
            return 0;
    }
    if (n == 1) return 0;
    else return 1;
}
 
long int firstprimefinder (long int n) {
    long int i = 0 , x = 0 , y = 0 , d = 0 ;
    if (primefinder (n) == 1) return 0;
    else if (n == 1) d = 1;
    else {
        while (i <= n){
            x = n + i;
            y = n - i;
            if ( (primefinder(x) == 1) || (primefinder(y) == 1) ){
                d = i;
                break;
            }
            i++;
        }
    }
    return d;
}
 
int main(void){
    long int n = 0 , i = 0 , x = 0 , p = 0;
//    printf("%d",primefinder (1));
    long int smallest = -1;
    scanf("%ld",&n );
//    printf("%d", primefinder(n));
    while ( i < n ){
        scanf("%ld",&x);
        i++;
        if (smallest == 0){
            continue ;
        }
        else{
            p = firstprimefinder (x);
            if ( smallest < 0) smallest = p;
            if ( p <= smallest) smallest = p;
        }
    }
//    printf ("%d", firstprimefinder (n));
    printf("%ld",smallest);    
}
