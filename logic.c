#include <stdio.h>
#include<math.h>
#include "logic.h"
#include "structs.h"

bool check(line l1,line l2){
    double m=(double)(l2.P1->y-l2.P2->y)/(double)(l2.P1->x-l2.P2->x);
    double m1=(double)(l1.P1->y-l2.P1->y) - m*(double)(l1.P1->x-l2.P1->x);
    double m2=(l1.P2->y-l2.P1->y) - m*(l1.P2->x-l2.P1->x);
    double midptx=(double)(l1.P1->x+l1.P2->x)/2.0;
    double midpty=(double)(l1.P1->y+l1.P2->y)/2.0;
    if(m1*m2>=0) return false;
    if(m1*m2<0){
        double minx,miny,maxx,maxy;
        minx=fmin(l2.P1->x,l2.P2->x);
        maxx=fmax(l2.P1->x,l2.P2->x);
        miny=fmin(l2.P1->y,l2.P2->y);
        maxy=fmax(l2.P1->y,l2.P2->y);
        if(minx<=midptx && midptx<=maxx && miny<=midpty && midpty<=maxy){
             return true;
        }
    }
    return false;
}

void print(data *g) {
    for (int i = 0; i < 24; i++) {     
        for (int j = 0; j < 24; j++) {
            if (g->board[i][j] == 0) {
                printf(". ");
            }
            if (g->board[i][j] == 1) {
                printf("R "); 
            }
            if (g->board[i][j] == 2) {
                printf("B ");
            }
        }
        printf("\n");
    }
}

void checkwinpoint(data *g, int p, int r, int c, bool visited[24][24], int *ans) {
    if (r<0 || r>=24 || c<0 || c>=24) {
        return;
    }
    if (g->board[r][c]!=p || visited[r][c]) {
        return;
    }   
    visited[r][c]=true;
    if (p==1 && r==23) { 
        *ans = 1;
        return;
    }
    if (p==2 && c==23) { 
        *ans = 2;
        return;
    }
    int move1[] = {1,1,2,2,-1,-1,-2,-2};
    int move2[] = {2,-2,1,-1,2,-2,1,-1};
    for (int i=0;i<8;i++) {
        int currow=r+move1[i];
        int curcol =c+move2[i];
        if (currow>=0 && currow<24 && curcol>=0 && curcol<24 && 
            g->board[currow][curcol]==p &&  visited[currow][curcol]==false) {        
            if (g->checklines[r][c][currow][curcol]==true) {
                checkwinpoint(g,p,currow,curcol,visited,ans);  
                if (*ans == p) {
                    return;
                }
            }
        }
    }
}

bool win(data *g, int p) {
    bool visited[24][24];
    int ans = 0;
    for(int i=0;i<24;i++){
        for(int j=0;j<24;j++){
            visited[i][j]=false;
        }
    }
    if (p==1) { 
        for (int j=0; j<24; j++) {
            if (g->board[0][j] == 1) {
                ans = 0;
                checkwinpoint(g,1,0,j,visited,&ans);
                if (ans == 1) {
                    return true;
                }
            }
        }
    }
    if (p == 2) { 
        for (int i = 0; i < 24; i++) {
            if (g->board[i][0] == 2) {
                ans = 0;
                checkwinpoint(g, 2, i, 0, visited, &ans);
                if (ans == 2) {
                    return true;
                }
            }
        }
    }
    return false;
}