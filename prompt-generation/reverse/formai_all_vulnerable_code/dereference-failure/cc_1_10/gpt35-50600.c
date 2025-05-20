//FormAI DATASET v1.0 Category: Syntax parsing ; Style: portable
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to store information about a parsed C function */
typedef struct ParsedCFunction {
    char* name;
    char* return_type;
    char** arguments;
    int num_arguments;
} ParsedCFunction;

/* Define a function to parse a C function declaration */
ParsedCFunction parse_c_function_declaration(char* declaration) {
    ParsedCFunction parsed_function;
    parsed_function.arguments = NULL;
    parsed_function.num_arguments = 0;

    /* Find the name of the function */
    char* name_start = declaration;
    while (*name_start == ' ' || *name_start == '\t' || *name_start == '\n') { // Skip whitespace
        name_start++;
    }
    char* name_end = name_start;
    while (*name_end != '(') {
        name_end++;
    }
    parsed_function.name = malloc(name_end - name_start + 1);
    memcpy(parsed_function.name, name_start, name_end - name_start);
    parsed_function.name[name_end - name_start] = '\0';

    /* Find the return type of the function */
    char* return_type_end = name_start - 1;
    while (*return_type_end == ' ' || *return_type_end == '\t' || *return_type_end == '\n') { // Skip whitespace
        return_type_end--;
    }
    char* return_type_start = return_type_end;
    while (*return_type_start != ' ') {
        return_type_start--;
    }
    return_type_start++;
    parsed_function.return_type = malloc(return_type_end - return_type_start + 1);
    memcpy(parsed_function.return_type, return_type_start, return_type_end - return_type_start);
    parsed_function.return_type[return_type_end - return_type_start] = '\0';

    /* Find the arguments of the function */
    char* argument_start = name_end + 1;
    char* argument_end = argument_start;
    while (*argument_end != ')') {
        if (*argument_end == ',') {
            parsed_function.num_arguments++;
            parsed_function.arguments = realloc(parsed_function.arguments, parsed_function.num_arguments * sizeof(char*));
            parsed_function.arguments[parsed_function.num_arguments - 1] = malloc(argument_end - argument_start + 1);
            memcpy(parsed_function.arguments[parsed_function.num_arguments - 1], argument_start, argument_end - argument_start);
            parsed_function.arguments[parsed_function.num_arguments - 1][argument_end - argument_start] = '\0';
            argument_start = argument_end + 1;
        }
        argument_end++;
    }
    parsed_function.num_arguments++;
    parsed_function.arguments = realloc(parsed_function.arguments, parsed_function.num_arguments * sizeof(char*));
    parsed_function.arguments[parsed_function.num_arguments - 1] = malloc(argument_end - argument_start + 1);
    memcpy(parsed_function.arguments[parsed_function.num_arguments - 1], argument_start, argument_end - argument_start);
    parsed_function.arguments[parsed_function.num_arguments - 1][argument_end - argument_start] = '\0';

    return parsed_function;
}

int main() {
    char* declaration = "int add(int a, int b)";
    ParsedCFunction parsed_function = parse_c_function_declaration(declaration);

    printf("Function name: %s\n", parsed_function.name);
    printf("Return type: %s\n", parsed_function.return_type);
    printf("Arguments:\n");
    for (int i = 0; i < parsed_function.num_arguments; i++) {
        printf("  %s\n", parsed_function.arguments[i]);
    }

    /* Free memory */
    free(parsed_function.name);
    free(parsed_function.return_type);
    for (int i = 0; i < parsed_function.num_arguments; i++) {
        free(parsed_function.arguments[i]);
    }
    free(parsed_function.arguments);

    return 0;
}