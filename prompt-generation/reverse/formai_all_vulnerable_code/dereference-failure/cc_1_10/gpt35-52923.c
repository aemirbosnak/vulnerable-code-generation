//FormAI DATASET v1.0 Category: File Synchronizer ; Style: irregular
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <dirent.h> 
#include <unistd.h> 

#define BUFFER_SIZE 1024 

int synchronized_file_check(char* file_path1, char* file_path2) { 
    FILE *file1, *file2;  
    int is_same = 1; 
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE]; 

    file1 = fopen(file_path1, "r"); 
    if (file1 == NULL) { 
        return 0; 
    } 

    file2 = fopen(file_path2, "r"); 
    if (file2 == NULL) { 
        fclose(file1); 
        return 0; 
    } 

    while (!feof(file1) || !feof(file2)) { 
        fread(buffer1, 1, BUFFER_SIZE, file1); 
        fread(buffer2, 1, BUFFER_SIZE, file2); 

        if (memcmp(buffer1, buffer2, BUFFER_SIZE) != 0) { 
            is_same = 0; 
            break; 
        } 
    } 

    fclose(file1); 
    fclose(file2); 

    return is_same; 
} 

void synchronize_files_recursive(char* directory1, char* directory2) { 
    DIR *dir1, *dir2; 
    struct dirent *dir1_entry, *dir2_entry; 
    char file_path1[PATH_MAX], file_path2[PATH_MAX]; 

    dir1 = opendir(directory1); 
    if (dir1 == NULL) { 
        fprintf(stderr, "Error opening directory: %s\n", directory1); 
        return; 
    } 

    dir2 = opendir(directory2); 
    if (dir2 == NULL) { 
        fprintf(stderr, "Error opening directory: %s\n", directory2); 
        closedir(dir1); 
        return; 
    } 

    while ((dir1_entry = readdir(dir1)) != NULL) { 
        if (dir1_entry->d_type != DT_REG) { 
            continue; 
        } 

        sprintf(file_path1, "%s/%s", directory1, dir1_entry->d_name); 
        sprintf(file_path2, "%s/%s", directory2, dir1_entry->d_name); 

        if (access(file_path2, F_OK) != 0) { 
            printf("Copying new file: %s\n", file_path1); 
            if (synchronized_file_copy(file_path1, file_path2) == 0) { 
                fprintf(stderr, "Error copying file: %s\n", file_path1); 
            } else { 
                printf("File copied successfully: %s\n", file_path1); 
            } 
        } else if (!synchronized_file_check(file_path1, file_path2)) { 
            printf("Updating file: %s\n", file_path2); 
            if (synchronized_file_copy(file_path1, file_path2) == 0) { 
                fprintf(stderr, "Error updating file: %s\n", file_path2); 
            } else { 
                printf("File updated successfully: %s\n", file_path2); 
            } 
        } 
    } 

    rewinddir(dir1); 

    while ((dir2_entry = readdir(dir2)) != NULL) { 
        if (dir2_entry->d_type != DT_REG) { 
            continue; 
        } 

        sprintf(file_path1, "%s/%s", directory1, dir2_entry->d_name); 
        sprintf(file_path2, "%s/%s", directory2, dir2_entry->d_name); 

        if (access(file_path1, F_OK) != 0) { 
            printf("Deleting file: %s\n", file_path2); 
            if (remove(file_path2) != 0) { 
                fprintf(stderr, "Error deleting file: %s\n", file_path2); 
            } else { 
                printf("File deleted successfully: %s\n", file_path2); 
            } 
        } 
    } 

    closedir(dir1); 
    closedir(dir2); 
} 

int synchronized_file_copy(char* source_file_path, char* destination_file_path) { 
    FILE *source_file, *destination_file; 
    char buffer[BUFFER_SIZE]; 
    int bytes_read; 

    source_file = fopen(source_file_path, "r"); 
    if (source_file == NULL) { 
        return 0; 
    } 

    destination_file = fopen(destination_file_path, "w"); 
    if (destination_file == NULL) { 
        fclose(source_file); 
        return 0; 
    } 

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) != 0) { 
        fwrite(buffer, 1, bytes_read, destination_file); 
    } 

    fclose(source_file); 
    fclose(destination_file); 

    return 1; 
} 

int main(int argc, char* argv[]) { 
    char* directory1; 
    char* directory2; 

    if (argc < 3) { 
        printf("Usage: %s [directory1] [directory2]\n", argv[0]); 
        return 0; 
    } 

    directory1 = argv[1]; 
    directory2 = argv[2]; 

    printf("Synchronizing directories:\n%s\n%s\n", directory1, directory2); 

    synchronize_files_recursive(directory1, directory2); 

    printf("Synchronization complete.\n"); 

    return 0; 
}