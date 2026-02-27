#define MT_CORE \
    flavor = "tap-preferred"; \
    tapping-term-ms = <220>; \
    quick-tap-ms = <220>; \
    hold-trigger-key-positions = <0>;

#define MACRO(NAME, BINDING) \
    ZMK_MACRO(NAME, \
        wait-ms = <5>; \
        tap-ms = <5>; \
        bindings = <BINDING>; \
    )

#define TAPHOLD_TP(NAME, TAP, HOLD) \
    ZMK_HOLD_TAP(NAME, \
      flavor = "tap-preferred"; \
      #binding-cells = <2>; \
      tapping-term-ms = <250>; \
      quick-tap-ms = <175>; \
      require-prior-idle-ms = <175>; \
      bindings = <HOLD>, <TAP>; \
)
