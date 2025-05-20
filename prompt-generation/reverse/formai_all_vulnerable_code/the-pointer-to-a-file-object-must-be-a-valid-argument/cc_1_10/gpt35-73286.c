//FormAI DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_DICT_SIZE 5000

int read_dictionary(char *filename, char dictionary[][MAX_WORD_SIZE]);
void remove_trailing_newline(char *s);
void to_lower(char *s);
void spell_check(char *filename, char dictionary[][MAX_WORD_SIZE], int dict_size);

int main()
{
    char dictionary[MAX_DICT_SIZE][MAX_WORD_SIZE];
    int dict_size = read_dictionary("dictionary.txt", dictionary);
    
    char filename[MAX_WORD_SIZE];
    printf("Enter file name to spell check: ");
    scanf("%s", filename);
    
    spell_check(filename, dictionary, dict_size);
    
    return 0;
}

int read_dictionary(char *filename, char dictionary[][MAX_WORD_SIZE])
{
    FILE *fp = fopen(filename, "r");
    int i = 0;
    
    while (fgets(dictionary[i], MAX_WORD_SIZE, fp) != NULL) {
        remove_trailing_newline(dictionary[i]);
        to_lower(dictionary[i]);
        i++;
    }
    
    fclose(fp);
    return i;
}

void remove_trailing_newline(char *s)
{
    if (s[strlen(s) - 1] == '\n') {
        s[strlen(s) - 1] = '\0';
    }
}

void to_lower(char *s)
{
    int i;
    for (i = 0; s[i]; i++) {
        s[i] = tolower(s[i]);
    }
}

void spell_check(char *filename, char dictionary[][MAX_WORD_SIZE], int dict_size)
{
    FILE *fp = fopen(filename, "r");
    char current_word[MAX_WORD_SIZE];
    int line_number = 1;
    
    while (fscanf(fp, "%s", current_word) != EOF) {
        remove_trailing_newline(current_word);
        to_lower(current_word);
        
        int found = 0;
        int i;
        for (i = 0; i < dict_size; i++) {
            if (strcmp(current_word, dictionary[i]) == 0) {
                found = 1;
                break;
            }
        }
        
        if (!found) {
            printf("Misspelled word \"%s\" found on line %d\n", current_word, line_number);
        }
        
        if (strchr(current_word, '\n') != NULL) {
            line_number++;
        }
    }
    
    fclose(fp);
}