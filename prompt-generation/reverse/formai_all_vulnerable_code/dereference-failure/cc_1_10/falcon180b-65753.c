//Falcon-180B DATASET v1.0 Category: Error handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 1024

void read_file(FILE *fp, char *buffer, size_t buf_size)
{
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, buf_size, fp)) > 0) {
        /* Do something with the read data */
    }

    if (ferror(fp)) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }
}

void write_file(FILE *fp, const char *buffer, size_t buf_size)
{
    size_t bytes_written;

    while ((bytes_written = fwrite(buffer, 1, buf_size, fp)) > 0) {
        /* Do something with the written data */
    }

    if (ferror(fp)) {
        perror("Error writing file");
        exit(EXIT_FAILURE);
    }
}

int main()
{
    char input_file[BUF_SIZE];
    char output_file[BUF_SIZE];
    FILE *input_fp, *output_fp;
    char buffer[BUF_SIZE];

    /* Get input and output file names */
    printf("Enter input file name: ");
    fgets(input_file, BUF_SIZE, stdin);
    printf("Enter output file name: ");
    fgets(output_file, BUF_SIZE, stdin);

    /* Open input file */
    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    /* Open output file */
    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    /* Read input file and write to output file */
    while (fgets(buffer, BUF_SIZE, input_fp)!= NULL) {
        write_file(output_fp, buffer, strlen(buffer));
    }

    /* Close input and output files */
    fclose(input_fp);
    fclose(output_fp);

    return 0;
}