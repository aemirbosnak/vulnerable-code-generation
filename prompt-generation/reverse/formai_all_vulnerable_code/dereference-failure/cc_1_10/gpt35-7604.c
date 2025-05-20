//FormAI DATASET v1.0 Category: QR code reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QR_CODE_LENGTH 1000
#define MAX_ENTRY_LENGTH 100

/**
 * Function to validate whether the given string is a valid QR code or not
 *
 * @param qrCode The QR code string
 * @return True if the input string is a valid QR code, False otherwise
 */
bool validateQRCode(char* qrCode) {
    // Check if the input string length is within limits
    if (strlen(qrCode) > MAX_QR_CODE_LENGTH) {
        printf("Sorry! The input QR code is too long.\n");
        return false;
    }

    // Check if all characters in the input string are either '0' or '1'
    for (int i = 0; i < strlen(qrCode); i++) {
        if (qrCode[i] != '0' && qrCode[i] != '1') {
            printf("Sorry! The input QR code contains invalid characters.\n");
            return false;
        }
    }

    return true;
}

/**
 * Function to parse the QR code and extract the entries
 *
 * @param qrCode The QR code string
 * @param entries An array of strings to store the extracted entries
 * @param numEntries The number of entries extracted from the QR code
 */
void parseQRCode(char* qrCode, char** entries, int* numEntries) {
    int entryLength = 0;
    char* entry = malloc(MAX_ENTRY_LENGTH * sizeof(char));

    // Iterate through the QR code string and extract the entries
    for (int i = 0; i < strlen(qrCode); i++) {
        entry[entryLength++] = qrCode[i];

        // Check if the current entry is complete
        if (qrCode[i] == ';') {
            entry[entryLength - 1] = '\0';
            entries[(*numEntries)++] = strdup(entry);
            entryLength = 0;
        }
    }

    free(entry);
}

/**
 * Main function to read a QR code and extract the entries
 *
 * @return The exit status code
 */
int main() {
    char* qrCode = malloc(MAX_QR_CODE_LENGTH * sizeof(char));
    char** entries = malloc(MAX_QR_CODE_LENGTH * sizeof(char*));
    int numEntries = 0;

    printf("Welcome to the QR code reader program!\n");
    printf("Please enter a valid QR code containing semicolon-separated entries:\n");
    scanf("%s", qrCode);

    if (validateQRCode(qrCode)) {
        parseQRCode(qrCode, entries, &numEntries);

        printf("QR code successfully read!\n");
        printf("The following entries were extracted from the QR code:\n");

        // Iterate through the extracted entries and print them
        for (int i = 0; i < numEntries; i++) {
            printf("%d. %s\n", i + 1, entries[i]);
        }
    }

    // Free the allocated memory
    free(qrCode);
    for (int i = 0; i < numEntries; i++) {
        free(entries[i]);
    }
    free(entries);

    return 0;
}