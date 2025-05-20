//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

struct virus_scan {
    char *file_path;
    int virus_flag;
};

void *scan_file(void *file_path) {
    FILE *file;
    struct virus_scan *scan_result;

    scan_result = (struct virus_scan *) malloc(sizeof(struct virus_scan));
    scan_result->file_path = (char *) file_path;
    scan_result->virus_flag = 0;

    file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", file_path);
        pthread_exit(NULL);
    }

    // Antivirus scanning logic goes here

    fclose(file);

    printf("Finished scanning file %s\n", file_path);
    pthread_exit((void *) scan_result);
}

int main(void) {
    pthread_t threads[4];
    struct virus_scan *scan_result;
    int i;

    char *file_paths[] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt"};
    int num_files = sizeof(file_paths)/sizeof(char *);

    for (i = 0; i < num_files; i++) {
        printf("Scanning file %s\n", file_paths[i]);
        pthread_create(&threads[i], NULL, &scan_file, (void *) file_paths[i]);
    }

    for (i = 0; i < num_files; i++) {
        pthread_join(threads[i], (void **) &scan_result);
        if (scan_result->virus_flag == 1) {
            printf("Virus detected in file %s\n", scan_result->file_path);
        } else {
            printf("No virus found in file %s\n", scan_result->file_path);
        }
        free(scan_result);
    }

    return 0;
}