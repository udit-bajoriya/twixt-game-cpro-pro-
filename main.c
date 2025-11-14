    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include <stdbool.h>
    #include<math.h>
    // win function is left to write after this it is done
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

    cr dots[500];
    int dotcount=0;
    line lines[1000];
    int linecount=0;
    void print_matrix(int matrix[24][24]){
    for(int i=0;i<24;i++){
        for(int j=0;j<24;j++){
            if(matrix[i][j]==0){
                printf(". ");
            }
            else if(matrix[i][j]==1){
                printf("R ");
            }
            else if( matrix[i][j]==-1){
                printf("B ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    }
    bool linecheck(int j,int i,cr p){
        
    for(int k=0;k<linecount;k++){
        double slope=(double)(lines[k].point1.y-lines[k].point2.y)/(double)(lines[k].point1.x-lines[k].point2.x);
        double s1= (j-lines[k].point1.y)- slope*(i-lines[k].point1.x);
        double s2= (p.y-lines[k].point1.y)- slope*(p.x-lines[k].point1.x);
        
        if(s1*s2<0){
            double mx=(double)(p.x+i)/2.0;
            double my=(double)(p.y+j)/2.0;
            
            double minx,miny,maxx,maxy;
            if(lines[k].point1.x<lines[k].point2.x){
                minx=lines[k].point1.x;
                maxx=lines[k].point2.x;
            }
            else{
                maxx=lines[k].point1.x;
                minx=lines[k].point2.x;
            }
            if(lines[k].point1.y<lines[k].point2.y){
                miny=lines[k].point1.y;
                maxy=lines[k].point2.y;
            }
            else{
                maxy=lines[k].point1.y;
                miny=lines[k].point2.y;
            }
          
            if(minx<=mx && mx<=maxx && miny<=my && my<=maxy){
                return true;
            }
        
        }
    }
    return false;
    }

    void check(int matrix[24][24], cr p,enum choice* cur){
        // return  true;
        for(int i=0;i<24;i++){
            for(int j=0;j<24;j++){
            if(*cur==player1){
            if(matrix[i][j]==1 && ((abs(j-p.x)==2&&abs(i-p.y)==1)|| (abs(i-p.y)==2&& abs(j-p.x)==1  )) && (!linecheck(i,j,p))){
                lines[linecount].point1.x=p.x;
                lines[linecount].point1.y=p.y; 
                lines[linecount].point2.x=j;
                lines[linecount].point2.y=i;
                linecount++;
                }
                }
            else if(*cur==player2){
                if(matrix[i][j]==-1 && ((abs(j-p.x)==2&&abs(i-p.y)==1)|| (abs(i-p.y)==2&& abs(j-p.x)==1  )) && (!linecheck(i,j,p))){
                lines[linecount].point1.x=p.x;
                lines[linecount].point1.y=p.y; 
                lines[linecount].point2.x=j;
                lines[linecount].point2.y=i;
                linecount++;
                }}}
        }
        for(int i=0;i<linecount;i++){
        printf("%d %d %d %d\n",lines[i].point1.x,lines[i].point1.y,lines[i].point2.x,lines[i].point2.y);}
    }


    void print_dot(int matrix[24][24],enum choice cur){
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
        print_dot(matrix,cur);
    }
    check(matrix,p,&cur);
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

    int main(){
    int matrix[24][24]={0};matrix[0][0]=-2;matrix[0][23]=-2;matrix[23][0]=-2;matrix[23][23]=-2;
    print_matrix(matrix);
    enum choice cur=player1;
    int i=10;
    printf("player 1 turn\n");

    while(i--){
    print_dot(matrix,cur);
    print_matrix(matrix);
    // win();
    change(&cur);
    }


    }