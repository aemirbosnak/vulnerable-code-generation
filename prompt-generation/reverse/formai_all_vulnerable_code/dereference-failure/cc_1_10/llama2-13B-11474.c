//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to represent a molecule
struct molecule {
    char *name;
    int num_atoms;
    struct atom *atoms;
};

// Define a structure to represent an atom
struct atom {
    char *element;
    int atomic_number;
    int x;
    int y;
    int z;
};

// Define a function to create a new molecule
struct molecule *create_molecule(char *name, int num_atoms) {
    struct molecule *molecule = malloc(sizeof(struct molecule));
    molecule->name = strdup(name);
    molecule->num_atoms = num_atoms;
    molecule->atoms = malloc(num_atoms * sizeof(struct atom));
    return molecule;
}

// Define a function to create a new atom
struct atom *create_atom(char *element, int atomic_number, int x, int y, int z) {
    struct atom *atom = malloc(sizeof(struct atom));
    atom->element = strdup(element);
    atom->atomic_number = atomic_number;
    atom->x = x;
    atom->y = y;
    atom->z = z;
    return atom;
}

// Define a function to add an atom to a molecule
void add_atom_to_molecule(struct molecule *molecule, struct atom *atom) {
    molecule->atoms[molecule->num_atoms] = *atom;
    molecule->num_atoms++;
}

// Define a function to print a molecule
void print_molecule(struct molecule *molecule) {
    printf("Molecule: %s\n", molecule->name);
    for (int i = 0; i < molecule->num_atoms; i++) {
        printf("Atom %d: %s (%d, %d, %d)\n", i, molecule->atoms[i].element, molecule->atoms[i].atomic_number, molecule->atoms[i].x, molecule->atoms[i].y, molecule->atoms[i].z);
    }
}

// Define a function to free memory
void free_memory(struct molecule **molecules, int num_molecules) {
    for (int i = 0; i < num_molecules; i++) {
        free(molecules[i]->name);
        free(molecules[i]->atoms);
    }
    free(molecules);
}

int main() {
    // Create a molecule
    struct molecule *molecule = create_molecule("Water", 3);

    // Create atoms and add them to the molecule
    struct atom *hydrogen = create_atom("Hydrogen", 1, 0, 0, 0);
    add_atom_to_molecule(molecule, hydrogen);

    struct atom *oxygen = create_atom("Oxygen", 8, 0, 0, 1);
    add_atom_to_molecule(molecule, oxygen);

    struct atom *hydrogen2 = create_atom("Hydrogen", 1, 0, 1, 0);
    add_atom_to_molecule(molecule, hydrogen2);

    // Print the molecule
    print_molecule(molecule);

    // Free memory
    free_memory(&molecule, 1);

    return 0;
}