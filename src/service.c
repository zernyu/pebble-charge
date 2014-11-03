#include <pebble.h>
#include "service.h"
  
static TextLayer *battery_percent_layer;
static TextLayer *charge_status_layer;

static void handle_battery(BatteryChargeState charge_state) {
  static char battery_text[] = "100%";
  snprintf(battery_text, sizeof(battery_text), "%d%%", charge_state.charge_percent);
  text_layer_set_text(battery_percent_layer, battery_text);
  
  static char charge_status_text[] = "unplugged";
  if (charge_state.is_charging) {
    snprintf(charge_status_text, sizeof(charge_status_text), "charging");
  } else if (charge_state.is_plugged) {
    snprintf(charge_status_text, sizeof(charge_status_text), "charged");
  } else {
    snprintf(charge_status_text, sizeof(charge_status_text), "unplugged");
  }
  text_layer_set_text(charge_status_layer, charge_status_text);
}

void attach_ui(TextLayer *set_battery_percent_layer, TextLayer *set_charge_status_layer) {
  battery_percent_layer = set_battery_percent_layer;
  charge_status_layer = set_charge_status_layer;
  battery_state_service_subscribe(&handle_battery);
  handle_battery(battery_state_service_peek());
}

void detach_ui() {
  battery_state_service_unsubscribe();
}