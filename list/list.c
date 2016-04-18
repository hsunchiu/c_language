/*list.c-- the functiion about list*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*prototype of local function*/
static void CopyToNode (Item item, Node * pnode);

/*funtion API*/
/*empty the list*/
void InitializeList (List * plist)
{
	* plist = NULL;
}

/*if the list is empty return true*/
bool ListIsEmpty (const List * plist)
{
	if (* plist == NULL)
		return true;
	else 
		return false;
}

/*if the list is full return true*/
bool ListIsFull (const List * plist)
{	
	Node * pt;
	bool full;

	pt = (Node *)malloc(sizeof(Node));
	if (pt == NULL)
		return true;
	else 
		return false;
	free(pt);
	return full;
}

/*return the number of Node*/
unsigned in ListItemCount (const List * plist)
{
	unsigned int count;
	Node * pnode = *plist; /*set the start of list*/

	while(pnode != NULL)
	{
	    ++count;
	    pnode = pnode ->next; /*set l as the next node*/
	}
	return count;
}

/*biuld a node of list and save it to*/
/*the tail of list pointed by plist(the speed of the compliment is not fast)*/
bool AddItem (Item item, List * plist)
{
	Node * pnew;
	Node * scan = *plist;

	pnew = (Node *)malloc(sizeof (Node));
	if (pnew == NULL)
	  	return false;  /*if failed, exit*/

	CopyToNode(item , pnew);
	pnew->next = NULL;  /*null list , so set pnew*/
	if (scan == NULL)  /*as the head */
	{
		*plist = pnew;
	}
	else 
	{
		while(scan->next != NULL) 
		{
		   	scan = scan->next; /*find the tail of list*/

		}
		scan->next = pnew;    /*add the pnew to the tail*/
	}
	return true;
}

/*access every node and use pfun to handle them*/
void Traverse (const List * plist, void (*pfun)(Item Item))
{
	Node * pnode = *plist;  
	while(pnode != NULL) 
	{
	    (* pfun)(pnode->item);
	    pnode = pnode->next;
	}
}

/*free the memory of malloc*/
/*set the point NULL*/
void EmptyTheList (List * plist)
{
	Node * psave;
	while(*plist != NULL)
	{
	 	psave = (*plist)->next;
	 	free (*plist);
	 	*plist = psave;
	}
}

/*define the local function*/
/*copy a item to node*/
static void CopyToNode (Item item, Node * pnode)
{
	pnode->item = item;             /*copy the structure*/
}