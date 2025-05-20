//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *string;
    int length;
} String;

typedef struct {
    String *strings;
    int count;
} StringArray;

StringArray *new_string_array(void) {
    StringArray *array = malloc(sizeof(StringArray));
    array->strings = NULL;
    array->count = 0;
    return array;
}

void free_string_array(StringArray *array) {
    for (int i = 0; i < array->count; i++) {
        free(array->strings[i].string);
    }
    free(array->strings);
    free(array);
}

StringArray *read_strings_from_file(const char *filename) {
    StringArray *array = new_string_array();
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        int length = strlen(line);
        if (line[length - 1] == '\n') {
            length--;
        }

        String string;
        string.string = malloc(length + 1);
        memcpy(string.string, line, length);
        string.string[length] = '\0';
        string.length = length;

        array->strings = realloc(array->strings, (array->count + 1) * sizeof(String));
        array->strings[array->count] = string;
        array->count++;
    }

    fclose(file);
    return array;
}

int search_string_array(StringArray *array, const char *string) {
    for (int i = 0; i < array->count; i++) {
        if (strcmp(array->strings[i].string, string) == 0) {
            return i;
        }
    }

    return -1;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    StringArray *array = read_strings_from_file(argv[1]);
    if (array == NULL) {
        return EXIT_FAILURE;
    }

    int index = search_string_array(array, argv[2]);
    if (index == -1) {
        printf("String not found.\n");
    } else {
        printf("String found at index %d.\n", index);
    }

    free_string_array(array);
    return EXIT_SUCCESS;
}