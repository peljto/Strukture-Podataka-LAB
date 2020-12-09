#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista* pozicija;
struct lista {
	int el;
	pozicija next;
};

void SortUnos(int, pozicija);
void Ispis(pozicija);
int Unija(pozicija, pozicija, pozicija);
int Presjek(pozicija, pozicija, pozicija);

int main()
{
	struct lista L1, L2, unija, presjek;
	L1.next = NULL;
	L2.next = NULL;
	unija.next = NULL;
	presjek.next = NULL;

	SortUnos(2, &L1);
	SortUnos(5, &L1);
	SortUnos(1, &L1);
	SortUnos(6, &L1);
	SortUnos(8, &L1);
	SortUnos(2, &L2);
	SortUnos(5, &L2);
	SortUnos(1, &L2);
	SortUnos(3, &L2);
	SortUnos(6, &L2);

	Ispis(L1.next);
	Ispis(L2.next);
	printf("\n");

	Unija(L1.next, L2.next, &unija);
	Presjek(L1.next, L2.next, &presjek);

	printf("Unija lista: \n");
	Ispis(unija.next);
	printf("\n");

	printf("Presjek lista: \n");
	Ispis(presjek.next);

	return 0;

}

void SortUnos(int x, pozicija p) {
	pozicija q;

	while (p->next != NULL && p->next->el < x)
		p = p->next;
	q = (pozicija)malloc(sizeof(struct lista));
	if (q != NULL) {
		q->el = x;
		q->next = p->next;
		p->next = q;
	}
}

void Ispis(pozicija p) {
	while (p != NULL) {
		printf("%d ", p->el);
		p = p->next;
	}
	printf("\n");
}

int Unija(pozicija a, pozicija b, pozicija unija) {
	
	pozicija q = NULL, p1 = a, p2 = unija;

	if (a == NULL && b == NULL)
		return -1;

	while (a != NULL) {
		pozicija q = NULL;
		q = (pozicija)malloc(sizeof(struct lista));
		
		if (q == NULL)
			return q;

		q->next = NULL;

		if (q == NULL)
			return -1;

		q->el = a->el;

		q->next = unija->next;
		unija->next = q;
		unija = q;

		a = a->next;
	}
	unija = p2;

	while (b != NULL) {
		a = p1;
		
		while (a != NULL && a->el != b->el)
			a = a->next;

		if (a == NULL) {
			pozicija q = NULL;
			q = (pozicija)malloc(sizeof(struct lista));

			if (q == NULL)
				return q;

			q->next = NULL;

			if (q == NULL)
				return -1;

			q->el = b->el;


			while(unija->next!=NULL && unija->next->el<q->el)
				unija = unija->next;
			
			q->next = unija->next;
			unija->next = q;
			unija = p2;
		}
		b = b->next;

	}
	return 0;
}

int Presjek(pozicija a, pozicija b, pozicija presjek) {

	pozicija q = NULL;

	while (a != NULL && b != NULL) {
		if (a->el > b->el)
			b = b->next;
		else if (a->el > b->el)
			a = a->next;
		else {
			pozicija q = NULL;
			q = (pozicija)malloc(sizeof(struct lista));
			
			if (q == NULL)
				return q;

			q->next = NULL;

			if (q == NULL)
				return -1;

			q->el = a->el;
			q->next = presjek->next;
			presjek->next = q;
			presjek = q;

			a = a->next;
			b = b->next;
		}
	}
	return 0;
}