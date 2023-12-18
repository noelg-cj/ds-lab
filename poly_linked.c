#include <stdio.h>
#include <stdlib.h>

typedef struct node { 
	int coeff; 
	int pow; 
	struct node* next; 
} node; 


void create_node(int x, int y, node** temp) 
{ 
	node *r, *z; 
	z = *temp; 
	if (z == NULL) { 
		r = (node*)malloc(sizeof(node)); 
		r->coeff = x; 
		r->pow = y; 
		*temp = r; 
		r->next = (node*)malloc(sizeof(node)); 
		r = r->next; 
		r->next = NULL; 
	} 
	else { 
		r->coeff = x; 
		r->pow = y; 
		r->next = (node*)malloc(sizeof(node)); 
		r = r->next; 
		r->next = NULL; 
	} 
} 

node* addnode(node* start, int coeff, int power) 
{ 
    node* newnode = (node*)malloc(sizeof(node)); 
    newnode->coeff = coeff; 
    newnode->pow = power; 
    newnode->next = NULL; 
  
    if (start == NULL) 
        return newnode; 
  
    node* ptr = start; 
    while (ptr->next != NULL) 
        ptr = ptr->next; 
    ptr->next = newnode; 
  
    return start; 
}

void removeDuplicates(node* start) 
{ 
    node *ptr1, *ptr2, *dup; 
    ptr1 = start; 
  
    while (ptr1 != NULL && ptr1->next != NULL) { 
        ptr2 = ptr1; 

        while (ptr2->next != NULL) { 
            if (ptr1->pow == ptr2->next->pow) { 
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff; 
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
  
                free(dup); 
            } 
            else
                ptr2 = ptr2->next; 
        } 
        ptr1 = ptr1->next; 
    } 
}

node* multiply(node* poly1, node* poly2, node* poly3) 
{ 
    node *ptr1, *ptr2; 
    ptr1 = poly1; 
    ptr2 = poly2; 
    while (ptr1 != NULL) { 
        while (ptr2 != NULL) { 
            int coeff, power; 
            coeff = ptr1->coeff * ptr2->coeff; 
            power = ptr1->pow + ptr2->pow; 
            poly3 = addnode(poly3, coeff, power); 
            ptr2 = ptr2->next; 
        } 
        ptr2 = poly2; 
  
        ptr1 = ptr1->next; 
    } 
    removeDuplicates(poly3); 
    return poly3; 
}

void polyadd(node* poly1, node* poly2, node* poly) 
{ 
	while (poly1->next && poly2->next) {
		if (poly1->pow > poly2->pow) { 
			poly->pow = poly1->pow; 
			poly->coeff = poly1->coeff; 
			poly1 = poly1->next; 
		} 

		else if (poly1->pow < poly2->pow) { 
			poly->pow = poly2->pow; 
			poly->coeff = poly2->coeff; 
			poly2 = poly2->next; 
		} 

		else { 
			poly->pow = poly1->pow; 
			poly->coeff = poly1->coeff + poly2->coeff; 
			poly1 = poly1->next; 
			poly2 = poly2->next; 
		} 

		poly->next = (node*)malloc(sizeof(node)); 
		poly = poly->next; 
		poly->next = NULL; 
	} 

	while (poly1->next || poly2->next) { 
		if (poly1->next) { 
			poly->pow = poly1->pow; 
			poly->coeff = poly1->coeff; 
			poly1 = poly1->next; 
		} 
		if (poly2->next) { 
			poly->pow = poly2->pow; 
			poly->coeff = poly2->coeff; 
			poly2 = poly2->next; 
		} 
		poly->next = (node*)malloc(sizeof(node)); 
		poly = poly->next; 
		poly->next = NULL; 
	} 
} 


void display(node* n) 
{ 
	while (n->next != NULL) { 
		printf("%dx^%d", n->coeff, n->pow); 
		n = n->next; 
		if (n->coeff >= 0) { 
			if (n->next != NULL) 
				printf("+"); 
		} 
	} 
} 


int main(void) 
{ 
    int op, n1, n2, coeff, exp, flag = 0;
    node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

    while(1) {
        printf("1. Polynomial addition\n2. Polynomial multiplication\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch(op) {
            case 1: 
                printf("Enter the number of terms in first polynomial: ");
                scanf("%d", &n1);
                for (int i = 0; i < n1; i++) {
                    printf("Coefficient: ");
                    scanf("%d", &coeff);
                    printf("Exponent: ");
                    scanf("%d", &exp);
                    create_node(coeff, exp, &poly1);
                }

                printf("Enter the number of terms in second polynomial: ");
                scanf("%d", &n2);
                for (int i = 0; i < n2; i++) {
                    printf("Coefficient: ");
                    scanf("%d", &coeff);
                    printf("Exponent: ");
                    scanf("%d", &exp);
                    create_node(coeff, exp, &poly2);
                }

                printf("\nFirst polynomial: ");
                display(poly1);

                printf("\nSecond polynomial: ");
                display(poly2);

                poly = (node*)malloc(sizeof(node));

                polyadd(poly1, poly2, poly);

                printf("\nResultant polynomial: ");
                display(poly);
                break;

            case 2: 
                printf("Enter the number of terms in first polynomial: ");
                scanf("%d", &n1);
                for (int i = 0; i < n1; i++) {
                    printf("Coefficient: ");
                    scanf("%d", &coeff);
                    printf("Exponent: ");
                    scanf("%d", &exp);
                    poly1 = addnode(poly1, coeff, exp);
                }

                printf("Enter the number of terms in second polynomial: ");
                scanf("%d", &n2);
                for (int i = 0; i < n2; i++) {
                    printf("Coefficient: ");
                    scanf("%d", &coeff);
                    printf("Exponent: ");
                    scanf("%d", &exp);
                    poly2 = addnode(poly2, coeff, exp);
                }

                printf("\nFirst polynomial: ");
                display(poly1);

                printf("\nSecond polynomial: ");
                display(poly2);

                poly = multiply(poly1, poly2, poly);

                printf("\nMultiplied polynomial: ");
                display(poly);
                break;

            case 3:
                flag = 1;
            break;
        }

        printf("\n");
        if (flag) break;
    }
	/* node *poly1 = NULL, *poly2 = NULL, *poly = NULL, *poly3 = NULL; 

	create_node(5, 2, &poly1); 
	create_node(4, 1, &poly1); 
	create_node(2, 0, &poly1); 

	create_node(-5, 1, &poly2); 
	create_node(-5, 0, &poly2); 

	printf("1st Number: "); 
	display(poly1); 

	printf("\n2nd Number: "); 
	display(poly2); 

	poly = (node*)malloc(sizeof(node)); 

	polyadd(poly1, poly2, poly); 

	printf("\nAdded polynomial: "); 
	display(poly); 

    printf("\nMultiplied polynomial: ");
    display(poly3);
 */

    /* node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL; 
  
    // Creation of 1st Polynomial: 3x^2 + 5x^1 + 6 
    poly1 = addnode(poly1, 3, 3); 
    poly1 = addnode(poly1, 6, 1); 
    poly1 = addnode(poly1, -9, 0); 
  
    // Creation of 2nd polynomial: 6x^1 + 8 
    poly2 = addnode(poly2, 9, 3); 
    poly2 = addnode(poly2, -8, 2); 
    poly2 = addnode(poly2, 7, 1); 
    poly2 = addnode(poly2, 2, 0); 
  
    // Displaying 1st polynomial 
    printf("First poly: "); 
    display(poly1); 
  
    // Displaying 2nd polynomial 
    printf("Second poly: "); 
    display(poly2); 
  
    // calling multiply function 
    poly3 = multiply(poly1, poly2, poly3); 
  
    // Displaying Resultant Polynomial 
    printf("\nMultiplied: "); 
    display(poly3);  */
	return 0; 
}
