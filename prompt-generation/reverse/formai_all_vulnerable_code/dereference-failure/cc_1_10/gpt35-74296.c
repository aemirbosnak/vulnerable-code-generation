//FormAI DATASET v1.0 Category: File Backup System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024
#define MAX_BACKUPS 10
#define DEFAULT_BACKUP_INTERVAL 10

char** backup_files;
int num_files = 0;

void backup(char* filename) {
    char* backup_filename = (char*) malloc(sizeof(char) * (strlen(filename) + 10));
    sprintf(backup_filename, "%s.bak", filename);

    FILE* original = fopen(filename, "r");
    FILE* backup = fopen(backup_filename, "w");

    if(original == NULL) {
        printf("Error: Failed to open file %s for backup\n", filename);
        return;
    }

    if(backup_files == NULL) {
        backup_files = (char**) malloc(sizeof(char*) * MAX_BACKUPS);
        for(int i = 0; i < MAX_BACKUPS; i++) {
            backup_files[i] = (char*) malloc(sizeof(char) * (strlen(filename) + 10));
        }
    }

    if(num_files < MAX_BACKUPS) {
        strcpy(backup_files[num_files++], backup_filename);
    } else {
        for(int i = 1; i < MAX_BACKUPS; i++) {
            remove(backup_files[i]);
            strcpy(backup_files[i - 1], backup_files[i]);
        }
        strcpy(backup_files[MAX_BACKUPS - 1], backup_filename);
    }

    if(backup == NULL) {
        printf("Error: Failed to create backup file %s\n", backup_filename);
        return;
    }

    char buffer[MAX_FILE_SIZE];
    size_t n;

    while((n = fread(buffer, sizeof(char), MAX_FILE_SIZE, original)) > 0) {
        fwrite(buffer, sizeof(char), n, backup);
    }

    fclose(original);
    fclose(backup);

    printf("File %s backed up to %s\n", filename, backup_filename);

    free(backup_filename);
}

void backup_all() {
    for(int i = 0; i < num_files; i++) {
        backup(backup_files[i]);
    }
}

int main(int argc, char** argv) {
    srand(time(NULL));

    char* filename;

    if(argc > 1) {
        filename = argv[1];
    } else {
        printf("Enter filename: ");
        filename = (char*) malloc(sizeof(char) * 256);
        fgets(filename, 256, stdin);
        filename[strlen(filename) - 1] = '\0';
    }

    int backup_interval = DEFAULT_BACKUP_INTERVAL;
    printf("Enter backup interval (default %d): ", DEFAULT_BACKUP_INTERVAL);
    char input[256];
    fgets(input, 256, stdin);
    if(input[0] != '\n') {
        backup_interval = atoi(input);
    }

    printf("Backup system initialized for file %s (interval: %d minutes)\n", filename, backup_interval);

    while(1) {
        int wait_time = (backup_interval - 1) * 60 + rand() % (2 * 60);

        printf("Waiting %d seconds for backup...\n", wait_time);

        sleep(wait_time);

        backup_all();
    }

    return 0;
}