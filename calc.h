#ifndef LAB3_CALC_H
#define LAB3_CALC_H

#define unary_op(c)c=='s'||c =='c'||c =='t'||c =='e' \
				   ||c =='i'||c =='m'||c =='r'||c=='d'
#define binary_op(c) c=='+'||c =='-'||c =='*'||c =='/'||c =='^'||c =='f'


double compute_rpn(char* rpn);
char* get_expressions(char* filename);
void process_expressions(char* expressions, char* filename);

#endif
