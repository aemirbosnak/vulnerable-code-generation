//FormAI DATASET v1.0 Category: Syntax parsing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char file_path[100];

    printf("Enter file path: ");

    fgets(file_path, 100, stdin);

    // Remove newline character from file path
    file_path[strcspn(file_path, "\n")] = 0;

    FILE* file_ptr = fopen(file_path, "r");

    if(file_ptr == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    char configuration[100][2][50];

    int count = 0;

    char line[100];

    while(fgets(line, 100, file_ptr)) {

        // Remove newline character from line
        line[strcspn(line, "\n")] = 0;

        char* token = strtok(line, "=");

        strcpy(configuration[count][0], token);

        token = strtok(NULL, "=");

        strcpy(configuration[count][1], token);

        count++;

    }

    fclose(file_ptr);

    // Display parsed configuration
    for(int i=0; i<count; i++) {
        printf("%s = %s\n", configuration[i][0], configuration[i][1]);
    }

    return 0;
}