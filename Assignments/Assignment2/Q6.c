#include<stdio.h>

int main (void){
	int P;
	scanf("%d",&P);
	int a, b, c, d;
	int i = 0, p = 0;
	for ( a = 1 ; a <= P ; a++){
		for (b = 1; b <= a ; b++){
			for (c = 1; c <= b ; c++){
				for (d = 1; d <= c; d++){
					p = a + b + c + d;
					if ((p == P) && (a < b + c + d)){
						i++;
					}
				}
			}
		}
	}
	printf("%d",i);
}
