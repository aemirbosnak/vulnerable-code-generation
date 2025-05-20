//FormAI DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void backup_file(char* filename);

int main(int argc, char** argv){
    if(argc < 2){
        printf("Usage: ./backup <filename1> <filename2> ...\n");
        return 0;
    }
    
    for(int i = 1; i < argc; i++){
        backup_file(argv[i]);
    }
    
    return 0;
}

void backup_file(char* filename){
    // Open file for reading
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("Could not open file %s\n", filename);
        return;
    }
    
    // Determine filename of backup file
    char* backup_filename = malloc(sizeof(char) * (strlen(filename) + 5));
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
    
    // Open file for writing
    FILE* backup_file = fopen(backup_filename, "w");
    if(backup_file == NULL){
        printf("Could not create backup file for %s\n", filename);
        fclose(file);
        free(backup_filename);
        return;
    }
    
    // Copy contents of original file to backup file
    char buffer[1024];
    size_t bytes_read;
    while((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file)) > 0){
        fwrite(buffer, sizeof(char), bytes_read, backup_file);
    }
    
    // Close files and free memory
    fclose(file);
    fclose(backup_file);
    free(backup_filename);
    
    printf("%s backed up successfully!\n", filename);
}