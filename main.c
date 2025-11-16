    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include <stdbool.h>
    #include<math.h>
    #include"datatype.h"
    #include"algo.h"

    // win function is left to write after this it is done
   
    
    int main(){
        strct s;
        s.linecount=0;
        s.dotcount=0;
        
        for(int i=0;i<24;i++){
            for(int j=0;j<24;j++){
                s.matrix[i][j]=0;
            }
        }
    // matrix[0][0]=-2;matrix[0][23]=-2;matrix[23][0]=-2;matrix[23][23]=-2;
    print_matrix(&s);
    enum choice cur=player1;
    int i=10;
    printf("player 1 turn\n");

    while(i--){
    print_dot(s.matrix,cur,&s);
    print_matrix(&s);
    // win();
    change(&cur);
    }


    }