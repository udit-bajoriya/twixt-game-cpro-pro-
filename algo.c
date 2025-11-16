    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include <stdbool.h>
    #include<math.h>
    #include"datatype.h"
    #include"algo.h"
    void print_matrix(strct*s){
    for(int i=0;i<24;i++){
        for(int j=0;j<24;j++){
            if(s->matrix[i][j]==0){
                printf(". ");
            }
            else if(s->matrix[i][j]==1){
                printf("R ");
            }
            else if( s->matrix[i][j]==-1){
                printf("B ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    }
    bool linecheck(int j,int i,cr p,strct *s){
        
    for(int k=0;k<s->linecount;k++){
        double slope=(double)(s->lines[k].point1.y-s->lines[k].point2.y)/(double)(s->lines[k].point1.x-s->lines[k].point2.x);
        double s1= (j-s->lines[k].point1.y)- slope*(i-s->lines[k].point1.x);
        double s2= (p.y-s->lines[k].point1.y)- slope*(p.x-s->lines[k].point1.x);
        
        if(s1*s2<0){
            double mx=(double)(p.x+i)/2.0;
            double my=(double)(p.y+j)/2.0;
            
            double minx,miny,maxx,maxy;
            if(s->lines[k].point1.x<s->lines[k].point2.x){
                minx=s->lines[k].point1.x;
                maxx=s->lines[k].point2.x;
            }
            else{
                maxx=s->lines[k].point1.x;
                minx=s->lines[k].point2.x;
            }
            if(s->lines[k].point1.y<s->lines[k].point2.y){
                miny=s->lines[k].point1.y;
                maxy=s->lines[k].point2.y;
            }
            else{
                maxy=s->lines[k].point1.y;
                miny=s->lines[k].point2.y;
            }
          
            if(minx<=mx && mx<=maxx && miny<=my && my<=maxy){
                return true;
            }
        
        }
    }
    return false;
    }

    void check(cr p,enum choice* cur,strct *s){
        // return  true;
        for(int i=0;i<24;i++){
            for(int j=0;j<24;j++){
            if(*cur==player1){
            if(s->matrix[i][j]==1 && ((abs(j-p.x)==2&&abs(i-p.y)==1)|| (abs(i-p.y)==2&& abs(j-p.x)==1  )) && (!linecheck(i,j,p,s))){
                s->lines[s->linecount].point1.x=p.x;
                s->lines[s->linecount].point1.y=p.y; 
                s->lines[s->linecount].point2.x=j;
                s->lines[s->linecount].point2.y=i;
                s->linecount++;
                }
                }
            else if(*cur==player2){
                if(s->matrix[i][j]==-1 && ((abs(j-p.x)==2&&abs(i-p.y)==1)|| (abs(i-p.y)==2&& abs(j-p.x)==1  )) && (!linecheck(i,j,p,s))){
                s->lines[s->linecount].point1.x=p.x;
                s->lines[s->linecount].point1.y=p.y; 
                s->lines[s->linecount].point2.x=j;
                s->lines[s->linecount].point2.y=i;
                s->linecount++;
                }}}
        }
        for(int i=0;i<s->linecount;i++){
        printf("%d %d %d %d\n",s->lines[i].point1.x,s->lines[i].point1.y,s->lines[i].point2.x,s->lines[i].point2.y);}
    }


    void print_dot(int matrix[24][24],enum choice cur,strct* s){
        bool done=false;
        while(!done){
        cr p;
        printf("give coordinate x y(0-23): ");
        scanf("%d %d",&(p.x),&(p.y));


    
        if(cur==player1 && p.x>0 && matrix[p.y][p.x]==0){
            matrix[p.y][p.x]=1;
        }
        else if(cur==player2 && p.y>0 && matrix[p.y][p.x]==0){
            matrix[p.y][p.x]=-1;
        }
        
    else{
        printf("give valid coordinate\n");
        continue;
    }
    check(p,&cur,s);
    done=true;
    }
    
}
    bool win(){
    }
    

    void change(enum choice *cur){
    if(*cur==player1){
        printf("player 2 turn\n");
        *cur=player2;
    }
    else{
        printf("player 1 turn\n");
        *cur=player1;
    }

    }