//FormAI DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4

char* beautify(char *code){
    char *formatted = (char*)malloc((strlen(code)*TAB_SIZE + 1) * sizeof(char));
    int index = 0;
    int depth = 0;
    int new_line = 1;

    for(int i = 0; i < strlen(code); i++){
        char current_char = code[i];
        if(current_char == '{'){
            if(!new_line){
                formatted[index++] = '\n';
                new_line = 1;
            }
            for(int j = 0; j < depth * TAB_SIZE; j++){
                formatted[index++] = ' ';
            }
            formatted[index++] = '{';
            formatted[index++] = '\n';
            depth++;
            new_line = 1;
        }
        else if(current_char == '}'){
            depth--;
            if(!new_line){
                formatted[index++] = '\n';
                new_line = 1;
            }
            for(int j = 0; j < depth * TAB_SIZE; j++){
                formatted[index++] = ' ';
            }
            formatted[index++] = '}';
            formatted[index++] = '\n';
            new_line = 1;
        }
        else if(current_char == '\n'){
            formatted[index++] = '\n';
            new_line = 1;
        }
        else{
            formatted[index++] = current_char;
            new_line = 0;
        }
    }

    formatted[index] = '\0';
    return formatted;
}

int main(){
    char code[] = "{\nvoid main(){\nprintf(\"Hello World\");\n}\n}";
    char *formatted_code = beautify(code);
    printf("Formatted code:\n%s", formatted_code);
    free(formatted_code);
    return 0;
}