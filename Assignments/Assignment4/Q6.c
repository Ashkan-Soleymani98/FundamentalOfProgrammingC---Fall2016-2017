#include<stdio.h>

/* 
Author : Ashkan Soleymani
*/
int xf , yf , zf;
int a , b , c;
//int arranger = 0;
int min;
int minm = 1000;
int i = 0;
int j = 0;
int f(int x , int y , int z , int m , int arranger){
//	printf("%d\n",m);
//	printf("arranger:%d\n",arranger);
	if ( m >= 15){
		return minm;
	}
	
	if ((x == xf) && (y == yf) && (z == zf)){
		if (m < minm) {
			minm = m;
		}	
	}
	
	if ( ( x > 0 ) && (y < b) && ( arranger != 1) ){
//		arranger = 1;
		if (x >= (b - y)){
			f(x - (b - y), b , z , m + 1 , 1);
		}
		else{
			f( 0 , y + x , z , m + 1 , 1);
		}
//		return 0;
	}
	if ( ( x > 0 ) && (z < c) && (arranger != 2) ){
//		arranger = 2;
		if (x >= (c - z)){
			f(x - (c - z), y , c , m + 1 , 2);
		}
		else{
			f(0 , y , z + x , m + 1 , 2);
		}
//		return 0;
	}
	if ( ( y > 0 ) && (x < a) && (arranger != 1) ){
//		arranger = 1;
		if (y >= (a - x)){
			f(a, y - (a - x) , z , m + 1 , 1);
		}
		else{
			f(x + y , 0 , z , m + 1 , 1);
		}
//		return 0;
	}
	if ( ( y > 0 ) && (z < c) && (arranger != 3) ){
//		arranger = 3;
		if (y >= (c - z)){
			f(x , y - (c - z) , c , m + 1 , 3);
		}
		else{
			f(x , 0 , z + y, m + 1 , 3);
		}
//		return 0;
	}
	if ( ( z > 0 ) && (x < a) && (arranger != 2) ){
//		arranger = 2;
		if (z >= (a - x)){
			f(a , y , z - (a - x) , m + 1 , 2);
		}
		else{
			f(x + z , y , 0 , m + 1 , 2);
		}
//		return 0;
	}
	if ( ( z > 0 ) && (y < b) && (arranger != 3) ){
//		arranger = 3;
		if (z >= (b - y)){
			f(x , b , z - (b - y) , m + 1 , 3);
		}
		else{
			f(x , y + z , 0 , m + 1 , 3);
		}
//		return 0;
	}
	return minm ;
}

int g(int x , int y , int z , int m , int arranger){
//	printf("%d\n",m);
//	printf("%d\n", min);
//	printf("arranger:%d\n",arranger);
	if ( min == 0){
		return 0;
	}
	
//	if ((x == xf) && (y == yf) && (z == zf)){
//		if (m == minm){
//			i = 1;
//			minm = m;
//			return 0;
//		}	
//	}
	if ( ( x > 0 ) && (y < b) && ( arranger != 1) ){
//		arranger = 1;
		minm = 1000;
		if (x >= (b - y)){
			if (f(x - (b - y), b , z , 0 , 1) == min - 1){
				min--;
				printf("dabbe 1 -> dabbe 2\n%d %d %d\n",x - (b - y) , b ,z);
				g(x - (b - y), b , z , m + 1 , 1);
			}
		}
		else{
			if (f( 0 , y + x , z , 0 , 1) == min - 1){
				min--;
				printf("dabbe 1 -> dabbe 2\n%d %d %d\n",0 ,x + y ,z);
				g( 0 , y + x , z , m + 1 , 1);
			}
		}
		
//		return 0;
	}
	if ( ( x > 0 ) && (z < c) && (arranger != 2) ){
//		arranger = 2;
		minm = 1000;
		if (x >= (c - z)){
			if(f(x - (c - z), y , c , 0 , 2) == min - 1){
				min--;
				printf("dabbe 1 -> dabbe 3\n%d %d %d\n",x - (c - z) , y , c);
				g(x - (c - z), y , c , m + 1 , 2);
			}
		}
		else{
			if (f(0 , y , z + x , 0 , 2) == min - 1){
				min--;
				printf("dabbe 1 -> dabbe 3\n%d %d %d\n",0 ,y ,z + x);
				g(0 , y , z + x , m + 1 , 2);
			}
		}
		
//		return 0;
	}
	if ( ( y > 0 ) && (x < a) && (arranger != 1) ){
//		arranger = 1;
		minm = 1000;
		if (y >= (a - x)){
			if (f(a, y - (a - x) , z , 0  , 1) == min - 1){
				min--;
				printf("dabbe 2 -> dabbe 1\n%d %d %d\n",a ,y - (a - x) ,z);
				g(a, y - (a - x) , z , m + 1 , 1);
			}
		}
		else{
			if (f(x + y , 0 , z , 0 , 1) == min - 1){
				min--;
				printf("dabbe 2 -> dabbe 1\n%d %d %d\n",x + y , 0 ,z);
				g(x + y , 0 , z , m + 1 , 1);
			}
		}
	
//		return 0;
	}
	if ( ( y > 0 ) && (z < c) && (arranger != 3) ){
//		arranger = 3;
		minm = 1000;
		if (y >= (c - z)){
			if (f(x , y - (c - z) , c , 0 , 3) == min - 1){
				min--;
				printf("dabbe 2 -> dabbe 3\n%d %d %d\n",x ,y - (c - z) , c);
				g(x , y - (c - z) , c , m + 1 , 3);
			}
		}
		else{
			if (f(x , 0 , z + y, 0 , 3) == min - 1){
				min--;
				printf("dabbe 2 -> dabbe 3\n%d %d %d\n",x ,0 , z + y);
				g(x , 0 , z + y, m + 1 , 3);
			}
		}
		
//		return 0;
	}
	if ( ( z > 0 ) && (x < a) && (arranger != 2) ){
//		arranger = 2;
		minm = 1000;
		if (z >= (a - x)){
			
			if (f(a , y , z - (a - x) , 0 , 2) == min - 1 ){
				min--;
				printf("dabbe 3 -> dabbe 1\n%d %d %d\n",a ,y ,z - (a - x));
				g(a , y , z - (a - x) , m + 1 , 2);
			}
		}
		else{
			if (f(x + z , y , 0 , 0 , 2) == min - 1){
				min--;
				printf("dabbe 3 -> dabbe 1\n%d %d %d\n",x + z ,y ,0);
				g(x + z , y , 0 , m + 1 , 2);
			}
		}
//		return 0;
		
	}
	if ( ( z > 0 ) && (y < b) && (arranger != 3) ){
//		arranger = 3;
		minm = 1000;
		if (z >= (b - y)){
			if (f(x , b , z - (b - y) , 0 , 3) == min - 1){
				min--;
				printf("dabbe 3 -> dabbe 2\n%d %d %d\n",x ,b ,z - (b - y));
				g(x , b , z - (b - y) , m + 1 , 3);
			}
		}
		else{
			if (f(x , y + z , 0 , 0 , 3) == min - 1){
				min--;
				printf("dabbe 3 -> dabbe 2\n%d %d %d\n",x ,y + z ,0);
				g(x , y + z , 0 , m + 1 , 3);
			}
		}
		
//		return 0;
	}
	
	
}

int main(){
	scanf("%d %d %d\n",&a ,&b ,&c);
	scanf("%d %d %d",&xf ,&yf ,&zf);
	min = f(xf + yf + zf , 0 , 0 , 0 , 0);
	printf("%d\n",min);
	g(xf + yf + zf , 0 , 0 , 0 , 0);
}
