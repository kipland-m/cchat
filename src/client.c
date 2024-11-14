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

	 connect(sockfd, &address, sizeof(address));

	 struct pollfd fds[2] = {
		 {
			 0, // file descriptor for stdin
			 POLLIN, // informs there is data to be read
			 0
		 },
		 {
			sockfd, // client file descriptor
			POLLIN,
			0
		 }	
	 };

	 for (;;) {
		 char buffer[256] = { 0 };

		 poll(fds, 2, 50000);

		 if (fds[0].revents & POLLIN) {
			 read(0, buffer, 255);
			 send(sockfd, buffer, 255, 0);
		 } 
		 else if (fds[1].revents & POLLIN) {
			 if (recv(sockfd, buffer, 255, 0) == 0) {
				 return 0;
			 }
			 printf("%s\n", buffer);
		 }
	 }

	 return 0; 
}
