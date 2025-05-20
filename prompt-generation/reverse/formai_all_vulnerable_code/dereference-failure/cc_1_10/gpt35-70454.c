//FormAI DATASET v1.0 Category: Data mining ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Map function that reads input data and emits key-value pairs
int mapper(char *line, char *key, char *value) {
    // Extract relevant data fields from the input line
    char *field1 = strtok(line, ",");
    char *field2 = strtok(NULL, ",");

    // Emit key-value pair with field1 as the key and field2 as the value
    strcpy(key, field1);
    strcpy(value, field2);

    return 0;
}

// Reduce function that aggregates key-value pairs
int reducer(char *key, char **values, int num_values, char *output) {
    // Calculate the sum of all values for the given key
    int sum = 0;
    for (int i = 0; i < num_values; i++) {
        sum += atoi(values[i]);
    }

    // Output the key and its corresponding sum
    sprintf(output, "%s,%d", key, sum);

    return 0;
}

int main(int argc, char **argv) {
    // Input data
    char *data[] = {
        "apple,2",
        "banana,3",
        "orange,1",
        "apple,4",
        "banana,2",
        "orange,3"
    };

    // Number of input data lines
    int num_lines = sizeof(data) / sizeof(data[0]);

    // Initialize key-value pairs array
    char keys[num_lines][256];
    char values[num_lines][256];

    // Map input data to key-value pairs
    for (int i = 0; i < num_lines; i++) {
        mapper(data[i], keys[i], values[i]);
    }

    // Create an array of key-value pairs for each mapper output
    char *mapper_outputs[][2] = {
        {keys[0], values[0]},
        {keys[1], values[1]},
        {keys[2], values[2]},
        {keys[3], values[3]},
        {keys[4], values[4]},
        {keys[5], values[5]}
    };

    // Separate the mapper outputs according to their keys
    int num_groups = 0;
    char *groups[256][256];
    for (int i = 0; i < num_lines; i++) {
        // Check if the current key already exists in the groups array
        int j;
        for (j = 0; j < num_groups; j++) {
            if (strcmp(keys[i], groups[j][0]) == 0) {
                break;
            }
        }

        // If the key doesn't exist, create a new group with this key
        if (j == num_groups) {
            groups[j][0] = keys[i];
            num_groups++;
        }

        // Add this value to the group with the matching key
        groups[j][i % 2 + 1] = values[i];
    }

    // Initialize output array
    char output[256];

    // Reduce each group of key-value pairs
    for (int i = 0; i < num_groups; i++) {
        // Extract the key and values for this group
        char *key = groups[i][0];
        char *values[] = {groups[i][1], groups[i][2]};

        // Call the reduce function to compute the sum of values for this key
        reducer(key, values, 2, output);

        // Output the result
        printf("%s\n", output);
    }

    return 0;
}