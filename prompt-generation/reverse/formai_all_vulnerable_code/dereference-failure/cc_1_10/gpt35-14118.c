//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WATERMARK_HEADER 3
#define WATERMARK_FOOTER 2
#define MAX_MESSAGE_LENGTH 50

char* generateWatermark(char* message);

int main(){
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter message to encode (max length %d): ", MAX_MESSAGE_LENGTH);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    
    char* watermark = generateWatermark(message);
    printf("The generated watermark is: %s\n", watermark);

    // write watermark to file
    FILE* file = fopen("watermark.txt", "w");
    if(file == NULL){
        printf("Could not write watermark to file.\n");
        return 1;
    }
    fprintf(file, "%s", watermark);
    fclose(file);

    printf("Watermark successfully written to file.\n");

    // read watermark from file
    file = fopen("watermark.txt", "r");
    if(file == NULL){
        printf("Could not read watermark from file.\n");
        return 1;
    }
    char readWatermark[MAX_MESSAGE_LENGTH + WATERMARK_HEADER + WATERMARK_FOOTER];
    fgets(readWatermark, MAX_MESSAGE_LENGTH + WATERMARK_HEADER + WATERMARK_FOOTER, file);
    fclose(file);

    printf("The read watermark is: %s\n", readWatermark);

    return 0;
}

char* generateWatermark(char* message){
    srand(time(NULL)); // to generate random numbers
    int messageLength = strlen(message);
    int watermarkLength = messageLength + WATERMARK_HEADER + WATERMARK_FOOTER; // header and footer added for encoding
    char* watermark = malloc((watermarkLength + 1) * sizeof(char)); // allocate memory for watermark
    watermark[watermarkLength] = '\0'; // set last character of watermark as null character for string termination

    int* randomIndices = malloc((watermarkLength - WATERMARK_HEADER - WATERMARK_FOOTER) * sizeof(int)); // allocate memory for array of random indices
    int i;
    for(i = 0; i < watermarkLength - WATERMARK_HEADER - WATERMARK_FOOTER; i++){
        randomIndices[i] = rand() % watermarkLength; // generate random index
        int j;
        for(j = 0; j < i; j++){
            if(randomIndices[i] == randomIndices[j]){ // check if index already exists
                i--;
                break; // if it does, generate new index
            }
        }
    }

    int index;
    int j;
    for(index = 0, j = 0; index < watermarkLength; index++){
        if(index < WATERMARK_HEADER || index >= watermarkLength - WATERMARK_FOOTER){ // if header or footer, place dollar symbol
            watermark[index] = '$';
        }
        else{ // otherwise, place corresponding characters
            if(index == randomIndices[j]){ // if index should have character from message
                watermark[index] = message[j];
                j++;
            }
            else{ // otherwise, place random character
                watermark[index] = (rand() % 93) + 33; // 33 is ASCII code for '!', 126 is ASCII code for '~', have 93 possible characters
            }
        }
    }

    free(randomIndices); // free memory for array of random indices
    return watermark;
}