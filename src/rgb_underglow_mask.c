#include <zephyr/devicetree.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/led_strip.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#define MASK_NODE DT_COMPAT_GET_ANY_STATUS_OKAY(zmk_zmk_rgb_underglow_mask_leds)

#if DT_NODE_EXISTS(MASK_NODE) && DT_NODE_HAS_PROP(MASK_NODE, led_mask)

static const uint32_t masked_leds[] = DT_PROP(MASK_NODE, led_mask);

void zmk_rgb_underglow_update_hook(struct led_rgb *pixels, size_t count) {
    size_t i = 0;
    for (; i < sizeof(masked_leds) / sizeof(*masked_leds); i++) {
        LOG_DBG("%s masking LED #%u", __func__, masked_leds[i]);
        memset(&pixels[masked_leds[i]], 0, sizeof(*pixels));
    };
}

#else

#warning "no zmk,zmk-rgb-underglow-mask-leds node found in devicetree"

#endif
