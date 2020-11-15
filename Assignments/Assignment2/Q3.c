    #include<stdio.h>
    /*
    Author : Ashkan Soleymani
    */
    int main(void){
        char type = ' ';
        int degree = 0, period = 0, turn =0, a = 0 , hour = 0, minute = 0, starttime = 0;
        int kt = 0,ct = 0 , restfindtime = 0,lunchfindtime = 0, endfindtime = 0, nextturn = 0;
        while(scanf(" %c %d",&type ,&degree) != EOF){
        	if( type == 'k'){
                kt = 40 + (degree - 1) * 4;
                restfindtime += kt;
                period = kt;
                lunchfindtime += kt; 
                endfindtime += kt;
            }
            else if( type == 'c'){
                ct = 10 + (degree - 1) * 3;
                restfindtime += ct;
                period = ct;
                lunchfindtime += ct;
                endfindtime += ct;
            }
            kt = 0;
            ct = 0;
            if  ( (lunchfindtime > 390)  && (a != 0) ){
                a = 1;
                restfindtime = period;
                endfindtime += 45;
                starttime += 45;
                lunchfindtime = 0;
            }
            if ((lunchfindtime - period > 300) && (a==0) && (restfindtime > 90) ){
                a = 1;
                restfindtime = period;
                endfindtime += 45;
                starttime += 45;
                lunchfindtime = 0;
            }
            if (restfindtime >  90){
                restfindtime = period;
                lunchfindtime += 10;
                starttime += 10;
                endfindtime += 10;
            }
            
            if ( endfindtime - period >= 570){
                printf("please try tomorrow\n");
                continue;
            }
            hour = 7 + starttime / 60;
            minute = starttime % 60; 
            printf("%.2d:%.2d\n",hour,minute);
    //        printf("starttime = %d. restfindtime = %d. lunchfindtime = %d. endfindtime = %d. period = %d",starttime ,restfindtime ,lunchfindtime , endfindtime , period);
            starttime += period;
        }
    }

