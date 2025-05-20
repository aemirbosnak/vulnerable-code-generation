//FormAI DATASET v1.0 Category: File system simulation ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE 1024
#define DISKSIZE 1024

int fd[20], disk[DISKSIZE];

//Function to create file
void createFile(char* fileName, int size){
    FILE* fp = fopen(fileName, "w");
    if(fp == NULL){
        printf("Error: Couldn't create file\n");
        return;
    }
    for(int i = 0; i < size; i++){
        char ch = 'a' + i%26;
        fprintf(fp, "%c", ch);
    }
    fclose(fp);
}

//Function to read file
void readFile(char* fileName){
    FILE* fp = fopen(fileName, "r");
    if(fp == NULL){
        printf("Error: Couldn't open file\n");
        return;
    }
    char ch;
    while((ch = fgetc(fp)) != EOF){
        printf("%c", ch);
    }
    printf("\n");
    fclose(fp);
}

//Function to write block
void writeBlock(int blockNum, char* buffer){
    int start = blockNum * BLOCKSIZE;
    int end = (blockNum+1) * BLOCKSIZE;
    for(int i = start, j = 0; i < end; i++, j++){
        disk[i] = buffer[j];
    }
}

//Function to read block
void readBlock(int blockNum, char* buffer){
    int start = blockNum * BLOCKSIZE;
    int end = (blockNum+1) * BLOCKSIZE;
    for(int i = start, j = 0; i < end; i++, j++){
        buffer[j] = disk[i];
    }
}

//Function to open file
int openFile(char* fileName){
    for(int i = 0; i < 20; i++){
        if(fd[i] == -1){
            fd[i] = i;
            return i;
        }
    }
    return -1;
}

//Function to write to file
void writeFile(int fd, char* data){
    if(fd == -1){
        printf("Error: File not found\n");
        return;
    }
    int blockNum = fd;
    writeBlock(blockNum, data);
}

//Function to read file
void readFileFD(int fd, char* buffer){
    if(fd == -1){
        printf("Error: File not found\n");
        return;
    }
    int blockNum = fd;
    readBlock(blockNum, buffer);
}

int main(){
    //Initialise file descriptor array
    for(int i = 0; i < 20; i++){
        fd[i] = -1;
    }

    //Create and read files
    createFile("file1.txt", DISKSIZE);
    createFile("file2.txt", BLOCKSIZE);
    readFile("file1.txt");
    readFile("file2.txt");

    //Open files and write data
    int fd1 = openFile("file1.txt");
    int fd2 = openFile("file2.txt");
    char data1[] = "Hello World";
    char data2[] = "Block File";
    writeFile(fd1, data1);
    writeFile(fd2, data2);

    //Read data from file descriptors
    char buffer1[BLOCKSIZE];
    char buffer2[BLOCKSIZE];
    readFileFD(fd1, buffer1);
    readFileFD(fd2, buffer2);
    printf("Data read from fd1: %s\n", buffer1);
    printf("Data read from fd2: %s\n", buffer2);

    return 0;
}