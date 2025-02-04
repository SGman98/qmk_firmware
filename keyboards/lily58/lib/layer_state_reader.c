#include "action_layer.h"
#include <stdio.h>

// Base layers
#define L_COLEMAK 0                               // 0
#define L_QWERTY (1 << 1)                         // 2

#define L_NUMS (1 << 2)                           // 4
#define L_SYMS (1 << 3)                           // 8
#define L_NAV (1 << 4)                            // 16
#define L_CONFIG (1 << 5)                         // 32
#define L_CONFIG_TRI (L_CONFIG | L_NUMS | L_SYMS) // 44

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_COLEMAK:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Colemak");
    break;
  case L_QWERTY:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Qwerty");
    break;

  case L_NUMS:
  case (L_NUMS | L_QWERTY):
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Nums");
    break;
  case L_SYMS:
  case (L_SYMS | L_QWERTY):
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Syms");
    break;
  case L_NAV:
  case (L_NAV | L_QWERTY):
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Nav");
    break;
  case L_CONFIG:
  case L_CONFIG_TRI:
  case (L_CONFIG | L_QWERTY):
  case (L_CONFIG_TRI | L_QWERTY):
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Config");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%u", layer_state);
  }

  return layer_state_str;
}
