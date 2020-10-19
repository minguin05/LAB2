/*main.c*/
#include <stdio.h>
#include "calculate.h"

int main(){
	printf("ADD : %d \n", (*add)(3,3));
	printf("subtract : %d \n", (*substract)(7,3));
	printf("devide : %d \n", (*devide)(16,2));
	printf("multiply : %d \n", (*multiply)(3,6));

}
