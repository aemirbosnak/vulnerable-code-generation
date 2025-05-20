//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum number of elements in periodic table
#define MAX_ELEMENTS 118

// Define maximum length of element names
#define MAX_NAME_LENGTH 15

// Define structure for each element in the periodic table
typedef struct {
    int atomic_number;
    char symbol[3];
    char name[MAX_NAME_LENGTH];
    float atomic_mass;
} element;

// Declare function prototypes
void print_table();
void populate_table();
void shuffle_elements();
void quiz();

// Declare global variables
element table[MAX_ELEMENTS];
int num_elements = 0;

int main() {
    // Populate periodic table and shuffle elements
    populate_table();
    shuffle_elements();
    
    // Display periodic table and prompt user for quiz
    printf("Welcome to the periodic table quiz!\n\n");
    printf("Here is the periodic table to help you get started:\n\n");
    print_table();
    printf("\nPress any key to start the quiz...");
    getchar();
    quiz();
    
    return 0;
}

// Populate periodic table array with elements
void populate_table() {
    FILE* fp;
    char line[100];
    fp = fopen("periodic_table.csv", "r");
    
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    
    while (fgets(line, 100, fp) != NULL) {
        char* token;
        token = strtok(line, ",");
        
        // Create new element with parsed data
        element new_element;
        new_element.atomic_number = atoi(token);
        token = strtok(NULL, ",");
        strcpy(new_element.symbol, token);
        token = strtok(NULL, ",");
        strcpy(new_element.name, token);
        token = strtok(NULL, ",");
        new_element.atomic_mass = atof(token);
        
        // Add new element to periodic table
        table[num_elements] = new_element;
        num_elements++;
    }
    
    fclose(fp);
}

// Print periodic table to console
void print_table() {
    for (int i = 0; i < num_elements; i++) {
        element el = table[i];
        printf("%-3s %-15s %6.4f\n", el.symbol, el.name, el.atomic_mass);
    }
}

// Shuffle elements in periodic table
void shuffle_elements() {
    srand(time(NULL));
  
    for (int i = num_elements - 1; i > 0; i--) {
        // Generate random index from 0 to i
        int j = rand() % (i + 1);
        
        // Swap elements
        element temp = table[i];
        table[i] = table[j];
        table[j] = temp;
    }
}

// Prompt user with periodic table questions
void quiz() {
    int score = 0;
    
    for (int i = 0; i < num_elements; i++) {
        element el = table[i];
        printf("\nWhat is the atomic number of %s?\n", el.name);
        int answer;
        scanf("%d", &answer);
        
        if (answer == el.atomic_number) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Incorrect. The correct answer is %d.\n", el.atomic_number);
        }
    }
    
    printf("\nYou scored %d out of %d.\n", score, num_elements);
    printf("Thanks for playing!\n");
}