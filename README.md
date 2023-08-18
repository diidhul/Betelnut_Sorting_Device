# IoT_Betelnut_Sorting_Machine_

## An IoT device for sorting betel nut based on temperature
This project aims to sort areca nut using temperature variables to sort good quality and poor quality betel nut

The idea of this project is; Betel nut is one of the export commodities in Aceh, but meeting quality requirements is a challenge for collectors because of difficulties in meeting export standards. One of the main problems is the moisture content of betel nuts which cannot be met and often cannot be sold to exporters. The betel nut sorting method used by collectors is also considered subjective because it does not use specific variables to distinguish between dry and moist betel nuts. This study aims to help betel nut collectors sort high-quality betel nuts using a more objective sorting method that uses temperature as a parameter for the moisture content of betel nuts. This study uses quantitative empirical research and produces a prototype of a betel nut sorting tool integrated with an IOT system and a thermal camera AMG8833. The outcome generated from this prototype is considered successful with an improvement in sorting accuracy compared to manual sorting methods by 5.5%. For further development, the author hopes to use microcontrollers and devices with more sophisticated specifications to improve the performance of this prototype

The image of good and bad betel nut below 👇👇
<kbd><img src="(https://github.com/diidhul/IoT_Betelnut_Sorting_Machine/blob/main/Images/half%20cut%20betel%20nut%20reveal.png)" alt="Image"></kbd>

## Tools & Materials
1. ESP32
2. Thermal Camera AMG 8833
3. Belt
4. Servo Master Pro M9935
5. Loadcell Sensor
6. Kaki Sensor Berat
7. HX711 Module
8. Motor Driver L298N
9. Arduino Uno
10. <a href="https://blynk.io/">Blynk IoT Appilcation.</a>
    
### How To
1. Install the arduino IDE u can see the tutorial in <a href="https://www.instructables.com/How-to-Install-Arduino-IDE-on-Windows-10/">here.</a>
2. Dont forget to download the library of
       a. HX711_ADC.h
       b. Servo.h
       c. BlynkSimpleEsp32.h
       d. Adafruit_AMG88xx_Library
    all of libraary above is necessary for define and intialize all the component
3. Download the needed files on the repository <a href="https:www..com">here.</a>
4. Wiring the component, u can see the wiring image below 👇
   <kbd><img src="(https://github.com/diidhul/IoT_Betelnut_Sorting_Machine/blob/main/Images/wiring.png)" alt="Image"></kbd>
5. Open the main folder & then upload the <a href="Arduino/main/conveyor_loadcell_esp32.ino">conveyor_loadcell.</a> into ESP32
6. Upload the <a href="Arduino/main/upload to arduino.ino">upload to arduino.</a> into Arduino. This code is for thermal camera for read the temperature of betel nut and command for moving servo
7. Then assembly the part u can see my prototype image below this.

<kbd><img src="(https://github.com/diidhul/IoT_Betelnut_Sorting_Machine/blob/main/Images/prototype%20image.png)" alt="Image"></kbd>

8. The final video is below here 👇
[![Watch the video](https://i.stack.imgur.com/Vp2cE.png)](https://drive.google.com/file/d/11n3sChgPE0puqIlMQ7-3FpZ_oxv0y5F3/view?usp=sharing)
   
   
