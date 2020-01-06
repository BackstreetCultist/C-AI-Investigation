#include <stdio.h>
#include "perceptron.h"

//x1 XOR x2 == (x1 AND NOT x2) OR (x2 AND NOT x1)
int main(int argc, char **argv){
	int x1[4] = {1,1,0,0};
	int x2[4] = {1,0,1,0};
	int T[4] = {0,0,0,0}; //Training value
	for (int i = 1; i<argc; i++){
		T[i - 1] = argv[i][0] - '0';
	}
	printf("ENTERING HIDDEN LAYER -----------------\n");
	//Hidden code 
	printf("ENTERING MAIN LAYER -----------------\n");
	
	
	perceptron(z1, z2, T);
	
	
	return 0;
}
