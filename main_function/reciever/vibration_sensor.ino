int TP_init() {
    delay(10);
    return pulseIn(vib_pin, HIGH);
}

int selector(){
    int timeout = 0, set_password = 0;
    while (1){
        delay(100);
        if(timeout == 3) 
            return set_password;
        int messure = TP_init();
        if (messure == 0){
            timeout++;
        }
        else
        {
            set_password++;
            timeout = 0;
        }
    }
}

void tonePin() {
    Serial.println("beep!!");
    digitalWrite(tone_pin, HIGH);
    delay(300);
    digitalWrite(tone_pin, LOW);
}
