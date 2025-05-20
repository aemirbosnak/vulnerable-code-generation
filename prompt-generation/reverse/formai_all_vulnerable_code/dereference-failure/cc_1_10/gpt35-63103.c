//FormAI DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TAB_SPACE "    " //sets the number of space per tab

int main(void){
    FILE *unformattedHtmlFilePointer, *formattedHtmlFilePointer;
    char *buffer;
    char ch;
    int size = 0, count_tab = 0;
    
    buffer = malloc( sizeof(char) * size );
    
    unformattedHtmlFilePointer = fopen("unformatted.html", "r"); // opens the file to read
    
    formattedHtmlFilePointer = fopen("formatted.html", "w"); // opens the file to write
    
    while((ch = fgetc(unformattedHtmlFilePointer)) != EOF){
        buffer = realloc(buffer, sizeof(char) * (size+1)); // reallocates buffer to a new size
        buffer[size] = ch; // add character to buffer
        size++; 
        
        if(ch == '\n') { // check if there is a new line
            count_tab--;
            
            for(int i = 0; i < count_tab; i++) { 
                fprintf(formattedHtmlFilePointer, TAB_SPACE); // prints tab space
            }
            
        }
        
        if(ch == '<') {
            count_tab++;
            if(buffer[size-2] == '>') {
                count_tab--;
            }
        }
        
        fprintf(formattedHtmlFilePointer, "%c", ch); // prints character to output file
    }
    
    free(buffer);
    
    fclose(unformattedHtmlFilePointer);
    fclose(formattedHtmlFilePointer);
    
    printf("HTML formatted successfully.");
    
    return 0;
}