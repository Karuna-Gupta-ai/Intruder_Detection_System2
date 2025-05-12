# Intruder_Detection_System2
A simulation project that detects intruders using a PIR sensor and sends a captured image via email with a alert beep. Built using Proteus, a microcontroller, and opencv. Useful for learning embedded security systems and email automation via SMTP and Comports.

💡 Features
Motion detection using PIR sensor (Proteus + Arduino)
Alert beep using buzzer
Sends image via email using Python (SMTP)
Displays "Theft Detected" message on confirmation
Serial communication between Arduino and Python via Compins

🛠️ Tools & Technologies
Proteus Design Suite
Arduino IDE (Embedded C)
Python (for image capture and email)
Compins (Arduino-Python serial bridge)
Virtual Serial Terminal / SMTP

📁 Project Structure
/Intruder-Detection
├── simulation_files/      # Proteus .DSN and circuit design
├── arduino_code/          # Arduino sketch (.ino)
├── python_script/         # Python email and image sender
├── compins_setup/         # Serial communication config
└── README.md

🚀 Getting Started
Open file in Proteus and load the compiled Arduino code.
Run the Python script (python_script/send_email.py).
On motion detection:
Buzzer gives an alert
Python script captures and sends image via email
"Theft Detected" message appears

✅ Requirements
Arduino IDE
Python 3 (with smtplib, serial, etc.)
Proteus Design Suite
Compins tool for Arduino-Python communication

simulation below...

https://1drv.ms/i/c/55d3fdb6cd3af785/Edd1Poo1cFdNgCkLVtWlYTIBky2Th3hwjnsytqsabWXERg?e=njX9CY

https://1drv.ms/v/c/55d3fdb6cd3af785/EY7n3pg-vutAioPd82k_boYB_Fm5fGl5QDnlWhfvy7so7w?e=IWoznw

