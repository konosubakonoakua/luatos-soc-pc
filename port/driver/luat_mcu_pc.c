
#include "uv.h"

#include "luat_base.h"
#include "luat_msgbus.h"
#include "luat_malloc.h"
#include "luat_mcu.h"

#include "luat_pcconf.h"

#define LUAT_LOG_TAG "mcu"
#include "luat_log.h"

extern luat_pcconf_t g_pcconf;

int luat_mcu_set_clk(size_t mhz) {
    return 0;
}
int luat_mcu_get_clk(void) {
    return g_pcconf.mcu_mhz;
}

extern uv_timespec64_t boot_ts;

const char* luat_mcu_unique_id(size_t* t) {
    *t = g_pcconf.mcu_unique_id_len;
    return (const char*)g_pcconf.mcu_unique_id;
}

long luat_mcu_ticks(void) {
    return luat_mcu_tick64() / 1000;
}
uint32_t luat_mcu_hz(void) {
    return 1;
}

uint64_t uv_startup_ns;
uint64_t luat_mcu_tick64(void) {
    uint64_t ns = uv_hrtime();
    return (ns - uv_startup_ns) / 1000;
}

int luat_mcu_us_period(void) {
    return 1;
}

uint64_t luat_mcu_tick64_ms(void) {
    return luat_mcu_tick64() / 1000;
}

void luat_mcu_set_clk_source(uint8_t source_main, uint8_t source_32k, uint32_t delay) {
    // nop
}

void luat_mcu_iomux_ctrl(uint8_t type, uint8_t sn, int pad_index, uint8_t alt, uint8_t is_input) {
    // nop
}

void luat_mcu_set_hardfault_mode(int mode) {
    // nop
}

void luat_mcu_xtal_ref_output(uint8_t main_enable, uint8_t slow_32k_enable) {;}
int luat_uart_pre_setup(int uart_id, uint8_t use_alt_type){return -1;}
int luat_i2c_set_iomux(int id, uint8_t value){return -1;}
