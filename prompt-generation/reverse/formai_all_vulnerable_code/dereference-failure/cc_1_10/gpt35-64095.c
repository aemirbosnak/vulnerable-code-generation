//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_NAME_LENGTH 50
#define MAX_ELEMENTS 118

// Define structure for an element
struct element {
    int atomic_number;
    char symbol[3];
    char name[MAX_NAME_LENGTH];
    float atomic_weight;
    int period;
};

// Define function prototypes
void initialize_elements(struct element[]);
int get_user_choice();
void print_menu();
void print_element(struct element);
void search_by_atomic_number(struct element[]);
void search_by_symbol(struct element[]);
void search_by_name(struct element[]);
void search_by_period(struct element[]);
void search_by_property(struct element[]);
void exit_program();

int main() {
    // Initialize array of elements
    struct element elements[MAX_ELEMENTS];
    initialize_elements(elements);
    
    // User interface loop
    int choice;
    do {
        // Print menu and get user choice
        print_menu();
        choice = get_user_choice();
        
        // Execute chosen action
        switch (choice) {
            case 1:
                search_by_atomic_number(elements);
                break;
            case 2:
                search_by_symbol(elements);
                break;
            case 3:
                search_by_name(elements);
                break;
            case 4:
                search_by_period(elements);
                break;
            case 5:
                search_by_property(elements);
                break;
            case 6:
                exit_program();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        // Wait for user input to continue
        printf("Press enter to continue...");
        getchar();
    } while (choice != 6);
    
    return 0;
}

// Initialize array of elements
void initialize_elements(struct element elements[]) {
    // Read element data from file
    FILE *fp = fopen("periodic_table.csv", "r");
    if (fp == NULL) {
        printf("Error: failed to read element data.\n");
        exit(1);
    }
    
    // Parse file and fill array of elements
    char buffer[1024];
    fgets(buffer, sizeof(buffer), fp); // Skip first line (header)
    int i = 0;
    while (fgets(buffer, sizeof(buffer), fp)) {
        char *token = strtok(buffer, ",");
        elements[i].atomic_number = atoi(token);
        token = strtok(NULL, ",");
        strncpy(elements[i].symbol, token, 3);
        token = strtok(NULL, ",");
        strncpy(elements[i].name, token, MAX_NAME_LENGTH);
        token = strtok(NULL, ",");
        elements[i].atomic_weight = atof(token);
        token = strtok(NULL, ",");
        elements[i].period = atoi(token);
        i++;
    }
    
    fclose(fp);
}

// Get user choice from menu
int get_user_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume new line character from input buffer
    return choice;
}

// Print menu
void print_menu() {
    printf("\n");
    printf("C PERIODIC TABLE QUIZ\n");
    printf("1. Search by Atomic Number\n");
    printf("2. Search by Symbol\n");
    printf("3. Search by Name\n");
    printf("4. Search by Period\n");
    printf("5. Search by Property\n");
    printf("6. Exit\n");
}

// Print details of an element
void print_element(struct element e) {
    printf("\n");
    printf("Atomic Number: %d\n", e.atomic_number);
    printf("Symbol: %s\n", e.symbol);
    printf("Name: %s\n", e.name);
    printf("Atomic Weight: %.4f\n", e.atomic_weight);
    printf("Period: %d\n", e.period);
}

// Search for an element by atomic number
void search_by_atomic_number(struct element elements[]) {
    int atomic_number;
    printf("Enter atomic number: ");
    scanf("%d", &atomic_number);
    
    // Find element with matching atomic number
    int i;
    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].atomic_number == atomic_number) {
            print_element(elements[i]);
            return;
        }
    }
    
    // Element not found
    printf("No element found with atomic number %d.\n", atomic_number);
}

// Search for an element by symbol
void search_by_symbol(struct element elements[]) {
    char symbol[3];
    printf("Enter symbol: ");
    scanf("%s", symbol);
    
    // Find element with matching symbol
    int i;
    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (strcmp(elements[i].symbol, symbol) == 0) {
            print_element(elements[i]);
            return;
        }
    }
    
    // Element not found
    printf("No element found with symbol %s.\n", symbol);
}

// Search for an element by name
void search_by_name(struct element elements[]) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name: ");
    scanf("%s", name);
    
    // Find element with matching name
    int i;
    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (strcmp(elements[i].name, name) == 0) {
            print_element(elements[i]);
            return;
        }
    }
    
    // Element not found
    printf("No element found with name %s.\n", name);
}

// Search for elements by period
void search_by_period(struct element elements[]) {
    int period;
    printf("Enter period: ");
    scanf("%d", &period);
    
    // Print elements in specified period
    int i;
    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].period == period) {
            print_element(elements[i]);
        }
    }
}

// Search for elements by property
void search_by_property(struct element elements[]) {
    printf("Sorry, function not yet implemented.\n");
}

// Exit program
void exit_program() {
    printf("Goodbye!\n");
    exit(0);
}