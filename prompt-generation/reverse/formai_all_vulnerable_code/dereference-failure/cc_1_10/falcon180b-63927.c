//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100
#define KEY "secretkey"

int main()
{
    char input_file[20],output_file[20],ch;
    FILE *fp1,*fp2;
    char key[SIZE];
    int i,j,k;

    printf("Enter input file name: ");
    scanf("%s",input_file);

    printf("Enter output file name: ");
    scanf("%s",output_file);

    fp1=fopen(input_file,"r");
    if(fp1==NULL)
    {
        printf("Error opening input file.\n");
        exit(0);
    }

    fp2=fopen(output_file,"w");
    if(fp2==NULL)
    {
        printf("Error opening output file.\n");
        exit(0);
    }

    //Copying the key into a character array
    for(i=0;i<strlen(KEY);i++)
    {
        key[i]=KEY[i];
    }

    //Reading the contents of input file
    while((ch=fgetc(fp1))!=EOF)
    {
        //Encrypting each character using the key
        for(i=0;i<strlen(key);i++)
        {
            for(j=0;j<strlen(key);j++)
            {
                if(key[i]==key[j])
                {
                    k=i;
                    break;
                }
            }
        }

        if(ch==key[k])
        {
            fprintf(fp2,"%c",ch);
        }
        else
        {
            fprintf(fp2,"%c",key[k]);
        }
    }

    fclose(fp1);
    fclose(fp2);

    printf("File encrypted successfully.\n");

    return 0;
}