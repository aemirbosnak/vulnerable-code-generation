//FormAI DATASET v1.0 Category: HTML beautifier ; Style: automated
#include<stdio.h>
#include<string.h>

int indent_level = 0;
int is_newline = 0;

void print_spaces(int n) {
    for(int i=0; i<n; i++) {
        printf(" ");
    }
}

void beautify(char line[]) {
    int len = strlen(line);
    
    for(int i=0; i<len; i++) {
        
        char ch = line[i];
        
        if(ch == '<') {
            if(line[i+1] == '/') {
                indent_level--;
            }
            else if(line[i+1] != '!') {
                is_newline = 1;
                print_spaces(indent_level * 4);
                indent_level++;
            }
        }
        
        if(is_newline) {
            putchar(ch);
            putchar('\n');
            is_newline = 0;
        }
        else {
            putchar(ch);
        }
        
        if(ch == '>') {
            if(line[i-1] == '/') {
                indent_level--;
            }
            else if(line[i-1] == '?') {
                indent_level--;
            }
        }
    }
}

int main() {
    char line[100];
    
    while(fgets(line, sizeof(line), stdin)) {
        beautify(line);
    }
    
    return 0;
}