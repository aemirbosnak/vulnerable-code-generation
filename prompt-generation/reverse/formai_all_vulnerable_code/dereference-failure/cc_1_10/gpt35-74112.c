//FormAI DATASET v1.0 Category: Image Steganography ; Style: active
#include<stdio.h>
#include<ctype.h>

// A function to convert decimal to binary
void decimalToBinary(int num)
{
    int binary[8];
    int i=0;
    while(num!=0)
    {
        binary[i] = num%2;
        num = num/2;
        i++;
    }
    //Printing the binary array in reverse order
    for(int j=i-1; j>=0; j--)
    {
        printf("%d", binary[j]);
    }
}

// A function to convert binary to decimal
int binaryToDecimal(int binary[])
{
    int decimal=0;
    int base=1;
    for(int i=7; i>=0; i--)
    {
        decimal += binary[i]*base;
        base *= 2;
    }
    return decimal;
}

// A function for image steganography
void imageSteganography()
{
    FILE *coverImage, *secretImage, *stegoImage;
    coverImage = fopen("cover_image.bmp", "rb");
    secretImage = fopen("secret_image.bmp", "rb");
    stegoImage = fopen("stego_image.bmp", "wb");
    
    if(coverImage == NULL || secretImage == NULL || stegoImage == NULL)
    {
        printf("Error in opening file!\n");
        return;
    }
    
    //Copying header information from cover image to stego image
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, coverImage);
    fwrite(header, sizeof(unsigned char), 54, stegoImage);
    
    //Extracting the pixel values of cover image
    unsigned char pixelCover[512][512][3];
    for(int i=0; i<512; i++)
    {
        for(int j=0; j<512; j++)
        {
            fread(pixelCover[i][j], sizeof(unsigned char), 3, coverImage);
        }
    }
    
    //Extracting the pixel values of secret image
    unsigned char pixelSecret[512][512][3];
    for(int i=0; i<512; i++)
    {
        for(int j=0; j<512; j++)
        {
            fread(pixelSecret[i][j], sizeof(unsigned char), 3, secretImage);
        }
    }
    
    //Copying the cover image pixels to stego image and embedding the secret image pixels
    int k=0, l=0;
    for(int i=0; i<512; i++)
    {
        for(int j=0; j<512; j++)
        {
            //Extracting the binary representation of red, green and blue values of cover image pixel
            int binRedCover[8], binGreenCover[8], binBlueCover[8];
            decimalToBinary(pixelCover[i][j][2]);
            printf(" ");
            decimalToBinary(pixelCover[i][j][1]);
            printf(" ");
            decimalToBinary(pixelCover[i][j][0]);
            printf("\n");

            //Replacing the least significant bit of red, green and blue values of cover image pixel with the binary representation of secret image pixel
            int binRedSecret[8], binGreenSecret[8], binBlueSecret[8];
            decimalToBinary(pixelSecret[k][l][2]);
            binRedCover[7] = binRedSecret[7];
            decimalToBinary(pixelSecret[k][l][1]);
            binGreenCover[7] = binGreenSecret[7];
            decimalToBinary(pixelSecret[k][l][0]);
            binBlueCover[7] = binBlueSecret[7];

            pixelCover[i][j][2] = binaryToDecimal(binRedCover);
            pixelCover[i][j][1] = binaryToDecimal(binGreenCover);
            pixelCover[i][j][0] = binaryToDecimal(binBlueCover);

            //Copying the cover image pixel with secret image pixel embedded to stego image
            fwrite(pixelCover[i][j], sizeof(unsigned char), 3, stegoImage);
            l++;
            if(l == 512)
            {
                l=0;
                k++;
            }
        }
    }

    printf("Image steganography successful!\n");

    //Closing the files
    fclose(coverImage);
    fclose(secretImage);
    fclose(stegoImage);
}

int main()
{
    imageSteganography();
    return 0;
}