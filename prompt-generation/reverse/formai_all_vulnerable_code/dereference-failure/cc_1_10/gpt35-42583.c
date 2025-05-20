//FormAI DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100 //Maximum number of files to backup

typedef struct {
    char* filename;
    time_t timestamp;
} backup_file;

backup_file* backup_list[SIZE]; //Array of pointers to backup_file structs
int backup_count = 0; //Number of files currently in backup_list

//Function to add a file to the backup list
void add_backup_file(char* filename) {
    if (backup_count >= SIZE) {
        printf("Error: Backup list is full\n");
        return;
    }
    
    backup_file* new_file = malloc(sizeof(backup_file));
    new_file->filename = filename;
    new_file->timestamp = time(NULL);
    backup_list[backup_count] = new_file;
    backup_count++;
    
    printf("File '%s' has been added to the backup list\n", filename);
}

//Function to remove a file from the backup list
void remove_backup_file(char* filename) {
    int index = -1;
    for (int i = 0; i < backup_count; i++) {
        if (strcmp(backup_list[i]->filename, filename) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Error: File '%s' is not in the backup list\n", filename);
        return;
    }
    
    free(backup_list[index]);
    backup_count--;
    for (int i = index; i < backup_count; i++) {
        backup_list[i] = backup_list[i+1];
    }
    
    printf("File '%s' has been removed from the backup list\n", filename);
}

//Function to print the backup list
void print_backup_list() {
    printf("Backup list:\n");
    for (int i = 0; i < backup_count; i++) {
        printf("%s\t\t%s", backup_list[i]->filename, ctime(&backup_list[i]->timestamp));
    }
}

int main() {
    char* file1 = "file1.txt";
    char* file2 = "file2.txt";
    char* file3 = "file3.txt";
    char* file4 = "file4.txt";
    
    add_backup_file(file1);
    add_backup_file(file2);
    add_backup_file(file3);
    add_backup_file(file4);
    
    print_backup_list();
    
    remove_backup_file(file2);
    remove_backup_file(file3);
    
    print_backup_list();
    
    return 0;
}