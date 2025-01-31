ENCODER_ENABLE = no
EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes
RGBLIGHT_ENABLE = no
BOOTMAGIC_ENABLE = no
MOUSEKEY_ENABLE = yes
REPEAT_KEY_ENABLE = yes
LAYER_LOCK_ENABLE = yes
LEADER_ENABLE = yes

# https://github.com/getreuer/qmk-keymap

SRC += features/achordion.c

# https://docs.qmk.fm/#/feature_caps_word?id=caps-word
CAPS_WORD_ENABLE = yes

# # https://docs.qmk.fm/#/custom_quantum_functions?id=deferred-execution
DEFERRED_EXEC_ENABLE = yes
