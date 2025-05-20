//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // Medieval Periodic Table Quiz

    char correct[1], answer[2], element[15], input[50];
    int i, j, k, correct_answers = 0, incorrect_answers = 0;

    printf("Welcome to the Medieval Periodic Table Quiz!\n\n");
    printf("You will be given 10 questions about the elements in the Medieval Periodic Table.\n");
    printf("Each question will have a multiple choice answer that you must choose from.\n");
    printf("Type the letter of the answer and hit enter.\n\n");

    // List of Elements

    char elements[10][15] = {
        "Iron",
        "Gold",
        "Silver",
        "Mercury",
        "Lead",
        "Sulfur",
        "Copper",
        "Tin",
        "Brass",
        "Bronze"
    };

    // List of Questions

    char questions[10][50] = {
        "What is the symbol for Iron?\nA) Fe\nB) Ir\nC) In\nD) I\n",
        "What is the symbol for Gold?\nA) Gd\nB) Go\nC) Au\nD) Ag\n",
        "What is the symbol for Silver?\nA) Sg\nB) Sv\nC) Si\nD) Ag\n",
        "What is the symbol for Mercury?\nA) Hg\nB) Me\nC) Mr\nD) Mg\n",
        "What is the symbol for Lead?\nA) Ld\nB) Le\nC) La\nD) Pb\n",
        "What is the symbol for Sulfur?\nA) Sl\nB) Su\nC) Sf\nD) S\n",
        "What is the symbol for Copper?\nA) Cu\nB) Cp\nC) Co\nD) Cr\n",
        "What is the symbol for Tin?\nA) Tn\nB) Ti\nC) Ta\nD) Sn\n",
        "What alloy is made of copper and zinc?\nA) Brass\nB) Bronze\nC) Pewter\nD) Iron\n",
        "What alloy is made of copper and tin?\nA) Brass\nB) Bronze\nC) Pewter\nD) Iron\n"
    };

    // List of Answers

    char answers[10][2] = {
        "A",
        "C",
        "D",
        "A",
        "D",
        "D",
        "A",
        "D",
        "A",
        "B"
    };

    // Loop through Questions

    for (i = 0; i < 10; i++) {
        printf("%s", questions[i]);
        scanf("%1s", answer); // Read 1 character for multiple choice answer
        strcpy(element, elements[i]); // Copy element name for future use
        strcpy(correct, answers[i]); // Copy correct answer for future use
        for (j = 0; j < 1; j++) {
            answer[j] = toupper(answer[j]); // Convert answer to uppercase
        }
        if (strcmp(answer, correct) == 0) { // Compare answer to correct answer
            printf("\nCorrect! %s is correct.\n\n", element);
            correct_answers++;
        }
        else {
            printf("\nIncorrect! %s is the correct answer.\n\n", correct);
            incorrect_answers++;
        }
    }

    // Display Results

    printf("You answered %d questions correctly and %d questions incorrectly.\n", correct_answers, incorrect_answers);
    if (correct_answers > 7) {
        printf("Congratulations! You know your Medieval Periodic Table!\n");
    }
    else {
        printf("Better luck next time! Keep studying the Medieval Periodic Table!\n");
    }

    return 0;
}