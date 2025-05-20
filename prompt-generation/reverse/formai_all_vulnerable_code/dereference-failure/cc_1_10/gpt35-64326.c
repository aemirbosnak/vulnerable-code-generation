//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    char *key;
    char *value;
} pair_t;

typedef struct {
    pair_t *pairs;
    int pair_count;
} object_t;

typedef struct {
    char *key;
    object_t *object;
} json_t;

char* read_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file: %s", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(size + 1);
    fread(buffer, size, 1, file);

    fclose(file);

    buffer[size] = '\0';
    return buffer;
}

int parse_pair(char *buffer, pair_t *pair) {
    // Locate the key
    char *start = strstr(buffer, "\"") + 1;
    char *end = strstr(start, "\"");

    // Copy the key string into memory
    int length = end - start;
    char *key = malloc(length + 1);
    memcpy(key, start, length);
    key[length] = '\0';

    pair->key = key;

    // Locate the value
    start = strstr(end + 1, "\"") + 1;
    end = strstr(start, "\"");

    // Copy the value string into memory
    length = end - start;
    char *value = malloc(length + 1);
    memcpy(value, start, length);
    value[length] = '\0';

    pair->value = value;

    // Add 1 to the buffer to skip over the closing quote
    return end - buffer + 1;
}

int parse_object(char *buffer, object_t *object) {
    int consumed = 0;

    // Count the number of pairs in the object
    char *ptr = strchr(buffer, ':');
    while (ptr != NULL) {
        object->pair_count++;
        ptr = strchr(ptr + 1, ':');
    }

    // Allocate memory for the pairs
    object->pairs = malloc(sizeof(pair_t) * object->pair_count);

    // Parse each pair
    for (int i = 0; i < object->pair_count; i++) {
        pair_t *pair = &object->pairs[i];
        consumed += parse_pair(&buffer[consumed], pair);

        // Skip to the next comma
        if (i < object->pair_count - 1) {
            consumed += 1;
        }
    }

    return consumed;
}

json_t* parse_json(char *buffer) {
    // Create the root JSON object
    json_t *json = malloc(sizeof(json_t));

    // Locate the key
    char *start = strstr(buffer, "\"") + 1;
    char *end = strstr(start, "\"");

    // Copy the key string into memory
    int length = end - start;
    char *key = malloc(length + 1);
    memcpy(key, start, length);
    key[length] = '\0';

    json->key = key;

    // Parse the contained object
    object_t *object = malloc(sizeof(object_t));
    int consumed = parse_object(end, object);

    json->object = object;

    return json;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    char *buffer = read_file(argv[1]);
    if (buffer == NULL) {
        return 1;
    }

    json_t *json = parse_json(buffer);

    printf("Key: %s\n", json->key);
    printf("Pairs:\n");
    for (int i = 0; i < json->object->pair_count; i++) {
        pair_t *pair = &json->object->pairs[i];
        printf("%s: %s\n", pair->key, pair->value);
    }

    free(buffer);
    free(json->key);
    free(json->object->pairs);
    free(json->object);
    free(json);

    return 0;
}