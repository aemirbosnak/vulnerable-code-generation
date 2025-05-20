//FormAI DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void recoverData(FILE* fp, int size){
    char *data = (char*)malloc(sizeof(char)*size);
    if(!data){
        printf("Out of memory\n");
        exit(1);
    }

    fread(data, size, 1, fp);

    FILE* new_fp = fopen("recovered_data.txt", "w");
    if(!new_fp){
        printf("Unable to create new file\n");
        exit(1);
    }

    printf("Recovered Data:- %s\n", data);

    fwrite(data, size, 1, new_fp);
    fclose(new_fp);
    free(data);
}

int main(){
    FILE *fp;
    char filename[50];

    printf("Enter the filename (with path) to recover data from:- ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if(!fp){
        printf("Unable to open file\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    printf("Size of file is %d bytes\n", size);

    if(size <= 0){
        printf("File is empty\n");
        exit(1);
    }

    recoverData(fp, size);

    fclose(fp);

    return 0;
}