//FormAI DATASET v1.0 Category: Spam Detection System ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct message {
    char text[100];
    int spam;
    float score;
};

int count_words(char *message) {
    int word_count = 0;
    for(int i=0; i<strlen(message); i++) {
        if(message[i] == ' ')
            word_count++;
    }
    return word_count+1;
}

void check_for_spam(struct message *msg) {
    char *spam_words[] = {"buy", "now", "limited", "offer", "discount", "sale"};
    int spam_word_count = sizeof(spam_words)/sizeof(spam_words[0]);
    int spam_count = 0;
    for(int i=0; i<spam_word_count; i++) {
        char *word = spam_words[i];
        if(strstr(msg->text, word) != NULL)
            spam_count++;
    }
    if(((float)spam_count/count_words(msg->text))*100 >= 30)
        msg->spam = 1;
    else
        msg->spam = 0;
}

void train_system(struct message **messages, int num_messages) {
    for(int i=0; i<num_messages; i++) {
        if(messages[i]->spam == 0)
            messages[i]->score = (float)count_words(messages[i]->text)/10;
        else
            messages[i]->score = -1*(float)count_words(messages[i]->text)/10;
    }
}

float get_score(struct message *msg, struct message **messages, int num_messages) {
    float score = 0;
    for(int i=0; i<num_messages; i++) {
        if(strcmp(msg->text, messages[i]->text) == 0) {
            score = messages[i]->score;
            break;
        }
    }
    return score;
}

void update_score(struct message *msg, struct message **messages, int num_messages, float learning_rate, float weight_decay) {
    float score = get_score(msg, messages, num_messages);
    float new_score = score + learning_rate*(msg->spam - score) - weight_decay*score;
    for(int i=0; i<num_messages; i++) {
        if(strcmp(msg->text, messages[i]->text) == 0) {
            messages[i]->score = new_score;
            break;
        }
    }
}

int main() {
    // Reading in messages from a file
    FILE *fp;
    char *filename = "messages.txt";
    char line[100];
    int num_messages = 0;
    struct message **messages = (struct message **)malloc(sizeof(struct message *));
    fp = fopen(filename, "r");
    while(fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\n")] = '\0'; // Removing newline character
        struct message *new_msg = (struct message *)malloc(sizeof(struct message));
        strcpy(new_msg->text, line);
        check_for_spam(new_msg);
        num_messages++;
        messages = (struct message **)realloc(messages, num_messages*sizeof(struct message *));
        messages[num_messages-1] = new_msg;
    }
    fclose(fp);
    
    // Training the system
    train_system(messages, num_messages);
    
    // Updating the scores based on feedback
    char feedback[10];
    while(1) {
        printf("Enter feedback (y/n): ");
        scanf("%s", feedback);
        if(strcmp(feedback, "n") == 0)
            break;
        else if(strcmp(feedback, "y") == 0) {
            char msg[100];
            printf("Enter message: ");
            scanf(" %[^\n]s", msg);
            struct message *new_msg = (struct message *)malloc(sizeof(struct message));
            strcpy(new_msg->text, msg);
            check_for_spam(new_msg);
            update_score(new_msg, messages, num_messages, 0.1, 0.05);
            num_messages++;
            messages = (struct message **)realloc(messages, num_messages*sizeof(struct message *));
            messages[num_messages-1] = new_msg;
        }
        else
            printf("Invalid input. Try again.\n");
    }
    
    // Predicting if a message is spam or not
    char test_msg[100];
    printf("Enter test message: ");
    scanf(" %[^\n]s", test_msg);
    struct message *test = (struct message *)malloc(sizeof(struct message));
    strcpy(test->text, test_msg);
    check_for_spam(test);
    if(test->spam == 1)
        printf("The message is spam!\n");
    else
        printf("The message is not spam.\n");
    
    // Freeing allocated memory
    for(int i=0; i<num_messages; i++)
        free(messages[i]);
    free(messages);
    
    return 0;
}