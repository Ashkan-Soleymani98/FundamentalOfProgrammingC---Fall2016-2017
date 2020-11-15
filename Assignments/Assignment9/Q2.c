#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
	char name[1000];
	struct Node *next, *before;
}node;

int main(){
	int n;
	scanf("%d",&n);
	int i;
	int num = 0;
	char person[1000];
	char com[4];
	node *p = (node*)calloc(1 , sizeof(node)) , *q = NULL;
 	node *head = p;
	node *last = p;
	head->next = NULL;
	last->before = NULL;
	
	for(i = 1 ; i <= n ; i++){
		scanf("%s",person);
		scanf("%s",com);
		
		if(strcmp(com , "in") == 0){
			num++;
			for(p = head ; p != NULL ; p = p->next){
				q = p;
			}
			q->next = (node*)calloc(1 , sizeof(node));
			q->next->before = q;
			q = q->next;
			strcpy(q->name , person);
			last = q;
		}
		
		if(strcmp(com , "out") == 0){
			num--;
			
			if(head == last){
				num++;
				continue;
			}
			
			if(strcmp(person , "first") == 0){
				printf("%s\n",head->next->name);
				head = head->next;
				head->before = NULL;
			}
			
			if(strcmp(person , "last") == 0){
				printf("%s\n",last->name);
				last = last->before;
				last->next = NULL;
			}
			
		}
		
	}
	printf("%d",num);
		
}

