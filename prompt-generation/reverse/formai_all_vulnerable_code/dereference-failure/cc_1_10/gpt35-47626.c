//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function declarations */
void get_user_input(int *num_questions, int *difficulty, char *avoids[]);
int ask_question(int num_questions, int difficulty, char *avoids[], int question_num);
void parse_input(char *input_str, int *input_arr);

/* Global constants */
const char ELEMENTS[118][3] = {
    "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
    "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
    "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
    "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
    "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
    "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
    "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
    "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
    "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
    "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
    "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
};

const int MAX_QUESTION_LENGTH = 50;

/* Main function */
int main(void) {
    int num_questions, difficulty;
    char avoid_str[MAX_QUESTION_LENGTH];
    char *avoids[118];
    int num_avoids = 0;
    int score = 0;

    /* Get user input */
    get_user_input(&num_questions, &difficulty, avoid_str);

    /* Parse avoid string */
    if (strlen(avoid_str) > 0) {
        char *token = strtok(avoid_str, ",");
        while (token != NULL && num_avoids < 118) {
            avoids[num_avoids] = token;
            num_avoids++;
            token = strtok(NULL, ",");
        }
    }

    /* Ask the questions */
    for (int i = 1; i <= num_questions; i++) {
        score += ask_question(num_questions, difficulty, avoids, i);
    }

    /* Calculate and output score */
    float percent_correct = ((float) score / num_questions) * 100.00;
    printf("You got %d out of %d questions right (%0.2f%%).\n", score, num_questions, percent_correct);

    return 0;
}

/* Function to get user input */
void get_user_input(int *num_questions, int *difficulty, char *avoids[]) {
    char input_str[MAX_QUESTION_LENGTH];
    int input_arr[2];
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? (1-30): ");
    fgets(input_str, MAX_QUESTION_LENGTH, stdin);
    parse_input(input_str, input_arr);
    *num_questions = input_arr[0];
    printf("What difficulty would you like? (1=easy, 2=medium, 3=hard): ");
    fgets(input_str, MAX_QUESTION_LENGTH, stdin);
    parse_input(input_str, input_arr);
    *difficulty = input_arr[0];
    printf("Which elements would you like to avoid? (comma-separated list, or leave blank): ");
    fgets(avoids[0], MAX_QUESTION_LENGTH, stdin);
    strtok(avoids[0], "\n");
}

/* Function to ask a single question */
int ask_question(int num_questions, int difficulty, char *avoids[], int question_num) {
    /* Generate random element */
    int element_num;
    do {
        element_num = rand() % 118;
    } while (element_num > 0 && element_num < 3);
    char *element = ELEMENTS[element_num];

    /* Create question string */
    char question_str[MAX_QUESTION_LENGTH];
    char input_str[MAX_QUESTION_LENGTH];
    snprintf(question_str, MAX_QUESTION_LENGTH, "Question #%d (out of %d): What is the symbol of %s?\n", question_num, num_questions, element);

    /* Get user input */
    printf("%s", question_str);
    fgets(input_str, MAX_QUESTION_LENGTH, stdin);
    strtok(input_str, "\n");

    /* Check if answer is correct */
    for (int i = 0; i < strlen(input_str); i++) {
        input_str[i] = toupper(input_str[i]);
    }
    if (strcmp(input_str, element) == 0) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect. The correct answer is %s.\n", element);
        return 0;
    }
}

/* Function to parse input string into an array of integers */
void parse_input(char *input_str, int *input_arr) {
    char *end_ptr;
    int i = 0;
    do {
        input_arr[i] = strtol(input_str, &end_ptr, 10);
        i++;
        input_str = end_ptr;
    } while (*end_ptr != '\n' && i < 2);
}