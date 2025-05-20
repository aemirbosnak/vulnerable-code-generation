//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_LENGTH 1000
#define BACKUP_SUFFIX ".bak"

typedef struct {
    char filename[MAX_FILE_LENGTH];
    char backupfilename[MAX_FILE_LENGTH];
} File;

void create_backup_filename(const char* filename, char* backupfilename) {
    strcpy(backupfilename, filename);
    strcat(backupfilename, BACKUP_SUFFIX);
}

int backup_file(const char* filename, const char* backupfilename) {
    FILE* inputfile = fopen(filename, "rb");
    FILE* outputfile = fopen(backupfilename, "wb");

    if (inputfile == NULL || outputfile == NULL) {
        return 1;
    }

    char buffer[1024];
    size_t bytesread;

    while ((bytesread = fread(buffer, sizeof(char), sizeof(buffer), inputfile)) > 0) {
        fwrite(buffer, sizeof(char), bytesread, outputfile);
    }

    fclose(inputfile);
    fclose(outputfile);

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    File file;
    strcpy(file.filename, argv[1]);
    create_backup_filename(file.filename, file.backupfilename);

    if (backup_file(file.filename, file.backupfilename)!= 0) {
        printf("Error creating backup file.\n");
        return 1;
    }

    printf("Backup created successfully.\n");
    return 0;
}