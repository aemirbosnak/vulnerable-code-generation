//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <string.h>

void create_backup(const char* filename) {
    FILE *fp, *bp;
    char backfilename[100];

    // Open the original file
    fp = fopen(filename, "r+");
    if (fp == NULL) {
        fprintf(stderr, "Couldn't open file\n");
        return;
    }

    // Create a backup copy of the file
    sprintf(backfilename, "%s.bak", filename);
    bp = fopen(backfilename, "w");
    if (bp == NULL) {
        fprintf(stderr, "Couldn't create backup file\n");
        return;
    }

    // Copy the contents of the original file to the backup copy
    fread(backfilename, sizeof(char), strlen(backfilename), fp);
    fclose(fp);
    fclose(bp);
}

void overwrite_file(const char* filename) {
    FILE *fp, *bp;
    char backfilename[100];

    // Open the backup copy
    fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Couldn't open backup file\n");
        return;
    }

    // Open the original file
    bp = fopen(backfilename, "r");
    if (bp == NULL) {
        fprintf(stderr, "Couldn't open backup file\n");
        return;
    }

    // Copy the contents of the backup copy to the original file
    fread(filename, sizeof(char), strlen(filename), bp);
    fclose(bp);
    fclose(fp);

    // Delete the backup copy
    remove(backfilename);
}

void delete_backup(const char* filename) {
    char backfilename[100];

    // Create a backup copy of the file
    sprintf(backfilename, "%s.bak", filename);
    remove(backfilename);
}

int main() {
    char filename[100];

    // Prompt the user for a file name
    printf("Enter the name of the file: ");
    fgets(filename, sizeof(filename), stdin);

    // Create a backup copy of the file
    create_backup(filename);

    // Overwrite the original file with the backup copy
    overwrite_file(filename);

    // Delete the backup copy
    delete_backup(filename);

    return 0;
}