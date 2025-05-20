//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define READ_BUFFER_SIZE 1024
#define WRITE_BUFFER_SIZE 512

struct thread_params {
    char* read_buffer;
    char* write_buffer;
    int read_size;
    int* write_size;
};

void* compress(void* arg) {
    struct thread_params* params = (struct thread_params*) arg;
    char* read_buffer = params->read_buffer;
    char* write_buffer = params->write_buffer;
    int read_size = params->read_size;
    int* write_size = params->write_size;

    int i, j, count;
    char current_char, last_char;

    last_char = read_buffer[0];
    count = 0;
    j = 0;
    for (i = 0; i < read_size; i++) {
        current_char = read_buffer[i];
        if (current_char == last_char) {
            count++;
        } else {
            write_buffer[j++] = last_char;
            if (count > 1) {
                write_buffer[j++] = '0' + count;
            }
            last_char = current_char;
            count = 1;
        }
    }

    write_buffer[j++] = last_char;
    if (count > 1) {
        write_buffer[j++] = '0' + count;
    }

    *write_size = j;

    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    char* read_buffer;
    char* write_buffer;
    int read_size;
    int write_size;
    struct thread_params params;
    pthread_t thread_id;

    read_buffer = (char*) malloc(READ_BUFFER_SIZE);
    write_buffer = (char*) malloc(WRITE_BUFFER_SIZE);

    while (fgets(read_buffer, READ_BUFFER_SIZE, stdin) != NULL) {
        read_size = strlen(read_buffer);
        if (read_buffer[read_size - 1] == '\n') {
            read_buffer[--read_size] = '\0';
        }

        params.read_buffer = read_buffer;
        params.write_buffer = write_buffer;
        params.read_size = read_size;
        params.write_size = &write_size;

        pthread_create(&thread_id, NULL, compress, (void*) &params);
        pthread_join(thread_id, NULL);

        fwrite(write_buffer, sizeof(char), write_size, stdout);
        fwrite("\n", sizeof(char), 1, stdout);
    }

    free(read_buffer);
    free(write_buffer);

    return 0;
}