//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sherlock's assistant, Dr. Watson
typedef struct {
    char *name;
    int age;
    char *occupation;
} Watson;

// A clue from a case
typedef struct {
    char *description;
    int weight; // Importance of the clue
} Clue;

// Sherlock's case file
typedef struct {
    char *case_name;
    Watson *assistant;
    Clue **clues;
    int num_clues;
} CaseFile;

// Function to initialize a Watson struct
Watson *init_watson(char *name, int age, char *occupation) {
    Watson *watson = malloc(sizeof(Watson));
    watson->name = strdup(name);
    watson->age = age;
    watson->occupation = strdup(occupation);
    return watson;
}

// Function to initialize a Clue struct
Clue *init_clue(char *description, int weight) {
    Clue *clue = malloc(sizeof(Clue));
    clue->description = strdup(description);
    clue->weight = weight;
    return clue;
}

// Function to initialize a CaseFile struct
CaseFile *init_case_file(char *case_name, Watson *assistant, Clue **clues, int num_clues) {
    CaseFile *case_file = malloc(sizeof(CaseFile));
    case_file->case_name = strdup(case_name);
    case_file->assistant = assistant;
    case_file->clues = clues;
    case_file->num_clues = num_clues;
    return case_file;
}

// Function to print a Watson struct
void print_watson(Watson *watson) {
    printf("Name: %s\n", watson->name);
    printf("Age: %d\n", watson->age);
    printf("Occupation: %s\n", watson->occupation);
}

// Function to print a Clue struct
void print_clue(Clue *clue) {
    printf("Description: %s\n", clue->description);
    printf("Weight: %d\n", clue->weight);
}

// Function to print a CaseFile struct
void print_case_file(CaseFile *case_file) {
    printf("Case Name: %s\n", case_file->case_name);
    printf("Assistant:\n");
    print_watson(case_file->assistant);
    printf("Clues:\n");
    for (int i = 0; i < case_file->num_clues; i++) {
        print_clue(case_file->clues[i]);
    }
}

// Main function
int main() {
    // Create an instance of Dr. Watson
    Watson *watson = init_watson("John Watson", 35, "Doctor");

    // Create an array of clues
    Clue *clues[] = {
        init_clue("A bloody fingerprint", 5),
        init_clue("A torn piece of cloth", 3),
        init_clue("A footprint in the mud", 4),
    };

    // Create a case file
    CaseFile *case_file = init_case_file(
        "The Case of the Purloined Letter",
        watson,
        clues,
        3);

    // Print the case file
    print_case_file(case_file);

    // Free the memory allocated for the case file
    free(case_file->case_name);
    free(case_file->assistant);
    for (int i = 0; i < case_file->num_clues; i++) {
        free(case_file->clues[i]->description);
        free(case_file->clues[i]);
    }
    free(case_file);

    return 0;
}