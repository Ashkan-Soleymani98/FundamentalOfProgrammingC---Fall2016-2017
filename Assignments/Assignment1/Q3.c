#include<stdio.h>
int main(void)
{	
	int x , z , y ;
	scanf("%d" ,&x);
	z =  ( x >> 1 ) + ( x & 1) * 128;
	printf("%x", z);
}

