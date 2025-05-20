//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
    Program to analyze Wi-Fi signal strength using Multivariable regression
*/

#define MAX 100        //maximum number of data points
#define FEATURES 3     //number of features

//Function to load data from file
void load_data(FILE *fp, double **x, double *y, int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<FEATURES;j++)
            fscanf(fp,"%lf",&x[i][j]);
        fscanf(fp,"%lf",&y[i]);
    }
}

//Function to normalize the data
void normalize(double **x, double *y, int n)
{
    int i,j;
    double mean[FEATURES],std_dev[FEATURES];

    //calculate mean and standard deviation for each feature
    for(j=0;j<FEATURES;j++)
    {
        mean[j] = 0;
        for(i=0;i<n;i++)
            mean[j] += x[i][j];
        mean[j] /= n;

        std_dev[j] = 0;
        for(i=0;i<n;i++)
            std_dev[j] += (x[i][j]-mean[j])*(x[i][j]-mean[j]);
        std_dev[j] /= n;
        std_dev[j] = sqrt(std_dev[j]);
    }

    //normalize x and y using z-score normalization
    for(i=0;i<n;i++)
    {
        for(j=0;j<FEATURES;j++)
        {
            x[i][j] = (x[i][j]-mean[j])/std_dev[j];
        }
        y[i] = (y[i]-mean[FEATURES])/std_dev[FEATURES];
    }
}

//Function to perform gradient descent
void gradient_descent(double **x, double *y, double *theta, double alpha, int n, int iterations)
{
    int i,j,k;
    double h,temp;

    for(k=0;k<iterations;k++)
    {
        for(j=0;j<FEATURES;j++)
        {
            temp = 0;
            for(i=0;i<n;i++)
            {
                h = theta[0] + theta[1]*x[i][1] + theta[2]*x[i][2] + theta[3]*x[i][3];
                temp += (h-y[i])*x[i][j];
            }
            theta[j] = theta[j] - (alpha/n)*temp;
        }
    }
}

//Function to predict Wi-Fi signal strength for given input values
double predict(double *input, double *theta)
{
    double h = theta[0] + theta[1]*input[0] + theta[2]*input[1] + theta[3]*input[2];
    return h;
}

int main()
{
    FILE *fp;
    fp = fopen("data.txt","r");
    if(fp==NULL)
    {
        printf("File error!\n");
        exit(0);
    }

    double **x,*y;
    x = (double **)malloc(MAX*sizeof(double *));
    for(int i=0;i<MAX;i++)
        x[i] = (double *)malloc(FEATURES*sizeof(double));
    y = (double *)malloc(MAX*sizeof(double));

    //load data from file
    int n=0;
    while(!feof(fp))
    {
        fscanf(fp,"%lf",&x[n][0]);
        n++;
    }
    fseek(fp,0,SEEK_SET);
    load_data(fp,x,y,n);

    fclose(fp);

    //normalize data
    normalize(x,y,n);

    //initialize theta
    double theta[FEATURES+1] = {0};

    //set learning rate and number of iterations
    double alpha = 0.01;
    int iterations = 1000;

    //perform gradient descent
    gradient_descent(x,y,theta,alpha,n,iterations);

    //predict Wi-Fi signal strength for given input values
    double input[3] = {0.6,-0.5,1.2};
    double signal_strength = predict(input,theta);

    printf("Predicted Wi-Fi signal strength: %lf\n",signal_strength);

    //free memory
    for(int i=0;i<MAX;i++)
        free(x[i]);
    free(x);
    free(y);

    return 0;
}