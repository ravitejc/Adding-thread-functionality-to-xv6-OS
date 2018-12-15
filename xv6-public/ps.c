#include "types.h"
#include "stat.h"
#include "user.h"
#include "uproc.h"
#define STDOUT 1

#define NPROC        64  // maximum number of processes

void getprocdata()
{
  int i = 0;
  struct uproc up;

  printf(STDOUT, "Name\tpid\tppid\tsize\tstate\t\twaiting_on_channel\tkilled\n");
  printf(STDOUT, "-----------------------------------------------------------------------------\n");

  for (i=0; i<NPROC; i++) {
    getprocinfo(i, &up);
    printf(STDOUT, "%s\t%d\t%d\t%d\t%s\t\t%d\t\t%d\n", up.name, up.pid, up.ppid, up.sz, states[up.state], up.wait, up.killed);
  }
  exit();
}

int
main(int argc, char *argv[])
{
  getprocdata();
  exit();
}
