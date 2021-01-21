#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct lista* Stog;
typedef struct Cvor* Red;

struct Cvor {
	int el;
	Red Next;
};

struct lista{
	int el;
	Stog Next;
};

void push(int,Stog);
void pop(Stog);

void StaviURed(int, Red);
void SkiniIzReda(Red);

void IspisS(Stog);
void IspisR(Red);


int main()
{
	struct lista head;
	struct Cvor head1;
	head1.Next = NULL;
	head.Next = NULL;
	int i, s, r, stog, red;
	
	printf("\r Koliko ce brojeva sadrzavati stog?");
	scanf("%d", &s);
	
	printf("\r Koliko ce brojeva sadrzavati red?");
	scanf("%d", &r);
	
	for(i = 0; i < s; i++) {
		stog = rand() % 100 +10;
		push(s, &head);
	}
	
	for(i = 0; i < r; i++) {
		red = rand() % 100 +10;
		StaviURed(r, &head1);
	}
	
	printf("Stog: ");
	IspisS(head.Next);
	printf("\r\nStog (nakon pop-a): ");
	pop(&head);
	IspisS(head.Next);
	
	printf("\r\nRed: ");
	IspisR(head1.Next);
	printf("\r\nRed (nakon skidanja elementa iz reda): ");
	SkiniIzReda(head1.Next);
	IspisR(head1.Next);
	
	return 1;
}

void push(int x, Stog S){

	Stog q;
	q = (Stog)malloc(sizeof(struct lista));
	q->Next = S->Next;
	S->Next = q;
	q->el = x;	
}

void pop(Stog S) {
	
	int x;
	Stog temp;
	if (S->Next != NULL)
	{
		x = S->Next->el;
		temp = S->Next;
		S->Next = temp->Next;
		free(temp);
	}
}

void IspisS(Stog S) {

	while (S != NULL) {
		printf("\n%d", S->el);
		S = S->Next;
	}
}

void StaviURed(int x, Red R) {

	Red q;
	q = (Red)malloc(sizeof(struct Cvor));
	q->El = x;
	while(R->Next != NULL){
		R = R->next;
	}
	q->Next = R->Next;
	R->Next = q;	
}

void SkiniIzReda(Red R) {
	Red temp;
	temp = R->Next;
	R->Next = temp->Next;
	free(temp);
}

void IspisR(Red R) {
	while(R != NULL) {
		printf("%d ", R->el);
		R = R->Next;
	}
}



