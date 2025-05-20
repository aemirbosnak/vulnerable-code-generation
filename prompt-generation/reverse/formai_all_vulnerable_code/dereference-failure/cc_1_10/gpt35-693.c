//FormAI DATASET v1.0 Category: Data recovery tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main() {

    printf("Welcome to the Happy Data Recovery Tool!\n");
    printf("Let's recover some lost memories! :)\n");

    // Prompt user to enter directory path
    char directory_path[100];
    printf("Enter the directory path to scan for lost data: ");
    scanf("%s", directory_path);
    printf("\n");

    // Open the directory
    DIR *dir = opendir(directory_path);
    if (dir == NULL) {
        printf("Oops...there was an issue opening the directory. Please check the path and try again.\n");
        exit(1);
    }

    // Loop through the directory and recover lost data from each file
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Ignore current directory and parent directory
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        // Recover data from the file
        char file_path[100];
        strcpy(file_path, directory_path);
        strcat(file_path, "/");
        strcat(file_path, entry->d_name);
        FILE *file = fopen(file_path, "r");
        if (file == NULL) {
            printf("Oops...there was an issue opening file %s for data recovery.\n", entry->d_name);
            continue;
        }
        printf("Recovering lost data from file %s...\n", entry->d_name);
        char data[100];
        fgets(data, 100, file);
        printf("Recovered data: %s\n", data);
        fclose(file);
    }

    closedir(dir);
    printf("\nAll lost data has been recovered successfully! :D\n");

    return 0;
}