#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "x86.h"
#include "proc.h"
#include "minheap.h"

struct node{
	double priority;
	struct proc* procptr;
};

struct node heap[NPROC];
int heapSize=0;

int MH_isEmpty()
{
	return heapSize == 0;
}

void switch_nodes(int i,int j)//only for local use of minheap!!!
{
	struct proc* tempp = heap[i].procptr;
	double temp = heap[i].priority;
	
	heap[i].procptr = heap[j].procptr;
	heap[i].priority = heap[j].priority;
	
	heap[j].procptr = tempp;
	heap[j].priority = temp;
}
void print()///////FOR TESTING ONLY!!!
{
	cprintf("heapsize=%d:\n",heapSize);
	for (int i = 0; i < heapSize; i++)
	{
		cprintf("%d----pid:%d,name:%s,priority:%d\n",i,heap[i].procptr->pid,heap[i].procptr->name,(int)(1000*heap[i].priority));
	}
	
	
}
void MH_insert(struct proc* procptr,double p)
{
	//cprintf("before INSERT ->");
	//print();
	
	//insert at last
	heap[heapSize].procptr=procptr;
	heap[heapSize++].priority=p;
	
	//put it in the right position
	int i = heapSize - 1;
	while ((i-1)/2 >= 0) //while not in the root
		if (heap[i].priority < heap[(i-1)/2].priority)	//if child < parent then switch them and continue
		{
			switch_nodes(i,(i-1)/2);
			i = (i-1)/2;
		}
		else //no need to continue
			break;
	
	//cprintf("after INSERT ->");
	//print();
}

struct proc* MH_pop()
{
	//cprintf("before POP ->");
	//print();
	
	//keep the first
	struct proc* item = heap[0].procptr;
	heapSize--;
	
	//last -> first
	switch_nodes(heapSize,0);
	
	//fix the heap
	int i = 0;
	while (heapSize > 2*i + 1)//while there is at least one child
	{
		int minpos;
		if (2*i + 1 == heapSize - 1)//if it has one child only
			minpos = 2*i+1;
		else if (heap[2*i+1].priority > heap[2*i+2].priority)//keep the minimum child
			minpos = 2*i+2;
		else
			minpos = 2*i+1;
		
		if (heap[i].priority > heap[minpos].priority)//if parent > child then switch them and continue
		{
			switch_nodes(i,minpos);
			i=minpos;
		}
		else //no need to continue
			break;
	}
	
	//cprintf("after POP ->");
	//print();
	return item;
}
