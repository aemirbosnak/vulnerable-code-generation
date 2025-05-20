//FormAI DATASET v1.0 Category: HTML beautifier ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to remove all the white spaces from the input buffer
void removeSpaces(char* str){
    int counter = 0;
    for(int i = 0; str[i]; i++){
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\r' && str[i] != '\n'){
            str[counter++] = str[i];
        }
    }
    str[counter] = '\0';
}

//Function to print the formatted HTML code
void printCode(char* code, int indentLevel){
    int i = 0;

    while(code[i] != '\0'){
        if(code[i] == '<'){
            //If the current character is '<', print a new line and then indent the next line
            printf("\n");
            for(int j=0;j<indentLevel;j++){
                printf("\t");
            }
        }

        printf("%c", code[i]);

        if(code[i] == '>'){
            //If the current character is '>', decrease the indentation level
            indentLevel--;

            //If the next line contains just whitespace, continue to the next line
            while(code[++i] == ' ' || code[i] == '\t' || code[i] == '\n' || code[i] == '\r'){}
            
            //Indent the next line
            printf("\n");
            for (int j = 0; j < indentLevel; j++){
                printf("\t");
            }

            //If the next char is not '<', decrease the indentation level by 1
            if(code[i] != '<'){
                indentLevel--;
            }
            i--;
        }
        i++;
    }
}

int main(){
    char* html = "<html>\n<body>\n<h1>Hello, World!</h1>\n</body>\n</html>\n";

    //Remove all the white spaces from the HTML code
    removeSpaces(html);

    //Pretty print the HTML code
    printCode(html, 0);

    return 0;
}