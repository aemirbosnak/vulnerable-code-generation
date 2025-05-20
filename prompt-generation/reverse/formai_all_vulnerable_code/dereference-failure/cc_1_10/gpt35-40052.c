//FormAI DATASET v1.0 Category: File Synchronizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILES 1000

char source_path[MAX_PATH_LENGTH];
char dest_path[MAX_PATH_LENGTH];
char files[MAX_FILES][MAX_PATH_LENGTH];
int file_count = 0;

void display_menu() {
    printf("Welcome to the C File Synchronizer\n");
    printf("----------------------------------\n\n");
    printf("Select an option:\n");
    printf("1. Synchronize files\n");
    printf("2. Exit\n");
}

void synchronize_files() {
    printf("Enter the source path: ");
    fgets(source_path, MAX_PATH_LENGTH, stdin);
    source_path[strcspn(source_path, "\n")] = '\0';

    printf("Enter the destination path: ");
    fgets(dest_path, MAX_PATH_LENGTH, stdin);
    dest_path[strcspn(dest_path, "\n")] = '\0';

    printf("Synchronizing files...\n");

    DIR *dir = opendir(source_path);
    struct dirent *ent;

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
            char src_file_path[MAX_PATH_LENGTH];
            char dest_file_path[MAX_PATH_LENGTH];
            struct stat st;

            snprintf(src_file_path, MAX_PATH_LENGTH, "%s/%s", source_path, ent->d_name);
            snprintf(dest_file_path, MAX_PATH_LENGTH, "%s/%s", dest_path, ent->d_name);

            stat(src_file_path, &st);

            if (S_ISDIR(st.st_mode)) {
                mkdir(dest_file_path, st.st_mode);
                synchronize_files();
            } else {
                strcpy(files[file_count], ent->d_name);
                file_count++;
            }
        }
    }

    closedir(dir);

    for (int i = 0; i < file_count; i++) {
        char src_file_path[MAX_PATH_LENGTH];
        char dest_file_path[MAX_PATH_LENGTH];
        
        snprintf(src_file_path, MAX_PATH_LENGTH, "%s/%s", source_path, files[i]);
        snprintf(dest_file_path, MAX_PATH_LENGTH, "%s/%s", dest_path, files[i]);
        
        FILE *src_file = fopen(src_file_path, "rb");
        FILE *dest_file = fopen(dest_file_path, "wb");
        
        if (src_file != NULL && dest_file != NULL) {
            fseek(src_file, 0, SEEK_END);
            long file_size = ftell(src_file);
            fseek(src_file, 0, SEEK_SET);
            
            char buffer[file_size];
            fread(buffer, sizeof(char), file_size, src_file);
            fwrite(buffer, sizeof(char), file_size, dest_file);
            
            printf("Synchronized: %s\n", files[i]);
        }
        
        fclose(src_file);
        fclose(dest_file);
    }

    printf("Synchronization complete!\n");
}

int main() {
    int option;

    do {
        display_menu();
        scanf("%d", &option);
        getchar(); // To consume the newline character in stdin

        switch (option) {
            case 1:
                synchronize_files();
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 2);

    return 0;
}