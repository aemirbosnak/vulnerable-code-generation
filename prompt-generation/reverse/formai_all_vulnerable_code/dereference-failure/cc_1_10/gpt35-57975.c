//FormAI DATASET v1.0 Category: HTML beautifier ; Style: distributed
#include <stdio.h>
#include <ctype.h>

void beautify(FILE *infp, FILE *outfp) {

    int ch, i, spaces = 0;

    while ((ch = fgetc(infp)) != EOF) {

        if (ch == '<') {
            i = 0;

            do {
                ch = fgetc(infp);
                if (isspace(ch)) {
                    spaces++;
                }
            } while (ch != '>' && ch != EOF);

            fprintf(outfp, "<");
            if (isspace(getc(infp)) && spaces > 0) {
                fprintf(outfp, "\n");
                for (i = 0; i < spaces; i++) {
                    fprintf(outfp, " ");
                }
            }
            fprintf(outfp, "%c\n", ch);

            spaces = 0;

        } else if (isspace(ch)) {
            spaces++;

        } else {
            fprintf(outfp,"%c", ch);
            spaces = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *infp, *outfp;

    if (argc == 1) {
        infp = stdin;
        outfp = stdout;

    } else if (argc == 2) {
        infp = fopen(argv[1], "r");
        outfp = stdout;

    } else {
        infp = fopen(argv[1], "r");
        outfp = fopen(argv[2], "w");
    }

    if (infp == NULL) {
        fprintf(stderr, "Error: cannot read from input file %s.\n", argv[1]);
        return 1;
    }

    if (outfp == NULL) {
        fprintf(stderr, "Error: cannot write to output file %s.\n", argv[2]);
        return 1;
    }

    beautify(infp, outfp);

    fclose(infp);
    fclose(outfp);

    return 0;
}