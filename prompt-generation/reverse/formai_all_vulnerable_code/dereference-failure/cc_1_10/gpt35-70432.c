//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char ch;
    int freq;
    struct node *left,*right;   
}node;

typedef struct heap
{
    int size;
    node **arr; 
}heap;

typedef struct table
{
    char ch;
    char *code; 
}table;

node* create_node(char ch,int freq)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->ch=ch;
    temp->freq=freq;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

heap* create_heap(int k)
{
    heap *temp=(heap*)malloc(sizeof(heap));
    temp->size=0;
    temp->arr=(node**)malloc(sizeof(node*)*k);
    return temp;
}

void swap(node **a,node **b)
{
    node *temp=*a;
    *a=*b;
    *b=temp;
}

void min_heapify(heap *Heap,int index)
{
    int parent=index;
    int left_child=2*parent+1;
    int right_child=2*parent+2;
    if(left_child<Heap->size && (Heap->arr[left_child]->freq)<(Heap->arr[parent]->freq))
        parent=left_child;
    if(right_child<Heap->size && (Heap->arr[right_child]->freq)<(Heap->arr[parent]->freq))
        parent=right_child;
    if(parent!=index)
    {
        swap(&Heap->arr[parent],&Heap->arr[index]);
        min_heapify(Heap,parent);
    }
}

int check_size_one(heap *Heap)
{
    return (Heap->size==1);
}

int is_leaf(node *root)
{
    return !(root->left) && !(root->right);
}

node* extract_min(heap *Heap)
{
    node *temp=Heap->arr[0];
    Heap->arr[0]=Heap->arr[Heap->size-1];
    Heap->size--;
    min_heapify(Heap,0);
    return temp;
}

void insert(heap *Heap,node *root)
{
    Heap->size++;
    int i=Heap->size-1;
    while(i && (root->freq)<(Heap->arr[(i-1)/2]->freq))
    {
        Heap->arr[i]=Heap->arr[(i-1)/2];
        i=(i-1)/2;
    }
    Heap->arr[i]=root;
}

heap* build_heap(char *ch_arr,int *freq_arr,int k)
{
    heap *Heap=create_heap(k);
    for(int i=0;i<k;i++)
        Heap->arr[i]=create_node(ch_arr[i],freq_arr[i]);
    Heap->size=k;
    for(int i=(Heap->size-1)/2;i>=0;i--)
        min_heapify(Heap,i);
    return Heap; 
}

node* build_tree(char *ch_arr,int *freq_arr,int k)
{
    node *left,*right,*top;
    heap *Heap=build_heap(ch_arr,freq_arr,k);
    while(!check_size_one(Heap))
    {
        left=extract_min(Heap);
        right=extract_min(Heap);
        top=create_node('$',left->freq+right->freq);
        top->left=left;
        top->right=right;
        insert(Heap,top);
    }
    return extract_min(Heap);
}

void assign_codes(node *root,char *arr,int top,table *Table,int *k)
{
    if(root->left)
    {
        arr[top]='0';
        assign_codes(root->left,arr,top+1,Table,k);
    }
    if(root->right)
    {
        arr[top]='1';
        assign_codes(root->right,arr,top+1,Table,k);
    }
    if(is_leaf(root))
    {
        Table[*k].ch=root->ch;
        Table[*k].code=(char*)malloc(sizeof(char)*(top+1));
        for(int i=0;i<top;i++)
            Table[*k].code[i]=arr[i];
        Table[*k].code[top]='\0';
        (*k)++;
    }
}

void print_table(table *Table,int k)
{
    printf("\nHuffman Code Table:\n");
    printf("--------------------\n");
    printf("Character\tCode\n");
    for(int i=0;i<k;i++)
        printf("%c\t\t%s\n",Table[i].ch,Table[i].code);
}

void encode_data(char *data,table *Table,int k)
{
    printf("\nEncoded Data:\n");
    printf("-------------\n");
    for(int i=0;i<strlen(data);i++)
    {
        for(int j=0;j<k;j++)
        {
            if(data[i]==Table[j].ch)
            {
                printf("%s",Table[j].code);
                break;
            }
        }
    }
    printf("\n");
}

int main()
{
    char ch_arr[]={'a','b','c','d','e','f'};
    int freq_arr[]={5,9,12,13,16,45};
    int k=sizeof(ch_arr)/sizeof(ch_arr[0]);
    node *root=build_tree(ch_arr,freq_arr,k);
    char arr[100];
    int top=0;
    table Table[100];
    int i=0;
    assign_codes(root,arr,top,Table,&i);
    print_table(Table,i);
    char data[100];
    printf("\nEnter data to be encoded:\n");
    scanf("%s",data);
    encode_data(data,Table,i);
    return 0;
}