//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <string.h>

void convertColor(char* input, char* output) {
    int red = 0, green = 0, blue = 0;
    char* hexString = strtok(input, "#");
    int n = strlen(hexString);
    for (int i = 0; i < n; i += 2) {
        int charVal = (int)hexString[i] - '0';
        if (charVal > 9) {
            charVal -= 7;
        }
        charVal *= 16;
        charVal += (int)hexString[i + 1] - '0';
        if (charVal > 255) {
            charVal -= 255;
        }
        if (charVal < 0) {
            charVal += 65535;
        }
        red = red | charVal;
    }
    char* hex = "00";
    for (int i = 0; i < 6; i++) {
        int charVal = (int)hexString[i] - '0';
        if (charVal > 9) {
            charVal -= 7;
        }
        charVal *= 16;
        charVal += (int)hexString[i + 1] - '0';
        if (charVal > 255) {
            charVal -= 255;
        }
        if (charVal < 0) {
            charVal += 65535;
        }
        hex = strcat(hex, (charVal > 9)? "0" : "") + charVal;
    }
    if (output!= NULL) {
        strcpy(output, "0x");
        strcat(output, hex);
    }
    printf("Red: %d\n", red);
}

int main() {
    char input[100];
    printf("Enter the color code: ");
    fgets(input, 100, stdin);
    char* output = NULL;
    convertColor(input, output);
    if (output!= NULL) {
        printf("Hex: %s\n", output);
    }
    return 0;
}