#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node{
	long long int id;
	long long int num;
	long long int debt;
	long long int paid;
	long long int rep;
	char fname[160];
	char lname[160];
}node;

int compare(const void *a, const void *b) 
{ 
    node *ia = (node *)a;
    node *ib = (node *)b;
    if(ia->debt - ib->debt != 0){
    	return ia->debt - ib->debt;
	}
    if(ib->rep - ia->rep != 0){
    	return ib->rep - ia->rep;
    }
    return ia->id - ib->id;
} 

int main(){
	long long int n;
	scanf("%lld",&n);
	long long int i;
	char com[100], fname[160] , lname[160];
	long long int a , b , c;
	node *arr = (node*)calloc(100000 , sizeof(node));
	long long int id = 0;
	for(i = 0 ; i < n ; i++){
		scanf("%s",com);
		
		if(strcmp(com , "register") == 0){
			scanf("%s",arr[id].fname);
			scanf("%s",arr[id].lname);
			arr[id].id = id;
//			strcpy(arr[id].fname , fname);
//			strcpy(arr[id].lname , lname);
			arr[id].debt = 0;
			arr[id].paid = 0;
			arr[id].rep = 0;
			id++;	
			continue;		   
		}
		
		if(strcmp(com , "came") == 0){
			scanf("%lld %lld %lld",&a ,&b ,&c);
//			if(a <= id){
				arr[a].debt += b - c;
				arr[a].paid += c;
				arr[a].rep++;
//			}
			continue;
		}
		
	}
	qsort(arr, id , sizeof(node), compare);
	for(i = 0 ; i < id ; i++){
		if(i > 50){
			printf("%s %s 0\n", arr[i].fname ,arr[i].lname);
		}
		else{
			printf("%s %s %lld\n", arr[i].fname ,arr[i].lname , arr[i].paid / (long long)pow(2 , i + 1) );
		}
	}
}
