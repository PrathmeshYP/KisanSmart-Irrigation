# Smart Irrigation System

## Overview
This project is a Smart Irrigation System designed to optimize water usage for agriculture or gardening. The system monitors **soil moisture**, **temperature**, and **humidity**, and automatically controls a water pump to irrigate plants only when necessary. This ensures efficient water usage and promotes healthy plant growth.

## Features
- Real-time soil moisture monitoring  
- Temperature & humidity monitoring using **DHT11/DHT22**  
- Automated water pump control based on moisture thresholds  
- Manual/Automatic irrigation control through Blynk  
- Data logging & visualization on Blynk IoT  
- Remote monitoring from anywhere  
- User-configurable thresholds  

## Hardware Components
- Soil Moisture Sensor  
- **DHT11/DHT22 Temperature & Humidity Sensor**  
- ESP32 Microcontroller  
- Water Pump  
- Relay Module (4-channel used here)  
- Power Supply  
- Connecting Wires  

## Software Components
- Arduino IDE  
- Blynk IoT Platform  
- Required Libraries:
  - `DHT.h`
  - `WiFi.h`
  - `BlynkSimpleEsp32.h`

## Installation
1. Connect the soil moisture sensor to the ESP32 analog pin.  
2. Connect the DHT sensor to a GPIO pin (e.g., GPIO 4 or 15).  
3. Connect the relay module to control the water pump.  
4. Set up a Blynk template and obtain credentials.  
5. Install all required libraries in Arduino IDE.  
6. Upload the firmware code to the ESP32.  
7. Configure moisture and temperature thresholds in the code or app.

   
## Working Model

<table>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/521aa3ca-ff4b-4462-983f-16b74df4222b" width="800"></td>
    <td><img src="https://github.com/user-attachments/assets/c212c399-019e-445c-b164-973e33769c29" width="800"></td>
    <td><img src="https://github.com/user-attachments/assets/1618d0bc-41fd-42fe-81a0-9c44485c41a5" width="800"></td>
    <td><img src="https://github.com/user-attachments/assets/5ea81a9f-492d-429a-86b6-d6aa381b17d9" width="800"></td>
  </tr>
</table>



## Usage
- Ensure all sensors and connections are secure.  
- Monitor soil moisture, temperature, and humidity via the Blynk app.  
- The pump turns ON automatically when moisture is below threshold.  
- You can manually override pump control from Blynk.  
- Adjust settings based on crop or environmental needs.  

## Future Scope
- AI-based irrigation using weather prediction  
- Solar-powered system  
- Multi-zone irrigation  
- ML-based crop care suggestions  

## Contribution
Contributions, issues, and feature requests are welcome!  
Feel free to open issues or submit pull requests.

## License
This project is licensed under the **MIT License**.

## Contact
For questions or support, email: **mohasinmulla861@gmail.com**
