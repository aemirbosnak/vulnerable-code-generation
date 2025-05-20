//FormAI DATASET v1.0 Category: Image Steganography ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

//function to check if a pixel location is valid
int valid_pixel(int row, int col, int height, int width){
    if(row>=0 && row<height && col>=0 && col<width){
        return 1;
    }
    return 0;
}

//function to get the nth bit of an integer
int get_bit(int num, int n){
    return (num >> n) & 1;
}

//function to set the nth bit of an integer
int set_bit(int num, int n, int bit){
    num &= ~(1 << n);  // first clear the bit at position n
    num |= (bit << n); // then set the bit to the desired value
    return num;
}

//function to read image data from file
void read_image_data(char* filename, int** image_data, int height, int width){
    FILE* image_file_ptr = fopen(filename,"rb");   //open file in binary mode
    if(image_file_ptr != NULL){
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                fread(&image_data[i][j], sizeof(int), 1, image_file_ptr);  //read pixel value
            }
        }
        fclose(image_file_ptr);   //close file
    }
}

//function to write image data to file
void write_image_data(char* filename, int** image_data, int height, int width){
    FILE* image_file_ptr = fopen(filename,"wb");   //open file in binary mode
    if(image_file_ptr != NULL){
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                fwrite(&image_data[i][j], sizeof(int), 1, image_file_ptr);  //write pixel value
            }
        }
        fclose(image_file_ptr);   //close file
    }
}

//function to embed data into the image using LSB substitution
void embed_data(int** image_data, int height, int width, char* message){
    int message_len = strlen(message);

    //calculate number of bits that can be embedded in the image
    int max_bits = height * width * 3;

    if(max_bits < message_len*8){
        printf("Image is not big enough to embed message!\n");
        return;
    }

    //embed message length in the first 32 bits
    for(int i=0; i<32; i++){
        int bit = get_bit(message_len, i);
        image_data[0][i/3] = set_bit(image_data[0][i/3], i%3, bit);
    }

    //embed message data in the remaining bits
    for(int i=0; i<message_len; i++){
        int ascii = message[i];
        for(int j=0; j<8; j++){
            int bit = get_bit(ascii, j);
            int row = (i*8+j+32)/(width*3);
            int col = (i*8+j+32)%(width*3)/3;
            int channel = (i*8+j+32)%(width*3)%3;
            image_data[row][col] = set_bit(image_data[row][col], channel, bit);
        }
    }
}

//function to extract data from the image using LSB substitution
char* extract_data(int** image_data, int height, int width){
    //extract message length from the first 32 bits
    int message_len = 0;
    for(int i=0; i<32; i++){
        int bit = get_bit(image_data[0][i/3], i%3);
        message_len = set_bit(message_len, i, bit);
    }

    char* message = (char*)malloc((message_len+1)*sizeof(char));

    //extract message data from the remaining bits
    for(int i=0; i<message_len; i++){
        int ascii = 0;
        for(int j=0; j<8; j++){
            int row = (i*8+j+32)/(width*3);
            int col = (i*8+j+32)%(width*3)/3;
            int channel = (i*8+j+32)%(width*3)%3;
            int bit = get_bit(image_data[row][col], channel);
            ascii = set_bit(ascii, j, bit);
        }
        message[i] = (char)ascii;
    }
    message[message_len] = '\0';

    return message;
}

int main(){
    char* filename = "image.bin";
    int height = 10;
    int width = 10;
    int** image_data = (int**)malloc(height*sizeof(int*));
    for(int i=0; i<height; i++){
        image_data[i] = (int*)malloc(width*sizeof(int));
    }

    //read image data from file
    read_image_data(filename, image_data, height, width);

    char* message = "Hello, world! This is a steganography example program.";

    //embed message in the image
    embed_data(image_data, height, width, message);

    //write modified image data to file
    write_image_data(filename, image_data, height, width);
    
    //extract message from the image
    char* extracted_message = extract_data(image_data, height, width);
    printf("Extracted message: %s\n", extracted_message);

    //free memory
    for(int i=0; i<height; i++){
        free(image_data[i]);
    }
    free(image_data);
    free(extracted_message);
    
    return 0;
}