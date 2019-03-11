# xv6_with_priority_scheduler
xv6 kernel with added feature of priority scheduling

Scheduler of xv6 operates now with a min-heap structure for the proccesses' priorities.
Priority of a proccess depends on its total running time (the less the better) in relation to the total being alive time (the more the better)

Differences from the original:
-proc.h: Adding to struct proc -> rtime,ctime,nsched
-proc.c: When a proc becomes runnable, it is inserted into minheap. Sched extracts from heap. Function printProc uses the syscall
-trap.c: Increase the running procs' time
-sysproc.c: new syscall printRunningProc (also changed syscall.c etc.)
-minheap.c/h
-w1,w2,w3,w4,w5: Workloads for testing scheduler.
