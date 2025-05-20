//FormAI DATASET v1.0 Category: QR code reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define CODE_MAX_LENGTH 256
#define WIDTH 21
#define CODE_START "##########"
#define CODE_END "##########"

void printCode(char* code, int length){
    for(int i=0;i<length;i++){
        if((i+1)%WIDTH==0){
            printf("|\n");
        }
        printf("%c",code[i]);
    }
    printf("|");
}

bool checkCode(char* code, int length){

    char startCode[] = CODE_START;
    char endCode[] = CODE_END;

    for(int i=0;i<10;i++){
        if(code[i]!=startCode[i] || code[length-11+i]!=endCode[i]){
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    printf("Please enter QR code:\n");

    char* input = (char*) malloc(sizeof(char) * CODE_MAX_LENGTH);
    fgets(input,CODE_MAX_LENGTH,stdin);
    int length = strlen(input)-1;
    input[length]=NULL;

    if (length<248) {
        printf("Invalid code entered.\n");
        return 0;
    }

    if(!checkCode(input,length)){
        printf("Invalid code entered.\n");
        return 0;
    }

    printf("QR code read successfully:\n");
    printf("|--------------|\n");
    printCode(input+10,length-20);
    printf("\n|--------------|\n");
    free(input);
    return 0;
}