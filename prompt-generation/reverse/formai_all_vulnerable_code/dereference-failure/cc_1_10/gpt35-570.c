//FormAI DATASET v1.0 Category: Online Examination System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_QUESTION_LEN 100
#define MAX_CHOICES 4
#define MAX_CHOICE_LEN 50
#define MAX_STUDENTS 100

typedef struct {
    char question[MAX_QUESTION_LEN];
    char choices[MAX_CHOICES][MAX_CHOICE_LEN];
    int answer;
} Question;

typedef struct {
    char name[50];
    int score;
    int answers[MAX_QUESTIONS];
} Student;

void display_menu() {
    printf("ONLINE EXAMINATION SYSTEM\n");
    printf("-------------------------\n");
    printf("1. Take Exam\n");
    printf("2. Add Questions\n");
    printf("3. List Questions\n");
    printf("4. Exit\n");
}

int load_questions(Question *questions[]) {
    FILE *fp = fopen("questions.dat", "rb");
    if (fp == NULL)
        return 0;

    int count;
    fread(&count, sizeof(int), 1, fp);

    for (int i = 0; i < count; i++) {
        questions[i] = calloc(1, sizeof(Question));
        fread(questions[i], sizeof(Question), 1, fp);
    }

    fclose(fp);
    return count;
}

void save_questions(Question *questions[], int count) {
    FILE *fp = fopen("questions.dat", "wb");
    if (fp == NULL) {
        printf("Error: Unable to save questions\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);

    for (int i = 0; i < count; i++)
        fwrite(questions[i], sizeof(Question), 1, fp);

    fclose(fp);
}

void list_questions(Question *questions[], int count) {
    printf("QUESTION LIST\n");
    printf("-------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d) %s\n", i+1, questions[i]->question);
        for (int j = 0; j < 4; j++)
            printf("    %c) %s\n", 'A'+j, questions[i]->choices[j]);
    }
}

void add_question(Question *questions[], int *count) {
    if (*count >= MAX_QUESTIONS) {
        printf("Error: Maximum questions reached\n");
        return;
    }

    Question *q = calloc(1, sizeof(Question));

    printf("Enter question: ");
    fgets(q->question, MAX_QUESTION_LEN, stdin);
    q->question[strcspn(q->question, "\n")] = 0;

    printf("Enter choices:\n");
    for (int i = 0; i < 4; i++) {
        printf("%c) ", 'A'+i);
        fgets(q->choices[i], MAX_CHOICE_LEN, stdin);
        q->choices[i][strcspn(q->choices[i], "\n")] = 0;
    }

    printf("Enter answer (A,B,C or D): ");
    char ans;
    scanf(" %c", &ans);
    q->answer = ans - 'A';

    questions[*count] = q;
    (*count)++;

    printf("Question saved!\n");
}

void take_exam(Question *questions[], int count) {
    Student student;
    printf("Enter your name: ");
    fgets(student.name, 50, stdin);
    student.name[strcspn(student.name, "\n")] = 0;

    int score = 0;
    for (int i = 0; i < count; i++) {
        printf("%d) %s\n", i+1, questions[i]->question);
        for (int j = 0; j < 4; j++)
            printf("    %c) %s\n", 'A'+j, questions[i]->choices[j]);

        char ans;
        printf("Your answer (A,B,C or D): ");
        scanf(" %c", &ans);

        student.answers[i] = ans - 'A';

        if (student.answers[i] == questions[i]->answer)
            score++;
    }

    student.score = score;

    printf("You scored %d out of %d\n", score, count);

    FILE *fp = fopen("scores.dat", "ab");
    if (fp == NULL) {
        printf("Error: Unable to save score\n");
        return;
    }

    fwrite(&student, sizeof(Student), 1, fp);
    fclose(fp);
}

void view_scores() {
    FILE *fp = fopen("scores.dat", "rb");
    if (fp == NULL) {
        printf("Error: Unable to open scores file\n");
        return;
    }

    printf("SCOREBOARD\n");
    printf("----------\n");

    Student student;
    while (fread(&student, sizeof(Student), 1, fp) == 1)
        printf("%s - Score: %d\n", student.name, student.score);

    fclose(fp);
}

int main() {
    Question *questions[MAX_QUESTIONS];
    int count = load_questions(questions);

    while (1) {
        display_menu();

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fgets((char*)stdin, 2, stdin);

        switch (choice) {
            case 1:
                take_exam(questions, count);
                break;
            case 2:
                add_question(questions, &count);
                save_questions(questions, count);
                break;
            case 3:
                list_questions(questions, count);
                break;
            case 4:
                view_scores();
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}