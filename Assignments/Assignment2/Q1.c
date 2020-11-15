#include<stdio.h>
/*
Author:  Ashkan Soleymani
*/
 
int main(void){
    int n = 0 , j = 1;
    scanf("%d",&n);
    int a1 = 0, a2 = 0;
    if (n <= 2){
        for (j = 1 ; j <= n ; j++){
            scanf("%d",&a1);
        }
        printf("Yes");
        return 0;
    }
    scanf("%d %d",&a1 ,&a2);
    int i = 1;// loop counter
    int q;// if aranger
    int cte = 0;
    int t = 0;
    int x = 0;
    while (a1 == a2){
        scanf("%d",&a2);
        if (i == (n - 2)){
            printf("Yes");
            return 0;
        }
        i++;
    }
    if (a1 > a2){
        q = 1;
    }
    else if( a1 < a2){
        q = 2;
    }
//    s = 1;
    while ( i <= (n - 2) ){
        i++;
        cte = a1 - a2;
        a1 = a2;
        scanf("%d",&a2 );
        t = a1 - a2;
        if ( (x != 0) && (t == 0) ){
            printf("No");
            return 0;
        }
        while (( t == 0) && ( x == 0) && ( i <= (n - 2))){
        	i++;
        	a1 = a2;
        	scanf("%d",&a2 );
        	t = a1 - a2;
        }
        if(( t == 0 ) && ( x == 0)){
            continue;
        }
        if(q == 1){
        	if ( t == 0) {
        	}
            if ( ( t * cte ) < 0){
                x++;
            }
            if ( x >= 2){
                printf("No");
                return 0;
            }
        }
        else if(q == 2){
            if ( ( t * cte ) < 0){
                x++;
            }
            if ( x >= 2){
                printf("No");
                return 0;
            }
        }
    }
    if (x <= 1) {
        printf("Yes");
    }
    else if ( x >= 2){
        printf("No");
    }
}
