//FormAI DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program parses a given C syntax and identifies the type of each variable declaration.
 * It supports basic data types, pointers, arrays, structs, and function pointers.
 * The output consists of the variable name and its type.
 */

typedef enum { NONE, CHAR, INT, FLOAT, DOUBLE } DataType;

typedef struct {
    DataType data_type;
    int num_pointers;
    int array_size;
    char* struct_name;
    int is_func_ptr;
} VarType;

// Parses a variable declaration and returns its type
VarType parse_variable(char* variable) {
    VarType type;
    type.data_type = NONE;
    type.num_pointers = 0;
    type.array_size = 0;
    type.struct_name = NULL;
    type.is_func_ptr = 0;

    char* token = strtok(variable, "*[]()");
    while (token != NULL) {
        if (strcmp(token, "int") == 0) {
            type.data_type = INT;
        } else if (strcmp(token, "float") == 0) {
            type.data_type = FLOAT;
        } else if (strcmp(token, "double") == 0) {
            type.data_type = DOUBLE;
        } else if (strcmp(token, "char") == 0) {
            type.data_type = CHAR;
        } else if (strcmp(token, "struct") == 0) {
            type.struct_name = strtok(NULL, " ");
            // Ignore the rest of the struct definition for now
            break;
        } else if (strcmp(token, "(") == 0) {
            type.is_func_ptr = 1;
            // Skip the rest of the variable declaration
            break;
        }
        token = strtok(NULL, "*[]()");
    }

    // Count the number of pointers
    while (strchr(variable, '*') != NULL) {
        type.num_pointers++;
        variable++;
    }

    // Count the array size
    char* ptr = strchr(variable, '[');
    if (ptr != NULL) {
        char* end = strchr(variable, ']');
        *end = '\0';
        type.array_size = atoi(ptr + 1);
    }

    return type;
}

int main() {
    char input[100];
    printf("Please enter a variable declaration: ");
    fgets(input, 100, stdin);
    strtok(input, "\n");

    VarType type = parse_variable(input);

    printf("Variable Type:\n");
    if (type.data_type == CHAR) {
        printf("char ");
    } else if (type.data_type == INT) {
        printf("int ");
    } else if (type.data_type == FLOAT) {
        printf("float ");
    } else if (type.data_type == DOUBLE) {
        printf("double ");
    }
    for (int i = 0; i < type.num_pointers; i++) {
        printf("*");
    }
    if (type.array_size > 0) {
        printf("[%d]", type.array_size);
    }
    if (type.struct_name != NULL) {
        printf("struct %s", type.struct_name);
    }
    if (type.is_func_ptr) {
        printf("()");
    }
    printf("\n");
    return 0;
}