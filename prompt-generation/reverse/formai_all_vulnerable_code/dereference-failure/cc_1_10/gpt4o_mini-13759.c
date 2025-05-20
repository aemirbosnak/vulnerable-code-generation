//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define INDENT_SIZE 4

typedef struct {
    char *input_file;
    char *output_file;
} BeautifierArgs;

void *beautifier(void *args) {
    BeautifierArgs *beautifier_args = (BeautifierArgs *) args;
    FILE *input = fopen(beautifier_args->input_file, "r");
    if (!input) {
        perror("Failed to open input file");
        pthread_exit(NULL);
    }

    FILE *output = fopen(beautifier_args->output_file, "w");
    if (!output) {
        perror("Failed to open output file");
        fclose(input);
        pthread_exit(NULL);
    }

    char buffer[BUFFER_SIZE];
    int indent_level = 0;
    int i = 0;

    while (fgets(buffer, BUFFER_SIZE, input)) {
        for (i = 0; i < strlen(buffer); ++i) {
            if (buffer[i] == '<' && buffer[i + 1] != '/') {
                // Starting a new tag
                fwrite(buffer, sizeof(char), i + 1, output);
                indent_level++;
                break;
            } else if (buffer[i] == '<' && buffer[i + 1] == '/') {
                // Ending a tag
                fwrite(buffer, sizeof(char), i + 1, output);
                indent_level--;
                break;
            } else {
                // Print with indentation
                for (int j = 0; j < indent_level * INDENT_SIZE; ++j) {
                    fputc(' ', output);
                }
                fputs(buffer, output);
                break;
            }
        }
    }

    fclose(input);
    fclose(output);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input html file> <output html file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    BeautifierArgs *args = malloc(sizeof(BeautifierArgs));
    args->input_file = argv[1];
    args->output_file = argv[2];

    pthread_t beautifier_thread;
    if (pthread_create(&beautifier_thread, NULL, beautifier, args) != 0) {
        perror("Failed to create thread");
        free(args);
        return EXIT_FAILURE;
    }

    pthread_join(beautifier_thread, NULL);
    free(args);

    printf("HTML beautification complete. Output saved to %s\n", argv[2]);
    return EXIT_SUCCESS;
}