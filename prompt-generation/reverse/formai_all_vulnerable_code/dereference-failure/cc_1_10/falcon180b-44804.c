//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 1000

struct trie{
    int count;
    struct trie *children[26];
};

struct trie *getnode(){
    struct trie *pnode=(struct trie *)malloc(sizeof(struct trie));
    pnode->count=0;
    int i;
    for(i=0;i<26;i++)
        pnode->children[i]=NULL;
    return pnode;
}

void insert(struct trie *root,char *word){
    struct trie *pnode=root;
    int len=strlen(word);
    int i;
    for(i=0;i<len;i++){
        if(isalpha(word[i])){
            if(pnode->children[tolower(word[i])-'a']==NULL)
                pnode->children[tolower(word[i])-'a']=getnode();
            pnode=pnode->children[tolower(word[i])-'a'];
        }
        else if(isdigit(word[i])){
            if(pnode->children[10+word[i]-'0']==NULL)
                pnode->children[10+word[i]-'0']=getnode();
            pnode=pnode->children[10+word[i]-'0'];
        }
        else{
            if(pnode->children[26]==NULL)
                pnode->children[26]=getnode();
            pnode=pnode->children[26];
        }
    }
    pnode->count++;
}

void printtrie(struct trie *root,char *prefix){
    struct trie *pnode=root;
    int i;
    for(i=0;i<26;i++){
        if(pnode->children[i]!=NULL){
            printf("%s%c ",prefix,i+'a');
            printtrie(pnode->children[i],prefix);
        }
    }
    if(pnode->count>0){
        printf("%s\n",prefix);
    }
}

int main(){
    int i,n,len;
    char word[MAX];
    struct trie *root=getnode();
    printf("Enter the number of words: ");
    scanf("%d",&n);
    printf("Enter the words:\n");
    for(i=0;i<n;i++){
        scanf("%s",word);
        insert(root,word);
    }
    printf("The trie is:\n");
    printtrie(root,"");
    return 0;
}