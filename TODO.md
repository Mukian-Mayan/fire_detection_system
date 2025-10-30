## TODO.md

This file tracks the current status, known issues, and future plans for your project.

```markdown
# Project TODO List

This document tracks immediate tasks, known issues, and future enhancement ideas for the Fire & Gas Detection System.

## Phase 1: Core Functionality (Current Focus)

* [ ] Complete the basic sensor reading loop in `main.c`.
* [ ] Implement the **threshold logic** to differentiate safe/danger states.
* [ ] Finalize the I/O pin definitions in `system_config.h` (or similar file).
* [ ] Write and test the `buzzer_activate()` and `led_update()` functions.
* [ ] **Fix**: Implement the **20-second warm-up delay** after system initialization for the MQ-2 sensor[cite: 18].

## Known Issues & Bugs

* [ ] **Sensor Flapping**: Occasionally, sensor readings fluctuate near the threshold, causing the buzzer to rapidly turn on and off.
    * **Fix**: Implement code to **average readings** over a short period (e.g., 5 readings) to prevent false alarms[cite: 18].
* [ ] **Flame Sensor Over-Sensitivity**: The flame sensor is currently triggering alarms even with ambient light.
    * **Fix**: Adjust the **potentiometer** on the physical flame sensor module, then fine-tune the software threshold[cite: 18].

## Enhancement Ideas (Future)

* [ ] **LCD Integration**: Display **"SAFE"** or **"DANGER"** status, and show raw or calibrated gas readings in real-time[cite: 4, 20].
* [ ] **Data Logging**: Log trigger events (time, sensor value) to an SD card for post-event analysis[cite: 21].
* [ ] **Mitigation**: Add a relay to auto-activate a small fan or exhaust system when danger is detected[cite: 20].
* [ ] **Calibration Routine**: Implement a user-activated routine to dynamically calibrate the sensor's "safe" baseline.