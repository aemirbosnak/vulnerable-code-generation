//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <jpeglib.h>
#include <sys/types.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILES 100

typedef struct {
    char filePath[MAX_PATH_LENGTH];
    int threadId;
} ThreadData;

void *extract_metadata(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    
    FILE *infile;
    if ((infile = fopen(data->filePath, "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", data->filePath);
        pthread_exit(NULL);
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    
    printf("Thread %d: Image: %s\n", data->threadId, data->filePath);
    printf("Thread %d: Image width: %d, height: %d\n", data->threadId, cinfo.image_width, cinfo.image_height);
    
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);
    pthread_exit(NULL);
}

void process_image_files(const char *dirPath) {
    DIR *dir;
    struct dirent *entry;
    pthread_t threads[MAX_FILES];
    ThreadData threadData[MAX_FILES];
    int threadCount = 0;

    dir = opendir(dirPath);
    if (!dir) {
        fprintf(stderr, "Error: cannot open directory %s\n", dirPath);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char *ext = strrchr(entry->d_name, '.');
            if (ext && (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".jpeg") == 0)) {
                if (threadCount >= MAX_FILES) {
                    fprintf(stderr, "Error: Maximum number of threads reached\n");
                    break;
                }
                snprintf(threadData[threadCount].filePath, MAX_PATH_LENGTH, "%s/%s", dirPath, entry->d_name);
                threadData[threadCount].threadId = threadCount;
                
                pthread_create(&threads[threadCount], NULL, extract_metadata, (void *)&threadData[threadCount]);
                threadCount++;
            }
        }
    }
    closedir(dir);

    for (int i = 0; i < threadCount; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_image_files(argv[1]);

    return EXIT_SUCCESS;
}