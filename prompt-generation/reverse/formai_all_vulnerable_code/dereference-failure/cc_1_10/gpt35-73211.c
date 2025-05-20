//FormAI DATASET v1.0 Category: QR code generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 1000
#define PLAYER_COUNT 2

char* generateCode() {
    char* code = malloc(MAX_LENGTH * sizeof(char));
    srand(time(NULL));
    for(int i=0; i<6; i++) {
        int r = rand() % 36;
        if(r < 26) {
            code[i] = 'A' + r;
        } else {
            code[i] = '0' + (r - 26);
        }
    }
    code[6] = '\0';
    return code;
}

void printQRCode(char code[]) {
    printf("QR code: \n");
    printf(" _________________________\n");
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
    printf("|@@@@@@@@%c@@@@@@@@@@@@@@@|\n", code[0]);
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
    printf("|@@@@@@@@@@@@%c@@@@@@@@@@@|\n", code[1]);
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
    printf("|@@@@@@@@@@@@@@@@%c@@@@@@@|\n", code[2]);
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
    printf("|@@@@@@@@@@@@@@@@@@@@%c@@@|\n", code[3]);
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
    printf("|@@@@@@@@@@@@@@@@@@@@@@%c@|\n", code[4]);
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@%c|\n", code[5]);
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
    printf("|@@@@@@@@@@@@@@@@@@@@@@@@@|\n");
    printf("|_________________________|\n");
}

int main() {
    char* code = generateCode();
    printQRCode(code);
    free(code);

    printf("\nWelcome!\nThis is a multiplayer game where you need to scan QR codes to play.\n");

    char input[MAX_LENGTH];
    char* qrCodes[PLAYER_COUNT];

    for(int i=0; i<PLAYER_COUNT; i++) {
        printf("\nPlayer %d, please enter your QR code: ", i+1);
        fgets(input, MAX_LENGTH, stdin);
        strtok(input, "\n");
        qrCodes[i] = strdup(input);
    }

    printf("\nQR codes entered:\n");
    for(int i=0; i<PLAYER_COUNT; i++) {
        printf("Player %d: %s\n", i+1, qrCodes[i]);
    }

    int winnnerIndex = rand() % PLAYER_COUNT;
    printf("\nAnd the winner is... Player %d!\n", winnnerIndex+1);

    for(int i=0; i<PLAYER_COUNT; i++) {
        free(qrCodes[i]);
    }

    return 0;
}