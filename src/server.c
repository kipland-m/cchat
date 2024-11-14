#include <sys/socket.h>

int main(){
	 int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

	 struct sockaddr_in address = {
		 AF_INET,
		 htons(9999),
		 0,
		}

	 bind(sockfd, &addr, sizeof(address));

	 listen(sockfd, 10);

	 int clientfd = accept(sockfd, 0, 0); 

	 struct pollfd[2] = {
		 {
			 0,
		 },
		 {
			0,
		 }	
	 };

}
