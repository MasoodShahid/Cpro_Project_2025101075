#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
#include "structs.h"
#include "logic.h"

int main() {
      data g; 
      for(int i=0;i<24;i++){
        for(int j=0;j<24;j++){
            g.board[i][j]=0; 
        }
    }
   for(int i=0;i<24;i++){
    for(int j=0;j<24;j++){
        for(int k=0;k<24;k++){
            for(int l=0;l<24;l++){
                g.checklines[i][j][k][l]=false; 
            }
        }
    }
   }
    g.countl= 0; 
    player curplayer = p1;
    int move1[] = {1,1,2,2,-1,-1,-2,-2};
    int move2[] = {2,-2,1,-1,2,-2,1,-1};
    
    while (true) {
        print(&g); 
        int num;
        if (curplayer==p1) {
            num=1;
        } else {
            num=2;
        }   
        char color;
        if (num==1) {
            color='R';
        } else {
            color='B';
        }     
        printf("Player %d (%c)\n", num, color);
        int r, c;     
        while (true) {
            printf("Enter row and column (0-23): ");
            if (scanf("%d %d",&r,&c)!=2) {
                while (getchar()!='\n'); 
                printf("Invalid,Enter two numbers.\n");
                continue;
            }
            if (r<0 || r>=24 || c<0 || c>=24) {
                printf("Invalid,Must be 0-23.\n");
                continue;
            }
            if (g.board[r][c]!=0) { 
                printf("Already taken.\n");
                continue;
            }
            if ((r==0 && c==0)||(r==0 && c==23) || (r==23 && c==0) || (r==23 && c==23)) {
                break;
            }
            if (num == 1 && (c == 0 || c == 23)) {
                printf("Player 1 cannot play in the first or last column (except corners).\n");
                continue;
            }         
            if (num == 2 && (r==0 || r==23)) {
                printf("Player 2 cannot play in the first or last row (except corners).\n");
                continue;
            }
            break; 
        }
        g.board[r][c]=num; 
        g.dots[r][c].x=c; 
        g.dots[r][c].y=r; 
        coord *newdot=&g.dots[r][c]; 
        
        for (int i=0;i<8; i++) {
            int currow = r+move1[i];
            int curcol = c+move2[i];
            if (currow<0 || currow>=24 || curcol<0 || curcol>=24) {
                continue;
            }
            if (g.board[currow][curcol]==num) { 
                coord *existingdot=&g.dots[currow][curcol]; 
                line curline;
                curline.P1=newdot;
                curline.P2=existingdot;
                bool intersects = false;
                for (int j=0; j<g.countl; j++) { 
                    if (check(curline, g.lines[j])==true) { 
                        intersects=true;
                        break;
                    }
                }
                if (intersects==false){
                    g.lines[g.countl]= curline; 
                    g.countl++;      
                    g.checklines[r][c][currow][curcol] = true; 
                    g.checklines[currow][curcol][r][c] = true; 
                    printf("Added line: (%d,%d) to (%d,%d)\n", r, c, currow, curcol);
                }
            }
        }
        
        if (win(&g, num)) { 
            print(&g); 
            printf("\n");
            printf("PLAYER %d (%c) WINS!\n", num, color);
            break; 
        }
        
        if (curplayer==p1) {
            curplayer=p2;
        } else {
            curplayer=p1;
        }
    }
    return 0;
}