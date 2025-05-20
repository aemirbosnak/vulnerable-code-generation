//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define INDENTATION_SPACES 2

typedef struct {
    char **lines;
    int *lineCount;
    int start;
    int end;
} BeautifyTask;

void *beautify(void *arg) {
    BeautifyTask *task = (BeautifyTask *)arg;
    char **lines = task->lines;
    int *lineCount = task->lineCount;

    for (int i = task->start; i < task->end; i++) {
        char *currentLine = lines[i];
        char *trimmedLine = malloc(strlen(currentLine) + 1);
        int j = 0, k = 0;

        // Trim leading white space
        while (isspace((unsigned char)currentLine[j])) {
            j++;
        }

        // If line is not empty
        if (currentLine[j] != '\0') {
            // Check for opening brackets
            if (currentLine[j] == '{') {
                // Add indentation before the bracket
                k += snprintf(trimmedLine + k, strlen(currentLine) + 1, "%*s%s", INDENTATION_SPACES, "", "{");
            } else {
                // Add indentation
                k += snprintf(trimmedLine + k, strlen(currentLine) + 1, "%*s%s", INDENTATION_SPACES, "", currentLine + j);
            }

            // Print the beautified line
            printf("%s\n", trimmedLine);
        }

        free(trimmedLine);
    }

    return NULL;
}

void read_input(char ***lines, int *lineCount) {
    size_t bufferSize = MAX_LINE_LENGTH;
    char *buffer = malloc(bufferSize);

    *lines = NULL;
    *lineCount = 0;

    while (fgets(buffer, bufferSize, stdin)) {
        *lines = realloc(*lines, sizeof(char *) * (*lineCount + 1));
        (*lines)[*lineCount] = strdup(buffer);
        (*lineCount)++;
    }

    free(buffer);
}

void free_lines(char **lines, int lineCount) {
    for (int i = 0; i < lineCount; i++) {
        free(lines[i]);
    }
    free(lines);
}

int main() {
    char **lines = NULL;
    int lineCount = 0;
    const int threadCount = 4;
    pthread_t threads[threadCount];
    BeautifyTask tasks[threadCount];
    int linesPerThread = 0;

    // Read input lines from stdin
    read_input(&lines, &lineCount);

    // Determine the number of lines per thread
    linesPerThread = lineCount / threadCount;

    // Create threads to beautify the code
    for (int i = 0; i < threadCount; i++) {
        tasks[i].lines = lines;
        tasks[i].lineCount = &lineCount;
        tasks[i].start = i * linesPerThread;
        tasks[i].end = (i == threadCount - 1) ? lineCount : (i + 1) * linesPerThread;

        pthread_create(&threads[i], NULL, beautify, &tasks[i]);
    }

    // Join threads
    for (int i = 0; i < threadCount; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up
    free_lines(lines, lineCount);

    return 0;
}