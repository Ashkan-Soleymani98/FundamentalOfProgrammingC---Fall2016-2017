#include<stdio.h>
#include<string.h>

/*
Author : Ashkan Soleymani
*/

int toAsghar(char asghar[]){
	int i;
	for(i = 0 ; i < strlen(asghar) ; i++){
		switch(asghar[i]){
			case 'l':
				asghar[i] = '1';
				break;
			case 'g':
				asghar[i] = '9';
				break;
			case 'r':
				asghar[i] = '7';
				break;
			case 'z':
				asghar[i] = '2';
				break;
		}
	}
	return 0;
}

int toBehrooz(char behrooz[]){
	int i , k ;
	int length = strlen(behrooz);
	
	if(behrooz[0] == 'b') behrooz[0] = '8';
	for( i = 0 ; i < length - 1 ; i++){
		if ( (behrooz[i] == ' ') && (behrooz[i + 1] == 'b') ){
			behrooz[i + 1] = '8';
		}
	}
	
	if( (behrooz[length - 1] == 'e') && (behrooz[length - 2] == 't') && (behrooz[length - 3] == 'a') ){
		behrooz[length - 3] = '8';
		behrooz[length - 2] = '\0';
		length -= 2;
		i -= 2;
	}
	
	for (i = 0 ; i < length ; i++){
		if( (behrooz[i] == 'a') && (behrooz[i + 1] == 't') && (behrooz[i + 2] == 'e') && (behrooz[i + 3] == ' ') ){
			behrooz[i] = '8';
			length -= 2;
			for ( k = i + 1 ; k < length ; k++){
				behrooz[k] = behrooz[k + 2];
			}
			i -= 2;
		}
	}	
	
	for (i = 1 ; i <= length - 2 ; i++){
		if( (behrooz[i - 1] != ' ') && (behrooz[i] == 'o') && (behrooz[i + 1] == 'o') && (behrooz[i + 2] != ' ') ){
			behrooz[i] = '8';
			length--;
			for ( k = i + 1 ; k < length ; k++){
				behrooz[k] = behrooz[k + 1];
			}
		}
	}
	
	behrooz[length] = '\0';
}

int backBehrooz(char behrooz[]){
	char cobehrooz[900];
	strcpy(cobehrooz , behrooz);
	int i , j;
	int length = strlen(behrooz);
	for(i = 0 ; i < length ; i++){
		if( behrooz[i] == '8'){
			if( (behrooz[i - 1] == ' ') || (i == 0) ){
				behrooz[i] = 'b'; 
				strcpy(cobehrooz , behrooz);
			}
			else if( (behrooz[i + 1] == ' ') || (i == (length - 1) ) ){
				behrooz[i] = 'a';
				behrooz[i + 1] = 't';
				behrooz[i + 2] = 'e';
				for (j = i + 1 ; j < length ; j++){
					behrooz[j + 2] = cobehrooz[j]; 
				}
				i -= 2;
				strcpy(cobehrooz , behrooz);
				length += 2;
			}
			else if( (behrooz[i - 1] != ' ') && (behrooz[i + 1] != ' ') && (i != 0 ) && (i != length - 1) ){
				behrooz[i] = 'o';
				behrooz[i + 1] = 'o';
				for ( j = i + 1 ; j < length ; j++){
					behrooz[j + 1] = cobehrooz[j];
				}
				strcpy(cobehrooz , behrooz);
				i -= 1;
				length++;
			}
		}
	}
	behrooz[length] = '\0';
}

int backAsghar(char asghar[]){
	int i;
	for(i = 0 ; i < strlen(asghar) ; i++){
		switch(asghar[i]){
			case '1':
				asghar[i] = 'l';
				break;
			case '9':
				asghar[i] = 'g';
				break;
			case '7':
				asghar[i] = 'r';
				break;
			case '2':
				asghar[i] = 'z';
				break;
		}
	}
	return 0;
}

int main(){
	char str1[900];
	char str2[900];
	gets(str1);
	gets(str2);
	backBehrooz(str1);
	toAsghar(str1);
	printf("%s\n",str1);
	backAsghar(str2);
	toBehrooz(str2);
	printf("%s",str2);
}
