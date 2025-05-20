//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 2048
#define MAX_KEY_SIZE 256
#define MAX_VALUE_SIZE 256

typedef struct KeyValue {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    struct KeyValue *next;
} KeyValue;

KeyValue* create_kv(char *key, char *value) {
    KeyValue *kv = (KeyValue *)malloc(sizeof(KeyValue));
    if (kv) {
        strncpy(kv->key, key, MAX_KEY_SIZE);
        strncpy(kv->value, value, MAX_VALUE_SIZE);
        kv->next = NULL;
    }
    return kv;
}

void free_kv_list(KeyValue *head) {
    while (head) {
        KeyValue *temp = head;
        head = head->next;
        free(temp);
    }
}

void trim_whitespace(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = 0;
}

char* parse_string(const char **json) {
    if (**json != '"') return NULL;

    (*json)++;
    const char *start = *json;

    while (**json && **json != '"') {
        if (**json == '\\') {
            (*json)++;
        }
        (*json)++;
    }

    size_t len = *json - start;
    char *str_value = (char *)malloc(len + 1);
    strncpy(str_value, start, len);
    str_value[len] = '\0';

    if (**json == '"') (*json)++;
    
    return str_value;
}

KeyValue* parse_json(char *json) {
    KeyValue *head = NULL;
    KeyValue *tail = NULL;

    const char *ptr = json;

    while (*ptr) {
        if (isspace(*ptr)) {
            ptr++;
            continue;
        }

        if (*ptr == '{') {
            ptr++;
            continue;
        } else if (*ptr == '}') {
            break;
        } else if (*ptr == '"') {
            char *key = parse_string(&ptr);
            if (key == NULL) continue;

            trim_whitespace((char *)ptr);
            if (*ptr == ':') ptr++; // skip the colon
            trim_whitespace((char *)ptr);

            char *value = parse_string(&ptr);
            if (value == NULL) {
                free(key);
                continue;
            }

            KeyValue *kv = create_kv(key, value);
            free(key);
            free(value);

            if (!head) {
                head = kv;
                tail = kv;
            } else {
                tail->next = kv;
                tail = kv;
            }
        }
    }

    return head;
}

void print_kv_list(KeyValue *head) {
    KeyValue *current = head;
    while (current) {
        printf("Key: %s, Value: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    char json[MAX_JSON_SIZE];

    printf("Enter JSON string (max %d characters):\n", MAX_JSON_SIZE - 1);
    if (fgets(json, MAX_JSON_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Remove trailing newline
    json[strcspn(json, "\n")] = 0;

    KeyValue *kv_list = parse_json(json);
    printf("\nParsed Key-Value Pairs:\n");
    print_kv_list(kv_list);

    // Free allocated memory
    free_kv_list(kv_list);

    return 0;
}