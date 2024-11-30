#include <stdlib.h>
#include <unistd.h>
#include "lvgl/lvgl.h"

static lv_display_t *hal_init(int32_t w, int32_t h);
static void bg_click_event_handler(lv_event_t *e);

int main(void) {
    lv_init();
    hal_init(368, 448);

    lv_obj_t *scr = lv_scr_act();
    lv_obj_add_event_cb(scr, bg_click_event_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *label = lv_label_create(scr);
    lv_label_set_text(label, "Click the background!");
    lv_obj_center(label);

    while (1) {
        lv_timer_handler();
        usleep(5000);
    }

    return 0;
}

static lv_display_t *hal_init(int32_t w, int32_t h) {
    lv_display_t *disp = lv_sdl_window_create(w, h);

    lv_indev_t *mouse = lv_sdl_mouse_create();
    lv_indev_set_display(mouse, disp);

    lv_display_set_default(disp);
    return disp;
}

static void bg_click_event_handler(lv_event_t *e) {
    static bool is_color_toggled = false;

    if (is_color_toggled) {
        lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0xFFFFFF), 0); // White
    } else {
        lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0xFF0000), 0); // Red
    }

    is_color_toggled = !is_color_toggled;
}
