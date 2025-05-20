//FormAI DATASET v1.0 Category: QR code reader ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to validate input
bool validateInput(const char* input) {
    int len = strlen(input);

    if (len != 25) {
        return false;
    }

    if (strncmp(input, "C-RE64-PIFC-SA21", 16) != 0) {
        return false;
    }

    for (int i = 16; i < len; i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }

    return true;
}

// Function to read and validate QR code
char* readQRCode(void) {
    char* input = (char*) malloc(sizeof(char) * 26);

    printf("Please scan QR code: ");
    scanf("%s", input);

    if (!validateInput(input)) {
        printf("ERROR: Invalid QR code!\n");
        free(input);
        return NULL;
    }

    return input;
}

int main(void) {
    char* input = readQRCode();

    if (input == NULL) {
        return 1;
    }

    // Parse input and extract information
    char region[3];
    char device[4];
    char year[4];

    strncpy(region, input + 5, 2);
    region[2] = '\0';

    strncpy(device, input + 7, 3);
    device[3] = '\0';

    strncpy(year, input + 10, 4);
    year[4] = '\0';

    printf("QR Code Information:\n");
    printf("Region: %s\n", region);
    printf("Device: %s\n", device);
    printf("Year: %s\n", year);

    free(input);
    return 0;
}