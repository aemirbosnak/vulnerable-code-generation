//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file_info {
    char* filename;
    size_t filesize;
    unsigned char* data;
} FileInfo;

int is_file_malicious(const FileInfo* file) {
    int num_malicious_bytes = 0;
    for (int i = 0; i < file->filesize; i++) {
        if (file->data[i] >= 0x80 && file->data[i] <= 0x9f) {
            num_malicious_bytes++;
        }
    }
    if (num_malicious_bytes > 50) {
        return 1;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file '%s'\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t filesize = ftell(file);
    rewind(file);

    unsigned char* data = (unsigned char*)malloc(filesize);
    size_t bytes_read = fread(data, 1, filesize, file);
    if (bytes_read!= filesize) {
        fprintf(stderr, "Failed to read file '%s'\n", argv[1]);
        return 1;
    }

    FileInfo file_info;
    file_info.filename = argv[1];
    file_info.filesize = filesize;
    file_info.data = data;

    int is_malicious = is_file_malicious(&file_info);

    if (is_malicious) {
        printf("File '%s' is malicious!\n", argv[1]);
    } else {
        printf("File '%s' is not malicious.\n", argv[1]);
    }

    free(data);
    fclose(file);
    return 0;
}