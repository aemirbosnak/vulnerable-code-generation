//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>

#define WaterMark "Hello World" //the message to be watermarked
#define ImageFile "input.bmp"   //the image file to be watermarked
#define WaterMarkedFile "output.bmp" //the watermarked output image file

void embed_watermark(unsigned char *image_data, int image_width, int image_height){

  //Embed Watermark using LSB technique

  int watermark_size = strlen(WaterMark);
  int watermark_index = 0;

  for(int i = 0; i < image_height; i++){
    for(int j = 0; j < image_width; j++){
        
        for(int k = 0; k < 3; k++){ //iterate over each channel R,G,B

            if(watermark_index >= watermark_size){ //if entire watermark is already embedded, return
                return;
            }

            unsigned char pixel_value = *(image_data + (i*image_width + j)*3 + k);  //get pixel color
            unsigned char lsb = WaterMark[watermark_index] >> (8 - sizeof(pixel_value)); //get lsb of the bit

            pixel_value = (pixel_value & 0xFE) | lsb; //mask the shift
            *(image_data + (i*image_width + j)*3 + k) = pixel_value; //update output data
            
            watermark_index++; //increment index
        }
    }
  }
}

int main(){

  //Read Image data

  FILE* file;
  file = fopen(ImageFile, "rb");

  if(!file){
    printf("Error Reading File\n");
    return -1;
  }

  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, file);

  unsigned int offset = *(unsigned int*)&header[10];
  unsigned int image_width = *(unsigned int*)&header[18];
  unsigned int image_height = *(unsigned int*)&header[22];

  unsigned int size = image_width*image_height*3;
  unsigned char* image_data = (unsigned char*)malloc(size);

  fseek(file, offset, SEEK_SET); 
  fread(image_data, sizeof(unsigned char), size, file);

  fclose(file);

  //Embed Watermark
  embed_watermark(image_data, image_width, image_height);


  //Write output data
  FILE* output_file;
  output_file = fopen(WaterMarkedFile, "wb");

  fwrite(header, sizeof(unsigned char), offset, output_file);
  fwrite(image_data, sizeof(unsigned char), size, output_file);

  fclose(output_file);

  free(image_data);

  return 0;
}