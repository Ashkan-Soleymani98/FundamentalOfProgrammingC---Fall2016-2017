#include<stdio.h>
#include<string.h>

/*
Author : Ashkan Soleymani
*/

int main(){
	int array[28];
	char str[1000];
	int i , alph;
	gets(str);
	for(i = 0 ; i < 27 ; i++){
		array[i] = 0;
	} 
	array[27] = 10000;
	int length = strlen(str);
	for(i = 0 ; i < length ; i++){
		alph = 27;
		if( ('A' <= str[i] ) && ( str[i] <= 'Z')){
			array[str[i] - 'A' + 1]++;
			alph = str[i] - 'A' + 1;
		}
		if( ('a' <= str[i] ) && ( str[i] <= 'z')){
			array[str[i] - 'a' + 1]++;
			alph = str[i] - 'a' + 1;
		}
		if( ( (alph % array[alph]) == 0) || (alph == 27) ){
			printf("%c",str[i]);
		}
	}
}
