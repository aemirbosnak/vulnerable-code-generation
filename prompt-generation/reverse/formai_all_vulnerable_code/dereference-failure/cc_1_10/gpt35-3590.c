//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_DIMENSION 8
#define BUFFER_SIZE 1024

char *ascii_art[ASCII_DIMENSION][ASCII_DIMENSION];

char *get_line(char *message, int length){
    char *line = malloc(length+1);
    printf("%s", message);
    fgets(line, length, stdin);
    strtok(line, "\n");
    return line;
}

void print_ascii(int dimension, char *message){
    int message_length = strlen(message);
    int skipped_rows = (ASCII_DIMENSION - dimension) / 2;
    int skipped_columns = (ASCII_DIMENSION - message_length) / 2;
    for(int i = 0; i < skipped_rows; i++){
        for(int j = 0; j < ASCII_DIMENSION; j++){
            printf("%s", ascii_art[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < skipped_columns; j++){
            printf("%s", ascii_art[skipped_rows+i][j]);
        }
        for(int j = 0; j < message_length; j++){
            printf("%s", ascii_art[skipped_rows+i][message[j] - ' ']);
        }
        for(int j = skipped_columns+message_length; j < ASCII_DIMENSION; j++){
            printf("%s", ascii_art[skipped_rows+i][j]);
        }
        printf("\n");
    }
    for(int i = skipped_rows+dimension; i < ASCII_DIMENSION; i++){
        for(int j = 0; j < ASCII_DIMENSION; j++){
            printf("%s", ascii_art[i][j]);
        }
        printf("\n");
    }
}

void load_ascii_art(){
    FILE *fp = fopen("ascii_art.txt", "r");
    if(fp == NULL){
        perror("Unable to open ascii_art.txt");
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    int row = 0;
    while(fgets(buffer, BUFFER_SIZE, fp)){
        char *token = strtok(buffer, "|");
        int column = 0;
        while(token){
            char *art_piece = malloc(strlen(token)+1);
            strcpy(art_piece, token);
            ascii_art[row][column] = art_piece;
            column++;
            token = strtok(NULL, "|");
        }
        row++;
    }
    fclose(fp);
}

int main(){
    load_ascii_art();
    char *name = get_line("Enter your name: ", 100);
    char *message = get_line("Enter a message: ", 100);
    printf("\n\n");
    print_ascii(strlen(message), message);
    free(name);
    free(message);
    for(int i = 0; i < ASCII_DIMENSION; i++){
        for(int j = 0; j < ASCII_DIMENSION; j++){
            free(ascii_art[i][j]);
        }
    }
    return 0;
}