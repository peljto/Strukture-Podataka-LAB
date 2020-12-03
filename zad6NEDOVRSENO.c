#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

void Ispis(Stog);


int main()
{
	struct lista head;
	head.Next = NULL;
	int x, i;
	int n = 10;

	for (i = 0; i < n; i++)
	{
		push(rand() % 100 + 10, &head);
	}
	printf("push\n");
	Ispis(head.Next);
	printf("\n");
	pop(head.Next);
	printf("\npop\n");
	Ispis(&head);

	return 0;
}

void push(int x, Stog S){

	Stog q;
	q = (Stog)malloc(sizeof(struct lista));
	q->Next = S->Next;
	S->Next = q;
	q->el = x;	
}
//int pop(Stog S) {

//	int x;
//	Stog temp;
//	x = S->Next->el;
//	temp = S->Next;
//	S->Next = temp->Next;
//	free(temp);
//	return x;
//}

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

void Ispis(Stog S) {

	while (S != NULL) {
		printf("\n%d", S->el);
		S = S->Next;
	}
}
void StaviURed(int x, Red R) {

	Red q;
	q = (Red)malloc(sizeof(struct Cvor));
	q->Next = R->Next;
	R->Next = q;
	q->el = x;
}



