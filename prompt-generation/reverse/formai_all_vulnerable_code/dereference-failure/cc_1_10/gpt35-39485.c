//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to check if the character is a whitespace character
int isWhitespace(char c){
    return c == ' ' || c == '\n' || c == '\t' || c == '\r';
}

//Function to beautify the HTML
void beautifyHTML(char* code){
    int indent = 0;
    int len = strlen(code);
    char* newCode = (char*)malloc((len+100)*sizeof(char));
    int newIndex = 0;
    for(int i=0;i<len;i++){
        if(code[i] == '<'){
            if(i+3 < len && code[i+1] == '!' && code[i+2] == '-' && code[i+3] == '-'){
                indent--;
                for(int j=0;j<indent;j++){
                    newCode[newIndex++] = '\t';
                }
                newCode[newIndex++] = '<';
                newCode[newIndex++] = '!';
                newCode[newIndex++] = '-';
                newCode[newIndex++] = '-';
                newCode[newIndex++] = '>';
                i += 3;
            }
            else if(i+2 < len && code[i+1] == '/' && isWhitespace(code[i+2])){
                indent--;
                for(int j=0;j<indent;j++){
                    newCode[newIndex++] = '\t';
                }
                for(int j=i;j<len;j++){
                    newCode[newIndex++] = code[j];
                    if(code[j] == '>'){
                        newCode[newIndex++] = '\n';
                        break;
                    }
                }
            }
            else if(isWhitespace(code[i+1])){
                for(int j=0;j<indent;j++){
                    newCode[newIndex++] = '\t';
                }
                for(int j=i;j<len;j++){
                    newCode[newIndex++] = code[j];
                    if(code[j] == '>'){
                        newCode[newIndex++] = '\n';
                        if(i+2 < len && code[i+2] != '<' && !isWhitespace(code[i+2])){
                            indent++;
                        }
                        break;
                    }
                }
            }
            else{
                for(int j=0;j<indent;j++){
                    newCode[newIndex++] = '\t';
                }
                newCode[newIndex++] = '<';
                if(code[i+1] == '/'){
                    indent--;
                    i++;
                    newCode[newIndex++] = '/';
                }
                else{
                    indent++;
                }
            }
        }
        else{
            newCode[newIndex++] = code[i];
        }
    }
    newCode[newIndex] = '\0';
    printf("%s\n",newCode);
}

int main(){
    char* code = "<html><head><title>Test Page</title></head><body><h1>Welcome</h1><ul><li>List Item 1</li><li>List Item 2</li></ul></body></html>";
    beautifyHTML(code);
    return 0;
}