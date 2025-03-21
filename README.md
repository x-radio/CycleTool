# CycleTool
A lightweight utility class for ESP32 to measure cycle times and track timeouts.

## Purpose
CycleTool is designed for profiling and monitoring execution cycles in ESP32-based projects. It helps:
- Measure the time between before() and after() calls.
- Calculate sliding average cycle time, maximum cycle duration, and timeout occurrences.
- Log cycle statistics periodically using ESP-IDF logging.

## Features
- Configurable timeout threshold.
- Enable/disable functionality.
- Periodic logging of cycle statistics (timeout count, average cycle, max cycle, total cycles).

## Installation
1. Clone this repository:
git clone https://github.com/x-radio/CycleTool.git
2. Copy cycleTool.h and cycleTool.cpp into your ESP-IDF project’s components directory.
3. Include it in your code:
#include "cycleTool.h"

## Usage Example
```cpp
#include "cycleTool.h"
void app_main() {
    // Initialize CycleTool with tag and 500ms timeout
    CycleTool tool("MyApp", 500);

    tool.enable();              // Start monitoring

    while (true) {
        tool.before();          // Mark cycle start
        // Your code here
        tool.after();           // Mark cycle end and process stats
    }
}
```
## API
- CycleTool(const char* tag, uint32_t timeout = 500): Constructor.
- void before(): Marks the start of a cycle.
- void after(): Marks the end, calculates stats, and logs periodically.
- void enable(): Enables the tool and sets log level to INFO.
- void disable(): Disables the tool.
- void setTimeout(uint32_t timeout): Updates the timeout threshold.

## Dependencies
- ESP-IDF (uses esp_timer and esp_log).

## License
MIT License (see LICENSE file).