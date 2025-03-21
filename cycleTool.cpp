//=============================================================================
//=============================================================================
#define CYCLE_TOOL_CPP
//=============================================================================
#include "cycleTool.h"
#include "esp_timer.h"
#include "esp_log.h"
//=============================================================================
CycleTool::CycleTool(const char* tag, uint32_t timeout)
    : tag(tag), timeout(timeout) {}
//---------------------------
void CycleTool::before()
{
    if(mode == Mode::OFF) return;
    start = esp_timer_get_time();
}
//---------------------------
void CycleTool::after()
{
    if(mode == Mode::OFF) return;

    uint32_t time = esp_timer_get_time();
    uint32_t period = time - lastTime;
    uint32_t crntCycle = time - start;

    if (crntCycle > maxCycleDuty) maxCycleDuty = crntCycle;
    cycleCntr++;
    cycle += (crntCycle - cycle) * 0.005f;
    lastTime = time;

    if (period > timeout) timeoutCntr++;
    if (timer > time) return;

    ESP_LOGI(tag, "cntr - %lu, cycle - %lu, max - %lu, total cycles - %lu",
                  timeoutCntr, (uint32_t)cycle, maxCycleDuty, cycleCntr);
    timer = time + 1000000;
    maxCycleDuty = 0;
    timeoutCntr = 0;
    cycleCntr = 0;
}
//---------------------------
void CycleTool::enable()
{
    mode = Mode::ON;
    esp_log_level_set(tag, ESP_LOG_INFO);
}
//---------------------------
void CycleTool::disable()
{
    mode = Mode::OFF;
}
//---------------------------
void CycleTool::setTimeout(uint32_t timeout)
{
    this->timeout = timeout;
}
//=============================================================================
