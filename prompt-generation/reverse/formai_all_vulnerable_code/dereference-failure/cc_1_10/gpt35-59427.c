//FormAI DATASET v1.0 Category: HTML beautifier ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILE_SIZE 1024

// Function to beautify the HTML file
void beautify(char *input_file, char *output_file) {
    
    FILE *in_file, *out_file;
    char *line = NULL;
    char *new_line = NULL;
    size_t len = 0;
    ssize_t read;

    // Open input file for reading
    in_file = fopen(input_file, "r");
    if (in_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open output file for writing
    out_file = fopen(output_file, "w");
    if (out_file == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Read input file line by line and beautify
    while ((read = getline(&line, &len, in_file)) != -1) {

        // Remove leading and trailing whitespaces
        char *p = line;
        while (*p == ' ' || *p == '\t') p++;          // skip leading spaces
        size_t trim_begin = p - line;                  // index of first non-whitespace
        p = line + read - 1;
        while (p > line && (*p == ' ' || *p == '\t')) p--;    // skip trailing spaces
        p[1] = '\0';                                           // remove them

        // Write the beautified line to the output file
        new_line = (char*) calloc(read+1, sizeof(char));
        strncpy(new_line, line+trim_begin, p-line+1-trim_begin);
        strncat(new_line, "\t\t", 2);
        strncat(new_line, p+1, strlen(p+1));
        fprintf(out_file, "%s\n", new_line);
        free(new_line);
    }

    // Close the input and output files
    fclose(in_file);
    fclose(out_file);

    // Free the memory allocated by getline()
    if (line)
        free(line);
}

// Thread function to beautify the HTML file
void* beautify_html(void* arg) {
    char* input_file = (char*) arg;
    char* output_file = (char*) calloc(strlen(input_file) + 4, sizeof(char));
    strcpy(output_file, input_file);
    strcat(output_file, ".out");
    beautify(input_file, output_file);
    free(output_file);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

    pthread_t threads[MAX_FILE_SIZE];
    int thread_count = 0;

    // Loop for each input file and create a thread to beautify it
    for (int i=1; i<argc; i++) {
        if (strstr(argv[i], ".html") != NULL) {
            pthread_create(&threads[thread_count], NULL, beautify_html, (void*) argv[i]);
            thread_count++;
        }
    }

    // Wait for all threads to complete
    for (int i=0; i<thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}