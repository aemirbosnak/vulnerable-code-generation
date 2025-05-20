//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define MAX_CODE_LEN 100

typedef struct node{
    char ch;
    int freq;
    int code[MAX_CODE_LEN];
}node;

void encode(FILE* fp, node* root){
    int i=0;
    fprintf(fp,"%d ",root->freq);
    for(i=0;i<root->freq;i++){
        fprintf(fp,"%d ",root->code[i]);
    }
    fprintf(fp,"\n");
}

void decode(FILE* fp, node* root){
    int i=0,j=0;
    int code=0;
    char ch;
    while((ch=fgetc(fp))!=EOF){
        if(ch=='0'){
            code=0;
        }
        else{
            code=code*2+ch-'0';
            if(code>root->freq){
                printf("Error in decoding\n");
                exit(0);
            }
            for(i=MAX_CODE_LEN-1;i>=0;i--){
                if((code>>i)&1){
                    printf("%c",root->code[j]);
                    j++;
                    break;
                }
            }
        }
    }
}

node* create_node(char ch){
    node* new_node=(node*)malloc(sizeof(node));
    new_node->ch=ch;
    new_node->freq=1;
    new_node->code[0]=0;
    return new_node;
}

node* build_tree(FILE* fp){
    node* root=create_node('$');
    node* curr_node=root;
    int i=0;
    char ch;
    while((ch=fgetc(fp))!=EOF){
        if(ch=='\n'){
            curr_node->freq++;
        }
        else if(ch!=' '){
            node* new_node=create_node(ch);
            curr_node->code[i]=0;
            curr_node->freq++;
            curr_node->code[i]='1';
            curr_node=new_node;
        }
        i++;
    }
    return root;
}

int main(){
    FILE* fp;
    fp=fopen("input.txt","r");
    if(fp==NULL){
        printf("Error in opening file\n");
        exit(0);
    }
    node* root=build_tree(fp);
    fclose(fp);
    fp=fopen("output.txt","w");
    encode(fp,root);
    fclose(fp);
    fp=fopen("output.txt","r");
    decode(fp,root);
    fclose(fp);
    return 0;
}