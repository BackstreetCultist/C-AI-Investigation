#include <stdio.h>
#include "perceptron.h"
#include <pthread.h>

//x1 XOR x2 == (x1 AND NOT x2) OR (x2 AND NOT x1)

int main(int argc, char **argv){
	pthread_t nodes[2];
	
	//Inputs
	int x1[4] = {1,1,0,0};
	int x2[4] = {1,0,1,0};
	
	//Mid-stage Targets
	int t1[4] = {0,1,0,0};
	int t2[4] = {0,0,1,0};
	
	//Mid-stage outputs
	int z1[4] = {0,0,0,0};
	int z2[4] = {0,0,0,0};

	
	int T[4] = {0,0,0,0}; //Training value
	int O[4] = {0,0,0,0}; //Output
	
	//Get CLI
	for (int i = 1; i<argc; i++){
		T[i - 1] = argv[i][0] - '0';
	}
	
	//Hidden Layer
	printf("ENTERING HIDDEN LAYER -----------------\n");
	
	for(int i = 0; i < 2; i++){
		printf("\nLEARNER: Creating thread %d\n", i);
		
		switch(i){
			case 0:
				if (pthread_create(&nodes[i], NULL, threadablePerceptron(x1, x2, t1, z1, (void *) &i), (void *) &i) == -1){
					printf("Creating thread %d failed\n", i);
					exit(-1);
				}
				break;
				
			case 1:
				if (pthread_create(&nodes[i], NULL, threadablePerceptron(x1, x2, t2, z2, (void *) &i), (void *) &i) == -1){
					printf("Creating thread %d failed\n", i);
					exit(-1);
				}
				break;
				
			default:
				printf("You shouldn't see this message\n");
				break;
		}

		printf("LEARNER: Continuing with loop\n");
	}
	printf("LEARNER: Proceeding to join threads\n");
	
	for(int i = 0; i < 2; i++){
		pthread_join(nodes[i], NULL);
	}
	
	printOutput(z1);
	printOutput(z2);
	
	
	//Output Layer
	printf("\nENTERING OUTPUT LAYER ---------------\n");
	
	perceptron(z1, z2, T, O);
	printOutput(O);
	
	return 0;
}
