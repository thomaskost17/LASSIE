%%
 %  File: MPU6050_noise_kalman.m
 % 
 %  Author: Thomas Kost
 %  
 %  Date: 05 April 2021
 %  
 %  @brief testing of noise and kalman tuning for mpu6050
 %

 clear variables; close all;
 %% Hardware Setup
 
 fs = 1000;
 samples_per_read = 500; % max value
 a = arduino();
 imu = mpu6050(a,'SampleRate',fs,'SamplesPerRead',samples_per_read,...
                'ReadMode','latest');
n = 10000; % total number of samples

%% Read in data 
n_read = 0;
accel = zeros(n,3);
gyro = zeros(n,3);
timestamps = zeros(n;1);

while(n_read < n)
    [accel_temp,gyro_temp,timestamps_temp,overrun] = imu.read();
    accel(n_read+1:n_read+500,:) = accel_temp;
    gyro(n_read+1:n_read+500,:) = gyro_temp;
    timestamps(n_read+1:n_read+500,:) = timestamps_temp;
    n_read = n_read +500;
end
 
accel = accel';
gyro = gyro';
timestamps = timestamps';

%% calculate unfiltered values
