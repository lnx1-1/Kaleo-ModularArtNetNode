# Project TODOs

## Hardware & Pin Conflicts

- [ ] **GPIO 5 Conflict**: Resolve conflict between `I2C_SDA_Pin` and `Stepper PIN_DIRECTION`. (Both currently set to
  GPIO 5).
    - *Context*: Required when moving to final hardware layout or adding more modules.

## Features & Improvements

- [ ] **DHCP & Network Fallback**:
    - [ ] Add `use_dhcp` setting in `Config`.
    - [ ] Implement detection of invalid static IP (e.g., gateway not reachable).
    - [ ] Logic: Static IP -> Fallback to DHCP -> Fallback to WiFi Access Point.
- [ ] **WiFi Captive Portal**:
    - [ ] Implement WiFi AP mode if Ethernet fails.
    - [ ] Integrate a DNS server to redirect all requests to the configuration page.
    - [ ] Add timeout for AP mode (auto-off after X minutes).
    - [ ] Simplify `CaptivePortal.html` or adapt current `WebInterface` for mobile-friendly setup.
- [ ] **DMX Fallback**:
    - [ ] Configurable timeout (ms).
    - [ ] Fallback mode: blackout or hold last.
- [ ] **DMX Driver Mode Switching**:
    - [ ] Cleanly enable/disable DMX driver when switching input modes.
- [ ] **OTA Updates (Over-The-Air)**:
    - [ ] Implement Web-based OTA (Upload `.bin` via browser).
    - [ ] (Optional) Add `ArduinoOTA` for developer convenience.
- [ ] **Gamma Correction**: Implement Gamma Correction for LEDs to improve color perception (linear DMX to non-linear
  brightness).
    - *Reference*: Check [WLED implementation](https://github.com/wled/WLED) for efficient lookup tables.
- [ ] **Advanced UI**: Improve Webinterface with more interactive elements (Real-time DMX monitor, etc.).

## Documentation

- [ ] Document global pin mapping once finalized.
