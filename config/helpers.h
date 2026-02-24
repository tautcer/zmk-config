#define MT_CORE \
    flavor = "tap-preferred"; \
    tapping-term-ms = <220>; \
    quick-tap-ms = <220>; \
    hold-trigger-key-positions = <0>;

#define OS_MORPH_IMPL(NAME, ALT_BINDING, DEF_BINDING) \
    NAME##_d: NAME##_d { \
        wait-ms = <0>; \
        tap-ms = <0>; \
        compatible = "zmk,behavior-macro"; \
        #binding-cells = <0>; \
        bindings \
            = <DEF_BINDING> \
            ; \
    }; \
    NAME##_a: NAME##_a { \
        wait-ms = <0>; \
        tap-ms = <0>; \
        compatible = "zmk,behavior-macro"; \
        #binding-cells = <0>; \
        bindings \
            = <ALT_BINDING> \
            ; \
    }; \
    NAME: NAME { \
        compatible = "zmk,behavior-layer-morph"; \
        #binding-cells = <0>; \
        layers = <ALT_OS>; \
        bindings \
            = <&NAME##_d> \
            , <&NAME##_a> \
            ; \
    };

#ifdef HOST_OS
#define OS_MORPH(NAME, ALT_BINDING, DEF_BINDING) \
    OS_MORPH_IMPL(NAME, ALT_BINDING, DEF_BINDING)
#else
#define OS_MORPH(NAME, ALT_BINDING, DEF_BINDING) \
    OS_MORPH_IMPL(NAME, DEF_BINDING, ALT_BINDING)
#endif

#define MACRO(NAME, BINDING) \
    ZMK_MACRO(NAME, \
        wait-ms = <5>; \
        tap-ms = <5>; \
        bindings = <BINDING>; \
    )

#define TAPHOLD_TP(NAME, TAP, HOLD) \
    ZMK_HOLD_TAP(NAME, bindings = <HOLD>, <TAP>; MT_CORE)

