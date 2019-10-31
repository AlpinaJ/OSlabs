#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  char *s = "This is a nice day";
  int f= open("ex1.txt", O_RDWR);

  char *map = mmap(NULL, strlen(s), PROT_WRITE | PROT_READ, MAP_SHARED, f, 0);

  memcpy(map, s, strlen(s));
  ftruncate(f, strlen(s));
  close(f);
  return 0;
}