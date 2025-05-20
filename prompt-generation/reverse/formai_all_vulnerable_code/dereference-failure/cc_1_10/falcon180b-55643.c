//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    char *data;
    int size;
} buffer;

void init_buffer(buffer *buf) {
    buf->data = malloc(MAX_SIZE);
    buf->size = 0;
}

void append_to_buffer(buffer *buf, char *str) {
    int new_size = buf->size + strlen(str);

    if (new_size > MAX_SIZE) {
        buf->data = realloc(buf->data, MAX_SIZE);
        memset(buf->data + buf->size, 0, MAX_SIZE - buf->size);
        buf->size = MAX_SIZE;
    } else {
        buf->data = realloc(buf->data, new_size);
    }

    strcat(buf->data, str);
    buf->size += strlen(str);
}

void print_buffer(buffer *buf) {
    printf("%s", buf->data);
}

void free_buffer(buffer *buf) {
    free(buf->data);
}

int main() {
    buffer output;
    init_buffer(&output);

    printf("Hello, world! ");
    append_to_buffer(&output, "Hello, world!\n");

    printf("Current buffer contents:\n");
    print_buffer(&output);

    free_buffer(&output);

    return 0;
}