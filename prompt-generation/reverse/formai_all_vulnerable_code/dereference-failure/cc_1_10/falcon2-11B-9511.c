//Falcon2-11B DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

struct character_t {
    int length;
    int position;
    struct character_t *next;
};

void print_all(struct character_t *characters) {
    struct character_t *character = characters;

    while (character!= NULL) {
        printf("Position: %d, Length: %d\n", character->position, character->length);
        character = character->next;
    }
}

int string_length(char *string) {
    int length = 0;
    while (string[length]!= '\0') {
        length++;
    }
    return length;
}

int main() {
    struct character_t characters[100];

    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int characters_read = fread(characters, sizeof(struct character_t), 100, file);
    if (characters_read == 0) {
        printf("Error reading from file!\n");
        return 1;
    }

    struct character_t *character = characters;
    while (character!= NULL) {
        print_all(characters);
        character = character->next;
    }

    char command[10];
    printf("Enter a command: ");
    scanf("%s", command);

    if (strcmp(command, "q") == 0) {
        printf("Exiting...\n");
        return 0;
    }

    if (strcmp(command, "c") == 0) {
        printf("Hello World!\n");
        return 0;
    }

    printf("Invalid command!\n");
    print_all(characters);
}