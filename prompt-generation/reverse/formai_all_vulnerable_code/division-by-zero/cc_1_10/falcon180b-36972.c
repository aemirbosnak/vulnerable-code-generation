//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 100

int vertices[MAX_VERTICES];
int colors[MAX_VERTICES];
int num_vertices;
int num_colors;

void init(int n) {
    num_vertices = n;
    for (int i = 0; i < n; i++) {
        vertices[i] = i;
        colors[i] = -1;
    }
}

void print_solution(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", i, colors[i]);
    }
}

int is_valid(int v, int c, int k) {
    for (int i = 0; i < k; i++) {
        if (colors[vertices[i]] == c && vertices[i]!= v) {
            return 0;
        }
    }
    return 1;
}

void backtrack(int v, int k) {
    if (v == num_vertices - 1) {
        print_solution(num_vertices);
        exit(0);
    }
    for (int i = 0; i < num_colors; i++) {
        if (is_valid(v, i, k)) {
            colors[v] = i;
            backtrack(v + 1, k);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init(n);
    srand(time(NULL));
    int k = rand() % num_colors + 1;
    printf("Number of colors: %d\n", k);
    backtrack(0, k);
    return 0;
}