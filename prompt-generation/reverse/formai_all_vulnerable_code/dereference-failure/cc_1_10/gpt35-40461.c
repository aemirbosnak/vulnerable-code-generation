//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: genious
#include <stdio.h>
#include <string.h>

// Function to embed the watermark in the given text using a keyword and key value
void embedWatermark(char text[], char keyword[], int key) {
    int textLen = strlen(text);
    int keywordLen = strlen(keyword);
    int watermarkLen = keywordLen + 1;
    char watermark[watermarkLen];

    // Construct the watermark by concatenating the keyword and the key value
    // The key value is converted to a string and appended to the keyword
    snprintf(watermark, watermarkLen, "%s%d", keyword, key);

    // Embed the watermark in the first few characters of the text
    // The number of characters used to embed the watermark depends on the length of the watermark
    for (int i = 0; i < watermarkLen; i++) {
        text[i] = watermark[i] ^ text[i];
    }
}

// Function to extract the watermark from the given text using the keyword
// Returns the key value
int extractWatermark(char text[], char keyword[]) {
    int textLen = strlen(text);
    int keywordLen = strlen(keyword);
    int watermarkLen = keywordLen + 1;
    char watermark[watermarkLen];

    // Extract the watermark from the first few characters of the text
    // The number of characters used to embed the watermark depends on the length of the watermark
    for (int i = 0; i < watermarkLen; i++) {
        watermark[i] = text[i] ^ keyword[i];
    }

    // Parse the watermark to extract the key value
    char keyStr[keywordLen];
    strncpy(keyStr, watermark + strlen(keyword), keywordLen);
    int key = atoi(keyStr);
    return key;
}

int main() {
    // Example usage of the watermarking functions
    char text[] = "This is some example text.";
    char keyword[] = "watermark";
    int key = 1234;

    // Embed the watermark
    embedWatermark(text, keyword, key);

    // Print the text with the embedded watermark
    printf("Original text: %s\n", text);

    // Extract the watermark and key value from the text
    int extractedKey = extractWatermark(text, keyword);

    // Print the extracted key value
    printf("Extracted key: %d\n", extractedKey);

    return 0;
}