CIRCUITO
[![circuito-carro-autonomo.png](https://i.postimg.cc/L8nZFnWQ/circuito-carro-autonomo.png)](https://postimg.cc/jDYjzdty)
[![diagama-de-flujo-carro-auitonomo1-0.png](https://i.postimg.cc/rwNNV0Bp/diagama-de-flujo-carro-auitonomo1-0.png)](https://postimg.cc/ZW0djRKk)
Introduction and Project Overview
This document provides a comprehensive technical breakdown of an autonomous vehicle project. The core objective was to transform a standard Porsche 911 remote control (RC) car into an autonomous platform capable of navigating a defined track for three complete laps without collision. This required significant structural modifications to the chassis, the integration of a custom electronic control system centered around the ESP32 microcontroller, and the implementation of an advanced environmental perception system using three ultrasonic sensors. The project falls within the category of engineering with significant structural and electronic design changes.

The success of the vehicle hinges on three critical and interrelated systems: Autonomous Mobility Management (Motors & Steering), Environmental Perception (Sensors), and Power Management (LiPo & Voltage Regulation).

Vehicle Base and Mechanical Modifications
The project began with a compact RC vehicle, a Porsche 911 model, chosen because it already incorporated an Ackerman steering system crucial mechanical feature that ensures the front wheels trace the correct arc during turns, minimizing tire slip and maximizing precision.

Vehicle Platform & Dimensions
The final autonomous vehicle configuration required deep modifications to the original RC car's chassis:

Original Chassis Modification: The outer shell was entirely removed, and the chassis itself was extensively cut and modified. This included enlarging the original battery compartment to create sufficient space for the new, larger electronic components (ESP32, L298N, and voltage regulator).
The final autonomous vehicle configuration required deep modifications to the original RC car's chassis:
Custom Supports: Team-designed supports were installed to securely fix the electronic modules and ultrasonic sensors, enhancing the vehicle's accessibility and stability.
Autonomous Mobility Management (Motors and Control)
Vehicle movement and directional changes are managed by two DC motors controlled by a dual H-bridge driver.

DC Motors and Function
The vehicle utilizes two Direct Current (DC) Motors:
Traction Motor (Rear): Responsible for the longitudinal movement (forward and reverse) of the vehicle. It requires sufficient torque to overcome initial inertia and friction, and to reach the desired operational speed.
Steering Motor (Front): Operates the mechanical gear system to adjust the angle of the front wheels according to the Ackerman principle. Its key requirement is high and precise torque to move the steering assembly; speed is less critical.
DC motors convert electrical energy into mechanical energy using coils and magnetic fields. Since DC motors cannot inherently reverse polarity to change direction, a separate motor driver is essential.
The L298N H-Bridge Motor Driver
The L298N H-Bridge moduleis the essential interface between the low-power microcontroller (ESP32) and the high-power motors.

Functionality:
Direction Control: It allows for the reversal of polarity to the DC motors, enabling both forward/backward traction and left/right steering.
Speed Regulation: It receives Pulse Width Modulation (PWM) signals from the ESP32 to precisely control the motor speed by varying the effective voltage.

The L298N receives power from the voltage regulator and distributes the necessary current to each motor based on the control instructions from the ESP32.
rinciples of Engineering: Power CalculationThe mechanical power (P) produced by a motor is directly proportional to its torque (T) and angular velocity (w)
The motors were selected to provide the optimal balance of torque and speed required for the vehicle's weight and track navigation.

Environmental Perception and Obstacle Management
The vehicle’s "senses" are its ultrasonic sensors, which constantly inform the ESP32 about the immediate environment, allowing for real-time decision-making.
HC-SR04 Ultrasonic Sensors
Three HC-SR04 ultrasonic sensors were employed for obstacle detection and distance measurement. These sensors work on the principle of echolocation, emitting high-frequency sound waves and measuring the time-of-flight for the echo to return to calculate distance.
Justification for Three Sensors: Using three sensors provides a wide field of vision, which is crucial for safe navigation in a confined track:
One sensor alone cannot detect lateral obstacles.
Two sensors do not offer sufficient precision for dynamic path correction.
The setup balances functionality, cost-effectiveness, and low energy consumption.
Sensor Placement and Function
The strategic placement of the sensors is key to managing the track's exterior wall and interior wall
The constant readings from these sensors enable the vehicle to maintain a stable trajectory within the allowed corridor, correcting its path dynamically to prevent deviations and collisions with either the interior or exterior walls.
Control Unit and Power System
The system's intelligence and energy distribution are handled by the ESP32 microcontroller and a robust power supply system.
Data Processing: It processes the continuous distance information received from the three ultrasonic sensors.

Decision-Making: It executes the navigation algorithms, making real-time decisions on movement (accelerate, brake, or stop) and direction (steering angle).

Motor Control: It generates and sends PWM signals and control logic to the L298N H-Bridge to regulate the speed and direction of both the traction and steering motors.

Its high performance and built-in connectivity features are instrumental for implementing complex navigation and control algorithms. The ESP32 operates on a stable, regulated 5V supply, regulated internally to 3.3V logic.
LiPo Battery and Power Management
The power system is designed for safety and efficiency, managing the high and variable voltage of the battery.

LiPo Battery: A Lithium Polymer (LiPo) battery was selected due to its high efficiency, high discharge capacity, and low weight, which are ideal characteristics for a compact mobile robot. The battery provides a relatively high and variable voltage (e.g., 11.1V as mentioned in the notes).
Voltage Regulator: An essential component that stabilizes and reduces the battery's voltage to a constant, safe level, protecting the sensitive electronics.

Power Distribution Flow
The LiPo Battery directly supplies power to the Voltage Regulator.
The Voltage Regulator stabilizes the high input voltage, converting it to a constant, lower voltage (e.g., 5V) suitable for the components.
The regulated power is then distributed to all main components:
The L298N H-Bridge (which, in turn, powers the high-current DC Motors).
The ESP32 Control Unit.
The HC-SR04 Ultrasonic Sensors.
This architecture ensures that all components operate securely and efficiently at their specified voltage, with the L298N H-Bridge being the highest power-consuming component due to the motor demands.

Operational Conclusion
The vehicle’s ability to successfully complete three laps without collision is a direct result of the precise integration and management of the hardware and control systems.

The ESP32 continuously processes data from the strategically positioned ultrasonic sensors, generating a dynamic map of the immediate path bounded by the exterior and interior walls. In response, the ESP32 utilizes the L298N driver to accurately modulate the power to the motors (speed via PWM and direction via H-bridge logic). This closed-loop control allows the vehicle to:
Maintain a stable trajectory between the boundaries.
Anticipate and manage curves by adjusting speed and steering angle in real-time.
Correct its path immediately upon detecting closeness to any wall.
The combination of an efficient, custom-integrated hardware platform and a responsive, sensor-driven control algorithm is what enables the autonomous vehicle to execute the required navigation challenges with precision, safety, and stability.
