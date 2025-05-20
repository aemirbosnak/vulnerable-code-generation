//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0;
    int i = 0;
    while (binary[i]!= '\0') {
        int digit = binary[i] - '0';
        decimal += digit * pow(2, (sizeof(int) * 8 - 1) - i);
        i++;
    }
    return decimal;
}

// Function to convert decimal to binary
char* decimalToBinary(int decimal) {
    int length = 0;
    int i = 0;
    int binary[32] = {0};

    while (decimal > 0) {
        binary[length] = decimal % 2;
        decimal /= 2;
        length++;
    }

    char* binaryString = malloc(sizeof(char) * (length + 1));
    for (i = 0; i < length; i++) {
        binaryString[i] = binary[length - 1 - i] + '0';
    }
    binaryString[length] = '\0';

    return binaryString;
}

// Function to convert decimal to binary using system call
int systemCallToBinary(int decimal) {
    char* binary = malloc(sizeof(char) * 32);
    int pid = fork();

    if (pid == 0) {
        sprintf(binary, "%d", decimal);
        printf("%s\n", binary);
    } else if (pid > 0) {
        // Parent process
        waitpid(pid, NULL, 0);
        free(binary);
    } else {
        // Child process
        execlp("echo", "echo", binary, NULL);
    }

    free(binary);
    return 0;
}

int main() {
    int decimal = 10;

    printf("Decimal: %d\n", decimal);

    char* binary = decimalToBinary(decimal);
    printf("Binary: %s\n", binary);

    systemCallToBinary(decimal);

    free(binary);

    return 0;
}