//=============================================================================
//=============================================================================
#ifndef CYCLE_TOOL_H
#define CYCLE_TOOL_H
//=============================================================================
#include <stdint.h>
//=============================================================================
class CycleTool {
    public:
        enum class Mode : uint8_t {OFF, ON};

        explicit CycleTool(const char* tag, uint32_t timeout = 500);            // Constructor with tag, and timeout
        void before();                                                          // Mark cycle start
        void after();                                                           // Mark cycle end and calculate stats
        void setTimeout(uint32_t timeout);                                      // Set new timeout
        void enable();                                                          // Enable
        void disable();                                                         // Disable
        enum{OFF, ON};                                                          // {OFF, ON}

    private:
        const char* tag;                                                        // Log tag
        uint64_t timer;                                                         // Periodic log timer
        uint32_t timeout;                                                       // Timeout threshold
        uint32_t start;                                                         // Cycle start time
        uint32_t lastTime;                                                      // Last measurement time
        uint32_t timeoutCntr;                                                   // Timeout counter
        uint32_t maxCycleDuty;                                                  // Max cycle duration
        uint32_t cycleCntr;                                                     // Cycle counter
        float cycle;                                                            // Sliding average cycle time
        Mode mode = Mode::OFF;                                                  // Operation mode
};
//=============================================================================
#endif