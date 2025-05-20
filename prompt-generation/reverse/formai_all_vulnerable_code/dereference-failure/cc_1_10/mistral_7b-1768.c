//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

void remove_sorry(char *line) {
    char *word, *save_ptr;
    size_t len = strlen(line);

    word = strtok_r(line, " ", &save_ptr);
    while (word != NULL) {
        if (strcmp(word, "sorry") == 0) {
            size_t pos = strcspn(line, word);
            memmove(line + pos, word + len, strlen(line + pos) - pos);
            len -= (strlen(word) + pos);
        }
        word = strtok_r(NULL, " ", &save_ptr);
    }
}

int main(int argc, char **argv) {
    FILE *fp_in, *fp_out;
    char buf[BUF_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    fp_in = fopen(argv[1], "r");
    if (fp_in == NULL) {
        perror("Error opening input file");
        return 1;
    }

    fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) {
        perror("Error opening output file");
        fclose(fp_in);
        return 1;
    }

    while (fgets(buf, BUF_SIZE, fp_in) != NULL) {
        remove_sorry(buf);
        fputs(buf, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}