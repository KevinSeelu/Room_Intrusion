# Room_Intrusion
Build for Room Intrusion sensor using ESP8266MOD.


ESP8266 WiFi-Enabled Intrusion Detection System


Project Overview:

This project implements an intelligent intrusion detection system that combines hardware sensing with modern communication technology. Built around the ESP8266 NodeMCU microcontroller, it uses an HC-SR04 ultrasonic sensor for proximity detection and automatically sends real-time alerts via Telegram messaging when intrusions are detected.

The system continuously monitors a designated area and triggers both visual (LED) and remote (Telegram) alerts when objects or people breach the security perimeter (closer than 103cm from the sensor).



Key Features:

-- Real-time ultrasonic distance monitoring using HC-SR04 sensor

-- Instant Telegram notifications sent directly to your smartphone

-- Visual LED alert system for local indication

-- Wi-Fi connectivity for remote monitoring capabilities

-- Anti-spam protection with 10-second cooldown between alerts

-- Serial monitoring for debugging and system status

-- Robust error handling for sensor malfunctions and network issues

-- Low power consumption suitable for 24/7 operation

-- Configurable detection threshold (currently set to 103cm)


Hardware Components:

ESP8266 NodeMCU              x1	
HC-SR04 Ultrasonic Sensor    x1	
Blue LED                     x1	
1000Ω Resistor               x1	
Jumper Wires                 xMultiple	
Breadboard	                 x1	


Core Functionality:
The system operates on a simple but effective algorithm:

Distance Measurement: Triggers ultrasonic pulse every 500ms
Range Evaluation: Compares measured distance against safe zone (100-110cm)
Alert Logic: Activates LED when distance falls outside safe range
Error Handling: Manages sensor timeouts and connection issues
Serial Logging: Outputs real-time readings for monitoring


Key Technical Specifications:

Detection Range: 2-400cm (HC-SR04 specification)
Practical Range: Up to ~343cm in testing
Accuracy: ±0.3cm under optimal conditions
Measurement Frequency: 2 readings per second
Alert Threshold: Objects detected outside 100-110cm range
Power Requirements: 3.3V-5V DC (USB powered)
Operating Current: ~100mA during operation


Potential Applications:

Home Security: Door/window intrusion detection
Garage Parking: Vehicle positioning assistance
Industrial Automation: Object presence monitoring
Educational Projects: IoT and sensor integration learning
Smart Home Integration: Trigger automation based on proximity


Future Enhancements:

Planned Features:

Telegram/Push Notifications: Remote alerts via Wi-Fi
Data Logging: SD card or cloud-based data storage
Web Dashboard: Real-time monitoring via browser interface
Multiple Sensor Support: Expanded coverage area
Battery Operation: Portable deployment capability

Expandability:

MQTT Integration: Smart home ecosystem compatibility
Machine Learning: Pattern recognition for advanced detection
Servo Integration: Automated physical responses
Multi-Zone Detection: Configurable detection areas


Technical Notes:

Voltage Considerations: HC-SR04 operates at 5V but ESP8266 uses 3.3V logic. The current setup uses 3.3V power which limits maximum range but ensures compatibility.
Range Limitations: Practical maximum range observed at ~343cm due to power and environmental factors.
Measurement Reliability: Best performance achieved with hard, flat surfaces perpendicular to sensor.


Contributions:

This project welcomes contributions for:

Code optimizations and bug fixes
Additional sensor integrations
Enhanced user interface features
Documentation improvements
Hardware design variations

License:

This project is open source and available under the Apache 2.0 License.


Note: This project serves as an excellent introduction to IoT development, combining hardware interfacing, sensor data processing, and real-time monitoring in a practical security application.
