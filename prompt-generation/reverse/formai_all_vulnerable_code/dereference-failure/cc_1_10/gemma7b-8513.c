//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medicine information
typedef struct Medicine {
    char name[50];
    char dosage[50];
    char frequency[50];
    char notes[50];
} Medicine;

// Define a function to search for a medicine
int searchMedicine(Medicine *medicines, int numMedics, char *name) {
    for (int i = 0; i < numMedics; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Define a function to add a medicine
int addMedicine(Medicine *medicines, int numMedics) {
    medicines = realloc(medicines, (numMedics + 1) * sizeof(Medicine));
    medicines[numMedics].name[0] = '\0';
    medicines[numMedics].dosage[0] = '\0';
    medicines[numMedics].frequency[0] = '\0';
    medicines[numMedics].notes[0] = '\0';
    numMedics++;
    return numMedics;
}

// Define a function to delete a medicine
int deleteMedicine(Medicine *medicines, int numMedics, char *name) {
    int index = searchMedicine(medicines, numMedics, name);
    if (index != -1) {
        for (int i = index; i < numMedics - 1; i++) {
            medicines[i] = medicines[i + 1];
        }
        numMedics--;
        return numMedics;
    }
    return -1;
}

int main() {
    // Create an array of medicines
    Medicine *medicines = NULL;
    int numMedics = 0;

    // Search for a medicine
    char *name = "Aspirin";
    int index = searchMedicine(medicines, numMedics, name);
    if (index != -1) {
        printf("Medicine name: %s\n", medicines[index].name);
        printf("Dosage: %s\n", medicines[index].dosage);
        printf("Frequency: %s\n", medicines[index].frequency);
        printf("Notes: %s\n", medicines[index].notes);
    } else {
        printf("Medicine not found.\n");
    }

    // Add a medicine
    name = "Tylenol";
    addMedicine(medicines, numMedics);
    printf("Number of medicines: %d\n", numMedics);

    // Delete a medicine
    name = "Tylenol";
    deleteMedicine(medicines, numMedics, name);
    printf("Number of medicines: %d\n", numMedics);

    return 0;
}