//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include<stdio.h>

int main(){
    printf("Surprise! This is a C program to beautify HTML code!\n");

    // Define variables
    FILE *fp, *fw;
    char ch;
    int indent = 0;

    // Open input file
    fp = fopen("input.html", "r");

    // Open output file
    fw = fopen("output.html", "w");

    // Check if both files opened successfully
    if(fp == NULL || fw == NULL){
        printf("Error opening files\n");
        return 0;
    }

    // Read input file character by character
    while((ch = fgetc(fp)) != EOF){

        // Increase indent on start tag
        if(ch == '<'){
            fputc(ch, fw);
            indent++;
            fputc('\n', fw);
            for(int i = 0; i < indent; i++){
                fputc('\t', fw);
            }
        }
        // Decrease indent on end tag
        else if(ch == '>'){
            fputc(ch, fw);
            indent--;
            fputc('\n', fw);
            for(int i = 0; i < indent; i++){
                fputc('\t', fw);
            }
        }
        else{
            // Write character normally
            fputc(ch, fw);
        }
    }

    // Close both files
    fclose(fp);
    fclose(fw);

    printf("HTML beautified successfully!\n");
    return 0;
}