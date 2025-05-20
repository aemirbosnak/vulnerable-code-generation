//FormAI DATASET v1.0 Category: Image Steganography ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

#define BUFFER_SIZE 1000
#define SECRET_KEY "$$h!h@@lL@t"
#define MAX_CHARACTERS_TO_HIDE_IN_IMAGE 100

//function to get size of file
int getFileSize(FILE* fp){
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return size;
}

//function to hide the secret message in image
void hideData(FILE* secret_text_fp, FILE* cover_image_fp, FILE* stego_image_fp) {

    //read cover image
    unsigned char data;
    int cover_image_size = getFileSize(cover_image_fp);
    fwrite(&cover_image_size, sizeof(int), 1, stego_image_fp);
    for(int i=0;i<cover_image_size;i++){
        fread(&data, sizeof(unsigned char), 1, cover_image_fp);
        fwrite(&data, sizeof(unsigned char), 1, stego_image_fp);
    }

    //hide message
    rewind(secret_text_fp);
    char secret_message[MAX_CHARACTERS_TO_HIDE_IN_IMAGE];
    fgets(secret_message, MAX_CHARACTERS_TO_HIDE_IN_IMAGE, secret_text_fp);

    for(int i=0;i<MAX_CHARACTERS_TO_HIDE_IN_IMAGE;i++){
        char secret_character = secret_message[i];
        if(secret_character == '\n' || secret_character == '\0'){
            break;
        }
        char secret_key_character = SECRET_KEY[i%strlen(SECRET_KEY)];
        unsigned char cover_image_data;
        fread(&cover_image_data, sizeof(unsigned char), 1, cover_image_fp);

        unsigned char stego_image_data = (cover_image_data & 0b11111100) | ((secret_character >> 6) & 0b00000011);
        fwrite(&stego_image_data, sizeof(unsigned char), 1, stego_image_fp);

        stego_image_data = (cover_image_data & 0b11111100) | ((secret_character >> 4) & 0b00000011);
        fwrite(&stego_image_data, sizeof(unsigned char), 1, stego_image_fp);

        stego_image_data = (cover_image_data & 0b11111100) | ((secret_character >> 2) & 0b00000011);
        fwrite(&stego_image_data, sizeof(unsigned char), 1, stego_image_fp);

        stego_image_data = (cover_image_data & 0b11111100) | (secret_character & 0b00000011);
        fwrite(&stego_image_data, sizeof(unsigned char), 1, stego_image_fp);
    }

    //copy remaining data from cover image
    while(fread(&data, sizeof(unsigned char), 1, cover_image_fp)){
        fwrite(&data, sizeof(unsigned char), 1, stego_image_fp);
    }

    printf("\nMessage Hiding Successful\n\n");
}

//function to extract secret message from image
void extractData(FILE* stego_image_fp) {
    
    //read stego image
    int cover_image_size;
    fread(&cover_image_size, sizeof(int), 1, stego_image_fp);
    printf("Cover Image Size: %d\n", cover_image_size);

    //extract message
    char extracted_secret_message[MAX_CHARACTERS_TO_HIDE_IN_IMAGE];
    int char_count = 0;
    unsigned char stego_image_data;
    while(fread(&stego_image_data, sizeof(unsigned char), 1, stego_image_fp)) {
        if (char_count >= MAX_CHARACTERS_TO_HIDE_IN_IMAGE){
            break;
        }
        char extracted_character;

        extracted_character = (stego_image_data & 0b00000011) << 6;
        if(extracted_character == 0){
            break;
        }
        fread(&stego_image_data, sizeof(unsigned char), 1, stego_image_fp);
        extracted_character |= (stego_image_data & 0b00000011) << 4;
        if(extracted_character == 0){
            break;
        }
        fread(&stego_image_data, sizeof(unsigned char), 1, stego_image_fp);
        extracted_character |= (stego_image_data & 0b00000011) << 2;
        if(extracted_character == 0){
            break;
        }
        fread(&stego_image_data, sizeof(unsigned char), 1, stego_image_fp);
        extracted_character |= (stego_image_data & 0b00000011);
        if(extracted_character == 0){
            break;
        }

        char extracted_key_character = SECRET_KEY[char_count%strlen(SECRET_KEY)];
        extracted_character = extracted_character ^ extracted_key_character;

        extracted_secret_message[char_count++] = extracted_character;
    }

    printf("\nExtracted Secret Message: %s\n\n", extracted_secret_message);
}

int main() {

    //Open files
    FILE* secret_text_fp = fopen("secret.txt", "r");
    FILE* cover_image_fp = fopen("cover.jpg", "rb");
    FILE* stego_image_fp = fopen("stego.jpg", "wb");

    if(!secret_text_fp || !cover_image_fp || !stego_image_fp){
        printf("Cannot open file(s).\n");
        exit(1);
    }

    //Hide data
    hideData(secret_text_fp, cover_image_fp, stego_image_fp);

    //Open stego image to extract data
    stego_image_fp = fopen("stego.jpg", "rb");

    if(!stego_image_fp){
        printf("Cannot open stego image.\n");
        exit(1);
    }

    //Extract data
    extractData(stego_image_fp);

    //Close files
    fclose(secret_text_fp);
    fclose(cover_image_fp);
    fclose(stego_image_fp);

    return 0;
}