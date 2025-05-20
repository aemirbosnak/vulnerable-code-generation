//FormAI DATASET v1.0 Category: HTML beautifier ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

char input[MAX_LINES][MAX_LINE_LENGTH];
char output[MAX_LINES][MAX_LINE_LENGTH];
int num_lines = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* format_line(void* arg);

int main() {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    pthread_t threads[MAX_LINES];
    int i;

    fp = fopen("input.html", "r");
    if (fp == NULL) {
        printf("Error: Couldn't open input file.\n");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1 && num_lines < MAX_LINES) {
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
            read--;
        }
        if (read > 0) {
            strncpy(input[num_lines], line, MAX_LINE_LENGTH - 1);
            input[num_lines][MAX_LINE_LENGTH - 1] = '\0';
            num_lines++;
        }
    }

    free(line);
    fclose(fp);

    for (i = 0; i < num_lines; i++) {
        pthread_create(&threads[i], NULL, format_line, (void*)i);
    }

    for (i = 0; i < num_lines; i++) {
        pthread_join(threads[i], NULL);
    }

    fp = fopen("output.html", "w");
    if (fp == NULL) {
        printf("Error: Couldn't open output file.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < num_lines; i++) {
        fprintf(fp, "%s\n", output[i]);
    }

    fclose(fp);

    printf("Done formatting!\n");

    return 0;
}

void* format_line(void* arg) {
    int line_num = (int)arg;
    char formatted[MAX_LINE_LENGTH];
    int indent_level = 0;
    int i;

    pthread_mutex_lock(&mutex);

    for (i = 0; i < strlen(input[line_num]); i++) {
        if (i == 0 || input[line_num][i - 1] == '<') {
            if (input[line_num][i] == '/') {
                indent_level--;
            }
            for (int j = 0; j < indent_level; j++) {
                strcat(formatted, "\t");
            }
            if (input[line_num][i] != '/') {
                indent_level++;
            }
        }
        strncat(formatted, &input[line_num][i], 1);
    }

    strncpy(output[line_num], formatted, MAX_LINE_LENGTH - 1);
    output[line_num][MAX_LINE_LENGTH - 1] = '\0';

    pthread_mutex_unlock(&mutex);

    return NULL;
}