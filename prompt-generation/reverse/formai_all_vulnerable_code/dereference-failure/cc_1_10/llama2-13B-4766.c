//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define TREE_HEIGHT_MIN 10
#define TREE_HEIGHT_MAX 50
#define TREE_DIAMeter_MIN 5
#define TREE_DIAMeter_MAX 20
#define TREE_SPACING 10

// Structure to hold tree data
typedef struct {
    int height;
    int diameter;
    int x;
    int y;
} tree_t;

// Function to generate random tree data
tree_t* generate_tree(void) {
    int height = (int)(rand() % (TREE_HEIGHT_MAX - TREE_HEIGHT_MIN + 1)) + TREE_HEIGHT_MIN;
    int diameter = (int)(rand() % (TREE_DIAMeter_MAX - TREE_DIAMeter_MIN + 1)) + TREE_DIAMeter_MIN;
    int x = (int)(rand() % (100 - TREE_SPACING + 1)) + TREE_SPACING;
    int y = (int)(rand() % (100 - TREE_SPACING + 1)) + TREE_SPACING;

    tree_t* t = malloc(sizeof(tree_t));
    t->height = height;
    t->diameter = diameter;
    t->x = x;
    t->y = y;

    return t;
}

// Function to print the forest of trees
void print_forest(tree_t** forest, int num_trees) {
    int i;

    for (i = 0; i < num_trees; i++) {
        printf("Tree %d: Height = %d, Diameter = %d, X = %d, Y = %d\n", i, forest[i]->height, forest[i]->diameter, forest[i]->x, forest[i]->y);
    }
}

int main(void) {
    srand(time(NULL)); // seed the random number generator

    // Create an array of tree structures
    tree_t** forest = malloc(sizeof(tree_t*) * 100);
    int num_trees = 100;

    // Generate the array of tree structures
    for (int i = 0; i < num_trees; i++) {
        forest[i] = generate_tree();
    }

    // Print the forest of trees
    print_forest(forest, num_trees);

    return 0;
}