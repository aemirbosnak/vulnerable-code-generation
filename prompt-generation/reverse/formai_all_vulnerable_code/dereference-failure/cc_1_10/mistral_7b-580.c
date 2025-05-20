//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256
#define BUFFER_SIZE 1024

typedef struct char_count {
    char ch;
    int count;
} char_count;

void get_char_count(char *str, char_count *count_array, int array_size) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        int index = (int)(isalpha(str[i]) - 'a');
        if (index >= 0 && index < array_size)
            count_array[index].count++;
    }
}

void print_char_count(char_count *count_array, int array_size) {
    int i;
    for (i = 0; i < array_size; i++) {
        if (isalpha(count_array[i].ch))
            printf("%c : %d\n", count_array[i].ch, count_array[i].count);
    }
}

int main() {
    char input[BUFFER_SIZE];
    char *str;
    int input_length;

    printf("Enter a string : ");
    fgets(input, BUFFER_SIZE, stdin);

    str = strtok(input, " \n");
    input_length = strlen(str);

    char_count *char_count_array = (char_count *)calloc(MAX_CHAR, sizeof(char_count));

    get_char_count(str, char_count_array, MAX_CHAR);

    print_char_count(char_count_array, MAX_CHAR);

    free(char_count_array);

    return 0;
}