//FormAI DATASET v1.0 Category: File Synchronizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

// Define maximum directory and file name length
#define MAX_PATH_LENGTH 2048
#define MAX_FILE_NAME_LENGTH 256

// Helper function to get next character in string comparison
char getch(const char* str, int i) {
    char ch = str[i];
    if (ch >= 'A' && ch <= 'Z')
        ch = ch - 'A' + 'a';
    return ch;
}

// Helper function to compare two strings ignoring case sensitivity
int strcasecmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        char ch1 = getch(str1, i);
        char ch2 = getch(str2, i);
        if (ch1 < ch2)
            return -1;
        else if (ch1 > ch2)
            return 1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return 0;
    else if (str1[i] == '\0')
        return -1;
    else
        return 1;
}

// Helper function to check if a directory exists
int directory_exists(const char* directory_path) {
    DIR* directory = opendir(directory_path);
    if (directory != NULL) {
        closedir(directory);
        return 1;
    }
    else {
        return 0;
    }
}

// Helper function to create a directory if it does not exist
int create_directory(const char* directory_path) {
    if (!directory_exists(directory_path)) {
        if (mkdir(directory_path, 0777) == -1) {
            printf("Unable to create directory: %s\n", directory_path);
            return 0;
        }
    }
    return 1;
}

// Helper function to synchronize two directories recursively
int synchronize_directories(const char* source_directory_path, const char* destination_directory_path) {
    // Check if source and destination directories exist
    if (!directory_exists(source_directory_path)) {
        printf("Source directory does not exist: %s\n", source_directory_path);
        return 0;
    }
    if (!create_directory(destination_directory_path)) {
        printf("Unable to create destination directory: %s\n", destination_directory_path);
        return 0;
    }

    // Open source directory and iterate over files and subdirectories
    DIR* source_directory = opendir(source_directory_path);
    if (source_directory == NULL) {
        printf("Unable to open source directory: %s\n", source_directory_path);
        return 0;
    }
    struct dirent* source_entry;
    while ((source_entry = readdir(source_directory)) != NULL) {
        // Ignore . and .. entries
        if (strcmp(source_entry->d_name, ".") == 0 || strcmp(source_entry->d_name, "..") == 0)
            continue;

        // Construct full paths for source and destination files/directories
        char source_path[MAX_PATH_LENGTH];
        char destination_path[MAX_PATH_LENGTH];
        snprintf(source_path, sizeof(source_path), "%s/%s", source_directory_path, source_entry->d_name);
        snprintf(destination_path, sizeof(destination_path), "%s/%s", destination_directory_path, source_entry->d_name);

        // Check if source file/directory exists
        if (source_entry->d_type == DT_DIR) { // If source entry is a directory, recursively synchronize directories
            if (!synchronize_directories(source_path, destination_path)) {
                closedir(source_directory);
                return 0;
            }
        }
        else { // If source entry is a file, synchronize file
            FILE* source_file = fopen(source_path, "rb");
            if (source_file == NULL) {
                printf("Unable to open source file: %s\n", source_path);
                closedir(source_directory);
                return 0;
            }
            FILE* destination_file = fopen(destination_path, "rb");
            if (destination_file == NULL) {
                // Destination file does not exist, copy source file to destination
                destination_file = fopen(destination_path, "wb");
                if (destination_file == NULL) {
                    printf("Unable to create destination file: %s\n", destination_path);
                    fclose(source_file);
                    closedir(source_directory);
                    return 0;
                }
                int ch;
                while ((ch = fgetc(source_file)) != EOF) {
                    if (fputc(ch, destination_file) == EOF) {
                        printf("Error writing to destination file: %s\n", destination_path);
                        fclose(source_file);
                        fclose(destination_file);
                        closedir(source_directory);
                        return 0;
                    }
                }
                fclose(destination_file);
            }
            else {
                // Destination file exists, check if files are the same
                fseek(source_file, 0, SEEK_END);
                long source_file_size = ftell(source_file);
                fseek(destination_file, 0, SEEK_END);
                long destination_file_size = ftell(destination_file);
                if (source_file_size != destination_file_size) {
                    printf("Source file size does not match destination file size: %s\n", destination_path);
                    fclose(source_file);
                    fclose(destination_file);
                    closedir(source_directory);
                    return 0;
                }
                fseek(source_file, 0, SEEK_SET);
                fseek(destination_file, 0, SEEK_SET);
                char source_buffer[source_file_size];
                char destination_buffer[destination_file_size];
                fread(source_buffer, source_file_size, 1, source_file);
                fread(destination_buffer, destination_file_size, 1, destination_file);
                if (memcmp(source_buffer, destination_buffer, source_file_size) != 0) {
                    printf("Source file content does not match destination file content: %s\n", destination_path);
                    fclose(source_file);
                    fclose(destination_file);
                    closedir(source_directory);
                    return 0;
                }
                fclose(destination_file);
            }
            fclose(source_file);
        }
    }
    closedir(source_directory);
    return 1;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }
    char* source_directory_path = argv[1];
    char* destination_directory_path = argv[2];
    if (!synchronize_directories(source_directory_path, destination_directory_path)) {
        printf("Directory synchronization failed\n");
        return 1;
    }
    printf("Directory synchronization successful\n");
    return 0;
}