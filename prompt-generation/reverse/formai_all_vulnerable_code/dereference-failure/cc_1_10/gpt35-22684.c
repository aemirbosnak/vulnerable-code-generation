//FormAI DATASET v1.0 Category: Text Summarizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 5000
#define MAX_SUMMARY_SIZE 200

char* readStringFromFile(const char *fileName){
    FILE *fp;
    long lSize;
    char *buffer;

    fp = fopen ( fileName , "rb" );
    if( !fp ) perror(fileName),exit(1);

    fseek( fp , 0L , SEEK_END);
    lSize = ftell( fp );
    rewind( fp );

    buffer = calloc( 1, lSize+1 );
    if( !buffer ) fclose(fp),fputs("memory alloc fails",stderr),exit(1);

    if( 1!=fread( buffer , lSize, 1 , fp) )
      fclose(fp),free(buffer),fputs("entire read fails",stderr),exit(1);

    fclose(fp);
    return buffer;
}

char* summarizeText(char *text){
    char *result = calloc(1, sizeof(char) * MAX_SUMMARY_SIZE);
    if(!result) return NULL;

    int idx = 0;
    int len = strlen(text);
    int i = 0;

    // Iterate through the text and identify end of sentences
    while(i < len && idx < MAX_SUMMARY_SIZE-1){
        result[idx++] = text[i];
        if(text[i] == '.'){
            int j = i+1;
            while(text[j] == ' ') j++; // Skip spaces

            if(isupper(text[j])){ // Beginning of next sentence
                if(idx+3 >= MAX_SUMMARY_SIZE) break; // No space to add "..."
                result[idx++]='.'; result[idx++]='.'; result[idx++]='.';
            }
        }
        i++;
    }
    result[idx] = '\0';
    free(text);
    return result;
}

int main(){
    char* fileContent = readStringFromFile("input.txt");
    char* summary = summarizeText(fileContent);
    printf("%s", summary);
    free(summary);
    return 0;
}