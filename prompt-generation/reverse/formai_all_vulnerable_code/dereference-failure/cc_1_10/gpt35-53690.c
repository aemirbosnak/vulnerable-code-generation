//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STR_LEN 100

typedef struct {
    char func_name[MAX_STR_LEN];
    int arg_count;
    char** args;
} Function_Call;

void parse_func_call(const char* input, Function_Call* fc);

int main()
{
    char input[MAX_STR_LEN * 10];

    printf("Enter a function call:\n");
    scanf("%[^\n]", input);

    Function_Call fc;
    parse_func_call(input, &fc);

    printf("Function Name: %s\n", fc.func_name);
    printf("Argument Count: %d\n", fc.arg_count);

    for (int i = 0; i < fc.arg_count; ++i) {
        printf("Argument %d: %s\n", i + 1, fc.args[i]);
        free(fc.args[i]);
    }
    free(fc.args);

    return 0;
}

void parse_func_call(const char* input, Function_Call* fc)
{
    fc->args = NULL;
    fc->arg_count = 0;

    int i = 0;
    while (isalpha(input[i]) || input[i] == '_') {
        fc->func_name[i] = input[i];
        ++i;
    }
    fc->func_name[i] = '\0';

    while (!isalnum(input[i]) && input[i] != '_' && input[i] != '(' && input[i] != '\0') {
        ++i;
    }

    if (input[i] != '(') {
        fprintf(stderr, "Invalid function call: missing opening parenthesis after function name\n");
        exit(1);
    }

    ++i;

    while (input[i] != ')' && input[i] != '\0') {
        char* arg = calloc(MAX_STR_LEN, sizeof(char));

        int j = 0;
        while (input[i] != ',' && input[i] != ')' && input[i] != '\0') {
            arg[j] = input[i];
            ++j;
            ++i;
        }
        arg[j] = '\0';

        if (fc->args == NULL) {
            fc->args = calloc(1, sizeof(char*));
        } else {
            fc->args = realloc(fc->args, (fc->arg_count + 1) * sizeof(char*));
        }

        fc->args[fc->arg_count] = arg;
        ++fc->arg_count;

        if (input[i] == ',') {
            ++i;
        }
    }

    if (input[i] != ')') {
        fprintf(stderr, "Invalid function call: missing closing parenthesis after arguments\n");
        exit(1);
    }
}