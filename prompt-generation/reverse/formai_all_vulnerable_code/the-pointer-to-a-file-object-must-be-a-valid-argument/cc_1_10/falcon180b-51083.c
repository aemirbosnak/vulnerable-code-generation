//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000

struct word_freq {
    char word[50];
    int freq;
};

void read_dict(struct word_freq dict[], int *size) {
    FILE *fp = fopen("dict.txt", "r");
    char line[100];
    int i = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        line[strcspn(line, "\n")] = '\0';
        strcpy(dict[i].word, line);
        i++;
    }

    fclose(fp);
    *size = i;
}

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void spell_check(char *word, struct word_freq dict[], int dict_size) {
    int i;
    char *correct_word = NULL;

    // Try exact match first
    for (i = 0; i < dict_size; i++) {
        if (strcmp(dict[i].word, word) == 0) {
            printf("%s is spelled correctly.\n", word);
            return;
        }
    }

    // Try fuzzy match
    qsort(dict, dict_size, sizeof(struct word_freq), compare_words);
    for (i = 0; i < dict_size; i++) {
        int j, k;
        int len1 = strlen(word);
        int len2 = strlen(dict[i].word);
        int distance = 0;

        if (len1 > len2) {
            continue;
        }

        for (j = 0; j < len1; j++) {
            for (k = 0; k < len2; k++) {
                if (tolower(word[j]) == tolower(dict[i].word[k])) {
                    distance++;
                }
            }
        }

        if (distance * 100 / len1 <= 80) {
            correct_word = dict[i].word;
            break;
        }
    }

    if (correct_word!= NULL) {
        printf("%s is a possible correction for %s.\n", correct_word, word);
    } else {
        printf("%s is not found in the dictionary.\n", word);
    }
}

int main() {
    struct word_freq dict[MAX_WORDS];
    int dict_size;

    read_dict(dict, &dict_size);

    char word[100];
    while (fgets(word, sizeof(word), stdin)!= NULL) {
        spell_check(word, dict, dict_size);
    }

    return 0;
}