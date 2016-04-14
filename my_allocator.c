/* 
    File: my_allocator.c

    Author: <your name>
            Department of Computer Science
            Texas A&M University
    Date  : <date>

    Modified: 

    This file contains the implementation of the module "MY_ALLOCATOR".

*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/


#include "my_allocator.h"


/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */
	static freelist flist;
/*--------------------------------------------------------------------------*/
/* CONSTANTS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FORWARDS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FUNCTIONS FOR MODULE MY_ALLOCATOR */
/*--------------------------------------------------------------------------*/

/* Don't forget to implement "init_allocator" and "release_allocator"! */

//checks user input for allocator
void check_init_allocator(unsigned int _basic_block_size, unsigned int _length) {
  if( _basic_block_size > 16) {
    _basic_block_size = 32; 
  }
  // check if _basic_block_size is a power of 2

}

unsigned int init_allocator(unsigned int _basic_block_size, 
          unsigned int _length) {
  
  check_init_allocator( _basic_block_size, _length );
  //check how much extra
  int length_log = ceil(log10(_length)/log10(2)); //get log2 of the _length
  int truesize = pow(2, length_log);    //take the power of 2 for that space. May create an unnecessary amount of space, however
  char* e = (char*)malloc(truesize);		//allocate space for the user based on their input, (removed sizeof header, currently header is a part of the block rather than being tacked-on the front)
  Header* h1 = (Header*)e;					//typecast e to a Header*
  // push to freelist?
  
  /*
  if( length_log ) {
    //do nothing
    malloc(_length + sizeof(Header));
    //return _length;
  }
  else {
    // some math that will allocate the block, based on things like extra space
    //for( ;; ) { // unlimited loop?
      unsigned int new_block = _basic_block_size*2; // multiply the _basic_block_size by 2
      if( new_block >= _length) {
        malloc(new_block);
        //return new_block;
      } 
    }
  }
  */
  // make sure size of basic block size cannot be less than 16
  // if user inputs a number for length that isnt a multiple of block size, 
  // call a check_init_allocator() function, if the user inputs a number that is negative, or maybe too large, have a response
  // then, do some math to see how many freelists there will be and
  // give largest block to the user?, split into smaller blocks for later use
  // if the biggest block isn't a multiple, give the user more then? 
  // ex. if user requests 600, give 512 block + 128 block.
  // find out number of freelists, which blocks to create

  // call malloc() to create enough memory for the blocks 
  
  // initialize freelists
  // 3 situations:
  // 1) initialize 128, 512. :initialize freelist with 3 blocks - 128, and 256, set both to NULL, have 512 point to the large block
  // 2) initialize 128, 600. :initialize free list with same 3 blocks - freelist for 256 is NULL, both 128 and 512 will be pointing to the initializer
  // 3) 
}


extern Addr my_malloc(unsigned int _length) {
  /* This preliminary implementation simply hands the call over the 
     the C standard library! 
     Of course this needs to be replaced by your implementation.
  */
  // ackerman calls this, use to give the ackerman function a random block
  // needs to handle many different situations
  // _length + size of the header (give room for the header)
  // allocator_find_bigger function
  // find a block bigger than _length+size
  // if( block > _length+size) return block to arguement
  // else return h+1, to shift to blcok memory that will be used 
    // segment_cut made to cut blocks, remove the block from the freelist
    // then call freelist_add to add new freelists to the block return my_malloc(_length)
  return malloc((size_t)_length);
}

extern int my_free(Addr _a) {
  /* Same here! */
  // called by ackerman, used to free a block
  // move pointer from memory to the header, 
  // header th = a-1;
  // after checking isfree, merge the blocks, merge as many blocks as possible
  // allocator_coalesce 
  free(_a);
  return 0;
}

