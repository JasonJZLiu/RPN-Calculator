#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack* create_stack(){
    struct stack* stack_ptr = malloc(sizeof(struct stack));
    if (stack_ptr == NULL) {
        return NULL;
    }else{
        stack_ptr -> size = 0;
        stack_ptr -> top = NULL;
        return stack_ptr;
    }
}

void delete_stack(struct stack* s){
    int og_size = s -> size;
    for (int i = 0; i < og_size; i++){
        pop(s);
    }
    free(s);
    s = NULL;
}

double pop(struct stack* s){
    float return_val = s -> top -> value;
    struct stack_entry* temp = s -> top;
    s -> top = s -> top -> next;
    free(temp);
    temp == NULL;
    s -> size += -1;

    return (double) return_val;
}

int push(struct stack* s, double e){
    struct stack_entry* entry_ptr = malloc(sizeof(struct stack_entry));
    if (entry_ptr == NULL){
        return -1;
    }else{
        entry_ptr -> value = (float)e;
        entry_ptr -> next = s -> top;
        s -> top = entry_ptr;
        s -> size += 1;
        return 0;
    }
}

/*
int main(){
    struct stack* s = create_stack ();
    double val1 = 23;
    double val2 = 424;

    push(s, val1);
    printf("%f \n", s -> top -> value );

    push(s, val2);
    printf("%f \n", s -> top -> value );
    printf("%d \n", s -> size );

    printf ("%f \n", pop(s));

    //delete_stack(s);
    printf ("%d", s);
}
*/







