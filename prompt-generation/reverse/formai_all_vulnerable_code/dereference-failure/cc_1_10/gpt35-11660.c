//FormAI DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_LINE_LEN 256

void checkSpelling(char *dictionaryFile, char *textFile);
int isWordInDictionary(char *word, char *dictionaryFile);
void toLowerCase(char *word);

int main()
{
    char dictionaryFile[MAX_LINE_LEN];
    char textFile[MAX_LINE_LEN];

    printf("Enter the name of the dictionary file: ");
    scanf("%s", dictionaryFile);

    printf("Enter the name of the text file to be checked: ");
    scanf("%s", textFile);

    checkSpelling(dictionaryFile, textFile);

    return 0;
}

void checkSpelling(char *dictionaryFile, char *textFile)
{
    FILE *dicFile;
    FILE *txtFile;
    char currWord[MAX_WORD_LEN];
    int lineNum = 1;
    int wordNum = 1;
    int errorsFound = 0;

    dicFile = fopen(dictionaryFile, "r");
    txtFile = fopen(textFile, "r");

    if (dicFile == NULL)
    {
        printf("Error opening dictionary file!\n");
        return;
    }

    if (txtFile == NULL)
    {
        printf("Error opening text file!\n");
        return;
    }

    printf("\nMisspelled Words:\n");
    printf("Line\tWord\tSuggestions\n");

    while (fgets(currWord, MAX_WORD_LEN, txtFile) != NULL)
    {
        toLowerCase(currWord);

        if (currWord[strlen(currWord) - 1] == '\n')
        {
            currWord[strlen(currWord) - 1] = '\0';
        }

        if (strcmp(currWord, "") == 0)
        {
            lineNum++;
            wordNum = 1;
            continue;
        }

        if (!isWordInDictionary(currWord, dictionaryFile))
        {
            printf("%d\t%d\t-", lineNum, wordNum);
            printf("%s\t[No Suggestions Found]\n", currWord);
            errorsFound++;
        }

        wordNum++;
    }

    if (errorsFound == 0)
    {
        printf("No spelling errors found!\n");
    }

    fclose(dicFile);
    fclose(txtFile);
}

int isWordInDictionary(char *word, char *dictionaryFile)
{
    FILE *dicFile;
    char currWord[MAX_WORD_LEN];

    dicFile = fopen(dictionaryFile, "r");

    if (dicFile == NULL)
    {
        printf("Error opening dictionary file!\n");
        return 0;
    }

    while (fgets(currWord, MAX_WORD_LEN, dicFile) != NULL)
    {
        toLowerCase(currWord);

        if (currWord[strlen(currWord) - 1] == '\n')
        {
            currWord[strlen(currWord) - 1] = '\0';
        }

        if (strcmp(currWord, word) == 0)
        {
            return 1;
        }
    }

    fclose(dicFile);

    return 0;
}

void toLowerCase(char *word)
{
    int i;

    for (i = 0; i < strlen(word); i++)
    {
        word[i] = tolower(word[i]);
    }
}