//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_FORTUNES 10
#define MAX_FORTUNE_LEN 80

char *fortunes[NUM_FORTUNES];

void init_fortunes(void) {
    char fortune_str[MAX_FORTUNE_LEN];
    FILE *fp;

    fp = fopen("fortunes.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open fortunes file.\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fgets(fortune_str, MAX_FORTUNE_LEN, fp) != NULL) {
        fortunes[i] = malloc(strlen(fortune_str) + 1);
        strcpy(fortunes[i], fortune_str);
        i++;
    }

    fclose(fp);
}

int get_random_fortune_index(void) {
    return rand() % NUM_FORTUNES;
}

void print_fortune(char *fortune) {
    printf("\n%s\n", fortune);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    init_fortunes();

    int i;
    for (i = 0; i < 3; i++) {
        int index = get_random_fortune_index();
        print_fortune(fortunes[index]);
    }

    for (i = 0; i < NUM_FORTUNES; i++) {
        free(fortunes[i]);
    }

    return EXIT_SUCCESS;
}