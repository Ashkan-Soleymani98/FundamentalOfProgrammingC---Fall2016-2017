#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[1000];
int ptr;
struct ta* head = NULL;

struct ta{
	char name[100];
	struct ta* nex;
	struct ta* bef;
};



int pr(int ptr , struct ta* a){
	int i = 0;
	while(str[ptr] == a->name[i]){
//		printf("& %c %c\n" , str[ptr] , a->name[i]);
		i++;
		ptr++;
		if(a->name[i] == '\0' && (str[ptr] == ' ' || str[ptr] == '\n' || str[ptr] == '\0')) return 1;
	}
	ptr -= i;
	return 0;
}



int main(){
	int n;
	char c;
	int i;
	scanf("%d" , &n);
	scanf("%c" , &c);
	int j;
	for(j = 0;j < n;j++){
		char c;
		scanf("%c" , &c);
		i = 0;
		while(c != '\n'){
			str[i] = c;
			scanf("%c" , &c);
			i++;
		}
		str[i] = '\0';
//		printf("^^ %s\n" , str);
		ptr = 0;
		struct ta* pointer;
		if(head == NULL){
			head = (struct ta*)malloc(sizeof(struct ta));
			int i = 0;
			int x = 0;
			while(!x){
				head->name[i] = str[ptr];
				i++;
				ptr++;
				if(str[ptr] == ' ' || str[ptr] == '\n' || str[ptr] == '\0') x = 1;
			}
			head->name[i] = '\0';
		}else{
			pointer = head;
			while(pointer->nex != NULL){
				pointer = pointer-> nex;
			}
			pointer->nex = (struct ta*)malloc(sizeof(struct ta));
			pointer->nex->bef = pointer;
			pointer->nex->nex = NULL;
			int i = 0;
			int x = 0;
			while(!x){
				pointer->nex->name[i] = str[ptr];
				i++;
				ptr++;
				if(1 && (str[ptr] == ' ' || str[ptr] == '\n' || str[ptr] == '\0')) x = 1;
			}
			pointer->nex->name[i] = '\0';
		}
	}
	while(1){
		char c;
		scanf("%c" , &c);
		i = 0;
		while(c != '\n'){
			str[i] = c;
			scanf("%c" , &c);
			i++;
		}
		str[i] = '\0';
		if(str[0] == 'e') break;
//		printf("^ %s\n" , str);
		ptr = 0;
		struct ta* pointer , *pointer2 , *pointer3 , *a , *b  ,*p1 , *p2;
		switch(str[ptr]){
			case 'a':
				if(str[ptr + 1] == 'd'){
					ptr += 4;
					if(head == NULL){
						head = (struct ta*)malloc(sizeof(struct ta));
						int i = 0;
						int x = 0;
						while(!x){
							head->name[i] = str[ptr];
							i++;
							ptr++;
							if(1 && (str[ptr] == ' ' || str[ptr] == '\n' || str[ptr] == '\0')) x = 1;
						}
						head->name[i] = '\0';
					}else{
						pointer = head;
						while(pointer->nex != NULL){
							pointer = pointer-> nex;
						}
						pointer->nex = (struct ta*)malloc(sizeof(struct ta));
						pointer->nex->bef = pointer;
						pointer->nex->nex = NULL;
						int i = 0;
						int x = 0;
						while(!x){
							pointer->nex->name[i] = str[ptr];
							i++;
							ptr++;
							if(1 && (str[ptr] == ' ' || str[ptr] == '\n' || str[ptr] == '\0')) x = 1;
						}
						pointer->nex->name[i] = '\0';
					}
				}else if(str[ptr + 1] == 'f'){
					ptr += 6;
					pointer = head;
					while(pointer != NULL){
//						printf("! %s\n" , pointer->name);
						if(pr(ptr , pointer)){
//							printf("!3\n");
							if(pointer->nex==NULL){
								printf("%s is the last TA.\n" , pointer->name);
							}else{
								printf("%s\n" , pointer->nex->name);
							}
						}
						pointer = pointer->nex;
					}
				}
				break;
			case 'd':
				ptr += 6;
				pointer = head;
				while(pointer != NULL){
					if(pr(ptr , pointer)){
						if(pointer == head){
							head = pointer->nex;
							if(head != NULL)
								head->bef = NULL;
						}else{
							pointer->bef->nex = pointer->nex;
							if(pointer->nex != NULL){
								pointer->nex->bef = pointer->bef;
							}
						}
					}
					pointer = pointer->nex;
				}
				break;
			case 'b':
				ptr += 7;
				pointer = head;
				while(pointer != NULL){
					if(pr(ptr , pointer)){
						if(pointer->bef==NULL){
							printf("%s is the first TA.\n" , pointer->name);
						}else{
							printf("%s\n" , pointer->bef->name);
						}
					}
					pointer = pointer->nex;
				}
				break;
			case 'w':
				pointer = head;
				while(pointer != NULL){
					printf("%s\n" , pointer->name);
					pointer = pointer->nex;
				}
				break;
			case 'r':
				ptr += 8;
				pointer = head;
				while(pointer != NULL){
//					printf("* %s\n" , pointer->name);
					if(pr(ptr , pointer)){
//						printf("!3");
						a = pointer;
					}
					pointer = pointer->nex;
				}
				while(str[ptr]!=' ') ptr++;
				ptr++;
				pointer = head;
				while(pointer != NULL){
//					printf("* %s\n" , pointer->name);
					if(pr(ptr , pointer)){
//						printf("!3");
						b = pointer;
					}
					pointer = pointer->nex;
				}
				pointer = a;
				pointer2 = a->nex;
				pointer3;
				p1 = a->bef;
				p2 = b->nex;
//				printf("* %s %s\n" , a->name , b->name);
				while(pointer!=b){
					pointer3 = pointer2->nex;
					pointer2->nex = pointer;
					pointer->bef = pointer2;
					pointer = pointer2;
					pointer2 = pointer3;
				}
				a->nex = p2;
				b->bef = p1;
				if(p1 != NULL) p1->nex = b;
				if(p2 != NULL) p2->bef = a;
				if(head == a){
					head = b;
				}
				break;
				
		}

	}
//	printf("!3\n");
	return 0;
}
