//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char* data;
    int size;
} buffer_t;

int get_checksum(buffer_t* buffer) {
    int checksum = 0;
    for (int i = 0; i < buffer->size; i++) {
        checksum += buffer->data[i];
    }
    return checksum;
}

void handle_data(buffer_t* buffer) {
    int checksum = get_checksum(buffer);
    printf("Checksum: %d\n", checksum);
}

void receive_data(buffer_t* buffer) {
    char c;
    while (scanf("%c", &c)!= EOF) {
        if (buffer->size >= MAX_SIZE) {
            printf("Error: Buffer overflow\n");
            exit(1);
        }
        buffer->data[buffer->size++] = c;
    }
}

int main() {
    buffer_t buffer;
    buffer.data = malloc(MAX_SIZE);
    buffer.size = 0;

    while (1) {
        receive_data(&buffer);
        if (buffer.size == 0) {
            continue;
        }
        handle_data(&buffer);
        memset(buffer.data, 0, buffer.size);
        buffer.size = 0;
    }

    return 0;
}