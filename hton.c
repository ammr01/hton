/*
 * Author : Amr Alasmer
 *
 * Date : 5-12-2022
 * 
 * Usage : reverse byte order (host byte order to network byte order) 
 * 
 * Example :	int value -> [b0 b1 b2 b3]
 * 		hton( (void*) &ptr ,sizeof(int))
 * 		value -> [b3 b2 b1 b0]
 *
 * Text Editor : VIM
 * 
 * Warning : Do not pass a different datatype size
 *
 * */

#include <stdio.h> 
#include <stdlib.h>

void hton(void* vptr , int size);


int main(){ 
	
  	//hton(int)
	int i = 3879;
	printf("[int Before hton]\ti : %d\n",i);
	hton( (void*) &i,sizeof(int));
	printf("[int After hton]\ti : %d\n",i);
  
  	//hton(short)
  	int s = 15;
  	printf("[short Before hton]\ts : %d\n",s);
	hton( (void*) &s,sizeof(short));
	printf("[short After hton]\ts : %d\n",s);
  
	//hton(char*)
	char b[]="abcdef";
	printf("[char[] Before hton]\tc : %s\n",b);
	hton( (void*) b,6);
	printf("[char[] After hton]\tc : %s\n",b);
	return 0; 
}


void hton(void* vptr , int size){

	char* cptr = (char*) vptr;

	int c=0;
  
	//tmp pointer to save value that cptr pointing to
	char* tmp = malloc(size); 
  
	//save values in tmp
	for(int i = 0 ; i < size ; i++ , c++){
		*(tmp+c) = *(cptr+i);
	}	
  
  	c=size;
  
	//reverse process
	for(int i = 0 ; i < size ; i++ , c--){
		*(cptr + i) = *(tmp + (c - 1)); 
	}
  
	free(tmp);
  
}
