  #include<stdio.h>
  #include <math.h>
     
    int main (void)
    {
        int a=0 , z=0 , c=0 , f=0 , m=0 , b=0 , i =0 , o = 1;
        scanf("%d",&a);
        o = a;
        while(b != a)
        {
            z++;
            c = (z * ( z + 1 ))/2;
            for (i = 1; i * i < c ; i++)
            {
                if( ( c % i ) == 0)
                {
                    m++;
                }
            }
            m*=2;
            if( i * i == c ){
                m++;
            }
            if( m >= a )
            {
                b = a;
            }
            m = 0;
        }
        printf("%d\n",c);
        
        for( i=2 ; i<= c; i++)
            {
        
        while( (c% i)==0)
        {
            printf("%d ",i);
            c = c/i;
        }
        
        }
}
