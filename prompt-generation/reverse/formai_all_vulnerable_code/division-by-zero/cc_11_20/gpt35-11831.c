//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: irregular
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char str[1000], word[1000];
    int freq[1000] = {0};
    int i,j,ctr,len;

    printf("Enter the text:\n");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);

    if (len > 0 && str[len-1] == '\n')
        str[len-1] = '\0';

    for(i=0,j=0; i<=len; i++){
        if(isalnum(str[i]) || str[i] == '-'){
            word[j++] = tolower(str[i]);
        }
        else if(str[i] == ' ' || str[i] == '\0'){
            word[j] = '\0';
            j = 0;
            for(ctr=0; ctr<=i; ctr++){
                if(strcmp(word, "")!=0 && strcmp(word, " ")!=0 && strcmp(word, "-")!=0 && strcmp(word, "--")!=0)
                {
                    if(strcmp(word, &str[ctr])==0 && strncmp(word, &str[ctr], strlen(word)+1)==0){
                        freq[ctr/strlen(word)]++;
                    }
                }
            }
        }
    }
    int count=0;

    printf("\nWord Frequency Counter Output:\n");
    printf("Word \t\t Frequency\n");

    for(i=0;i<ctr/len;i++){
        if(freq[i]!=0){
            for(j=i*strlen(word);j<(i+1)*strlen(word); j++){
                if(str[j]!='\0'){
                    printf("%c", str[j]);
                }
            }
            printf("\t\t%d\n", freq[i]);
            count++;
        }
    }
    printf("\nTotal words: %d\n", count);
    return 0;
}