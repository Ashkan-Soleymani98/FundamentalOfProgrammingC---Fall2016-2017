#include<stdio.h>
#include<math.h>
/* 
	Author: Ashkan Soleymani
*/

int main (void){
	int a = 0, b = 0, spacecounter2 = 0;
	int i = 0, j = 0;
	int x = 0, bcounter = b, spacecounter = 0, y = 0;
	scanf("%d %d",&a, &b);
	int diameter = (2 * a) - 1;
	int limit = ( ( (2 * a) - 1) - b);
	bcounter = b;
	int middlecounter = 1;
	while ( i < limit){
		i += 2;
		spacecounter = diameter - bcounter;
		if ( bcounter < 2 * b){
			j = 0;
			while ( j < (spacecounter/2) ){
				j++;
				printf(" ");
			}
			j = 0;	
			while ( j < bcounter ){
				j++;
				printf("*");
			}
			j = 0;
			while ( j < (spacecounter/2) ){
				j++;
				printf(" ");
			}
			j = 0;
			printf("\n");		
		}
		if ((bcounter < 2 * b) && (i != 0)){
			bcounter += 2;
		if (bcounter > 2 * b) bcounter = 2 * b;
		}
		if ( bcounter >= 2 * b){
			j = 0;
			while ( j < (spacecounter - middlecounter)/2 ){	
				j++;
				printf(" ");
			}
			j = 0;
			while( j < b){
				printf("*");
				j++;
			}
			j = 0;
			while( j < middlecounter ){
				printf(" ");
				j++;
			}
			j = 0;
			while( j < b){
				printf("*");
				j++;
			}
			while ( j < (spacecounter - middlecounter)/2 ){	
				j++;
				printf(" ");
			}
			middlecounter += 2;
			printf("\n");
		}
	}
	middlecounter -= 4;
	while( i >= 1){
		i -= 2;
		spacecounter = diameter - bcounter;
		if (( bcounter >= 2 * b ) && (middlecounter > 0)){
			j = 0;
			while ( j < (spacecounter - middlecounter)/2 ){	
				j++;
				printf(" ");
			}
			j = 0;
			while( j < b){
				printf("*");
				j++;
			}
			j = 0;
			while( j < middlecounter ){
				printf(" ");
				j++;
			}
			j = 0;
			while( j < b){
				printf("*");
				j++;
			}
			while ( j < (spacecounter - middlecounter)/2 ){	
				j++;
				printf(" ");
			}
			middlecounter -= 2;
			printf("\n");
		}
		
	}
	bcounter = 2 * b - 1; 
	while (bcounter >= b){
		spacecounter = diameter - bcounter;
		j = 0;
		while ( j < (spacecounter/2) ){
			j++;
			printf(" ");
		}
		j = 0;	
		while ( j < bcounter ){
			j++;
			printf("*");
		}
		j = 0;
		while ( j < (spacecounter/2) ){
			j++;
			printf(" ");
		}
		j = 0;
		printf("\n");
		bcounter -= 2;		
	} 		
}
