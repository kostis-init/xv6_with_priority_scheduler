//something useless but time-consuming (approx 6 minutes) to check our scheduler
#include "types.h"
#include "stat.h"
#include "user.h"

#define LIMIT 1000000
int
main(void)
{
	int garbage = 0;
	for (int i = 1; i < LIMIT; i++)
		for (int k = 1; k < LIMIT; k++)
			if ((i-k)%4==0 || (i-k)%4==1)
				garbage+=12*245+534*3;
			else
				garbage-=12345-234*3.4;

	printf(1,"w1 ends, garbage value = %d\n",garbage);
	exit();
}
