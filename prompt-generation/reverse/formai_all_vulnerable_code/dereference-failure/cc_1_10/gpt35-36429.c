//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to hold file information */
typedef struct {
    char *filename;
    long size;
} FileInfo;

/* Define function to retrieve file information given a file path */
FileInfo getFileSize(char *path) {
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", path);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0L, SEEK_END);
    long size = ftell(file);

    FileInfo fileInfo;
    fileInfo.filename = path;
    fileInfo.size = size;

    fclose(file);
    return fileInfo;
}

/* Define function to sort an array of file information structs by file size */
void sortFilesBySize(FileInfo files[], int numFiles) {
    for (int i = 0; i < numFiles - 1; i++) {
        for (int j = i + 1; j < numFiles; j++) {
            if (files[j].size > files[i].size) {
                FileInfo temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

/* Define main function */
int main(int argc, char *argv[]) {

    /* Check for correct number of command line arguments */
    if (argc != 2) {
        printf("Usage: %s directory\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *directory = argv[1];

    /* Build command to get list of files in directory and pipe output to wc command to count files */
    char command[100];
    sprintf(command, "ls %s | wc -l", directory);
    FILE *fp = popen(command, "r");

    /* Read output of command */
    int numFiles;
    fscanf(fp, "%d", &numFiles);

    /* Close pipe */
    pclose(fp);

    /* Allocate memory for array of file information structs */
    FileInfo *files = (FileInfo *) malloc(numFiles * sizeof(FileInfo));

    /* Build command to get list of files in directory and pipe output to awk command to print file paths and file sizes */
    sprintf(command, "ls -l %s | awk '{print $9,$5}'", directory);
    fp = popen(command, "r");

    /* Read output of command and store file information in array */
    char line[200];
    for (int i = 0; i < numFiles; i++) {
        fgets(line, sizeof(line), fp);

        /* Remove newline character from end of string */
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        /* Split line into filename and file size */
        char *filename = strtok(line, " ");
        char *sizeStr = strtok(NULL, " ");
        long size = atol(sizeStr);

        /* Add file information to array */
        files[i].filename = filename;
        files[i].size = size;
    }

    /* Close pipe */
    pclose(fp);

    /* Sort files by size */
    sortFilesBySize(files, numFiles);

    /* Print file information */
    printf("Disk space used by files in %s (sorted by size):\n", directory);
    for (int i = 0; i < numFiles; i++) {
        FileInfo fileInfo = files[i];
        printf("%s\t%ld bytes\n", fileInfo.filename, fileInfo.size);
    }

    /* Free array of file information structs */
    free(files);

    return 0;
}