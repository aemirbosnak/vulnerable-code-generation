//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: scientific
#include<stdio.h>

//Function to generate unique digital watermark for image
void digitalWatermark(char message[], char image[]){
    //Open image file 
    FILE *fptr = fopen(image, "rb+");
    
    //If image file doesn't exist
    if(fptr == NULL){
        printf("Error: File not found");
        return;
    }
    
    //Open message file 
    FILE *fptrMsg = fopen(message, "r");
    if(fptrMsg == NULL){
        printf("Error: File not found");
        return;
    }
    
    //Skip header of the image file
    fseek(fptr, 54, SEEK_SET);
    
    //Variable to store character from message file
    char c;
    
    //Loop through entire message file
    while((c = fgetc(fptrMsg)) != EOF){
        //Loop through 8 bits of character from message file
        for(int i=0; i<8; i++){
            //Loop through 3 bytes of image file
            for(int j=0; j<3; j++){
                //Get current pixel value of image
                char pixelValue = 0;
                fread(&pixelValue, sizeof(char), 1, fptr);
                
                //Check if current bit of message is 0 or 1
                if(c & (1 << i)){
                    //If message bit is 1 and pixel value is even, increment pixel value by 1
                    if(pixelValue%2 == 0){
                        fseek(fptr, -1, SEEK_CUR);
                        pixelValue = pixelValue + 1;
                        fwrite(&pixelValue, sizeof(char), 1, fptr);
                    }
                }
                else{
                    //If message bit is 0 and pixel value is odd, decrement pixel value by 1
                    if(pixelValue%2 != 0){
                        fseek(fptr, -1, SEEK_CUR);
                        pixelValue = pixelValue - 1;
                        fwrite(&pixelValue, sizeof(char), 1, fptr);
                    }
                }
            }
        }
    }
    
    //Close files
    fclose(fptr);
    fclose(fptrMsg);
    printf("Digital watermarking done successfully");
}

int main(){
    char message[] = "message.txt";  //Message file
    char image[] = "image.bmp";     //Image file
    digitalWatermark(message, image);
    return 0;
}