//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: immersive
#include<stdio.h>
#include<string.h>

// Function to extract bits from integer
int extractBit(int num, int bitIndex){
    return ((num >> bitIndex) & 1);
}

// Function to set a bit in integer
int setBit(int num, int bitIndex){
    return (num | (1 << bitIndex));
}

// Function to clear a bit in integer
int clearBit(int num, int bitIndex){
    return (num & ~(1 << bitIndex));
}

// Function to print an integer in binary format
void binary(int num){
    for(int i=31; i>=0; i--){
        printf("%d", extractBit(num, i));
    }
}

// Function to embed watermark in an integer
int embedWatermark(int num, char watermark[]){
    int watermarkIndex = 0;
    for(int i=0; i<32; i++){
        if(i%2 == 0 && watermarkIndex < strlen(watermark)){
            // If even bit, embed watermark bit
            if(watermark[watermarkIndex] == '1'){
                num = setBit(num, i);
            }
            else{
                num = clearBit(num, i);
            }
            watermarkIndex++;
        }
    }
    return num;
}

// Function to extract watermark from an integer
char* extractWatermark(int num){
    char watermark[9] = "";
    for(int i=0; i<32; i++){
        if(i%2 == 0){
            // If even bit, extract watermark bit
            if(extractBit(num, i) == 1){
                strcat(watermark, "1");
            }
            else{
                strcat(watermark, "0");
            }
        }
    }
    return watermark;
}

int main(){
    int num = 127; // Example integer
    char watermark[] = "water"; // Example watermark

    printf("Integer: "); binary(num); printf("\n");

    // Embed watermark in integer
    int newNum = embedWatermark(num, watermark);
    printf("Watermark Embedded: "); binary(newNum); printf("\n");

    // Extract watermark from integer
    char* extractedWatermark = extractWatermark(newNum);
    printf("Extracted Watermark: %s\n", extractedWatermark);
    
    return 0;
}