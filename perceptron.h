#ifndef PERCEPTRON_H				//Once-only header
#define PERCEPTRON_H

void perceptron(int[], int[], int[], int[], int);

void * threadablePerceptron(int[], int[], int[], int[], void *);
int printOutput(int[]);

#endif

