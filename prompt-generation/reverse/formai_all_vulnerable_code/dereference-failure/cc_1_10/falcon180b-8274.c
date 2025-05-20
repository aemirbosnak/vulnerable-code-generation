//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define MAX_SIZE 1000000

typedef struct {
    char *data;
    int size;
} string;

void init(string *s) {
    s->data = (char *)malloc(MAX_SIZE*sizeof(char));
    s->size = 0;
}

void append(string *s, char c) {
    s->data[s->size] = c;
    s->size++;
}

void reverse(string *s) {
    int i = 0, j = s->size-1;
    char temp;
    while(i<j) {
        temp = s->data[i];
        s->data[i] = s->data[j];
        s->data[j] = temp;
        i++;
        j--;
    }
}

void print(string s) {
    int i;
    for(i=0;i<s.size;i++) {
        printf("%c",s.data[i]);
    }
}

int main() {
    string input, output;
    char c;
    init(&input);
    init(&output);
    printf("Enter the string to be compressed: ");
    while((c=getchar())!='\n') {
        append(&input,c);
    }
    input.size--;
    reverse(&input);
    int i,j;
    for(i=0,j=0;i<input.size;i++) {
        if(i==0 || input.data[i]!=input.data[i-1]) {
            append(&output,input.data[i]);
            j++;
        }
        if(j==input.size) break;
    }
    printf("Compressed string: ");
    print(output);
    printf("\n");
    return 0;
}