//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILE_LENGTH 256
#define MAX_VIRUS_SIGNATURES 100

char virus_signatures[MAX_VIRUS_SIGNATURES][MAX_FILE_LENGTH];
int num_virus_signatures = 0;

void scan_directory(char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        fprintf(stderr, "Error: Failed to open directory '%s'\n", dir_path);
        return;
    }
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char path[MAX_PATH_LENGTH];
        snprintf(path, MAX_PATH_LENGTH, "%s/%s", dir_path, entry->d_name);
        
        if (entry->d_type == DT_DIR) {
            scan_directory(path);
        }
        else if (entry->d_type == DT_REG) {
            FILE *file = fopen(path, "rb");
            if (file == NULL) {
                fprintf(stderr, "Error: Failed to open file '%s'\n", path);
                continue;
            }
            
            char file_buf[MAX_FILE_LENGTH];
            memset(file_buf, 0, MAX_FILE_LENGTH);
            
            size_t read_size = fread(file_buf, sizeof(char), MAX_FILE_LENGTH, file);
            if (ferror(file)) {
                fprintf(stderr, "Error: Failed to read file '%s'\n", path);
                fclose(file);
                continue;
            }
            fclose(file);
            
            for (int i = 0; i < num_virus_signatures; ++i) {
                if (memcmp(file_buf, virus_signatures[i], strlen(virus_signatures[i])) == 0) {
                    printf("Virus detected in file: %s\n", path);
                    return;
                }
            }
        }
    }
    
    closedir(dir);
}

void load_virus_signatures(char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open virus signature file '%s'\n", file_path);
        return;
    }
    
    char virus_sig[MAX_FILE_LENGTH];
    while (fgets(virus_sig, MAX_FILE_LENGTH, file) != NULL) {
        virus_sig[strcspn(virus_sig, "\r\n")] = 0;
        strcpy(virus_signatures[num_virus_signatures], virus_sig);
        ++num_virus_signatures;
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <virus signatures file> <directory to scan>\n", argv[0]);
        return 0;
    }
    
    char *virus_signatures_file = argv[1];
    char *scan_directory_path = argv[2];
    
    load_virus_signatures(virus_signatures_file);
    
    scan_directory(scan_directory_path);
    
    printf("Scan complete. No viruses found.\n");
    
    return 0;
}