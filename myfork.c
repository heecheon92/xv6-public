#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "stat.h"

int main(int argc, char *argv[])
{
  int k;
  int n;
  int id = 0;
  int num;
  int count = 1;

  if ( argc < 2 )
  {
    n = 1;
  }
  else
  {
    n = atoi ( argv[1] );
  }
  
  if ( n < 0 || n > 20 )
  {
    n = 2;
  }

  for ( k = 0; k < n; k++)
  {
    id = fork();
    if ( id < 0)
    {
      printf(1, "%d failed in fork!\n", getpid());
    }
    else if (id == 0 )
    {
      printf(1, "Child %d created\n", getpid());
      for ( num = 0; num < 10000000000; num++)
      {
         count = count * num;
	 //sleep(1);
      }
      break;
    }
    else
    {
      printf(1, "Parent %d creating child %d\n", getpid(), id);

      wait ();

    }
  }
  printf(1, "Main program exited successfully.\n");
  exit();
}
