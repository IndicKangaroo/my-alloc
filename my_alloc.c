#include <stdio.h>
#include<string.h>
#include<unistd.h>
void *heap_start =NULL;
void* my_alloc(size_t length){
	void * allocated_address=sbrk(length);
	if(heap_start==NULL){
		heap_start=allocated_address;
			}


	return allocated_address;
}
int my_free_all(){
	if(heap_start==NULL){
		return -1;
	}
	return brk(heap_start);
}
int main(void) {
   const char *message="This is my own malloc!";
   size_t size =strlen(message)*sizeof(char);
   char * allocated_mem=my_alloc(size);
   strcpy(allocated_mem,message);
   my_free_all();
}
