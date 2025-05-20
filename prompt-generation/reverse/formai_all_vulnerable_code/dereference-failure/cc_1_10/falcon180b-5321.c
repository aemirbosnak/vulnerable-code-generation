//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

char words[MAX_WORDS][MAX_WORD_LEN];
int num_words = 0;

void read_file(FILE *fp) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in file.\n");
            exit(1);
        }
        if (isalpha(ch)) {
            int len = 0;
            while (isalpha(ch)) {
                words[num_words][len++] = tolower(ch);
                ch = fgetc(fp);
            }
            words[num_words][len] = '\0';
            num_words++;
        } else if (isspace(ch)) {
            // ignore spaces
        } else {
            printf("Error: invalid character in file.\n");
            exit(1);
        }
    }
}

void process_words() {
    int i, j;
    for (i = 0; i < num_words; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char temp[MAX_WORD_LEN];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
}

void write_file(FILE *fp) {
    int i;
    for (i = 0; i < num_words; i++) {
        fprintf(fp, "%s\n", words[i]);
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: cannot open input file.\n");
        return 1;
    }
    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: cannot open output file.\n");
        fclose(input_file);
        return 1;
    }
    read_file(input_file);
    fclose(input_file);
    process_words();
    write_file(output_file);
    fclose(output_file);
    return 0;
}