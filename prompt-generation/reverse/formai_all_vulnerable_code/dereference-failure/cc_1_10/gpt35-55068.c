//FormAI DATASET v1.0 Category: Image Steganography ; Style: grateful
#include <stdio.h>

//function to get the value of a specific bit from a number
int getBitValue(unsigned char byte, int bit){
    return (byte >> bit) & 1;
}

//function to change the value of a specific bit in a number
void setBitValue(unsigned char *byte, int bit, int value){
    *byte |= (value << bit);
}

//function to hide data in the least significant bits of an image
void hideData(unsigned char* imageData, unsigned char* messageData, int messageLength){
    for(int i=0; i < messageLength; i++){
        unsigned char messageByte = *(messageData+i);
        for(int j=0; j < 8; j++){
            unsigned char imageByte = *(imageData+i*8+j);
            setBitValue(&imageByte, 0, getBitValue(messageByte, j));
            *(imageData+i*8+j) = imageByte;
        }
    }
}

//function to retrieve data hidden in the least significant bits of an image
void retrieveData(unsigned char* imageData, unsigned char* messageData, int messageLength){
    for(int i=0; i < messageLength; i++){
        unsigned char messageByte = 0;
        for(int j=0; j < 8; j++){
            unsigned char imageByte = *(imageData+i*8+j);
            setBitValue(&messageByte, j, getBitValue(imageByte, 0));
        }
        *(messageData+i) = messageByte;
    }
}

int main(){
    //open image file
    FILE* imageFile = fopen("image.jpg", "rb");
    if(imageFile == NULL){
        printf("Error: could not open image file.\n");
        return 1;
    }

    //get image size
    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);

    //allocate memory for image data
    unsigned char* imageData = (unsigned char*)malloc(imageSize);
    if(imageData == NULL){
        printf("Error: could not allocate memory for image data.\n");
        fclose(imageFile);
        return 1;
    }

    //read image data into memory
    int bytesRead = fread(imageData, 1, imageSize, imageFile);
    if(bytesRead != imageSize){
        printf("Error: could not read image data into memory.\n");
        free(imageData);
        fclose(imageFile);
        return 1;
    }

    //close image file
    fclose(imageFile);

    //open message file
    FILE* messageFile = fopen("message.txt", "rb");
    if(messageFile == NULL){
        printf("Error: could not open message file.\n");
        free(imageData);
        return 1;
    }

    //get message size
    fseek(messageFile, 0, SEEK_END);
    int messageSize = ftell(messageFile);
    fseek(messageFile, 0, SEEK_SET);

    //allocate memory for message data
    unsigned char* messageData = (unsigned char*)malloc(messageSize);
    if(messageData == NULL){
        printf("Error: could not allocate memory for message data.\n");
        fclose(messageFile);
        free(imageData);
        return 1;
    }

    //read message data into memory
    bytesRead = fread(messageData, 1, messageSize, messageFile);
    if(bytesRead != messageSize){
        printf("Error: could not read message data into memory.\n");
        free(messageData);
        fclose(messageFile);
        free(imageData);
        return 1;
    }

    //close message file
    fclose(messageFile);

    //hide message data in image
    hideData(imageData, messageData, messageSize);

    //save modified image to file
    FILE* modifiedImageFile = fopen("modified_image.jpg", "wb");
    if(modifiedImageFile == NULL){
        printf("Error: could not open modified image file.\n");
        free(imageData);
        return 1;
    }

    fwrite(imageData, 1, imageSize, modifiedImageFile);
    fclose(modifiedImageFile);

    //retrieve message data from modified image
    unsigned char* retrievedMessageData = (unsigned char*)malloc(messageSize);
    if(retrievedMessageData == NULL){
        printf("Error: could not allocate memory for retrieved message data.\n");
        free(imageData);
        return 1;
    }

    retrieveData(imageData, retrievedMessageData, messageSize);

    //print retrieved message
    printf("Retrieved Message: %s\n", retrievedMessageData);

    //free memory
    free(imageData);
    free(messageData);
    free(retrievedMessageData);

    return 0;
}