/*film.c --use the ADT of list */
/*compiled with list.c */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void showmovies (Item item);

int main(int argc, char const *argv[])
{
	List movies;
	Item temp;
/*Initialization*/
	InitializeList(&movies);///???????
	if (ListIsFull(movies))
	{
		fprintf(stderr, "No memory avialiable ! Bye.\n" );
		exit (1);
	}
/*collect and save*/
	puts("Enter first movie title:");
	while(gets(temp.title)!=NULL && temp.title[0]!='\0')
	{
	    puts("Enter your rating<0-10>");
	    scanf("%d",&temp.taring);
	    while(gets()!='/n') 
	    	continue;
	    if (AddItem(temp,&movies)==false)
	    {
	    	fprintf(stderr, "Problem allocting memory\n" );
	    	break;

	    }	
	    if (ListIsFull(movies))
	    {
	    	puts("The list is now full");
	    	break;
	    }
	    puts("Enter next movie title (empty line to stop):");

	    
	}
/*display*/
	if (ListIsEmpty(movies))
	{
		printf("No data entered.\n");
		Traverse(movies,showmovies);
	}
	printf("You entered %d movies.\n",ListItemCount(movies));
    /*clear*/
    EmptyTheList(&movies);
    printf("Bye\n");

	return 0;
}

void show(Item item)
{
    printf("Movies:%s Rating:%d\n",item.title,item.rating);
}
    


