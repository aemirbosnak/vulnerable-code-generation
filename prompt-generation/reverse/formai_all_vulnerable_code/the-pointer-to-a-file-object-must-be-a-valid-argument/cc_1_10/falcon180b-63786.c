//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct{
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compare(const void* a, const void* b){
    WordFrequency* freq1 = (WordFrequency*)a;
    WordFrequency* freq2 = (WordFrequency*)b;
    if(freq1->count > freq2->count)
        return -1;
    else if(freq1->count < freq2->count)
        return 1;
    else
        return 0;
}

int main(){
    FILE* file = fopen("input.txt","r");
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordFrequency frequencies[MAX_WORDS];
    int numWords = 0;

    while(fgets(line,MAX_WORD_LENGTH,file)!= NULL){
        char* token = strtok(line,",.?!;:");
        while(token!= NULL){
            strcpy(word,token);
            int i;
            for(i=0;i<numWords;i++){
                if(strcmp(word,frequencies[i].word) == 0){
                    frequencies[i].count++;
                    break;
                }
            }
            if(i == numWords){
                strcpy(frequencies[numWords].word,word);
                frequencies[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL,",.?!;:");
        }
    }

    qsort(frequencies,numWords,sizeof(WordFrequency),compare);

    printf("Word\tFrequency\n");
    for(int i=0;i<numWords;i++){
        printf("%s\t%d\n",frequencies[i].word,frequencies[i].count);
    }

    return 0;
}