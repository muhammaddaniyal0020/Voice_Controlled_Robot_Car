import serial
import time
import speech_recognition as sr
from gtts import gTTS
from playsound import playsound
import os

# --- Arduino Bluetooth Setup ---
try:
    # Change 'COM3' to your HC-05 Bluetooth COM port
    arduino = serial.Serial('COM3', 9600, timeout=1)
    time.sleep(2)
    print("Connected to Arduino via Bluetooth.")
except serial.SerialException:
    print("Could not connect to Arduino. Check Bluetooth pairing and COM port.")
    exit()

# --- Function: Send command to Arduino ---
def send_command(command_char):
    print(f"Sending command to robot: {command_char}")
    arduino.write(command_char.encode())
    time.sleep(0.1)

# --- Function: Speak with TTS (gTTS) ---
def speak_robot(text):
    print(f"Robot says: {text}")
    tts = gTTS(text=text, lang='en')
    filename = "robot_voice.mp3"
    tts.save(filename)
    playsound(filename)
    os.remove(filename)

# --- Function: Listen for voice command ---
r = sr.Recognizer()
def listen_command():
    with sr.Microphone() as source:
        print("Listening for command...")
        r.adjust_for_ambient_noise(source)
        audio = r.listen(source)
    try:
        text = r.recognize_google(audio)
        print(f"You said: {text}")
        return text.lower()
    except sr.UnknownValueError:
        speak_robot("Sorry, I didn't catch that.")
        return ""
    except sr.RequestError as e:
        speak_robot(f"My speech service is unavailable. Error: {e}")
        return ""

# --- Main Program with Chat & Control ---
def main():
    speak_robot("Hello! I am Sheher Bano your voice-controlled robot. How can I help you?")

    while True:
        command_text = listen_command()

        if "forward" in command_text:
            send_command('F')
            speak_robot("Moving forward.")
        elif "backward" in command_text:
            send_command('B')
            speak_robot("Moving backward.")
        elif "left" in command_text:
            send_command('L')
            speak_robot("Turning left.")
        elif "right" in command_text:
            send_command('R')
            speak_robot("Turning right.")
        elif "stop" in command_text:
            send_command('S')
            speak_robot("Stopping.")

        # --- Chatbot-like Responses ---
        elif "hello" in command_text or "hi" in command_text:
            speak_robot("Hi there! What can I do for you?")
        elif "how are you" in command_text:
            speak_robot("I'm fully charged and ready to go!")
        elif "what is your name" in command_text:
            speak_robot("I am Shehr Bano, your voice-controlled assistant.")
        elif "thank you" in command_text:
            speak_robot("You're welcome!")
        elif "who made you" in command_text:
            speak_robot("I was built by a brilliant human who loves robotics.")
        elif "what can you do" in command_text:
            speak_robot("I can move around and chat with you. Try saying forward or left.")
        elif "exit" in command_text or "quit" in command_text or "bye" in command_text:
            speak_robot("Goodbye! Talk to you soon.")
            send_command('S')
            break

        # --- Unrecognized input fallback ---
        elif command_text:
            speak_robot("Hmm, I don't know how to respond to that. Try saying a movement command or ask me something.")

# --- Run Program ---
if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nProgram terminated by user.")
        if 'arduino' in locals() and arduino.is_open:
            send_command('S')
            arduino.close()
    finally:
        if 'arduino' in locals() and arduino.is_open:
            arduino.close()
        print("Bluetooth serial connection closed. Cleanup complete.")
