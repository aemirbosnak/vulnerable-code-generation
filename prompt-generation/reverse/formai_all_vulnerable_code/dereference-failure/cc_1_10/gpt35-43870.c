//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defines the maximum length of the input message
#define MAX_MSG_SIZE 100

//defines the watermark size
#define WATERMARK_SIZE 10

//define the maximum length of the final watermarked message
#define OUTPUT_MSG_SIZE MAX_MSG_SIZE + WATERMARK_SIZE

//function to generate the watermark
char *generateWatermark(){
    char *watermark = malloc(WATERMARK_SIZE+1);
    strcpy(watermark, "WATERMARK");
    return watermark;
}

//function to embed the watermark into the message
char *embedWatermark(char *message, char *watermark){
    int i = 0, j = 0, k = 0;
    char *outputMessage = malloc(OUTPUT_MSG_SIZE+1);

    //copy the message into the output string and insert the watermark
    for(i = 0; i < strlen(message); i++){
        if(j < WATERMARK_SIZE){
            outputMessage[k++] = watermark[j++];
        }
        outputMessage[k++] = message[i];
    }

    //if the watermark is longer than the message, append it
    while(j < WATERMARK_SIZE){
        outputMessage[k++] = watermark[j++];
    }

    outputMessage[k] = '\0';

    //clean up the memory
    free(message);
    free(watermark);

    return outputMessage;
}

int main(){
    char *message = malloc(MAX_MSG_SIZE+1);
    char *watermark = generateWatermark();
    char *outputMessage;

    //get the input message from the user
    printf("Enter your message: ");
    fgets(message, MAX_MSG_SIZE, stdin);

    //embed the watermark into the message
    outputMessage = embedWatermark(message, watermark);

    //display the watermarked message
    printf("Watermarked message: %s\n", outputMessage);

    //clean up the memory
    free(outputMessage);

    return 0;
}