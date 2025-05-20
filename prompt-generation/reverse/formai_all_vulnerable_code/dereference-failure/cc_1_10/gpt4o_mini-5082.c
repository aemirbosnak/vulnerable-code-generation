//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent an element
typedef struct {
    char name[20];
    char symbol[3];
    int atomic_number;
} Element;

// Function prototypes
void display_welcome();
void create_quiz(Element elements[], int num_elements);
Element *initialize_elements(int *num_elements);
void shuffle_elements(Element *elements, int num_elements);
void ask_question(Element element);
int get_user_answer(int correctAnswer, int maxOptions);
void display_result(int score, int totalQuestions);

int main() {
    srand(time(NULL)); // Seed random number generator

    int num_elements = 0;
    Element *elements = initialize_elements(&num_elements);

    display_welcome();
    create_quiz(elements, num_elements);

    free(elements);
    return 0;
}

// Function to display welcome message
void display_welcome() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Test your knowledge of chemical elements.\n");
    printf("Let's get started!\n");
}

// Initialize element data
Element *initialize_elements(int *num_elements) {
    *num_elements = 10; // For simplicity, we load only 10 elements
    Element *elements = (Element *)malloc(*num_elements * sizeof(Element));

    // Sample elements
    strcpy(elements[0].name, "Hydrogen"); strcpy(elements[0].symbol, "H"); elements[0].atomic_number = 1;
    strcpy(elements[1].name, "Helium"); strcpy(elements[1].symbol, "He"); elements[1].atomic_number = 2;
    strcpy(elements[2].name, "Lithium"); strcpy(elements[2].symbol, "Li"); elements[2].atomic_number = 3;
    strcpy(elements[3].name, "Beryllium"); strcpy(elements[3].symbol, "Be"); elements[3].atomic_number = 4;
    strcpy(elements[4].name, "Boron"); strcpy(elements[4].symbol, "B"); elements[4].atomic_number = 5;
    strcpy(elements[5].name, "Carbon"); strcpy(elements[5].symbol, "C"); elements[5].atomic_number = 6;
    strcpy(elements[6].name, "Nitrogen"); strcpy(elements[6].symbol, "N"); elements[6].atomic_number = 7;
    strcpy(elements[7].name, "Oxygen"); strcpy(elements[7].symbol, "O"); elements[7].atomic_number = 8;
    strcpy(elements[8].name, "Fluorine"); strcpy(elements[8].symbol, "F"); elements[8].atomic_number = 9;
    strcpy(elements[9].name, "Neon"); strcpy(elements[9].symbol, "Ne"); elements[9].atomic_number = 10;

    return elements;
}

// Create a quiz by shuffling elements and asking questions
void create_quiz(Element elements[], int num_elements) {
    int score = 0;
    int num_questions = 5; // Number of questions to ask
    if (num_questions > num_elements) num_questions = num_elements; // Limit to available elements

    shuffle_elements(elements, num_elements); // Shuffle the elements

    for (int i = 0; i < num_questions; i++) {
        ask_question(elements[i]);
        score += get_user_answer(elements[i].atomic_number, num_elements);
    }

    display_result(score, num_questions);
}

// Shuffle the elements for quiz randomness
void shuffle_elements(Element *elements, int num_elements) {
    for (int i = num_elements - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

// Ask a question about an element
void ask_question(Element element) {
    printf("\nWhat is the atomic number of %s (symbol: %s)?\n", element.name, element.symbol);
}

// Get the user's answer and return 1 if correct, 0 if incorrect
int get_user_answer(int correctAnswer, int maxOptions) {
    int answer;
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == correctAnswer) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect! The correct answer was %d.\n", correctAnswer);
        return 0;
    }
}

// Display the final result
void display_result(int score, int totalQuestions) {
    printf("\nYou scored %d out of %d.\n", score, totalQuestions);
    printf("Thank you for playing the Periodic Table Quiz!\n");
}