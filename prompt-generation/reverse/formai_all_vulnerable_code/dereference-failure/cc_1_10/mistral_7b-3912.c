//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AlienLanguage {
    char *name;
    char *symbol;
    int num_of_symbols;
} AlienLanguage;

void load_aliens(AlienLanguage **aliens, int *num_aliens, char *filename) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file: %s\n", filename);
        exit(1);
    }

    fscanf(fp, "%d", num_aliens);
    *aliens = (AlienLanguage *) calloc(*num_aliens, sizeof(AlienLanguage));

    for (int i = 0; i < *num_aliens; i++) {
        fscanf(fp, "%s %s %d", &((*aliens)[i].name), &((*aliens)[i].symbol), &((*aliens)[i].num_of_symbols));
    }

    fclose(fp);
}

int translate(char *input, AlienLanguage *aliens, int num_aliens) {
    int translation_length = 0;

    for (int i = 0; i < strlen(input); i++) {
        for (int j = 0; j < num_aliens; j++) {
            if (strchr(aliens[j].symbol, input[i]) != NULL) {
                printf("%s: %c -> %s\n", aliens[j].name, input[i], aliens[j].symbol);
                translation_length += aliens[j].num_of_symbols;
                for (int k = 0; k < aliens[j].num_of_symbols; k++) {
                    putchar(aliens[j].symbol[k]);
                }
                break;
            }
        }
    }

    return translation_length;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <filename> <input>\n", argv[0]);
        return 1;
    }

    AlienLanguage *aliens;
    int num_aliens;

    load_aliens(&aliens, &num_aliens, argv[1]);

    int input_length = strlen(argv[2]);
    int output_length = translate(argv[2], aliens, num_aliens);

    if (output_length > input_length) {
        printf("Translated text is larger than the input text. This is not possible.\n");
        return 1;
    }

    for (int i = input_length - 1; i >= 0 && i < output_length; i--) {
        putchar(argv[2][i]);
    }

    for (int i = output_length; i < strlen(argv[2]); i++) {
        putchar('_');
    }

    printf(" -> ");

    for (int i = 0; i < output_length; i++) {
        putchar(aliens[i % num_aliens].symbol[i / num_aliens]);
    }

    free(aliens);

    return 0;
}