#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct lista* Stog;
typedef struct Cvor* Red;

struct Cvor {
	int el;
	Red Next;
};

struct lista {
	int el;
	Stog Next;
};

void push(int, Stog);
void pop(Stog);

void StaviURed(int, Red);
void SkiniIzReda(Red);

void IspisS(Stog);
void IspisR(Red);


int main()
{
	struct lista head;
	struct Cvor Head;
	head.Next = NULL;
	Head.Next = NULL;

	int x, i;
	int n = 10;

	for (i = 0; i < n; i++)
		push(rand() % 100 + 10, &head);

	for (i = 0; i < n; i++)
		StaviURed(rand() % 100 + 10, &head);

	printf("Stog: ");
	IspisS(head.Next);
	printf("\r\nStog: ");
	pop(&head);
	IspisS(head.Next);

	printf("\n");

	printf("Red: ");
	IspisR(head.Next);
	printf("\r\nRed: ");
	SkiniIzReda(&head);
	IspisR(head.Next);

	return 0;
}

void push(int x, Stog S) {

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
		printf("%d ", S->el);
		S = S->Next;
	}
}
void StaviURed(int x, Red R) {
	Red q;
	q = (Red)malloc(sizeof(struct Cvor));
	q->el=x;
	while (R->Next != NULL)
		R = R->Next;
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

	while (R != NULL) {
		printf("%d ", R->el);
		R = R->Next;
	}
}
