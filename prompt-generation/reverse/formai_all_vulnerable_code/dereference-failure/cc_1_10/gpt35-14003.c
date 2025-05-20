//FormAI DATASET v1.0 Category: File Synchronizer ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/* Function to synchronize files */
void synchronize(char f1[], char f2[]){

    /* Opening files */
    FILE *fp1, *fp2;
    fp1 = fopen(f1, "r");
    fp2 = fopen(f2, "r");

    /* Checking if files exist */
    if(fp1==NULL || fp2==NULL){
        printf("Error: One or both files do not exist.\n");
        return;
    }

    /* Getting file size */
    fseek(fp1,0,SEEK_END);
    long int f1_size = ftell(fp1);
    fseek(fp1,0,SEEK_SET);

    fseek(fp2,0,SEEK_END);
    long int f2_size = ftell(fp2);
    fseek(fp2,0,SEEK_SET);

    /* Getting current time */
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    /* Synchronizing files */
    if(f1_size==f2_size){
        printf("Files are already synchronized.\n");
        printf("Last synchronized: %s\n", c_time_string);
        fclose(fp1);
        fclose(fp2);
        return;
    }
    else if(f1_size>f2_size){
        char ch;
        int counter = 0;
        while((ch=getc(fp2))!=EOF){
            counter++;
        }
        while((ch=getc(fp1))!=EOF){
            fputc(ch,fp2);
            counter++;
        }
        printf("Files synchronized successfully.\n");
        printf("Last synchronized: %s\n", c_time_string);
        fclose(fp1);
        fclose(fp2);
        return;
    }
    else{
        char ch;
        int counter = 0;
        while((ch=getc(fp1))!=EOF){
            counter++;
        }
        while((ch=getc(fp2))!=EOF){
            fputc(ch,fp1);
            counter++;
        }
        printf("Files synchronized successfully.\n");
        printf("Last synchronized: %s\n", c_time_string);
        fclose(fp1);
        fclose(fp2);
        return;
    }
}

int main(){

    /* Getting file names from user */
    char f1[100], f2[100];
    printf("Enter path of first file: ");
    scanf("%s",f1);
    printf("Enter path of second file: ");
    scanf("%s",f2);

    /* Synchronizing files */
    synchronize(f1,f2);

    return 0;
}