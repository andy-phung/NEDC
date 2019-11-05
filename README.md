# MESA NEDC (Round 2)
**Project Outline**
  - **Need to be addressed**: Anxiety Disorders
  - **Hardware**: Arduino, Raspberry Pi 3 + SD Card, Lav Mic/Microphone, Heart Rate/Pulse Monitor
  - **Software/Libraries**: Arduino IDE, Pytorch/Tensorflow
  - **Approach**
    - **Ideas**
      - use a CNN to translate acoustic parameters and heart rate into a number indicating the probabilty that the subject in a recording had been experiencing anxiety/a panic attack, then administer noninvasive therapy/treatment
      - arduino controls the microphone and and interfaces with the raspberry pi
      - raspberry pi runs the CNN (trained with pytorch/tensorflow)
      - recordings are stored such that privacy is not compromised (when should the client's voice be recorded? perhaps after some indication of possibility?)
      - (where should all of the components be stored?)
  - **Competitors**:
    - **Advantages over competitors**:
  - **Design Process**
**Logistics**
  - Registration: 
  - Members: Andy Phung, Louie Cabrera, ______________
      
**Things to consider**
  - what other methods could be used to reduce anxiety?
  - swap out acoustic cues for another indicator, as background noise could interfere with detection
  - looking over the other high school projects from 2019
  - The possible fact that those who suffer from anxiety disorders could tend to not speak as often as others (this project is essentially "exploit the relationship between [biometric data] with [disorder] to administer [treatment/therapy])
  - all team members must have contributed equally (no filler members)
  - the arduino could run a tensorflow neural net or use cloud processing (the former would be more difficult to present in a positive light due to the cost of cloud computing)
  - add more, there is a lot to consider and do (for both MESA and MIT THiNK, SynChamp is likely going to be a separate project) 
  - **Construction Precautions**
    - handle all hardware components carefully
    - ground before touching hardware
    - ensure connections are correct
    - do not change connections while arduino/raspberry pi is powered

**Resources**
  - **Rules**
    - https://mesa.ucop.edu/wp-content/uploads/2018/08/NEDC-18-19-Rules-Complete-w_CA-Addendum.pdf (not updated)
  - **Hardware**
    - https://maker.pro/raspberry-pi/tutorial/how-to-connect-and-interface-raspberry-pi-with-arduino (interfacing arduino and raspberry pi)
    - http://soundsmate.com/principles-microphone-placement/ (mic placement)
    - https://conoroneill.net/2013/06/05/connecting-an-arduino-to-raspberry-pi-for-the-best-of-both-worlds/
  - **Software**
    - https://medium.com/hardware-interfacing/how-to-install-pytorch-v4-0-on-raspberry-pi-3b-odroids-and-other-arm-based-devices-91d62f2933c7 (installing pytorch on raspberry pi)
  - **Papers**
    - https://link.springer.com/article/10.1007/s10919-008-0055-9 (Acoustic Analysis and Perception of Anxiety in Social Phobics’ Speech)
    - https://onlinelibrary.wiley.com/doi/abs/10.1111/j.1559-1816.1994.tb00570.x (The Role of Auditory Cues in the Detection of State Anxiety)
    - https://www.ncbi.nlm.nih.gov/pmc/articles/PMC5072238/ (The Effects of Music Therapy on Anxiety and Depression of Cancer)
    - https://www.sciencedirect.com/science/article/pii/S0197455615000064 (Music therapy in generalized anxiety disorder)
    - https://www.sciencedirect.com/science/article/pii/S0147956398900048 (Effectiveness of a music therapy intervention on relaxation and anxiety for patients receiving ventilatory assistance)
    - https://www.liebertpub.com/doi/abs/10.1089/jpm.2007.0193 (The Effect of Music Therapy on Anxiety in Patients who are Terminally Ill)
    - https://www.sciencedirect.com/science/article/abs/pii/S002239999700202X (Autonomic balance revisited: Panic anxiety and heart rate variability)
    - https://www.sciencedirect.com/science/article/abs/pii/S0002870300160053 (Heart rate variability in depressive and anxiety disorders)
    - https://www.tandfonline.com/doi/abs/10.1080/03637757109375689?journalCode=rcmm19 (Heart rate as an index of speech anxiety)
    - https://psycnet.apa.org/record/1962-03143-001 (Human heart rate responses during experimentally induced anxiety)
  
  
