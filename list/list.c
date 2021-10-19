// list/list.c
// 
// Implementation for linked list.
//
// <Jose Ruiz>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

/* Functions for allocating and freeing lists. By using only these functions,
 * the user should be able to allocate and free all the memory required for
 * this linked list library. */
list_t *list_alloc() 
{
  list_t* list = (list_t*)malloc(sizeof(list_t));
  list->head = NULL;
  return list;
}
node_t *node_alloc(elem val)
{
  //take a ptrr
  //if(ptr!= NULL) {"error msg"}
  node_t *node = (node_t *) malloc(sizeof(node_t));
  node->value = val;
  node->next = NULL;
  return node;
}
void list_free(list_t *l) 
{
  node_t *tempptr , *currentptr;
  if (l->head != NULL)
    {  
       if (l->head->next != NULL)
         {
            currentptr = l->head;
            while(currentptr !=NULL)
            {
              tempptr = currentptr->next;
              free(currentptr);
              currentptr = tempptr;
            }
         }
       else
         {
           free(l->head);
         }
       l->head = NULL;
    } 
}
void node_free(node_t *n) 
{
  free(n);
}
/* Prints the list in some format. */
void list_print(list_t *l) 
{
  node_t *cur = l->head;
  while (cur != NULL)
  {  
    printf("%d\n",cur->value);
    cur = cur->next;
  }
}
/* Returns the length of the list. */
int list_length(list_t *l) 
{
  node_t *current = l->head;
  int i = 0;
  while (current != NULL) // while we equal a node // while we do no equal null
  {
    i++;
    current = current->next; //points to the next node in the linkedlist
  }
  return i;
}
/* Methods for adding to the list. */
void list_add_to_back(list_t *l, elem value) 
{
  node_t *newnode = node_alloc(value);
  newnode->next = NULL;
  if(l->head == NULL) //if list is empty already
  {
    l->head = newnode;
  }
  else
  {
     node_t *current = l->head;
     while (current->next != NULL)// looping to find current-next value to = null // loops to end of list
      {
        current = current->next;
      }
      current->next = newnode;
  }

}
void list_add_to_front(list_t *l, elem value) 
{
   node_t *newnode;
   newnode = node_alloc(value);
   newnode->next =  l->head; //old head
   l->head = newnode; // the head point to the new node
}
void list_add_at_index(list_t *l, elem value, int index)
{
   int i =0; // counter
   node_t *newnode = node_alloc(value);
   node_t *current = l->head;
 
   if(index==0)
   {
     newnode->next = l->head;
     l-> head= newnode;   // or call add to front list_add_to_front(l,value)
   }
   else
   if (index > 0)
   {
     while(i < (index - 1) && current->next != NULL)
     {
       current = current->next;
       i++; // or call 
     }
     newnode->next = current->next;// linked to old index
     current->next = newnode; // breaks off old connection
   } 
    /*
    if(index > list_length(l))
    {
      list_add_to_back(l,value);
    }
    */
}
/* Methods for removing from the list. Returns the removed element. */
elem list_remove_from_back(list_t *l)
{ 
  elem value = (elem)-1;
  node_t *current = l->head;
  if(l->head != NULL) //if list is empty already
  {
    if(current->next == NULL)// one node in the list
    {
      l->head = NULL;
      value = current->value;
      node_free(current);
    }
    else
    {
      while(current->next->next != NULL)
      {
        current = current->next;
      }
      value = current->next->value;
      node_free(current->next->next);
      current->next = NULL;
    }
  }
  return value;
}
elem list_remove_from_front(list_t *l) 
{ 
  elem value = (elem)-1;
  if (l->head == NULL)
  {
    return value;
  }
  else
  {
    node_t *current = l->head;
    value = current->value; //stored value
    l->head = l->head->next;// remove value from linked list
    node_free(current);
  }
  return value;
}
elem list_remove_at_index(list_t *l, int index) 
{
  int i;
  elem value = (elem)-1;
  bool found = false;
  
  if (l->head == NULL)
    {
      return value;
    }
  else 
  if (index == 0)
    {
      return list_remove_from_front(l);
    }
  else 
  if (index > 0)
  {
    node_t *current = l->head;
    node_t *prev = current;
    i = 0;
    while(current != NULL && !found)
    {
      if(i== index)
        {
          found = true;
        }
      else
      {
        prev = current; // this makes prev lag behind current always will be 1 behind
        current = current->next;
        i++;
      }
    }
    if(found)
    {
     value = current->value;
     prev->next = current->next; //making the new connection
     node_free(current);// released old connection
    }  
    return value;
  } 
}
/* Checks to see if the given element exists in the list. */
bool list_is_in(list_t *l, elem value) 
{
  node_t *tempnode = l->head; 
  while(tempnode != NULL)
  {
    if(value == tempnode->value)
    {
      return true;
    }
    tempnode = tempnode->next;   
  }
  return false;
  
}
/* Returns the element at the given index. */
elem list_get_elem_at(list_t *l, int index) 
{
  int i;
  elem value = (elem)-1;
  if(l->head == NULL)
    {
      return value;
    }
  else 
  if (index == 0)
    {
      node_t *current = l->head;
      value = current->value;
    }
  else
  if(index > 0)
    {
      node_t *current = l->head;
      i = 0;
      while(current != NULL)
      {
        if(i == index)
          {
            return(current->value);
          }
        else
          {
            current = current->next;
            i++;
          }
      }
    }
  return value;
}
/* Returns the index at which the given element appears. */
int list_get_index_of(list_t *l, elem value) 
{
  int i = 0;
  node_t *current = l->head;
  if(l->head == NULL)
    {
      return value;
    }
  while (current != NULL)
    {
      if (value == current->value)
        {
          return i;
        }
      current = current->next;
      i++;
    }
  return -1; 
}