//FormAI DATASET v1.0 Category: File Backup System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 1000
#define MAX_FILE_NAME_LEN 50

struct File {
    char name[MAX_FILE_NAME_LEN];
    time_t created_time;
    char content[1000];
};

struct BackupSystem {
    struct File *files[MAX_FILES];
    int num_files;
};

void init_backup_system(struct BackupSystem *sys) {
    sys->num_files = 0;
}

void add_file(struct BackupSystem *sys, char *name, char *content) {
    struct File *new_file = malloc(sizeof(struct File));
    strcpy(new_file->name, name);
    strcpy(new_file->content, content);
    new_file->created_time = time(NULL);
    sys->files[sys->num_files++] = new_file;
}

void delete_file(struct BackupSystem *sys, int index) {
    free(sys->files[index]);
    for(int i=index+1; i<sys->num_files; i++) {
        sys->files[i-1] = sys->files[i];
    }
    sys->num_files--;
}

void print_files(struct BackupSystem *sys) {
    printf("File Backup System:\n");
    printf("%-20s %-20s %-20s\n", "File Name", "Created Time", "Content");
    for(int i=0; i<sys->num_files; i++) {
        struct File *file = sys->files[i];
        printf("%-20s %-20s %-20s\n", file->name, asctime(localtime(&file->created_time)), file->content);
    }
}

void backup_files(struct BackupSystem *sys, char *backup_file_name) {
    FILE *backup_file = fopen(backup_file_name, "w");
    if(backup_file == NULL) {
        printf("Failed to create backup file.\n");
        return;
    }
    fprintf(backup_file, "File Backup System:\n");
    fprintf(backup_file, "%-20s %-20s %-20s\n", "File Name", "Created Time", "Content");
    for(int i=0; i<sys->num_files; i++) {
        struct File *file = sys->files[i];
        fprintf(backup_file, "%-20s %-20s %-20s\n", file->name, asctime(localtime(&file->created_time)), file->content);
    }
    fclose(backup_file);
}

int main() {
    struct BackupSystem backup_sys;
    init_backup_system(&backup_sys);
    add_file(&backup_sys, "file1.txt", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    add_file(&backup_sys, "file2.txt", "Nam tellus risus, gravida ac mauris id, euismod dignissim risus.");
    add_file(&backup_sys, "file3.txt", "Pellentesque massa est, tempor vel odio a, molestie congue orci.");
    print_files(&backup_sys);
    delete_file(&backup_sys, 1);
    print_files(&backup_sys);
    backup_files(&backup_sys, "backup.txt");
    return 0;
}