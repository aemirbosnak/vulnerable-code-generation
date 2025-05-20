//FormAI DATASET v1.0 Category: Image compression ; Style: inquisitive
#include <stdio.h>
#include <string.h>

struct Node {
    unsigned char c;
    int freq;
    int parent;
    int left;
    int right;
};

void frequency(char *text, int len, int *freq) {
    int i;
    for (i = 0; i < len; i++) {
        freq[(unsigned char)text[i]]++;
    }
}

void find_min_two(struct Node *tree, int num_nodes, int *min1, int *min2) {
    int i;
    *min1 = -1;
    *min2 = -1;
    for (i = 0; i < num_nodes; i++) {
        if (tree[i].parent == -1) {
            if (*min1 == -1 || tree[i].freq < tree[*min1].freq) {
                *min2 = *min1;
                *min1 = i;
            } else if (*min2 == -1 || tree[i].freq < tree[*min2].freq) {
                *min2 = i;
            }
        }
    }
}

int create_tree(struct Node *tree, int *freq) {
    int i, num_nodes = 256, next_node = 256;
    for (i = 0; i < num_nodes; i++) {
        tree[i].c = (unsigned char)i;
        tree[i].freq = freq[i];
        tree[i].parent = -1;
        tree[i].left = -1;
        tree[i].right = -1;
    }
    while (1) {
        int min1, min2;
        find_min_two(tree, next_node, &min1, &min2);
        if (min2 == -1) {
            break;
        }
        tree[next_node].freq = tree[min1].freq + tree[min2].freq;
        tree[next_node].left = min1;
        tree[next_node].right = min2;
        tree[min1].parent = next_node;
        tree[min2].parent = next_node;
        next_node++;
    }
    return next_node;
}

void encode(char *text, int len, struct Node *tree, char *out, int max_out) {
    int stack[256], top = 0;
    int i, n = create_tree(tree, NULL), node = n - 1;
    for (i = 0; i < len; i++) {
        int c = (unsigned char)text[i];
        while (tree[node].c != c) {
            if (tree[node].left != -1) {
                stack[top++] = 0;
                node = tree[node].left;
            } else {
                stack[top++] = 1;
                node = tree[node].right;
            }
        }
        while (top > 0) {
            out[i*2] = out[i*2] * 2 + stack[--top];
        }
        out[i*2+1] = 0;
    }
    if (max_out > len*2+1) {
        out[len*2+1] = 255;
    } else {
        out[max_out-1] = 255;
    }
}

void decode(char *text, int len, struct Node *tree, char *out, int max_out) {
    int i;
    int n = create_tree(tree, NULL), node = n - 1;
    for (i = 0; i < len; i++) {
        int c = (unsigned char)text[i];
        int j;
        for (j = 0; j < 8; j++) {
            if (c & 0x80) {
                node = tree[node].right;
            } else {
                node = tree[node].left;
            }
            c <<= 1;
            if (tree[node].left == -1) {
                if (max_out > 0) {
                    *out++ = tree[node].c;
                    max_out--;
                }
                node = n - 1;
            }
        }
    }
}

int main() {
    char text[] = "This is a test message to see if our compression algorithm works.";
    int freq[256];
    memset(freq, 0, sizeof(freq));
    frequency(text, strlen(text), freq);

    struct Node tree[512];
    char out[1024];
    memset(out, 0, sizeof(out));
    encode(text, strlen(text), tree, out, sizeof(out));

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    decode(out, strlen(text)*2+1, tree, buffer, sizeof(buffer));

    printf("Original: %s\n", text);
    printf("Compressed: %s\n", out);
    printf("Decompressed: %s\n", buffer);

    return 0;
}