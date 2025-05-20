//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#define SITE_COUNT 101
#define BOTTOM 100

typedef struct {
    int site;
    int state;
    struct Site *down;
} Site;

Site *sites;
int open_sites = 0;

void initialize() {
    int i;
    sites = (Site *)calloc(SITE_COUNT, sizeof(Site));

    for (i = 0; i < SITE_COUNT; i++) {
        sites[i].site = i;
        sites[i].state = 0;
        sites[i].down = NULL;
    }

    sites[0].state = 1;
    open_sites = 1;
}

void connect_neighbors(int site) {
    int top = site - 1;
    int bottom = site + 1;
    int left = site - 1 - 1;
    int right = site + 1 + 1;

    if (top >= 0 && sites[top].state == 0) {
        sites[top].down = &sites[site];
        sites[site].state++;
        open_sites++;
    }

    if (bottom < SITE_COUNT && sites[bottom].state == 0) {
        sites[bottom].down = &sites[site];
        sites[site].state++;
        open_sites++;
    }

    if (left >= 0 && sites[left].state == 0) {
        sites[left].down = &sites[site];
        sites[site].state++;
        open_sites++;
    }

    if (right < SITE_COUNT && sites[right].state == 0) {
        sites[right].down = &sites[site];
        sites[site].state++;
        open_sites++;
    }
}

void print_state() {
    int i;

    for (i = 0; i < SITE_COUNT; i++) {
        if (sites[i].state == 0)
            printf("%d ", sites[i].site);
        else
            printf("%d ", sites[i].site);
    }

    printf("\n");
}

int main() {
    int i, j;

    initialize();

    for (i = 1; open_sites < SITE_COUNT; i++) {
        connect_neighbors(i);
    }

    print_state();

    free(sites);

    return 0;
}