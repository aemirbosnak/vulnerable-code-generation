//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

struct Element {
    char name[20];
    char symbol[3];
    int atomic_number;
    char category[10];
    double atomic_mass;
};

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void print_header() {
    printf("*************************\n");
    printf("*   C Periodic Table    *\n");
    printf("*************************\n\n");
}

void print_element(struct Element element) {
    printf("Name: %s\n", element.name);
    printf("Symbol: %s\n", element.symbol);
    printf("Atomic Number: %d\n", element.atomic_number);
    printf("Category: %s\n", element.category);
    printf("Atomic Mass: %.4f\n\n", element.atomic_mass);
}

void print_elements(struct Element elements[]) {
    for(int i=0; i<118; i++) {
        printf("%d. %s\n", i+1, elements[i].name);
    }
}

void shuffle(int arr[], int n) {
    srand(time(NULL));
    for(int i=n-1; i>0; i--) {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quiz(struct Element elements[]) {
    printf("Let's start the quiz!\n");
    printf("---------------------\n");
    int num_questions;
    do {
        printf("How many questions would you like to answer? (1-10)\n");
        scanf("%d", &num_questions);
    } while(num_questions < 1 || num_questions > 10);
    
    int question_numbers[num_questions];
    for(int i=0; i<num_questions; i++) {
        question_numbers[i] = i;
    }
    shuffle(question_numbers, num_questions);
    
    int correct_answers = 0;
    for(int i=0; i<num_questions; i++) {
        printf("\nQuestion %d:\n", i+1);
        int atomic_number = elements[question_numbers[i]].atomic_number;
        char element_name[20];
        printf("What is the symbol of the element with atomic number %d?\n", atomic_number);
        scanf("%s", element_name);
        clear_input_buffer();
        for(int j=0; element_name[j]; j++) {
            element_name[j] = toupper(element_name[j]);
        }
        if(strcmp(element_name, elements[atomic_number-1].symbol) == 0) {
            printf("That's correct!\n");
            correct_answers++;
        } else {
            printf("Sorry, the correct answer is %s.\n", elements[atomic_number-1].symbol);
        }
    }
    printf("\nThank you for playing! You got %d/%d correct answers\n\n", correct_answers, num_questions);
}

int main() {
    print_header();
    
    struct Element elements[118];
    FILE* file = fopen("elements.txt", "r");
    if(file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }
    
    int i;
    char buf[100];
    for(i=0; fgets(buf, 100, file); i++) {
        char* ptr = strtok(buf, ",");
        strcpy(elements[i].name, ptr);
        ptr = strtok(NULL, ",");
        strcpy(elements[i].symbol, ptr);
        ptr = strtok(NULL, ",");
        elements[i].atomic_number = atoi(ptr);
        ptr = strtok(NULL, ",");
        strcpy(elements[i].category, ptr);
        ptr = strtok(NULL, ",");
        elements[i].atomic_mass = atof(ptr);
    }
    fclose(file);
    
    int choice;
    do {
        printf("What would you like to do?\n");
        printf("1. View all elements\n");
        printf("2. Start a quiz\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\n");
                print_elements(elements);
                printf("\n");
                break;
            case 2:
                printf("\n");
                quiz(elements);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);
    
    return 0;
}