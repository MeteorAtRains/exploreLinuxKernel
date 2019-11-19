#include <linux/wait.h>

#define wait_event(wq, condition)
do {
  if (condition)
    break;
  __wait_event(wq, condition);
} while (0)

#define __wait_event(wq, condition)
do {
  DEFINE_WAIT(__wait);
  
  for(;;) {
    prepare_to_wait(&wq, &__wait, TASK_UNINTERRUPTIBLE);
    if (condition)
      break;
    schedule();
  }
  finish_wait(&wq, &__wait);
} while (0)
