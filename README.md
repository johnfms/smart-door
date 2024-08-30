# Smart Door System 🚀🔒

## Project Overview

This project implements a Smart Door System using the AVR ATmega microcontroller, designed for IoT applications. It provides secure, personalized access control for homes or offices.

## Key Features

- **Personalized Access**: Each user has a unique ID and password for authorized entry.
- **Intuitive Interface**: An LCD screen provides clear feedback and prompts.
- **Real-time Monitoring**: Red and green LEDs signal access status.
- **Automated Door Control**: A DC motor opens and closes the door automatically.

## Hardware Components

- AVR ATmega32 microcontroller
- 16x2 LCD Display (LM016L)
- 4x4 Matrix Keypad
- DC Motor
- LEDs (Red and Green)

## Software Implementation

The system is programmed in C and includes the following key functionalities:

- User authentication (ID and password verification)
- LCD interface for user interaction
- Keypad input handling
- Motor control for door operation
- LED signaling for access status

## Usage

1. Power on the system.
2. Enter your unique ID when prompted.
3. If ID is valid, enter your password.
4. Upon successful authentication, the door will open automatically.
5. The system provides visual feedback via LCD and LEDs throughout the process.

## Security Features

- Each user has a unique ID, password, and name stored in the system.
- Failed authentication attempts are logged and signaled.

## Future Enhancements

- Integration with mobile apps for remote access
- Addition of biometric authentication methods
- Logging of entry/exit times for advanced security


Tags: #SmartHome #IoT #HomeSecurity #SecurityTech #Innovation #AVR #ATmega #Technology #EmbeddedSystems
