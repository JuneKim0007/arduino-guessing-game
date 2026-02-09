# Exergaming: Fitness Games with Biofeedback  
**Arduino / M5Stack-Based Interactive Fitness Game System**

## Team Members
- Joonjak Kim  
- Changju Song  
- Jaehyeon Kim  

---

## 1. Introduction

Over the last decades, modern lifestyles have become increasingly sedentary, accompanied by unhealthy dietary patterns. This shift has contributed to rising levels of physical inactivity, obesity, and mental health issues. These problems impose serious socio-economic burdens worldwide and significantly reduce overall quality of life.

The goal of this project is to encourage users to adopt a more physically active lifestyle through **exergaming**—fitness-focused games enhanced with **biofeedback**. By applying a **reward-based game design**, we aim to motivate users to continue exercising while enjoying engaging and interactive gameplay.

---

## 2. Project Description

This project is a **collection of mini-games** that require physical movement to progress. Each game tracks player actions using sensors and rewards performance through scores and in-game feedback.

### Key Features
- Multiple fitness-based mini-games
- Real-time motion input via sensors
- Competitive scoring system
- Reward and progression mechanics
- Biofeedback-driven difficulty adjustment
- Arduino / M5Stack hardware integration

### Biofeedback Concept
The system collects player data such as:
- Movement speed
- Reaction time
- Body condition (e.g., heart rate via external sensors)

This data is used to dynamically adjust exercise intensity to prevent overtraining or undertraining.

---

## 3. Hardware & Platform

- **Arduino / M5Stack Core**
- Buttons and motion sensors
- Optional biofeedback sensors (heart rate, accelerometer)
- LCD display for visual feedback
- Serial / wireless communication for data input

---

## 4. Mini-Games Overview

### Game 1: Speed Matching

A fast-paced reaction game where players must quickly match shapes and colors displayed on the screen. The correct answer is randomized each round to challenge the player's perception and reaction speed.

#### Gameplay Mechanics
- Randomized shapes and colors
- Time-limited response window
- Button-based input
- Score tracking

#### Core Code Logic

```cpp
int answer_arr[4] = {1, 0, 0, 0}; // only one correct answer
String str_arr[4] = {"Rectangle", "Triangle", "Circle", "Ellipse"};
String color_arr[4] = {"Red", "Blue", "Yellow", "Green"};
int tempAnswer;

}

