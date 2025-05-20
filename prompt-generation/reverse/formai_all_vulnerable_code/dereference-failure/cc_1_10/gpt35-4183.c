//FormAI DATASET v1.0 Category: File Backup System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

void copy_file(char *source, char *destination) {
    FILE *fs, *fd;

    fs = fopen(source, "r");
    fd = fopen(destination, "w");

    char current_char = fgetc(fs);

    while (current_char != EOF) {
        fputc(current_char, fd);
        current_char = fgetc(fs);
    }

    fclose(fs);
    fclose(fd);
}

int main() {
    char source_file[MAX_LENGTH], destination_file[MAX_LENGTH], confirm[5];
    time_t current_time = time(NULL);
    struct tm *tm = localtime(&current_time);
    char timestamp[MAX_LENGTH];

    printf("Welcome to the File Backup System!\n\n");

    printf("Please enter the name of the file you would like to backup: ");
    fgets(source_file, MAX_LENGTH, stdin);
    source_file[strcspn(source_file, "\n")] = 0;

    printf("Please enter the name you would like to give to the backup file: ");
    fgets(destination_file, MAX_LENGTH, stdin);
    destination_file[strcspn(destination_file, "\n")] = 0;

    sprintf(timestamp, "_%d-%02d-%02d_%02d%02d%02d", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

    strcat(destination_file, timestamp);
    strcat(destination_file, ".bak");

    printf("\nYou are about to backup '%s' to '%s'.\n", source_file, destination_file);

    printf("Do you want to continue? (yes/no) ");
    fgets(confirm, 5, stdin);
    confirm[strcspn(confirm, "\n")] = 0;

    if (strcmp(confirm, "yes") == 0) {
        copy_file(source_file, destination_file);
        printf("\nBackup complete!\n");
    } else {
        printf("\nBackup cancelled.\n");
    }

    return 0;
}