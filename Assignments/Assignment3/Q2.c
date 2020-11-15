#include<stdio.h>
#include<math.h>
 
/*
Author : Ashkan Soleymani
*/
 
int primefinder (int n) {
    int i;
    for(i = 2 ; i <= sqrt(n); i++){
        if (  n % i == 0 )
            return 0;
    }
    if (n == 1) return 0;
    else return 1;
}
 
int f (int n){
    int i = 0 , j = 0;
    for(i = 1; i < n; i++){
        if (primefinder(i) == 1) j++;
    }
    return j;
}
 
int g (int n){
    int i = 0 , j = 0;
    for(i = 1; i < n / 2 + 1; i++){
        if (n % i == 0) {
        	if (primefinder(i) == 1) j++;
        }
    }
    return j;    
}
 
int main(void){
    int n = 0 , stone = 0, price = 0, i = 0;
    scanf("%d", &n);
    for ( i = 1; i <= n ; i++){
        scanf("%d", &stone);
        if (primefinder (stone) == 1 ) price += f(stone);
        else price += g(stone);
    }
    if (primefinder (price) == 1 ) price -= f(price);
    else price -= g(price);
    printf("%d",price);
}
