//Falcon2-11B DATASET v1.0 Category: Checksum Calculator ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 100
#define MAX_CHECKSUM_LEN 5

typedef struct {
    char message[MAX_LEN];
    char checksum[MAX_CHECKSUM_LEN];
} Checksum;

void calculate_checksum(Checksum* checksum) {
    // Calculate checksum based on the message
    char* message = checksum->message;
    int length = strlen(message);

    int checksum_length = length % 2 == 0? length / 2 : (length / 2 + 1);
    checksum_length += 1; // Adding 1 for the delimiter

    char checksum_string[checksum_length + 1];
    int i = 0;
    for (int j = 0; j < length; j += 2) {
        int num = (int) message[j] - (int) '0';
        int mod = num % 10;
        num = (num / 10) * 10;
        if (j < length - 1) {
            num += (int) message[j + 1] - (int) '0';
            num %= 10;
        }
        checksum_string[i++] = (char) num + '0';
        if (i >= checksum_length) {
            break;
        }
    }
    checksum_string[i] = '\0';

    checksum->checksum[0] = '\0';
    for (int j = 0; j < checksum_length; j++) {
        if (j % 2 == 0) {
            checksum->checksum[j / 2] = checksum_string[j] - '0';
        } else {
            checksum->checksum[j / 2 + 1] = checksum_string[j] - '0';
        }
    }
    checksum->checksum[checksum_length] = '\0';
}

int main() {
    Checksum checksum;
    printf("Enter a message: ");
    fgets(checksum.message, MAX_LEN, stdin);
    if (strlen(checksum.message) > MAX_LEN - 1) {
        printf("Message length exceeds maximum allowed length.\n");
        return 1;
    }
    calculate_checksum(&checksum);
    printf("Message: %s\n", checksum.message);
    printf("Checksum: %s\n", checksum.checksum);
    return 0;
}