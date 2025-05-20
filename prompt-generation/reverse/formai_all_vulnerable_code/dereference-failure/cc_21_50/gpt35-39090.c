//FormAI DATASET v1.0 Category: Syntax parsing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a function name
#define MAX_FUNC_NAME_LENGTH 20

// Define the maximum length of a variable name
#define MAX_VAR_NAME_LENGTH 10

// Define a struct for variables
typedef struct {
    char name[MAX_VAR_NAME_LENGTH];
    int value;
} Variable;

// Define a struct for functions
typedef struct {
    char name[MAX_FUNC_NAME_LENGTH];
    char params[MAX_VAR_NAME_LENGTH];
    char body[100];
} Function;

// Define a function to read a line of input
char *read_line() {
    char *line = malloc(sizeof(char) * 100);
    fgets(line, 100, stdin);

    // Remove the newline character
    line[strcspn(line, "\n")] = 0;

    return line;
}

int main() {
    // Define an array of variables
    Variable vars[10];

    // Define an array of functions
    Function funcs[5];

    int num_vars = 0;
    int num_funcs = 0;

    // Loop to accept user input and parse the code
    while (1) {
        printf("Enter code: ");
        char *input_line = read_line();

        // If the line is empty, break the loop and end the program
        if (strcmp(input_line, "") == 0) {
            break;
        }

        // Split the line into tokens
        char *token = strtok(input_line, " ");

        // If the first token is a variable name, create a new variable
        if (strlen(token) <= MAX_VAR_NAME_LENGTH && token[0] >= 'a' && token[0] <= 'z') {
            // Check if the variable already exists
            int var_exists = 0;
            int i;
            for (i = 0; i < num_vars; i++) {
                if (strcmp(vars[i].name, token) == 0) {
                    var_exists = 1;
                    break;
                }
            }

            // If the variable does not exist, create a new one
            if (!var_exists) {
                Variable var;
                strcpy(var.name, token);

                token = strtok(NULL, " ");
                if (strcmp(token, "=") != 0) {
                    printf("Syntax error: expected '='\n");
                    continue;
                }

                token = strtok(NULL, " ");
                if (atoi(token) == 0 && token[0] != '0') {
                    printf("Syntax error: expected integer value\n");
                    continue;
                }

                var.value = atoi(token);
                vars[num_vars++] = var;
                printf("Created variable %s with value %d\n", var.name, var.value);
            } else {
                token = strtok(NULL, " ");
                if (strcmp(token, "=") != 0) {
                    printf("Syntax error: expected '='\n");
                    continue;
                }

                token = strtok(NULL, " ");
                if (atoi(token) == 0 && token[0] != '0') {
                    printf("Syntax error: expected integer value\n");
                    continue;
                }

                vars[i].value = atoi(token);
                printf("Updated variable %s to value %d\n", vars[i].name, vars[i].value);
            }
        }

        // If the first token is the keyword "def", create a new function
        else if (strcmp(token, "def") == 0) {
            // Check if the function already exists
            int func_exists = 0;
            int i;
            for (i = 0; i < num_funcs; i++) {
                if (strcmp(funcs[i].name, token) == 0) {
                    func_exists = 1;
                    break;
                }
            }

            // If the function does not exist, create a new one
            if (!func_exists) {
                Function func;
                strcpy(func.name, token);

                token = strtok(NULL, "(");
                strcpy(func.params, token);

                strcpy(func.body, "");

                // Read the function body
                while (1) {
                    input_line = read_line();

                    if (strcmp(input_line, "end") == 0) {
                        break;
                    }

                    strcat(func.body, input_line);
                    strcat(func.body, "\n");
                }

                funcs[num_funcs++] = func;
                printf("Created function %s with parameters %s and body:\n%s", func.name, func.params, func.body);
            } else {
                printf("Function %s already exists.\n", funcs[i].name);
            }
        }

        // If the first token is the name of a function, call the function
        else {
            int i;
            for (i = 0; i < num_funcs; i++) {
                if (strcmp(funcs[i].name, token) == 0) {
                    // Parse the function parameters
                    char *param = strtok(NULL, ",");
                    Variable args[sizeof(funcs[i].params) / sizeof(char)];
                    int j = 0;

                    while (param != NULL) {
                        // Check if the parameter is a variable
                        int var_exists = 0;
                        int k;
                        for (k = 0; k < num_vars; k++) {
                            if (strcmp(vars[k].name, param) == 0) {
                                var_exists = 1;
                                break;
                            }
                        }

                        if (!var_exists) {
                            printf("Syntax error: variable %s not defined\n", param);
                            continue;
                        }

                        args[j++] = vars[k];
                        param = strtok(NULL, ",");
                    }

                    // Execute the function body
                    input_line = funcs[i].body;
                    while (*input_line != '\0') {
                        char *line_start = input_line;
                        char *line_end = strstr(input_line, "\n");
                        if (line_end == NULL) {
                            line_end = strchr(input_line, '\0');
                        } else {
                            line_end++; // include newline character
                        }

                        char *line = malloc(sizeof(char) * (line_end - line_start + 1));
                        strncpy(line, line_start, line_end - line_start);
                        line[line_end - line_start] = '\0';

                        // Handle variable assignments
                        if (strlen(line) > 0 && line[0] >= 'a' && line[0] <= 'z') {
                            char *var_name = strtok(line, "=");

                            // Check if the variable exists
                            int var_exists = 0;
                            int j;
                            for (j = 0; j < num_vars; j++) {
                                if (strcmp(vars[j].name, var_name) == 0) {
                                    var_exists = 1;
                                    break;
                                }
                            }

                            if (!var_exists) {
                                printf("Syntax error: variable %s not defined\n", var_name);
                                continue;
                            }

                            char *value = strtok(NULL, "");
                            if (atoi(value) == 0 && value[0] != '0') {
                                printf("Syntax error: expected integer value\n");
                                continue;
                            }

                            vars[j].value = atoi(value);
                            printf("Updated variable %s to value %d\n", vars[j].name, vars[j].value);

                        }

                        // Handle print statements
                        else if (strncmp(line, "print", 5) == 0) {
                            char *value = strtok(line + 6, "");
                            if (value[0] == '\"' && value[strlen(value) - 1] == '\"') {
                                // Printing a string
                                value[strlen(value) - 1] = '\0';
                                printf("%s\n", value + 1);
                            } else {
                                // Printing a variable
                                int var_exists = 0;
                                int j;
                                for (j = 0; j < j; j++) {
                                    if (strcmp(vars[j].name, value) == 0) {
                                        var_exists = 1;
                                        break;
                                    }
                                }

                                if (!var_exists) {
                                    printf("Syntax error: variable %s not defined\n", value);
                                    continue;
                                }

                                printf("%d\n", vars[j].value);
                            }
                        }

                        free(line);
                        input_line = line_end;
                    }

                    break;
                }
            }

            if (i == num_funcs) {
                printf("Syntax error: function %s not defined\n", token);
            }
        }
    }

    return 0;
}