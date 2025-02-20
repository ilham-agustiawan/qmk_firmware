EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes
MOUSEKEY_ENABLE = yes
REPEAT_KEY_ENABLE = yes
LAYER_LOCK_ENABLE = yes
LEADER_ENABLE = yes

# https://docs.qmk.fm/#/feature_caps_word?id=caps-word
CAPS_WORD_ENABLE = yes

# # https://docs.qmk.fm/#/custom_quantum_functions?id=deferred-execution
DEFERRED_EXEC_ENABLE = yes

# save firmware space
BOOTMAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
ENCODER_ENABLE = no       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow

# https://github.com/getreuer/qmk-keymap

SRC += features/achordion.c

ORBITAL_MOUSE_ENABLE ?= yes
ifeq ($(strip $(ORBITAL_MOUSE_ENABLE)), yes)
	MOUSE_ENABLE = yes
	OPT_DEFS += -DORBITAL_MOUSE_ENABLE
	SRC += features/orbital_mouse.c
endif

# From qmk-vim
# note that the order is important here
SRC += qmk-vim/src/mac_mode.c
SRC += qmk-vim/src/process_func.c
SRC += qmk-vim/src/numbered_actions.c
SRC += qmk-vim/src/motions.c
SRC += qmk-vim/src/actions.c
SRC += qmk-vim/src/modes.c
SRC += qmk-vim/src/vim.c
