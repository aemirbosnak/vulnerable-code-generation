//FormAI DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 10000    // maximum input text size
#define MAX_SUMMARY_SIZE 1000  // maximum summary size

char *summarize(char *text);

int main()
{
    char *text = (char *)malloc(MAX_TEXT_SIZE * sizeof(char));  // allocate memory for input text
    char *summary;

    printf("Enter text to be summarized(max %d characters):\n", MAX_TEXT_SIZE);
    fgets(text, MAX_TEXT_SIZE, stdin);  // read input text from user

    summary = summarize(text);
    printf("\nSummary:\n%s", summary);

    free(text);
    free(summary);
    return 0;
}

char *summarize(char *text)
{
    char *summary = (char *)malloc(MAX_SUMMARY_SIZE * sizeof(char));  // allocate memory for summary
    int summary_index = 0;  // index for summary

    char *token = strtok(text, " ");  // tokenize input text using blank spaces as delimiters
    
    int sentence_count = 0;
    while (token != NULL)
    {
        strcat(summary, token);  // append current token to summary
        summary_index += strlen(token);

        if (summary_index >= MAX_SUMMARY_SIZE - 2)  // if summary size limit reached, break
        {
            break;
        }

        if (strchr(token, '.') != NULL || strchr(token, '!') != NULL || strchr(token, '?') != NULL)  // check if current token is end of sentence
        {
            sentence_count++;

            if (sentence_count == 3)  // if three sentences already included in summary, break
            {
                break;
            }
            else  // if not, append period and add a space in summary
            {
                strcat(summary, ".");
                summary_index++;
                strcat(summary, " ");
                summary_index++;
            }
        }
        else  // if current token is not end of sentence, add a space in summary
        {
            strcat(summary, " ");
            summary_index++;
        }

        token = strtok(NULL, " ");  // get next token
    }

    strcat(summary, "...");  // add ellipsis at the end of summary
    return summary;
}