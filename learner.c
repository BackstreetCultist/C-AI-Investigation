#include <stdio.h>
#include "perceptron.h"

int main(int argc, char **argv){
	int x1[4] = {1,1,0,0};
	int x2[4] = {1,0,1,0};
	int T[4] = {0,0,0,0}; //Training value
	for (int i = 1; i<argc; i++){
		T[i - 1] = argv[i][0] - '0';
	}
	perceptron(x1,x2,T);
	return 0;
}