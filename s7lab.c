#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista* Stog;

struct lista {
	int el;
	Stog Next;
};

void push(int,Stog);
int pop(Stog);
int UnosDat(Stog);
void Postfix(Stog, char*, char);

int main()
{
	struct lista head;
	head.Next = NULL;
}

int UnosDat(Stog S) {
	char str[20];
	FILE* dat = NULL;
	Stog q = NULL;

	printf("Unesi ime datoteke: ");
	scanf("%s", str);
	if (strchr(str, '.') == NULL)
		strcat(str, ".txt");

	dat = fopen(str, "r");
	if (dat == NULL)
		return -1;

	while (!feof(dat)) {
		q = (Stog)malloc(sizeof(struct lista));
			if (q == NULL)
				return -1;

		fscanf(dat, " %s", &q->el);

		q->Next = S->Next;
		S->Next = q;
	}
	fclose(dat);
}

void push(int x, Stog S) {

	Stog q;
	q = (Stog)malloc(sizeof(struct lista));
	q->Next = S->Next;
	S->Next = q;
	q->el = x;
}

int pop(Stog S) {

	int x;
	Stog temp;
	if (S->Next != NULL)
	{
		x = S->Next->el;
		temp = S->Next;
		S->Next = temp->Next;
		free(temp);
	}
	return 0;
}
void Postfix(Stog S, char* izraz, char c) {
	
	int a = pop(S);
	int b = pop(S);

	char* t;

	t = strtok(izraz, " ");
	while (t != NULL) {
		if (isdigit(*t))
			push(S, atoi(t));
		else
		{
			switch (c)
			{
			case '+':
				push(S, a + b);
				break;
			case '-':
				push(S, a - b);
				break;
			case '*':
				push(S, a * b);
				break;
			case '/':
				push(S, a / b);
				break;
			}
		}
		t = strtok(NULL, " ");
	}
}
