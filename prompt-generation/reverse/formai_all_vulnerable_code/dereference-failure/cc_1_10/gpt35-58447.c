//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILENAME_LENGTH 256

/* Function to check if a file is a virus */
int isVirus(char *filename) {
    int virus_detected = 0;
    char *virus_list[] = {"trojan", "worm", "malware", "rootkit"};

    for(int i = 0; i < sizeof(virus_list)/sizeof(char*); i++) {
        if(strstr(filename, virus_list[i]) != NULL) {
            virus_detected = 1;
            break;
        }
    }
    return virus_detected;
}

/* Function to recursively scan directories for viruses */
void scanDirectory(char *directory) {
    DIR *dir;
    struct dirent *entry;
    char filename[MAX_FILENAME_LENGTH];

    if((dir = opendir(directory)) == NULL) {
        perror("Unable to open directory");
        exit(1);
    }

    while((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            sprintf(filename, "%s/%s", directory, entry->d_name);
            if(entry->d_type == DT_DIR) {
                scanDirectory(filename);
            } else {
                if(isVirus(entry->d_name)) {
                    printf("Virus detected: %s\n", filename);
                }
            }
        }
    }
    closedir(dir);
}

/* Main function */
int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s directory\n", argv[0]);
        exit(1);
    }

    char *directory = argv[1];
    scanDirectory(directory);

    printf("Scan complete!\n");
    return 0;
}