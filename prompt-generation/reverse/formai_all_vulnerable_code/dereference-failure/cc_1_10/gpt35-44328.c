//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of questions in the quiz
#define MAX_QUESTIONS 10

// Define the maximum number of options for each question
#define MAX_OPTIONS 4

// Define the maximum length of each element's symbol
#define MAX_SYMBOL_LENGTH 3

// Define the structure for each question
typedef struct {
    char symbol[MAX_SYMBOL_LENGTH];
    char options[MAX_OPTIONS][20];
    char correctOption;
} Question;

// Declare an array of questions for the quiz
Question quizQuestions[MAX_QUESTIONS];

// Function to generate a random number within a range
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random question
Question generateQuestion() {
    // Define an array of elements for the quiz
    char elements[118][MAX_SYMBOL_LENGTH] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

    // Define an array of options for each question
    char options[MAX_OPTIONS][20];

    // Select a random element for the question
    int elementIndex = getRandomNumber(0, 117);
    strcpy(quizQuestions[elementIndex].symbol, elements[elementIndex]);

    // Generate random options for the question
    int correctOptionIndex = getRandomNumber(0, 3);
    quizQuestions[elementIndex].correctOption = correctOptionIndex + 'A';
    for (int i = 0; i < MAX_OPTIONS; i++) {
        if (i == correctOptionIndex) {
            sprintf(options[i], "%s", elements[elementIndex]);
        } else {
            int randomIndex = getRandomNumber(0, 117);
            sprintf(options[i], "%s", elements[randomIndex]);
        }
    }

    // Return the generated question
    return quizQuestions[elementIndex];
}

// Function to display a question and get user's answer
char displayQuestion(Question question) {
    printf("\nWhat is the symbol for %s?\n", question.options[0]);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%c) %s\n", i + 'A', question.options[i]);
    }
    printf("Enter your answer (A/B/C/D): ");
    char answer;
    scanf(" %c", &answer);
    return answer;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the quiz questions
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        quizQuestions[i] = generateQuestion();
    }

    // Display the quiz questions and get the user's answers
    int correctAnswers = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        char answer = displayQuestion(quizQuestions[i]);
        if (answer == quizQuestions[i].correctOption) {
            printf("\nCorrect!\n");
            correctAnswers++;
        } else {
            printf("\nIncorrect! The correct answer was %c) %s\n", quizQuestions[i].correctOption, quizQuestions[i].symbol);
        }
    }

    // Display the quiz result
    printf("\nYou answered %d out of %d questions correctly. Your score is %.2f%%.\n", correctAnswers, MAX_QUESTIONS, (float)correctAnswers / MAX_QUESTIONS * 100);

    return 0;
}