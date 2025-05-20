//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> // for directory traversing
#include <regex.h> // for regex pattern matching

#define MAX_BUF_SIZE 1024
#define VIRUS_SIGNATURE "malware" // change this to actual virus signature

int is_file_infected(const char *filename) {
    FILE *fp;
    char buf[MAX_BUF_SIZE];
    int len;
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }
    
    // read file content
    len = fread(buf, sizeof(char), MAX_BUF_SIZE, fp);
    
    if (len < 0) {
        perror("Error reading file");
        return -1;
    }
    
    // check if file content contains virus signature
    if (strstr(buf, VIRUS_SIGNATURE) != NULL) {
        fclose(fp);
        return 1; // file infected
    }
    
    fclose(fp);
    return 0; // file not infected
}

int scan_directory(const char *dirname) {
    DIR *dir;
    struct dirent *entry;
    int found = 0; // number of infected files found
    
    dir = opendir(dirname);
    if (dir == NULL) {
        perror("Error opening directory");
        return -1;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        char fullpath[MAX_BUF_SIZE];
        strcpy(fullpath, dirname);
        strcat(fullpath, "/");
        strcat(fullpath, entry->d_name);
        
        // skip current and parent directory
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // check if file is infected
        if (is_file_infected(fullpath) == 1) {
            printf("Infected file found: %s\n", fullpath);
            found++;
        }
        
        // if directory, scan it recursively
        if (entry->d_type == DT_DIR) {
            scan_directory(fullpath);
        }
    }
    
    closedir(dir);
    return found;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Usage: %s directory\n", argv[0]);
        exit(EXIT_SUCCESS);
    }
    
    // compile regex pattern to ignore certain files and directories
    regex_t reg;
    regcomp(&reg, "^\\.\\.?$|\\.bak$|\\.exe$|\\.dll$|\\.so$|\\.out$|\\.o$|\\.a$|\\.txt$",
        REG_EXTENDED | REG_NOSUB);
    
    int found = 0;
    for (int i = 1; i < argc; i++) {
        if (regexec(&reg, argv[i], 0, NULL, 0) == 0) {
            printf("Ignoring %s\n", argv[i]);
            continue;
        }
        printf("Scanning %s\n", argv[i]);
        found += scan_directory(argv[i]);
    }
    
    printf("Total infected files found: %d\n", found);
    
    regfree(&reg);
    return 0;
}