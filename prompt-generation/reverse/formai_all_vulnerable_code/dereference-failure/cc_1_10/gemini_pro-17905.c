//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_FILE_SIZE 1024 * 1024 * 1024

// Structure to store virus signature
typedef struct {
    uint32_t offset;
    char *signature;
} VirusSignature;

// Array of virus signatures
static const VirusSignature virus_signatures[] = {
    {0, "EICAR-STANDARD-ANTIVIRUS-TEST-FILE"},
    {16, "MZ"},
    {32, "PE"},
    {60, "ELF"},
    {72, "Mach-O"},
    {0, NULL} // End of array marker
};

// Function to scan a file for viruses
int scan_file(FILE *fp) {
    // Get file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Read file into memory
    char *file_data = malloc(file_size);
    fread(file_data, 1, file_size, fp);
    
    
    // Iterate over virus signatures and check for matches
    for (int i = 0; virus_signatures[i].signature != NULL; i++) {
   
      size_t sig_len = strlen(virus_signatures[i].signature); 
      for (long int  j = virus_signatures[i].offset; j < file_size - sig_len; j++) {
         if (memcmp(&file_data[j], virus_signatures[i].signature, sig_len) == 0) {
            printf("Virus detected: %s\n", virus_signatures[i].signature);
            return 1;
         }
      }
   }

    // No viruses detected
    printf("No viruses detected.\n");
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // Open file
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    // Scan file for viruses
    int result = scan_file(fp);

    // Close file
    fclose(fp);

    return result;
}