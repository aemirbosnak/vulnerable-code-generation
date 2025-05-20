//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: creative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_WORDS 1000
#define WORD_LENGTH 50

struct word_frequency {
    char word[WORD_LENGTH];
    int frequency;
};

typedef struct word_frequency Word_Frequency;

int wordCount(char* sentence) {
    int count=0;
    for(int i=0;sentence[i]!='\0';i++) {
        if(sentence[i]==' ')
            count++;
    }
    return count+1;
}
void lower(char* string) {
    for(int i=0;i<strlen(string);i++)
        string[i]=tolower(string[i]);
    return;
}
int compare(const void *p, const void *q) {
    int f = ((Word_Frequency*)p)->frequency;
    int s = ((Word_Frequency*)q)->frequency;

    if(f==s) {
        char str1[WORD_LENGTH],str2[WORD_LENGTH];
        strcpy(str1, ((Word_Frequency*)p)->word);
        strcpy(str2, ((Word_Frequency*)q)->word);
        lower(str1);
        lower(str2);

        return strcmp(str1,str2)>0;
    }
    return (s-f);
}
Word_Frequency* wordFrequency(char* sentence) {
    Word_Frequency* w=(Word_Frequency*)malloc(sizeof(Word_Frequency)*MAX_WORDS);
    int i=0,j=0,words=0;
    char word[WORD_LENGTH];
    for(int k=0;k<strlen(sentence);k++) {
        if(sentence[k]!=' ')
            word[j++]=sentence[k];
        else {
            word[j]='\0';
            strcpy(w[i].word,word);
            w[i].frequency=1;
            i++;
            j=0;
            words++;
        }
    }
    word[j]='\0';
    strcpy(w[i].word,word);
    w[i].frequency=1;
    words++;
    qsort(w,words,sizeof(Word_Frequency),compare);
    return w;
}
void printWordFrequency(Word_Frequency* w) {
    for(int i=0; i<MAX_WORDS; i++) {
        if(w[i].frequency==0)
            return;
        printf("\n%-20s - %d ",w[i].word,w[i].frequency);
    }
}
int main() {
    char sentence[10000];
    printf("Enter a sentence: ");
    fgets(sentence,10000,stdin);
    Word_Frequency* wf=wordFrequency(sentence);
    printf("\nWord frequency in the sentence: ");
    printWordFrequency(wf);
    return 0;
}