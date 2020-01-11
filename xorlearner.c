#include <stdio.h>
#include "perceptron.h"

//x1 XOR x2 == (x1 AND NOT x2) OR (x2 AND NOT x1)
int main(int argc, char **argv){
	//Inputs
	int x1[4] = {1,1,0,0};
	int x2[4] = {1,0,1,0};
	
	//Mid-stage outputs
	int z1[4] = {0,0,0,0};
	int z2[4] = {0,0,0,0};
	
	int T[4] = {0,0,0,0}; //Training value
	int *O; //Output
	
	//Get CLI
	for (int i = 1; i<argc; i++){
		T[i - 1] = argv[i][0] - '0';
	}
	
	//Hidden Layer
	printf("ENTERING HIDDEN LAYER -----------------\n");
		

	printf("ENTERING MAIN LAYER -----------------\n");
	
	
	perceptron(z1, z2, T);
	
	
	return 0;
}
