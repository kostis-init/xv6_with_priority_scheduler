//Read random data (one char at a time) from random file for scheduler test
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define LIMIT 10000000
int
main(void)
{
	char buf[1];
	int fd,fd1;
	fd1 = open("testfile1",O_CREATE);
	close(fd1);
	//fd = open("usertests",0);
	//fd1 = open("testfile1",1);
	for (int i = 1; i < LIMIT; i++)
	{
		fd = open("grep",0);
		fd1 = open("testfile1",1);
		while(read(fd,buf,1)>0)write(fd1,buf,1);
		close(fd1);
		close(fd);
	}
	//close(fd1);
	//close(fd);
	printf(1,"w2 ends\n");
	exit();
}
