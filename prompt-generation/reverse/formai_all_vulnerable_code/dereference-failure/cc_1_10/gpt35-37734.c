//FormAI DATASET v1.0 Category: HTML beautifier ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100000 //maximum size of input file

/* function to remove single and multi line comments from code */
char* remove_comments(char *html){
    char *single = strstr(html,"//");
    while(single != NULL){
        char *end = strstr(single,"\n");
        if(end != NULL){
            memmove(single,end+1,strlen(end+1)+1);
            single = strstr(html,"//");
        }
        else{
            memset(single,'\0',strlen(single));
            break;
        }
    }

    char *multi1 = strstr(html,"/*");
    while(multi1 != NULL){
        char *multi2 = strstr(multi1+2,"*/");
        if(multi2 != NULL){
            memmove(multi1,multi2+2,strlen(multi2+2)+1);
            multi1 = strstr(html,"/*");
        }
        else{
            memset(multi1,'\0',strlen(multi1));
            break;
        }
    }

    return html;
}

/* function to indent code based on braces and semicolons */
char* beautify_html(char *html){
    int braces = 0, tabs = 0, newline = 1;
    size_t length = strlen(html);
    char *output = (char*) malloc(length * sizeof(char));

    for(int i=0; i<length; i++){
        /* newline */
        if(html[i] == '\n'){
            output[i] = '\n';
            newline = 1;
        }
        /* opening brace */
        else if(html[i] == '{'){
            if(newline == 1){
                for(int j=0; j<tabs; j++){
                    strcat(output,"\t");
                }
            }
            braces++;
            strcat(output,"{\n");
            newline = 1;
        }
        /* closing brace */
        else if(html[i] == '}'){
            if(braces > 0){
                braces--;
                tabs--;
            }
            if(newline == 0){
                strcat(output,"\n");
            }
            for(int j=0; j<tabs; j++){
                strcat(output,"\t");
            }
            strcat(output,"}\n");
            newline = 1;
        }
        /* semicolon */
        else if(html[i] == ';'){
            output[i] = ';';
            if(newline == 1){
                for(int j=0; j<tabs; j++){
                    strcat(output,"\t");
                }
            }
            newline = 1;
        }
        /* other characters */
        else{
            if(newline == 1){
                tabs++;
                for(int j=0; j<tabs; j++){
                    strcat(output,"\t");
                }
            }
            output[i] = html[i];
            newline = 0;
        }
    }

    return output;
}

int main(){

    char input[MAX_SIZE];

    /* read input file */
    FILE *file = fopen("input.html","r");
    if(file == NULL){
        printf("Error: Cannot open input file.\n");
        return 1;
    }
    fgets(input,MAX_SIZE,file);
    fclose(file);

    /* remove comments */
    char *no_comments = remove_comments(input);

    /* beautify code */
    char *beautified = beautify_html(no_comments);

    /* write to output file */
    file = fopen("output.html","w");
    if(file == NULL){
        printf("Error: Cannot open output file.\n");
        return 1;
    }
    fprintf(file,"%s",beautified);
    fclose(file);

    /* print beautified code */
    printf("%s",beautified);

    free(beautified);

    return 0;
}