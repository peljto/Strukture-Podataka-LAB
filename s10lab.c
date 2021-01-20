#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stablo;
typedef struct stablo* pozicija;

struct stog;
typedef struct stog* polozaj;

struct stablo {
	char el[10];
	pozicija L;
	pozicija D;
};

struct stog {
	pozicija st;
	polozaj next;
};

pozicija stvoriStablo();
polozaj stvoriStog();
int push(polozaj, pozicija);
pozicija pop(polozaj);
int citajDokument(polozaj, pozicija);
int inorder(pozicija);

int main()
{

}

int citajDokument(polozaj p, pozicija s) {
	char* imeDat = NULL, * buffer = NULL;
	FILE* dat = NULL;
	pozicija a = NULL;
	int i = 0;

	imeDat = (char*)malloc(30 * sizeof(char));
	if (imeDat == NULL)
		return-2;

	buffer = (char*)malloc(30 * sizeof(char));
	if (buffer == NULL)
		return -2;

	printf("Upisite ime datoteke: ");
	scanf(" %s", imeDat);

	if (strchr(imeDat, '.') == NULL)
		strcat(imeDat, ".txt");

	dat = fopen(imeDat, "r");
	if (dat == NULL)
		return -3;

	while (!feof(dat)) {
		memset(buffer, 0, 30);

		fscanf(dat, "%s", buffer);

		if (isdigit(buffer[0])) {
			a = stvoriStablo();
			if (a == NULL)
				return -1;

			strcpy(a->el, buffer);
			i = push(p, a);

			if (i != 0)
				return -5;
		}
		else if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/') {
			a = stvoriStablo();
			if (a == NULL)
				return -1;

			strcpy(a->el, buffer);
			a->D = pop(p);
			a->L = pop(p);

			i = push(p, a);
		}
		else
			continue;
	}
	fclose(dat);
	free(imeDat);
	free(buffer);

	return 0;
}

int inorder(pozicija p) {
	if (p != NULL) {
		inorder(p->L);
		printf(" %s", p->el);
		inorder(p->D);
	}
	return 0;
}

pozicija stvoriStablo() {
	pozicija q = NULL;
	q = (pozicija)malloc(sizeof(struct stablo));
	if (q == NULL)
		return q;

	q->L = q->D = NULL;
	
	return q;
}

polozaj stvoriStog() {
	polozaj q = NULL;
	q = (polozaj)malloc(sizeof(struct stog));
	if (q == NULL)
		return q;

	q->next = q->st = NULL;

	return q;
}

int push(polozaj p, pozicija s) {
	if (p == NULL || s == NULL)
		return -6;

	polozaj q = NULL;
	q = StvoriStog();
	if (q == NULL)
		return -2;

	q->st = s;

	q->next = p->next;
	p->next = q;

	return 0;
}

pozicija pop(polozaj p) {
	if (p = NULL)
		return NULL;

	if (p->next == NULL)
		return NULL;

	polozaj temp = NULL;
	pozicija st = NULL;

	temp = p->next;
	st = temp->st;

	p->next = temp->next;
	free(temp);

	return(st);
}