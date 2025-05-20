//FormAI DATASET v1.0 Category: System boot optimizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 1024

void optimizeBoot()
{
    // Initialize variables for parsing
    FILE *bootFile;
    char bootPath[MAX_PATH];
    char *line;
    size_t len = 0;
    ssize_t read;

    // Prompt user for boot file path
    printf("Enter path to boot file: ");
    scanf("%s", bootPath);

    // Attempt to open boot file
    bootFile = fopen(bootPath, "r+");
    if (bootFile == NULL) {
        printf("Error opening boot file.\n");
        exit(EXIT_FAILURE);
    }

    // Read boot file line-by-line
    while ((read = getline(&line, &len, bootFile)) != -1) {
        // Check if line contains kernel boot parameters
        if (strstr(line, "kernel") != NULL) {
            // Parse kernel parameters
            char *params = strchr(line, ' ');
            if (params == NULL) {
                continue;
            }
            params++; // Move past white space

            // Split parameters into array for easy manipulation
            char *paramArray[256];
            int paramCount = 0;
            char *token = strtok(params, " ");
            while (token != NULL) {
                paramArray[paramCount] = token;
                paramCount++;
                token = strtok(NULL, " ");
            }

            // Loop through parameter array
            for (int i = 0; i < paramCount; i++) {
                // Remove any unnecessary boot parameters
                if (strcmp(paramArray[i], "quiet") == 0
                    || strcmp(paramArray[i], "splash") == 0
                    || strcmp(paramArray[i], "rhgb") == 0) {
                    // Shift all remaining parameters to the left
                    for (int j = i; j < paramCount; j++) {
                        paramArray[j] = paramArray[j+1];
                    }
                    i--; // Decrement to account for shifted array
                    paramCount--;
                }
            }

            // Reconstruct boot parameter string and write back to file
            fseek(bootFile, -(long int)strlen(params), SEEK_CUR); // Move cursor back to start of parameters
            for (int i = 0; i < paramCount; i++) {
                fprintf(bootFile, "%s ", paramArray[i]);
            }
            fprintf(bootFile, "\n"); // Add line break
        }
    }

    // Free memory and close file
    if (line) {
        free(line);
    }
    fclose(bootFile);

    // Output success message
    printf("Boot file optimized successfully!\n");
}

int main()
{
    optimizeBoot();
    return 0;
}