//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct {
    uint16_t crc;
    uint32_t count;
    bool is_calculated;
} checksum_data_t;

typedef struct {
    const char *data;
    uint32_t length;
    checksum_data_t *checksum_data;
} thread_data_t;

void *calculate_checksum(void *thread_args) {
    thread_data_t *args = thread_args;
    const char *data = args->data;
    uint32_t length = args->length;
    uint16_t crc = 0;
    uint32_t count = 0;
    for (uint32_t i = 0; i < length; ++i) {
        crc += data[i];
        count += 1;
    }
    args->checksum_data->crc = crc;
    args->checksum_data->count = count;
    args->checksum_data->is_calculated = true;
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Syntax: %s [input_file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    fseek(input, 0, SEEK_END);
    uint32_t length = ftell(input);
    fseek(input, 0, SEEK_SET);
    char *data = (char *) malloc(length);
    fread(data, length, 1, input);
    fclose(input);
    
    checksum_data_t checksum_data[2];
    thread_data_t thread1_args = {data, length/2, &checksum_data[0]};
    thread_data_t thread2_args = {data+length/2, length-length/2, &checksum_data[1]};
    
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, calculate_checksum, (void *) &thread1_args);
    pthread_create(&thread2, NULL, calculate_checksum, (void *) &thread2_args);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    uint16_t final_crc = checksum_data[0].crc + checksum_data[1].crc;
    uint32_t final_count = checksum_data[0].count + checksum_data[1].count;
    
    printf("Checksum: 0x%04X\n", final_crc);
    printf("Byte count: %u\n", final_count);
    
    free(data);
    return 0;
}