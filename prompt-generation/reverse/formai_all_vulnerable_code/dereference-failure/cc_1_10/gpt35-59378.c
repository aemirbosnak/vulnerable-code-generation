//FormAI DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to define decentralized string
typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} DecentralizedString;

// initialize the decentralized string
void init_string(DecentralizedString *str, const char *data) {
    str->length = 0;
    str->capacity = strlen(data) + 1;
    str->data = malloc(str->capacity);
    strcpy(str->data, data);
    str->length = strlen(str->data);
}

// resize the decentralized string to accommodate more data
void resize_string(DecentralizedString *str, size_t new_capacity) {
    if (new_capacity <= str->capacity) {
        return;
    }

    char *new_data = malloc(new_capacity * sizeof(char));
    strcpy(new_data, str->data);

    free(str->data);
    str->data = new_data;
    str->capacity = new_capacity;
}

// append character to the end of the decentralized string
void append_char(DecentralizedString *str, char c) {  
    if (str->length == (str->capacity - 1)) {
        resize_string(str, str->capacity * 2);
    }
  
    str->data[str->length++] = c;
    str->data[str->length] = '\0';
}

// concatenate decentralized strings
void concatenate_string(DecentralizedString *str1, DecentralizedString *str2) {
    size_t new_capacity = str1->length + str2->length + 1;
  
    if (new_capacity > str1->capacity) {
        resize_string(str1, new_capacity);
    }
  
    strcat(str1->data, str2->data);
    str1->length = strlen(str1->data);
}

int main(void) {
    DecentralizedString str1, str2, str3;
  
    // initialize the strings
    init_string(&str1, "Hello, ");
    init_string(&str2, "World!");

    // concatenate the strings
    concatenate_string(&str1, &str2);

    // append character to the string
    append_char(&str1, ' ');

    // print the string
    printf("%s\n", str1.data);

    // re-initialize the strings
    init_string(&str1, "Tomorrow, ");
    init_string(&str2, "I'm");
    init_string(&str3, "going to the beach.");

    // concatenate the strings
    concatenate_string(&str1, &str2);
    concatenate_string(&str1, &str3);

    // append character to the string
    append_char(&str1, '\n');

    // print the string
    printf("%s", str1.data);

    // free the memory
    free(str1.data);
    free(str2.data);
    free(str3.data);

    return 0;
}