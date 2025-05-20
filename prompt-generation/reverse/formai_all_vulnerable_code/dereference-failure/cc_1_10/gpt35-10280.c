//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum size of the input string

typedef struct {
    int is_string;
    char *key;
    int value_type; // 0 for null, 1 for boolean, 2 for number, 3 for string
    void *value;
} json_element;

json_element parse_element(char *input, int *pos);

json_element parse_object(char *input, int *pos) {
    json_element object = {
        .is_string = 0,
        .key = NULL,
        .value_type = 0,
        .value = NULL
    };
    
    if (input[*pos] != '{') {
        printf("Error: expected '{' at position %d\n", *pos + 1);
        exit(1);
    }
    (*pos)++;
    
    json_element *elements = malloc(sizeof(json_element) * MAX_SIZE);
    int num_elements = 0;
    
    while (input[*pos] != '}') {
        if (num_elements > 0) {
            if (input[*pos] != ',') {
                printf("Error: expected ',' at position %d\n", *pos + 1);
                exit(1);
            }
            (*pos)++;
        }
        
        if (input[*pos] == '"') {
            elements[num_elements] = parse_element(input, pos);
            num_elements++;
        } else {
            printf("Error: expected '\"' at position %d\n", *pos + 1);
            exit(1);
        }
    }
    (*pos)++;
    
    object.value_type = 4;
    object.value = elements;
    return object;
}

json_element parse_array(char *input, int *pos) {
    json_element array = {
        .is_string = 0,
        .key = NULL,
        .value_type = 0,
        .value = NULL
    };
    
    if (input[*pos] != '[') {
        printf("Error: expected '[' at position %d\n", *pos + 1);
        exit(1);
    }
    (*pos)++;
    
    json_element *elements = malloc(sizeof(json_element) * MAX_SIZE);
    int num_elements = 0;
    
    while (input[*pos] != ']') {
        if (num_elements > 0) {
            if (input[*pos] != ',') {
                printf("Error: expected ',' at position %d\n", *pos + 1);
                exit(1);
            }
            (*pos)++;
        }
        
        elements[num_elements] = parse_element(input, pos);
        num_elements++;
    }
    (*pos)++;
    
    array.value_type = 5;
    array.value = elements;
    return array;
}

json_element parse_string(char *input, int *pos) {
    json_element string = {
        .is_string = 1,
        .key = NULL,
        .value_type = 3,
        .value = NULL
    };
    
    char *buffer = malloc(sizeof(char) * MAX_SIZE);
    int buffer_pos = 0;
    
    if (input[*pos] != '"') {
        printf("Error: expected '\"' at position %d\n", *pos + 1);
        exit(1);
    }
    (*pos)++;
    
    while (input[*pos] != '"' && buffer_pos < MAX_SIZE) {
        buffer[buffer_pos] = input[*pos];
        buffer_pos++;
        (*pos)++;
    }
    buffer[buffer_pos] = '\0';
    (*pos)++;
    
    string.value = buffer;
    return string;
}

json_element parse_number(char *input, int *pos) {
    json_element number = {
        .is_string = 0,
        .key = NULL,
        .value_type = 2,
        .value = NULL
    };
    
    char *buffer = malloc(sizeof(char) * MAX_SIZE);
    int buffer_pos = 0;
    
    while ((input[*pos] >= '0' && input[*pos] <= '9') || input[*pos] == '.') {
        buffer[buffer_pos] = input[*pos];
        buffer_pos++;
        (*pos)++;
    }
    buffer[buffer_pos] = '\0';
    
    if (strstr(buffer, ".") != NULL) {
        number.value = (double *) malloc(sizeof(double));
        *((double *) number.value) = atof(buffer);
    } else {
        number.value = (int *) malloc(sizeof(int));
        *((int *) number.value) = atoi(buffer);
    }
    
    number.value_type = 2;
    return number;
}

json_element parse_boolean(char *input, int *pos) {
    json_element boolean = {
        .is_string = 0,
        .key = NULL,
        .value_type = 1,
        .value = NULL
    };
    
    if (strncmp(&input[*pos], "true", 4) == 0) {
        boolean.value = (int *) malloc(sizeof(int));
        *((int *) boolean.value) = 1;
        *pos += 4;
    } else if (strncmp(&input[*pos], "false", 5) == 0) {
        boolean.value = (int *) malloc(sizeof(int));
        *((int *) boolean.value) = 0;
        *pos += 5;
    } else {
        printf("Error: expected 'true' or 'false' at position %d\n", *pos + 1);
        exit(1);
    }
    
    boolean.value_type = 1;
    return boolean;
}

json_element parse_null(char *input, int *pos) {
    json_element null = {
        .is_string = 0,
        .key = NULL,
        .value_type = 0,
        .value = NULL
    };
    
    if (strncmp(&input[*pos], "null", 4) == 0) {
        *pos += 4;
    } else {
        printf("Error: expected 'null' at position %d\n", *pos + 1);
        exit(1);
    }
    
    return null;
}

json_element parse_element(char *input, int *pos) {
    json_element element = {
        .is_string = 0,
        .key = NULL,
        .value_type = 0,
        .value = NULL
    };
    
    if (input[*pos] == '{') {
        element = parse_object(input, pos);
    } else if (input[*pos] == '[') {
        element = parse_array(input, pos);
    } else if (input[*pos] == '"') {
        element = parse_string(input, pos);
    } else if (input[*pos] == '-' || (input[*pos] >= '0' && input[*pos] <= '9')) {
        element = parse_number(input, pos);
    } else if (strncmp(&input[*pos], "true", 4) == 0 || strncmp(&input[*pos], "false", 5) == 0) {
        element = parse_boolean(input, pos);
    } else if (strncmp(&input[*pos], "null", 4) == 0) {
        element = parse_null(input, pos);
    } else {
        printf("Error: unrecognized character at position %d\n", *pos + 1);
        exit(1);
    }
    
    return element;
}

json_element parse(char *input) {
    int pos = 0;
    return parse_element(input, &pos);
}

void print_element(json_element element, int indent) {
    if (element.is_string) {
        printf("\"%s\"", (char *) element.value);
    } else {
        switch (element.value_type) {
            case 0:
                printf("null");
                break;
            case 1:
                printf(*((int *) element.value) ? "true" : "false");
                break;
            case 2:
                if (strstr((char *) element.value, ".") != NULL) {
                    printf("%f", *((double *) element.value));
                } else {
                    printf("%d", *((int *) element.value));
                }
                break;
            case 4:
                printf("{\n");
                for (int i = 0; i < MAX_SIZE && ((json_element *) element.value)[i].key != NULL; i++) {
                    printf("%*s\"%s\": ", indent + 4, "", ((json_element *) element.value)[i].key);
                    print_element(((json_element *) element.value)[i], indent + 4);
                    printf(i < MAX_SIZE - 1 && ((json_element *) element.value)[i + 1].key != NULL ? ",\n" : "\n");
                }
                printf("%*s}", indent, "");
                break;
            case 5:
                printf("[\n");
                for (int i = 0; i < MAX_SIZE && ((json_element *) element.value)[i].key != NULL; i++) {
                    printf("%*s", indent + 4, "");
                    print_element(((json_element *) element.value)[i], indent + 4);
                    printf(i < MAX_SIZE - 1 && ((json_element *) element.value)[i + 1].key != NULL ? ",\n" : "\n");
                }
                printf("%*s]", indent, "");
                break;
            default:
                printf("ERROR: unrecognized value type %d", element.value_type);
                break;
        }
    }
}

int main() {
    char input[MAX_SIZE] = "{\n"
                           "    \"name\": \"John Doe\",\n"
                           "    \"age\": 42,\n"
                           "    \"is_student\": true,\n"
                           "    \"courses\": [\n"
                           "        {\n"
                           "            \"name\": \"Math\",\n"
                           "            \"credits\": 3.5\n"
                           "        },\n"
                           "        {\n"
                           "            \"name\": \"English\",\n"
                           "            \"credits\": 4\n"
                           "        }\n"
                           "    ],\n"
                           "    \"address\": {\n"
                           "        \"street\": \"123 Main St\",\n"
                           "        \"city\": \"Anytown\",\n"
                           "        \"state\": \"CA\",\n"
                           "        \"zip\": \"12345\"\n"
                           "    }\n"
                           "}";
    
    json_element json = parse(input);
    print_element(json, 0);
    printf("\n");
    
    return 0;
}