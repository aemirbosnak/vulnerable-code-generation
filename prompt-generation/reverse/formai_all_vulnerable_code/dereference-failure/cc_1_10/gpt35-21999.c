//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// function to generate a random watermark string of given length
char* generateWatermark(int length) {
    char* watermark = (char*) malloc(sizeof(char) * (length + 1));
    srand(time(NULL)); // seeding the random number generator
    int i;
    for(i=0; i<length; i++) {
        int r = rand() % 26; // generating a random number between 0 and 26
        watermark[i] = r + 'A'; // converting the number to a capital letter
    }
    watermark[length] = '\0';
    return watermark;
}

// function to embed the watermark in the given message using the LSB algorithm
void embedWatermark(char* message, char* watermark) {
    int mLen = strlen(message);
    int wLen = strlen(watermark);
    if(wLen > (mLen/8)) {
        printf("Message is too small to hold the watermark!\n");
        return;
    }
    int i, j, k;
    k = 0;
    for(i=0; i<mLen; i=i+8) {
        if(k == wLen) break;
        for(j=0; j<8; j++) {
            if(k == wLen) break;
            int bit = ((watermark[k] & (1 << j)) > 0) ? 1 : 0; // extracting the jth bit of the kth character of the watermark
            message[i+j] = (message[i+j] & 254) | bit; // inserting the bit in the least significant bit of the ith byte of the message
            k++;
        }
    }
}

// function to extract the watermark from the given message using the LSB algorithm
char* extractWatermark(char* message, int watermarkLength) {
    int mLen = strlen(message);
    char* watermark = (char*) malloc(sizeof(char) * (watermarkLength + 1));
    int i, j, k;
    k = 0;
    for(i=0; i<mLen; i=i+8) {
        if(k == watermarkLength) break;
        char ch = 0;
        for(j=0; j<8; j++) {
            ch = ch | ((message[i+j] & 1) << j); // extracting the least significant bit of the ith byte of the message and inserting it in the jth bit of the kth character of the watermark
        }
        watermark[k] = ch;
        k++;
    }
    watermark[watermarkLength] = '\0';
    return watermark;
}

int main() {
    char message[] = "This is a sample message that we want to embed a watermark in.";
    char* watermark = generateWatermark(10); // generate a 10-character-long watermark
    printf("Watermark: %s\n", watermark);
    embedWatermark(message, watermark);
    printf("Message with watermark: %s\n", message);
    char* extractedWatermark = extractWatermark(message, strlen(watermark));
    printf("Extracted Watermark: %s\n", extractedWatermark);
    free(watermark);
    free(extractedWatermark);
    return 0;
}