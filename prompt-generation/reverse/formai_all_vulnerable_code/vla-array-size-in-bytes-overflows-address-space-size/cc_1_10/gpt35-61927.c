//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Sort-o-matic 3000!\n");
    printf("Input how many items you want to sort: ");

    int num_items;
    scanf("%d", &num_items);

    int items[num_items];

    printf("Great! Now enter your items, separated by a space:\n");

    for (int i = 0; i < num_items; i++) {
        scanf("%d", &items[i]);
    }

    printf("Sorting...\n");

    // Here comes the funny part!
    srand(time(NULL));
    int random_number = rand() % 3 + 1;
    switch (random_number) {
        case 1:
            printf("Summoning Sorting Hat...\n");
            printf("Sorting...\n");
            break;
        case 2:
            printf("Commencing item juggling...\n");
            printf("Sorting...\n");
            break;
        case 3:
            printf("Engaging autopilot...\n");
            printf("Sorting...\n");
            break;
        default:
            printf("Sorting...\n");
            break;
    }

    // We'll just use a simple bubble sort for now
    for (int i = 0; i < num_items-1; i++) {
        for (int j = 0; j < num_items-i-1; j++) {
            if (items[j] > items[j+1]) {
                int temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }

    printf("Sorted items: ");

    for (int i = 0; i < num_items; i++) {
        printf("%d ", items[i]);
    }
    
    printf("\nThank you for using Sort-o-matic 3000!\n");
    
    return 0;
}