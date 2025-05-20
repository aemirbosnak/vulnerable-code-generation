//FormAI DATASET v1.0 Category: Online Examination System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the structure for the question */
struct Question {
    char question[250];
    char options[4][100];
    int correct_option;
};

/* Declare functions */
void displayWelcomeMessage();
void selectTestType();
int loadQuestions(struct Question questions[]);
void startQuiz(struct Question questions[], int num_questions);
int promptAnswer();
void displayResult(int score, int num_questions);

/* Main Function */
int main() {
    displayWelcomeMessage();
    selectTestType();
    return 0;
}

/* Functions */

void displayWelcomeMessage() {
    printf("Welcome to the Online Examination System!\n");
    printf("This program will quiz you on your knowledge in various fields.\n");
}

void selectTestType() {
    int choice;
    printf("\nChoose the type of test you would like take:\n");
    printf("1. Computer Science\n");
    printf("2. English Grammar\n");
    printf("3. General Knowledge\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: {
            struct Question cs_questions[10];
            int num_questions = loadQuestions(cs_questions);
            startQuiz(cs_questions, num_questions);
            break;
        }
        case 2: {
            struct Question eng_questions[10];
            int num_questions = loadQuestions(eng_questions);
            startQuiz(eng_questions, num_questions);
            break;
        }
        case 3: {
            struct Question gk_questions[10];
            int num_questions = loadQuestions(gk_questions);
            startQuiz(gk_questions, num_questions);
            break;
        }
        case 4: {
            printf("\nExiting program. Goodbye!\n");
            exit(0);
        }
        default: {
            printf("\nInvalid choice. Try again.\n");
            selectTestType();
        }
    }
}

int loadQuestions(struct Question questions[]) {
    FILE *question_file;
    int num_questions = 0;
    char file_name[20];
    int i;

    /* Get the file name based on the test type */
    printf("\nEnter the name of file containing questions: ");
    scanf("%s", file_name);
    question_file = fopen(file_name, "r");

    if (question_file == NULL) {
        printf("\nError opening file. Try Again.\n");
        selectTestType();
    }

    /* Loop through the file and divide questions, options and correct answer into the struct */
    while(fgets(questions[num_questions].question, 250, question_file) != NULL) {
        /* Check if the last character is a newline. if so, remove it */
        if (questions[num_questions].question[strlen(questions[num_questions].question)-1] == '\n') {
            questions[num_questions].question[strlen(questions[num_questions].question)-1] = '\0';
        }
        for(i = 0; i < 4; i++) {
            fgets(questions[num_questions].options[i], 100, question_file);
            if (questions[num_questions].options[i][strlen(questions[num_questions].options[i])-1] == '\n') {
                questions[num_questions].options[i][strlen(questions[num_questions].options[i])-1] = '\0';
            }
        }
        fscanf(question_file, "%d", &questions[num_questions].correct_option);
        num_questions++;
    }

    fclose(question_file);

    return num_questions;
}

void startQuiz(struct Question questions[], int num_questions) {
    int i, score = 0, answer;
    printf("\nThere are %d questions in this test.\n", num_questions);

    /* Loop through each question and prompt for answer */
    for(i = 0; i < num_questions; i++) {
        printf("\nQuestion %d. %s\n", i + 1, questions[i].question);
        printf("1. %s\n", questions[i].options[0]);
        printf("2. %s\n", questions[i].options[1]);
        printf("3. %s\n", questions[i].options[2]);
        printf("4. %s\n", questions[i].options[3]);
        answer = promptAnswer();
        if(answer == questions[i].correct_option) {
            score++;
        }
    }

    /* Display the final score */
    displayResult(score, num_questions);

    /* Ask if user wants to try again */
    printf("\nWould you like to try again? (1 for Yes, 0 for No): ");
    scanf("%d", &answer);
    if(answer == 1) {
        selectTestType();
    } else {
        printf("\nThank you for using the Online Examination System.\n Goodbye!\n");
        exit(0);
    }
}

int promptAnswer() {
    int answer;
    printf("\nEnter your answer (1-4): ");
    scanf("%d", &answer);
    if(answer > 4 || answer < 1) {
        printf("\nInvalid input. Try again.\n");
        promptAnswer();
    }
    return answer;
}

void displayResult(int score, int num_questions) {
    float percentage = ((float)score / (float)num_questions)*100;
    printf("\nYou got %d out of %d questions right.\n", score, num_questions);
    printf("Your percentage score is %.2f percent.\n", percentage);
    if(percentage >= 50) {
        printf("Congratulations! You passed the test.\n");
    } else {
        printf("Sorry! You failed the test.\n");
    }
}