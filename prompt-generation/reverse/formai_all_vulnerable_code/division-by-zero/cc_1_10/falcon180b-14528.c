//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>

#define MAX_LEN 500
#define DIC_LEN 500
#define THRESHOLD 0.8
#define WINDOW_SIZE 4

char *dictionary[DIC_LEN];
int count = 0;

struct spam_record{
    char word[MAX_LEN];
    int count;
};

void load_dictionary(char *filename){
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error: cannot open dictionary file.\n");
        exit(1);
    }
    char line[MAX_LEN];
    while(fgets(line, MAX_LEN, fp)!= NULL){
        dictionary[count++] = strdup(line);
    }
    fclose(fp);
}

int is_spam(char *text){
    int i, j, len = strlen(text);
    struct spam_record *spam_table = (struct spam_record*)malloc(sizeof(struct spam_record) * count);
    for(i = 0; i < count; i++){
        spam_table[i].word[0] = '\0';
    }
    int max_count = 0;
    for(i = 0; i < len; i++){
        for(j = 0; j < WINDOW_SIZE && i + j < len; j++){
            char word[MAX_LEN];
            strncat(word, text + i, j + 1);
            word[j] = '\0';
            int k;
            for(k = 0; k < count; k++){
                if(strcmp(word, dictionary[k]) == 0){
                    spam_table[k].count++;
                    break;
                }
            }
        }
    }
    for(i = 0; i < count; i++){
        if(spam_table[i].count > max_count){
            max_count = spam_table[i].count;
        }
    }
    free(spam_table);
    return max_count / len > THRESHOLD;
}

int main(){
    char text[MAX_LEN];
    printf("Enter text to be checked for spam:\n");
    fgets(text, MAX_LEN, stdin);
    if(is_spam(text)){
        printf("The text contains spam.\n");
    }else{
        printf("The text does not contain spam.\n");
    }
    return 0;
}