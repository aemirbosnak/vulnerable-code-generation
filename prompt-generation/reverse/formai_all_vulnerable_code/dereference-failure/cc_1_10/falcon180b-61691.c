//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: immersive
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 1000000

typedef struct word_count{
    char word[MAX_SIZE];
    int count;
}word_count;

word_count *create_word_count(char *str){
    int i,j;
    word_count *word_count_array=malloc(sizeof(word_count)*26);
    for(i=0;i<26;i++){
        word_count_array[i].word[0]='\0';
        word_count_array[i].count=0;
    }
    for(i=0;i<strlen(str);i++){
        if(isalpha(str[i])){
            str[i]=tolower(str[i]);
        }
    }
    for(i=0;i<strlen(str);i++){
        if(isalpha(str[i])){
            j=tolower(str[i])-'a';
            word_count_array[j].word[strlen(word_count_array[j].word)]=str[i];
            word_count_array[j].word[strlen(word_count_array[j].word)+1]='\0';
            word_count_array[j].count++;
        }
    }
    return word_count_array;
}

void print_word_count(word_count *word_count_array){
    int i;
    for(i=0;i<26;i++){
        if(word_count_array[i].word[0]!='\0'){
            printf("%c:\t%d\n",i+'a',word_count_array[i].count);
        }
    }
}

int main(){
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str,MAX_SIZE,stdin);
    word_count *word_count_array=create_word_count(str);
    print_word_count(word_count_array);
    free(word_count_array);
    return 0;
}