//FormAI DATASET v1.0 Category: Spell checking ; Style: safe
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function to convert the given string to lowercase
void toLowerCase(char *str)
{
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i]=str[i]+32;
    }
}

// Function to check if a given character is an alphabet or not
int isAlphabet(char ch)
{
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        return 1;
    else
        return 0;
}

// Function to check the spelling of a given word
int spellCheck(char *word, char **dictionary, int dictSize)
{
    int i, j, flag;
    char *temp=(char*)malloc(sizeof(char)*strlen(word));

    // Converting the given word to lowercase
    strcpy(temp, word);
    toLowerCase(temp);

    // Check if the word is present in the dictionary
    for(i=0;i<dictSize;i++)
    {
        if(strcmp(temp, dictionary[i])==0)
            return 1;
    }

    // If the word is not found in the dictionary,
    // check if it is a valid word by checking if it consists
    // of only alphabets
    flag=1;
    for(i=0;i<strlen(word);i++)
    {
        if(!isAlphabet(word[i]))
        {
            flag=0;
            break;
        }
    }
    if(flag==0)
        return 0;

    // If the word is a valid word, check for spelling errors
    // by comparing it with the words in the dictionary
    for(i=0;i<dictSize;i++)
    {
        if(strlen(temp)==strlen(dictionary[i]))
        {
            flag=1;
            for(j=0;j<strlen(temp);j++)
            {
                if(temp[j]!=dictionary[i][j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                return 2;
        }
    }
    return 0;
}

// Driver function
int main()
{
    char *dictionary[]={"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "jackfruit", "kiwi", "lemon", "mango", "nectarine", "orange", "peach", "quince", "raspberry", "strawberry", "tangerine", "watermelon"};
    int dictSize=20;
    char word[50];
    int status;

    printf("Enter a word: ");
    scanf("%s", word);

    // Call the spellCheck function to check the spelling of the word
    status=spellCheck(word, dictionary, dictSize);

    if(status==1)
        printf("\nThe word is spelled correctly.\n");
    else if(status==2)
        printf("\nDid you mean %s?\n", word);
    else
        printf("\nThe word is misspelled.\n");

    return 0;
}