//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Animal {
    char name[20];
    float weight;
    struct Animal *next;
} Animal;

void createAnimal(Animal **head, char *name, float weight) {
    Animal *newAnimal = (Animal *) malloc(sizeof(Animal));
    strcpy(newAnimal->name, name);
    newAnimal->weight = weight;
    newAnimal->next = *head;
    *head = newAnimal;
}

float calculateTotalWeight(Animal *head) {
    float totalWeight = 0;
    Animal *currentAnimal = head;
    while (currentAnimal != NULL) {
        totalWeight += currentAnimal->weight;
        currentAnimal = currentAnimal->next;
    }
    return totalWeight;
}

int main() {
    Animal *head = NULL;
    char animalNames[5][20] = {"Elephant", "Giraffe", "Rhinoceros", "Zebra", "Hippopotamus"};
    float animalWeights[5] = {5000.0, 1200.0, 5000.0, 600.0, 3000.0};

    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        int randomIndex = rand() % 5;
        createAnimal(&head, animalNames[randomIndex], animalWeights[randomIndex]);
    }

    printf("Animals in the list:\n");
    Animal *currentAnimal = head;
    while (currentAnimal != NULL) {
        printf("%s: %.2f kg\n", currentAnimal->name, currentAnimal->weight);
        currentAnimal = currentAnimal->next;
    }

    float totalWeight = calculateTotalWeight(head);
    printf("\nTotal weight of animals: %.2f kg\n", totalWeight);

    while (head != NULL) {
        Animal *tempAnimal = head;
        head = head->next;
        free(tempAnimal);
    }

    return 0;
}