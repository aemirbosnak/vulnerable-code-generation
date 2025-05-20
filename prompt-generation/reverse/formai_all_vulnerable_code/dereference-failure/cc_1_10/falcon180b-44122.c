//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Function to print ASCII art
void print_art(char* art)
{
    int i = 0;
    while(art[i]!= '\0')
    {
        printf("%c",art[i]);
        i++;
    }
    printf("\n");
}

//Function to convert image to ASCII art
char* image_to_art(char* img_path)
{
    FILE* fp = fopen(img_path,"rb");
    if(fp == NULL)
    {
        printf("Error opening image file\n");
        return NULL;
    }
    
    int width,height;
    int c;
    char* art = (char*)malloc(100000*sizeof(char));
    art[0] = '\0';
    
    fseek(fp,18,SEEK_SET);
    fread(&width,sizeof(int),1,fp);
    fread(&height,sizeof(int),1,fp);
    
    int row,col;
    for(row=0;row<height;row++)
    {
        for(col=0;col<width;col++)
        {
            fseek(fp,54+row*width*3+col*3,SEEK_SET);
            fread(&c,sizeof(char),1,fp);
            art[row*width+col] = c;
        }
    }
    
    fclose(fp);
    return art;
}

int main()
{
    char* art = image_to_art("image.bmp");
    if(art == NULL)
        return 0;
    
    printf("ASCII art:\n");
    print_art(art);
    
    return 0;
}