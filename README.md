# Exergaming: Fitness Games with Biofeedback  
**Arduino / M5Stack-Based Interactive Fitness Game System**

## Team Members
- JoonHak Kim  
- Changju Song  
- Jaehyeon Kim  

---

## 1. Introduction

The goal of this project is to encourage users to adopt a more physically active lifestyle through fitness-focused games enhanced with **biofeedback**. 

---

## 2. Hardware & Platform

- **Arduino / M5Stack Core**
- Buttons and motion sensors
- Optional biofeedback sensors (heart rate, accelerometer)
- LCD display for visual feedback
- Serial / wireless communication for data input

---

## 3. Mini-Games Overview

### Game 1: Speed Matching

A fast-paced reaction game where players shall quickly match shapes and colors displayed on the screen. T
he correct answer is randomized each round to challenge the player's perception and reaction speed.

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

void drawBoard()
{
    uint32_t temp_color;

    if (color_arr[1] == "Red") temp_color = RED;
    if (color_arr[1] == "Blue") temp_color = BLUE;
    if (color_arr[1] == "Yellow") temp_color = YELLOW;
    if (color_arr[1] == "Green") temp_color = GREEN;

    if (str_arr[1] == "Rectangle")
        M5.Lcd.fillRect(10, 10, 120, 120, temp_color);
    else if (str_arr[1] == "Triangle")
        M5.Lcd.fillTriangle(65, 10, 10, 130, 130, 130, temp_color);
    else if (str_arr[1] == "Circle")
        M5.Lcd.fillCircle(70, 70, 60, temp_color);
    else if (str_arr[1] == "Ellipse")
        M5.Lcd.fillEllipse(70, 70, 60, 40, temp_color);
}

void shuffleArr()
{
    srand(time(NULL));

    for (int i = 0; i < 4; i++)
    {
        int j = rand() % (4 - i);

        int tmp_ans = answer_arr[i];
        answer_arr[i] = answer_arr[j];
        answer_arr[j] = tmp_ans;

        String tmp_color = color_arr[i];
        color_arr[i] = color_arr[j];
        color_arr[j] = tmp_color;

        String tmp_str = str_arr[i];
        str_arr[i] = str_arr[j];
        str_arr[j] = tmp_str;
    }

    for (int i = 0; i < 4; i++)
    {
        if (answer_arr[i] == 1)
            tempAnswer = i;
    }
}
```

### Game 2: Obstacle Dodging

A Unity-based game where players physically move to dodge falling objects. The game receives movement input from the M5Stack via serial communication.

#### Gameplay Mechanics
- Real-time serial communication between M5Stack and Unity
- Physics-based obstacle spawning
- Player movement controlled by physical gestures
- Animation-driven character feedback

#### Core Code Logic
```csharp
private void CreatePoop()
{
    Vector3 pos = Camera.main.ViewportToWorldPoint(
        new Vector3(UnityEngine.Random.Range(0.01f, 1.0f), 1.1f, 0)
    );

    pos.z = 0.0f;
    Instantiate(poop, pos, Quaternion.identity);
}

void Update()
{
    horizontal = Input.GetAxis("Horizontal");

    if (GameManager.Instance.stopTrigger)
    {
        animator.SetTrigger("start");
        PlayerMove();
    }

    if (!GameManager.Instance.stopTrigger)
    {
        animator.SetTrigger("End");
    }

    ScreenChk();
}

public void OnMessageArrived(string msg)
{
    if (msg.Contains("A"))
        direction = -1;
    else if (msg.Contains("C"))
        direction = 1;
    else
        direction = 0;
}
```

---

## 4. Technologies Used

- **Embedded**: Arduino (C++), M5Stack Core
- **Communication**: Serial protocol (UART)
- **Sensors**: Buttons, accelerometer (optional), heart rate monitor (optional)

---

## Contributors

This project was developed as part of Interactive Media coursework at NYU Abu Dhabi.
