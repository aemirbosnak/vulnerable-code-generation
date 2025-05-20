//FormAI DATASET v1.0 Category: QR code reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 50

bool isQRValid(char qrCode[MAX_LEN]){
    // Check if the string is empty
    int len = strlen(qrCode);
    if (len == 0){
        return false;
    }
    
    // Check if the string starts and ends with Q
    if (qrCode[0] != 'Q' || qrCode[len-1] != 'Q'){
        return false;
    }

    // Validate the contents of the code
    for (int i = 1; i < len-1; i++){
        if (qrCode[i] < 'A' || qrCode[i] > 'Z'){
            return false;
        }
    }

    // If all checks pass, return true
    return true;
}

char* readQR(){
    // Allocate memory for the maximum possible length of the QR code
    char* qrCode = (char*)malloc(MAX_LEN*sizeof(char)); 

    printf("Please scan QR code: ");
    scanf("%s", qrCode);

    // Validation check
    if (!isQRValid(qrCode)){
        printf("Invalid QR code. Please try again.\n");
        return NULL;
    }

    return qrCode;
}

int main(){
    char* qrCode = NULL;

    // Keep prompting the user until a valid QR code is scanned
    while (qrCode == NULL){
        qrCode = readQR();
    }

    printf("QR code is: %s\n", qrCode);

    free(qrCode); // free the memory allocated for the QR code string

    return 0;
}