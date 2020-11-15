 #include<stdio.h>
 
/* 
Author: Ashkan Soleymani
*/

int x = 0,y = 0;

void pathfinder (void){
	 char move = ' ';
	static int a = 0, b = 0;
	scanf("%c",&move);
	if (move != 'S') pathfinder();
	switch(move){
 		case 'U':
			printf(" -> (%d, %d)",x ,++y);
 			break; 		
		case 'D':
 			printf(" -> (%d, %d)",x ,--y);
 			break;
 		case 'R':
			printf(" -> (%d, %d)",++x ,y);
 			break;
 		case 'L':
 			printf(" -> (%d, %d)",--x ,y);
 			break;
 	}
}
int main(){
	scanf("%d %d",&x ,&y);
	printf("(%d, %d)",x ,y);
	pathfinder();
	
}
