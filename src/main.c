/*extern "C"{
    // Add the header files required to run your main 
}*/
#include "dfs.h"
#include "search.h"
#include "sum.h"
#include <stdio.h>
#include <stdlib.h>

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    int a[4] = {1, 2, 4, 3};
    printf("%d \n", sum(a, 4));

    printf("%d \n", search(a, 4, 1));

    node *start = make_node (4,
			  make_node (7,
				     make_node (28,
						make_node (77,
							   NULL,
							   NULL),
						make_node (23,
							   NULL,
							   NULL)),
				     make_node (86,
						make_node (3,
							   NULL,
							   NULL),
						make_node (9,
							   NULL,
							   NULL))),
			  make_node (98,
				     NULL,
				     NULL));

    DFT(start);

	node *x1 = malloc(sizeof(node));
	node *x2 = malloc(sizeof(node));
	node *x3 = malloc(sizeof(node));

	x1->num = 10;
	x2->num = 32;
	x3->num = 5;

	stack *fisk = malloc(sizeof(stack));
	fisk->next = NULL;
	fisk->node = x1;

	//push(fisk, x1);
	fisk = push(fisk, x2);
	fisk = push(fisk, x3);
	printf("\n");
	print_stack(fisk);
    return 0;
}