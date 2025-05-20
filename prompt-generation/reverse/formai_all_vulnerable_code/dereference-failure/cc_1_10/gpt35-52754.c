//FormAI DATASET v1.0 Category: Data recovery tool ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#define BLOCK_SIZE 512

// function to get the size of the file
long int get_file_size(FILE* file) {
   fseek(file, 0L, SEEK_END);
   long int file_size = ftell(file);
   rewind(file);
   return file_size; 
}

// function to recover data from the image file
void recover_data(char* file_name) {
   FILE* image_file = fopen(file_name, "r");
   if(image_file == NULL) {
      printf("Error: Failed to open image file.\n");
      exit(1);
   }
   
   long int file_size = get_file_size(image_file);
   long int no_of_blocks = file_size / BLOCK_SIZE;   
   
   // create a buffer
   char* buffer = (char*) malloc(sizeof(char) * BLOCK_SIZE);
   if(buffer == NULL) {
      printf("Error: Failed to allocate memory.\n");
      exit(1);
   }

   // create a folder to store recovered files
   system("mkdir recovered_files");
   
   for(long int i=0; i<no_of_blocks; i++) {
      // read block from image file
      fread(buffer, BLOCK_SIZE, 1, image_file);
      
      // check for the start of JPEG signature
      if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
         // create a file to store the recovered JPEG data
         char* file_path = (char*) malloc(sizeof(char) * 100);
         snprintf(file_path, 100, "recovered_files/recovered_%d.jpg", i);
         FILE* recovered_file = fopen(file_path, "w");
         if(recovered_file == NULL) {
            printf("Error: Failed to create recovered file.\n");
            exit(1);
         }
         
         // write JPEG signature
         fwrite(buffer, BLOCK_SIZE, 1, recovered_file);
         
         // read blocks until the end of JPEG signature
         int j = i+1;
         while(j<no_of_blocks) {
            fread(buffer, BLOCK_SIZE, 1, image_file);
            fwrite(buffer, BLOCK_SIZE, 1, recovered_file);
            if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
               break;
            }
            j++;
         }
         
         // close recovered file
         fclose(recovered_file);
         i = j-1;
      }  
   }
   
   // close image file and free the memory
   fclose(image_file);
   free(buffer);
}

int main(int argc, char* argv[]) {
   if(argc != 2) {
      printf("Usage: %s <image_file_path>\n", argv[0]);
      return 1;
   }
   
   char* file_name = argv[1];
   recover_data(file_name);
   
   printf("Data recovery from %s is successful. Check the 'recovered_files' folder.\n", file_name);
   
   return 0;
}