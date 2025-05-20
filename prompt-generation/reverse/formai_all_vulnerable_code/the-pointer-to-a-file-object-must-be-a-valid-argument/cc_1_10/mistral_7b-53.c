//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_CHAR 256
#define MAX_LINE 1024

typedef struct {
    char question[MAX_CHAR];
    char options[MAX_OPTIONS][MAX_CHAR];
    int answer;
} Question;

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int read_question_file(const char *filename, Question *questions) {
    int fd, i = 0;
    char line[MAX_LINE];

    fd = open(filename, O_RDONLY);
    if (fd < 0) die("Cannot open file");

    while (fgets(line, MAX_LINE, fd)) {
        sscanf(line, "%s %s %s %s %s %s %d",
               questions[i].question,
               questions[i].options[0],
               questions[i].options[1],
               questions[i].options[2],
               questions[i].options[3],
               questions[i].options[4],
               &questions[i].answer);
        i++;
    }

    close(fd);
    return i;
}

void print_question(Question q) {
    int i;

    printf("\n%s\n", q.question);
    for (i = 0; i < 5; i++)
        printf("%d. %s\n", i + 1, q.options[i]);
}

int main(int argc, char **argv) {
    Question questions[MAX_QUESTIONS];
    int num_questions, i;

    if (argc != 2) {
        printf("Usage: %s <questions.txt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    num_questions = read_question_file(argv[1], questions);

    for (i = 0; i < num_questions; i++) {
        print_question(questions[i]);
        int choice;
        scanf("%d", &choice);

        if (choice == questions[i].answer + 1)
            printf("Correct!\n");
        else
            printf("Incorrect. The answer was %d.\n", questions[i].answer);
    }

    return EXIT_SUCCESS;
}