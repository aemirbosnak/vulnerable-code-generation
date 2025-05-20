//FormAI DATASET v1.0 Category: File handling ; Style: brave
#include<stdio.h>
#include<stdlib.h>

// Function to copy the contents of one file to another
void copyFile(FILE *fRead, FILE *fWrite){
    char ch;
    while((ch = fgetc(fRead)) != EOF){
        fputc(ch, fWrite);
    }
}

int main(){
    FILE *file1, *file2, *temp;

    // Opening file1 in read mode
    file1 = fopen("file1.txt", "r");
    if(file1 == NULL){
        perror("Error opening file1");
        exit(1);
    }

    // Opening file2 in write mode
    file2 = fopen("file2.txt", "w");
    if(file2 == NULL){
        perror("Error opening file2");
        exit(1);
    }

    // Opening temp file in write mode
    temp = fopen("temp.txt", "w");
    if(temp == NULL){
        perror("Error opening temp file");
        exit(1);
    }

    // Copying contents of file1 to file2 and temp
    copyFile(file1, file2);
    rewind(file1);
    copyFile(file1, temp);

    // Closing opened files
    fclose(file1);
    fclose(file2);
    fclose(temp);

    // Deleting file2
    remove("file2.txt");

    // Renaming temp file to file2
    rename("temp.txt", "file2.txt");
    
    printf("Content of file1 has been copied to file2 using temp file. \n");

    return 0;
}