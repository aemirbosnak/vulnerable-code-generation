//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CHAR 256

struct trie_node{
    int count;
    struct trie_node* children[MAX_CHAR];
};

void create_trie(struct trie_node** root){
    *root = (struct trie_node*)malloc(sizeof(struct trie_node));
    (*root)->count = 0;
    for(int i=0;i<MAX_CHAR;i++){
        (*root)->children[i] = NULL;
    }
}

void insert_word(struct trie_node* root, char* word){
    struct trie_node* current = root;
    int len = strlen(word);
    for(int i=0;i<len;i++){
        int index = word[i];
        if(current->children[index] == NULL){
            current->children[index] = (struct trie_node*)malloc(sizeof(struct trie_node));
        }
        current = current->children[index];
    }
    current->count++;
}

void print_trie(struct trie_node* root, char* prefix){
    if(root->count > 0){
        printf("%s %d\n", prefix, root->count);
    }
    for(int i=0;i<MAX_CHAR;i++){
        if(root->children[i]!= NULL){
            char next_char = (char)i;
            print_trie(root->children[i], (char*)malloc(strlen(prefix)+2));
            free(next_char);
        }
    }
}

void delete_trie(struct trie_node* root){
    for(int i=0;i<MAX_CHAR;i++){
        if(root->children[i]!= NULL){
            delete_trie(root->children[i]);
        }
    }
    free(root);
}

int main(){
    struct trie_node* root = NULL;
    create_trie(&root);

    char word[100];
    while(scanf("%s", word)!= EOF){
        insert_word(root, word);
    }

    printf("Trie:\n");
    print_trie(root, "");

    delete_trie(root);

    return 0;
}