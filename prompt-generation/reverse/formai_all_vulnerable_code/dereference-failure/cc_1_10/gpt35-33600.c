//FormAI DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

unsigned char readbyte(FILE *f);
void writebyte(FILE *f, unsigned char byte);
void encode(char *infile, char *datafile, char *outfile);
void decode(char *infile, char *outfile);

int main(int argc, char *argv[]) {
    
  if(argc < 3) {
    printf("Usage: %s <encode/decode> <infile> <datafile> <outfile (for encode only)>\n", argv[0]);
    return 1;
  }
  
  if(strcmp(argv[1], "encode") == 0) {
    if(argc != 5) {
      printf("Usage: %s encode <infile> <datafile> <outfile>\n", argv[0]);
      return 1;
    }
    encode(argv[2], argv[3], argv[4]);
    return 0;
  }
  
  if(strcmp(argv[1], "decode") == 0) {
    if(argc != 4) {
      printf("Usage: %s decode <infile> <outfile>\n", argv[0]);
      return 1;
    }
    decode(argv[2], argv[3]);
    return 0;
  }
  
  printf("Invalid command\n");
  return 1;
}

//Function to read a byte from a file
unsigned char readbyte(FILE *f) {
  int c;
  while((c = fgetc(f)) != EOF) {
    return (unsigned char)c;
  }
  return 0;
}

//Function to write a byte to a file
void writebyte(FILE *f, unsigned char byte) {
  fputc(byte, f);
}

//Function to encode a file with hidden data
void encode(char *infile, char *datafile, char *outfile) {
  
  FILE *inf, *df, *outf;
  int i, j;
  unsigned char inbyte, outbyte;
  int datafilesiz, bit;
  
  inf = fopen(infile, "rb");
  if(inf == NULL) {
    printf("Error opening input file %s\n", infile);
    exit(1);
  }
  
  df = fopen(datafile, "rb");
  if(df == NULL) {
    printf("Error opening data file %s\n", datafile);
    fclose(inf);
    exit(1);
  }
  
  outf = fopen(outfile, "wb");
  if(outf == NULL) {
    printf("Error creating output file %s\n", outfile);
    fclose(inf);
    fclose(df);
    exit(1);
  }
  
  fseek(df, 0, SEEK_END);
  datafilesiz = ftell(df);
  fseek(df, 0, SEEK_SET);
  
  for(i=0; i<datafilesiz; i++) {
  
    inbyte = readbyte(inf);
    
    for(j=0; j<8; j++) {
    
      bit = fgetc(df);
      if(bit == EOF) {
        fclose(inf);
        fclose(df);
        fclose(outf);
        remove(outfile);
        printf("Data file too short\n");
        exit(1);
      }
      
      outbyte = (inbyte & ~1) | (bit & 1);
      writebyte(outf, outbyte);
      
      inbyte >>= 1;
    }
  }
  
  while((inbyte = readbyte(inf)) != 0) {
    writebyte(outf, inbyte);
  }
  
  fclose(inf);
  fclose(df);
  fclose(outf);
}

//Function to decode a file with hidden data
void decode(char *infile, char *outfile) {
  
  FILE *inf, *outf;
  int i, j;
  unsigned char inbyte, outbyte;
  int bit;
  
  inf = fopen(infile, "rb");
  if(inf == NULL) {
    printf("Error opening input file %s\n", infile);
    exit(1);
  }
  
  outf = fopen(outfile, "wb");
  if(outf == NULL) {
    printf("Error creating output file %s\n", outfile);
    fclose(inf);
    exit(1);
  }
  
  for(i=0; ; i++) {
  
    inbyte = readbyte(inf);
    if(feof(inf)) {
      fclose(inf);
      fclose(outf);
      printf("Data not found in input file\n");
      exit(1);
    }
    
    bit = (inbyte & 1);
    
    for(j=0; j<7; j++) {
      bit <<= 1;
      inbyte = readbyte(inf);
      if(feof(inf)) {
        fclose(inf);
        fclose(outf);
        printf("Data not found in input file\n");
        exit(1);
      }
      bit |= (inbyte & 1);
    }
    
    if(bit == 0) {
      break;
    }
    
    outbyte = bit;
    writebyte(outf, outbyte);
  }
  
  fclose(inf);
  fclose(outf);
}