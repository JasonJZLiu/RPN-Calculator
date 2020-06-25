#ifndef LAB3_STACK_H
#define LAB3_STACK_H

struct stack_entry{
	float value;
	struct stack_entry* next;
};

struct stack{
	int size;
	struct stack_entry* top;
};

struct stack* create_stack(void);
void delete_stack(struct stack*);

double pop(struct stack* s);
int push(struct stack* s, double e);

#endif
