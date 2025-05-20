//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

    FILE *fpIn, *fpOut; // file pointers for input and output files
    char filenameIn[50], filenameOut[50], str[1000], c;
    int i, flag=0, space=0, comment=0, quotes=0, indent=0, indentFlag=0;

    // Input filename
    printf("Enter the input filename: ");
    scanf("%s", filenameIn);

    // Output filename
    printf("Enter the output filename: ");
    scanf("%s", filenameOut);

    // Open input file in read mode
    fpIn = fopen(filenameIn, "r");

    // Check if input file is successfully opened
    if(fpIn == NULL){
        printf("Unable to open input file!\n");
        exit(1);
    }

    // Open output file in write mode
    fpOut = fopen(filenameOut, "w");

    // Check if output file is successfully opened
    if(fpOut == NULL){
        printf("Unable to open output file!\n");
        exit(1);
    }

    // Process input file character by character
    while((c = fgetc(fpIn)) != EOF){

        // Check for opening/closing quotes
        if(c == '\"' && comment == 0){
            if(quotes == 0){
                quotes = 1;
                fprintf(fpOut, "\"");
            }
            else{
                quotes = 0;
                fprintf(fpOut, "\"");
            }
        }

        // Check for opening/closing comments
        else if(c == '/' && comment == 0){
            comment = 1;
            if((c = fgetc(fpIn)) == '/'){
                // Single line comment
                fprintf(fpOut, "/%c", c);
                while((c = fgetc(fpIn)) != '\n'){
                    fprintf(fpOut, "%c", c);
                }
                fprintf(fpOut, "\n");
            }
            else if(c == '*'){
                // Multiline comment
                flag = 1;
                fprintf(fpOut, "/*");
                while(flag){
                    c = fgetc(fpIn);
                    if(c == '*'){
                        if((c = fgetc(fpIn)) == '/'){
                            fprintf(fpOut, "*%c/", c);
                            flag = 0;
                        }
                        else{
                            fprintf(fpOut, "*%c", c);
                        }
                    }
                    else{
                        fprintf(fpOut, "%c", c);
                    }
                }
            }
        }
        else if(c == '*' && comment == 1){
            c = fgetc(fpIn);
            if(c == '/'){
                fprintf(fpOut, "%c/", c);
                comment = 0;
            }
            else{
                fprintf(fpOut, "*%c", c);
            }
        }

        // Check for new line character
        else if(c == '\n' && quotes == 0 && comment == 0){
            fprintf(fpOut, "\n");

            // Set indentFlag to 1 if more than one consecutive line breaks
            if(space >= 1){
                indentFlag = 1;
            }
            space = 0;
        }

        // Check for space/tab character
        else if(c == ' ' || c == '\t'){
            if(quotes == 0 && comment == 0){
                if(space == 0){
                    if(indentFlag == 1){
                        indent++;
                        indentFlag = 0;
                    }
                    fprintf(fpOut, " ");
                    space++;
                }
            }
            else{
                fprintf(fpOut, "%c", c);
            }
        }

        // Any other character
        else{
            if(space >= 1){
                space = 0;
            }
            fprintf(fpOut, "%c", c);
        }
    }

    // Close input and output files
    fclose(fpIn);
    fclose(fpOut);

    // Success message
    printf("HTML beautifier program executed successfully!\n");

    return 0;

}