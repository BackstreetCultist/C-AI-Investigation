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
	int * z1Buffer;
	int z1[4] = {0,0,0,0};
	int * z2Buffer;
	int z2[4] = {0,0,0,0};

	
	int T[4] = {0,0,0,0}; //Training value
	int *O; //Output
	
	//Get CLI
	for (int i = 1; i<argc; i++){
		T[i - 1] = argv[i][0] - '0';
	}
	
	//Hidden Layer
	printf("ENTERING HIDDEN LAYER -----------------\n");
	
	printf("\nFIRST NODE");
	z1Buffer = perceptron(x1, x2, t1);
	printOutput(z1Buffer);
	//Parse buffer into main var
	for (int i = 0; i<3; i++){
		z1[i] = z1Buffer[i];
	}
	printOutput(z1);
	
	printf("\nSECOND NODE");
	z2Buffer = perceptron(x1, x2, t2);
	printOutput(z2Buffer);
	//Parse buffer into main var
	for (int i = 0; i<3; i++){
		z2[i] = z2Buffer[i];
	}
	printOutput(z2);

	printf("\nENTERING MAIN LAYER -----------------");
	
	O = perceptron(z1, z2, T);
	printOutput(O);
	
	return 0;
}
