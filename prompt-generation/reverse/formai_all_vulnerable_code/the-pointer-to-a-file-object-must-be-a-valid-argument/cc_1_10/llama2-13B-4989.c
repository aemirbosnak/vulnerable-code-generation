//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ANSWERS 10

typedef struct {
    char *question;
    char *answer;
} question_t;

question_t questions[MAX_ANSWERS];
int current_question = 0;

void load_questions() {
    char filename[] = "questions.txt";
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        questions[current_question].question = line;
        current_question++;
    }
    fclose(file);
}

void print_question() {
    printf("%s\n", questions[current_question - 1].question);
}

int get_answer() {
    int answer;
    printf("Enter your answer: ");
    scanf("%d", &answer);
    return answer;
}

int check_answer(int answer) {
    int correct = 0;
    for (int i = 0; i < current_question; i++) {
        if (answer == questions[i].answer) {
            correct++;
        }
    }
    return correct;
}

int main() {
    srand(time(NULL));
    load_questions();

    for (int i = 0; i < 10; i++) {
        print_question();
        int answer = get_answer();
        int correct = check_answer(answer);
        printf("Correct: %d\n", correct);
        if (correct == 10) {
            break;
        }
    }

    return 0;
}