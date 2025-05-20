//FormAI DATASET v1.0 Category: Image Steganography ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void hideMessage(int message[],int size,int image[],int width,int height,int depth)
{
    //Calculate the maximum message size that can be hidden in the given image
    int max_message_size=(height*width*depth)/8;
    if(size>max_message_size)
    {
        printf("Error: Message size is too large to be hidden in the given image! Reduce message size and try again.\n");
        return;
    }
    else
    {
        //Calculate the number of bits required to store the message length
        int bits_for_message_length=ceil(log2(size));

        //Create an array to store the message length
        int message_length[bits_for_message_length];

        //Convert the message length into binary and store it in the message_length array
        for(int i=0;i<bits_for_message_length;i++)
        {
            message_length[i]=(size>>i)&1;

            //Hide the message length in the image by modifying the least significant bit of the first few pixels
            image[i]= (image[i] & ~1) | message_length[i];
        }

        //Hide the message in the remaining pixels
        for(int i=bits_for_message_length;i<size+bits_for_message_length;i++)
        {
            int index=i-bits_for_message_length;
            int bit_to_hide=message[index];

            //Calculate the pixel and bit to modify
            int pixel_index=i*8/depth;
            int bit_index=(i*8)%depth;

            //Modify the bit in the pixel to hide the message
            image[pixel_index]= (image[pixel_index] & ~(1<<bit_index)) | (bit_to_hide<<bit_index);
        }
    }

    //Save the steganographed image
    FILE* f;
    f=fopen("steganographed_image.ppm","w");
    fprintf(f,"P6\n%d %d\n255\n",width,height);
    fwrite(image,1,width*height*depth,f);
    fclose(f);

    printf("Message successfully hidden in the image!\n");
}

void extractMessage(int image[],int width,int height,int depth)
{
    //Count the number of bits required to store the message length
    int bits_for_message_length=0;
    for(int i=0;i<32;i++)
    {
        if((1<<i)> width*height*depth/8)
        break;

        bits_for_message_length++;
    }

    //Extract the message length from the image
    int message_length=0;
    for(int i=0;i<bits_for_message_length;i++)
    {
        int bit_to_extract=(image[i]&1);
        message_length |=(bit_to_extract<<i);
    }

    //Extract the message from the image
    int message[message_length];
    for(int i=bits_for_message_length;i<message_length+bits_for_message_length;i++)
    {
        int index=i-bits_for_message_length;
        int pixel_index=i*8/depth;
        int bit_index=(i*8)%depth;
        int bit_to_extract= (image[pixel_index]>>bit_index)&1;
        message[index]=bit_to_extract;
    }

    printf("Extracted message:\n");
    for(int i=0;i<message_length;i++)
    printf("%d",message[i]);

    printf("\n");
}

int main()
{
    //Read the cover image
    FILE* f;
    f=fopen("cover_image.ppm","r");
    char buffer[100];
    fgets(buffer,100,f);
    int width;
    int height;
    fscanf(f,"%d %d\n",&width,&height);
    fgets(buffer,100,f);
    int depth=3;
    int image[width*height*depth];
    fread(image,1,width*height*depth,f);
    fclose(f);

    //Hide the secret message in the image
    int message[]={0,1,1,0,0,1,0,1,0,1,0,1,1,0,0,1,1,1,0,1,1,0,0,1,0,1,0,1,0,1,1,0,0,1,1,1,0,1,1,0,0,1,0,1,0,1,0,1,1,0,0,1,1,1,0,1,1,0,0,1,0,1,0,1,0,1,1,0,0,1,1,1,0,1,1};
    int message_size=sizeof(message)/sizeof(message[0]);
    hideMessage(message,message_size,image,width,height,depth);

    //Extract the secret message from the steganographed image
    f=fopen("steganographed_image.ppm","r");
    fgets(buffer,100,f);
    fscanf(f,"%d %d\n",&width,&height);
    fgets(buffer,100,f);
    fread(image,1,width*height*depth,f);
    fclose(f);
    extractMessage(image,width,height,depth);

    return 0;
}