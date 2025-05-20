//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

void list_files(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("In the land of '%s':\n", path);
    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') {
            printf(" - %s\n", entry->d_name);
        }
    }
    closedir(dp);
}

void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "This file holds secrets untold!\n");
        fclose(file);
        printf("A new realm named '%s' has been created!\n", filename);
    } else {
        perror("fopen");
    }
}

void delete_file(const char *filename) {
    if (remove(filename) == 0) {
        printf("The realm '%s' has vanished into the void!\n", filename);
    } else {
        perror("remove");
    }
}

void explore_and_interact(const char *path) {
    char command[256];
    printf("Type 'list' to see the wonders, 'create <name>' to craft a new realm, 'delete <name>' to erase one, or 'exit' to leave your wanderings:\n");

    while (1) {
        printf("Wanderer at your service! > ");
        fgets(command, 256, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character
        
        if (strcmp(command, "exit") == 0) {
            printf("Farewell wanderer! Until next we meet...\n");
            break;
        } 
        else if (strcmp(command, "list") == 0) {
            list_files(path);
        } 
        else if (strncmp(command, "create ", 7) == 0) {
            create_file(command + 7);
        } 
        else if (strncmp(command, "delete ", 7) == 0) {
            delete_file(command + 7);
        } 
        else {
            printf("Unrecognized incantation! Try again...\n");
        }
    }
}

int main() {
    char *current_path = ".";
    
    printf("Welcome to the Mind-Bending File Manager!\n");
    explore_and_interact(current_path);
    
    return 0;
}