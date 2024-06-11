import serial
from pynput.keyboard import Controller
import time

# Initialize the keyboard controller
keyboard = Controller()

# Configure the serial port connection
ser = serial.Serial("COM3", 9600)  # Replace 'COM3' with your Arduino's serial port
time.sleep(2)  # Wait for the serial connection to initialize


def press_key(char):
    keyboard.press(char)
    time.sleep(0.05)  # Keep the key pressed for 50 milliseconds
    keyboard.release(char)


# Read from serial and press keys
try:
    while True:
        if ser.in_waiting > 0:
            line = (
                ser.readline().decode("utf-8").strip()
            )  # Read a line and remove whitespace
            print(line)
            if line == "upshift":
                press_key("U")
            elif line == "downshift":
                press_key("D")
except KeyboardInterrupt:
    print("Program terminated")
finally:
    ser.close()
