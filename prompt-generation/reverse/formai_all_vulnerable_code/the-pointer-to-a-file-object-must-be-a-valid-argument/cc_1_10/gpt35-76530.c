//FormAI DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input_text[1000], dictionary_text[1000];
    int i, j, found, flag = 0;
    
    printf("Please enter the text to check for spelling error:\n");
    fgets(input_text, sizeof(input_text), stdin);

    printf("\nThe following words contain spelling errors:\n");
    
    // convert input text to lowercase
    for(i = 0; input_text[i] != '\0'; i++)
    {
        input_text[i] = tolower(input_text[i]);
    }

    // read from dictionary file
    FILE *fp;
    fp = fopen("dictionary.txt", "r");

    // check each word in the input text
    char* word;
    word = strtok(input_text, " ,\n");

    while(word != NULL)
    {
        found = 0;
        while(fgets(dictionary_text, sizeof(dictionary_text), fp) != NULL)
        {
            // convert dictionary word to lowercase
            for(i = 0; dictionary_text[i] != '\0'; i++)
            {
                dictionary_text[i] = tolower(dictionary_text[i]);
            }
            
            if(strcmp(word, dictionary_text) == 0)
            {
                found = 1;
                break;
            }
        }
        
        // check if word was found in dictionary
        if(!found)
        {
            flag = 1;
            printf("%s\n", word);
        }

        // reset file pointer
        fseek(fp, 0, SEEK_SET);
        word = strtok(NULL, " ,\n");
    }

    // check if no spelling errors were found
    if(!flag)
    {
        printf("No spelling errors found.\n");
    }
    
    // close file
    fclose(fp);

    return 0;
}