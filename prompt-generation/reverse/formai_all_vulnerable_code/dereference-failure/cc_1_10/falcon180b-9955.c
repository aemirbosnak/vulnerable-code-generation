//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

struct string_t {
    char* text;
    int length;
};

struct string_t* create_string(char* text) {
    struct string_t* new_string = (struct string_t*)malloc(sizeof(struct string_t));
    new_string->text = (char*)malloc(strlen(text) + 1);
    strcpy(new_string->text, text);
    new_string->length = strlen(text);
    return new_string;
}

void destroy_string(struct string_t* string) {
    free(string->text);
    free(string);
}

void print_string(struct string_t* string) {
    printf("%s\n", string->text);
}

int main() {
    char* input_buffer = (char*)malloc(MAX_STRING_LENGTH);
    int input_buffer_length = 0;
    int input_buffer_capacity = MAX_STRING_LENGTH;
    struct string_t* input_string = NULL;
    int exit_code = 0;

    while (exit_code == 0) {
        printf("Enter text (up to %d characters):\n", MAX_STRING_LENGTH - 1);
        fgets(input_buffer, input_buffer_capacity, stdin);
        input_buffer_length = strlen(input_buffer);
        if (input_buffer_length > 0 && input_buffer[input_buffer_length - 1] == '\n') {
            input_buffer[input_buffer_length - 1] = '\0';
            input_buffer_length--;
        }
        if (input_buffer_length > 0) {
            if (input_string == NULL) {
                input_string = create_string(input_buffer);
            } else {
                struct string_t* new_string = create_string(input_buffer);
                input_string->text = (char*)realloc(input_string->text, input_string->length + new_string->length + 1);
                strcat(input_string->text, new_string->text);
                destroy_string(new_string);
                input_string->length += new_string->length;
            }
        } else {
            exit_code = 1;
        }
    }

    print_string(input_string);
    destroy_string(input_string);
    free(input_buffer);

    return 0;
}