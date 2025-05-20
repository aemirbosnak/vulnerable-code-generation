//Falcon-180B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int size;
    char *data;
} String;

void init_string(String *str) {
    str->size = 0;
    str->data = NULL;
}

void free_string(String *str) {
    if (str->data!= NULL) {
        free(str->data);
    }
    init_string(str);
}

void append_string(String *str, char *data) {
    int new_size = str->size + strlen(data);
    if (new_size > MAX_SIZE) {
        printf("Error: String too long.\n");
        return;
    }
    char *new_data = realloc(str->data, new_size + 1);
    if (new_data == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    str->data = new_data;
    str->size = new_size;
    strcat(str->data, data);
}

int main() {
    String str;
    init_string(&str);

    append_string(&str, "Hello, world! ");
    printf("String: %s\n", str.data);
    append_string(&str, "How are you? ");
    printf("String: %s\n", str.data);

    free_string(&str);
    return 0;
}