//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct sentiment_scores {
    double pos_score;
    double neg_score;
    double neu_score;
} sent_scores;

typedef struct word_emotion_lexicon {
    char word[100];
    double pos_value;
    double neg_value;
    double neu_value;
} lexicon;

int main() {

    int i, j, num_words, num_lines;
    double pos_score = 0, neg_score = 0, neu_score = 0;
    char line[10000], *token, *delim = " \n";
    sent_scores *score_list;
    lexicon *emotion_lexicon;

    FILE *fp = fopen("emotion_lexicon.txt", "r"); // replace the file name with your own lexicon file name
    if(fp == NULL) {
        printf("Error: Could not open the lexicon file!\n");
        exit(1);
    }

    fscanf(fp, "%d %d", &num_words, &num_lines); // read the number of words and lines
    emotion_lexicon = (lexicon *) calloc(num_words, sizeof(lexicon)); // allocate memory for the lexicon

    // read the words with their corresponding positive, negative, and neutral values
    for(i=0; i<num_words; i++) {
        fscanf(fp, "%s %lf %lf %lf", emotion_lexicon[i].word, &emotion_lexicon[i].pos_value, &emotion_lexicon[i].neg_value, &emotion_lexicon[i].neu_value);
    }

    fclose(fp);

    fp = fopen("input_reviews.txt", "r"); // replace the file name with your own input file name
    if(fp == NULL) {
        printf("Error: Could not open the input file!\n");
        exit(1);
    }

    score_list = (sent_scores *) calloc(num_lines, sizeof(sent_scores)); // allocate memory for the sentiment scores

    i = 0;

    // read the input reviews line by line
    while(fgets(line, 10000, fp)) {
        token = strtok(line, delim);

        // calculate sentiment scores for each review
        while(token != NULL) {
            for(j=0; j<num_words; j++) {
                if(strcmp(emotion_lexicon[j].word, token) == 0) {
                    pos_score += emotion_lexicon[j].pos_value;
                    neg_score += emotion_lexicon[j].neg_value;
                    neu_score += emotion_lexicon[j].neu_value;
                    break;
                }
            }
            token = strtok(NULL, delim); 
        }

        // store the sentiment scores for each review
        score_list[i].pos_score = pos_score;
        score_list[i].neg_score = neg_score;
        score_list[i].neu_score = neu_score;

        // reset the scores for the next review
        pos_score = 0;
        neg_score = 0;
        neu_score = 0;

        i++;
    }

    fclose(fp);

    // print the sentiment scores for each review
    for(i=0; i<num_lines; i++) {
        printf("Review %d:\n", i+1);
        printf("Positive Score: %.2lf\n", score_list[i].pos_score);
        printf("Negative Score: %.2lf\n", score_list[i].neg_score);
        printf("Neutral Score: %.2lf\n", score_list[i].neu_score);
    }

    // free the memory allocated for lexicon and sentiment score list
    free(emotion_lexicon);
    free(score_list);

    return 0;
}