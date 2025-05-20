//FormAI DATASET v1.0 Category: Spell checking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

/* Define a linked list for dictionary entries */
typedef struct Dictionary {
    char word[20];
    struct Dictionary* next;
} dictionary;

/* Define function prototypes */
void parseDictionary(FILE* dict, dictionary** head);
void checkSpelling(FILE* text, dictionary* head);

int main() {
    FILE* dictionaryFile;
    FILE* textFile;

    /* Open dictionary and text files */
    dictionaryFile = fopen("medieval_dict.txt", "r");
    textFile = fopen("sir_lancelot.txt", "r");

    /* Ensure files were opened successfully */
    if (!dictionaryFile || !textFile) {
        printf("Error opening file(s).\n");
        return 1;
    }

    /* Parse dictionary file and create linked list */
    dictionary* dictHead = NULL;
    parseDictionary(dictionaryFile, &dictHead);

    /* Check spelling of text file */
    checkSpelling(textFile, dictHead);

    /* Close files and free allocated memory */
    fclose(dictionaryFile);
    fclose(textFile);
    while (dictHead != NULL) {
        dictionary* temp = dictHead;
        dictHead = dictHead->next;
        free(temp);
    }

    return 0;
}

/* Function to parse dictionary and create linked list */
void parseDictionary(FILE* dict, dictionary** head) {
    char buffer[20];
    dictionary* current = *head;
    dictionary* new;

    while (fgets(buffer, sizeof(buffer), dict)) {
        /* Remove newline character */
        buffer[strcspn(buffer, "\n")] = '\0';

        /* Create new node and copy word from buffer */
        new = (dictionary*)malloc(sizeof(dictionary));
        strcpy(new->word, buffer);
        new->next = NULL;

        /* Add node to list */
        if (*head == NULL) {
            /* This is the first node */
            *head = new;
            current = *head;
        }
        else {
            /* Add node to end of list */
            current->next = new;
            current = current->next;
        }
    }
}

/* Function to check spelling of text file */
void checkSpelling(FILE* text, dictionary* head) {
    char buffer[20];
    int lineNum = 1;
    int wordNum = 1;

    printf("Methinks thy errorneous words doth offend mine eyes!\n\n");

    while (fgets(buffer, sizeof(buffer), text)) {
        char* token = strtok(buffer, " ");

        while (token != NULL) {
            /* Remove any leading/trailing punctuation marks */
            int len = strlen(token);
            if (ispunct(token[0])) {
                memmove(token, token+1, len);
                len--;
            }
            if (ispunct(token[len-1])) {
                token[len-1] = '\0';
                len--;
            }

            /* Convert word to lowercase */
            for (int i = 0; i < len; i++) {
                token[i] = tolower(token[i]);
            }

            /* Search for word in dictionary */
            dictionary* current = head;
            int found = 0;
            while (current != NULL) {
                if (strcmp(token, current->word) == 0) {
                    found = 1;
                    break;
                }
                current = current->next;
            }

            /* Print error message if word not found */
            if (!found) {
                printf("ERROR: Line %d, Word %d - \"%s\" is not a valid word!\n", lineNum, wordNum, token);
            }

            /* Get next token */
            token = strtok(NULL, " ");
            wordNum++;
        }

        /* Reset word count and increment line count */
        wordNum = 1;
        lineNum++;
    }

    printf("\nThat is all, fair sir/madam!\n");
}