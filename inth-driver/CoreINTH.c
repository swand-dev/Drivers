#include "coreinth.h"
#include <stdint.h>
#include "fpga_design_config/fpga_design_config.h"

#define ACK_SIGNAL_RECEIVED 1

// Function to read register value
uint32_t read_reg(uint32_t offset)
{
    return *((volatile uint32_t *)(COREINTH_BASE_ADDR + offset));
}

// Function to write register value
void write_reg(uint32_t offset, uint32_t value)
{
    *((volatile uint32_t *)(COREINTH_BASE_ADDR + offset)) = value;
}

// Initialize the IP Core
int coreinth_init(void)
{
    // Step 1: Check Version Register
    if (read_reg(COREINTH_VERSION) != COREINTH_VERSION_VALUE)
    {
        return -1; // Version mismatch error
    }

    // Step 2: Clear Control Registers
    write_reg(COREINTH_LINUX_CTRL, 0);
    write_reg(COREINTH_LIM_CTRL, 0);
    write_reg(COREINTH_ITIM_CTRL, 0);

    // Step 3: Clear Counter Registers
    for (int i = 0; i < COREINTH_NUM_COUNTERS ; i++)
    {
        write_reg(COREINTH_LINUX_0 + (i * 4), 0);
        write_reg(COREINTH_LIM_0 + (i * 4), 0);
        write_reg(COREINTH_ITIM_0 + (i * 4), 0);
    }

    return 0; // Initialization successful
}

// Main function to monitor control signals and read counter values
void coreinth_monitor(void)
{
    while (1)
    {
        // Wait for any of the control signals' LSB to be set
        while (!(read_reg(COREINTH_LINUX_CTRL) & 0x1) ||
               !(read_reg(COREINTH_LIM_CTRL) & 0x1) ||
               !(read_reg(COREINTH_ITIM_CTRL) & 0x1))
        {
            // Loop until control bit is set
        }

        // Wait for ACK signal from the master
        while (!ACK_SIGNAL_RECEIVED)
        {
            // Wait for ACK to be received
        }

        // Step 4: Read and process counter values
        for (int i = 0; i < COREINTH_NUM_COUNTERS ; i++)
        {
            uint32_t linux_count = read_reg(COREINTH_LINUX_0 + (i * 4));
            uint32_t lim_count = read_reg(COREINTH_LIM_0 + (i * 4));
            uint32_t itim_count = read_reg(COREINTH_ITIM_0 + (i * 4));
        }
//        if (ACK_SIGNAL_RECEIVED)
//        {
//            for (i=0; i<10; i++)
//            {
//                *COREINTH_LINUX_0= *COREINTH_
//            }
//        }
    }
}
