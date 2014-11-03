#include <pebble.h>
#include "main.h"
#include "service.h"

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_gothic_14;
static TextLayer *battery_percent_label;
static TextLayer *battery_percent_layer;
static TextLayer *charge_status_layer;
static TextLayer *charge_status_label;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  window_set_fullscreen(s_window, 0);
  
  s_res_gothic_14 = fonts_get_system_font(FONT_KEY_GOTHIC_14);
  // battery_percent_label
  battery_percent_label = text_layer_create(GRect(10, 32, 86, 20));
  text_layer_set_background_color(battery_percent_label, GColorClear);
  text_layer_set_text_color(battery_percent_label, GColorWhite);
  text_layer_set_text(battery_percent_label, "battery level:");
  layer_add_child(window_get_root_layer(s_window), (Layer *)battery_percent_label);
  
  // battery_percent_layer
  battery_percent_layer = text_layer_create(GRect(96, 32, 34, 20));
  text_layer_set_background_color(battery_percent_layer, GColorClear);
  text_layer_set_text_color(battery_percent_layer, GColorWhite);
  text_layer_set_text(battery_percent_layer, "100%");
  text_layer_set_text_alignment(battery_percent_layer, GTextAlignmentRight);
  text_layer_set_font(battery_percent_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)battery_percent_layer);
  
  // charge_status_layer
  charge_status_layer = text_layer_create(GRect(65, 10, 65, 20));
  text_layer_set_background_color(charge_status_layer, GColorClear);
  text_layer_set_text_color(charge_status_layer, GColorWhite);
  text_layer_set_text(charge_status_layer, "unplugged");
  text_layer_set_text_alignment(charge_status_layer, GTextAlignmentRight);
  text_layer_set_font(charge_status_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)charge_status_layer);
  
  // charge_status_label
  charge_status_label = text_layer_create(GRect(10, 10, 50, 20));
  text_layer_set_background_color(charge_status_label, GColorClear);
  text_layer_set_text_color(charge_status_label, GColorWhite);
  text_layer_set_text(charge_status_label, "status:");
  layer_add_child(window_get_root_layer(s_window), (Layer *)charge_status_label);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(battery_percent_label);
  text_layer_destroy(battery_percent_layer);
  text_layer_destroy(charge_status_layer);
  text_layer_destroy(charge_status_label);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  detach_ui();
  destroy_ui();
}

void show_main(void) {
  initialise_ui();
  attach_ui(battery_percent_layer, charge_status_layer);
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_main(void) {
  window_stack_remove(s_window, true);
}
