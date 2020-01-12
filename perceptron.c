#include <stdio.h>
#include "perceptron.h"

void perceptron(int x1[4], int x2[4], int T[4], int O[4]){
	int pass; //1 = pass, 0 = fail, reset to 1 each time
	float y = 0.5;
	float w1 = 0;
	float w2 = 0;
	double LR = 0.1;
	do {
		pass = 1;
		printf("\n\nNEW CYCLE\n");

		//Loop through all target values
		for (int i = 0; i<4; i++){
			printf("Bias = %f\n", y);
			printf("Weight 1 = %f\n", w1);
			printf("Weight 2 = %f\n", w2);

			//Attempt to fire neuron
			if (y <= (x1[i] * w1) + (x2[i] * w2) ){
				O[i] = 1;
			}
			else {
				O[i] = 0;
			}
			
			//Print what just happened
			printf("x1 = %d,    x2 = %d,    output = %d,    target = %d\n", x1[i], x2[i], O[i], T[i]);
			
			//Adjust weights if there is an error
			w1 = w1 + (LR * (T[i] - O[i]) * x1[i]);
			w2 = w2 + (LR * (T[i] - O[i]) * x2[i]);
			y = y - (LR * (T[i] - O[i]));
		}
		
		//Test whether any are wrong
		for (int i = 0; i<4; i++){
			if (O[i] != T[i]){
				pass = 0;
			}
		}
		
	} while (pass == 0);
	printf("Perceptron out\n");
}

int printOutput(int output[4]){
	printf("Returned: ");
	for (int i = 0; i<4; i++){
		printf("  %d  ", output[i]);
	}
	printf("\n");
}
