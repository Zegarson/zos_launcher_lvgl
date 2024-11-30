#include <stdlib.h>
#include <unistd.h>
#include "lvgl/lvgl.h"

static lv_display_t *hal_init(int32_t w, int32_t h);

int main(void) {
    lv_init();
    hal_init(368, 448);

    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello, LVGL!");
    lv_obj_center(label);

    while (1) {
        lv_timer_handler();
        usleep(5000);
    }

    return 0;
}

static lv_display_t *hal_init(int32_t w, int32_t h) {
    lv_display_t *disp = lv_sdl_window_create(w, h);
    lv_display_set_default(disp);
    return disp;
}
