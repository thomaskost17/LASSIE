/**
 *  File: IMU.h
 * 
 *  Author: Thomas Kost
 *  
 *  Date: 03 April 2021
 *  
 *  @brief Acceleromoter object for managing I2C connection for MPU6050 IMU
 *
 */
#ifndef IMU_H
#define IMU_H

class IMU{
    public:
        IMU();
        void read(int* data_array);
        void setClockFreq(int freq);
        int getLoopTime();
    private:
        int m_MPU_address;
        int m_loop_timer_a; // might not need if just returning raw values
        int m_loop_timer_b; // might not need if just returning raw values

};

#endif