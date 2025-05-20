//FormAI DATASET v1.0 Category: File Synchronizer ; Style: standalone
#include<stdio.h>
#include<string.h>

//function to synchronize two files
int synchronize_files(char* file1, char* file2){
    FILE *fp1, *fp2;
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    //checking if the files exist
    if(fp1 == NULL || fp2 == NULL){
        return -1;
    }

    //getting the sizes of both files
    fseek(fp1, 0L, SEEK_END);
    long size1 = ftell(fp1);
    fseek(fp1, 0L, SEEK_SET);
    char data1[size1+1];
    fread(data1, 1, size1, fp1);
    fclose(fp1);

    fseek(fp2, 0L, SEEK_END);
    long size2 = ftell(fp2);
    fseek(fp2, 0L, SEEK_SET);
    char data2[size2+1];
    fread(data2, 1, size2, fp2);
    fclose(fp2);

    //comparing the two files
    if(strcmp(data1, data2) != 0){
        //if files are different, synchronizing them
        fp1 = fopen(file1, "w");
        fp2 = fopen(file2, "w");

        fprintf(fp1, "%s", data2);
        fprintf(fp2, "%s", data1);

        fclose(fp1);
        fclose(fp2);

        return 1;
    }
    return 0;
}

int main(){
    //testing the function
    int result = synchronize_files("file1.txt", "file2.txt");

    if(result == -1){
        printf("Error: One of the files does not exist!\n");
    }else if(result == 0){
        printf("Files are already synchronized!\n");
    }else{
        printf("Files were different! Synchronized now.\n");
    }

    return 0;
}