#include "c_util.h"

pthread_mutex_t g_lock_print;

int main() {
  pthread_mutex_init(&g_lock_print, NULL);
  int array_len = 0;
  // char buf[]="round-trip min/avg/max = 50.294/56.765/65.589 ms\nround-trip
  // min/avg/max = 50.294/56.765/65.589 ms\nround-trip min/avg/max
  // = 50.294/56.765/65.589 ms";
  char buf[] = "round-trip min/avg/max = 61.542/68.705/75.211 ms";

  if (startswith(buf, "round-trip")) {
    char *cur_date = getFormatTime();
    printf("cur_date %s \n", cur_date);
    free(cur_date);
    char **split_arr = split(buf, "/", &array_len);

    for (int i = 0; i < array_len; i++) {
      printf("== split %d : value %s\n", i, split_arr[i]);
    }

    // free the malloced memory
    for (int i = 0; i < array_len; i++) {
      free(split_arr[i]);
    }
    free(split_arr);
  }
  pthread_mutex_destroy(&g_lock_print);
  return 0;
}
