//Read random data (10000 chars at a time) in combination with useless time-consuming computations for scheduler test
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
	int garbage = 0;
	fd1 = open("testfile4",O_CREATE);
	close(fd1);
	
	for (int i = 1; i < 1000000; i++)
	{
		fd = open("cat",0);
		fd1 = open("testfile4",1);
		while(read(fd,buf,sizeof(buf))>0)
		{
			for (int k = 1; k < LIMIT; k++)
			{
				if ((i-k)%4==0 || (i-k)%4==1)
					garbage+=12345*225-234*3.4+i;
				else
					garbage-=12345*2*3-i;
			}
			//write(1,"aerfd\n",6);
			write(fd1,buf,sizeof(buf));
			
			//printf(1,"w5 ends, garbage value = %d\n",garbage);
		}
		close(fd1);
		close(fd);
		
		
	}
	
	printf(1,"w5 ends, garbage value = %d\n",garbage);
	exit();
}
