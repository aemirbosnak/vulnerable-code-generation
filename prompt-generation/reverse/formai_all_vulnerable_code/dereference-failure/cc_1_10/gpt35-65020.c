//FormAI DATASET v1.0 Category: Data recovery tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FILE_SIZE 1048576    // 1MB

struct File {
    char name[50];
    unsigned char data[MAX_FILE_SIZE];
    unsigned int size;
};

void recover_file(struct File* file_list, int num_files, int file_num) {
    printf("Recovering File %d: %s\n", file_num+1, file_list[file_num].name);
    
    // Create a new file with recovered data
    FILE* recovered_file = fopen(file_list[file_num].name, "wb");
    if(recovered_file == NULL) {
        printf("Error: Failed to create recovered file!\n");
        exit(EXIT_FAILURE);
    }
    fwrite(file_list[file_num].data, sizeof(unsigned char), file_list[file_num].size, recovered_file);
    fclose(recovered_file);
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s <file1> <file2> ...\n", argv[0]);
        return 0;
    }
    
    // Create a list of files to recover
    int num_files = argc-1;
    struct File* file_list = malloc(num_files * sizeof(struct File));
    
    for(int i=0; i<num_files; i++) {
        // Read file data into memory
        FILE* file = fopen(argv[i+1], "rb");
        if(file == NULL) {
            printf("Error: Failed to open file %s!\n", argv[i+1]);
            exit(EXIT_FAILURE);
        }
        
        file_list[i].size = fread(file_list[i].data, sizeof(unsigned char), MAX_FILE_SIZE, file);
        fclose(file);
        
        // Save file name
        strncpy(file_list[i].name, argv[i+1], 49);
        file_list[i].name[49] = '\0';
    }
    
    // Scan file data for magic bytes
    bool* is_recoverable = calloc(num_files, sizeof(bool));
    for(int i=0; i<num_files; i++) {
        unsigned char* data = file_list[i].data;
        int size = file_list[i].size;
        
        if(size < 4 || data[0] != 0xDE || data[1] != 0xAD || data[2] != 0xBE || data[3] != 0xEF) {
            // Not recoverable if file size is too small or does not contain magic bytes
            is_recoverable[i] = false;
            continue;
        }
        
        // If data contains magic bytes, assume it is recoverable
        is_recoverable[i] = true;
    }
    
    // Recover recoverable files
    int num_recovered = 0;
    for(int i=0; i<num_files; i++) {
        if(is_recoverable[i]) {
            recover_file(file_list, num_files, i);
            num_recovered++;
        }
    }
    
    // Print recovery stats and free memory
    printf("Recovered %d out of %d files.\n", num_recovered, num_files);
    free(file_list);
    free(is_recoverable);

    return 0;
}