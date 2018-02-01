
 // These are #include lines, they list other files which have to be referenced
#include <tamtypes.h>
#include <kernel.h>
#include <sifrpc.h>
#include <stdio.h>
#include <debug.h>
#include <malloc.h>
 
// This is the main code, it's what will be run when the program is executed.
int main(int argc, char *argv[])
{
	// This initialises the Remote Procedure Call handler. It allows the Emotion Engine CPU to talk to the Input Output Processor.
	SifInitRpc(0);
	
	// This sets up the screen so we can write things on it.
	init_scr();
  
  int iter = 0; 

  realloc(malloc(10), 8); /* 1 */ 
  realloc(malloc(10), 8); /* 2 */ 
  realloc(realloc(malloc(10), 20), 10); 

  for (;;) { 
    char *ptr; 
    ptr = malloc(2048*1024);  /* This can be smaller also */ 
    printf ("%d: %p\n", iter++, ptr); 
	scr_printf("%d: %p\n", iter++, ptr);
    if (ptr == NULL) { 
      printf ("malloc() failed!\n"); 
      break; 
    } 
    free(ptr); 
  }

	return 0;
}
