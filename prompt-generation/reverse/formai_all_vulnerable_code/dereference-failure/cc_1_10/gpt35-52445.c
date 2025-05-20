//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_OBJECTS 100
#define MAX_JSON_OBJECT_MEMBERS 100
#define MAX_JSON_INPUT_SIZE 10000

typedef struct json_member {
    char *name;
    char *value;
} json_member;

typedef struct json_object {
    char *name;
    int num_members;
    json_member members[MAX_JSON_OBJECT_MEMBERS];
} json_object;

// Parses a JSON object from the input string starting at index i and returns the index immediately after the object
int parse_object(char *input, int i, json_object *output) {
    int j = i;

    // Find the start of the object
    while (input[j] != '{') j++;

    // Find the end of the name
    int k = j - 1;
    while (input[k] == ' ' || input[k] == '\n') k--;
    output->name = malloc((k - j + 2) * sizeof(char));
    strncpy(output->name, &input[i], k - i + 1);
    output->name[k - i + 1] = '\0';

    // Find the members of the object
    j++;
    while (input[j] != '}') {
        // Find the name of the member
        int l = j;
        while (input[l] == ' ' || input[l] == '\n') l++;
        int m = l;
        while (input[m] != ':') m--;
        json_member *member = &(output->members[output->num_members]);
        member->name = malloc((m - l + 2) * sizeof(char));
        strncpy(member->name, &input[l], m - l + 1);
        member->name[m - l + 1] = '\0';

        // Find the value of the member
        m++;
        l = m;
        int nesting_level = 0;
        while (input[l] != ',' && input[l] != '}') {
            if (input[l] == '{' || input[l] == '[') nesting_level++;
            else if (input[l] == '}' || input[l] == ']') nesting_level--;
            l++;
        }
        member->value = malloc((l - m + 2) * sizeof(char));
        strncpy(member->value, &input[m], l - m + 1);
        member->value[l - m + 1] = '\0';

        output->num_members++;
        if (input[l] == ',') l++;
        j = l;
    }

    return j + 1;
}

// Parses an array from the input string starting at index i and returns the index immediately after the array
int parse_array(char *input, int i) {
    int j = i;

    // Find the start of the array
    while (input[j] != '[') j++;

    // Find the end of the array
    int nesting_level = 0;
    while (input[j] != ']' || nesting_level > 0) {
        if (input[j] == '{' || input[j] == '[') nesting_level++;
        else if (input[j] == '}' || input[j] == ']') nesting_level--;
        j++;
    }

    return j + 1;
}

// Parses a JSON string from the input string starting at index i and returns the index immediately after the string
int parse_string(char *input, int i) {
    int j = i;

    // Find the start of the string
    while (input[j] != '\"') j++;

    // Find the end of the string
    j++;
    while (input[j] != '\"') j++;

    return j + 1;
}

// Parses a JSON number from the input string starting at index i and returns the index immediately after the number
int parse_number(char *input, int i) {
    int j = i;

    // Find the start of the number
    while (input[j] < '0' || input[j] > '9') j++;

    // Find the end of the number
    while (input[j] >= '0' && input[j] <= '9') j++;

    return j;
}

// Parses a JSON value from the input string starting at index i and returns the index immediately after the value
int parse_value(char *input, int i) {
    if (input[i] == '{') {
        json_object object;
        i = parse_object(input, i, &object);
        printf("Object name: %s\n", object.name);
        for (int j = 0; j < object.num_members; j++) {
            printf("Member name: %s, value: %s\n", object.members[j].name, object.members[j].value);
        }
    } else if (input[i] == '[') {
        i = parse_array(input, i);
    } else if (input[i] == '\"') {
        i = parse_string(input, i);
    } else {
        i = parse_number(input, i);
    }

    return i;
}

int main() {
    char input[MAX_JSON_INPUT_SIZE] = "{\n"
                                       "    \"name\": \"John\",\n"
                                       "    \"age\": 30,\n"
                                       "    \"city\": \"New York\",\n"
                                       "    \"pets\": [\n"
                                       "        {\n"
                                       "            \"name\": \"Fido\",\n"
                                       "            \"species\": \"dog\",\n"
                                       "            \"age\": 3\n"
                                       "        },\n"
                                       "        {\n"
                                       "            \"name\": \"Mittens\",\n"
                                       "            \"species\": \"cat\",\n"
                                       "            \"age\": 2\n"
                                       "        }\n"
                                       "    ]\n"
                                       "}";
    parse_value(input, 0);

    return 0;
}