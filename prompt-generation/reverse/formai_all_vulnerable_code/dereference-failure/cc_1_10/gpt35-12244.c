//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Dennis Ritchie
/* C Text Summarizer by (Your Name Here) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 10000
#define MAX_SUMMARY_LENGTH 2000

char* get_summary(char* text, int summary_length);

int main()
{
    char text[MAX_TEXT_LENGTH];
    char* summary;
    int summary_length;
    
    printf("Enter article: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);
    
    do
    {
        printf("Enter summary length (max %d): ", MAX_SUMMARY_LENGTH);
        scanf("%d", &summary_length);
        getchar();
    } while(summary_length > MAX_SUMMARY_LENGTH);
    
    summary = get_summary(text, summary_length);
    
    printf("Summary:\n%s", summary);
    
    free(summary);
    return 0;
}

char* get_summary(char* text, int summary_length)
{
    char* summary = (char*)malloc(MAX_SUMMARY_LENGTH*sizeof(char));
    int sentences_count = 0;
    char* sentence;
    char* temp;
    
    /* Count sentences in text */
    temp = strtok(text, ".");
    while(temp != NULL)
    {
        temp = strtok(NULL, ".");
        sentences_count++;
    }
    
    /* Allocate memory for sentence pointers and copy sentences from text */
    sentence = (char*)malloc(sentences_count*sizeof(char));
    temp = strtok(text, ".");
    for(int i = 0; i < sentences_count; i++)
    {
        strcpy(&sentence[i], temp);
        strcat(&sentence[i], ".");
        temp = strtok(NULL, ".");
    }
    
    /* Sort sentences by length */
    for(int i = 0; i < sentences_count - 1; i++)
    {
        for(int j = i + 1; j < sentences_count; j++)
        {
            if(strlen(&sentence[i]) < strlen(&sentence[j]))
            {
                char* tmp = sentence[i];
                sentence[i] = sentence[j];
                sentence[j] = tmp;
            }
        }
    }
    
    /* Create summary */
    summary[0] = '\0';
    int summary_length_so_far = 0;
    for(int i = 0; i < sentences_count; i++)
    {
        strcat(summary, &sentence[i]);
        summary_length_so_far += strlen(&sentence[i]);
        if(summary_length_so_far > summary_length)
        {
            summary[i] = '\0';
            break;
        }
    }
    
    free(sentence);
    return summary;
}