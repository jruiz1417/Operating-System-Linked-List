#include <stdio.h>

#include "list.h"


int main() {
  
  elem val;
  
  printf("Tests for linked list implementation\n");
  
  list_t *mylist = list_alloc ();
  
  list_print(mylist);
  
  printf("Inserting to front: 5\n");
  list_add_to_front(mylist, 5); 
   printf("Inserting to front: 10\n");
  list_add_to_front(mylist, 10); 
   printf("Inserting to front: 20\n");
  list_add_to_front(mylist, 20); 
 
  printf("Inserting to front: 30\n");
  list_add_to_back(mylist, 30);
  printf("Inserting to front: 35\n");
  list_add_to_back(mylist, 35);
  printf("Inserting to front: 40\n");
  list_add_to_front(mylist, 40); 
  printf("Inserting to front: 50\n");
  list_add_to_back(mylist, 50);
  printf("Insert '15' at Index:3 \n");
  list_add_at_index(mylist,15,3);
  printf("The length of the list is : %d\n",list_length(mylist));
  
  list_print(mylist);
  
  printf("\n");
  
  val = list_remove_from_back(mylist);
  printf("Removing from back: %d\n", val);
  
  val = list_remove_from_front(mylist);
  printf("Removing from front: %d\n", val);

  val = list_remove_at_index(mylist,35);
  printf("Removing at '%d' Index: 2 \n", val);
  
  printf("Add at end of list: 60 \n");
  list_add_to_back(mylist, 60);
  
  printf("Add to beginning of list: 1\n");
  list_add_to_front(mylist, 1);
  
  printf("Is 101 in our linked list?: %d\n", list_is_in(mylist, 101));
  printf("Is 40 in our linked list?: %d\n", list_is_in(mylist, 40));
  printf("Element in Index 4 is: %d\n", list_get_elem_at(mylist, 4));
  printf("Number 60 is stored in Index: %d\n", list_get_index_of(mylist, 60)); 

  list_print(mylist);
  
  return 0;
}
