#include <TI_SN76489.h>

TI_SN76489 sn(2, 3, 4, 5, 6, 7, 8, 10, 13, 9, _1MHz);

#define DEBUG

float mtof(float midi_note)
{
    return float(440.0 * pow(2.0, (midi_note - 69) / 12.0));
}

void setup()
{
    Serial.begin(115200);

    sn.begin();
    sn.attenuation(0, 15);
    sn.attenuation(1, 15);
    sn.attenuation(2, 15);
    sn.attenuation(3, 15);
    // sn.frequency(0, 200);
}

void loop()
{
    while (Serial.available() > 0)
    {
        Serial.print("size: ");
        Serial.println(Serial.available());
        
        //byte incomingByte = Serial.read();
        byte buf[3];
        Serial.readBytes(buf, 3);

        byte channel = buf[0] & 15;
        sn.attenuation(channel, buf[1]);
        sn.frequency(channel, mtof(buf[2]));
        
        
        /*
        byte status = Serial.parseInt();
        byte note = Serial.parseInt();
        byte velocity = Serial.parseInt();
        byte channel = NULL;
        
        Serial.println(status);
        Serial.println(note);
        Serial.println(velocity);
        
        if (Serial.read() == '\n')
        {
            // sn.frequency(0, red);
            channel = status & 15;
            sn.attenuation(channel, velocity);
            sn.frequency(channel, mtof(note));
        }
        */
/*
#if defined(DEBUG)
        Serial.print("[ GENERATOR ]\t");
        Serial.print(channel);
        Serial.print("\t[ ATTENUATION ]\t");
        Serial.print(velocity);
        Serial.print("\t[ FREQUENCY ]\t");
        Serial.println(note);
#endif
*/
    }
}
