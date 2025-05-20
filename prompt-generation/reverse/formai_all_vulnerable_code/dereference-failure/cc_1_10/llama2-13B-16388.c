//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a struct to represent a molecule
struct molecule {
    char *name;
    int num_atoms;
    int *atom_ids;
};

// Define a function to allocate memory for a molecule
struct molecule *molecule_alloc(int num_atoms) {
    struct molecule *mol = malloc(sizeof(struct molecule));
    mol->num_atoms = num_atoms;
    mol->atom_ids = malloc(num_atoms * sizeof(int));
    return mol;
}

// Define a function to deallocate memory for a molecule
void molecule_free(struct molecule *mol) {
    free(mol->atom_ids);
    free(mol);
}

// Define a function to print a molecule
void print_molecule(struct molecule *mol) {
    printf("Molecule: %s\n", mol->name);
    for (int i = 0; i < mol->num_atoms; i++) {
        printf("Atom %d: %d\n", i, mol->atom_ids[i]);
    }
}

int main() {
    // Create a molecule with 5 atoms
    struct molecule *mol = molecule_alloc(5);
    mol->name = "C2H4";
    mol->atom_ids = malloc(5 * sizeof(int));
    mol->atom_ids[0] = 1;
    mol->atom_ids[1] = 2;
    mol->atom_ids[2] = 3;
    mol->atom_ids[3] = 4;
    mol->atom_ids[4] = 5;

    // Print the molecule
    print_molecule(mol);

    // Allocate memory for another molecule with 7 atoms
    struct molecule *mol2 = molecule_alloc(7);
    mol2->name = "C3H6O";
    mol2->atom_ids = malloc(7 * sizeof(int));
    mol2->atom_ids[0] = 1;
    mol2->atom_ids[1] = 2;
    mol2->atom_ids[2] = 3;
    mol2->atom_ids[3] = 4;
    mol2->atom_ids[4] = 5;
    mol2->atom_ids[5] = 6;
    mol2->atom_ids[6] = 7;

    // Print the second molecule
    print_molecule(mol2);

    // Free the memory for the first molecule
    molecule_free(mol);

    // Print the second molecule again
    print_molecule(mol2);

    return 0;
}