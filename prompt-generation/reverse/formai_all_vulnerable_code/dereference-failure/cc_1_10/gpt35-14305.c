//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> // for directory operations
#include <sys/stat.h> // for file stat operations

#define MAX_THREADS 10 // Maximum number of threads allowed.

// Structure to hold metadata extracted from file.
typedef struct {
    char filename[100];
    int filesize;
    char file_extension[10];
} metadata_t;

// Structure to hold thread details.
typedef struct {
    int thread_id;
    int num_files_processed;
    char* directory_path;
} thread_details_t;

// Function to extract metadata from file.
metadata_t extract_metadata(char* filepath) {
    metadata_t metadata;
    
    struct stat filestat;
    stat(filepath, &filestat);
    strcpy(metadata.filename, filepath);
    metadata.filesize = filestat.st_size;
    
    char* ext = strrchr(filepath, '.'); // Get file extension.
    if(ext == NULL) {
        strcpy(metadata.file_extension, "Unknown");
    } else {
        strcpy(metadata.file_extension, ext+1);
    }
    
    return metadata;
}

// Function to process files in a directory and extract metadata.
void* process_directory(void* arg) {
    thread_details_t* thread_details = (thread_details_t*)arg;
    DIR* directory = opendir(thread_details->directory_path);
    struct dirent* file_entry;
    
    while((file_entry = readdir(directory)) != NULL) {
        if(file_entry->d_type == DT_REG) { // Check if it is a regular file.
            char filepath[100];
            sprintf(filepath, "%s/%s", thread_details->directory_path, file_entry->d_name);
            
            // Process file and extract metadata.
            metadata_t metadata = extract_metadata(filepath);
            
            // Print metadata.
            printf("Thread %d: Filename: %s, Filesize: %d, Extension: %s\n", thread_details->thread_id, metadata.filename, metadata.filesize, metadata.file_extension);
            thread_details->num_files_processed++; // Increase count of files processed.
        }
    }
    
    closedir(directory);
    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: %s directory_path\n", argv[0]);
        exit(1);
    }
    
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;
    int num_files_processed = 0;
    char* directory_path = argv[1];
    
    DIR* directory = opendir(directory_path);
    if(directory == NULL) {
        printf("Error opening directory at %s\n", directory_path);
        exit(1);
    }
    
    struct dirent* file_entry;
    while((file_entry = readdir(directory)) != NULL) {
        if(file_entry->d_type == DT_DIR && num_threads < MAX_THREADS) { // Check if it is a directory and maximum threads not reached.
            char subdirectory_path[100];
            sprintf(subdirectory_path, "%s/%s", directory_path, file_entry->d_name);
            
            thread_details_t* thread_details = (thread_details_t*)malloc(sizeof(thread_details_t));
            thread_details->thread_id = num_threads;
            thread_details->num_files_processed = 0;
            thread_details->directory_path = subdirectory_path;
            
            // Create thread and start processing directory.
            pthread_create(&threads[num_threads], NULL, process_directory, (void*) thread_details);
            num_threads++;
        }
    }
    
    while(num_threads > 0) { // Wait for all threads to finish processing.
        pthread_join(threads[num_threads-1], NULL);
        num_threads--;
    }
    
    rewinddir(directory); // Rewind directory to process remaining files.
    while((file_entry = readdir(directory)) != NULL) {
        if(file_entry->d_type == DT_REG) { // Check if it is a regular file.
            char filepath[100];
            sprintf(filepath, "%s/%s", directory_path, file_entry->d_name);
            
            // Process file and extract metadata.
            metadata_t metadata = extract_metadata(filepath);
            
            // Print metadata.
            printf("Main thread: Filename: %s, Filesize: %d, Extension: %s\n", metadata.filename, metadata.filesize, metadata.file_extension);
            num_files_processed++;
        }
    }
    
    closedir(directory);
    printf("Total number of files processed: %d\n", num_files_processed);
    
    return 0;
}