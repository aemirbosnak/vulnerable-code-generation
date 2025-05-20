//FormAI DATASET v1.0 Category: Error handling ; Style: Donald Knuth
/* A unique C Error handling example program a la Donald Knuth */

#include <stdio.h>
#include <stdlib.h>

#define FATAL(msg) { fprintf(stderr, "Fatal error: %s\n", msg); exit(EXIT_FAILURE); }

int main(int argc, char *argv[]) {
    // Check if number of arguments is correct
    if (argc != 2) {
        FATAL("Usage: program_name argument");
    }
    
    // Attempt to open the file
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        FATAL("Could not open file");
    }
    
    // Allocate memory for the data
    int num_elems = 10;
    int *data = malloc(sizeof(int) * num_elems);
    if (!data) {
        FATAL("Could not allocate memory");
    }

    // Read in the data
    int curr_elem = 0;
    int num_read;
    while ((num_read = fscanf(fp, "%d", &data[curr_elem])) == 1) {
        curr_elem++;
        // Resize the data array if necessary
        if (curr_elem == num_elems) {
            num_elems *= 2;
            int *new_data = realloc(data, sizeof(int) * num_elems);
            if (!new_data) {
                FATAL("Could not reallocate memory");
            }
            data = new_data;
        }
    }
    
    // Check for errors in the input file
    if (num_read == EOF) {
        if (ferror(fp)) {
            FATAL("Error reading input file");
        } else {
            printf("End of file reached\n");
        }
    } else {
        printf("Error parsing input\n");
    }
    
    // Clean up and exit
    fclose(fp);
    free(data);
    return 0;
}