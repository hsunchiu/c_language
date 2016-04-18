/*list.h -- the header of  simple list type */
#ifndef LIST_H
#define LIST_H
#include <stdbool.h> /*C 99*/
#define TSIZE 45 /*the size of array*/
struct film
	{
		char title[TSIZE];
		int rating;
	};	
 
 typedef struct film Item;

 typedef struct node
 {
 	Item item;
 	struct node * next;
 }Node;

typedef Node * List;

/*
prototype
descriprion:initialize a list
procodition:plist pointed to a list
postcondion:initialize a list to void
*/
void InitializeList(List * plist); 

/*
prototype
descriprion: comfirm whether a list is empty
procodition:plist pointed to a list
postcondion:initialize the list empty
*/
bool ListIsEmpty(const List * plist);

/*
prototype
descriprion:comfirn whether a list is full
procodition:plist pointed to a list
postcondion:return true when list is full or return false
*/
bool ListIsFull(const List * plist);

/*
prototype
descriprion:get the number of a list
procodition:plist pointed to a list initialized
postcondion:return the number of the item of the list
*/
unsigned int ListItemCount (const List * plist);

/*
prototype
descriprion:add a item to the tail of the list
procodition:item will be added to the list 
			plist pointed to a list initialized
postcondion:if it works,add the item to the tail of the list
			and return true or return false
*/
bool AddItem (Item item, List * plist);

/*
prototype
descriprion:use a function to handle the list
procodition:plist pointed to a list initialized
			pfun pointed to a funtion which recieve a
			an argument Item and return void
postcondion:the functinn pointed by pfun is handling the 
			item of the list
*/
void Traverse (const List * plist, void (* pfun)(Item item));

/*
prototype
descriprion:release the memory(if malloc done)
procodition:plist pointed to a list initialized
postcondion:release the memory of the list
			and set the list void
*/	
void EmptyTheList(List * plist);

#endif //LIST_H
