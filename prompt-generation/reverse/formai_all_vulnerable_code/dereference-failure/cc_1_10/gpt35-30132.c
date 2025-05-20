//FormAI DATASET v1.0 Category: Binary search trees ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct Ant {
    int id;
    struct Ant *left;
    struct Ant *right;
} Ant;

Ant *createAnt(int id) {
    Ant *newAnt = (Ant*) malloc(sizeof(Ant));
    newAnt->id = id;
    newAnt->left = NULL;
    newAnt->right = NULL;
    return newAnt;
}

Ant *insert(Ant *ant, int id) {
    if (ant == NULL) {
        return createAnt(id);
    } else if (id < ant->id) {
        ant->left = insert(ant->left, id);
    } else if (id > ant->id) {
        ant->right = insert(ant->right, id);
    } else {
        printf("You can't add two ants with the same ID\n");
        return ant;
    }
    return ant;
}

Ant *search(Ant *ant, int id) {
    if (ant == NULL || ant->id == id) {
        return ant;
    } else if (id < ant->id) {
        return search(ant->left, id);
    } else {
        return search(ant->right, id);
    }
}

void printAnts(Ant *ant) {
    if (ant != NULL) {
        printAnts(ant->left);
        printf("%d\n", ant->id);
        printAnts(ant->right);
    }
}

int main() {
    Ant *queen = NULL;
    int numOfAnts;

    printf("Welcome to the ant binary search tree! How many ants in the colony?\n");
    scanf("%d", &numOfAnts);

    for (int i = 0; i < numOfAnts; i++) {
        int id;
        printf("Enter the ID of ant #%d: \n", i+1);
        scanf("%d", &id);

        queen = insert(queen, id);
    }

    printf("\nAnts in the colony, in order by ID:\n");
    printAnts(queen);

    int searchID;
    printf("\nEnter an ant ID to search for:\n");
    scanf("%d", &searchID);

    Ant *found = search(queen, searchID);
    if (found == NULL) {
        printf("Ant ID not found in colony.\n");
    } else {
        printf("Ant ID %d found in colony.\n", found->id);
    }

    return 0;
}