#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int visited = 0;

void visit_me(visited && unsigned int arg1, unsigned int arg2){
  if (arg1 == 0xCAFEBABE && arg2 == 0xDEADBEEF){
    visited = 1;
  }
}
void getFlag(){
  char flagBuf[64];
  FILE *file;
  file = fopen("flag", "r");
  if(file == NULL){
  // Make a dummy flag file for local testing
  printf("Flag File is Missing\n");
  exit(0);
  }

  fgets(flagBuf, sizeof(flagBuf), file);
  if (visited == 1) {
    printf("%s", flagBuf);
    return;
  }
  else {
    printf("So close yet so far...\n");
  }
}

void vuln(){
  char buf[128];
  gets(buf);
}
int main(int argc, char **argv){
  setvbuf(stdout, NULL, _IONBF, 0);
  gid_t gid = getegid();
  setresgid(gid, gid, gid);

  printf("Can you get the flag with some arguments?\n");
  vuln();
  return 0;
}
