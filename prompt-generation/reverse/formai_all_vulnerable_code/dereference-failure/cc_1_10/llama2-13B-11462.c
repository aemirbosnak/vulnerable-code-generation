//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

// Medieval-style string manipulation functions

void knight_split(char *str, char **words) {
    int i, j;
    char *token;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            token = str + i;
            j = i;
            while (str[j] != ' ' && str[j] != '\0') {
                j++;
            }
            *words = realloc(*words, (j - i) + 1);
            strcpy(*words, token);
            *words += j - i;
        }
    }
}

void dragon_concatenate(char *str1, char *str2, char *str3) {
    int i, j;
    char *temp;

    temp = malloc(strlen(str1) + strlen(str2) + strlen(str3) + 1);
    for (i = 0; str1[i] != '\0'; i++) {
        temp[i] = str1[i];
    }
    for (j = 0; str2[j] != '\0'; j++) {
        temp[i + j] = str2[j];
    }
    for (; str3[j] != '\0'; j++) {
        temp[i + j + strlen(str2)] = str3[j];
    }
    strcpy(str1, temp);
}

int king_length(char *str) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            break;
        }
    }
    return i;
}

int knight_compare(char *str1, char *str2) {
    int i, j;

    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char str1[] = "Fair knight, thou art brave and true!";
    char str2[] = "Thy loyal squire, Sir Reginald, doth bear a message for thee.";
    char str3[] = "Hail, good sir! What news dost thou bring?";
    char *words1, *words2, *words3;

    knight_split(str1, &words1);
    knight_split(str2, &words2);
    knight_split(str3, &words3);

    dragon_concatenate(words1, words2, words3);

    king_length(words1);

    if (knight_compare(words1, words2)) {
        printf("The two strings are not equal.\n");
    } else {
        printf("The two strings are equal.\n");
    }

    return 0;
}