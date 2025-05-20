//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char fileName[30], fileContent[1000], ch;
    int choice, size;

    printf("Welcome to the File Handling program!\n");
    printf("Please enter the name of the file to be created: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "w+");

    if(fp != NULL){
        printf("File created successfully!\n");
        printf("What would you like to do next?\n");
        printf("1. Write content to the file.\n");
        printf("2. Read content from the file.\n");
        printf("3. Exit.\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Please enter the content to be written to the file: ");
                scanf("%s", fileContent);

                size = fwrite(fileContent, sizeof(char), sizeof(fileContent), fp);

                if(size != 0){
                    printf("Content written successfully!\n");
                }
                else{
                    printf("Error! Could not write content to file.\n");
                }

                break;

            case 2:
                printf("Reading content from the file...\n");
                printf("Content: ");

                while(!feof(fp)){
                    ch = fgetc(fp);
                    printf("%c", ch);
                }

                fclose(fp);
                break;

            case 3:
                printf("Exiting program...\n");
                fclose(fp);
                return 0;
        }
    }
    else{
        printf("Error! Could not create file.\n");
        return 1;
    }

    return 0;
}