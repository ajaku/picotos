.global loop

loop:
    cpsid if

    ldr r0, =#25
    ldr r1, =#0
    b my_gpio_put
    cpsie if