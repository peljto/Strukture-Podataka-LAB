#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct stablo;
typedef struct stablo Cvor;
typedef struct stablo* Pozicija;
typedef struct stablo* Pozicija;

struct stablo {
	int el;
	Pozicija L;
	Pozicija D;
};

Pozicija Trazi(int,Pozicija);
Pozicija Brisi(int, Pozicija);
Pozicija TraziMin(Pozicija);
Pozicija Dodaj(int, Pozicija);
Pozicija Ispis(Pozicija);

int main()
{
	Pozicija cvor = NULL;
	Pozicija x = NULL;
	int a, cl;

	do {
		
		printf("\n\n 1.Dodaj novi element\n");
		printf("2.Ispis stabla\n");
		printf("3.Trazi elemente stabla\n");
		printf("4.Brisi elemente stabla\n");
		printf("0.Kraj");

		printf("\nUnesi svoj odabir: \n");
		scanf("%d", &a);

		switch (a) {
		case 1:
			printf("\nDodaj novi element: \n");
			scanf("%d", &cl);
			cvor = Dodaj(cl, cvor);
			if (cvor == NULL)
				printf("Greska!\n");
			break;
		case 2:
			x = Ispis(cvor);
			if (x == NULL)
				printf("Stablo je prazno!\n");
			break;
		case 3:
			printf("\nTrazi elemente stabla\n");
			scanf("%d", &cl);
			x = Trazi(cl, cvor);
			if (x == NULL)
				printf("Element ne postoji\n");
			else
				printf("Element %d je pronaðen\n", x->el);
			break;
		case 4:
			printf("\nOdaberite element koji zelite izbrisati: \n");
			scanf("%d", &cl);
			cvor = Brisi(cl, cvor);
			if (cvor == NULL)
				printf("ERROR\n");
			break;
		case 0:
			printf("\nKraj!!\n");
			break;
		default:
			printf("\nPogrešan unos, pokušajte ponovno!\n");

		}

	} while (a != 0);

}

Pozicija Trazi(int x, Pozicija p) {

	if (NULL == p)
		return NULL;
	else if (x < p->el)
		return Trazi(x, p->L);
	else if (x > p->el)
		return Trazi(x, p->D);
	else
		return p;
}

Pozicija Brisi(int X, Pozicija p) {

	Pozicija temp=NULL;

	if (NULL == p)
		printf("Nema ga!");
	if (X < p->el)
		p->L = Brisi(X, p->L);
	if (X > p->el)
		p->D = Brisi(X, p->D);
	if (p->L != NULL && p->D != NULL) {
		temp = TraziMin(p->D);
		p->el = temp->el;
		p->D = Brisi(p->el, p->D);
	}
	else {
		temp = p;
		if (NULL == p->L)
			p = p->D;
		else
			p = p->L;
		free(temp);
	}
	return p;
}

Pozicija TRaziMin(Pozicija p){

	if (NULL == p)
		return NULL;
	if (NULL == p->L)
		return p;
	else
		return TraziMin(p->L);
}

Pozicija Dodaj(int X, Pozicija p) {

	if (NULL == p) {
		p = (Pozicija)malloc(sizeof(struct stablo));
		p->el = X;
		p->L = NULL;
		p->D = NULL;
	}
	else if (X < p->el)
		p->L = Dodaj(X, p->L);
	else if (X > p->el)
		p->D = Dodaj(X, p->D);
	else
		printf("\nElement vec postoji");
	return p;
}

Pozicija Ispis(Pozicija p) {

	if (p == NULL)
		return p;

	Ispis(p->L);
	printf("%d", p->el);
	Ispis(p->L);
	return p;
}

