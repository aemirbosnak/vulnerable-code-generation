//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#define MAX_STRING_LENGTH 100

void translate_to_cat_language(char* english_sentence, char* cat_sentence);

int main()
{
    char english_sentence[MAX_STRING_LENGTH], cat_sentence[MAX_STRING_LENGTH];
    printf("Enter a sentence in English to translate into Cat language:\n");
    fgets(english_sentence, MAX_STRING_LENGTH, stdin);
    english_sentence[strcspn(english_sentence, "\n")] = 0; //removes trailing newline character
    translate_to_cat_language(english_sentence, cat_sentence);
    printf("The sentence in Cat language is: %s\n", cat_sentence);
    return 0;
}

void translate_to_cat_language(char* english_sentence, char* cat_sentence)
{
    char cat_word[MAX_STRING_LENGTH], cat_verb[MAX_STRING_LENGTH];
    int sentence_length = strlen(english_sentence);
    int cat_word_index = 0, current_word_length = 0, last_whitespace = 0;
    for(int i = 0; i < sentence_length; i++)
    {
        if(english_sentence[i] == ' ')
        {
            current_word_length = i - last_whitespace;
            strncpy(cat_word, &english_sentence[last_whitespace], current_word_length);
            cat_word[current_word_length] = '\0';
            cat_word_index = 0;
            if(i+1 < sentence_length && english_sentence[i+1] == 'v')
            {
                strncpy(cat_verb, &english_sentence[i+3], 2);
                cat_verb[2] = '\0';
                strcat(cat_sentence, cat_verb);
            }
            strcat(cat_sentence, cat_word);
            strcat(cat_sentence, " ");
            last_whitespace = i+1;   
        }
        else if(i == sentence_length-1)
        {
            current_word_length = i - last_whitespace + 1;
            strncpy(cat_word, &english_sentence[last_whitespace], current_word_length);
            cat_word[current_word_length] = '\0';
            if(english_sentence[i-1] == 'v')
            {
                strncpy(cat_verb, &english_sentence[i+1], 2);
                cat_verb[2] = '\0';
                strcat(cat_sentence, cat_verb);
            }
            strcat(cat_sentence, cat_word);
            strcat(cat_sentence, " ");
        }
        else if(i > 0 && english_sentence[i-1] == ' ' && english_sentence[i] == 'v' && english_sentence[i+1] == ' ')
        {
            strncpy(cat_verb, &english_sentence[i+2], 2);
            cat_verb[2] = '\0';
            strcat(cat_sentence, cat_verb);
        }
        else if(i > 0 && english_sentence[i-1] == 'v' && english_sentence[i] == ' ' && english_sentence[i+1] != ' ')
        {
            strncpy(cat_word, &english_sentence[i+1], 1);
            cat_word[1] = '\0';
            strcat(cat_sentence, cat_word);
        }
    }
}