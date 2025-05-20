//FormAI DATASET v1.0 Category: Spell checking ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 26
#define MAX_LEN 100
 
struct tnode{
    int isEnd;
    struct tnode* children[SIZE];
};

typedef struct tnode tnode;

tnode* createTrieNode(){
    tnode* tn = (tnode*)malloc(sizeof(tnode));
    tn->isEnd = 0;
    for(int i=0;i<SIZE;i++) tn->children[i] = NULL;
    return tn;
}

void insertWord(tnode* root, char* w){
    tnode* tn = root;
    int idx;
    for(int i=0;i<strlen(w);i++){
        idx = w[i] - 'a';
        if(tn->children[idx] == NULL)
            tn->children[idx] = createTrieNode();
        tn = tn->children[idx];
    }
    tn->isEnd = 1;
}

int isWord(tnode* root, char* w){
    tnode* tn = root;
    int idx;
    for(int i=0;i<strlen(w);i++){
        idx = w[i] - 'a';
        if(tn->children[idx] == NULL) return 0;
        tn = tn->children[idx];
    }
    if(tn != NULL && tn->isEnd == 1) return 1;
    return 0;
}

int checkSpell(tnode* root, char* w){
    if(isWord(root, w)) return 1;
    return 0;
}

void checkAndPrint(tnode* root, char* w){
    if(!checkSpell(root, w)){
        printf("Word '%s' is mis-spelled\n", w);
        printf("Suggestions: ");
        for(int i=0;i<strlen(w);i++){
            char* temp = (char*)malloc(sizeof(char)*MAX_LEN);
            strcpy(temp, w);
            for(int j=0;j<SIZE;j++){
                temp[i] = j+'a';
                if(checkSpell(root, temp))
                    printf("%s ", temp);
            }
        }
        printf("\n");
    }
}

int main(){
    FILE* fp = fopen("dictionary.txt", "r");
    char word[MAX_LEN];
    tnode* root = createTrieNode();
    while(fscanf(fp, "%s", word) != EOF)
        insertWord(root, word);
    fclose(fp);
    char testWord[MAX_LEN];
    printf("Enter word to spell-check (-1 to exit): ");
    scanf("%s", testWord);
    while(strcmp(testWord, "-1")!=0){
        checkAndPrint(root, testWord);
        printf("\nEnter word to spell-check (-1 to exit): ");
        scanf("%s", testWord);
    }
    return 0;
}