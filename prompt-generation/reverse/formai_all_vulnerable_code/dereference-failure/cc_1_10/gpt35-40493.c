//FormAI DATASET v1.0 Category: Online Examination System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for each question, including the question, options, and answer
typedef struct {
    char question[100];
    char options[4][50];
    int answer;
} Question;

// Define the structure for the exam, including the number of questions, the questions themselves, and the score
typedef struct {
    int num_questions;
    Question *questions;
    int score;
} Exam;

// Function to create a new question
Question create_question(char *question_text, char *option1, char *option2, char *option3, char *option4, int answer) {
    Question question;
    strcpy(question.question, question_text);
    strcpy(question.options[0], option1);
    strcpy(question.options[1], option2);
    strcpy(question.options[2], option3);
    strcpy(question.options[3], option4);
    question.answer = answer;
    return question;
}

// Function to create a new exam
Exam create_exam(int num_questions) {
    Exam exam;
    exam.num_questions = num_questions;
    exam.questions = (Question*) malloc(num_questions * sizeof(Question));
    exam.score = 0;
    return exam;
}

// Function to delete an exam
void delete_exam(Exam exam) {
    free(exam.questions);
}

// Function to take an exam (display questions, get answers, and calculate score)
void take_exam(Exam exam) {
    printf("-----Exam Started-----\n");
    int i, chosen_answer;
    for(i = 0; i < exam.num_questions; i++) {
        printf("Question %d: %s?\n", i+1, exam.questions[i].question);
        printf("    A. %s\n", exam.questions[i].options[0]);
        printf("    B. %s\n", exam.questions[i].options[1]);
        printf("    C. %s\n", exam.questions[i].options[2]);
        printf("    D. %s\n", exam.questions[i].options[3]);
        printf("Enter your chosen answer (A=1, B=2, C=3, D=4): ");
        scanf("%d", &chosen_answer);
        if(chosen_answer == exam.questions[i].answer) {
            exam.score++;
        }
    }
    printf("-----Exam Ended-----\n");
    printf("Your score: %d/%d\n", exam.score, exam.num_questions);
}

int main() {
    // Create a new exam with 3 questions
    Exam exam = create_exam(3);

    // Add questions to the exam
    exam.questions[0] = create_question("What is the capital of France", "Paris", "London", "Tokyo", "New York", 1);
    exam.questions[1] = create_question("What is the biggest animal in the world", "Elephant", "Blue Whale", "Giraffe", "Hippo", 2);
    exam.questions[2] = create_question("What year did World War 2 end", "1939", "1941", "1945", "1950", 3);

    // Take the exam and display the score
    take_exam(exam);

    // Delete the exam to free up memory
    delete_exam(exam);

    return 0;
}