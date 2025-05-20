//FormAI DATASET v1.0 Category: File Encyptor ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to encrypt the file
void encrypt(char* file_name,char* key){
    //Open the file in read mode
    FILE* file=fopen(file_name,"rb");
    //Check if file opened successfully
    if(file==NULL){
        printf("Failed to open file!\n");
        exit(0);
    }
    //Calculate the size of file
    fseek(file,0,SEEK_END);
    int file_size=ftell(file);
    fseek(file,0,SEEK_SET);
    //Create buffer to hold data of file
    char* buffer=(char*)malloc(file_size*sizeof(char));
    //Read the data of file into the buffer
    fread(buffer,sizeof(char),file_size,file);
    //Open the file in write mode
    FILE* encrypted_file=fopen(strcat(file_name,".enc"),"wb");
    //Check if file opened successfully
    if(encrypted_file==NULL){
        printf("Failed to open file!\n");
        exit(0);
    }
    //Encrypt the file using the provided key
    for(int i=0;i<file_size;i++){
        buffer[i]=buffer[i]^key[i%strlen(key)];
    }
    //Write the encrypted data into the file
    fwrite(buffer,sizeof(char),file_size,encrypted_file);
    //Close the files and free the buffer
    fclose(file);
    fclose(encrypted_file);
    free(buffer);
}

int main(){
    //Get the file name from the user
    char* file_name=(char*)malloc(100*sizeof(char));
    printf("Enter the name of the file you want to encrypt: ");
    scanf("%s",file_name);
    //Get the key from the user
    char* key=(char*)malloc(100*sizeof(char));
    printf("Enter the encryption key: ");
    scanf("%s",key);
    //Encrypt the file
    encrypt(file_name,key);
    //Print success message
    printf("File has been encrypted successfully!\n");
    //Free the memory allocated
    free(file_name);
    free(key);
    return 0;
}