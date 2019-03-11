//Read random data (10000 chars at a time) from random file for scheduler test
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define LIMIT 10000000
int
main(void)
{
	char *buf;
	buf = malloc(10000);
	int fd,fd1;
	fd1 = open("testfile2",O_CREATE);
	close(fd1);
	//fd1 = open("testfile2",1);
	//fd = open("usertests",0);
	for (int k = 1; k < LIMIT; k++)
	{
		fd = open("ln",0);
		fd1 = open("testfile2",1);
		while(read(fd,buf,sizeof(buf))>0)write(fd1,buf,sizeof(buf));
		close(fd1);
		close(fd);
	}
	//close(fd);
	//close(fd1);
	printf(1,"w3 ends\n");
	exit();
}
