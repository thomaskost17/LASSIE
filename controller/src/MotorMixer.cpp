/**
 *  File: MotorMixer.cpp
 * 
 *  Author: Thomas Kost
 *  
 *  Date: 01 April 2021
 *  
 *  @brief Implements motor mixing for quadcopter motor outputs in response to throttle, pitch, roll, and yaw
 *
 */

#include <MotorMixer.h>
#include <ADC.h>

MotorMixer::MotorMixer(int M1, int M2, int M3, int M4, 
                   int M1_center, int M2_center,
                   int M3_center, int M4_center){

    // Initialize member variables
    m_M1_pin    = M1;
    m_M2_pin    = M2;
    m_M3_pin    = M3;
    m_M4_pin    = M4;
    m_M1_center = M1_center;
    m_M2_center = M2_center;
    m_M3_center = M3_center;
    m_M4_center = M4_center;

    // Configure pins for PWM (controlled by analogWrite)
    analogWriteFrequency(m_M1_pin, 250);
    analogWriteFrequency(m_M2_pin, 250);
    analogWriteFrequency(m_M3_pin, 250);
    analogWriteFrequency(m_M4_pin, 250);
    analogWriteResolution(12);
    m_max_val = (1<<11);
    m_min_val = 1<<10;
}

void MotorMixer::write(int throttle, int pitch, int yaw, int roll){
    // Implement motor mixing algorithm for dynamics
    int M1 = throttle - yaw + pitch - roll;
    int M2 = throttle + yaw + pitch + roll;
    int M3 = throttle + yaw - pitch - roll;
    int M4 = throttle - yaw - pitch + roll;

    // Bound check before writing
    M1 = (M1 > m_max_val)? m_max_val : ((M1 < m_min_val)? m_min_val : M1);
    M2 = (M2 > m_max_val)? m_max_val : ((M2 < m_min_val)? m_min_val : M2);
    M3 = (M3 > m_max_val)? m_max_val : ((M3 < m_min_val)? m_min_val : M3);
    M4 = (M4 > m_max_val)? m_max_val : ((M4 < m_min_val)? m_min_val : M4);

    // Update motor commands
    analogWrite(m_M1_pin, M1);
    analogWrite(m_M2_pin, M2);
    analogWrite(m_M3_pin, M3);
    analogWrite(m_M4_pin, M4);

    return;
}