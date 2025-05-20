//FormAI DATASET v1.0 Category: Image Steganography ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

void steganography(char* in_file, char* out_file, char* hidden_msg){

    FILE *in_fp, *out_fp;
    char ch, hidden_ch;
    int h_len = 0, bit_count = 0, i = 0;
    long int lsize;

    //Open input file
    in_fp = fopen(in_file, "rb");

    //calculate size of input file
    fseek(in_fp, 0L, SEEK_END);
    lsize = ftell(in_fp);
    rewind(in_fp);
    
    //Open output file
    out_fp = fopen(out_file, "wb");
    if(out_fp == NULL){
        printf("Error: Unable to open output file!\n");
        exit(1);
    }

    //Get length of hidden message
    while(hidden_msg[h_len] != '\0'){
        h_len++;
    }

    //Hide message in the LSB of each byte
    while (ftell(in_fp) < lsize){

        ch = fgetc(in_fp);
        
        if(i < h_len){
            hidden_ch = hidden_msg[i];
        } else {
            hidden_ch = '\0';
        }

        //Hide bits in LSB
        ch = (ch & ~1) | (hidden_ch & 1);
        fputc(ch, out_fp);

        if(bit_count == 7){
            i++;
            bit_count = 0;
        } else {
            bit_count++;
        }
    }

    //Close files
    fclose(in_fp);
    fclose(out_fp);
}

void extract_message(char* in_file){

    FILE *in_fp;
    char ch;
    int bit_count = 0;
    char hidden_ch = 0;

    //Open input file
    in_fp = fopen(in_file, "rb");

    //Extract message from LSB
    while(1){

        ch = fgetc(in_fp);
        hidden_ch |= ((ch & 1) << bit_count);

        if(bit_count == 7){
            if(hidden_ch == '\0'){
                break;
            } else {
                printf("%c", hidden_ch);
                bit_count = 0;
                hidden_ch = 0;
            }
        } else {
            bit_count++;
        }
    }
    
    //Close file
    fclose(in_fp);
}

int main(){

    char* input_file = "input.txt";
    char* output_file = "output.txt";
    char* hidden_msg = "Hello, World!";

    steganography(input_file, output_file, hidden_msg);
    printf("Message hidden successfully!\n");

    printf("Extracted message: ");
    extract_message(output_file);

    return 0;
}