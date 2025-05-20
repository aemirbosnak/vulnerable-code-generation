//FormAI DATASET v1.0 Category: File Backup System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// function to copy the contents of one file to another
void copy_file(FILE *source, FILE *destination) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    
    // read in blocks of BUFFER_SIZE and write to destination file
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source))) {
        fwrite(buffer, 1, bytes_read, destination);
    }
}

// function to backup a file to a specified location
void backup_file(char *filename, char *location) {
    // open the source file
    FILE *source = fopen(filename, "r");
    if (!source) {
        printf("Error: could not open file %s\n", filename);
        return;
    }
    
    // ensure that the specified backup location exists
    if (!access(location, F_OK)) {
        printf("Error: backup location %s already exists\n", location);
        fclose(source);
        return;
    }
    
    if (mkdir(location, 0777)) {
        printf("Error: could not create backup location %s\n", location);
        fclose(source);
        return;
    }
    
    // get the filename only (without path)
    char *backup_filename = strrchr(filename, '/');
    if (backup_filename) {
        backup_filename++;
    } else {
        backup_filename = filename;
    }
    
    // build the backup file path
    char backup_path[BUFFER_SIZE];
    snprintf(backup_path, BUFFER_SIZE, "%s/%s.bak", location, backup_filename);
    
    // open the destination file
    FILE *destination = fopen(backup_path, "w");
    if (!destination) {
        printf("Error: could not open backup file %s\n", backup_path);
        fclose(source);
        return;
    }
    
    // copy the contents of the source file to the destination file
    copy_file(source, destination);
    
    // close the files
    fclose(source);
    fclose(destination);
    
    printf("File %s backed up to %s\n", filename, backup_path);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s [filename] [backup location]\n", argv[0]);
        return 0;
    }
    
    backup_file(argv[1], argv[2]);
    
    return 0;
}