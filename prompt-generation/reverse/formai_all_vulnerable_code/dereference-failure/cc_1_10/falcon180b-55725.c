//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* question;
    char* answer;
    int score;
} Question;

int compare(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

void shuffle(Question* questions, int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

int main() {
    int num_questions, score = 0;
    char input[100];

    // Load questions from a file
    FILE* fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open questions file.\n");
        return 1;
    }

    Question* questions = (Question*)malloc(sizeof(Question));
    while (fscanf(fp, "%s %s %d\n", questions->question, questions->answer, &questions->score)!= EOF) {
        questions = (Question*)realloc(questions, sizeof(Question) * ++num_questions);
    }
    fclose(fp);

    // Shuffle the questions
    shuffle(questions, num_questions);

    // Present the questions to the user
    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, questions[i].answer) == 0) {
            score += questions[i].score;
        }
    }

    // Print the final score
    printf("Your score is: %d out of %d\n", score, num_questions * questions[0].score);

    return 0;
}