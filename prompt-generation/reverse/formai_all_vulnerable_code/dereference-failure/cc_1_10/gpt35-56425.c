//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define BITS_PER_BYTE 8
#define MAX_FILE_LENGTH 1000

int main(){

  FILE *image_fp, *watermark_fp, *image_out_fp;
  char image_filename[MAX_FILE_LENGTH], watermark_filename[MAX_FILE_LENGTH], output_filename[MAX_FILE_LENGTH];
  unsigned long int image_size, watermark_size, watermark_bit_length, bit_length, i;
  unsigned char image_byte, watermark_byte, output_byte;
  int image_bit, watermark_bit, output_bit, output_byte_count = 0;
  long int bits_to_hide;
  
  printf("\nEnter the name of the image file: ");
  scanf("%s", image_filename);

  printf("\nEnter the name of the watermark file: ");
  scanf("%s", watermark_filename);

  printf("\nEnter the name of the output file: ");
  scanf("%s", output_filename);
  
  image_fp = fopen(image_filename, "rb");
  if(image_fp == NULL){
    printf("\nUnable to open image file: %s\n", image_filename);
    exit(1);
  }

  watermark_fp = fopen(watermark_filename, "rb");
  if(watermark_fp == NULL){
    printf("\nUnable to open watermark file: %s\n", watermark_filename);
    exit(1);
  }
  
  image_out_fp = fopen(output_filename, "wb");
  if(image_out_fp == NULL){
    printf("\nUnable to open output file: %s\n", output_filename);
    exit(1);
  }

  //Get the size of the image and the watermark
  fseek(image_fp, 0L, SEEK_END);
  image_size = ftell(image_fp);
  fseek(image_fp, 0L, SEEK_SET);

  fseek(watermark_fp, 0L, SEEK_END);
  watermark_size = ftell(watermark_fp);
  fseek(watermark_fp, 0L, SEEK_SET);

  //Calculate the number of bits that can be hidden in the image
  bits_to_hide = (image_size / BITS_PER_BYTE) - 8;

  //Check if the watermark is too long to fit into the image
  if(watermark_size > bits_to_hide){
    printf("\nThe watermark is too big to fit into the image");
    exit(1);
  }

  //Calculate the bit length of the watermark
  watermark_bit_length = watermark_size * BITS_PER_BYTE;

  //Calculate the total bit length of the message
  bit_length = watermark_bit_length + BITS_PER_BYTE;

  printf("\nEncrypting data...\n");

  //Write the size of the watermark to the first 8 bits of the image
  fwrite(&watermark_size, sizeof(unsigned long int), 1, image_out_fp);
  
  //Hide the watermark in the image
  for(i = 0; i < watermark_bit_length; i++){
    //Read a byte from the image
    fread(&image_byte, sizeof(unsigned char), 1, image_fp);

    //Get the next bit to hide
    watermark_bit = fgetc(watermark_fp);

    //Get the next bit from the image byte
    image_bit = (image_byte >> 7) & 0x01;
    
    //Calculate the new bit value for the output byte
    output_bit = (image_bit | (watermark_bit << 1));

    //Set the new output byte bit
    output_byte = (output_byte << 1) | output_bit;
    
    //If we have filled a complete byte, write it to the output file
    if(i % 8 == 7){
      fwrite(&output_byte, sizeof(unsigned char), 1, image_out_fp);
      output_byte = 0x00;
      output_byte_count++;
    }
    
    //Print progress message
    if(i % 1000 == 0){
      printf("\r%d bits encrypted", i+1);
      fflush(stdout);
    }
  }

  //Write the remaining bits
  if(i % 8 != 0){
    while(i % 8 != 0){
      output_byte = (output_byte << 1);
      i++;
    }
    fwrite(&output_byte, sizeof(unsigned char), 1, image_out_fp);
  }
  
  fclose(image_fp);
  fclose(watermark_fp);
  fclose(image_out_fp);
  
  printf("\nEncryption complete. %d bytes written to %s\n", output_byte_count, output_filename);

  return 0;
}