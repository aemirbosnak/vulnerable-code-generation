//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>

#define MAX_FILES 1000
#define MAX_THREADS 10
#define MAX_FILENAME_LEN 256
#define MAX_VIRUS_SIGNATURES 5

char virus_signatures[MAX_VIRUS_SIGNATURES][20] = {     // array of virus signatures
    "virus_signature_1",
    "virus_signature_2",
    "virus_signature_3",
    "virus_signature_4",
    "virus_signature_5"
};

int num_files = 0;
char file_list[MAX_FILES][MAX_FILENAME_LEN];
int thread_index = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void scan_file_for_virus(char *filename) {
    FILE *fp;
    char line[256];
    int i, flag = 0;

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    while(fgets(line, sizeof(line), fp)) {    // scan each line in the file for virus signatures
        for(i = 0; i < MAX_VIRUS_SIGNATURES; i++) {
            if(strstr(line, virus_signatures[i])) {
                printf("Found virus signature %s in file %s\n", virus_signatures[i], filename);
                flag = 1;
                break;
            }
        }
    }

    if(flag == 0) {
        printf("No virus signatures found in file %s\n", filename);
    }

    fclose(fp);
}

void *scan_directory(void *dir_name) {
    char *directory = (char *)dir_name;
    struct dirent *dir_entry;
    DIR *current_dir = opendir(directory);

    if(current_dir == NULL) {
        printf("Error: Cannot open directory %s\n", directory);
        pthread_exit(NULL);
    }

    while((dir_entry = readdir(current_dir)) != NULL) {     // traverse the directory
        if(strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
            continue;
        }

        char file_path[MAX_FILENAME_LEN];
        snprintf(file_path, sizeof(file_path), "%s/%s", directory, dir_entry->d_name);

        if(dir_entry->d_type == DT_DIR) {    // check if the file is a directory
            printf("Processing directory: %s\n", file_path);

            pthread_mutex_lock(&mutex);    // acquire lock
            while(thread_index >= MAX_THREADS) {     // check if max threads limit reached
                pthread_mutex_unlock(&mutex);    // release lock
                sleep(1);
                pthread_mutex_lock(&mutex);    // acquire lock again
            }

            pthread_t tid;
            char *new_dir = strdup(file_path);
            pthread_create(&tid, NULL, scan_directory, (void *)new_dir);     // create new thread for the sub-directory
            thread_index++;

            pthread_mutex_unlock(&mutex);    // release lock
        } 
        else {
            printf("Processing file: %s\n", file_path);
            strcpy(file_list[num_files], file_path);
            num_files++;
        }
    }

    closedir(current_dir);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return -1;
    }

    pthread_t tid;
    char *dir_name = strdup(argv[1]);
    pthread_create(&tid, NULL, scan_directory, (void *)dir_name);    // create a new thread for the main directory
    thread_index++;

    pthread_join(tid, NULL);     // wait for all threads to finish

    int i;
    for(i = 0; i < num_files; i++) {    // scan each file for virus signatures
        printf("Scanning file: %s\n", file_list[i]);
        scan_file_for_virus(file_list[i]);
    }

    return 0;
}