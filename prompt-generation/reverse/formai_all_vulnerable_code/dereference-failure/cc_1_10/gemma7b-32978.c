//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store information about a wizard
typedef struct Wizard {
    char name[20];
    int level;
    int experience;
    int gold;
    struct Wizard* next;
} Wizard;

// Function to create a new wizard
Wizard* createWizard(char* name, int level, int experience, int gold) {
    Wizard* newWizard = (Wizard*)malloc(sizeof(Wizard));
    strcpy(newWizard->name, name);
    newWizard->level = level;
    newWizard->experience = experience;
    newWizard->gold = gold;
    newWizard->next = NULL;
    return newWizard;
}

// Function to add a new wizard to the list
void addWizard(Wizard* head, char* name, int level, int experience, int gold) {
    Wizard* newWizard = createWizard(name, level, experience, gold);
    if (head == NULL) {
        head = newWizard;
    } else {
        head->next = newWizard;
        head = newWizard;
    }
}

// Function to print the list of wizards
void printWizards(Wizard* head) {
    while (head) {
        printf("%s, level %d, experience %d, gold %d\n", head->name, head->level, head->experience, head->gold);
        head = head->next;
    }
}

int main() {
    Wizard* head = NULL;
    addWizard(head, "Gandalf", 10, 100, 1000);
    addWizard(head, "Frodo", 8, 80, 800);
    addWizard(head, "Sam", 6, 60, 600);
    addWizard(head, "Merry", 4, 40, 400);
    addWizard(head, "Pippin", 2, 20, 200);

    printWizards(head);

    return 0;
}