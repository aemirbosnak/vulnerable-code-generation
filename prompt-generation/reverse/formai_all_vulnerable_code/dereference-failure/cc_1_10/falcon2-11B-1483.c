//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* colorName;
    int colorCode;
} Color;

Color* readColorsFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    Color* colors = (Color*)malloc(sizeof(Color) * 100);

    int count = 0;
    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strlen(line) == 0) {
            continue;
        }
        char* name = strtok(line, ":");
        int code = atoi(strtok(NULL, ":"));
        colors[count].colorName = strdup(name);
        colors[count].colorCode = code;
        count++;
    }

    fclose(file);

    return colors;
}

void printColors(Color* colors, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", colors[i].colorName, colors[i].colorCode);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <colors.txt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Color* colors = readColorsFromFile(argv[1]);
    printColors(colors, strlen(argv[1]));
    free(colors);

    return 0;
}