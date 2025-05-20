//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char filename[30];
    FILE *fp;
    char ch;
    int i,j=0;

    printf("Enter the file name to scan: ");
    scanf("%s", filename);

    fp = fopen(filename,"r");

    if(fp == NULL)
    {
        printf("Error opening file. Check if the file exists.\n");
        exit(1);
    }

    while((ch=getc(fp))!=EOF)
    {
        char virus[] = "antivirus";
        char buf[10];

        if(ch == virus[0])
        {
            fseek(fp,-1,SEEK_CUR);

            for(i=0;i<9;i++)
            {
                ch = getc(fp);
                buf[i] = ch;
            }
            buf[i] = '\0';
            if(strcmp(virus,buf) == 0)
            {
                printf("Warning: This file contains antivirus software.\n");
                printf("Please remove the software and rescan the file.\n");
                j=1;
                break;
            }
        }
    }

    if(j==0)
        printf("File is safe!\n");

    return 0;
}