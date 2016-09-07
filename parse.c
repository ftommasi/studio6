#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char** argv){
  char* buf = (char*) malloc(sizeof(char)*256);
  
  int max_args = 15;
  int max_argv_size = max_args + 2; //one for argv[0], one for null terminator
  char* cmd = (char*) malloc(sizeof(char)*256);
  char* my_argv[max_argv_size];
  
  fgets(buf,256,stdin);
  buf = strtok (buf,"\n");
  char* next = strtok(buf," ");
  strcpy(cmd,next);
  int i=0;
  while(next){
    printf("in while appended %s\n",next);
    my_argv[i] = (char*) malloc(sizeof(char)*256);
    strcpy(my_argv[i],next);
//    my_argv[i] = temp;
    next = strtok(NULL," ");    
    i++;
  }
  int j=0;
  printf("[ ");
  for(j;j<i;j++){
    printf("%s",my_argv[j]);
    if(j+1 != i)
      printf(", ");
    else
      printf(" ");
  }
  printf("]\n");
  execvp(cmd,my_argv);
  return 0;
}
