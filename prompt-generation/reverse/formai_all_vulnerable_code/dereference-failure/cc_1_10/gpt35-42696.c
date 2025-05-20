//FormAI DATASET v1.0 Category: Data recovery tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// function signature
void recover_file(char* filename, int num_blocks);

int main(int argc, char* argv[]) {
  if (argc < 3) {
    printf("Usage: %s <filename> <num_blocks>\n", argv[0]);
    return 1;
  }
  
  // get filename and number of blocks from command line args
  char* filename = argv[1];
  int num_blocks = atoi(argv[2]);

  recover_file(filename, num_blocks);
  
  return 0;
}

// recover_file function definition
void recover_file(char* filename, int num_blocks) {
  FILE* fp = fopen(filename, "rb");
  if (!fp) {
    printf("Error: could not open file %s\n", filename);
    return;
  }

  // find file size by moving to end of file and getting position
  fseek(fp, 0L, SEEK_END);
  int file_size = ftell(fp);
  rewind(fp);

  int block_size = file_size / num_blocks;
  int leftover_size = file_size % num_blocks;

  // dynamically allocate memory for data array
  unsigned char* data = (unsigned char*) malloc(sizeof(unsigned char) * block_size);
  if (!data) {
    printf("Error: could not allocate memory\n");
    return;
  }

  // read each block of data from file
  for (int i = 0; i < num_blocks; i++) {
    if (fread(data, sizeof(unsigned char), block_size, fp) != block_size) {
      printf("Error: could not read data\n");
      free(data);
      fclose(fp);
      return;
    }

    // do something with the data (e.g. recover lost files)
    printf("Recovered data block %d\n", i+1);
  }

  // read any leftover data from file
  if (leftover_size > 0) {
    unsigned char* leftover_data = (unsigned char*) malloc(sizeof(unsigned char) * leftover_size);
    if (!leftover_data) {
      printf("Error: could not allocate memory\n");
      free(data);
      fclose(fp);
      return;
    }

    if (fread(leftover_data, sizeof(unsigned char), leftover_size, fp) != leftover_size) {
      printf("Error: could not read data\n");
      free(data);
      free(leftover_data);
      fclose(fp);
      return;
    }

    // do something with the leftover data (e.g. recover lost files)
    printf("Recovered leftover data\n");
    free(leftover_data);
  }

  free(data);
  fclose(fp);
}