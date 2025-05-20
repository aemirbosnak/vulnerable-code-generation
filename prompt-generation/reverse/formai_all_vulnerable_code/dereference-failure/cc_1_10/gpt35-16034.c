//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_FILENAME_LEN  256
#define MAX_BUFFER_LEN    1024

typedef struct {
    char filename[MAX_FILENAME_LEN];
    int status;
} File;

int is_file_infected(File file) {
    /* Placeholder function for virus scanning */
    return rand() % 2;
}

int main(int argc, char *argv[]) {
    int num_files;
    char buffer[MAX_BUFFER_LEN];
    File *files;

    /* Get number of files from user */
    printf("Enter number of files to scan: ");
    fgets(buffer, sizeof(buffer), stdin);
    num_files = atoi(buffer);

    /* Allocate memory for files array */
    files = (File *) malloc(sizeof(File) * num_files);

    /* Prompt user to enter filenames and scan files for viruses */
    for (int i = 0; i < num_files; i++) {
        printf("Enter filename %d: ", i+1);
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%s", files[i].filename);

        files[i].status = is_file_infected(files[i]);
    }

    /* Display scan results */
    printf("\n\nScan results:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s: ", files[i].filename);

        if (files[i].status)
            printf("INFECTED\n");
        else
            printf("CLEAN\n");
    }

    /* Cleanup memory */
    free(files);

    return 0;
}