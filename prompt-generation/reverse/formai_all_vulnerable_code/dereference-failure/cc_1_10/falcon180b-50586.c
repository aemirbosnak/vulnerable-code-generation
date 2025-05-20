//Falcon-180B DATASET v1.0 Category: Recursive ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} String;

String *create_string(char *data, int size) {
    String *string = (String *) malloc(sizeof(String));

    if (!string) {
        printf("Error: Unable to allocate memory.\n");
        exit(1);
    }

    string->data = (char *) malloc(size * sizeof(char));

    if (!string->data) {
        printf("Error: Unable to allocate memory.\n");
        exit(1);
    }

    string->size = size;

    strcpy(string->data, data);

    return string;
}

String *concat_strings(String *string1, String *string2) {
    int new_size = string1->size + string2->size;
    String *result = (String *) malloc(sizeof(String));

    if (!result) {
        printf("Error: Unable to allocate memory.\n");
        exit(1);
    }

    result->data = (char *) malloc(new_size * sizeof(char));

    if (!result->data) {
        printf("Error: Unable to allocate memory.\n");
        exit(1);
    }

    result->size = new_size;

    strcpy(result->data, string1->data);
    strcat(result->data, string2->data);

    return result;
}

void print_string(String *string) {
    printf("%s\n", string->data);
}

int main() {
    String *string1 = create_string("Hello, ", 6);
    String *string2 = create_string("world!", 6);
    String *string3 = concat_strings(string1, string2);
    print_string(string3);

    free(string1->data);
    free(string1);
    free(string2->data);
    free(string2);
    free(string3->data);
    free(string3);

    return 0;
}