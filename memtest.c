#include "ackerman.h"

int main(int argc, char ** argv) {
  int c;
  c = getopt(argc, argv, "bsc:")
  	switch (c)
  	{

  	}
  //getopt();
  init_allocator( argc, argv)
  ackerman_main();
}
// change name to memtest.c
// ./memtest -b <blocksize (default 128)> -s <memsize (default 512)>
// use getopt() to parse 
// create init_allocator( b, s) 
// call ackerman_main();
// at_exit() used to release all resources, place it into main(), need to pass release_allocator to it
// release_allocator frees memory and frees the list 