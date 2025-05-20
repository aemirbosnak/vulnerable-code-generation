//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a file is corrupt
int is_file_corrupt(FILE *file) {
    int c;
    while ((c = fgetc(file))!= EOF) {
        if (c < 32 || c > 126) {
            return 1; // file is corrupt
        }
    }
    return 0; // file is not corrupt
}

// Function to recover data from a corrupt file
void recover_data(const char *filename) {
    FILE *in_file = fopen(filename, "rb");
    FILE *out_file = fopen("recovered.txt", "wb");
    
    if (in_file == NULL || out_file == NULL) {
        fprintf(stderr, "Failed to open file for writing\n");
        exit(1);
    }
    
    char buffer[1024];
    int num_bytes_read = 0;
    
    while ((num_bytes_read = fread(buffer, 1, sizeof(buffer), in_file)) > 0) {
        if (is_file_corrupt(in_file)) {
            fprintf(stderr, "File is corrupt\n");
            exit(1);
        }
        
        fwrite(buffer, 1, num_bytes_read, out_file);
    }
    
    fclose(in_file);
    fclose(out_file);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    
    recover_data(argv[1]);
    
    return 0;
}