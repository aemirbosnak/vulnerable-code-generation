//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct node Node;

struct node
{
    char data;
    int freq;
    Node *left, *right;
};

typedef struct MinHeap MinHeap;

struct MinHeap
{
    int size;
    Node** array;
};

MinHeap* createMinHeap(int capacity)
{
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));

    minHeap->size = 0;

    minHeap->array = (Node**)malloc(capacity * sizeof(Node*));

    return minHeap;
}

Node* newNode(char data, int freq)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;

    return node;
}

void swap(Node** a, Node** b)
{
    Node* t = *a;
    *a = *b;
    *b = t;
}

void heapify(MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx)
    {
        swap(&minHeap->array[smallest], &minHeap->array[idx]);
        heapify(minHeap, smallest);
    }
}

int isSizeOne(MinHeap* minHeap)
{
    return (minHeap->size == 1);
}

Node* extractMin(MinHeap* minHeap)
{
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    heapify(minHeap, 0);

    return temp;
}

void insertMinHeap(MinHeap* minHeap, Node* node)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = node;
}

void buildMinHeap(MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        heapify(minHeap, i);
}

int isLeaf(Node* root)
{
    return !(root->left) && !(root->right);
}

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

Node* HuffmanCoding(char data[], int freq[], int size)
{
    Node *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printCodes(Node* root, int arr[], int top, char input[], int freq[], double entropy, double compression)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, input, freq, entropy, compression);
    }

    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, input, freq, entropy, compression);
    }

    if (isLeaf(root))
    {
        int i = 0;
        while (input[i] != root->data && input[i]!='\0') 
            i++;

        printf("%c\t", root->data);
        for (int j = 0; j < top; j++)
            printf("%d", arr[j]);

        int k = 0;
        while (input[k] != '\0')
        {
            if (input[k] == root->data)
            {
                if (root->data == 32 || root->data == 9 || root->data == 10)
                    compression = compression + ((top) * freq[i]);
                else
                    compression = compression + ((top + 1) * freq[i]);

                entropy = entropy - freq[i] * log2(freq[i]);
                freq[i] = -1;
            }
            k++;
        }

        printf("\n");
    }
}

void HuffmanCodes(char input[], int freq[], int size)
{
    Node* root = HuffmanCoding(input, freq, size);

    double entropy = 0, compression = 0, total_freq = 0, one_word_freq = 0;
    int arr[MAX_TREE_HT], top = 0;

    for (int i = 0; i < size; i++)
    {
        if (freq[i] != -1)
        {
            if (input[i] == 32 || input[i] == 9 || input[i] == 10)
                total_freq += freq[i] * top;
            else
                total_freq += freq[i] * (top + 1);

            one_word_freq =  ((double)freq[i]);
        }
    }

    entropy = log2(size);

    printCodes(root, arr, top, input, freq, entropy, compression);

    printf("\n");
    printf("Total Frequency: %.0lf bits\n", total_freq);
    printf("Entropy: %.2lf bits\n", entropy);
    printf("Compression Ratio: %.2lf %%\n", ((total_freq / entropy) * 100));
    printf("Average Length of Codewords: %.2lf bits\n", total_freq / one_word_freq);
}

int main()
{
    char input[] = "HUFFMAN CODING";
    int freq[] = { 2, 2, 1, 3, 1, 1, 1, 2, 1, 1, 1 };

    int size = sizeof(input) / sizeof(input[0]);

    HuffmanCodes(input, freq, size);

    return 0;
}