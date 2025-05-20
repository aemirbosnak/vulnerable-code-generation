//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_GUESS 100
#define MAX_FILE_SIZE 1024

// Structure to hold the file contents and the guesses
typedef struct {
    char *file_contents;
    int guesses;
} file_data;

// Function to open and read the file
file_data* read_file(const char *file_name) {
    file_data *data = malloc(sizeof(file_data));
    data->file_contents = NULL;
    data->guesses = 0;

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char buffer[1024];
    while (fgets(buffer, 1024, file) != NULL) {
        data->file_contents = realloc(data->file_contents, strlen(data->file_contents) + strlen(buffer) + 1);
        strcat(data->file_contents, buffer);
    }

    fclose(file);
    return data;
}

// Function to write the file
void write_file(const char *file_name, file_data *data) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fputs(data->file_contents, file);
    fclose(file);
}

// Function to play the game
void play_game(const char *file_name) {
    file_data *data = read_file(file_name);
    if (data == NULL) {
        printf("Error reading file\n");
        return;
    }

    int guess = 0;
    char guess_char;
    do {
        printf("Guess a character in the file %s:\n", file_name);
        scanf("%c", &guess_char);

        int index = strcspn(data->file_contents, &guess_char);
        if (index == -1) {
            printf("The character %c does not appear in the file\n", guess_char);
        } else {
            printf("You guessed %c, the correct index is %d\n", guess_char, index);
        }

        guess++;
    } while (guess < MAX_GUESS);

    printf("You guessed %d times\n", guess);
    write_file(file_name, data);
}

int main() {
    srand(time(NULL));

    const char *file_name = "genius_file.txt";
    file_data *data = read_file(file_name);
    if (data == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    play_game(file_name);

    return 0;
}