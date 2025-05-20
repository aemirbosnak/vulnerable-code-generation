//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100000

struct node{
    int data;
    int freq;
    struct node* next;
};

struct node* create_node(int data, int freq){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->freq = freq;
    new_node->next = NULL;
    return new_node;
}

struct node* create_table(){
    struct node* table = (struct node*)malloc(sizeof(struct node)*MAX);
    int i;
    for(i=0;i<MAX;i++){
        table[i].data = -1;
        table[i].freq = 0;
        table[i].next = NULL;
    }
    return table;
}

void add_node(struct node* table, int data, int freq){
    int index = data%MAX;
    struct node* new_node = create_node(data, freq);
    new_node->next = table[index].next;
    table[index].next = new_node;
    table[index].freq++;
}

void encode(struct node* table, int data, char* output){
    int index = data%MAX;
    while(table[index].next!=NULL){
        if(table[index].next->data==data){
            strcat(output,"0");
            data = table[index].next->data;
        }
        else{
            strcat(output,"1");
            data = table[index].next->data;
        }
        index = data%MAX;
    }
    strcat(output,"0");
}

void decode(struct node* table, char* input){
    int data = 0, index = 0;
    while(input[index]!='\0'){
        if(input[index]=='0'){
            data = table[data%MAX].next->data;
        }
        else{
            data = table[data%MAX].next->data;
        }
        index++;
    }
    printf("%d\n", data);
}

int main(){
    struct node* table = create_table();
    char input[MAX];
    int i;
    for(i=0;i<5;i++){
        printf("Enter input string: ");
        scanf("%s", input);
        int j;
        for(j=0;j<strlen(input);j++){
            add_node(table, input[j], 1);
        }
    }
    printf("Enter input string to encode: ");
    scanf("%s", input);
    char output[MAX];
    encode(table, input[0], output);
    printf("%s\n", output);
    printf("Enter input string to decode: ");
    scanf("%s", input);
    decode(table, input);
    return 0;
}