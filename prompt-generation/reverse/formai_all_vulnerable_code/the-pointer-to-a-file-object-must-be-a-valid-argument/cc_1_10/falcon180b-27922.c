//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Donald Knuth
#include <stdio.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 4
#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int student_id;
    int score;
} Student;

typedef struct {
    char question[MAX_NAME_LENGTH];
    char choices[MAX_CHOICES][MAX_NAME_LENGTH];
    int answer;
} Question;

void read_questions(Question questions[], int num_questions) {
    FILE *fp;
    char line[MAX_NAME_LENGTH];
    int i = 0;
    fp = fopen("questions.txt", "r");
    while (fgets(line, MAX_NAME_LENGTH, fp)!= NULL && i < num_questions) {
        sscanf(line, "%s %s %s %d", questions[i].question, questions[i].choices[0], questions[i].choices[1], &questions[i].answer);
        i++;
    }
    fclose(fp);
}

void read_students(Student students[], int num_students) {
    FILE *fp;
    char line[MAX_NAME_LENGTH];
    int i = 0;
    fp = fopen("students.txt", "r");
    while (fgets(line, MAX_NAME_LENGTH, fp)!= NULL && i < num_students) {
        sscanf(line, "%s %d", students[i].name, &students[i].student_id);
        i++;
    }
    fclose(fp);
}

void take_exam(Question questions[], int num_questions, Student students[], int num_students) {
    int i, j, k, choice, correct = 0;
    for (i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);
        for (j = 0; j < MAX_CHOICES; j++) {
            printf("%d. %s\n", j + 1, questions[i].choices[j]);
        }
        scanf("%d", &choice);
        if (choice == questions[i].answer) {
            correct++;
        }
    }
    printf("You got %d out of %d questions correct.\n", correct, num_questions);
    for (i = 0; i < num_students; i++) {
        students[i].score = correct;
        printf("%s got %d out of %d questions correct.\n", students[i].name, correct, num_questions);
    }
}

int main() {
    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];
    int num_questions, num_students;
    printf("Enter number of questions: ");
    scanf("%d", &num_questions);
    read_questions(questions, num_questions);
    printf("Enter number of students: ");
    scanf("%d", &num_students);
    read_students(students, num_students);
    take_exam(questions, num_questions, students, num_students);
    return 0;
}