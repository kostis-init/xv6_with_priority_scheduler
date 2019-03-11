//Read random data (one char at a time) in combination with useless time-consuming computations for scheduler test
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
	int garbage = 0;
	fd1 = open("testfile3",O_CREATE);
	close(fd1);
	
	for (int i = 1; i < 1000000; i++)
	{
		fd = open("echo",0);
		fd1 = open("testfile3",1);
		while(read(fd,buf,1)>0)
		{
			for (int k = 1; k < LIMIT; k++)
			{
				if ((i-k)%4==0 || (i-k)%4==1)
					garbage+=12345*245-234*3-i;
				else
					garbage-=12345*345-234*3+i;
			}
				//printf(1,"w4 ends, garbage value = %d\n",garbage);
			write(fd1,buf,1);
		}
		close(fd1);
		close(fd);
	}
	
		
	printf(1,"w4 ends, garbage value = %d\n",garbage);
	exit();
}
