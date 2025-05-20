//FormAI DATASET v1.0 Category: File Encyptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 128

void encrypt(char[], char[], char[]);
void decrypt(char[], char[], char[]);
int generate_key(char[]);
int check_file(FILE*);

int main(){
    char key[KEY_LENGTH];
    char input_file[100];
    char output_file[100];

    int choice = 0;
    int key_length = 0;

    printf("Welcome to the C File Encryptor/Decryptor!\n\n");

    while(1){
        printf("Please make a selection:\n");
        printf("1) Encrypt a file\n");
        printf("2) Decrypt a file\n");
        printf("3) Exit\n");

        scanf("%d", &choice);

        if(choice == 1){
            printf("Please enter the name of the input file:\n");
            scanf("%s", input_file);

            printf("Please enter the name of the output file:\n");
            scanf("%s", output_file);

            key_length = generate_key(key);

            encrypt(input_file, output_file, key);

            printf("Encryption successful!\n");
        }
        else if(choice == 2){
            printf("Please enter the name of the input file:\n");
            scanf("%s", input_file);

            printf("Please enter the name of the output file:\n");
            scanf("%s", output_file);

            printf("Please enter the key used to encrypt the file:\n");
            scanf("%s", key);

            decrypt(input_file, output_file, key);

            printf("Decryption successful!\n");
        }
        else if(choice == 3){
            printf("Goodbye!\n");
            exit(EXIT_SUCCESS);
        }
        else{
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void encrypt(char input_file[], char output_file[], char key[]){
    FILE* fp_input;
    FILE* fp_output;

    if(check_file(fp_input) != 0){
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    if(check_file(fp_output) != 0){
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    int c;

    int i = 0;

    while((c = fgetc(fp_input)) != EOF){
        fputc(c ^ key[i], fp_output);
        i++;

        if(i == KEY_LENGTH){
            i = 0;
        }
    }

    fclose(fp_input);
    fclose(fp_output);
}

void decrypt(char input_file[], char output_file[], char key[]){
    FILE* fp_input;
    FILE* fp_output;

    if(check_file(fp_input) != 0){
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    if(check_file(fp_output) != 0){
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    int c;

    int i = 0;

    while((c = fgetc(fp_input)) != EOF){
        fputc(c ^ key[i], fp_output);
        i++;

        if(i == KEY_LENGTH){
            i = 0;
        }
    }

    fclose(fp_input);
    fclose(fp_output);
}

int generate_key(char key[]){
    int i;

    for(i = 0; i < KEY_LENGTH; i++){
        key[i] = rand() % 256;
    }

    return i;
}

int check_file(FILE* fp){
    if(fp == NULL){
        return 1;
    }

    return 0;
}