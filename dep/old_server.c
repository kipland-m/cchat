#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 9000

//  Creating error function to handle errors
void error(const char *msg){
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[]){
	// if command line args are less than 2, raise error
	// 1 = the command itself
	// 2 = given port number
	if (argc < 2){
		fprintf(stderr, "please provide a port number.\n");
		exit(1);
	}

	// initializing vars 
	// sockfd (socket file descriptor)
	// newsockfd (new file descriptor)
	// portno (port number)
	int sockfd, newsockfd, portno;
	char buffer[255];

	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen;

	// establishing socket
	// 0 == success
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0){
		error("error opening socket.");
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	
	portno = atoi(argv[1]);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
		error("binding failed.");
	}


}













