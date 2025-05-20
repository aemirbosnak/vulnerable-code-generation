//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void encode(char source[], char watermark[]) {
    FILE *original_file, *watermark_file, *encoded_file;
    int byte_count = 0;
    char ch, wm;
    
    // open the files
    original_file = fopen(source, "r");
    watermark_file = fopen(watermark, "r");
    encoded_file = fopen("encoded_file.txt", "w");
    
    // check if files were opened successfully
    if (original_file == NULL || watermark_file == NULL || encoded_file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    
    // loop through original file and write to encoded file, with watermark added to each byte
    while ((ch = fgetc(original_file)) != EOF) {
        // get watermark byte
        wm = fgetc(watermark_file);
        if (wm == EOF) // if the watermark file is smaller than the original file
            rewind(watermark_file);
            
        // encode the byte
        ch = ch ^ wm;
        
        // write to encoded file
        fputc(ch, encoded_file);
        
        // increment the byte count
        byte_count++;
    }
    
    // print encoding results
    printf("Encoding complete. %d bytes encoded.\n", byte_count);
    
    // close files
    fclose(original_file);
    fclose(watermark_file);
    fclose(encoded_file);
}

void decode(char encoded_file_name[], char watermark_file_name[]) {
    FILE *encoded_file, *watermark_file, *decoded_file;
    int byte_count = 0;
    char ch, wm;
    
    // open the files
    encoded_file = fopen(encoded_file_name, "r");
    watermark_file = fopen(watermark_file_name, "w");
    decoded_file = fopen("decoded_file.txt", "w");
    
    // check if files were opened successfully
    if (encoded_file == NULL || watermark_file == NULL || decoded_file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    
    // loop through encoded file and write to decoded file, with watermark removed from each byte
    while ((ch = fgetc(encoded_file)) != EOF) {
        // get watermark byte
        wm = fgetc(watermark_file);
        if (wm == EOF) // if the watermark file is smaller than the encoded file
            rewind(watermark_file);
            
        // decode the byte
        ch = ch ^ wm;
        
        // write to decoded file
        fputc(ch, decoded_file);
        
        // write the watermark byte to the watermark file
        fputc(wm, watermark_file);
        
        // increment byte count
        byte_count++;
    }
    
    // print decoding results
    printf("Decoding complete. %d bytes decoded.\n", byte_count);
    
    // close files
    fclose(encoded_file);
    fclose(watermark_file);
    fclose(decoded_file);
}

int main() {
    char choice;
    char source[MAX_SIZE], watermark[MAX_SIZE], encoded_file_name[MAX_SIZE], watermark_file_name[MAX_SIZE];
    
    // get user input
    printf("Enter the name of the original file: ");
    fgets(source, MAX_SIZE, stdin);
    printf("Enter the name of the file containing the watermark: ");
    fgets(watermark, MAX_SIZE, stdin);
    printf("Enter the name of the encoded file: ");
    fgets(encoded_file_name, MAX_SIZE, stdin);
    printf("Enter the name of the file to store the watermark: ");
    fgets(watermark_file_name, MAX_SIZE, stdin);
    
    // remove newline characters from user input
    source[strcspn(source, "\n")] = 0;
    watermark[strcspn(watermark, "\n")] = 0;
    encoded_file_name[strcspn(encoded_file_name, "\n")] = 0;
    watermark_file_name[strcspn(watermark_file_name, "\n")] = 0;
    
    // encode or decode
    printf("Enter E to encode or D to decode: ");
    scanf("%c", &choice);
    if (choice == 'E') {
        encode(source, watermark);
    } else if (choice == 'D') {
        decode(encoded_file_name, watermark_file_name);
    } else {
        printf("Invalid choice.\n");
        exit(1);
    }
    
    return 0;
}