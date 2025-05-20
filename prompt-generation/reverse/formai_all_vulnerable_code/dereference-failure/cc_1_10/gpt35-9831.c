//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function to implement digital watermarking */
char* digital_watermark(char* originalText, char* watermarkText) {
    char *watermarkedText = malloc(1000);
    char *temp = malloc(1000);

    int i = 0, j = 0;

    while (originalText[i] != '\0') {
        if (originalText[i] >= 'a' && originalText[i] <= 'z') {
            temp[j] = originalText[i] + 1; /* shift the character by 1 */
        } else if (originalText[i] >= 'A' && originalText[i] <= 'Z') {
            temp[j] = originalText[i] - 1;
        } else {
            temp[j] = originalText[i];
        }

        i++;
        j++;
    }

    temp[j] = '#';
    j++;

    i = 0;

    while (watermarkText[i] != '\0') {
        temp[j] = watermarkText[i];
        i++;
        j++;
    }

    temp[j] = '\0';

    i = 0;
    j = 0;

    /* convert each character to its ascii value */
    while (temp[i] != '\0') {
        watermarkedText[j] = (temp[i] / 100 + '0');
        watermarkedText[j + 1] = (temp[i] % 100 / 10 + '0');
        watermarkedText[j + 2] = (temp[i] % 10 + '0');

        i++;
        j += 3;
    }

    watermarkedText[j] = '\0';

    return watermarkedText;
}

int main() {
    char originalText[1000], watermarkText[1000];
    printf("Enter the original text: ");
    scanf("%[^\n]%*c", originalText);
    printf("Enter the watermark text: ");
    scanf("%[^\n]%*c", watermarkText);

    char *watermarkedText = digital_watermark(originalText, watermarkText);

    printf("Original text: %s\n", originalText);
    printf("Watermark text: %s\n", watermarkText);
    printf("Watermarked text: %s\n", watermarkedText);

    free(watermarkedText);

    return 0;
}