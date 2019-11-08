#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int priority;
  int pid;
  
  if (argc <= 2)
  {
    printf(2, "Usage error: Needs 2 arguments\n");
    exit();
  }
  pid = atoi ( argv[1] );
  priority = atoi ( argv[2] );
  if ( priority < 0 || priority > 20 )
  {
    printf(2, "Priority out of range\n");
    exit();
  }
  chpr ( pid, priority );
  exit();
}
