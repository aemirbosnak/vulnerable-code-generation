//FormAI DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    char buffer[BUFFER_SIZE];

    FILE *fp = NULL;
    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *raw_data = (unsigned char *)malloc(file_size);
    int read_count = fread(raw_data, 1, file_size, fp);

    if (read_count != file_size) {
        printf("Failed to read file\n");
        return 1;
    }

    fclose(fp);

    // Perform data recovery algorithm

    unsigned char *recovered_data = (unsigned char *)malloc(file_size);
    int recovered_count = 0;

    for (int i = 0; i < file_size; i++) {
        if (i % 2 == 0) {
            recovered_data[recovered_count] = raw_data[i];
            recovered_count++;
        }
    }

    // Write recovered data to file

    char *recovery_filename = "recovered_data.bin";
    FILE *recovery_fp = NULL;
    recovery_fp = fopen(recovery_filename, "wb");

    if (recovery_fp == NULL) {
        printf("Failed to create recovery file\n");
        return 1;
    }

    int write_count = fwrite(recovered_data, 1, recovered_count, recovery_fp);

    if (write_count != recovered_count) {
        printf("Failed to write recovery file\n");
        return 1;
    }

    fclose(recovery_fp);

    printf("Data recovery successful: %d bytes recovered\n", recovered_count);

    free(raw_data);
    free(recovered_data);

    return 0;
}