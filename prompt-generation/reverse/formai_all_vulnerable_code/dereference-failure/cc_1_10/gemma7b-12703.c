//Gemma-7B DATASET v1.0 Category: Table Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the Romeo and Juliet family members
struct family {
    char name[20];
    int strength;
    int loyalty;
    struct family *next;
};

// Create a linked list of family members
struct family *head = NULL;

// Function to add a family member to the list
void addFamilyMember(char *name, int strength, int loyalty) {
    struct family *newMember = malloc(sizeof(struct family));
    strcpy(newMember->name, name);
    newMember->strength = strength;
    newMember->loyalty = loyalty;
    newMember->next = NULL;

    if (head == NULL) {
        head = newMember;
    } else {
        struct family *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newMember;
    }
}

// Function to simulate a fight between two family members
int fight(struct family *member1, struct family *member2) {
    int strength1 = member1->strength;
    int strength2 = member2->strength;
    int loyalty1 = member1->loyalty;
    int loyalty2 = member2->loyalty;

    // Calculate the damage dealt by each member
    int damage1 = strength1 - loyalty2;
    int damage2 = strength2 - loyalty1;

    // If the damage dealt by member1 is greater than the damage dealt by member2,
    // member2 is defeated
    if (damage1 > damage2) {
        return 1;
    }

    // If the damage dealt by member2 is greater than the damage dealt by member1,
    // member1 is defeated
    else if (damage2 > damage1) {
        return 2;
    }

    // If the damage dealt by both members is equal, the fight continues
    else {
        return 0;
    }
}

int main() {
    // Add family members to the list
    addFamilyMember("Romeo", 8, 6);
    addFamilyMember("Juliet", 7, 5);
    addFamilyMember("Benvolio", 9, 7);
    addFamilyMember("Tybalt", 10, 8);
    addFamilyMember(" Mercutio", 8, 6);

    // Simulate a fight between Romeo and Tybalt
    int result = fight(head->next, head->next->next);

    // Print the result of the fight
    switch (result) {
        case 1:
            printf("Tybalt has been defeated.\n");
            break;
        case 2:
            printf("Romeo has been defeated.\n");
            break;
        case 0:
            printf("The fight continues.\n");
            break;
    }

    return 0;
}