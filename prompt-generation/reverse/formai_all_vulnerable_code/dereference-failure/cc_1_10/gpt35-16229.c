//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encryptText(char* str, int key) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = (str[i] + key) % 127;
    }
}

void decryptText(char* str, int key) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = (str[i] - key + 127) % 127;
    }
}

void generateKey(char *key) {
    srand(time(NULL));
    for(int i=0;i<16;i++) {
        key[i] = (rand() % (127 - 33)) + 33;
    }
}

void shiftEncryption(char* str, char* key) {
    int keylen = strlen(key);
    int keyIndex = 0;
    for (int i = 0; i < strlen(str); i++) {
        str[i] = (str[i] + key[keyIndex]) % 127;
        keyIndex = (keyIndex + 1) % keylen;
    }
}

void shiftDecryption(char* str, char* key) {
    int keylen = strlen(key);
    int keyIndex = 0;
    for (int i = 0; i < strlen(str); i++) {
        str[i] = (str[i] - key[keyIndex] + 127) % 127;
        keyIndex = (keyIndex + 1) % keylen;
    }
}

void shapeShift(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            if (str[i] == 'z') {
                str[i] = 'a';
            }
            else if (str[i] == 'Z') {
                str[i] = 'A';
            }
            else {
                str[i] += 1;
            }
            if (i % 2 == 0) {
                str[i] = toupper(str[i]);
            }
        }
        else if(str[i] >= '0' && str[i] <= '9') {
            str[i] = '0' + ((str[i] - '0' + 1) % 10);
        }
    }
}

void shapeShiftInverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            if (str[i] == 'a') {
                str[i] = 'z';
            }
            else if (str[i] == 'A') {
                str[i] = 'Z';
            }
            else {
                str[i] -= 1;
            }
            if (i % 2 == 0) {
                str[i] = tolower(str[i]);
            }
        }
        else if(str[i] >= '0' && str[i] <= '9') {
            str[i] = '0' + ((str[i] - '0' + 9) % 10);
        }
    }
}

int main() {
    char str[1000];
    char key[16];

    printf("Enter a message to encrypt using shape shifting and shift encryption:\n");
    fgets(str, sizeof(str), stdin);

    generateKey(key);

    shapeShift(str);
    shiftEncryption(str, key);

    printf("The encrypted message is:\n%s", str);

    shiftDecryption(str, key);
    shapeShiftInverse(str);

    printf("The decrypted message is:\n%s", str);

    return 0;
}