//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void summary(char *input){
    char *temp;
    int i, j, k, sent_start, sent_end, num_sent, num_words, sum_words;
    char sentence[300];
    char *sentences[20];
    char *words[60];
    
    temp = strtok(input, "."); //tokenize with period as delimiter to get sentences
    i = 0;
    while(temp != NULL){
        sentences[i] = malloc(strlen(temp)+1);
        strcpy(sentences[i], temp);
        strcat(sentences[i], ".");
        i++;
        temp = strtok(NULL, ".");
    }
    num_sent = i;
    
    for(i=0; i<num_sent; i++){
        temp = strtok(sentences[i], " "); //tokenize the sentence to get words
        j = 0;
        while(temp != NULL){
            words[j] = malloc(strlen(temp)+1);
            strcpy(words[j], temp);
            j++;
            temp = strtok(NULL, " ");
        }
        num_words = j;
        
        sum_words = 0;
        sent_start = -1;
        sent_end = -1;
        for(j=0; j<num_words; j++){ //analyze words in the sentence
            if(words[j][strlen(words[j])-1] == ','){
                sum_words += strlen(words[j])-1;
            } else{
                sum_words += strlen(words[j]);
            }
            
            if(sent_start == -1){
                sent_start = j;
            }
            if(sum_words >= 30){ //if a sentence has more than or equal to 30 words, it is summarized
                sent_end = j;
                break;
            }
        }
        
        if(sent_end == -1){ //if the current sentence is not summarized, add it to the summary
            printf("%s", sentences[i]);
        } else{ //if the current sentence is summarized
            for(k=sent_start; k<=sent_end; k++){
                printf("%s ", words[k]);
            }
            printf("... ");
        }
        
        for(j=0; j<num_words; j++){ //free memory for words
            free(words[j]);
        }
        printf("\n");
    }
    
    for(i=0; i<num_sent; i++){ //free memory for sentences
        free(sentences[i]);
    }
}

int main(){
    char input[1000];
    printf("Enter text to summarize:\n");
    fgets(input, 1000, stdin);
    
    summary(input);
    
    return 0;
}