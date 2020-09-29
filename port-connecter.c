//a simple c tool for connecting to a port and recive the connection
//tool author: krisna pranav
//dont forget to follow me on github

//imports
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socketvar.h>

//sockaddr
struct sockaddr_in dest;

//main function
int main(){
	int msocket, con, port;
	printf("Enter The Port To Connect > ")
	scanf("%d", &port);

	if ((msocket = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket");
		exit()
	}
	dest.sin_family = AF_INET;
	dest.sin_port = htons(port);
	bzero(dest.sin_zero, sizeof(dest.sin_zero))


	if ((con = connect(msocket, (struct sockaddr *)&dest, sizeof(dest))) == -1){
		perror("connect")
		close(msocket)
		exit(1);
	}else{
		printf("%d Port Is Open And Connected Successfully \n ", port);
		exit(1);
	}
	return 0;

}
	
