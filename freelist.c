typedef struct h {
  struct h* next;
  struct h* prev;
  unsigned int size;
  bool isFree; 
  unsigned int marker;
} Header;

typedef struct freelist {
  Header *first;
  Header *last;
  int mysize;
  int seq_size; 
};