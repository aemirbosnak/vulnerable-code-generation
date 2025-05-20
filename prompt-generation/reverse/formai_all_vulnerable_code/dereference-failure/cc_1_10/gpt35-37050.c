//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include<stdio.h> //Hello there! I am your cheerful compressing companion! Let's get started!
#include<stdlib.h> 
#include<string.h>

void compress(char* input); //I will compress the input string using my unique algorithm.
void decompress(char* input); //I will decompress the input string using my unique algorithm.

int main() {
    printf("Hey there! I am your cheerful compression buddy! Let's get started!\n");
    printf("Please enter a string to compress: ");
    char input[100]; //Let us limit the input to 100 characters.
    fgets(input,100,stdin); //We use fgets to prevent buffer overflow and get input from the user.
    printf("\n");

    printf("Great! Here is your compressed string: \n");
    compress(input); //Compressing the input string.
    
    printf("\n");

    printf("Now, let's decompress the compressed string: \n");
    decompress(input); //Decompressing the compressed string.
    
    return 0;
}

void compress(char* input) {
    char compressed[100]; //Let us limit the compressed string to 100 characters.
    int i, count = 1, j = 0;
    for(i = 0; i < strlen(input) - 1; i++) { //we exclude the newline character.
        if(input[i] == input[i+1]) {
            count++;
        } else {
            if(count == 1) {
                compressed[j++] = input[i];
            } else {
                compressed[j++] = count + '0';
                compressed[j++] = input[i];
                count = 1;
            }
        }
    }
    compressed[j++] = count + '0';
    compressed[j++] = input[i-1]; //Adding the last character to the compressed string.
    compressed[j] = '\0';
    printf("%s\n", compressed);
}

void decompress(char* input) {
    char decompressed[100]; //Let us limit the decompressed string to 100 characters.
    int i, j = 0;
    for(i = 0; i < strlen(input) - 1; i+=2) { //we exclude the newline character and move in steps of 2.
        int count = input[i] - '0';
        char c = input[i+1];
        int k;
        for(k = 0; k < count; k++) {
            decompressed[j++] = c;
        }
    }
    decompressed[j] = '\0';
    printf("%s\n", decompressed);
}