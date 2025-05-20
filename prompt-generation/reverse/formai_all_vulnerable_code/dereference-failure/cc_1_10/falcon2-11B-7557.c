//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/mman.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[]) {
    // Check if user has provided argument
    if (argc!= 2) {
        printf("Usage: %s <file path>\n", argv[0]);
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    // Create buffer
    char buffer[BUFFERSIZE];

    // Read file into buffer
    while (fgets(buffer, BUFFERSIZE, file)!= NULL) {
        // Check if buffer contains virus pattern
        if (strstr(buffer, "VIRUS")!= NULL) {
            // Write file name to log file
            FILE *log = fopen("log.txt", "a");
            fprintf(log, "%s detected as virus\n", argv[1]);
            fclose(log);

            // Close file
            fclose(file);

            // Exit program with error code
            return 1;
        }
    }

    // Close file
    fclose(file);

    // Exit program with success code
    return 0;
}