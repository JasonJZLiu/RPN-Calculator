#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"
#include "stack.h"

double compute_rpn(char* rpn){
    char str_arr [256];
    struct stack* s = create_stack ();

    double answer;

    strcpy (str_arr, rpn);
    char *tok = strtok (str_arr , " ");
    push(s, atof(tok));

    while (tok = strtok (NULL , " " )){
        if (binary_op(tok[0])){
            double op2 = pop(s);
            double op1 = pop(s);
            //printf("%lf \n", op1);
            //printf("%lf \n", op2);

            if (strcmp(tok,"+") == 0){
                push (s, op1 + op2);
            }else if(strcmp(tok,"-") == 0){
                push (s, op1 - op2);
            }else if(strcmp(tok,"*") == 0){
                push (s, op1 * op2);
            }else if(strcmp(tok,"/") == 0){
                push (s, op1 / op2);
            }else if(strcmp(tok,"^") == 0){
                push (s, pow(op1, op2));
            }else if(strcmp(tok,"f") == 0){
                push (s, op2);
                push (s, op1);
            }

        }else if (unary_op(tok[0])){
            double op1 = pop(s);

            if (strcmp(tok,"s") == 0){
                push (s, sin(op1));
            }else if(strcmp(tok,"c") == 0){
                push (s, cos(op1));
            }else if(strcmp(tok,"t") == 0){
                push (s, tan(op1));
            }else if(strcmp(tok,"c") == 0){
                push (s, cos(op1));
            }else if(strcmp(tok,"e") == 0){
                push (s, exp(op1));
            }else if(strcmp(tok,"i") == 0){
                push (s, 1/op1);
            }else if(strcmp(tok,"m") == 0){
                push (s, -op1);
            }else if(strcmp(tok,"r") == 0){
                push (s, pow(op1, 0.5));
            }

        }else{
            push(s, atof(tok));
        }
    }
    answer = pop(s);
    delete_stack (s);
    return answer;
}

char* get_expressions(char* filename){

    FILE *input_stream = fopen(filename, "r");

    char file_line[256];
    //char* char_arr = calloc (0, 0);
    char* char_arr;
    int size = 0;
    int count = 0;

  
    while(fgets(file_line, sizeof(file_line), input_stream)!= NULL){
        size = size + strlen(file_line)+1;

        if (count == 0){
            char_arr = calloc(strlen(file_line), sizeof(char));
            strcat(char_arr,file_line);
        }else{
            char_arr = realloc(char_arr, size* sizeof(char));
            strcat(char_arr,file_line);
        }
        count ++;
    }
    fclose(input_stream);
    return char_arr;
}

void process_expressions(char* expressions, char* filename){

    char* token;
    char* rest = expressions;
    double answer;

    FILE *output_stream = fopen(filename, "w");
    while (token = strtok_r(rest, "\n", &rest)){
	answer = compute_rpn(token);
	fprintf(output_stream, "%f\n", answer);
    }
    fclose(output_stream);
}



int main (){
    char *str = "1 2 f m +";
    double ans = compute_rpn(str);
    //printf("%lf \n", ans);
    char* asd = get_expressions("sample_in.txt");
    //printf("%s\n", asd);
    for (int i=0; i < strlen(asd); i++){
        printf ("%c", asd[i]);

    }


    printf("\n");
    process_expressions(asd, "asd");
    free (asd);
    asd = NULL;



}
