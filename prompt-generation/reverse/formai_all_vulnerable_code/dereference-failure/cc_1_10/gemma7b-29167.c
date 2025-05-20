//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[1024];
    fgets(buffer, 1024, fp);

    // Extract header
    char *header = strstr(buffer, ",");
    if (header) {
        header++;
    } else {
        header = buffer;
    }

    // Convert header to array
    char **arr = malloc(10 * sizeof(char *));
    int i = 0;
    for (char *h = header; h && *h; h++) {
        arr[i++] = strdup(h);
    }

    // Read remaining data
    while (fgets(buffer, 1024, fp) != NULL) {
        // Extract data
        char *data = strstr(buffer, ",");
        if (data) {
            data++;
        } else {
            data = buffer;
        }

        // Convert data to array
        char **arr_data = malloc(10 * sizeof(char *));
        int j = 0;
        for (char *d = data; d && *d; d++) {
            arr_data[j++] = strdup(d);
        }

        // Process data
        for (int k = 0; k < 10; k++) {
            printf("%s: %s\n", arr[k], arr_data[k]);
        }

        free(arr_data);
    }

    fclose(fp);
    free(arr);

    return 0;
}