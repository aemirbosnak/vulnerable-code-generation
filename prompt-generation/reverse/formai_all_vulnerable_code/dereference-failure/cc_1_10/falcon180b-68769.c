//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <output>\n", argv[0]);
        exit(1);
    }

    char input_filename[64];
    char output_filename[64];

    strcpy(input_filename, argv[1]);
    strcpy(output_filename, argv[2]);

    int input_file = open(input_filename, O_RDONLY);
    if (input_file == -1) {
        printf("Error opening input file.\n");
        exit(1);
    }

    struct stat input_stat;
    fstat(input_file, &input_stat);

    int output_file = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_file == -1) {
        printf("Error opening output file.\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(input_file, buffer, BUFFER_SIZE)) > 0) {
        write(output_file, buffer, bytes_read);
    }

    close(input_file);
    close(output_file);

    printf("Data recovery successful!\n");

    return 0;
}