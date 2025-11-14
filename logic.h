#ifndef logic
#define logic
#include <stdbool.h>
#include "structs.h"

bool check(line l1, line l2);
void print(data *g);
void checkwinpoint(data *g, int p, int r, int c, bool visited[24][24], int *ans);
bool win(data *g, int p);

#endif