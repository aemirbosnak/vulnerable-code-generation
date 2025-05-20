//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FORTUNES 10
#define FORTUNE_LEN 140

// Structure to store fortune data
typedef struct {
    char fortune[FORTUNE_LEN];
} Fortune;

// Function to read fortune files and store them in an array
Fortune *read_fortunes(char *filename) {
    FILE *file;
    int i = 0;
    Fortune *fortunes = malloc(MAX_FORTUNES * sizeof(Fortune));

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open fortunes file.\n");
        exit(1);
    }

    while (fgets(fortunes[i].fortune, FORTUNE_LEN, file) != NULL && i < MAX_FORTUNES) {
        i++;
    }

    fclose(file);

    // Remove newline characters from fortunes
    for (int j = 0; j < i; j++) {
        size_t len = strlen(fortunes[j].fortune);
        if (fortunes[j].fortune[len - 1] == '\n') {
            fortunes[j].fortune[len - 1] = '\0';
        }
    }

    return fortunes;
}

// Function to select and print a random fortune
void print_fortune(Fortune *fortunes, int size) {
    srand(time(NULL));
    int index = rand() % size;

    printf("\n%s\n", fortunes[index].fortune);
}

int main() {
    char *filename = "fortunes.txt";
    Fortune *fortunes;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Your fortune awaits...\n\n");

    fortunes = read_fortunes(filename);
    print_fortune(fortunes, MAX_FORTUNES);

    free(fortunes);

    return 0;
}