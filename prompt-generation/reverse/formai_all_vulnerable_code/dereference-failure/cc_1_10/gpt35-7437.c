//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREASURES 1000
#define MAX_CAPACITY 100
#define KNAPSACK_PERCENTAGE 0.6

struct treasure {
    int value;
    int weight;
    char* name;
};

typedef struct treasure Treasure;

void print_menu() {
    printf("\n-----------------------\n");
    printf("What do you want to do?\n");
    printf("1. Add a treasure to the hoard\n");
    printf("2. See the hoard\n");
    printf("3. Fill the knapsack\n");
    printf("4. Quit\n");
    printf("-----------------------\n\n");
}

void add_treasure(Treasure* hoard[], int* size) {
    if (*size >= MAX_TREASURES) {
        printf("The hoard is full!\n");
        return;
    }

    Treasure* new_treasure = malloc(sizeof(Treasure));

    printf("Enter the treasure's name: ");
    new_treasure->name = malloc(50);
    scanf("%s", new_treasure->name);

    printf("Enter the treasure's value (gold coins): ");
    scanf("%d", &(new_treasure->value));

    printf("Enter the treasure's weight (pounds): ");
    scanf("%d", &(new_treasure->weight));

    hoard[*size] = new_treasure;
    *size = *size + 1;
    printf("The treasure was added to the hoard.\n");
}

void print_hoard(Treasure* hoard[], int size) {
    if (size == 0) {
        printf("The hoard is empty!\n");
        return;
    }

    printf("=====================\n");
    for (int i = 0; i < size; i++) {
        Treasure* treasure = hoard[i];
        printf("Name: %s\n", treasure->name);
        printf("Value: %d gold coins\n", treasure->value);
        printf("Weight: %d pounds\n", treasure->weight);
        printf("---------------------\n");
    }
}

int comp(const void* a, const void* b) {
    Treasure** treasure_a = (Treasure**)a;
    Treasure** treasure_b = (Treasure**)b;

    double ratio_a = (double)(*treasure_a)->value / (double)(*treasure_a)->weight;
    double ratio_b = (double)(*treasure_b)->value / (double)(*treasure_b)->weight;

    if (ratio_a > ratio_b) {
        return -1;
    } else if (ratio_a < ratio_b) {
        return 1;
    } else {
        return 0;
    }
}

void fill_knapsack(Treasure* hoard[], int size) {
    if (size == 0) {
        printf("The hoard is empty!\n");
        return;
    }

    int knapsack_capacity = MAX_CAPACITY * KNAPSACK_PERCENTAGE;

    qsort(hoard, size, sizeof(Treasure*), comp);

    int current_weight = 0;
    int current_value = 0;
    int index = 0;

    printf("=====================\n");
    printf("Filling the knapsack with treasures:\n");

    while (current_weight < knapsack_capacity && index < size) {
        Treasure* treasure = hoard[index];

        if (current_weight + treasure->weight <= knapsack_capacity) {
            current_weight += treasure->weight;
            current_value += treasure->value;
            printf("- %s (%d gold coins, %d pounds)\n", treasure->name, treasure->value, treasure->weight);
        }

        index++;
    }

    printf("---------------------\n");
    printf("Total value of the treasures: %d gold coins\n", current_value);
    printf("Total weight of the treasures: %d pounds\n", current_weight);
    printf("=====================\n");
}

int main() {
    Treasure* hoard[MAX_TREASURES];
    int hoard_size = 0;
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_treasure(hoard, &hoard_size);
                break;
            case 2:
                print_hoard(hoard, hoard_size);
                break;
            case 3:
                fill_knapsack(hoard, hoard_size);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    printf("Thank you for playing!\n");

    return 0;
}