#include <stdio.h>

int main(){

	struct addrinfo{
		int ai_flags;			// AI_PASSIVE, AI_CANONNAME, etc.
		int ai_family;			// AF_INET, AF_INET6
		int ai_socktype;
		int ai_protocol;
		size_t ai_addrlen;
		struct sockaddr *ai_addr;
		char *ai_canonname;

		struct addrinfo *ai_next;
	};
}
