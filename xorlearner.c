#include <stdio.h>
#include "perceptron.h"
#include <pthread.h>
#include <stdlib.h>

//x1 XOR x2 == (x1 AND NOT x2) OR (x2 AND NOT x1)

int main(int argc, char **argv){
	pthread_t nodes[2];
	
	//Inputs
	int xs[2][4] = {
		{1,1,0,0},
		{1,0,1,0}
	};

	
	//Mid-stage Targets
	int ts[2][4] = {
		{0,1,0,0},
		{0,0,1,0}
	};
	
	//Mid-stage outputs
	int zs[2][4] = {
		{0,0,0,0},
		{0,0,0,0}
	};

	
	int T[4] = {0,0,0,0}; //Training value
	int O[4] = {0,0,0,0}; //Output
	
	//Get CLI
	for (int i = 1; i<argc; i++){
		T[i - 1] = argv[i][0] - '0';
	}
	
	//Hidden Layer
	printf("ENTERING HIDDEN LAYER ----------------------------------------\n");
	
	for(int i = 0; i < 2; i++){
		printf("\nLEARNER: Creating thread %d\n", i);
		if (pthread_create(&nodes[i], NULL, threadablePerceptron\
			(xs[0], xs[1], ts[i], zs[i], (void *) &i), (void *) &i) == -1){
			printf("Creating thread %d failed\n", i);
			exit(-1);
		}

		printf("LEARNER: Continuing with loop\n");
	}
	printf("LEARNER: Proceeding to join threads\n");
	
	pthread_join(nodes[0], NULL);
	pthread_join(nodes[1], NULL);
	
	printOutput(zs[0]);
	printOutput(zs[1]);
	
	
	//Output Layer
	printf("\nENTERING OUTPUT LAYER --------------------------------------\n");
	
	perceptron(zs[0], zs[1], T, O);
	printOutput(O);
	
	return 0;
}
