//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CRYSTAL_POWERS 10

typedef struct CrystalPower {
    char name[20];
    int power_level;
    int element;
    struct CrystalPower* next;
} CrystalPower;

CrystalPower* createCrystalPower(char* name, int power_level, int element) {
    CrystalPower* new_power = malloc(sizeof(CrystalPower));
    strcpy(new_power->name, name);
    new_power->power_level = power_level;
    new_power->element = element;
    new_power->next = NULL;
    return new_power;
}

void printCrystalPower(CrystalPower* power) {
    printf("Name: %s, Power Level: %d, Element: %d\n", power->name, power->power_level, power->element);
}

int main() {
    srand(time(NULL));
    CrystalPower* head = NULL;

    // Create a bunch of crystal powers
    for (int i = 0; i < NUM_CRYSTAL_POWERS; i++) {
        char name[20];
        sprintf(name, "Crystal Power %d", i + 1);
        int power_level = rand() % 10 + 1;
        int element = rand() % 4 + 1;

        CrystalPower* new_power = createCrystalPower(name, power_level, element);
        if (head == NULL) {
            head = new_power;
        } else {
            new_power->next = head;
            head = new_power;
        }
    }

    // Print the crystal powers
    printCrystalPower(head);

    return 0;
}