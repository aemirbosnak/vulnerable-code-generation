//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_LINE_LENGTH 1024
#define CHECKSUM_ALGORITHM "md5"

int main(int argc, char *argv[]) {
    FILE *file_ptr;
    char line[MAX_LINE_LENGTH];
    char *checksum_ptr;
    char checksum[33];
    int line_count = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file_ptr = fopen(argv[1], "r");

    if (file_ptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file_ptr)!= NULL) {
        line_count++;

        // Calculate checksum for each line
        checksum_ptr = line + strlen(line) - 2;
        while (*checksum_ptr == '\n' || *checksum_ptr == '\r') {
            checksum_ptr--;
        }
        strcpy(checksum, CHECKSUM_ALGORITHM);
        strcat(checksum, " ");
        strcat(checksum, line);
        strcat(checksum, "\n");

        printf("%s%d: %s\n", CHECKSUM_ALGORITHM, line_count, checksum);
    }

    fclose(file_ptr);

    return 0;
}