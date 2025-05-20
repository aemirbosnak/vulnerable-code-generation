//FormAI DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024  //Buffer size for file chunks
#define KEY 77           //Encryption and Decryption key

//Function to encrypt data
void encrypt(char *buffer,int size){
    for(int i=0;i<size;i++){
        *buffer ^= KEY;
        buffer++;
    }
}

int main(){
    char filename[100];
    FILE *fp,*fe;
    int size;

    printf("Enter filename to encrypt: ");
    scanf("%s",filename);

    fp = fopen(filename,"rb");  //Open file in binary mode

    if(fp == NULL){
        printf("File not found or unable to open.\n");
        exit(0);
    }

    //Get the file size
    fseek(fp,0,SEEK_END);
    size = ftell(fp);
    fseek(fp,0,SEEK_SET);

    //Allocate memory for the buffer
    char *buffer = (char*) malloc(size);

    //Read file into buffer 
    fread(buffer,size,1,fp); 

    //Close file
    fclose(fp);

    //Encrypt data
    encrypt(buffer,size);

    //Write the encrypted data to a new file
    char new_filename[100];
    strcpy(new_filename,filename);
    strcat(new_filename,".enc");

    fe = fopen(new_filename,"wb");

    if(fe == NULL){
        printf("Unable to create encrypted file.\n");
        exit(0);
    }

    fwrite(buffer,size,1,fe);

    //Close the encrypted file
    fclose(fe);

    printf("File encrypted successfully.\n");

    //Free the buffer
    free(buffer);

    return 0;
}