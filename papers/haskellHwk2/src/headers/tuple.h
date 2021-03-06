#ifndef TUPLE_H_
#define TUPLE_H_

#endif /*TUPLE_H_*/

struct TUPLE {
	char* numbers;
	char* characters;
	int pointerNumbers;
	int pointerCharacters;
};

void init_tuple(struct TUPLE *tuple, char* str);
void add_number_to_tuple(struct TUPLE *tuple, char num);
void add_character_to_tuple(struct TUPLE *tuple, char c);
void print_tuple(struct TUPLE *tuple);
