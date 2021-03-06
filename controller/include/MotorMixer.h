/**
 *  File: MotorMixer.h
 * 
 *  Author: Thomas Kost
 *  
 *  Date: 02 April 2021
 *  
 *  @brief Implements motor mixing for quadcopter motor outputs in response to throttle, pitch, roll, and yaw
 *
 */

#ifndef MOTOR_MIXER_H
#define MOTOR_MIXER_H

class MotorMixer{
    public:
        /**
         *  @brief constructor
         *  @param int M1: Front Left motor pin
         *  @param int M2: Front Right motor pin
         *  @param int M3: Back Left motor pin
         *  @param int M4: Back Right motor pin
         *  @param int M1_center: Front Left ESC center Value (not moving) 
         *  @param int M2_center: Front Right ESC center Value (not moving)
         *  @param int M3_center: Back Left ESC center Value (not moving)
         *  @param int M4_center: Back Right ESC center Value (not moving)
         */
        
        MotorMixer(int M1, int M2, int M3, int M4, 
                   int M1_center = 1500, int M2_center= 1500,
                   int M3_center = 1500, int M4_center = 1500);
        
        /**
         *  @brief update PWM values to motors besed upon throttle, pitch, yaw, and roll commands
         *  @param int throttle: throttle command (prescaled)
         *  @param int pitch: pitch command (prescaled)
         *  @param int yaw: yaw command (prescaled)
         *  @param int roll: roll command (prescaled)
         */
        
        void write(int throttle, int pitch, int yaw, int roll);

    private:
        // Member variables
        int m_M1_pin;
        int m_M2_pin;
        int m_M3_pin;
        int m_M4_pin;
        int m_M1_center;
        int m_M2_center;
        int m_M3_center;
        int m_M4_center;
        unsigned int m_max_val;
        unsigned int m_min_val;
};

#endif