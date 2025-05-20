//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    int age;
    float wealth;
} Villager;

void readVillagers(FILE *file, Villager *villagers, int *numVillagers) {
    fscanf(file, "%s %d %f", villagers[*numVillagers].name, &villagers[*numVillagers].age, &villagers[*numVillagers].wealth);
    (*numVillagers)++;
}

int main() {
    FILE *file;
    char filename[100] = "villagers.txt";
    Villager *villagers;
    int numVillagers = 0;

    // Open the file
    file = fopen(filename, "r");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    // Read the number of villagers from the file
    readVillagers(file, NULL, &numVillagers);

    // Allocate memory for the villagers array
    villagers = (Villager*) malloc(numVillagers * sizeof(Villager));

    // Re-read the file and store the villagers' data in the array
    rewind(file);
    for (int i = 0; i < numVillagers; i++) {
        readVillagers(file, &villagers[i], NULL);
    }

    // Print the wealthiest villager
    Villager wealthiestVillager = villagers[0];
    for (int i = 1; i < numVillagers; i++) {
        if (villagers[i].wealth > wealthiestVillager.wealth) {
            wealthiestVillager = villagers[i];
        }
    }

    printf("In the land of %s, the wealthiest villager is %s, with a wealth of %0.2f gold coins.\n", "Age of Chivalry", wealthiestVillager.name, wealthiestVillager.wealth);

    // Free the memory allocated for the villagers array
    free(villagers);

    // Close the file
    fclose(file);

    return 0;
}