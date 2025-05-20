//Falcon-180B DATASET v1.0 Category: Memory management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int size;
    char *data;
} String;

void init_string(String *string) {
    string->size = 0;
    string->data = (char *)malloc(MAX_SIZE * sizeof(char));
    if (string->data == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    string->data[0] = '\0';
}

void destroy_string(String *string) {
    free(string->data);
}

void append_string(String *string, const char *str) {
    int new_size = string->size + strlen(str) + 1;
    if (new_size > MAX_SIZE) {
        printf("Error: String too long!\n");
        exit(1);
    }
    string->data = (char *)realloc(string->data, new_size * sizeof(char));
    if (string->data == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    strcat(string->data, str);
    string->size = new_size;
}

int main() {
    String str;
    init_string(&str);

    append_string(&str, "Hear me, noble knights and fair ladies of the realm!");
    printf("The string is: %s\n", str.data);

    append_string(&str, ", I beseech thee to lendeth thine ears to my tale.");
    printf("The string is: %s\n", str.data);

    destroy_string(&str);

    return 0;
}