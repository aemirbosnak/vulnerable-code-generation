//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: retro
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int freq;
    char data;
    struct node *left,*right;
};

struct node* getNode(int freq, char data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->freq=freq;
    newNode->data=data;
    return newNode;
}

void display(struct node *root,char *str,int charfreq[256]){

    if(root==NULL)
        return;
    if(root->data!='\0'){
        charfreq[root->data]=root->freq;
        printf("%c - %d\n",root->data,root->freq);
    }

    display(root->left,strcat(str,"0"),charfreq);
    str[strlen(str)-1]='\0';

    display(root->right,strcat(str,"1"),charfreq);
    str[strlen(str)-1]='\0';
}

void insertInHeap(struct node** heap,struct node* newNode,int* heapSize){

    *heapSize=*heapSize+1;
    heap[*heapSize-1]=newNode;
    int i=*heapSize-1;
    while(i!=0 && heap[(i-1)/2]->freq > heap[i]->freq){
        struct node* temp=heap[i];
        heap[i]=heap[(i-1)/2];
        heap[(i-1)/2]=temp;
        i=(i-1)/2;
     }
}

struct node* extractMinFromHeap(struct node** heap,int* heapSize){

      struct node* min=heap[0];
      heap[0]=heap[*heapSize-1];
      *heapSize=*heapSize-1;

      int i=0;
      while((2*i +2)<*heapSize){
          int minIndex=(heap[2*i +1]->freq < heap[2*i+2]->freq)?2*i+1:2*i+2;

          if(heap[i]->freq > heap[minIndex]->freq){
              struct node* temp=heap[i];
              heap[i]=heap[minIndex];
              heap[minIndex]=temp;
              i=minIndex;
          }
          else
              break;
      }

      if((2*i+1)==*heapSize-1 &&heap[i]->freq > heap[2*i+1]->freq ){

          struct node* temp=heap[i];
          heap[i]=heap[2*i+1];
          heap[2*i+1]=temp;
      }
      return min;
}

struct node* buildHuffmanTree(char* inputStr){


    int freq[256];
    memset(freq,0,sizeof(freq));

    int n=strlen(inputStr);
    for(int i=0;i<n;i++){
        char ch=inputStr[i];
        freq[ch]++;
    }

    struct node **heap=(struct node**)malloc(sizeof(struct node*)*n);
    int heapSize=0;
    for(int i=0;i<256;i++){
        if(freq[i]!=0){
            struct node* newNode=getNode(freq[i],i);
            insertInHeap(heap,newNode,&heapSize);
        }
    }

    while(heapSize!=1){
        struct node* left=extractMinFromHeap(heap,&heapSize);
        struct node* right=extractMinFromHeap(heap,&heapSize);

        int sum=left->freq + right->freq;
        struct node* newNode=getNode(sum,'\0');

        newNode->left=left;
        newNode->right=right;
        insertInHeap(heap,newNode,&heapSize);
    }
    return heap[0];
}

int main(){

    char inputStr[1000];
    printf("Enter a string : ");
    scanf("%[^\n]%*c",inputStr);

    struct node* root=buildHuffmanTree(inputStr);
    int charfreq[256];
    memset(charfreq,0,sizeof(charfreq));
    char str[1000];
    display(root,str,charfreq);

    return 0;
}