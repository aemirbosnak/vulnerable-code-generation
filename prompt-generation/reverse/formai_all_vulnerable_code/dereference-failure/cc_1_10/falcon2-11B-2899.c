//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char filename[100];
    FILE *fp;
    struct stat st;
    int i, n;

    if(argc!=2){
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    if((fp = fopen(filename, "r")) == NULL){
        printf("File not found\n");
        return 1;
    }

    if(stat(filename, &st) == -1){
        printf("File not found\n");
        return 1;
    }

    if(st.st_size == 0){
        printf("File is empty\n");
        return 1;
    }

    printf("File Name: %s\n", filename);
    printf("File Size: %ld bytes\n", st.st_size);

    if(fread(&n, sizeof(int), 1, fp)!= 1){
        printf("Failed to read the file\n");
        return 1;
    }

    printf("Number of records: %d\n", n);

    for(i=0; i<n; i++){
        char buf[100];
        if(fread(buf, sizeof(char), 100, fp)!= 100){
            printf("Failed to read the file\n");
            return 1;
        }
        printf("%s\n", buf);
    }

    fclose(fp);
    return 0;
}