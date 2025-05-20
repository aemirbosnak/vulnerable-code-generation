//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct{
    char *word;
    int count;
} WordFrequency;

int compareWords(const void *p1, const void *p2){
    WordFrequency *w1 = (WordFrequency*)p1;
    WordFrequency *w2 = (WordFrequency*)p2;
    return strcmp(w1->word, w2->word);
}

int main(){
    FILE *ebook;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *word = NULL;
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    int i;

    ebook = fopen("ebook.txt", "r");
    if(ebook == NULL){
        printf("Error opening ebook.\n");
        exit(1);
    }

    while((read = getline(&line, &len, ebook))!= -1){
        if(read > 0 && line[read-1] == '\n'){
            line[--read] = '\0';
        }
        word = strtok(line, ",.?!;:");
        while(word!= NULL){
            for(i=0; i<numWords; i++){
                if(strcmp(word, words[i].word) == 0){
                    words[i].count++;
                    break;
                }
            }
            if(i == numWords){
                if(numWords >= MAX_WORDS){
                    printf("Maximum number of words reached.\n");
                    break;
                }
                words[numWords].word = strdup(word);
                words[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for(i=0; i<numWords; i++){
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(line);
    fclose(ebook);
    return 0;
}