//Falcon-180B DATASET v1.0 Category: Error handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char **argv) {
    FILE *file;
    char *filename = "nonexistent_file.txt";
    char line[MAX_LINE_SIZE];
    int linenum = 0;
    int ret;

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        linenum++;

        // Reverse the line
        char *p = line;
        char *q = line + strlen(line) - 1;
        while (p < q) {
            char tmp = *p;
            *p = *q;
            *q = tmp;
            p++;
            q--;
        }

        // Print the reversed line
        printf("%d: %s\n", linenum, line);
    }

    // Close the file
    ret = fclose(file);
    if (ret!= 0) {
        fprintf(stderr, "fclose: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}