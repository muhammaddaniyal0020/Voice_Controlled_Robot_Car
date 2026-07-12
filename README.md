# 🚗 Voice Controlled Robot Car with Rule-Based Chatbot

A Bluetooth-based **Voice Controlled Robot Car** developed using **Arduino UNO** and **Python**. The robot responds to real-time voice commands for movement while also providing predefined conversational responses through a **rule-based chatbot**.

The project demonstrates the integration of **Speech Recognition**, **Bluetooth Communication**, **Arduino Motor Control**, and **Text-to-Speech (TTS)** to create an interactive robotic system.

---

## 📖 Overview

This project enables a user to control a robot car using natural voice commands from a computer. Voice input is processed using Python, converted into movement commands, and transmitted wirelessly through an HC-05 Bluetooth module to an Arduino UNO. The Arduino controls the DC motors via an L298N motor driver while the chatbot responds to predefined conversational queries.

---

## ✨ Features

- 🎙️ Real-time Voice Recognition
- 🤖 Rule-Based Chatbot
- 📡 Bluetooth Communication (HC-05)
- 🚗 Wireless Robot Navigation
- 🔊 Text-to-Speech Responses
- ⚡ Real-Time Command Processing
- 🛑 Safe Stop Function
- 💻 Simple and Easy-to-Use Interface
- 🔄 Bidirectional Robot Control

---

## 🎯 Supported Voice Commands

### Robot Movement

| Voice Command | Arduino Command | Action |
|--------------|-----------------|--------|
| Forward | `F` | Move Forward |
| Backward | `B` | Move Backward |
| Left | `L` | Turn Left |
| Right | `R` | Turn Right |
| Stop | `S` | Stop Robot |

---

### Chatbot Commands

The chatbot supports several predefined conversational responses.

Examples include:

- Hello
- Hi
- How are you?
- What is your name?
- Who made you?
- What can you do?
- Thank you
- Bye
- Exit

---

## 🛠 Technologies Used

### Programming Languages

- Python
- Arduino C++

### Hardware

- Arduino UNO
- HC-05 Bluetooth Module
- L298N Motor Driver
- Robot Chassis
- DC Gear Motors
- Wheels
- Jumper Wires
- Battery Pack

### Python Libraries

- SpeechRecognition
- PySerial
- gTTS
- playsound
- os
- time

---

## ⚙ Hardware Connections

### HC-05 Bluetooth Module

| HC-05 | Arduino |
|--------|----------|
| VCC | 5V |
| GND | GND |
| TXD | Pin 10 |
| RXD | Pin 11 |

---

### L298N Motor Driver

| L298N | Arduino |
|--------|----------|
| IN1 | Pin 2 |
| IN2 | Pin 3 |
| IN3 | Pin 4 |
| IN4 | Pin 5 |
| GND | GND |

---

## 🔄 System Workflow

```text
User Voice
      │
      ▼
Speech Recognition
      │
      ▼
Python Application
      │
      ▼
Command Detection
      │
      ▼
Bluetooth (HC-05)
      │
      ▼
Arduino UNO
      │
      ▼
L298N Motor Driver
      │
      ▼
DC Motors
      │
      ▼
Robot Movement
```

---

## 🚀 Installation

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/Voice-Controlled-Robot-Car.git
```

### 2. Install Python Dependencies

```bash
pip install pyserial
pip install SpeechRecognition
pip install gTTS
pip install playsound
pip install pyaudio
```

Or install all dependencies using:

```bash
pip install -r requirements.txt
```

---

## ▶️ Usage

### Upload Arduino Code

1. Open the Arduino sketch.
2. Select the correct board.
3. Select the COM Port.
4. Upload the code.

### Connect Bluetooth

- Pair the HC-05 module with your computer.
- Default PIN:

```
1234
```

or

```
0000
```

- Update the Bluetooth COM port inside the Python script.

Example:

```python
COM_PORT = "COM3"
```

---

### Run the Python Program

```bash
python main.py
```

Speak commands such as:

```
Forward
Backward
Left
Right
Stop
Hello
Who made you
Bye
```

---

## 🧠 Chatbot

The chatbot implemented in this project is a **rule-based conversational assistant**. It recognizes predefined questions and replies with programmed responses while simultaneously supporting robot movement through voice commands.

Unlike AI-powered language models, this chatbot operates using conditional logic and keyword matching, making it lightweight, reliable, and suitable for embedded robotics applications.

---

## 📊 Testing Results

| Test | Result |
|------|---------|
| Voice Recognition | ✅ Passed |
| Bluetooth Communication | ✅ Passed |
| Forward Movement | ✅ Passed |
| Backward Movement | ✅ Passed |
| Left Turn | ✅ Passed |
| Right Turn | ✅ Passed |
| Stop Function | ✅ Passed |
| Chatbot Responses | ✅ Passed |
| Text-to-Speech | ✅ Passed |

---

## 📈 Future Enhancements

- AI-powered conversational assistant
- OpenAI API integration
- Mobile Application Control
- Computer Vision Integration
- Face Recognition
- Object Detection
- Obstacle Avoidance
- Autonomous Navigation
- IoT-based Remote Monitoring
- Speed Control using PWM
- Battery Monitoring System

---

## 🎓 Learning Outcomes

This project demonstrates practical implementation of:

- Arduino Programming
- Embedded Systems
- Bluetooth Communication
- Voice Recognition
- Human-Robot Interaction
- Python Automation
- Motor Control
- Rule-Based Artificial Intelligence

---

## 🤝 Contributing

Contributions are welcome.

Feel free to fork the repository, improve the project, and submit a pull request.

---

## 📄 License

This project is released under the **MIT License**.

---

## 👨‍💻 Developer

**Muhammad Daniyal**

Artificial Intelligence Student

Gomal University, Dera Ismail Khan

---

## ⭐ Support

If you found this project useful, please consider giving it a ⭐ on GitHub.

Your support is greatly appreciated!
