//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_LINE_NUMBER 1000

typedef struct {
    char *line;
    int lineNumber;
} Line;

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    Line lines[MAX_LINE_NUMBER];
    int numLines = 0;
    int i;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(lines[numLines].line, MAX_LINE_LENGTH, file)!= NULL) {
        lines[numLines].lineNumber = numLines + 1;
        numLines++;
    }

    fclose(file);

    printf("Enter the line number to convert to binary: ");
    scanf("%d", &i);

    if (i < 1 || i > numLines) {
        printf("Error: invalid line number\n");
        exit(1);
    }

    char *text = lines[i-1].line;
    int length = strlen(text);
    char binary[MAX_LINE_LENGTH];
    int j;

    for (j = 0; j < length; j++) {
        char c = text[j];
        int decimal = (int)c;
        int binaryDigit = 0;

        while (decimal > 0) {
            binaryDigit = decimal % 2;
            decimal /= 2;
            strcat(binary, binaryDigit == 1? "1" : "0");
        }
    }

    printf("Binary representation of line %d:\n%s\n", i, binary);

    return 0;
}