#ifndef types
#define types
#include <stdbool.h>

typedef struct coord {
    int x;
    int y;
} coord;

typedef struct line {
    coord *P1;
    coord *P2;
} line;

typedef enum {
    p1,
    p2
} player;

typedef struct data {
    int board[24][24];
    coord dots[24][24];
    line lines[24 * 24 * 4]; 
    int countl;
    bool checklines[24][24][24][24];
} data;
#endif