//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char *question;
    char **options;
    int num_options;
    int correct_option;
};

struct Exam {
    char *name;
    int num_questions;
    struct Question *questions;
};

struct Student {
    char *name;
    int score;
};

struct Exam *create_exam(char *name, int num_questions) {
    struct Exam *exam = malloc(sizeof(struct Exam));
    exam->name = strdup(name);
    exam->num_questions = num_questions;
    exam->questions = malloc(sizeof(struct Question) * num_questions);
    return exam;
}

void free_exam(struct Exam *exam) {
    for (int i = 0; i < exam->num_questions; i++) {
        free(exam->questions[i].question);
        for (int j = 0; j < exam->questions[i].num_options; j++) {
            free(exam->questions[i].options[j]);
        }
        free(exam->questions[i].options);
    }
    free(exam->questions);
    free(exam->name);
    free(exam);
}

struct Question *create_question(char *question, char **options, int num_options, int correct_option) {
    struct Question *question_struct = malloc(sizeof(struct Question));
    question_struct->question = strdup(question);
    question_struct->options = malloc(sizeof(char *) * num_options);
    for (int i = 0; i < num_options; i++) {
        question_struct->options[i] = strdup(options[i]);
    }
    question_struct->num_options = num_options;
    question_struct->correct_option = correct_option;
    return question_struct;
}

void free_question(struct Question *question) {
    free(question->question);
    for (int i = 0; i < question->num_options; i++) {
        free(question->options[i]);
    }
    free(question->options);
    free(question);
}

struct Student *create_student(char *name) {
    struct Student *student = malloc(sizeof(struct Student));
    student->name = strdup(name);
    student->score = 0;
    return student;
}

void free_student(struct Student *student) {
    free(student->name);
    free(student);
}

void take_exam(struct Exam *exam, struct Student *student) {
    for (int i = 0; i < exam->num_questions; i++) {
        printf("%s\n", exam->questions[i].question);
        for (int j = 0; j < exam->questions[i].num_options; j++) {
            printf("%d. %s\n", j + 1, exam->questions[i].options[j]);
        }
        int answer;
        scanf("%d", &answer);
        if (answer == exam->questions[i].correct_option) {
            student->score++;
        }
    }
}

void print_results(struct Exam *exam, struct Student *student) {
    printf("Exam: %s\n", exam->name);
    printf("Student: %s\n", student->name);
    printf("Score: %d/%d\n", student->score, exam->num_questions);
}

int main() {
    struct Exam *exam = create_exam("C Online Exam", 10);
    exam->questions[0] = *create_question("What is the output of the following code?\nint main() { printf(\"Hello, world!\"); }", (char *[]){"Hello, world!", "World, hello!", "Error"}, 3, 0);
    exam->questions[1] = *create_question("What is the data type of the variable x in the following code?\nint x = 10;", (char *[]){"int", "float", "double"}, 3, 0);
    exam->questions[2] = *create_question("What is the value of y in the following code?\nint y = 10 % 3;", (char *[]){"1", "2", "3"}, 3, 1);
    exam->questions[3] = *create_question("What is the output of the following code?\nint main() { for (int i = 0; i < 10; i++) { printf(\"%d\\n\", i); } }", (char *[]){"0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n", "1\n2\n3\n4\n5\n6\n7\n8\n9\n", "0\n1\n2\n3\n4\n5\n6\n7\n8\n9"}, 3, 0);
    exam->questions[4] = *create_question("What is the value of x in the following code?\nint x = ++y + z++;", (char *[]){"11", "12", "13"}, 3, 0);
    exam->questions[5] = *create_question("What is the output of the following code?\nint main() { int x = 10; x += 5; printf(\"%d\\n\", x); }", (char *[]){"5", "10", "15"}, 3, 2);
    exam->questions[6] = *create_question("What is the value of y in the following code?\ny = x ?: 10;", (char *[]){"0", "10", "Error"}, 3, 1);
    exam->questions[7] = *create_question("What is the output of the following code?\nint main() { int x = 10; x *= 5; printf(\"%d\\n\", x); }", (char *[]){"5", "10", "50"}, 3, 2);
    exam->questions[8] = *create_question("What is the value of x in the following code?\nx = y = 10;", (char *[]){"10", "20", "Error"}, 3, 0);
    exam->questions[9] = *create_question("What is the output of the following code?\nint main() { int x = 10; x /= 5; printf(\"%d\\n\", x); }", (char *[]){"2", "5", "10"}, 3, 0);

    struct Student *student = create_student("John Doe");
    take_exam(exam, student);
    print_results(exam, student);

    free_question(&exam->questions[0]);
    free_question(&exam->questions[1]);
    free_question(&exam->questions[2]);
    free_question(&exam->questions[3]);
    free_question(&exam->questions[4]);
    free_question(&exam->questions[5]);
    free_question(&exam->questions[6]);
    free_question(&exam->questions[7]);
    free_question(&exam->questions[8]);
    free_question(&exam->questions[9]);
    free(exam->questions);
    free(exam->name);
    free(exam);
    free_student(student);
    return 0;
}