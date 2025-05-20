//FormAI DATASET v1.0 Category: Text Summarizer ; Style: invasive
/*Hey there! I'm an awesome C Text Summarizer program, ready to make your life easier!*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*I need a function to read the input file and convert it to a string*/
char* readFile(char *filename)
{
    /*First, I'll open the file using fopen function*/
    FILE *fileptr = fopen(filename, "r");
    /*If the file doesn't exist, bye-bye!*/
    if(fileptr == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    /*I'll use fseek function to determine the size of the file*/
    fseek(fileptr, 0, SEEK_END);
    long file_size = ftell(fileptr);
    rewind(fileptr); /*I reset the file pointer to the beginning*/

    /*I'll allocate memory for the string that will hold the entire file*/
    char *file_content = (char*)malloc(sizeof(char)*(file_size+1)); /*Don't forget the null terminator*/
    /*If there isn't enough memory, bye-bye!*/
    if(file_content == NULL)
    {
        printf("Error allocating memory!\n");
        exit(1);
    }

    /*I read the file content into the string*/
    fread(file_content, sizeof(char), file_size, fileptr);
    file_content[file_size] = '\0'; /*Don't forget the null terminator*/

    /*I close the file*/
    fclose(fileptr);

    return file_content;
}

/*I need a function to summarize the input string*/
char* summarizeText(char *text)
{
    /*First, I'll tokenize the text into sentences*/
    char **sentences = (char**)malloc(sizeof(char*)*10); /*I'll assume the text has a maximum of 10 sentences*/
    int max_sentences = 10;
    int num_sentences = 0;
    char *delimiter = ".\n"; /*I'll use '.' and '\n' as sentence delimiters*/
    char *token = strtok(text, delimiter);
    while(token != NULL)
    {
        /*I check if there is enough memory for the sentence*/
        if(num_sentences >= max_sentences)
        {
            max_sentences *= 2;
            sentences = (char**)realloc(sentences, sizeof(char*)*max_sentences);
        }

        /*I allocate memory for the sentence*/
        sentences[num_sentences] = (char*)malloc(sizeof(char)*(strlen(token)+2)); /*I'll add '.' and '\n' to the end of the sentence*/
        /*If there isn't enough memory for the sentence, bye-bye!*/
        if(sentences[num_sentences] == NULL)
        {
            printf("Error allocating memory!\n");
            exit(1);
        }
        /*I add the sentence to the array*/
        strcat(strcat(sentences[num_sentences], token), ".\n");
        num_sentences++;

        /*I get the next sentence*/
        token = strtok(NULL, delimiter);
    }

    /*Now, I'll rank the sentences based on their length*/
    int *lengths = (int*)malloc(sizeof(int)*num_sentences);
    for(int i=0; i<num_sentences; i++)
    {
        lengths[i] = strlen(sentences[i]);
    }

    /*I sort the lengths in decreasing order*/
    for(int i=0; i<num_sentences; i++)
    {
        for(int j=i+1; j<num_sentences; j++)
        {
            if(lengths[i] < lengths[j])
            {
                /*I swap the lengths*/
                int temp = lengths[i];
                lengths[i] = lengths[j];
                lengths[j] = temp;

                /*I swap the sentences*/
                char *temp2 = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp2;
            }
        }
    }

    /*I'll take the first 3 sentences*/
    char *summary = (char*)malloc(sizeof(char)*1);
    summary[0] = '\0';
    for(int i=0; i<3 && i<num_sentences; i++)
    {
        /*I append the sentence to the summary*/
        summary = (char*)realloc(summary, sizeof(char)*(strlen(summary)+strlen(sentences[i])+1)); /*Don't forget the null terminator*/
        strcat(summary, sentences[i]);
    }

    /*I free the memory allocated for the sentences and lengths*/
    for(int i=0; i<num_sentences; i++)
    {
        free(sentences[i]);
    }
    free(sentences);
    free(lengths);

    return summary;
}

/*I need a main function to make use of the previous functions*/
int main()
{
    /*I'll ask the user for the name of the file to summarize*/
    printf("Please enter the name of the file to summarize (including extension): ");
    char filename[50];
    scanf("%s", filename);

    /*I read the file and convert it to a string*/
    char *text = readFile(filename);

    /*I summarize the text*/
    char *summary = summarizeText(text);

    /*I print the summary*/
    printf("SUMMARY:\n%s", summary);

    /*I free the memory allocated for the text and summary*/
    free(text);
    free(summary);

    return 0;
}