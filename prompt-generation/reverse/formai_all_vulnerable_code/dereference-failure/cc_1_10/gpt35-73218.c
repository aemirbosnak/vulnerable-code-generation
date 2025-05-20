//FormAI DATASET v1.0 Category: HTML beautifier ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

int isWhiteSpace(char c){
    if(c == ' ' || c == '\t' || c == '\n') return 1;
    else return 0;
}

char* beautifyHTML(char* html){
    int len = strlen(html);
    char* newHTML = (char*) malloc(MAX * sizeof(char));
    int count = 0, indentLevel = 0;

    for(int i=0; i<len; i++){
        if(html[i] == '<'){
            if(html[i+1] == '/'){
                indentLevel--;
                count -= 2;
            }
            for(int j=0; j<count; j++)
                newHTML[strlen(newHTML)] = ' ';
            if(html[i+1] != '/')
                indentLevel++;
            count += 2;
        }else if(html[i] == '>'){
            newHTML[strlen(newHTML)] = html[i];
            newHTML[strlen(newHTML)] = '\n';
        }else{
            newHTML[strlen(newHTML)] = html[i];
        }
    }
    return newHTML;
}

int main(void){
    char html[MAX], c;
    int i=0;
    printf("Enter HTML code:\n");
    while((c=getchar()) != EOF && i<MAX){
        html[i] = c;
        i++;
    }
    html[i] = '\0';
    char* newHTML = beautifyHTML(html);
    printf("\n\n*** Beautified HTML code ***\n\n");
    printf("%s\n", newHTML);
    free(newHTML);
    return 0;
}