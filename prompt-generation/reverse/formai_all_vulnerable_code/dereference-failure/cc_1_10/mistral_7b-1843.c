//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUFFER 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    char infile[MAX_BUFFER];
    char outfile[MAX_BUFFER];
    char buff[MAX_BUFFER];
    int fd_in, fd_out;
    int i, j, k;

    // Check command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // Copy file names to local variables
    strcpy(infile, argv[1]);
    strcpy(outfile, argv[2]);

    // Open input file
    fd_in = open(infile, O_RDONLY);
    if (fd_in < 0) {
        die("Failed to open input file.");
    }

    // Open output file
    fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_out < 0) {
        die("Failed to open output file.");
    }

    // Read input file line by line
    while (fgets(buff, MAX_BUFFER, fd_in) != NULL) {
        // Process each line
        for (i = 0, j = 0; buff[i] != '\0'; i++) {
            if (buff[i] == 'a') {
                // Replace 'a' with 'e'
                buff[i] = 'e';
            } else if (buff[i] == '\n') {
                // Add a random number at the end of the line
                for (k = 0; k < 5; k++) {
                    buff[++i] = '0' + (rand() % 10);
                }
                buff[++i] = '\n';
                break;
            }
            buff[++j] = buff[i];
        }

        // Write processed line to output file
        write(fd_out, buff, j + 1);
    }

    // Close input and output files
    close(fd_in);
    close(fd_out);

    printf("File processing completed.\n");
    return 0;
}