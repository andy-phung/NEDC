# MESA NEDC, Round 2
**Project Outline**
  - **Need to be addressed**: State Anxiety/Mental Disorders
  - **Hardware**: Arduino, Raspberry Pi 3, Microphone
  - **Software**: Arduino IDE, Pytorch
  - **Approach**
    - **Ideas**
      - use a CNN to translate acoustic parameters into a number indicating the probabilty that the subject in a recording had been experiencing anxiety/a panic attack
      - arduino controls the microphone and and interfaces with the raspberry pi
      - raspberry pi runs the CNN in pytorch
      - recordings are stored such that privacy is not compromised (when should the client's voice be recorded? perhaps after some indication of possibility?)
      - (where should all of the components be stored?)
    
**Resources**
  - **Hardware**
    - https://maker.pro/raspberry-pi/tutorial/how-to-connect-and-interface-raspberry-pi-with-arduino (interfacing arduino and raspberry pi)
    - https://conoroneill.net/2013/06/05/connecting-an-arduino-to-raspberry-pi-for-the-best-of-both-worlds/
  - **Software**
    - https://medium.com/hardware-interfacing/how-to-install-pytorch-v4-0-on-raspberry-pi-3b-odroids-and-other-arm-based-devices-91d62f2933c7 (installing pytorch on raspberry pi)
  - **Papers**
    - https://link.springer.com/article/10.1007/s10919-008-0055-9
    - https://onlinelibrary.wiley.com/doi/abs/10.1111/j.1559-1816.1994.tb00570.x
  
  
