//FormAI DATASET v1.0 Category: Image Steganography ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

void encode(char *input_image_name, char *secret_message, char *output_image_name)
{
  FILE *input_image_file, *output_image_file;
  char *buffer;
  int input_image_size, secret_message_length, i, j, k;
  
  // Opening input file in read-binary mode.
  input_image_file = fopen(input_image_name, "rb");
  if(input_image_file == NULL)
  {
    printf("Error: Unable to open image file '%s'!\n", input_image_name);
    exit(1);
  }
  
  // Opening output file in write-binary mode.
  output_image_file = fopen(output_image_name, "wb");
  if(output_image_file == NULL)
  {
    printf("Error: Unable to create output image file '%s'!\n", output_image_name);
    exit(1);
  }
  
  // Determining input file size.
  fseek(input_image_file, 0, SEEK_END);
  input_image_size = ftell(input_image_file);
  fseek(input_image_file, 0, SEEK_SET);
  
  // Reading input file into buffer.
  buffer = (char*)malloc(input_image_size);
  fread(buffer, input_image_size, 1, input_image_file);
  
  // Determining secret message length.
  secret_message_length = strlen(secret_message);
  
  // Encoding secret message into input file.
  for(i = 54, j = 0, k = 7; i < input_image_size && j < secret_message_length; i++, k--)
  {
    if(buffer[i] % 2 == 0 && secret_message[j] - '0' == 1)
      buffer[i]++;
    else if(buffer[i] % 2 == 1 && secret_message[j] - '0' == 0)
      buffer[i]--;
  
    if(k == 0)
    {
      k = 7;
      j++;
    }
  }
  
  // Writing buffer into output file.
  fwrite(buffer, input_image_size, 1, output_image_file);
  
  // Closing files and freeing buffer.
  fclose(input_image_file);
  fclose(output_image_file);
  free(buffer);
}

char* decode(char *output_image_name)
{
  FILE *output_image_file;
  char *buffer, *secret_message;
  int output_image_size, i, j, k, secret_message_length;
  
  // Opening output file in read-binary mode.
  output_image_file = fopen(output_image_name, "rb");
  if(output_image_file == NULL)
  {
    printf("Error: Unable to open output image file '%s'!\n", output_image_name);
    exit(1);
  }
  
  // Determining output file size.
  fseek(output_image_file, 0, SEEK_END);
  output_image_size = ftell(output_image_file);
  fseek(output_image_file, 0, SEEK_SET);
  
  // Reading output file into buffer.
  buffer = (char*)malloc(output_image_size);
  fread(buffer, output_image_size, 1, output_image_file);
  
  // Decoding secret message from output file.
  secret_message = (char*)malloc((output_image_size - 54) / 8 + 1);
  for(i = 54, j = 0, k = 7; i < output_image_size; i++, k--)
  {
    if(k == 0)
    {
      k = 7;
      secret_message[j] = '\0';
      j++;
    }
    
    if(buffer[i] % 2 == 0)
      secret_message[j] = secret_message[j] * 2;
    else
      secret_message[j] = secret_message[j] * 2 + 1;
  }
  secret_message[j] = '\0';
  
  // Determining secret message length.
  secret_message_length = strlen(secret_message);
  
  // Printing secret message.
  printf("Secret Message (%d bits):\n%s\n", secret_message_length, secret_message);
  
  // Closing file and freeing buffer and secret message.
  fclose(output_image_file);
  free(buffer);
  free(secret_message);
  
  return secret_message;
}

int main()
{
  char *input_image_name = "input.bmp"; // Input image file name.
  char *output_image_name = "output.bmp"; // Output image file name.
  char *secret_message = "10101010"; // Secret message to encode.
  
  // Encoding secret message into input file.
  encode(input_image_name, secret_message, output_image_name);
  
  // Decoding secret message from output file.
  decode(output_image_name);
  
  return 0;
}