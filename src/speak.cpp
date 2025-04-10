#include"../include/speak.h"
void speak(string& text) {
    string command = "powershell -Command \"Add-Type -AssemblyName System.Speech; "
                     "(New-Object System.Speech.Synthesis.SpeechSynthesizer).Speak(\\\"" + text + "\\\")\"";
    system(command.c_str());
}
