//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 256

typedef struct {
    char symbol;
    int freq;
} Symbol;

void build_tree(Symbol *tree, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        tree[i].freq += tree[i - 1].freq;
    }
    for (i = n - 1; i >= 0; i--) {
        j = (int) ((double) tree[i].freq * 256.0 / tree[n - 1].freq);
        tree[i].freq = (unsigned char) j;
        tree[i].symbol = (char) (i + 'A');
    }
}

void encode(Symbol *tree, int n, FILE *out) {
    int i;
    for (i = 0; i < n; i++) {
        fprintf(out, "%c %d\n", tree[i].symbol, tree[i].freq);
    }
}

void decode(Symbol *tree, int n, FILE *in) {
    int i, j;
    char c;
    unsigned char freq;
    for (i = 0; i < n; i++) {
        freq = 0;
        while (fscanf(in, "%c %d\n", &c, &j) == 2) {
            if (c == tree[i].symbol) {
                freq = j;
                break;
            }
        }
        tree[i].freq = freq;
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);
    FILE *in = fopen(filename, "r");
    if (in == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    char c;
    int n = 0;
    while ((c = fgetc(in))!= EOF) {
        if (c >= 'A' && c <= 'Z') {
            n++;
        }
    }
    rewind(in);
    Symbol *tree = (Symbol *) malloc(n * sizeof(Symbol));
    if (tree == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
    build_tree(tree, n);
    encode(tree, n, stdout);
    printf("\n");
    fclose(in);
    in = fopen(filename, "r");
    if (in == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    decode(tree, n, in);
    fclose(in);
    free(tree);
    return 0;
}