#ifndef COREINTH_H
#define COREINTH_H

#include <stdint.h>

// Register Offsets
#define COREINTH_VERSION      0x00
#define COREINTH_LINUX_CTRL   0x04
#define COREINTH_LIM_CTRL     0x08
#define COREINTH_ITIM_CTRL    0x0C

// Counter Register Offsets
#define COREINTH_LINUX_0      0x10
#define COREINTH_LINUX_1      0x14
#define COREINTH_LINUX_2      0x18
#define COREINTH_LINUX_3      0x1C
#define COREINTH_LINUX_4      0x20
#define COREINTH_LINUX_5      0x24
#define COREINTH_LINUX_6      0x28
#define COREINTH_LINUX_7      0x2C
#define COREINTH_LINUX_8      0x30
#define COREINTH_LINUX_9      0x34

#define COREINTH_LIM_0        0x40
#define COREINTH_LIM_1        0x44
#define COREINTH_LIM_2        0x48
#define COREINTH_LIM_3        0x4C
#define COREINTH_LIM_4        0x50
#define COREINTH_LIM_5        0x54
#define COREINTH_LIM_6        0x58
#define COREINTH_LIM_7        0x5C
#define COREINTH_LIM_8        0x60
#define COREINTH_LIM_9        0x64

#define COREINTH_ITIM_0       0x80
#define COREINTH_ITIM_1       0x84
#define COREINTH_ITIM_2       0x88
#define COREINTH_ITIM_3       0x8C
#define COREINTH_ITIM_4       0x90
#define COREINTH_ITIM_5       0x94
#define COREINTH_ITIM_6       0x98
#define COREINTH_ITIM_7       0x9C
#define COREINTH_ITIM_8       0xA0
#define COREINTH_ITIM_9       0xA4

#define COREINTH_VERSION_VALUE 0x1  // Expected Version Register Value

#define COREINTH_NUM_COUNTERS   0xA
// Function Prototypes
int coreinth_init(void);
uint32_t read_reg(uint32_t);
void write_reg(uint32_t, uint32_t);

#endif // APB_INT_COUNT_H
