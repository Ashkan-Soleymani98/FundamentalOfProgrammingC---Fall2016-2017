#include<stdio.h>

/*
Author : Ashkan Soleymani
*/

int m , n;
int place[12][12];

int pathfinder(int x ,int y){
	if ((x == 0) && (y == m)) return place[x][y];
	if ((x < 0) || (y > m) || (x > n) || (y < 0) ) return -111111;
	int a = pathfinder (x - 1 , y);
	int b = pathfinder (x , y + 1);
	if( a >= b ) {
		if(b > 0) return place[x][y] + b;
		else if  (a > 0 ) return place[x][y] + a;
		else return -111111;
	}
	else{
		if(a > 0) return place[x][y] + a;
		else if  (b > 0 ) return place[x][y] + b;
		else return -111111;
	}
}

int main(){
	int i , j;
	scanf("%d %d",&n ,&m);
	for(i = 0 ; i <= n ; i++){
		for(j = 0 ; j <= m ; j++){
			scanf("%d",&place[i][j]);
		}
	}
	printf("%d",pathfinder(n , 0));
}


