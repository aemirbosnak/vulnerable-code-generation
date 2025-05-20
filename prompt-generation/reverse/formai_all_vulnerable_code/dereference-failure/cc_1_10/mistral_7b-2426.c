//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Bag structure
typedef struct {
    int id;
    char *origin;
    char *destination;
} Bag;

// Function to generate random bag IDs
int generate_random_id() {
    return rand() % 1000 + 1;
}

// Function to generate random origin and destination cities
void generate_city_names(char *city1, char *city2) {
    int random_index1, random_index2;
    static char cities[][10] = {"Amsterdam", "Barcelona", "Copenhagen", "Dubai", "Edinburgh", "Frankfurt", "Geneva", "Helsinki", "Istanbul", "Jeddah"};

    do {
        random_index1 = rand() % 10;
        random_index2 = rand() % 10;
    } while (strcmp(cities[random_index1], cities[random_index2]) == 0);

    strcpy(city1, cities[random_index1]);
    strcpy(city2, cities[random_index2]);
}

// Function to simulate baggage handling
void handle_baggage(Bag *bags, int num_bags) {
    int i;
    srand(time(NULL));

    for (i = 0; i < num_bags; i++) {
        bags[i].id = generate_random_id();
        generate_city_names(bags[i].origin, bags[i].destination);
        printf("Bag %d from %s to %s\n", bags[i].id, bags[i].origin, bags[i].destination);
    }
}

int main() {
    int num_bags;
    Bag *bags;

    printf("Enter number of bags: ");
    scanf("%d", &num_bags);

    bags = (Bag *) malloc(num_bags * sizeof(Bag));

    handle_baggage(bags, num_bags);

    free(bags);

    return 0;
}