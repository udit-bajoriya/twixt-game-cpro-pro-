
#ifndef al
#define al
#include<stdbool.h>
#include "datatype.h"
void print_matrix(strct*s);
  bool linecheck(int j,int i,cr p,strct *s);
 void check(cr p,enum choice* cur,strct *s);


void print_dot(int matrix[24][24],enum choice cur,strct* s);
    
    bool win();

    void change(enum choice *cur);
   

    
#endif
