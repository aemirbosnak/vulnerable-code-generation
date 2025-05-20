//FormAI DATASET v1.0 Category: File Synchronizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void add_file_to_list (char* file_name, int* count, char*** files) {
    *count += 1;
    *files = (char**) realloc (*files, *count * sizeof (char*));
    (*files)[*count-1] = (char*) malloc (strlen (file_name)+1);
    strcpy ((*files)[*count-1], file_name);
}

void sync_files (char* dir_name_1, char* dir_name_2) {
    int count_1 = 0, count_2 = 0;
    char** files_1 = NULL;
    char** files_2 = NULL;
    
    DIR* dirp_1 = opendir (dir_name_1);
    struct dirent* dp_1;
    while ((dp_1 = readdir (dirp_1)) != NULL) {
        if (strcmp (dp_1->d_name, ".") != 0 && strcmp (dp_1->d_name, "..") != 0) {
            char file_path_1[1024];
            strcpy (file_path_1, dir_name_1);
            strcat (file_path_1, "/");
            strcat (file_path_1, dp_1->d_name);

            struct stat s;
            if (stat (file_path_1, &s) == 0) {
                if (s.st_mode & S_IFREG) {
                    add_file_to_list (file_path_1, &count_1, &files_1);
                }
            }
        }
    }
    closedir (dirp_1);
    
    DIR* dirp_2 = opendir (dir_name_2);
    struct dirent* dp_2;
    while ((dp_2 = readdir (dirp_2)) != NULL) {
        if (strcmp (dp_2->d_name, ".") != 0 && strcmp (dp_2->d_name, "..") != 0) {
            char file_path_2[1024];
            strcpy (file_path_2, dir_name_2);
            strcat (file_path_2, "/");
            strcat (file_path_2, dp_2->d_name);

            struct stat s;
            if (stat (file_path_2, &s) == 0) {
                if (s.st_mode & S_IFREG) {
                    add_file_to_list (file_path_2, &count_2, &files_2);
                }
            }
        }
    }
    closedir (dirp_2);
    
    for (int i=0; i<count_1; i++) {
        int found = 0;
        for (int j=0; j<count_2; j++) {
            if (strcmp (files_1[i], files_2[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            printf ("Copying %s to %s...\n", files_1[i], dir_name_2);
            char command[1024];
            sprintf (command, "cp %s %s", files_1[i], dir_name_2);
            system (command);
        }
    }
    
    for (int i=0; i<count_2; i++) {
        int found = 0;
        for (int j=0; j<count_1; j++) {
            if (strcmp (files_2[i], files_1[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            printf ("Copying %s to %s...\n", files_2[i], dir_name_1);
            char command[1024];
            sprintf (command, "cp %s %s", files_2[i], dir_name_1);
            system (command);
        }
    }
    
    for (int i=0; i<count_1; i++) {
        free (files_1[i]);
    }
    free (files_1);
    
    for (int i=0; i<count_2; i++) {
        free (files_2[i]);
    }
    free (files_2);
}

int main () {
    sync_files ("/home/user1/folder1", "/home/user2/folder2");
    return 0;
}