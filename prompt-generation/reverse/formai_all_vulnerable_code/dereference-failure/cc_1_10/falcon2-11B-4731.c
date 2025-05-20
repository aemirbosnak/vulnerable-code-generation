//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_FILE_PATH_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source destination\n", argv[0]);
        return 1;
    }

    char source[MAX_FILE_PATH_LENGTH], destination[MAX_FILE_PATH_LENGTH];
    strcpy(source, argv[1]);
    strcpy(destination, argv[2]);

    struct stat st;
    if (stat(source, &st)!= 0) {
        fprintf(stderr, "Error: source file '%s' does not exist.\n", source);
        return 1;
    }

    if (stat(destination, &st)!= 0) {
        mkdir(destination, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }

    int numFiles = 0;
    char *files[] = {
        "file1.txt",
        "file2.txt",
        "file3.txt",
        "file4.txt",
        "file5.txt",
    };

    for (int i = 0; i < sizeof(files) / sizeof(files[0]); i++) {
        FILE *sourceFile = fopen(source, "r");
        if (sourceFile == NULL) {
            fprintf(stderr, "Error: failed to open source file '%s'.\n", files[i]);
            return 1;
        }

        FILE *destinationFile = fopen(destination, "w");
        if (destinationFile == NULL) {
            fprintf(stderr, "Error: failed to open destination file '%s'.\n", files[i]);
            fclose(sourceFile);
            return 1;
        }

        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), sourceFile)) {
            fprintf(destinationFile, "%s", buffer);
        }

        fclose(sourceFile);
        fclose(destinationFile);
        numFiles++;
    }

    printf("Backup complete. %d files backed up.\n", numFiles);

    return 0;
}