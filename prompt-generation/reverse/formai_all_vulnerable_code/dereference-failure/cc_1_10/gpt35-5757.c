//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>

#define MAX_FILES 1000
#define MAX_PATH 256
#define MAX_VIRUS_SIGNATURES 10

char virus_signatures[MAX_VIRUS_SIGNATURES][10] = {"Worm", "Trojan", "Malware", "Spyware", "Ransomware", "Adware", "Rootkit", "Keylogger", "Scareware", "Backdoor"};
char files[MAX_FILES][MAX_PATH];

void *scanFiles(void *arg) {
    char *path = (char *) arg;
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        pthread_exit(NULL);
    }

    while ((entry = readdir(dir))) {
        char filepath[MAX_PATH];
        strcpy(filepath, path);
        strcat(filepath, "/");
        strcat(filepath, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            pthread_t tid;
            pthread_create(&tid, NULL, scanFiles, filepath);
            pthread_join(tid, NULL);
        } else {
            for (int i = 0; i < MAX_VIRUS_SIGNATURES; i++) {
                if (strstr(entry->d_name, virus_signatures[i])) {
                    printf("Virus found in file: %s\n", filepath);
                    break;
                }
            }
        }
    }

    closedir(dir);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [directory path]\n", argv[0]);
        exit(0);
    }

    DIR *dir;
    struct dirent *entry;

    dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Error opening directory");
        exit(0);
    }

    int count = 0;
    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_REG) {
            strcpy(files[count], argv[1]);
            strcat(files[count], "/");
            strcat(files[count], entry->d_name);
            count++;
        }
    }

    closedir(dir);
    
    pthread_t thread[count];
    for (int i = 0; i < count; i++) {
        pthread_create(&thread[i], NULL, scanFiles, files[i]);
    }

    for (int i = 0; i < count; i++) {
        pthread_join(thread[i], NULL);
    }

    return 0;
}