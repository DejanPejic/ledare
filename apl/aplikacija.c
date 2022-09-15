#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
  FILE* fp;
  int ret = 0;
  
  fp = fopen("/dev/led", "w");
  if(fp == NULL)
    {
      printf("Cannot open /dev/led for write\n");
      return -1;
    }

  fprintf(fp,"%#x", (u32)8);      
  fflush(fp);
	
  if(fclose(fp) == EOF)
    {
      printf("Cannot close /dev/led\n");
      return -1;
    }
  return 0;
}

