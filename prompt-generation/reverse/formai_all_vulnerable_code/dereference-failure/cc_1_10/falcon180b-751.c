//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char hex[8];
    char rgb[16];
    char name[16];
} Color;

Color* getColor(char* name) {
    Color* color = NULL;
    FILE* file = fopen("colors.txt", "r");

    if (file!= NULL) {
        char line[MAX_LINE_LENGTH];
        while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
            if (strcmp(line, "\n") == 0) {
                continue;
            }

            char* delimiter = strchr(line, ',');
            if (delimiter == NULL) {
                continue;
            }

            *delimiter = '\0';
            strcpy(color->name, line);

            strcpy(color->hex, strtok(line, ","));
            strcpy(color->rgb, strtok(NULL, ","));

            break;
        }

        fclose(file);
    }

    return color;
}

void printColor(Color* color) {
    printf("Name: %s\n", color->name);
    printf("HEX: %s\n", color->hex);
    printf("RGB: %s\n", color->rgb);
    printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <color name> <output format>\n", argv[0]);
        printf("Output formats:\n");
        printf("- hex\n");
        printf("- rgb\n");
        return 1;
    }

    Color* color = getColor(argv[1]);
    if (color == NULL) {
        printf("Color not found!\n");
        return 1;
    }

    if (strcmp(argv[2], "hex") == 0) {
        printf("%s\n", color->hex);
    } else if (strcmp(argv[2], "rgb") == 0) {
        printf("%s\n", color->rgb);
    } else {
        printf("Invalid output format!\n");
        return 1;
    }

    return 0;
}