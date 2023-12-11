// #include <TI_SN76489.h>

// TI_SN76489 sn(2, 3, 4, 5, 6, 7, 8, 10, 13, 9, _1MHz);

#define DEBUG

void setup()
{
    Serial.begin(115200);
    /*
    sn.begin();
    sn.attenuation(0, 0);
    sn.frequency(0, 200);
    */
}

void loop()
{
    while (Serial.available() > 0)
    {
        byte status = Serial.parseInt();
        byte note = Serial.parseInt();
        byte velocity = Serial.parseInt();
        byte channel = NULL;
        
        if (Serial.read() == '\n')
            // sn.frequency(0, red);
            channel = status & 15;
            
#if defined(DEBUG)
        Serial.print("[ GENERATOR ]\t");
        Serial.print(channel);
        Serial.print("\t[ ATTENUATION ]\t");
        Serial.print(velocity);
        Serial.print("\t[ FREQUENCY ]\t");
        Serial.println(note);
#endif
    }
}
