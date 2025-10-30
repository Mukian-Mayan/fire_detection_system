# 🔥 Fire & Gas Detection System (Arduino)

## Project Overview

This embedded system project is designed to enhance safety by detecting multiple hazards—specifically **smoke/gas leakage** and **direct fire presence**—and immediately triggering local audio-visual alerts. It utilizes a microcontroller (Arduino Uno) to monitor sensor thresholds and indicate the safety status in real-time.

* [cite_start]**Objective**: To detect smoke, fire, or gas leakage and trigger alerts (buzzer, LEDs, or LCD) for safety and quick response[cite: 3].
* [cite_start]**Core Technology**: Sensor calibration and threshold-based logic[cite: 16].

## 🛠️ Components Used

| Component | Purpose | Notes |
| :--- | :--- | :--- |
| **Arduino Uno** | [cite_start]Central controller and logic executor[cite: 4]. | |
| **MQ-2 Gas Sensor** | [cite_start]Detects smoke, LPG, CO, or methane[cite: 4]. | [cite_start]Needs a 20-second warm-up time after power-on[cite: 18]. |
| **Flame Sensor** | [cite_start]Detects the presence of fire (infrared light)[cite: 4]. | [cite_start]Potentiometer can be adjusted to control sensitivity[cite: 18]. |
| **Buzzer** | [cite_start]Gives a loud audio alarm when danger is detected[cite: 4, 9]. | |
| **LEDs (Red, Green)** | [cite_start]Indicate safe/danger states (Green = SAFE, Red = DANGER)[cite: 4, 11]. | |
| **16x2 LCD** | [cite_start]Displays "SAFE" or "DANGER" messages and real-time status (Optional)[cite: 4, 20]. | |
| **Power Supply (5V)** | [cite_start]Powers the circuit[cite: 4]. | |

## Working Principle

1.  [cite_start]**Monitoring**: The MQ-2 Gas Sensor monitors air quality, and the Flame Sensor actively searches for fire[cite: 7, 8].
2.  **Logic**: The Arduino continuously checks the analog/digital output of both sensors against a predefined danger threshold.
3.  [cite_start]**Alert**: If either sensor crosses the threshold, the Arduino activates the **Buzzer** and the **Red LED** (indicating danger), while turning off the Green LED[cite: 9].
4.  [cite_start]**Idle/Safe**: When conditions are normal, the Green LED stays ON, the Red LED is OFF, and the system remains idle[cite: 11].
5.  [cite_start]**Handling False Alarms**: The system incorporates debouncing/averaging logic to mitigate sensor false alarms[cite: 18].

## Wiring & Setup

*(**TODO**: Add a Fritzing or hand-drawn diagram and a pinout table here.)*

**Key Connections:**

* **MQ-2 Sensor A0** -> Arduino Analog Pin **A0**
* **Flame Sensor D0** -> Arduino Digital Pin **2**
* **Buzzer** -> Arduino Digital Pin **9**
* **Green LED** -> Arduino Digital Pin **7**
* **Red LED** -> Arduino Digital Pin **8**

## Getting Started

1.  Clone the repository:
    ```bash
    git clone [Your-Repo-URL]
    ```
2.  Open the project in your IDE (e.g., Arduino IDE, PlatformIO, or VS Code).
3.  Ensure you have the necessary libraries installed (e.g., `LiquidCrystal.h` for the LCD).
4.  Upload the code (`main.c` or `main.ino`) to the **Arduino Uno**.
5.  [cite_start]Wait **~20 seconds** after power-on for the MQ-2 sensor to properly warm up[cite: 18].

---

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