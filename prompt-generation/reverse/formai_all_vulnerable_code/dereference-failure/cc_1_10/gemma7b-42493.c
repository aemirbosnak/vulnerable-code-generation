//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Atom
{
    char name[20];
    int atomicNumber;
    float atomicMass;
    struct Atom* next;
} Atom;

Atom* createAtom(char* name, int atomicNumber, float atomicMass)
{
    Atom* newAtom = (Atom*)malloc(sizeof(Atom));
    strcpy(newAtom->name, name);
    newAtom->atomicNumber = atomicNumber;
    newAtom->atomicMass = atomicMass;
    newAtom->next = NULL;

    return newAtom;
}

void printAtom(Atom* atom)
{
    printf("%s (%d) - %.2f\n", atom->name, atom->atomicNumber, atom->atomicMass);
}

int main()
{
    Atom* pHead = NULL;

    // Create a few atoms
    Atom* hydrogen = createAtom("Hydrogen", 1, 1.008);
    Atom* helium = createAtom("Helium", 2, 4.0026);
    Atom* sodium = createAtom("Sodium", 11, 22.989);
    Atom* potassium = createAtom("Potassium", 19, 38.412);

    // Link the atoms together
    pHead = hydrogen;
    hydrogen->next = helium;
    helium->next = sodium;
    sodium->next = potassium;

    // Print the atoms
    printAtom(pHead);

    return 0;
}