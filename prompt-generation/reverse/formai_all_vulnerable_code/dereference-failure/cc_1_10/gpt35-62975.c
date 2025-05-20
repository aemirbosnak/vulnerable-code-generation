//FormAI DATASET v1.0 Category: Compression algorithms ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ASCII_LENGTH 128

typedef struct {
    int freq;
    char symbol;
    char *code;
} char_info;

int compare_freq(const void *a, const void *b) {
    const char_info *ia = (char_info *)a;
    const char_info *ib = (char_info *)b;
    return (ib->freq - ia->freq);
}

void update_code(char_info *table, int index, char *code) {
    for(int i=0; i<index; i++) {
        if(strstr(table[i].code,code)==table[i].code) {
            table[index].code = strcat(table[i].code,code);
            break;
        }
    }
}

void build_huffman_tree(char_info *table, int n) {
    for(int i=n; i>1; i--) {
        qsort(table,i,sizeof(char_info),compare_freq);
        update_code(table,i-2,"0");
        update_code(table,i-1,"1");
        table[i-2].freq = table[i-1].freq + table[i-2].freq;
    }
}

void build_table(char_info *table, char *text) {
    for(int i=0; i<ASCII_LENGTH; i++) {
        table[i].symbol = (char)i;
        table[i].freq = 0;
        table[i].code = (char*)malloc(sizeof(char));
        table[i].code[0] = '\0';
    }
    int len = strlen(text);
    for(int i=0; i<len; i++) {
        table[(int)text[i]].freq++;
    }
    build_huffman_tree(table,ASCII_LENGTH);
}

void encode(char_info *table, char *text, char *code) {
    int len = strlen(text);
    for(int i=0; i<len; i++) {
        for(int j=0; j<ASCII_LENGTH; j++) {
            if(table[j].symbol == text[i]) {
                strcat(code,table[j].code);
                break;
            }
        }
    }
}

void decode(char_info *table, char *code, char *text) {
    int len = 0;
    int n = strlen(code);
    for(int i=0; i<n; i++) {
        char tmp[10];
        memcpy(tmp,code+i,1);
        tmp[1] = '\0';
        for(int j=0; j<ASCII_LENGTH; j++) {
            if(!strcmp(table[j].code,tmp)) {
                text[len++] = table[j].symbol;
                break;
            }
        }
    }
    text[len] = '\0';
}

int main() {
    char_info table[ASCII_LENGTH];
    char text[500];
    char code[500];
    char decode_text[500];
    printf("Enter the text: ");
    scanf("%[^\n]",text);
    build_table(table,text);
    encode(table,text,code);
    printf("Encoding of text: %s\n",code);
    decode(table,code,decode_text);
    printf("Decoding of text: %s",decode_text);
    return 0;
}