//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#define MAX_THREADS 5
#define MAX_FILE_NAME_LENGTH 100
#define MAX_METADATA_LENGTH 200

void* extract_metadata_from_file(void* args);

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: ./metadata_extractor file_1 file_2 file_3 ...\n");
        exit(1);
    }

    pthread_t threads[MAX_THREADS];
    int rc;

    int i, j=0;
    for(i=1; i<argc; i++) {
        rc = pthread_create(&threads[j], NULL, extract_metadata_from_file, (void*)argv[i]);
        if(rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(1);
        }
        j++;
        if(j == MAX_THREADS) {
            for(int k=0; k<j; k++) {
                pthread_join(threads[k], NULL);
            }
            j=0;
        }
    }

    for(i=0; i<j; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
}


void* extract_metadata_from_file(void* args) {
    char* file_name = (char*)args;

    char command[strlen(file_name) + 50]; 
    sprintf(command, "mdls -name kMDItemDurationSeconds -name kMDItemContentTypeTree -raw %s", file_name);

    FILE* fp = popen(command, "r");

    char metadata[MAX_METADATA_LENGTH];
    fgets(metadata, MAX_METADATA_LENGTH, fp);

    printf("Metadata for %s: %s\n", file_name, metadata);

    pclose(fp);
    pthread_exit(NULL);
}