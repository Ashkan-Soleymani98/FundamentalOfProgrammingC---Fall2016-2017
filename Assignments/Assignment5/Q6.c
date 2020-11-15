#include<stdio.h>
 
/* 
Author: Ashkan Soleymani
*/
 
int main(){
    int n , k;
    int counter = 0 , m = 0 , b = 0 , maxcounter = 0;
    scanf("%d",&n);
    int array[n][2];
    int j , i;
    int x , y;
    for(i = 0 ; i < n ; i++){
        scanf("%d %d",&x ,&y);
        array[i][0] = x;
        array[i][1] = y;
    }
    if (n == 1){
        printf("1");
        return 0;
    }
    for( i = 0 ; i < n ; i++){
    	for(j = 0 ; j < n ; j++){
    		if (array[i][0] != array[j][0]){
       			m = (array[i][1] - array[j][1])/(array[i][0] - array[j][0]);
				b = - m * array[i][0] + array[i][1];
        	}
        	for(k = 0 ; k < n ; k++){
         	   if (array[k][1] == array[k][0] * m + b) {
            	    counter++;
            	}
        	}
        	if (counter > maxcounter){
            	maxcounter = counter;
       		}
       		counter = 0;
        }	
    }
    for(i = 0 ; i < n ; i++){
        	for(j = 0 ; j < n ; j++){
            	if (array[j][0] == array[i][0]) {
            	    counter++;
            	}
        	}
        	if (counter > maxcounter){
            	maxcounter = counter;
        	}
        	counter = 0;
   	}
    printf("%d",maxcounter);
}
