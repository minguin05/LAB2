#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "lib/calculate.h"

void main(int argc, char *argv[]){
  void *handle;
  int (*add)(int,int), (*divi)(int,int),(*sub)(int,int),(*mult)(int,int);
  char *error;

  handle = dlopen("./lib/libshared.so", RTLD_LAZY);
  if (!handle) {
    fputs(dlerror(), stderr);
    exit(1);
  }

  add = dlsym(handle, "add");
  if ((error = dlerror()) != NULL){
    fprintf (stderr, "%s", error);
    exit(1);
  }
  divi = dlsym(handle, "divi");
  if ((error = dlerror()) != NULL){
    fprintf (stderr, "%s", error);
    exit(1);
  }
  mult = dlsym(handle, "mult");
  if ((error = dlerror()) != NULL){
    fprintf (stderr, "%s", error);
    exit(1);
  }
  sub = dlsym(handle, "sub");
  if ((error = dlerror()) != NULL){
    fprintf (stderr, "%s", error);
    exit(1);
  }
  
	printf("덧셈 결과 : %d \n", (*add)(3,3));
	printf("뺄셈 결과 : %d \n", (*substract)(7,3));
	printf("나눗셈 결과 : %d \n", (*devide)(16,2));
	printf("곱셈 결과 : %d \n", (*multiply)(3,6));

}
