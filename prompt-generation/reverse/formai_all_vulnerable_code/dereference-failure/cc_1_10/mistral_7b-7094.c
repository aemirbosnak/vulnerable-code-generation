//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define MAX_BAGS 1000
#define BAG_SIZE 50

struct Bag {
    char id[7];
    char contents[BAG_SIZE];
    int weight;
    struct Bag* next;
};

typedef struct Bag Bag;

Bag* belt = NULL;
int total_bags = 0;

void add_bag(char* id, char* contents, int weight) {
    Bag* new_bag = (Bag*) malloc(sizeof(Bag));
    strcpy(new_bag->id, id);
    strcpy(new_bag->contents, contents);
    new_bag->weight = weight;
    new_bag->next = belt;
    belt = new_bag;
    total_bags++;
}

void scan_bag(Bag* bag) {
    printf("Scanning bag %s...\n", bag->id);
    if (strcmp(bag->id, "BOMB") == 0) {
        printf("BOMB DETECTED!!\n");
        printf("Bag %s contains: %s\n", bag->id, bag->contents);
        printf("Weight: %d kg\n", bag->weight);
        exit(1);
    }
}

void handle_bags() {
    printf("\n---------- BAGGAGE HANDLING STARTS ----------\n");
    Bag* current = belt;
    srand(time(NULL));

    while (current != NULL && total_bags > 0) {
        int random_time = rand() % 10 + 1; // simulate random time
        printf("Handling bag %s...\n", current->id);
        scan_bag(current);
        total_bags--;
        current = current->next;
        sleep(random_time);
    }

    if (total_bags == 0) {
        printf("\n---------- ALL BAGS HANDLED ----------\n");
    }
}

int main() {
    add_bag("SMITH J12345", "Shirt, Jeans, Shoes", 10);
    add_bag("JOHN D67890", "Trousers, Belt, Wallet", 5);
    add_bag("BOMB X13579", "Explosives", 10);
    add_bag("SARA K24681", "Dress, Heels, Makeup", 5);
    add_bag("MIKE L39527", "Suit, Tie, Laptop", 15);

    handle_bags();

    return 0;
}