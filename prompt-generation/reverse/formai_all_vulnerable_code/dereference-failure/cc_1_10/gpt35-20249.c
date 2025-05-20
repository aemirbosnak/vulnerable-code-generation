//FormAI DATASET v1.0 Category: Data recovery tool ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINE_LEN 256

int main(int argc, char* argv[]){
    char filepath[1024], del[]=".del";
    FILE *fp,*fpTemp;
    char *buffer;
    long size;
    int i;

    printf("Enter file path to recover: ");
    fgets(filepath, sizeof(filepath), stdin);
    // remove newline character at the end
    filepath[strcspn(filepath,"\n")]=0;
    // check if the file exists and the file name ends with ".del"
    if((fp=fopen(filepath,"rb"))==NULL||strcmp(strrchr(filepath,'.'),del)!=0){
        printf("The specified file cannot be recovered.\n");
        return 1;
    }
    // get the size of the file
    fseek(fp, 0, SEEK_END);
    size=ftell(fp);
    rewind(fp);

    // allocate memory for the buffer to hold the contents of the file
    buffer=(char*) malloc(size);
    if(buffer==NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }

    // read the contents of the file into the buffer
    fread(buffer,1,size,fp);

    // close the file
    fclose(fp);

    // open a new file with the same name as the original file, without the ".del" extension
    fpTemp=fopen(strtok(filepath,"."),"wb");
    if(fpTemp==NULL){
        printf("Failed to create file.\n");
        free(buffer);
        return 1;
    }

    // write the contents of the buffer to the new file
    fwrite(buffer,1,size,fpTemp);

    // close the new file
    fclose(fpTemp);

    printf("File recovered successfully!\n");

    // free the memory allocated for the buffer
    free(buffer);

    return 0;
}