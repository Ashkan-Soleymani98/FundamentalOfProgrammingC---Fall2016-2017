#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
Author: Ashkan Soleymani
*/

int max(int a , int b){
	return a > b ? a : b;
}

int main(){
	int m = 0, n = 0;
	scanf("%d %d",&m ,&n);
	int towel[1000];
	int *tec[1000];
	char command[100];
	int towelnum = 0;
	int drydegree = 0;
	int i = 0;
	int tecnum;
	for(i = 0 ; i < 1000 ; i++){
		tec[i] = 0;
		towel[i] = 0;
	}
	while(2){
		tecnum = 0;
		drydegree = 0;
		scanf("%d",&tecnum);
		if(tecnum == 0){
			break;
		}
//		tecnum = command[0] - 48;
		scanf("%s",command);
		if(strcmp(command , "track") == 0){
			scanf("%d",&towelnum);
			tec[tecnum - 1] = &towel[towelnum - 1];
			continue;
		}
		
		
		
		if(strcmp(command , "dry") == 0){
			scanf("%d",&drydegree);
			if(tec[tecnum - 1] == 0){
				printf("no towel has been assigned to me.\n");
				continue;
			}
			if( drydegree >= 0){
				if(*tec[tecnum - 1] >= drydegree){
					*tec[tecnum - 1] -= drydegree;
				}
				else{
					*tec[tecnum - 1] = 0;
				}
			}
			continue;
		}
		
		if(strcmp(command , "give") == 0){
			if(tec[tecnum - 1] == 0){
				printf("no towel has been assigned to me.\n");
				continue;
			}
			if(*tec[tecnum - 1] == 0){
				printf("ok\n");
				*tec[tecnum - 1] = 10;
			}
			else{
				printf("impossible\n");
			}
			continue;
		}
		
		if(strcmp(command , "output") == 0){
			if(tec[tecnum - 1] == 0){
				printf("no towel has been assigned to me.\n");
				continue;
			}
			printf("%d\n",*tec[tecnum - 1]);
			continue;
		}
	}
}
