//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 1000
#define MAX_COLOR_CODE_LENGTH 7

struct color_name {
    char name[20];
    char code[MAX_COLOR_CODE_LENGTH];
};

int main() {
    FILE *fp;
    char line[100];
    char *token;
    int i = 0;
    struct color_name colors[MAX_COLOR_NAMES];

    // Open the color names file
    fp = fopen("color_names.txt", "r");

    if (fp == NULL) {
        printf("Error: Could not open color_names.txt\n");
        exit(1);
    }

    // Read in the color names and codes
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        strcpy(colors[i].name, token);

        token = strtok(NULL, ",");
        strcpy(colors[i].code, token);

        i++;
        if (i >= MAX_COLOR_NAMES) {
            printf("Error: Too many color names in file\n");
            exit(1);
        }
    }

    fclose(fp);

    // Convert a color name to its code
    char color_name[20];
    printf("Enter a color name: ");
    scanf("%s", color_name);

    int found = 0;
    for (i = 0; i < MAX_COLOR_NAMES; i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            printf("Color code: %s\n", colors[i].code);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Color not found\n");
    }

    return 0;
}