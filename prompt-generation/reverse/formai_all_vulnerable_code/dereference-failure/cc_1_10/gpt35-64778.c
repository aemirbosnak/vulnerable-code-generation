//FormAI DATASET v1.0 Category: Syntax parsing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char keywords[32][10]={"auto","break","case","char",
                        "const","continue","default","do",
                        "double","else","enum","extern",
                        "float","for","goto","if",
                        "int","long","register","return",
                        "short","signed","sizeof","static",
                        "struct","switch","typedef","union",
                        "unsigned","void","volatile","while"};

int isKeyword(char buffer[]){
    for(int i=0;i<32;++i){
        if(strcmp(keywords[i], buffer) == 0){
            return 1;
        }
    }
    return 0;
}

int main(){
    FILE *fp1, *fp2;
    char ch, buffer[15], operators[] = "+-*/%=><&|!";
    int i, j=0, flag=0;

    fp1 = fopen("input.txt","r");
    fp2 = fopen("output.txt", "w");

    if(fp1 == NULL){
        printf("Error in opening input file.\n");
        exit(0);
    }

    if(fp2 == NULL){
        printf("Error in opening output file.\n");
        exit(0);
    }

    while((ch = fgetc(fp1)) != EOF){
        for(i=0;i<9;++i){
            if(ch == operators[i]){
                fprintf(fp2, "%c is operator\n", ch);
                flag=1;
                break;
            }
        }

        if(isalnum(ch)){
            buffer[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n') && (j!=0)){
            buffer[j] = '\0';
            j=0;

            if(isKeyword(buffer) == 1){
                fprintf(fp2, "%s is keyword\n", buffer);
            }
            else{
                fprintf(fp2, "%s is identifier\n", buffer);
            }
        }
    }

    fclose(fp1);
    fclose(fp2);

    printf("Output file created successfully.\n");

    return 0;
}