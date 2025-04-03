const char *read_logo(void);

//
// Rotate OLED display
//
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;
    return OLED_ROTATION_270;
}

//
// Render left OLED display
//
static void render_status(void) {
    // Layer indicator
    oled_write_P(PSTR("LAYER"), false);

    // Layer name
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWER "), false);
            break;
        case _NUMS:
            oled_write_P(PSTR("NUMS "), false);
            break;
        case _SYMS:
            oled_write_P(PSTR("SYMS "), false);
            break;
        case _NAV:
            oled_write_P(PSTR(" NAV "), false);
            break;
        case _CONFIG:
            oled_write_P(PSTR("CONF "), false);
            break;
        default:
            oled_write_P(PSTR("COLE "), false);
            break;
    }
    oled_write_P(PSTR("\n"), false);
}

//
// OLED display rendering
//
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        oled_write(read_logo(), false);
    }
    return true;
}
