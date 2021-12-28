SRC += andy.c

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
    SRC += secrets.c
endif

MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
OLED_ENABLE = no
