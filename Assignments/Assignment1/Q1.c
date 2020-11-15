#include<stdio.h>
int main(void)
{	
	int x , z , y , a , k , q , b , w;
	float l;
	scanf("%d" ,&x);
	z = 255 + 45 * x; 
	y = z % 60;
	a = z / 60;
	l = 3.29 + 0.04 * (x - 1);
	k = y % 10;
	q = y / 10 ;
	b = a % 10;
	w = a / 10;
//	printf("Welcome to my hammaam!\nI wil rub you with kise with degree %d and this will approximately last %d%d:%d%d!\nAt the end you should give me %.2f$.\nHave fun!", x , w , b , q , k , l );
	printf("Welcome to my hammaam!\nI will rub you with kise with degree %d and this will approximately last %d%d:%d%d!\nAt the end you should give me %.2f$.\nHave fun!",x , w , b ,q ,k , l);
}

