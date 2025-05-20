//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent a case in the life of Mr. Sherlock Holmes
typedef struct {
    char *name;
    char *description;
    int urgency;
} Case;

// Function to create a new case
Case* create_case(const char *name, const char *description, int urgency) {
    Case *new_case = (Case *) malloc(sizeof(Case));
    if (new_case == NULL) {
        perror("Failed to allocate memory for new case");
        exit(EXIT_FAILURE);
    }

    new_case->name = (char *) malloc(strlen(name) + 1);
    if (new_case->name == NULL) {
        perror("Failed to allocate memory for case name");
        free(new_case);
        exit(EXIT_FAILURE);
    }
    strcpy(new_case->name, name);

    new_case->description = (char *) malloc(strlen(description) + 1);
    if (new_case->description == NULL) {
        perror("Failed to allocate memory for case description");
        free(new_case->name);
        free(new_case);
        exit(EXIT_FAILURE);
    }
    strcpy(new_case->description, description);
    
    new_case->urgency = urgency;
    
    return new_case;
}

// Function to display case details
void display_case(const Case *case_to_display) {
    if (case_to_display == NULL) return;
    printf("Case Name: %s\n", case_to_display->name);
    printf("Description: %s\n", case_to_display->description);
    printf("Urgency Level: %d\n\n", case_to_display->urgency);
}

// Function to free the allocated memory for a case
void free_case(Case *case_to_free) {
    if (case_to_free) {
        free(case_to_free->name);
        free(case_to_free->description);
        free(case_to_free);
    }
}

// Function to simulate investigating a batch of cases
void investigate_cases(int num_cases) {
    Case **case_array = (Case **) malloc(num_cases * sizeof(Case *));
    if (case_array == NULL) {
        perror("Failed to allocate memory for cases array");
        exit(EXIT_FAILURE);
    }
    
    // Sample case data
    const char *names[] = {"The Blue Carbuncle", "A Scandal in Bohemia", "The Hound of the Baskervilles"};
    const char *descriptions[] = {
        "A precious gem is stolen from a respectable man.",
        "A woman's cunning almost outsmarts Holmes himself.",
        "A supernatural hound haunts the Baskerville estate."
    };
    const int urgencies[] = {5, 8, 10};

    // Creating cases
    for (int i = 0; i < num_cases && i < 3; i++) {
        case_array[i] = create_case(names[i], descriptions[i], urgencies[i]);
    }
    
    // Display cases
    for (int i = 0; i < num_cases && i < 3; i++) {
        display_case(case_array[i]);
    }

    // Free allocated memories
    for (int i = 0; i < num_cases && i < 3; i++) {
        free_case(case_array[i]);
    }
    
    free(case_array);
}

int main() {
    printf("Welcome to the investigatory intriguing world of Sherlock Holmes!\n");
    int number_of_cases = 3; // Number of cases to investigate

    // Investigate the cases
    investigate_cases(number_of_cases);

    printf("Investigation complete. Until next time, Watson!\n");
    return 0;
}