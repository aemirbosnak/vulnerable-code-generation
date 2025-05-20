//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_META_LEN 1000

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char filename[256];
    strcpy(filename, argv[1]);

    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char metadata[MAX_META_LEN];

    int ch, index = 0;
    while((ch = fgetc(fp)) != EOF){
        if(index >= MAX_META_LEN-1){
            break;
        }

        // check for metadata start
        if(ch == '<'){
            if(fgetc(fp) == '?'){ // check for xml declaration
                ch = fgetc(fp);
                while(ch != '?'){ // skip xml declaration
                    ch = fgetc(fp);
                    if(ch == EOF){ // reached end of file, no metadata found
                        fclose(fp);
                        exit(EXIT_SUCCESS);
                    }
                }
                ch = fgetc(fp); // read next character after '?'
            }

            if(ch == '!'){ // check for comment
                ch = fgetc(fp);
                if(ch == '-'){
                    ch = fgetc(fp);
                    if(ch == '-'){ // comment found
                        while((ch = fgetc(fp)) != EOF){
                            if(ch == '-'){
                                if(fgetc(fp) == '-'){ // end of comment found
                                    ch = fgetc(fp); // read next character after '--'
                                    break;
                                }
                            }
                            if(index >= MAX_META_LEN-1){
                                break;
                            }
                            metadata[index++] = ch; // store comment in metadata
                        }
                    }
                }
            }

            if(ch == '/'){ // check for closing tag
                break;
            }

            // read metadata until end of opening tag is found
            while(ch != '>'){
                ch = fgetc(fp);
                if(ch == EOF){ // reached end of file, no metadata found
                    fclose(fp);
                    exit(EXIT_SUCCESS);
                }
                if(ch == '\"'){ // handle quotes within metadata
                    metadata[index++] = ch;
                    ch = fgetc(fp);
                    while(ch != '\"'){
                        metadata[index++] = ch;
                        ch = fgetc(fp);
                        if(ch == EOF){ // reached end of file, no metadata found
                            fclose(fp);
                            exit(EXIT_SUCCESS);
                        }
                    }
                }
                else{
                    metadata[index++] = ch;
                }
                if(index >= MAX_META_LEN-1){
                    break;
                }
            }

            metadata[index++] = '\0'; // add null terminator to metadata
            break; // metadata found, exit while loop
        }
    }

    if(index == 0){ // no metadata found
        printf("No metadata found in file: %s\n", filename);
    }
    else{
        printf("Metadata found in file: %s\n", filename);
        printf("%s\n", metadata);
    }

    fclose(fp);
    exit(EXIT_SUCCESS);
}