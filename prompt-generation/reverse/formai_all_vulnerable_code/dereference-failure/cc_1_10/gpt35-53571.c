//FormAI DATASET v1.0 Category: HTML beautifier ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

void indent(int level, FILE* output){
    for(int i=0;i<level;i++){
        putc('\t',output);
    }
}

int main(){
    FILE* input;
    FILE* output;
    int level=0;
    char c,lastc;
  
    input=fopen("source.html","r");
    output=fopen("beautified.html","w");
    if(input==NULL || output==NULL){
        printf("Error opening file");
        exit(1);
    }

    while((c=getc(input))!=EOF){
        if(c=='<'){
            if(lastc=='\n'){
                indent(level,output);
            }
            putc(c,output);
            c=getc(input);
            putc(c,output);
            if(c=='/'){
                level--;
            }
            else{
                level++;
            }
            putc('\n',output);
            indent(level,output);
        }
        else if(c=='>'){
            putc(c,output);
            putc('\n',output);
            if(lastc=='/'){
                level--;
            }
            indent(level,output);
        }
        else{
            putc(c,output);
        }
        lastc=c;
    }

    fclose(input);
    fclose(output);
    return 0;
}