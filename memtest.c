#include "ackerman.h"
#include <iostream>
using namespace std;

int main(int argc, char ** argv) {
  int c = 0;
  int b = 0; 
  int s = 0; //integers for block size and length 
  while ((c = getopt(argc, argv, "b:s:")) != -1) { // the colons in b:s: means it takes input after writing -b
  	switch (c)
  	{
  		case 'b':
  			b = atoi(optarg);
  			break;
  		case 's':
  			s = atoi(optarg);
  			break; 
  	}
  }
  cout << "Value of b:" << b << endl;
  cout << "Value of s:" << s << endl;
  //getopt();
  //init_allocator( , );
  //ackerman_main();
}
// change name to memtest.c
// ./memtest -b <blocksize (default 128)> -s <memsize (default 512)>
// use getopt() to parse 
// create init_allocator( b, s) 
// call ackerman_main();
// at_exit() used to release all resources, place it into main(), need to pass release_allocator to it
// release_allocator frees memory and frees the list 