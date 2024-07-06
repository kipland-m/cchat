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

int main(int argc, char *argv[]){
	if (argc < 2){
		fprintf(stderr, "please provide a port #\n");
		exit(1);
	}

	int sockfd, newsockfd, portno;
	char buffer[255];

	struct sockaddr_in serv_addr, cli_addr;
	printf("\ntest");
}


