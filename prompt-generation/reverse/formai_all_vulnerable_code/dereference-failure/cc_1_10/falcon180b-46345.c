//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 256
#define MAX_TREE_HEIGHT 100

typedef struct {
    int freq;
    char ch;
    struct treenode* left;
    struct treenode* right;
} treenode;

void init_freq(char text[], int freq[]) {
    int i;
    for(i = 0; i < MAX_CHARS; i++) {
        freq[i] = 0;
    }
    for(i = 0; text[i]; i++) {
        freq[text[i]]++;
    }
}

void build_tree(char text[], int freq[], treenode* tree, int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(freq[i]) {
            tree[i].freq = freq[i];
            tree[i].ch = i;
            tree[i].left = NULL;
            tree[i].right = NULL;
            build_tree(text, freq, tree[i].left, n);
            build_tree(text, freq, tree[i].right, n);
        }
        else {
            tree[i].freq = 0;
            tree[i].ch = '\0';
            tree[i].left = NULL;
            tree[i].right = NULL;
        }
    }
}

void encode(FILE* fp, char text[], treenode* tree) {
    int i;
    for(i = 0; text[i]; i++) {
        if(tree[text[i]].freq) {
            fputc(tree[text[i]].ch, fp);
        }
        else {
            fprintf(fp, "%c", text[i]);
        }
    }
}

int main() {
    char text[1000000];
    int freq[MAX_CHARS];
    treenode tree[MAX_TREE_HEIGHT];
    int n;
    FILE* input_file, *output_file;

    input_file = fopen("input.txt", "r");
    if(input_file == NULL) {
        printf("Error: Input file not found.\n");
        return 1;
    }

    output_file = fopen("output.txt", "w");
    if(output_file == NULL) {
        printf("Error: Could not create output file.\n");
        return 1;
    }

    n = 0;
    while(fscanf(input_file, "%c", &text[n])!= EOF) {
        n++;
    }
    fclose(input_file);

    init_freq(text, freq);

    build_tree(text, freq, tree, n);

    encode(output_file, text, tree);

    fclose(output_file);

    return 0;
}