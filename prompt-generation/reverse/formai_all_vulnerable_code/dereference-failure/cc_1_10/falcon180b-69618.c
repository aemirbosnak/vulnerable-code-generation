//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX_CODES 4096

typedef struct {
    char ch;
    int freq;
    int code;
} node;

void build_tree(node *tree, int n) {
    int i, j;
    node *left, *right;
    for (i = 0; i < n; i++) {
        if (tree[i].freq > 0) {
            left = tree + 2 * n - 1;
            right = left + 1;
            tree[i].code = 0;
            while (left->freq > 0) {
                if (left->freq < tree[i].freq) {
                    break;
                }
                tree[i].code = (tree[i].code << 1) | 1;
                left--;
            }
            while (right->freq > 0) {
                if (right->freq < tree[i].freq) {
                    break;
                }
                tree[i].code = (tree[i].code << 1) | 2;
                right++;
            }
            tree[i].code = (tree[i].code << 1) | 1;
            tree[i + n] = *left;
            tree[i + n + 1] = *right;
        }
    }
}

void encode(node *tree, char *str, FILE *fp) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        j = 0;
        while (tree[j].ch!= str[i]) {
            j = (j << 1) | 1;
        }
        fputc(tree[j].code, fp);
    }
}

void decode(node *tree, FILE *fp) {
    int code, i;
    while ((code = fgetc(fp))!= EOF) {
        i = 0;
        while (tree[i].code!= code) {
            i = (i << 1) | 1;
        }
        printf("%c", tree[i].ch);
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    char *filename = argv[1];
    node tree[MAX_CHARS + MAX_CODES];
    int i, n;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    n = 0;
    while ((i = fgetc(fp))!= EOF) {
        if (n >= MAX_CHARS) {
            printf("Too many characters.\n");
            fclose(fp);
            return 1;
        }
        if (i >= 0 && i <= 127) {
            tree[n].ch = i;
            tree[n].freq = 1;
        } else {
            printf("Invalid character.\n");
            fclose(fp);
            return 1;
        }
        n++;
    }
    fclose(fp);

    build_tree(tree, n);

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error creating output file.\n");
        return 1;
    }

    encode(tree, "", fp);

    fclose(fp);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    decode(tree, fp);

    fclose(fp);

    return 0;
}