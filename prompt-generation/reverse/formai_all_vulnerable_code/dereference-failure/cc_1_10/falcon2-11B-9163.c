//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <ebook_file>\n", argv[0]);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int buffer_index = 0;

    FILE *ebook = fopen(argv[1], "r");
    if (!ebook) {
        perror("Error opening ebook file");
        return 1;
    }

    struct stat file_stats;
    if (fstat(fileno(ebook), &file_stats)!= 0) {
        perror("Error getting file stats");
        return 1;
    }

    if (file_stats.st_size < BUFFER_SIZE) {
        buffer[buffer_index] = '\0';
        printf("Reading %s...\n", argv[1]);
        while (fgets(buffer, BUFFER_SIZE, ebook)!= NULL) {
            printf("%s", buffer);
            fflush(stdout);
        }
        return 0;
    }

    buffer[buffer_index] = '\0';
    printf("Reading %s...\n", argv[1]);
    while (fgets(buffer, BUFFER_SIZE, ebook)!= NULL) {
        printf("%s", buffer);
        fflush(stdout);
    }

    fclose(ebook);

    return 0;
}