//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

// Mutex for printing to console
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;

void *translate_thread(void *arg) {
    char *input_line = (char *) arg;
    char *output_line = malloc(MAX_LINE_LENGTH);
    int output_length = 0;

    // Translate input line to Cat Language
    for (int i = 0; i < strlen(input_line); i++) {
        if (isalpha(input_line[i])) {
            if (isupper(input_line[i])) {
                output_line[output_length++] = 'M';
            } else {
                output_line[output_length++] ='m';
            }
        } else {
            output_line[output_length++] = input_line[i];
        }
    }
    output_line[output_length] = '\0';

    // Print translated line
    pthread_mutex_lock(&print_mutex);
    printf("%s\n", output_line);
    pthread_mutex_unlock(&print_mutex);

    free(output_line);
    return NULL;
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    char input_line[MAX_LINE_LENGTH];
    while (fgets(input_line, MAX_LINE_LENGTH, input_file)!= NULL) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, translate_thread, input_line);
    }

    fclose(input_file);
    return 0;
}