//FormAI DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program takes in a text file and replaces all instances of a given string
   with a new one. It then saves the modified text to a new file */

int main() {
    FILE *fp;
    char *old_str, *new_str, *file_name, *new_file_name, *temp_str, temp_ch;
    int old_len, new_len, size, i, j, match, count=0;

    // Get old string and new string from user
    old_str = (char*)malloc(sizeof(char)*100);
    new_str = (char*)malloc(sizeof(char)*100);
    printf("Enter the original string: ");
    scanf("%s", old_str);
    printf("Enter the new string: ");
    scanf("%s", new_str);

    // Get file name from user
    file_name = (char*)malloc(sizeof(char)*100);
    printf("Enter the name of the file to modify: ");
    scanf("%s", file_name);

    // Open file
    fp = fopen(file_name, "r");
    if(fp == NULL) {
        printf("Error: File not found!");
        exit(0);
    }

    // Get file size
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Dynamic memory allocation
    temp_str = (char*)malloc(sizeof(char)*size+1);
    new_file_name = (char*)malloc(sizeof(char)*100);

    // Read characters from file and load them into temp_str
    i = 0;
    while((temp_ch = fgetc(fp)) != EOF) {
        temp_str[i++] = temp_ch;
    }
    temp_str[i] = '\0';

    // Close original file
    fclose(fp);

    // Get length of old and new string
    old_len = strlen(old_str);
    new_len = strlen(new_str);

    // Search for old string in temp_str and replace with new string
    for(i=0; temp_str[i]!='\0';) {
        match = 1;
        for(j=0; j<old_len; j++) {
            if(temp_str[i+j] != old_str[j]) {
                match = 0;
                break;
            }
        }
        if(match == 1) {
            for(j=0; j<new_len; j++) {
                temp_str[i+j] = new_str[j];
            }
            i += new_len;
            count++;
        }
        else {
            i++;
        }
    }

    // Get new file name from user
    printf("Enter the name of the new file: ");
    scanf("%s", new_file_name);

    // Create new file and write modified text to it
    fp = fopen(new_file_name, "w");
    if(fp == NULL) {
        printf("Error: Unable to create file!");
        exit(0);
    }
    fprintf(fp, "%s", temp_str);

    // Close new file
    fclose(fp);

    // Print results to console
    printf("\nFile modified successfully!\n");
    printf("Number of replacements made: %d\n", count);

    // Free allocated memory
    free(old_str);
    free(new_str);
    free(file_name);
    free(new_file_name);
    free(temp_str);

    return 0;
}