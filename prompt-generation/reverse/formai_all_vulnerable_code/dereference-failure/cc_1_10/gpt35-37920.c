//FormAI DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define MAX_DIC_SIZE 10000
#define MAX_SUGGESTIONS_SIZE 5

typedef struct Node
{
    char word[MAX_WORD_SIZE];
    struct Node *next;
}Node;

Node *dictionary[MAX_DIC_SIZE];

char *stringToLower(char *str)
{
    char *ptr = str;
    while (*ptr != '\0')
    {
        *ptr = tolower(*ptr);
        ptr++;
    }
    return str;
}

Node *createNode(char *word)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

void insertIntoDictionary(char *word)
{
    int hash = (int) stringToLower(word)[0] % MAX_DIC_SIZE;

    if (dictionary[hash] == NULL)
        dictionary[hash] = createNode(word);
    else
    {
        Node *ptr = dictionary[hash];
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = createNode(word);
    }
}

void loadDictionary(char *filePath)
{
    FILE *fptr = fopen(filePath, "r");
    if (fptr == NULL)
    {
        printf("Error opening dictionary file!\n");
        exit(0);
    }

    char word[MAX_WORD_SIZE];
    while (fscanf(fptr, "%s", word) != EOF)
        insertIntoDictionary(word);

    fclose(fptr);
}

int isWordInDictionary(char *word)
{
    int hash = (int) stringToLower(word)[0] % MAX_DIC_SIZE;

    if (dictionary[hash] == NULL)
        return 0;
    else
    {
        Node *ptr = dictionary[hash];
        while (ptr != NULL)
        {
            if (strcmp(ptr->word, word) == 0)
                return 1;
            ptr = ptr->next;
        }
        return 0;
    }
}

int getWordSuggestions(char *word, char **suggestions)
{
    int hash = (int) stringToLower(word)[0] % MAX_DIC_SIZE;

    int suggestionsCount = 0;
    if (dictionary[hash] == NULL)
        return suggestionsCount;
    else
    {
        Node *ptr = dictionary[hash];
        while (ptr != NULL)
        {
            char *lowerPtrWord = stringToLower(ptr->word);
            char *lowerInputWord = stringToLower(word);

            int wordLen = strlen(ptr->word);
            int inputLen = strlen(word);

            if (wordLen == inputLen)
            {
                if (strcmp(lowerPtrWord, lowerInputWord) == 0)
                {
                    free(lowerPtrWord);
                    free(lowerInputWord);
                    return 0;
                }
            }

            if (abs(wordLen - inputLen) <= 1)
            {
                int i = 0, j = 0, diffCount = 0;
                while (i < wordLen && j < inputLen)
                {
                    if (lowerPtrWord[i] != lowerInputWord[j])
                    {
                        if (++diffCount > 1)
                            break;

                        if (wordLen > inputLen)
                            i++;
                        else if (wordLen < inputLen)
                            j++;
                        else
                        {
                            i++;
                            j++;
                        }
                    }
                    else
                    {
                        i++;
                        j++;
                    }
                }

                if (diffCount <= 1)
                    suggestions[suggestionsCount++] = ptr->word;
            }

            free(lowerPtrWord);
            free(lowerInputWord);

            if (suggestionsCount == MAX_SUGGESTIONS_SIZE)
                break;

            ptr = ptr->next;
        }
        return suggestionsCount;
    }
}

void printSuggestions(char **suggestions, int count)
{
    printf("Did you mean:\n");
    for (int i = 0; i < count; i++)
        printf("%d. %s\n", i + 1, suggestions[i]);
}

void checkSpelling(char *filePath)
{
    FILE *fptr = fopen(filePath, "r");
    if (fptr == NULL)
    {
        printf("Error opening input file!\n");
        exit(0);
    }

    char word[MAX_WORD_SIZE];
    while (fscanf(fptr, "%s", word) != EOF)
    {
        if (!isWordInDictionary(word))
        {
            char *suggestions[MAX_SUGGESTIONS_SIZE];
            int count = getWordSuggestions(word, suggestions);

            if (count == 0)
                printf("%s\n", word);
            else
                printSuggestions(suggestions, count);
        }
    }

    fclose(fptr);
}

int main()
{
    printf("Loading dictionary...\n");
    loadDictionary("dictionary.txt");
    printf("Dictionary loaded successfully!\n");

    printf("Checking spelling...\n");
    checkSpelling("input.txt");
    printf("Spelling check completed!\n");

    return 0;
}