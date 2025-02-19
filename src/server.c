#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <poll.h>
#include <unistd.h>

int main(){
	 int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	 struct sockaddr_in address = {
		 AF_INET,
		 htons(9999),
		 0,
		};

	 bind(sockfd, &address, sizeof(address));

	 listen(sockfd, 10);

	 int clientfd = accept(sockfd, 0, 0); 

	 struct pollfd fds[2] = {
		 {
			 0, // file descriptor for stdin
			 POLLIN, // informs there is data to be read
			 0
		 },
		 {
			clientfd, // client file descriptor
			POLLIN,
			0
		 }	
	 };

	 for (;;) {
		 char buffer[256] = { 0 };

		 poll(fds, 2, 50000);

		 if (fds[0].revents & POLLIN) {
			 read(0, buffer, 255);
			 send(clientfd, buffer, 255, 0);
		 } 
		 else if (fds[1].revents & POLLIN) {
			 recv(clientfd, buffer, 255, 0);
			 printf("%s\n", buffer);
		 }
	 }

	 return 0; 
}
