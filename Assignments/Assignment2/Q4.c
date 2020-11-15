#include<stdio.h>
int main(void){
    unsigned int n,j=0,i = 0, s, x=0;
    scanf("%d", &n);
    if(n<10) s=1;
    else if(n<190) s=2;
    else if(n<2890) s=3;
    else if(n<38890) s=4;
    else if(n<488890) s=5;
    else if(n<5888890) s=6;
    switch(s){
        case 1:
            printf("%d", n);
            break;
        case 2:
            n-=9;
            x=((n - 1)/2) + 1;
            x+=9;
            i=n%2;
            printf("%d", (i==0) ? x%10 : x/10);
            break;
        case 3:
            n-=189;
            x=((n - 1)/3) + 1;
            x+=99;
            i=(n+2)%3+1;
            for(;j<3-i;j++) {
            	x/=10;
            }
            printf("%d",x%10);
            break;
        case 4:
            n-=2889;
            x=((n - 1)/4) + 1;
            x+=999;
            i=(n+3)%4+1;
            for(;j<4-i;j++) {
            	x/=10;
            }
            printf("%d",x%10);
            break;
        case 5:
            n-=38889;
            x=((n - 1)/5) + 1;
            x+=9999;
            i=(n+4)%5+1;
            for(;j<5-i;j++) {
            	x/=10;
            }
            printf("%d",x%10);
			break;
        case 6:
            n-=488889;
            x=((n - 1)/6.) + 1;
            x+=99999;
            i=(n+5)%6+1;
            for(;j<6-i;j++) {
            	x/=10;
            }
            printf("%d",x%10);
			break;
    }

}
