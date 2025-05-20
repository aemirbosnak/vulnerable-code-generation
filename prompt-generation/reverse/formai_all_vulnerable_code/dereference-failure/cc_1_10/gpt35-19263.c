//FormAI DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>

int main()
{
    FILE *infile, *outfile;
    char ch, key;
    
    // Get the input file name from the user
    char infile_name[50];
    printf("Enter the name of the input file: ");
    scanf("%s", infile_name);
    
    // Open the input file
    infile = fopen(infile_name, "rb");
    if(infile == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Get the output file name from the user
    char outfile_name[50];
    printf("Enter the name of the output file: ");
    scanf("%s", outfile_name);
    
    // Open the output file
    outfile = fopen(outfile_name, "wb");
    if(outfile == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Get the encryption key from the user
    printf("Enter the encryption key: ");
    scanf(" %c", &key);
    
    // Encrypt the contents of the input file
    while((ch = fgetc(infile)) != EOF)
    {
        ch = ch ^ key; // XOR operation to encrypt
        fputc(ch, outfile);
    }
    
    // Close the input and output files
    fclose(infile);
    fclose(outfile);
    
    printf("Encryption successful!\n");
    return 0;
}