//FormAI DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char name[50];
    time_t modified_time;
} File;

int main(){
    int file_count = 0;
    File* files = malloc(sizeof(File));
    char file_name[50];
    time_t current_time = time(NULL);

    // Add files to backup system
    while(1){
        printf("Enter file name to backup (type 'stop' to stop adding files): ");
        scanf("%s", file_name);
        if(strcmp(file_name, "stop") == 0) break;

        // Add file to files array
        File new_file;
        strcpy(new_file.name, file_name);
        new_file.modified_time = current_time;
        files[file_count] = new_file;
        file_count++;

        // Resize files array if necessary
        if(file_count%10 == 0){
            files = realloc(files, (file_count+10)*sizeof(File));
        }
    }

    // Backup files
    printf("\nBacking up files...\n");
    for(int i=0; i<file_count; i++){
        printf("Backing up %s...\n", files[i].name);

        // Create backup file name
        char backup_name[50];
        time_t backup_time = files[i].modified_time;
        strftime(backup_name, 50, "%Y%m%d%H%M%S", localtime(&backup_time));
        strcat(backup_name, "_");
        strcat(backup_name, files[i].name);

        // Create backup file
        FILE* backup_file = fopen(backup_name, "w");
        fprintf(backup_file, "This is a backup of %s.\n", files[i].name);
        fprintf(backup_file, "Backed up at %s", ctime(&backup_time));
        fclose(backup_file);
    }

    // Free memory and exit
    free(files);
    return 0;
}