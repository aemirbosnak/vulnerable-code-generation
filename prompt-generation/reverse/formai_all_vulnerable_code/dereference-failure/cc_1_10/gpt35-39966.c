//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void parse_json(char *json_string);
void parse_object(char *json_string, int start_index);
void parse_array(char *json_string, int start_index);
void parse_value(char *json_string, int start_index);

int main()
{
    char *json_string = "{\"name\":\"John\", \"age\":30, \"friends\":[\"Mary\",\"Mark\"]}";

    parse_json(json_string);

    return 0;
}

void parse_json(char *json_string)
{
    // Check if the JSON string starts with an object or array
    if (json_string[0] == '{')
    {
        parse_object(json_string, 1);
    }
    else if (json_string[0] == '[')
    {
        parse_array(json_string, 1);
    }
    else
    {
        printf("Error: Invalid JSON string");
        exit(1);
    }
}

void parse_object(char *json_string, int start_index)
{
    char *key, *value;
    int i, j, key_start_index, key_end_index, value_start_index, value_end_index;

    printf("{\n");

    i = start_index;

    while (json_string[i] != '}')
    {
        // Parse key
        key_start_index = i + 1;

        while (json_string[i] != ':')
        {
            i++;
        }

        key_end_index = i++;

        key = (char *)malloc(key_end_index - key_start_index + 1);
        strncpy(key, json_string + key_start_index, key_end_index - key_start_index);
        key[key_end_index - key_start_index] = '\0';

        // Parse value
        parse_value(json_string, i);

        // Print key-value pair
        printf("    \"%s\": %s", key, value);

        // Free key memory
        free(key);

        // Check for comma or end of object
        if (json_string[i] == ',')
        {
            printf(",\n");
            i++;
        }
        else if (json_string[i] == '}')
        {
            printf("\n");
        }
        else
        {
            printf("Error: Invalid JSON string");
            exit(1);
        }
    }

    printf("}\n");
}

void parse_array(char *json_string, int start_index)
{
    int i;

    printf("[\n");

    i = start_index;

    while (json_string[i] != ']')
    {
        // Parse value
        parse_value(json_string, i);

        // Check for comma or end of array
        if (json_string[i] == ',')
        {
            printf(",\n");
            i++;
        }
        else if (json_string[i] == ']')
        {
            printf("\n");
        }
        else
        {
            printf("Error: Invalid JSON string");
            exit(1);
        }
    }

    printf("]\n");
}

void parse_value(char *json_string, int start_index)
{
    char *value;
    int i, j, value_start_index, value_end_index;

    if (json_string[start_index] == '\"')
    {
        // Parse string
        i = start_index + 1;

        while (json_string[i] != '\"')
        {
            i++;
        }

        value_start_index = start_index + 1;
        value_end_index = i;

        value = (char *)malloc(value_end_index - value_start_index + 1);
        strncpy(value, json_string + value_start_index, value_end_index - value_start_index);
        value[value_end_index - value_start_index] = '\0';

        printf("    \"%s\"", value);

        free(value);
    }
    else if (json_string[start_index] == '{')
    {
        // Parse object
        parse_object(json_string, start_index + 1);
    }
    else if (json_string[start_index] == '[')
    {
        // Parse array
        parse_array(json_string, start_index + 1);
    }
    else
    {
        // Parse number or boolean
        i = start_index;

        while (json_string[i] != ',' && json_string[i] != '}' && json_string[i] != ']')
        {
            i++;
        }

        value_start_index = start_index;
        value_end_index = i;

        value = (char *)malloc(value_end_index - value_start_index + 1);
        strncpy(value, json_string + value_start_index, value_end_index - value_start_index);
        value[value_end_index - value_start_index] = '\0';

        printf("    %s", value);

        free(value);
    }
}