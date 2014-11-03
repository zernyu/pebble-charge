#include <pebble.h>
#include "main.h"
  
static void init(void) {
  show_main();
}

static void deinit(void) {
  hide_main();
}
  
int main(void) {
  init();
  app_event_loop();
  deinit();
  
  return 0;
}