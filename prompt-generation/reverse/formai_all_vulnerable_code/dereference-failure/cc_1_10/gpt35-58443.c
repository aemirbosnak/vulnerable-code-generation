//FormAI DATASET v1.0 Category: File Backup System ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define BUFFER_SIZE 1024 // Define buffer size (in bytes)

void create_backup(char* filename); // Function declaration
char* get_backup_filename(char* filename); // Function declaration

int main(){

    char filename[100]; // Declare filename variable

    printf("Enter the name of the file that you want to backup: ");
    fgets(filename, 100, stdin); // Get filename from user
    strtok(filename, "\n"); // Remove newline character from end of string

    create_backup(filename); // Call create_backup function

    return 0;
}

/**
 * Create a backup of the given file.
 */
void create_backup(char* filename){

    char buffer[BUFFER_SIZE]; // Declare buffer variable

    FILE* original_file = fopen(filename, "rb"); // Open original file for reading in binary mode

    if(original_file == NULL){ // Check if file exists
        printf("Error: File not found.\n");
        return;
    }

    char* backup_filename = get_backup_filename(filename); // Get backup filename

    FILE* backup_file = fopen(backup_filename, "wb"); // Open backup file for writing in binary mode
    
    while(fread(buffer, 1, BUFFER_SIZE, original_file)){
        fwrite(buffer, 1, BUFFER_SIZE, backup_file); // Write to backup file
    }

    fclose(original_file); // Close original file
    fclose(backup_file); // Close backup file

    printf("Backup created successfully!\n");
}

/**
 * Generate a backup filename.
 */
char* get_backup_filename(char* filename){

    char* backup_filename = malloc(sizeof(char) * 200); // Allocate memory for backup filename

    time_t current_time = time(NULL); // Get current time
    struct tm* timeinfo = localtime(&current_time); // Convert current time to local time

    sprintf(backup_filename, "%s_%d-%d-%d_%d-%d-%d.bak",
            filename, timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec); // Format backup filename string

    return backup_filename;
}