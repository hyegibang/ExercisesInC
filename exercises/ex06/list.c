/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
  Node *n;
  n = *list; // gets first element of the list

  if (n == NULL) {
      return -1;
  }

  //original head value
  int prevhead = n->val;
  *list = n->next; //moving head to the next element
  free(n); // removes previous head
  return prevhead;
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
  Node *n;
  n = make_node(val, *list); // point to current head
  *list = n; // make added node a new head
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {
    Node *current = *list;
    Node *prev = current;

    while(current != NULL) {
        // when we find a match
        if (current->val == val) {

            // if the found list is the first node
            if(prev->next == NULL) {
                *list = current->next; // move head
            }
            else {
                prev->next = current->next;
            }
            free(current);
            return 1;

        } else { // if the values doesn't match,
            prev = current;
            current = current->next;
        }
    }
    // no values exist in the list
    return 0;
}


/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
   Node *new = *list;
   Node *p;
   Node *curr;

   while (new != NULL) {
       curr = new;
       new = new->next; 
       curr->next = p;
       p = curr;
   }

   // sets head to the original last element
   *list = curr;
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
