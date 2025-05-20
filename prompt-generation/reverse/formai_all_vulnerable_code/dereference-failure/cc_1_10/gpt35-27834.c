//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK "This text is watermarked"

void embedWatermark(FILE* inputFile, FILE* outputFile){
    char c;
    int i = 0;

    while((c = fgetc(inputFile)) != EOF){
        if(i < strlen(WATERMARK)){
            fputc(c ^ WATERMARK[i], outputFile);
            i++;
        }
        else{
            fputc(c, outputFile);
        }
    }
}

int checkWatermark(FILE* file){
    char c;
    int i = 0;

    while((c = fgetc(file)) != EOF){
        if(i < strlen(WATERMARK)){
            if(c != WATERMARK[i] ^ i){
                return 0;
            }
            i++;
        }
        else{
            return 1;
        }
    }

    return 0;
}

int main(){
    char inputFileName[100], outputFileName[100], checkFileName[100];
    FILE* inputFile;
    FILE* outputFile;
    FILE* checkFile;
    int choice;

    printf("Enter the input file name: ");
    scanf("%s", inputFileName);

    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    printf("Do you want to embed or check the watermark? (1 - Embed, 2 - Check): ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            inputFile = fopen(inputFileName, "r");
            outputFile = fopen(outputFileName, "w");

            if(inputFile == NULL){
                printf("Error opening input file!");
                exit(1);
            }

            if(outputFile == NULL){
                printf("Error opening output file!");
                exit(1);
            }

            embedWatermark(inputFile, outputFile);
            printf("Watermark embedded successfully!");

            fclose(inputFile);
            fclose(outputFile);

            break;
        case 2:
            printf("Enter the file name to check watermark: ");
            scanf("%s", checkFileName);

            checkFile = fopen(checkFileName, "r");

            if(checkFile == NULL){
                printf("Error opening check file!");
                exit(1);
            }

            if(checkWatermark(checkFile)){
                printf("This file contains the watermark!");
            }
            else{
                printf("This file does not contain the watermark!");
            }

            fclose(checkFile);

            break;
        default:
            printf("Invalid choice!");
            break;
    }

    return 0;
}