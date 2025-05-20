//FormAI DATASET v1.0 Category: Log analysis ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // check if filename is provided as argument
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    FILE* fp = fopen(filename, "r");

    // check if file is opened successfully
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    // initialize variables
    int total_requests = 0;
    int status_200 = 0;
    int status_404 = 0;
    int status_500 = 0;

    // read log file line by line
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        char* token = strtok(line, " ");
        int count = 0;
        char* status = NULL;

        // parse each line to extract status code
        while (token != NULL) {
            count++;

            if (count == 3) {
                status = token;
            }

            token = strtok(NULL, " ");
        }

        // increase count of total requests
        total_requests++;

        // increase count of specific status codes
        if (strcmp(status, "200") == 0) {
            status_200++;
        } else if (strcmp(status, "404") == 0) {
            status_404++;
        } else if (strcmp(status, "500") == 0) {
            status_500++;
        }
    }

    // print results
    printf("Total Requests: %d\n", total_requests);
    printf("Status 200: %d\n", status_200);
    printf("Status 404: %d\n", status_404);
    printf("Status 500: %d\n", status_500);

    // cleanup
    free(line);
    fclose(fp);

    return 0;
}