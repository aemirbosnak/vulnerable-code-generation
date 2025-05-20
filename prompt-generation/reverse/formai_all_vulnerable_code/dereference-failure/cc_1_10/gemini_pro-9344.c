//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a question
typedef struct Question {
    char question[256];
    char options[4][64];
    int correct_answer;
} Question;

// Function to create a new question
Question* create_question(char *question, char *option1, char *option2, char *option3, char *option4, int correct_answer) {
    Question *q = malloc(sizeof(Question));
    strcpy(q->question, question);
    strcpy(q->options[0], option1);
    strcpy(q->options[1], option2);
    strcpy(q->options[2], option3);
    strcpy(q->options[3], option4);
    q->correct_answer = correct_answer;
    return q;
}

// Function to print a question
void print_question(Question *q) {
    printf("%s\n", q->question);
    for (int i = 0; i < 4; i++) {
        printf("\t%d. %s\n", i + 1, q->options[i]);
    }
}

// Function to check if an answer is correct
int is_correct_answer(Question *q, int answer) {
    return q->correct_answer == answer;
}

// Function to conduct an online examination
void conduct_examination() {
    // Create a list of questions
    Question *questions[] = {
        create_question("What is the capital of India?", "New Delhi", "Mumbai", "Kolkata", "Chennai", 1),
        create_question("Who is the current Prime Minister of India?", "Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee", 1),
        create_question("Which is the largest state in India?", "Rajasthan", "Madhya Pradesh", "Uttar Pradesh", "Maharashtra", 3),
        create_question("Which is the highest mountain in the world?", "Mount Everest", "K2", "Kangchenjunga", "Nanga Parbat", 1),
        create_question("Who invented the telephone?", "Alexander Graham Bell", "Thomas Edison", "Nikola Tesla", "Albert Einstein", 1)
    };

    // Get the number of questions
    int num_questions = sizeof(questions) / sizeof(questions[0]);

    // Initialize the score to 0
    int score = 0;

    // Iterate over the questions
    for (int i = 0; i < num_questions; i++) {
        // Print the question
        print_question(questions[i]);

        // Get the answer from the user
        int answer;
        printf("Enter your answer: ");
        scanf("%d", &answer);

        // Check if the answer is correct
        if (is_correct_answer(questions[i], answer)) {
            // Increment the score
            score++;
        }
    }

    // Print the score
    printf("Your score is: %d\n", score);
}

int main() {
    // Conduct the online examination
    conduct_examination();

    return 0;
}