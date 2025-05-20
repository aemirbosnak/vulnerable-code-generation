//FormAI DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1000

struct Record {
    float feature1;
    float feature2;
    float feature3;
    float feature4;
    char label[20];
};

int main()
{
    FILE *file = fopen("data.csv", "r");

    if (file == NULL) {
        printf("Error opening file\n");
    } else {
        char line[MAX_LINE_LENGTH];
        int count = 0;

        while (fgets(line, MAX_LINE_LENGTH, file)) {
            struct Record record;

            char *token = strtok(line, ",");
            sscanf(token, "%f", &record.feature1);

            token = strtok(NULL, ",");
            sscanf(token, "%f", &record.feature2);

            token = strtok(NULL, ",");
            sscanf(token, "%f", &record.feature3);

            token = strtok(NULL, ",");
            sscanf(token, "%f", &record.feature4);

            token = strtok(NULL, ",");
            strcpy(record.label, token);

            printf("Record %d:\n", count);
            printf("Feature 1: %f\n", record.feature1);
            printf("Feature 2: %f\n", record.feature2);
            printf("Feature 3: %f\n", record.feature3);
            printf("Feature 4: %f\n", record.feature4);
            printf("Label: %s\n\n", record.label);

            count++;
        }

        fclose(file);
    }

    return 0;
}