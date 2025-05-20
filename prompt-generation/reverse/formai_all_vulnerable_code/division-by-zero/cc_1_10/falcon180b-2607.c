//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LENGTH 1000000
#define MAX_KEY_LENGTH 100
#define MIN_KEY_LENGTH 4

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
} Key;

void generate_key(char *key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = toupper(rand() % 26 + 'A');
    }
    key[length] = '\0';
}

int get_key_length() {
    int length = rand() % (MAX_KEY_LENGTH - MIN_KEY_LENGTH + 1) + MIN_KEY_LENGTH;
    printf("Enter the length of the key (minimum %d): ", MIN_KEY_LENGTH);
    scanf("%d", &length);
    return length;
}

void encrypt_file(char *input_file, char *output_file, Key *key) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");

    if (input == NULL || output == NULL) {
        printf("Error opening file(s).\n");
        exit(1);
    }

    int key_index = 0;
    char line[MAX_LENGTH];

    while (fgets(line, MAX_LENGTH, input)!= NULL) {
        for (int i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                line[i] = line[i] + key_index;
                if (line[i] > 'Z') {
                    line[i] = line[i] - 26;
                }
            }
        }
        fputs(line, output);
        key_index = (key_index + 1) % key->key_length;
    }

    fclose(input);
    fclose(output);
}

int main() {
    Key key;
    generate_key(key.key, get_key_length());

    printf("Enter the input file name: ");
    scanf("%s", key.key);

    printf("Enter the output file name: ");
    scanf("%s", key.key);

    encrypt_file(key.key, key.key, &key);

    printf("File encrypted successfully!\n");

    return 0;
}