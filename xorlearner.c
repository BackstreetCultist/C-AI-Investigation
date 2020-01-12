#include <stdio.h>
#include "perceptron.h"

//x1 XOR x2 == (x1 AND NOT x2) OR (x2 AND NOT x1)

int main(int argc, char **argv){
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
	
	printf("\nFIRST NODE");
	perceptron(x1, x2, t1, z1);
	printOutput(z1);
	
	printf("\nSECOND NODE");
	perceptron(x1, x2, t2, z2);
	printOutput(z2);
	
	
	//Output Layer
	printf("\nENTERING OUTPUT LAYER ---------------\n");
	
	perceptron(z1, z2, T, O);
	printOutput(O);
	
	return 0;
}
