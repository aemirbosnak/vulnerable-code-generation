//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// A struct to represent a node in Huffman Tree
struct node{
    char data;
    int freq;
    struct node* left,*right;
};

// A Min Heap node
struct minHeapNode{
    char data;
    int freq;
    struct minHeapNode* left,*right;
};

// A Min Heap:    
struct minHeap{
    int size;
    int capacity;
    struct minHeapNode** array;
};

// A function to create a new node in Huffman Tree
struct node* newNode(char data, int freq){
    struct node* temp=(struct node*) malloc(sizeof(struct node));
    temp->left=temp->right=NULL;
    temp->data=data;
    temp->freq=freq;
    return temp;
}

// A function to create a new Min Heap Node
struct minHeapNode* newMinHeapNode(char data, int freq){
    struct minHeapNode* temp=(struct minHeapNode*) malloc(sizeof(struct minHeapNode));
    temp->left=temp->right=NULL;
    temp->data=data;
    temp->freq=freq;
    return temp;
}

// A function to create a new Min Heap
struct minHeap* createMinHeap(int capacity){
    struct minHeap* temp=(struct minHeap*) malloc(sizeof(struct minHeap));
    temp->size=0;
    temp->capacity=capacity;
    temp->array=(struct minHeapNode**) malloc(sizeof(struct minHeapNode*));
    return temp;
}

// A function to swap two Min Heap Nodes
void swapMinHeapNode(struct minHeapNode** a, struct minHeapNode** b){
    struct minHeapNode* temp= *a;
    *a=*b;
    *b=temp;
}

// A function to heapify min heap
void minHeapify(struct minHeap* minHeap, int idx){
    int smallest=idx;
    int left=2*idx+1;
    int right=2*idx+2;

    if(left<minHeap->size && minHeap->array[left]->freq
          < minHeap->array[smallest]->freq)
        smallest=left;

    if(right<minHeap->size && minHeap->array[right]->freq<
           minHeap->array[smallest]->freq)
        smallest=right;

    if(smallest!=idx){
        swapMinHeapNode(&minHeap->array[smallest],&minHeap->array[idx]);
        minHeapify(minHeap,smallest);
    }
}

// A function to check if the given min heap is size 1 or not
int isSizeOne(struct minHeap* minHeap){
    return minHeap->size==1;
}

// A function to extract minimum value node from heap
struct minHeapNode* extractMin(struct minHeap* minHeap){
    struct minHeapNode* temp=minHeap->array[0];
    minHeap->array[0]=minHeap->array[minHeap->size-1];

    --minHeap->size;
    minHeapify(minHeap,0);

    return temp;
}

// A function to insert a new min heap node
void insertMinHeap(struct minHeap* minHeap, struct minHeapNode* temp){
    ++minHeap->size;
    int i=minHeap->size-1;

    while(i && temp->freq<minHeap->array[(i-1)/2]->freq){
        minHeap->array[i]=minHeap->array[(i-1)/2];
        i=(i-1)/2;
    }
    minHeap->array[i]=temp;
}

// Building Huffman Tree
struct minHeapNode* buildHuffmanTree(char* data, int* freq, int size){
    struct minHeapNode *left,*right,*top;

    struct minHeap* minHeap=createMinHeap(size);

    for(int i=0;i<size;++i)
        insertMinHeap(minHeap,newMinHeapNode(data[i],freq[i]));

    while(!isSizeOne(minHeap)){
        left=extractMin(minHeap);
        right=extractMin(minHeap);

        top=newMinHeapNode('$',left->freq+right->freq);

        top->left=left;
        top->right=right;

        insertMinHeap(minHeap,top);
    }

    return extractMin(minHeap);
}

// A function to print Huffman Codes from the root of Huffman Tree
void printCodes(struct node* root, int arr[], int top){
    // Assign value of 0 to left edge
    if(root->left){
        arr[top]=0;
        printCodes(root->left,arr,top+1);
    }

    // Assign value of 1 to right edge
    if(root->right){
        arr[top]=1;
        printCodes(root->right,arr,top+1);
    }

    // Print the character and its code from leaf node
    if(root->left==NULL && root->right==NULL){
        printf("%c: ",root->data);
        for(int i=0;i<top;++i)
            printf("%d",arr[i]);
        printf("\n");
    }
}

int main(){
    printf("Welcome to Huffman Fun Time\n");
    printf("Give me some text to Huffman Code: ");
    char text[1000];
    scanf("%[^\n]s",text);
    getchar(); // to handle unwanted newline character

    int n=strlen(text);
    char data[n];
    int freq[n];
    int arr[n];

    for(int i=0;i<n;++i)
        freq[i]=0;

    int count=0;
    for(int i=0;i<n;++i){
        int flag=1; 
        
        for(int j=0;j<count;++j){
            if(text[i]==data[j]){
                ++freq[j];
                flag=0;
            }
        }
        if(flag){
            data[count]=text[i];
            freq[count]=1;
            ++count;
        }
    }

    struct minHeapNode* root = buildHuffmanTree(data,freq,count);

    printf("\nHuffman Codes are:\n");
    printCodes(root,arr,0);

    return 0;
}