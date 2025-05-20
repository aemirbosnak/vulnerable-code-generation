//FormAI DATASET v1.0 Category: File system simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int size;
    char* content;
} file;

typedef struct {
    file* files;
    int numOfFiles;
} directory;

directory rootDir;

void init(){
    rootDir.files = NULL;
    rootDir.numOfFiles = 0;
}

file* createFile(char* name, int size, char* content){
    file* f = (file*) malloc(sizeof(file));
    f->name = name;
    f->size = size;
    f->content = content;
    return f;
}

void addFile(directory* dir, file* f){
    dir->numOfFiles++;
    dir->files = (file*) realloc(dir->files, dir->numOfFiles * sizeof(file));
    dir->files[dir->numOfFiles-1] = *f;
}

void deleteFile(directory* dir, int index){
    if(index < dir->numOfFiles){
        for(int i = index; i < dir->numOfFiles-1; i++){
            dir->files[i] = dir->files[i+1];
        }
        dir->numOfFiles--;
        dir->files = (file*) realloc(dir->files, dir->numOfFiles * sizeof(file));
    }
}

int main(){
    printf("*** CYBERPUNK FILE SYSTEM SIMULATOR ***\n");

    init();

    printf("*** CREATING FILES ***\n");

    file* f1 = createFile("secret.txt", 32, "This is some secret data.");
    addFile(&rootDir, f1);

    file* f2 = createFile("music.mp3", 512, "This is some music.");
    addFile(&rootDir, f2);

    file* f3 = createFile("game.exe", 1024, "This is a game.");
    addFile(&rootDir, f3);

    printf("*** FILES CREATED ***\n");

    printf("*** LISTING FILES ***\n");
    for(int i = 0; i < rootDir.numOfFiles; i++){
        printf("%d. %s (size: %d bytes)\n", i+1, rootDir.files[i].name, rootDir.files[i].size);
    }

    printf("*** DELETING FILE 2 ***\n");
    deleteFile(&rootDir, 1);

    printf("*** NEW FILE LIST ***\n");
    for(int i = 0; i < rootDir.numOfFiles; i++){
        printf("%d. %s (size: %d bytes)\n", i+1, rootDir.files[i].name, rootDir.files[i].size);
    }

    printf("*** SHUTTING DOWN ***\n");
    return 0;
}