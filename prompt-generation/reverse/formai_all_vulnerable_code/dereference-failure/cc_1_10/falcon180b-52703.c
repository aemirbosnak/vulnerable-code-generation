//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

typedef struct {
    char filename[100];
    int filesize;
    char *data;
} File;

int main() {
    int numFiles;
    FILE *fp;
    char input[100];
    File files[100];

    printf("Enter the number of files to recover: ");
    scanf("%d", &numFiles);

    for (int i = 0; i < numFiles; i++) {
        printf("Enter the filename of file %d: ", i+1);
        scanf("%s", files[i].filename);

        fp = fopen(files[i].filename, "rb");
        if (fp == NULL) {
            printf("Error: File not found.\n");
            exit(1);
        }

        fseek(fp, 0L, SEEK_END);
        files[i].filesize = ftell(fp);
        rewind(fp);

        files[i].data = (char*)malloc(files[i].filesize);
        if (files[i].data == NULL) {
            printf("Error: Out of memory.\n");
            exit(1);
        }

        fread(files[i].data, 1, files[i].filesize, fp);
        fclose(fp);
    }

    printf("Enter the output directory: ");
    scanf("%s", input);

    for (int i = 0; i < numFiles; i++) {
        char output[200];
        sprintf(output, "%s/%s", input, files[i].filename);

        fp = fopen(output, "wb");
        if (fp == NULL) {
            printf("Error: Could not create output file.\n");
            exit(1);
        }

        fwrite(files[i].data, 1, files[i].filesize, fp);
        fclose(fp);

        printf("File %s recovered successfully.\n", files[i].filename);
    }

    return 0;
}