//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void synchronize_file(char *file1, char *file2){

    FILE* f1 = fopen(file1, "r");
    FILE* f2 = fopen(file2, "r");

    if(f1 == NULL){
        printf("Error: Could not open %s\n", file1);
        exit(1);
    }
    else if(f2 == NULL){
        printf("Error: Could not open %s\n", file2);
        exit(1);
    }

    char c1 = getc(f1);
    char c2 = getc(f2);
    int different = 0;
    int pos = 0;
    while (c1 != EOF && c2 != EOF)
    {
        pos++;

        if (c1 != c2){
            printf("Files are not identical\n");
            different = 1;
            break;
        }

        c1 = getc(f1);
        c2 = getc(f2);
    }

    if(different == 0){
        printf("Files are identical\n");
    }

    fclose(f1);
    fclose(f2);
}

int main()
{
    char file1[] = "file1.txt";
    char file2[] = "file2.txt";
    synchronize_file(file1,file2);
    return 0;
}