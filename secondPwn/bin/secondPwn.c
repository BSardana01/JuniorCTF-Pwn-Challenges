#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void getFlag() {
  char buf[64];
  FILE *f = fopen("flag","r");
  if (f == NULL) {
    // Make a dummy flag file for local testing
    printf("Flag File is Missing\n");
    exit(0);
  }

  fgets(buf,64,f);
  printf(buf);
}

void vuln(){
  char buf[128];
  gets(buf);
}

int main(int argc, char **argv){

  setvbuf(stdout, NULL, _IONBF, 0);
  gid_t gid = getegid();
  setresgid(gid, gid, gid);
  puts("Enter your input and hope it's big enough\n");
  vuln();
  return 0;
}
