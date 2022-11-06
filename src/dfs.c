/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"

void DFT (node * root)
{
	// Implement DFS
	// Hint: You can use print_node, print_tree and/or print_stack.
  stack *runstack = malloc(sizeof(stack)); //
  runstack->next = NULL;                   // Initializes runstack with the root of the tree
  runstack->node = root;                   //

  while (!isEmpty(runstack)) // While the runstack is not empty, execute next element on it
  {
    node *T = NULL; // Temporary node-pointer to contain the node being processed.
    T = top(runstack); // Storing the current node
    runstack = pop(runstack); // Deleting the node from the runstack
    printf("%d", T->num); // print node
    if (T->rchild != NULL)                  // If there is a right child, add it to the runstack
      runstack = push(runstack, T->rchild); //
    if (T->lchild != NULL)                    // If there is a left child, add it to the runstack
      runstack = push(runstack, T->lchild);   //
      free_node(T); // Garbage collect
    if (!isEmpty(runstack)) //
      printf(", ");         // If there is more nodes, we need to put a "," because we will print another number.
  }
}

node *make_node (int num, node * left, node * right)
{
  node *newNode = malloc(sizeof(node)); // Create a node
  newNode->num = num; // Initialize its value
  newNode->lchild = left; // Initialize left child
  newNode->rchild = right; // Initialize right child
  newNode->visited = false; // Initialize visited state
	return newNode; 
}

void free_node (node * p)
{
	free(p); // garbage collet node
}


void print_node (node * p)
{
  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

stack *push (stack * topp, node * node)
{
  stack *newElement = malloc(sizeof(stack)); // Create the new stack-element
  newElement->node = node; // Initialize new stack with the given node
  newElement->next = topp; // Put it on top of the stack
  topp = newElement; // make the stack pointer point to the top of the stack yet again.
	return topp;
}

bool isEmpty (stack * topp)
{
  if (topp == NULL) // If no first element, it is empty
    return true;
  return false;
}

node *top (stack * topp)
{
  return topp->node; // The first element of the stack will be the top, and it's node, will be the top node.
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack * topp)
{
  topp = topp->next; // Stack-pointer points to number 2 top element, to make it the new top
	return topp; // return old top element
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
