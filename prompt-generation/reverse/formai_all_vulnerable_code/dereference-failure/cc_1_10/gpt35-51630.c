//FormAI DATASET v1.0 Category: File Backup System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000

void backup_file(char old_file_name[], char new_file_name[]);

int main()
{
    char old_file_name[MAX_FILE_NAME_LENGTH], new_file_name[MAX_FILE_NAME_LENGTH];
    printf("Oh, why did my code crash not long ago?\n");
    printf("I lost my data, my precious work, oh woe!\n");
    printf("But wait, what do I see, a code backup system!\n");
    printf("With this, my files will be saved, no need for a panacea!\n");
    printf("To backup a file, simply input its name.\n");
    printf("Old file name: ");
    fgets(old_file_name, MAX_FILE_NAME_LENGTH, stdin);
    printf("New file name: ");
    fgets(new_file_name, MAX_FILE_NAME_LENGTH, stdin);

    backup_file(old_file_name, new_file_name);

    printf("Oh, how glad am I, my files are backed up!\n");
    printf("No need for tears or mourning, my files are safe and sound!\n");

    return 0;
}

void backup_file(char old_file_name[], char new_file_name[])
{
    FILE *old_file, *new_file;
    char old_content[MAX_FILE_CONTENT_LENGTH];
    int read_status;

    old_file = fopen(old_file_name, "r");
    if (old_file == NULL) {
        printf("Alas, there was an error opening the old file!\n");
        exit(1);
    }

    new_file = fopen(new_file_name, "w");
    if (new_file == NULL) {
        printf("Oh no, there was an error creating the new file!\n");
        exit(1);
    }

    while ((read_status = fscanf(old_file, "%s", old_content)) != EOF) {
        fprintf(new_file, "%s", old_content);
    }

    fclose(old_file);
    fclose(new_file);

    printf("Hark! The file %s hath been backed up to %s!\n", old_file_name, new_file_name);
}