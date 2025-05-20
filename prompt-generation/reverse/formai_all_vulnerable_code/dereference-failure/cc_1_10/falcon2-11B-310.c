//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

struct date {
    char* word;
    int days;
    struct date* next;
};

struct date* convert_date(struct date* date, int days) {
    if (date->word[0] == '\0') {
        return NULL;
    }
    if (strlen(date->word) == 1 && isalpha(date->word[0])) {
        int num = atoi(date->word);
        return convert_date(date->next, num + days);
    } else if (date->word[0] == 'y') {
        struct date* yesterday = malloc(sizeof(struct date));
        yesterday->word = "yesterday";
        yesterday->days = -1;
        yesterday->next = NULL;
        return yesterday;
    } else if (date->word[0] == 't') {
        struct date* tomorrow = malloc(sizeof(struct date));
        tomorrow->word = "tomorrow";
        tomorrow->days = 1;
        tomorrow->next = NULL;
        return tomorrow;
    } else if (date->word[0] == 't' && date->word[1] == 'o') {
        struct date* tomorrow = malloc(sizeof(struct date));
        tomorrow->word = "tomorrow";
        tomorrow->days = 1;
        tomorrow->next = NULL;
        return tomorrow;
    } else {
        struct date* tomorrow = malloc(sizeof(struct date));
        tomorrow->word = "tomorrow";
        tomorrow->days = 1;
        tomorrow->next = NULL;
        return tomorrow;
    }
}

int main() {
    struct date* date = convert_date(NULL, 0);
    printf("Unix timestamp for '%s': %d\n", date->word, date->days);
    return 0;
}