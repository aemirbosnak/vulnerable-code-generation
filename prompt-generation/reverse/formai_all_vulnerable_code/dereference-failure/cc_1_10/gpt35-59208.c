//FormAI DATASET v1.0 Category: Image Steganography ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    unsigned char r,g,b;
}Pixel;

typedef struct {
    int width,height;
    Pixel* data;
}Image;

//Read image function
int readImage(FILE* fp,Image* img) {
    char magicNumber[3];
    int max;
    fscanf(fp,"%s",magicNumber);
    if(strcmp(magicNumber,"P3")==0) {
        fscanf(fp,"%d%d%d",&img->width,&img->height,&max);
        img->data = (Pixel*)malloc(sizeof(Pixel)*img->width*img->height);
        for(int i=0;i<img->width*img->height;i++) {
            fscanf(fp,"%hhu%hhu%hhu",&img->data[i].r,&img->data[i].g,&img->data[i].b);
        }
        return 1;
    } else {
        return 0;
    }
}

//Write image function
void writeImage(FILE* fp,Image* img) {
    fprintf(fp,"P3\n%d %d\n255\n",img->width,img->height);
    for(int i=0;i<img->width*img->height;i++) {
        fprintf(fp,"%u %u %u ",img->data[i].r,img->data[i].g,img->data[i].b);
    }
}

//Encode function
void encode(Image* img,char* message) {
    int len = strlen(message);
    int i=0,j=0;
    while(i<len) {
        char c = message[i];
        //modify the LSB of each channel (r,g,b) to encode the character
        img->data[j].r &= 0xFE;
        img->data[j].r |= (c>>7) & 0x01;
        img->data[j].g &= 0xFE;
        img->data[j].g |= (c>>6) & 0x01;
        img->data[j].b &= 0xFE;
        img->data[j].b |= (c>>5) & 0x01;
        j++;
        img->data[j].r &= 0xFE;
        img->data[j].r |= (c>>4) & 0x01;
        img->data[j].g &= 0xFE;
        img->data[j].g |= (c>>3) & 0x01;
        img->data[j].b &= 0xFE;
        img->data[j].b |= (c>>2) & 0x01;
        j++;
        img->data[j].r &= 0xFE;
        img->data[j].r |= (c>>1) & 0x01;
        img->data[j].g &= 0xFE;
        img->data[j].g |= c & 0x01;
        j++;
        i++;
    }
}

//Decode function
char* decode(Image* img,int len) {
    char* message = (char*)malloc(sizeof(char)*len);
    int i=0,j=0;
    while(i<len) {
        char c = 0;
        c |= (img->data[j].r & 0x01) << 7;
        c |= (img->data[j].g &0x01) << 6;
        c |= (img->data[j].b & 0x01) << 5;
        j++;
        c |= (img->data[j].r & 0x01) << 4;
        c |= (img->data[j].g &0x01) << 3;
        c |= (img->data[j].b & 0x01) << 2;
        j++;
        c |= (img->data[j].r & 0x01) << 1;
        c |= img->data[j].g & 0x01;
        j++;
        message[i] = c;
        i++;
    }
    return message;
}

int main(int argc,char** argv) {
    if(argc!=4) {
        printf("Usage: ./stegano encode/decode input_image output_image\n");
        return 1;
    }
    char* mode = argv[1];
    char* input_file = argv[2];
    char* output_file = argv[3];

    FILE* fp = fopen(input_file,"r");
    if(!fp) {
        printf("Cannot open file\n");
        return 1;
    }

    Image img;
    if(!readImage(fp,&img)) {
        printf("Invalid image format\n");
        return 1;
    }

    fclose(fp);

    //If mode is encode, take input message from user and encode it into the image
    if(strcmp(mode,"encode")==0) {
        printf("Enter message to hide:\n");

        char message[1000];
        fgets(message,sizeof(message),stdin);
        message[strlen(message)-1] = '\0';

        encode(&img,message);

        fp = fopen(output_file,"w");
        if(!fp) {
            printf("Cannot open file\n");
            return 1;
        }

        writeImage(fp,&img);

        fclose(fp);
    }
    //If mode is decode, decode the message from the image
    else if(strcmp(mode,"decode")==0) {

        char* message = decode(&img,strlen(argv[2]));

        printf("%s",message);

        free(message);
    }
    return 0;
}