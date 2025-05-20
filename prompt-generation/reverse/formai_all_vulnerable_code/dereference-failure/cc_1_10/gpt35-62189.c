//FormAI DATASET v1.0 Category: Text Summarizer ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 200
#define MAX_SUMMARY_LENGTH 1000

typedef struct 
{
    char sentence[MAX_SENTENCE_LENGTH];
    int score;
} Sentence;

char* read_input(FILE *);
int count_sentences(char *);
void replace_chars(char *, char, char);
int compute_score(char *);
int generate_summary(char *, char *);

int main()
{   
    char input_file[100], summary_file[100];
    printf("Enter the input file name: ");
    scanf("%s", input_file);
    printf("Enter the file name where you want to generate summary: ");
    scanf("%s", summary_file);

    char *input_data = NULL;
    FILE *fp = fopen(input_file, "r");
    if(fp)
    {
        input_data = read_input(fp);
        fclose(fp);
    }
    else
    {
        printf("Unable to open input file!");
        exit(1);
    }

    int summary_size = generate_summary(input_data, summary_file);

    printf("Summary generated successfully in %s, with total %d characters.\n", summary_file, summary_size);

    free(input_data);

    return 0;

}

//function to read the input file and return a string containing the input data.
char* read_input(FILE *fp)
{
    char *input_data = NULL;
    long size = 0;
    if(fp)
    {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp);
        rewind(fp);
        input_data = (char *) malloc(sizeof(char) * size);
        fread(input_data, sizeof(char), size, fp);
    }

    return input_data;
}

//function to count the number of sentences in a string
int count_sentences(char *input_data)
{
    int num_sentences = 0;
    char *pch = strchr(input_data, '.');
    while(pch!=NULL)
    {
        num_sentences++;
        pch = strchr(pch+1, '.');
    }

    return num_sentences;
}

//function to replace all special characters except the alphabets and digits with spaces
void replace_chars(char *str, char old_char, char new_char)
{
    while(*str)
    {
        if((*str)>=65 && (*str)<=90)
        {
            *str = *str + 32;
        }
        if(!((*str>=97 && *str<=122) || (*str>=48 && *str<=57)))
        {
            *str = new_char;
        }
        else
        {
            *str = *str;
        }
        str++;
    }
}

//function to compute score of each sentence based on the frequency of key words in it
int compute_score(char *sentence)
{
    int score = 0;
    char keywords[5][20] = {"summer", "winter", "spring", "autumn", "season"};
    char *token = strtok(sentence, " ");
    while(token!=NULL)
    {
        for(int i=0; i<5; i++)
        {
            if(strstr(token, keywords[i])!=NULL)
            {
                score++;
            }
        }
        token = strtok(NULL, " ");
    }

    return score;
}

//function to generate summary of the text data
int generate_summary(char *input_data, char *summary_file)
{
    int num_sentences = count_sentences(input_data);
    Sentence sentence_list[MAX_SENTENCES];
    int sentence_count = 0;

    char *pch, *context=NULL;
    pch = strtok_r(input_data, ".?!", &context);
    while(pch!=NULL)
    {
        replace_chars(pch, '\n', ' ');
        int sentence_score = compute_score(pch);
        if(sentence_score>0)
        {
            Sentence sentence;
            strcpy(sentence.sentence, pch);
            sentence.score = sentence_score;
            sentence_list[sentence_count++] = sentence;
        }
        pch = strtok_r(NULL, ".?!", &context);
    }

    //sorting the sentence list based on the sentence score
    for(int i=0; i<sentence_count-1; i++)
    {
        for(int j=i+1; j<sentence_count; j++)
        {
            if(sentence_list[i].score<sentence_list[j].score)
            {
                Sentence temp = sentence_list[i];
                sentence_list[i] = sentence_list[j];
                sentence_list[j] = temp;
            }
        }
    }

    //generate summary string based on highest scoring sentences
    int summary_size = 0;
    char summary[MAX_SUMMARY_LENGTH] = "";
    for(int i=0; i<sentence_count && summary_size<MAX_SUMMARY_LENGTH; i++)
    {
        summary_size += strlen(sentence_list[i].sentence);
        if(summary_size>MAX_SUMMARY_LENGTH)
        {
            break;
        }
        strcat(summary, sentence_list[i].sentence);
        strcat(summary, ". ");
    }

    //writing summary data to the summary file
    FILE *fp = fopen(summary_file, "w");
    if(fp)
    {
        fprintf(fp, "%s", summary);
        fclose(fp);
    }
    else
    {
        printf("Unable to open summary file!");
        exit(1);
    }

    return summary_size;

}