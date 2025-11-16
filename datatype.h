#ifndef key
#define key
#include<stdbool.h>
 typedef enum choice{
        player1,
        player2
    } choice;

    typedef struct{
        int x;
        int y;
    }cr;
    typedef struct{
        cr point1;
        cr point2;
    }line;
    
    typedef struct {
     cr dots[500];
     line lines[1000];
     int dotcount;
     int linecount;
    int matrix[24][24];
    }strct;


#endif

