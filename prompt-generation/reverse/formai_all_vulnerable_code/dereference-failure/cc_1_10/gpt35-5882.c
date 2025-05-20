//FormAI DATASET v1.0 Category: Log analysis ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 10000
#define MAX_LOG_LINE_LENGTH 1000

char* log_lines[MAX_LOG_LINES];
int num_lines = 0;

void read_log_file(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open log file\n");
        exit(1);
    }

    char* line = malloc(MAX_LOG_LINE_LENGTH);
    while (fgets(line, MAX_LOG_LINE_LENGTH, file) != NULL) {
        if (num_lines >= MAX_LOG_LINES) {
            printf("Error: log file is too big\n");
            exit(1);
        }
        char* log_line = malloc(strlen(line) + 1);
        strcpy(log_line, line);
        log_lines[num_lines++] = log_line;
    }

    fclose(file);
    free(line);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        return 1;
    }

    read_log_file(argv[1]);

    printf("The world as we knew it has come to an end. The log file is all we have left to remember the life that once was.\n");
    printf("In the darkness, a group of survivors huddle around a campfire, fumbling through lines of code to make sense of what happened.\n\n");
    printf("As they scan through the surviving lines of code, one thing becomes clear: the virus that caused the apocalypse had been lurking in our systems for months, undetected.\n");
    printf("It spread rapidly, infecting every machine it touched. And as it spread, it crashed all of our infrastructure, from the power grid to our communication systems.\n\n");
    printf("But there's something else about these logs that's really unsettling. There are lines of code that don't belong here, something foreign.\n");
    printf("It looks like someone or something tried to infiltrate our systems even before the apocalypse hit. But who could have done this?\n\n");
    
    int num_foreign_lines = 0;
    for (int i = 0; i < num_lines; i++) {
        char* line = log_lines[i];
        if (strstr(line, "foreign") != NULL) {
            num_foreign_lines++;
            printf("Line %d: %s", i + 1, line);
        }
    }

    printf("\nThe survivors look at each other in fear. They know that they can't trust anyone, not even their own machines.\n");
    printf("They vow to start rebuilding, but this time they'll do it without technology. The apocalypse has taught them that sometimes, the only way to survive is to go back to basics.\n");
    printf("As the fire flickers and the night settles in, they start to plan their next move, wondering what other secrets their logs might hold.\n");

    for (int i = 0; i < num_lines; i++) {
        free(log_lines[i]);
    }

    return 0;
}