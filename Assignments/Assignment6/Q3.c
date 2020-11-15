#include<stdio.h>
#include<string.h>

/*
Author : Ashkan Soleymani
*/

int min(int a, int b){
	if(a > b) return b;
	else return a;
}

int zero(char a[]){
	int i;
	int n = strlen(a);
	for(i = 0 ; i < n ; i++){
		a[i] = '\0';
	}
}

int main(){
	char f1[100];
	char str1[100];
	char str2[100];
	char aux1[100];
	char aux2[100];
	gets(str1);
	gets(str2);
	int i = 0 , a = 0 ,  j = 0 , k = 0 , p = 0 , arranger = 0;
	int length1 = strlen(str1);
	int length2 = strlen(str2);
	int length = min(length1 , length2);
	for(i = length ; i > 0 ; i--){
		for( j = 0 ; j <= length1 - i; j++){
			strncpy(aux1 , str1 + j, i);
			for ( k = 0 ; k <= length2 - i ; k++){
				strncpy(aux2 , str2 + k , i);
				if(strcmp(aux1, aux2) == 0){
					arranger = 1;
					if(a == 0){
						strcpy(f1, aux1);
						a = 1;
					}
					else if(a == 1){
						if(strcmp(aux1, f1) < 0){
							strcpy(f1, aux1);
						}
					}
				}
				zero(aux2);
			}
			zero(aux1);
		}
		if (arranger == 1){
			printf("%s",f1);
			return 0;
		}
	}
}
