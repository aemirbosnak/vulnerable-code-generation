//FormAI DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program creates a system administrator tool that helps manage file backups */

int main() {
    
    // Set up variables to store file information
    
    char filename[20];
    char backup[20];
    int backup_num = 0;
    
    // Get user input for the filename
    
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    
    // Generate backup filename with timestamp
    
    time_t current_time;
    struct tm * time_info;
    char time_str[20];
    
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d_%H:%M:%S", time_info);
    sprintf(backup, "%s_%s", filename, time_str);
    
    // Check if backup already exists
    
    FILE *f;
    f = fopen(backup, "r");
    
    if (f != NULL) {
        printf("A backup already exists with the same name.\n");
        fclose(f);
        
        // Increment backup number and regenerate filename
        
        backup_num++;
        sprintf(backup, "%s_%s_%d", filename, time_str, backup_num);
        f = fopen(backup, "r");
    }
    
    // Create backup file
    
    FILE *orig, *copy;
    orig = fopen(filename, "r");
    copy = fopen(backup, "w+");
    char c;
    
    if (orig == NULL) {
        printf("Error opening source file.\n");
    } else {
        while ((c = fgetc(orig)) != EOF) {
            fputc(c, copy);
        }
        
        printf("Backup successfully created: %s\n", backup);
        fclose(orig);
        fclose(copy);
    }
    
    return 0;
}