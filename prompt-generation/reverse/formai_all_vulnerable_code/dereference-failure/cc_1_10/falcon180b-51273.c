//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1000
#define MAX_COLOR 256

typedef struct {
    char name[MAX_LINE];
    int code;
} ColorCode;

void readColorCodes(ColorCode *codes, int numColors) {
    FILE *fp = fopen("colors.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open colors.txt\n");
        exit(1);
    }
    int i = 0;
    while (i < numColors && fscanf(fp, "%s %d\n", codes[i].name, &codes[i].code) == 2) {
        i++;
    }
    if (i!= numColors) {
        printf("Error: not enough color codes in colors.txt\n");
        exit(1);
    }
    fclose(fp);
}

int main() {
    int numColors;
    printf("Enter the number of color codes: ");
    scanf("%d", &numColors);
    ColorCode codes[numColors];
    readColorCodes(codes, numColors);
    char input[MAX_LINE];
    while (fgets(input, MAX_LINE, stdin)!= NULL) {
        int colorCode = -1;
        for (int i = 0; i < numColors; i++) {
            if (strcmp(codes[i].name, input) == 0) {
                colorCode = codes[i].code;
                break;
            }
        }
        if (colorCode == -1) {
            printf("Error: invalid color code '%s'\n", input);
            exit(1);
        }
        printf("%d\n", colorCode);
    }
    return 0;
}