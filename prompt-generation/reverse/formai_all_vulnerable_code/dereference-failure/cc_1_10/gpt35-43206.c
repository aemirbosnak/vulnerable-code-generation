//FormAI DATASET v1.0 Category: Text Summarizer ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SENTENCES 50
#define MAX_SENTENCE_LEN 200
#define MAX_WORD_LEN 20

int compare(const void *a, const void *b);
void remove_punctuations(char *string);
int count_words(char *string);
void to_lower_case(char *string);
int get_sentence_index(char *sentences[MAX_SENTENCES], char *sentence, int count);

int main()
{
    char document[5000];
    printf("Enter the document: ");
    fgets(document, sizeof(document), stdin);

    char *sentences[MAX_SENTENCES];
    int count = 0;

    char *sentence = strtok(document, ".\n");
    while (sentence != NULL && count < MAX_SENTENCES)
    {
        sentences[count] = sentence;
        sentence = strtok(NULL, ".\n");
        count++;
    }

    int scores[MAX_SENTENCES];
    for (int i = 0; i < count; i++)
    {
        remove_punctuations(sentences[i]);
        to_lower_case(sentences[i]);
        int word_count = count_words(sentences[i]);
        scores[i] = word_count;
    }

    int threshold = 0;
    for (int i = 0; i < count; i++)
    {
        int sentence_score = scores[i];
        if (sentence_score > threshold)
        {
            threshold = sentence_score;
        }
    }

    char summary[MAX_SENTENCES][MAX_SENTENCE_LEN];
    int summary_count = 0;

    for (int i = 0; i < count; i++)
    {
        int sentence_score = scores[i];
        if (sentence_score >= threshold / 2)
        {
            int duplicate_sentence = get_sentence_index((char **)summary, sentences[i], summary_count);
            if (duplicate_sentence == -1)
            {
                strcpy(summary[summary_count], sentences[i]);
                summary_count++;
            }
        }
    }

    qsort(summary, summary_count, MAX_SENTENCE_LEN*sizeof(char), compare);

    printf("\n\nThe summary of the document is:\n");

    for (int i = 0; i < summary_count; i++)
    {
        printf("%s. ", summary[i]);
    }

    return 0;
}

int compare(const void *a, const void *b)
{
    const char *string_a = *(const char **)a;
    const char *string_b = *(const char **)b;

    return strcmp(string_a, string_b);
}

void remove_punctuations(char *string)
{
    for (int i = 0, j = 0; i < strlen(string); i++)
    {
        if (ispunct(string[i]))
        {
            continue;
        }
        string[j] = string[i];
        j++;
    }
    string[strlen(string)] = '\0';
}

int count_words(char *string)
{
    int count = 0;
    char *word = strtok(string, " \t");
    while (word != NULL)
    {
        count++;
        word = strtok(NULL, " \t");
    }
    return count;
}

void to_lower_case(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        string[i] = tolower(string[i]);
    }
}

int get_sentence_index(char *sentences[MAX_SENTENCES], char *sentence, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(sentences[i], sentence) == 0)
        {
            return i;
        }
    }
    return -1;
}