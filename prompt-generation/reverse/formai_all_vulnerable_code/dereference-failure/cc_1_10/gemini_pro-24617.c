//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: Cryptic
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX(_a, _b) (_a > _b ? _a : _b)

enum{ N, E, S, W };

struct path{
    int **p;
    int sx, sy, ex, ey, n, m;
    bool **vst;
};

int moves[4][2] = {
    {0, -1}, //N
    {1, 0},  //E
    {0, 1},  //S
    {-1, 0}, //W
};

bool is_valid(struct path p, int x, int y){
    return p.p[x][y] == 0 && !p.vst[x][y] &&
    x >= 0 && x < p.n && y >= 0 && y < p.m;
}

int dfs_path(struct path p, int x, int y){
    if(x == p.ex && y == p.ey)
        return 1;

    int c, mx = 1;
    p.vst[x][y] = true;
    for(c = 0; c < 4; c++){
        if(is_valid(p, x + moves[c][0], y + moves[c][1]))
            mx = MAX(mx, 1 + dfs_path(p, x + moves[c][0], y + moves[c][1]));
    }
    p.vst[x][y] = false;
    return mx;
}

int main(int argc, char** argv){
    struct path p = {{
        0, 0, 0, 0,
        0, 1, 1, 0,
        0, 0, 1, 0,
        0, 0, 0, 0
    }, 0, 0, 3, 3, 4, 4, NULL};
    // p.p contains the grid, p.sx and p.sy are the starting position,
    // p.ex and p.ey are the ending position,
    // p.n and p.m are the number of rows and columns of the grid.

    p.vst = malloc(p.n * sizeof(bool*));
    for(int i = 0; i < p.n; i++)
        p.vst[i] = malloc(p.m * sizeof(bool));

    printf("Longest path length: %d", dfs_path(p, p.sx, p.sy));

    for(int i = 0; i < p.n; i++)
        free(p.vst[i]);
    free(p.vst);

    return 0;
}