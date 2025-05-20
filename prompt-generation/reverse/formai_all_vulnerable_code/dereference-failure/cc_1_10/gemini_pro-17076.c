//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string_buffer {
    char *buffer;
    size_t capacity;
    size_t size;
};

struct string_buffer* string_buffer_new() {
    struct string_buffer *sb = malloc(sizeof(struct string_buffer));
    sb->buffer = malloc(16);
    sb->capacity = 16;
    sb->size = 0;
    return sb;
}

void string_buffer_free(struct string_buffer *sb) {
    free(sb->buffer);
    free(sb);
}

void string_buffer_append(struct string_buffer *sb, const char *str) {
    size_t len = strlen(str);
    if (sb->size + len >= sb->capacity) {
        while (sb->size + len >= sb->capacity) {
            sb->capacity *= 2;
        }
        sb->buffer = realloc(sb->buffer, sb->capacity);
    }
    memcpy(sb->buffer + sb->size, str, len);
    sb->size += len;
}

char* string_buffer_to_string(struct string_buffer *sb) {
    char *str = malloc(sb->size + 1);
    memcpy(str, sb->buffer, sb->size);
    str[sb->size] = '\0';
    return str;
}

int main() {
    struct string_buffer *sb = string_buffer_new();
    char *str = "Hello world!";
    string_buffer_append(sb, str);
    printf("%s\n", string_buffer_to_string(sb));
    string_buffer_free(sb);
    return 0;
}