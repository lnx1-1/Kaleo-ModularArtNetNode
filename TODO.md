# Project TODOs

## Hardware & Pin Conflicts

- [ ] **GPIO 5 Conflict**: Resolve conflict between `I2C_SDA_Pin` and `Stepper PIN_DIRECTION`. (Both currently set to
  GPIO 5).
    - *Context*: Required when moving to final hardware layout or adding more modules.

## Features & Improvements

- [ ] **Gamma Correction**: Implement Gamma Correction for LEDs to improve color perception (linear DMX to non-linear
  brightness).
    - *Reference*: Check [WLED implementation](https://github.com/wled/WLED) for efficient lookup tables.
- [ ] **Advanced UI**: Improve Webinterface with more interactive elements (Real-time DMX monitor, etc.).

## Documentation

- [ ] Document global pin mapping once finalized.
