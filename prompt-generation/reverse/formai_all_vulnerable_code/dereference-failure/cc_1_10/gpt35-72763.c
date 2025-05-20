//FormAI DATASET v1.0 Category: File Synchronizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sync_files(char *file1, char *file2){
    printf("We're going to synchronize '%s' and '%s'.\n", file1, file2);

    // Open file1 for reading
    FILE *fp1 = fopen(file1, "r");
    if(fp1 == NULL){
        printf("Error opening file '%s'.\n", file1);
        exit(1);
    }

    // Open file2 for reading
    FILE *fp2 = fopen(file2, "r");
    if(fp2 == NULL){
        printf("Error opening file '%s'.\n", file2);
        exit(1);
    }

    // Read character by character from both files
    char c1 = fgetc(fp1);
    char c2 = fgetc(fp2);
    int line = 1, column = 1;

    while(c1 != EOF || c2 != EOF){
        // Compare characters from both files
        if(c1 != c2){
            // Print a cheerful message indicating the difference
            printf("Found difference at line %d, column %d: '%c' in '%s' and '%c' in '%s'.\n", 
                    line, column, c1, file1, c2, file2);
        }

        // Move on to next character
        if(c1 != EOF){
            c1 = fgetc(fp1);
            if(c1 == '\n'){
                line++;
                column = 1;
            }else{
                column++;
            }
        }

        if(c2 != EOF){
            c2 = fgetc(fp2);
            if(c2 == '\n'){
                line++;
                column = 1;
            }else{
                column++;
            }
        }
    }

    // Close both files
    fclose(fp1);
    fclose(fp2);

    // Celebratory success message
    printf("Hooray! File synchronization complete!\n");
}

int main(){
    // File synchronization time!
    sync_files("myfile1.txt", "myfile2.txt");

    return 0;
}