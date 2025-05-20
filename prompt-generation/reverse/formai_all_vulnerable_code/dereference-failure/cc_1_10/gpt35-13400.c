//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#define MAX_TREE_HT 100

// STRUCTURE OF A NODE
struct MinHeapNode{
    char data;
    unsigned freq;
    struct MinHeapNode *left,*right;
};

// STRUCTURE OF MINHEAP
struct MinHeap{
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

// CREATING A NEW NODE
struct MinHeapNode* newNode(char data,unsigned freq){
    struct MinHeapNode* temp=(struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left=temp->right=NULL;
    temp->data=data;
    temp->freq=freq;
    return temp;
}

// FUNCTION TO CREATE A NEW MINHEAP
struct MinHeap* createMinHeap(unsigned capacity){
    struct MinHeap* minHeap=(struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size=0;
    minHeap->capacity=capacity;
    minHeap->array=(struct MinHeapNode**)malloc(minHeap->capacity*sizeof(struct MinHeapNode*));
    return minHeap;
}

// FUNCTION TO SWAP TWO NODES
void swapMinHeapNode(struct MinHeapNode** a,struct MinHeapNode** b){
    struct MinHeapNode* temp=*a;
    *a=*b;
    *b=temp;
}

// FUNCTION TO HEAPIFY A SUBTREE
void minHeapify(struct MinHeap* minHeap,int idx){
    int smallest=idx;
    int left=2*idx+1;
    int right=2*idx+2;
    if(left<minHeap->size && minHeap->array[left]->freq<minHeap->array[smallest]->freq){
        smallest=left;
    }
    if(right<minHeap->size && minHeap->array[right]->freq<minHeap->array[smallest]->freq){
        smallest=right;
    }
    if(smallest!=idx){
        swapMinHeapNode(&minHeap->array[smallest],&minHeap->array[idx]);
        minHeapify(minHeap,smallest);
    }
}

// FUNCTION TO CHECK IF THE NODE IS LEAF NODE
int isLeafNode(struct MinHeapNode* root){
    return !(root->left) && !(root->right);
}

// FUNCTION TO CREATE A MINHEAP AND INSERT A NEW NODE
void insertMinHeap(struct MinHeap* minHeap,struct MinHeapNode* minHeapNode){
    ++minHeap->size;
    int i=minHeap->size-1;
    while(i && minHeapNode->freq < minHeap->array[(i-1)/2]->freq){
        minHeap->array[i]=minHeap->array[(i-1)/2];
        i=(i-1)/2;
    }
    minHeap->array[i]=minHeapNode;
}

// FUNCTION TO CREATE MINHEAP FROM GIVEN ARRAY OF NODES
struct MinHeap* createAndBuildMinHeap(char data[],int freq[],int size){
    struct MinHeap* minHeap=createMinHeap(size);
    for(int i=0;i<size;++i){
        minHeap->array[i]=newNode(data[i],freq[i]);
    }
    minHeap->size=size;
    for(int i=(minHeap->size-2)/2;i>=0;--i){
        minHeapify(minHeap,i);
    }
    return minHeap;
}

// FUNCTION TO EXTRACT THE MINIMUM VALUE NODE FROM MINHEAP
struct MinHeapNode* extractMin(struct MinHeap* minHeap){
    struct MinHeapNode* temp=minHeap->array[0];
    minHeap->array[0]=minHeap->array[minHeap->size-1];
    --minHeap->size;
    minHeapify(minHeap,0);
    return temp;
}

// FUNCTION TO BUILD HUFFMAN TREE
struct MinHeapNode* buildHuffmanTree(char data[],int freq[],int size){
    struct MinHeapNode *left,*right,*top;
    struct MinHeap* minHeap=createAndBuildMinHeap(data,freq,size);
    while(minHeap->size!=1){
        left=extractMin(minHeap);
        right=extractMin(minHeap);
        top=newNode('$',left->freq+right->freq);
        top->left=left;
        top->right=right;
        insertMinHeap(minHeap,top);
    }
    return extractMin(minHeap);
}

// FUNCTION TO PRINT VALUES FROM CODES ARRAY UP TO THE GIVEN NUMBER OF BITS
void printCodes(struct MinHeapNode* root,int arr[],int top){
    if(root->left){
        arr[top]=0;
        printCodes(root->left,arr,top+1);
    }
    if(root->right){
        arr[top]=1;
        printCodes(root->right,arr,top+1);
    }
    if(isLeafNode(root)){
        printf("%c: ",root->data);
        for(int i=0;i<top;++i){
            printf("%d",arr[i]);
        }
        printf("\n");
    }
}

// MAIN FUNCTION
int main(){
    char arr[]={'A','B','C','D','E','F'};
    int freq[]={5,9,12,13,16,45};
    int size=sizeof(arr)/sizeof(arr[0]);
    struct MinHeapNode* root=buildHuffmanTree(arr,freq,size);
    int arr1[MAX_TREE_HT],top=0;
    printCodes(root,arr1,top);
    return 0;
}