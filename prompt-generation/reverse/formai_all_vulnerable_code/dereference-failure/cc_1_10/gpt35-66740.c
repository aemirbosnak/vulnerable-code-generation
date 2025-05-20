//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    char* value;
} json_key_value_pair;

typedef struct {
    json_key_value_pair* pairs;
    int num_pairs;
} json_object;

typedef struct {
    char* data;
    int len;
} input;

input* read_input(const char* filename);
json_object* parse_json(const char* data, int len);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("usage: %s filename\n", argv[0]);
        exit(1);
    }

    input* in = read_input(argv[1]);

    json_object* obj = parse_json(in->data, in->len);

    printf("Parsed JSON object:\n");
    for (int i = 0; i < obj->num_pairs; i++) {
        printf("%s: %s\n", obj->pairs[i].key, obj->pairs[i].value);
    }

    free(obj->pairs);
    free(obj);
    free(in->data);
    free(in);

    return 0;
}

input* read_input(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("error opening file\n");
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    int len = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* data = malloc(len + 1);
    int bytes_read = fread(data, 1, len, f);
    if (bytes_read != len) {
        printf("error reading file\n");
        exit(1);
    }
    data[len] = '\0';

    fclose(f);

    input* in = malloc(sizeof(input));
    in->data = data;
    in->len = len;

    return in;
}

json_object* parse_json(const char* data, int len) {
    json_object* obj = malloc(sizeof(json_object));
    obj->pairs = NULL;
    obj->num_pairs = 0;

    int index = 0;
    while (index < len) {
        char next_char = data[index];
        if (next_char == '{') {
            index++;
            while (data[index] != '}') {
                int key_start_index = index;
                while (data[index] != ':') {
                    index++;
                }
                int key_end_index = index;
                index++;
                
                int value_start_index = index;
                while (data[index] != ',' && data[index] != '}') {
                    index++;
                }
                int value_end_index = index;
                index++;

                json_key_value_pair* pair = malloc(sizeof(json_key_value_pair));
                pair->key = malloc(key_end_index - key_start_index + 1);
                pair->value = malloc(value_end_index - value_start_index + 1);

                strncpy(pair->key, data + key_start_index, key_end_index - key_start_index);
                pair->key[key_end_index - key_start_index] = '\0';

                strncpy(pair->value, data + value_start_index, value_end_index - value_start_index);
                pair->value[value_end_index - value_start_index] = '\0';

                obj->num_pairs++;
                obj->pairs = realloc(obj->pairs, obj->num_pairs * sizeof(json_key_value_pair));
                obj->pairs[obj->num_pairs - 1] = *pair;
            }
        } else {
            index++;
        }
    }

    return obj;
}