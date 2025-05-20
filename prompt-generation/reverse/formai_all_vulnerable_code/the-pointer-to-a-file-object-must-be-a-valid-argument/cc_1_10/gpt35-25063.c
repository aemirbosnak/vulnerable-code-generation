//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define MAX_QUESTIONS 10

typedef struct {
    char name[3];
    char symbol[3];
    int atomic_number;
    char category[20];
    float atomic_mass;
} Element;

void initialize_elements(Element elements[NUM_ELEMENTS]);
void shuffle_array(int arr[], int size);
void instructions();
void print_question(Element element);
int get_user_input();
void handle_answer(int user_answer, Element current_element, int *num_correct);
void determine_grade(int num_correct);

int main() {
    Element elements[NUM_ELEMENTS]; // array of elements
    int question_nums[NUM_ELEMENTS]; // array to keep track of shuffled indices
    initialize_elements(elements); // fill elements array with data
    srand(time(0)); // seed random number generator

    instructions();

    shuffle_array(question_nums, NUM_ELEMENTS); // Shuffle the array of indices

    int num_correct = 0;
    int question_count = 0;
    for (int i = 0; i < NUM_ELEMENTS && question_count < MAX_QUESTIONS; i++) {
        Element current_element = elements[question_nums[i]];

        // Check if the current element has already been asked about
        if (current_element.name[0] == '\0') {
            continue;
        }

        print_question(current_element); // Display the current question
        int user_answer = get_user_input(); // Wait for user input
        handle_answer(user_answer, current_element, &num_correct);
        
        // Update the array of elements to mark the current element as already asked
        current_element.name[0] = '\0';

        question_count++;
    }

    determine_grade(num_correct);

    return 0;
}

// Fill the given array of elements with data from a file
void initialize_elements(Element elements[NUM_ELEMENTS]) {
    FILE *fp = fopen("periodic_table.txt", "r");

    char line[256];
    int index = 0;
    while (fgets(line, sizeof(line), fp)) {
        Element element;

        // Parse the elements data from each line
        char *token;
        int count = 0;
        token = strtok(line, ",");
        while (token != NULL) {
            switch (count) {
                case 0:
                    strcpy(element.name, token);
                    break;
                case 1:
                    strcpy(element.symbol, token);
                    break;
                case 2:
                    element.atomic_number = atoi(token);
                    break;
                case 3:
                    strcpy(element.category, token);
                    break;
                case 4:
                    element.atomic_mass = strtof(token, NULL);
                    break;
            }

            count++;
            token = strtok(NULL, ",");
        }

        // Add the current element to the array
        elements[index++] = element;
    }

    fclose(fp);
}

// Shuffle an array of indices
void shuffle_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Display instructions
void instructions() {
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You will be asked %d multiple choice questions about the elements of the periodic table.\n", MAX_QUESTIONS);
    printf("Enter the number of the answer you choose and press Enter.\n");
    printf("Good luck!\n\n");
}

// Display a new question
void print_question(Element element) {
    printf("What is the atomic number of %s?\n", element.symbol);
    printf("a) %d\n", element.atomic_number);
    printf("b) %d\n", element.atomic_number - 1);
    printf("c) %d\n", element.atomic_number + 1);
    printf("d) %d\n", element.atomic_number + 2);
}

// Wait for user input and return the integer value of the input
int get_user_input() {
    int user_input;
    scanf("%d", &user_input);
    return user_input;
}

// Handle the user's answer to the current question
void handle_answer(int user_answer, Element current_element, int *num_correct) {
    if (user_answer == 'a' - 'a' + 1) {
        printf("Correct! %s has an atomic number of %d.\n", current_element.name, current_element.atomic_number);
        (*num_correct)++;
    } else {
        printf("Incorrect. %s has an atomic number of %d.\n", current_element.name, current_element.atomic_number);
    }
    printf("\n");
}

// Determine the user's grade based on the number of questions answered correctly
void determine_grade(int num_correct) {
    printf("You answered %d out of %d questions correctly!\n", num_correct, MAX_QUESTIONS);
    float percentage = (float) num_correct / MAX_QUESTIONS * 100;

    if (percentage == 100) {
        printf("Congratulations, you got a perfect score!\n");
    } else if (percentage >= 90) {
        printf("Excellent work, you got an A!\n");
    } else if (percentage >= 80) {
        printf("Great job, you got a B!\n");
    } else if (percentage >= 70) {
        printf("Not bad, you got a C.\n");
    } else if (percentage >= 60) {
        printf("You got a D.\n");
    } else {
        printf("Sorry, you got an F.\n");
    }
}