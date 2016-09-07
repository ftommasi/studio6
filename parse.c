#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char** argv){
  char* buf = (char*) malloc(sizeof(char)*256);
  
  int max_args = 15;
  int max_argv_size = max_args + 2; //one for argv[0], one for null terminator
  char* cmd;
  char* my_argv[max_argv_size];
  
  fgets(buf,256,stdin);
  buf = strtok (buf,"\n");
  char* next = strtok(buf," ");
  strcpy(next,cmd);
  if(next == cmd){
    printf("ERROR");
    return -1;
  }
  else{
    printf("%s",cmd);
  }
  while(next){    
    printf("%s\n",next);
    next = strtok(NULL," ");
    
  }
  return 0;
}
