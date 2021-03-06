#include "tests.h"
#include <sys/syscall.h>

#ifdef __NR_epoll_wait

# include <stdio.h>
# include <sys/epoll.h>
# include <unistd.h>

int
main(void)
{
	struct epoll_event *const ev = tail_alloc(sizeof(*ev));

	long rc = syscall(__NR_epoll_wait, -1, ev, 1, -2);
	printf("epoll_wait(-1, %p, 1, -2) = %ld %s (%m)\n",
	       ev, rc, errno2name());

	puts("+++ exited with 0 +++");
	return 0;
}

#else

SKIP_MAIN_UNDEFINED("__NR_epoll_wait")

#endif
