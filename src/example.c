#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_string(char *rand_buffer, int len)
{
  int index;
  char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  srand(time(NULL));

  for (index = 0; index < len; index++) {
    rand_buffer[index] = alpha[rand() % (sizeof(alpha) - 1)];
  }
  rand_buffer[index] = '\0';
}

int main(int argc, char **argv)
{
  char rand_buffer[1024];
  if (argc == 2) {
    int len = atoi(argv[1]);
    generate_string(rand_buffer, len);
    printf("%s\n", rand_buffer);
  }

  return 0;
}
