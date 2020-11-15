#include<stdio.h>
#include<math.h>
int main(void)
{
	int x;
	int a,b,c;
	scanf("%d",&a);
	b = a >> 1;
	c = a - ( b * 2 );
	x = x + c;
	a = a * c;
	b = b * c;
	a = (b >> 1);
	c = b - ( a * 2);
	x = x + c;
	a = a * c;
	b = b * c;
	b = (a >> 1);
	c = a - ( b * 2 );
	x = x + c;
	a = a * c;
	b = b * c;
	a = (b >> 1);
	c = b - ( a * 2 );
	x = x + c;
	a = a * c;
	b = b * c;
	b = (a >> 1);
	c = a - ( b * 2 );
	x = x + c;
	a = a * c;
	b = b * c;
	a = (b >> 1);
	c = b - ( a * 2 );
	x = x + c;
	a = a * c;
	b = b * c;
	b = (a >> 1);
	c = a - ( b * 2 );
	x = x + c;
	a = a * c;
	b = b * c;
	int z = pow( 2 , x);
	printf("%d",z);
}
