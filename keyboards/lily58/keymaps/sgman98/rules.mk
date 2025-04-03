CAPS_WORD_ENABLE = yes      # Word-wise capitalization
EXTRAKEY_ENABLE = yes       # Audio control and System control
LTO_ENABLE = yes            # Link Time Optimization enabled
MOUSEKEY_ENABLE = yes       # Mouse keys
NKRO_ENABLE = yes           # N-Key Rollover
OLED_ENABLE = yes           # OLED display
TAP_DANCE_ENABLE = yes      # Tap dance
KEY_OVERRIDE_ENABLE = yes   # Enable key override
REPEAT_KEY_ENABLE = yes     # Enable repeat key
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite

# If you want to change the display of OLED, you need to change here
SRC += ./lib/logo_reader.c
