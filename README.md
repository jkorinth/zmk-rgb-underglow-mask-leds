# zmk-rgb-underglow-mask-leds

ZMK module that allows to use the new `zmk_rgb_underglow_update_hook` to mask RGB LEDs in the underglow strip.

## Example
Specify a node with `zmk,zmk-rgb-underglow-mask-leds` compatible string:

```dts
/ {
    masked {
        compatible = "zmk,zmk-rgb-underglow-mask-leds";
        // turn off LEDs at index 1, 8, 12
        led_mask = <1 8 12>;
    };
};
```

