#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Trie{
	char alph;
	int num;
	struct Trie *next , *child , *before;
}trie;



int main(){
	int n;
	scanf("%d",&n);
	int i , j;
	char name[1000];
	trie *p = (trie*)calloc(1 , sizeof(trie)) , *q = NULL;
	p->next = NULL;
	p->alph = 'a';
	p->num = 0;
	p->before = NULL;
//	p->next = NULL;
//	p->child = NULL;
	trie *head = p;
//	trie *arr[10001];
	int arranger = 0 , first = 1;
	
	for(i = 1 ; i <= n; i++){
		scanf("%s",name);
		 
		for(j = 0 ; j < strlen(name) ; j++){
			
			for( ; p != NULL ; p = p->next){
				q = p;
				if( name[j] == p->alph){
					arranger = 1;
					break;
				}
			}
			
			if(arranger == 0){
				p = (trie *)calloc(1 , sizeof(trie));
				p->before = q;
				if(p->before != NULL){
					p->before->next = p;
				}
				p->alph = name[j];
				p->num = 0;
				p->next = NULL;
			}
			
			arranger = 0;
			
			 
			if( j == strlen(name) - 1){
				p->num++;
			}
			
			if(p->child == NULL){
				p->child = (trie *)calloc(1 , sizeof(trie));
				p->child->alph = 'a';
				p->child->num = 0;
				p->child->child = NULL;
			}
			
			p = p->child;
			
		}
		
 		p = head;
		
	}
	
	int m;
	scanf("%d",&m);
	p = head;
	
	for(i = 0 ; i < m ; i++){
		scanf("%s",name);
		
		for(j = 0 ; j < strlen(name); j++){
			
			for( ; p != NULL ; p = p->next){
				if(p->alph == name[j]){
					break;
				}
			}
			
			if( p == NULL){
				printf("0\n");
				break;
			}
			if( j == strlen(name) - 1 && p->alph == name[j]){
				printf("%d\n",p->num);
				break;
			}
			else if( j == strlen(name) - 1){
				printf("0\n");
				break;
			}
			if(p->child != NULL){
				p = p->child;
			}
		}
		
		p = head;
	}
}
