//FormAI DATASET v1.0 Category: Log analysis ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int i, n = 0, errorCount = 0, warningCount = 0;

    FILE *fp;
    char *line = NULL, *temp;
    char *filePath = "/var/log/system.log";
    size_t len = 0;
    ssize_t read;

    fp = fopen(filePath, "r");
    if (fp == NULL){
        printf("Could not open file %s", filePath);
        return 1;
    }

    while ((read = getline(&line, &len, fp)) != -1){
        n++;

        // Check for errors
        if(strstr(line, "ERROR")){
            errorCount++;
            temp = strtok(line, " ");
            printf("\nError found on line %d. Time: %s\n", n, temp);
            printf("Error details: %s\n", line);
        }

        // Check for warnings
        else if (strstr(line, "WARNING")){
            warningCount++;
            temp = strtok(line, " ");
            printf("\nWarning found on line %d. Time: %s\n", n, temp);
            printf("Warning details: %s\n", line);
        }

    }

    printf("Total errors found: %d\n", errorCount);
    printf("Total warnings found: %d\n", warningCount);

    fclose(fp);
    if (line)
        free(line);

    return 0;
}