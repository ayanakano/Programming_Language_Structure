#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/set.h"
#include "headers/set_node.h"

void add(struct Set * set, char * word) {
	//create the node containing the word
	struct SetNode * item = (struct SetNode *) malloc( sizeof( struct SetNode));
	if (item == NULL) error();
	item -> word = word;
	item -> next = NULL;
	//attach node to set:
	if ( set -> size == 0) {// set is empty
		set -> first = item;
		set -> size = 1;
	}
	else if (!isMember(set, word) ){
		item -> next = set -> first;
		set -> first = item;
		set -> size = set -> size + 1;
	}
}

int isMember(struct Set * set, char * word)
{
	struct SetNode * item = set -> first;
	while(item -> next != NULL)
	{
		if(strcmp(item -> word,word) == 0)
			return 1;
		item = item -> next;
	}
	if(strcmp(item -> word,word) == 0)
		return 1;
	return 0;
}

void printSet(struct Set * set)
{
	struct SetNode * item = set -> first;
	while(item -> next != NULL)
	{
		if(item -> word != NULL)
			printf("%s\n",item -> word);
		item = item -> next;
	}
	if(item -> word != NULL)
		printf("%s\n",item -> word);
}

void writeSetToFile(struct Set * set, FILE * file)
{
	struct SetNode * item = set -> first;
	while(item -> next != NULL)
	{
		if(item -> word != NULL)
		{
			fprintf(file, item -> word);
			fprintf(file, "\n");
		}
		item = item -> next;
	}
	if(item -> word != NULL)
	{
		fprintf(file, item -> word);
		fprintf(file, "\n");
	}
}