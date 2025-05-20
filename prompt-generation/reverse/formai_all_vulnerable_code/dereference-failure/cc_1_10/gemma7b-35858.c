//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void baggage_handling(int num_bags, int bag_size, char **bag_contents) {
    for (int i = 0; i < num_bags; i++) {
        printf("Bag %d:\n", i + 1);
        for (int j = 0; j < bag_size; j++) {
            printf("  Item: %s\n", bag_contents[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int num_bags = 3;
    int bag_size = 5;
    char **bag_contents = malloc(num_bags * sizeof(char **));
    for (int i = 0; i < num_bags; i++) {
        bag_contents[i] = malloc(bag_size * sizeof(char *));
        for (int j = 0; j < bag_size; j++) {
            bag_contents[i][j] = malloc(20 * sizeof(char));
        }
    }

    strcpy(bag_contents[0][0], "Laptop");
    strcpy(bag_contents[0][1], "Shoes");
    strcpy(bag_contents[0][2], "Clothes");
    strcpy(bag_contents[0][3], "Books");
    strcpy(bag_contents[0][4], "Water bottle");

    strcpy(bag_contents[1][0], "Phone");
    strcpy(bag_contents[1][1], "Tweed jacket");
    strcpy(bag_contents[1][2], "Wallet");
    strcpy(bag_contents[1][3], "Sunglasses");
    strcpy(bag_contents[1][4], "Snacks");

    strcpy(bag_contents[2][0], "Ipad");
    strcpy(bag_contents[2][1], "Sandals");
    strcpy(bag_contents[2][2], "Jewelry");
    strcpy(bag_contents[2][3], "Hand cream");
    strcpy(bag_contents[2][4], "Hairbrush");

    baggage_handling(num_bags, bag_size, bag_contents);

    for (int i = 0; i < num_bags; i++) {
        free(bag_contents[i]);
    }
    free(bag_contents);

    return 0;
}