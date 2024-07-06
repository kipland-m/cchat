#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 9000

void error(const char *msg){
	perror(msg);
	exit(1);
}

int main(){
    printf("test");
}

