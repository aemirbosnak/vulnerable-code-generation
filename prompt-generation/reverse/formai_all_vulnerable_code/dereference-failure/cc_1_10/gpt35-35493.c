//FormAI DATASET v1.0 Category: HTML beautifier ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

//structure to hold the file content and its length
typedef struct FileContent {
    char* content;
    long length;
} FileContent;

//function to read the contents of the file
void readFile(char* filename, FileContent* file) {
    FILE* fp = fopen(filename, "r");
    fseek(fp, 0L, SEEK_END);
    file->length = ftell(fp);
    rewind(fp);
    file->content = malloc(file->length+1);
    fread(file->content, file->length, 1, fp);
    file->content[file->length] = '\0';
    fclose(fp);
}

//function to beautify the HTML content
void* beautifyHtml(void* ptr) {
    FileContent* file = (FileContent*)ptr;
    char* content = file->content;
    long length = file->length;

    int indentation_level = 0;
    char* beautified_content = malloc(length*2); //assuming the beautified content would be twice the size of the original content
    int pos = 0;
    for(int i=0; i<length; i++) {
        char c = content[i];
        if(c == '<') {
            beautified_content[pos++] = '\n';
            for(int j=0; j<indentation_level; j++)
                beautified_content[pos++] = '\t';
            beautified_content[pos++] = c;
            if(content[i+1] == '/') //closing tag
                indentation_level--;
            else
                indentation_level++;
        }
        else if(c == '>')
            beautified_content[pos++] = c;
        else
            beautified_content[pos++] = c;
    }
    beautified_content[pos] = '\0';
    file->content = beautified_content;
}

int main() {
    FileContent file;
    char* filename = "index.html"; //assuming the filename is index.html
    readFile(filename, &file);

    pthread_t tid;
    pthread_create(&tid, NULL, beautifyHtml, &file);
    pthread_join(tid, NULL); //wait for the thread to complete its task

    printf("%s", file.content);
    free(file.content);
    return 0;
}