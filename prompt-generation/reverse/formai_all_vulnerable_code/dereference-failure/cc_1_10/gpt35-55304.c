//FormAI DATASET v1.0 Category: Text processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *line;
    int lineNumber;
} Line;

Line *lines[MAX_LINE_LENGTH];
int lineNumber = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *processLine(void *arg) {
    Line *line = (Line *) arg;
    char *pos;
    int len = 0;
    int numWords = 0;

    pos = strstr(line->line, "the");
    while (pos != NULL) {
        numWords++;
        len += 3;
        pos = strstr(pos + 3, "the");
    }

    pthread_mutex_lock(&mutex);

    printf("Thread #%d found %d instances of 'the' in line %d: %s\n", 
    (int)pthread_self(), numWords, line->lineNumber, line->line);

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Cannot open file: %s\n", filename);
        return 1;
    }

    int i = 0;
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        lines[i] = (Line *) malloc(sizeof(Line));
        if (lines[i] == NULL) {
            printf("Error: Cannot allocate memory\n");
            return 2;
        }
        lines[i]->line = strdup(buffer);
        if (lines[i]->line == NULL) {
            printf("Error: Cannot allocate memory\n");
            return 2;
        }
        lines[i]->lineNumber = i + 1;
        i++;
    }
    lineNumber = i;

    pthread_t threads[lineNumber];
    int rc;

    for (int i = 0; i < lineNumber; i++) {
        rc = pthread_create(&threads[i], NULL, &processLine, (void *) lines[i]);
        if (rc != 0) {
            printf("Error: pthread_create failed: %d\n", rc);
            return 3;
        }
    }

    for (int i = 0; i < lineNumber; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc != 0) {
            printf("Error: pthread_join failed: %d\n", rc);
            return 4;
        }
    }

    fclose(file);
    pthread_mutex_destroy(&mutex);

    for (int i = 0; i < lineNumber; i++) {
        free(lines[i]->line);
        free(lines[i]);
    }

    return 0;
}