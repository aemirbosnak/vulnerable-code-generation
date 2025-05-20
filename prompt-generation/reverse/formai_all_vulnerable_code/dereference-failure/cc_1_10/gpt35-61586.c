//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ASCII_SIZE 256

typedef struct Node
{
    int freq;
    struct Node* left;
    struct Node* right;
}Node;

//To create a new node in the Huffman Tree
Node* createNode(int freq,Node* left,Node* right)
{
    Node* node=malloc(sizeof(Node));
    node->freq=freq;
    node->left=left;
    node->right=right;
    return node;
}

//Heap Structure for Huffman coding
typedef struct Heap
{
    Node** arr;
    int count;
}Heap;

//To create a new heap
Heap* createHeap(int capacity)
{
    Heap* heap=malloc(sizeof(Heap));
    heap->arr=malloc(sizeof(Node*)*capacity);
    heap->count=0;
    return heap;
}

//Swaps the values within the heap
void swap(Node** a,Node** b)
{
    Node* temp=*a;
    *a=*b;
    *b=temp;
}

//To maintain heap order in the Huffman encoding tree
void heapify(Heap* heap,int index)
{
    int smallest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<heap->count&&heap->arr[left]->freq<heap->arr[smallest]->freq)
        smallest=left;

    if(right<heap->count&&heap->arr[right]->freq<heap->arr[smallest]->freq)
        smallest=right;

    if(smallest!=index)
    {
        swap(&heap->arr[index],&heap->arr[smallest]);
        heapify(heap,smallest);
    }
}

//To return the minimum value from the heap
Node* getMin(Heap* heap)
{
    Node* min=heap->arr[0];
    heap->arr[0]=heap->arr[heap->count-1];
    heap->count--;
    heapify(heap,0);
    return min;
}

//To insert a new node into the Heap
void insert(Heap* heap,Node* node)
{
    int i=heap->count;

    heap->count++;

    while(i&&node->freq<heap->arr[(i-1)/2]->freq)
    {
        heap->arr[i]=heap->arr[(i-1)/2];
        i=(i-1)/2;
    }

    heap->arr[i]=node;
}

//To check if the heap contains only one tree
int isSizeOne(Heap* heap)
{
    return heap->count==1;
}

//To build the Huffman Tree using the heap priority queue
Node* buildHuffmanTree(char data[],int freq[],int size)
{
    Node *left,*right,*top;

    Heap* heap=createHeap(size);

    for(int i=0;i<size;i++)
    {
        insert(heap,createNode(freq[i],NULL,NULL));
    }

    while(!isSizeOne(heap))
    {
        left=getMin(heap);
        right=getMin(heap);

        top=createNode(left->freq+right->freq,left,right);

        insert(heap,top);
    }

    return getMin(heap);
}

//To print the Huffman codes for the given Huffman tree
void printCodes(Node* root,int arr[],int top)
{
    if(root->left)
    {
        arr[top]=0;
        printCodes(root->left,arr,top+1);
    }

    if(root->right)
    {
        arr[top]=1;
        printCodes(root->right,arr,top+1);
    }

    if(!root->left&&!root->right)
    {
        printf("%c: ",root->freq);
        for(int i=0;i<top;i++)
        {
            printf("%d",arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    char data[ASCII_SIZE];
    int freq[ASCII_SIZE];
    int n;
    printf("Enter the number of characters: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the character: ");
        fflush(stdin);
        scanf("%c",&data[i]);
        printf("Enter the frequency of the character: ");
        scanf("%d",&freq[i]);
    }
    Node* root=buildHuffmanTree(data,freq,n);

    int arr[ASCII_SIZE],top=0;

    printCodes(root,arr,top);

    return 0;
}