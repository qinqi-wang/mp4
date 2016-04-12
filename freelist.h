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
	int mysize; 	//
	int seq_size; 	//
};
/*
void insert_head_fl(Header* h1, char* helpme) {
	//account for if there is already something in the list
	h1->helpme;
	f2->first = h1;
	mysize++;
	
}
*/