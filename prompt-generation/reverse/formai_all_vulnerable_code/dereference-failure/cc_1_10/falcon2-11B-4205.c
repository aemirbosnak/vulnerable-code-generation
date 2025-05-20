//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: random
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    FILE *fp;
    char *secret;
    char *hidden;
    char *tohide;
    int size,len;
    int i;

    fp = fopen("stego.bmp","rb");
    fseek(fp,0,SEEK_END);
    size = ftell(fp);
    fseek(fp,0,SEEK_SET);
    secret = (char*) malloc(size+1);
    fread(secret,1,size,fp);
    fclose(fp);

    tohide = (char*) malloc(size+1);
    hidden = (char*) malloc(size+1);

    for(i=0;i<size;i++)
    {
        if(secret[i]=='0')
        {
            tohide[i]='1';
            hidden[i]='0';
        }
        else
        {
            tohide[i]='0';
            hidden[i]='1';
        }
    }
    tohide[size]='\0';
    hidden[size]='\0';

    fp = fopen("stego.bmp","rb+");
    fseek(fp,0,SEEK_SET);
    fwrite(hidden,1,size,fp);
    fclose(fp);

    fp = fopen("stego.bmp","rb");
    fseek(fp,0,SEEK_SET);
    fread(secret,1,size,fp);
    fclose(fp);

    printf("Hidden Message: %s\n",secret);
    printf("Original Message: %s\n",tohide);
}