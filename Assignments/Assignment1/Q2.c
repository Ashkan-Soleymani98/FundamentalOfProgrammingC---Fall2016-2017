#include<stdio.h>
int main(void)
{
	int x , y , z ;
	int a ;
	scanf("Mr.Bit's answer is %d.\nMr.Bit's friend's answer is %d.", &x, &y);
	z = ( x ^ y );
	a = (( z & 8 )>> 3) +( ( z & 4) >> 2 )+ ((z & 2 )>> 1 )+ ( z & 1  );
	printf("There are %d bit difference(s) between these numbers.", a);
}

