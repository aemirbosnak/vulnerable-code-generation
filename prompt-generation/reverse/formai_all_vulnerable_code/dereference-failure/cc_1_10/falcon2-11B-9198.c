//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file {
    char* name;
    char* data;
    struct file* next;
} file;

file* root = NULL;

void create_file(char* name, char* data) {
    file* new_file = (file*)malloc(sizeof(file));
    new_file->name = strdup(name);
    new_file->data = strdup(data);
    new_file->next = NULL;

    if (root == NULL) {
        root = new_file;
    } else {
        file* current = root;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_file;
    }
}

char* read_file(char* name) {
    file* current = root;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    create_file("love_letter.txt", "My dearest, I write to you today to express my deepest feelings for you.\n\nI never thought I would find someone who understands me the way you do. You bring joy and happiness to my life, and I am forever grateful for your presence.\n\nI love the way you laugh, the sound of your voice, and the way you look at me with those beautiful eyes. You are my everything, and I can't imagine life without you.\n\nI want to spend the rest of my days with you, cherishing every moment we share together. You are my soulmate, my partner in crime, and my best friend.\n\nForever and always, yours,\n[Your Name]");
    create_file("poem.txt", "Love is like a rose,\nSo pure and so divine,\nA beauty that never fades,\nA love that will always shine.\n\nYour smile is like the sun,\nWarm and bright, shining through,\nA light that guides me home,\nA love that I hold true.\n\nMy heart beats for you,\nA rhythm that is true,\nA love that will last forever,\nA love that I will always pursue.\n\nForever and always,\nYours, in love and passion,\n[Your Name]");
    create_file("song.txt", "I want to hold you close,\nAnd feel your love for me,\nA bond that will never end,\nA love that will set us free.\n\nOur hearts beat as one,\nA rhythm that is true,\nA love that will never die,\nA love that is forever new.\n\nI want to spend my life with you,\nA love that will never fade,\nA love that will forever be,\nA love that will never be swayed.\n\nForever and always,\nYours, in love and devotion,\n[Your Name]");

    char* love_letter = read_file("love_letter.txt");
    if (love_letter!= NULL) {
        printf("Here is your love letter:n%s\n", love_letter);
    } else {
        printf("No love letter found.\n");
    }

    char* poem = read_file("poem.txt");
    if (poem!= NULL) {
        printf("Here is your poem:n%s\n", poem);
    } else {
        printf("No poem found.\n");
    }

    char* song = read_file("song.txt");
    if (song!= NULL) {
        printf("Here is your song:n%s\n", song);
    } else {
        printf("No song found.\n");
    }

    return 0;
}