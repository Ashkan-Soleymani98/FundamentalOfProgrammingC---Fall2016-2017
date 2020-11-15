        #include<stdio.h>
         
        /* 
        Author: Ashkan Soleymani
        */
        
        int w = 0; 
        int n;
        int array[1000][2];
         
        int f(char a){
            int i;
            if (('0' <= a ) && (a <= '9')){
                return a - 48;
            }
            else{
                int to = 0;
                for(i = 3 * n - 1 ; i >= 0 ; i--){
                    if ( array[i][0] == a){
                        to =  array[i][1];
                        return to;
                    }
                }
                w = 1;
                return to;
            }
        }
         
         
        int main(){
            int arranger;
            int i , j = 0;
            char a , b , c ; 
            scanf("%d",&n);
            for(i = 0 ; i < n + j ;){
                scanf("\n%d",&arranger);
                switch(arranger){
                    case 1:
                        scanf("\nconfluence %c[%c,%c]",&a ,&b ,&c);
                            array[i][1] = f(b) + f(c);
                            array[i][0] = a;
                            i++;     
                            if(w == 1) return 0;
                            break;
                    case 2:
                        scanf("\nbifurcation [%c,%c]%c",&a ,&b ,&c);    
                            j++;
                            array[i][1] = f(c);
                            array[i][0] = a;
                            i++;
                            array[i][1] = f(c);
                            array[i][0] = b;
                            i++;
                            if(w == 1) return 0;
                            break;
                }
                arranger = 0;
            }
            printf("%d",f('z'));
        }
