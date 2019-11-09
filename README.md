# MESA NEDC (Round 2)
**Project Outline**
  - **Need to be addressed**: Anxiety Disorders
  - **Hardware**: Arduino Uno, Raspberry Pi 3 + SD Card, Lav Mic/Microphone, Heart Rate/Pulse Monitor, Earbuds (possibly with an embedded mic)
  - **Software/Libraries**: Arduino IDE, Pytorch/Tensorflow, Matplotlib
  - **Approach**
    - **Ideas**
      - use a CNN to translate acoustic parameters and heart rate into a number indicating the probabilty that the subject in a recording had been experiencing anxiety/a panic attack, then administer noninvasive therapy/treatment
      - raspberry pi administers noninvasive audio therapy 
      - arduino controls the microphone and and interfaces with the raspberry pi
      - raspberry pi runs the CNN (trained with pytorch/tensorflow)
      - recordings are stored such that privacy is not compromised (when should the client's voice be recorded? perhaps after some indication of possibility?)
      - (where should all of the components be stored?)
      - training data is generated by an algorithm whose input is average speech from a dataset (e.g. Spoken Wikipedia Corpora) that has been passed through a low-pass filter and whose output is labelled with a number indicating probability of anxiety and a modified low-pass speech sample that embeds certain auditory cues (don't do this manually, use an audio processing library)
      - synthetic heart rate training data is generated by a similar algorithm
  - **Competitors**:
    - **Advantages over competitors**:
  - **Design Process**
  
**Logistics**
  - Registration: Deadline unknown, contact MESA SJSU
  - Members: Andy Phung, Louie Cabrera, ______________
      
**Things to consider**
  - what other methods could be used to reduce anxiety?
  - swap out acoustic cues for another indicator, as background noise could interfere with detection
  - looking over the other high school projects from 2019
  - The possible fact that those who suffer from anxiety disorders could tend to not speak as often as others (this project is essentially "exploit the relationship between [biometric data] with [disorder] to administer [treatment/therapy])
  - the arduino could run a tensorflow neural net or use cloud processing (the former would be more difficult to present in a positive light due to the cost of cloud computing
  - **Construction Precautions**
    - handle all hardware components carefully
    - ground before touching hardware
    - ensure connections are correct
    - do not change connections while arduino/raspberry pi is powered
    
 **Ordered TODO**
 - **Project**
  1. read papers on anxiety indicators, extract and document key information/data
  2. implement synthetic data generation algorithm
  3. train CNN
  4. implement CNN on raspberry pi
  5. interface raspberry pi and arduino, along with other hardware components
  6. write arduino program
  7. construct chassis
  8. assemble all parts
 - **Competition**
  1. find updated rules
  
**Resources**
  - **Rules**
    - https://static1.squarespace.com/static/5c9a89a5b10f2543fc85dacd/t/5d6ed734fa8349000138bbe0/1567545146608/NEDC+19-20+Specifications+w_CA+addendum.pdf
    - https://docs.google.com/document/d/1nAW40ddnQ9bKP-cwnOATC5p0L5kLmP52kOVH_K2hPZ0/edit (official resources doc)
  - **Hardware**
    - https://maker.pro/raspberry-pi/tutorial/how-to-connect-and-interface-raspberry-pi-with-arduino (interfacing arduino and raspberry pi)
    - http://soundsmate.com/principles-microphone-placement/ (mic placement)
    - https://conoroneill.net/2013/06/05/connecting-an-arduino-to-raspberry-pi-for-the-best-of-both-worlds/
  - **Software**
    - https://medium.com/hardware-interfacing/how-to-install-pytorch-v4-0-on-raspberry-pi-3b-odroids-and-other-arm-based-devices-91d62f2933c7 (installing pytorch on raspberry pi)
    - https://opensource.com/article/19/9/audio-processing-machine-learning-python (python audio processing)
  - **Papers** (use researchgate to find free versions of articles)
    - **Detection**
      - https://link.springer.com/article/10.1007/s10919-008-0055-9 (Acoustic Analysis and Perception of Anxiety in Social Phobics’ Speech)
      - https://www.sciencedirect.com/science/article/abs/pii/S0002870300160053 (Heart rate variability in depressive and anxiety disorders)
      - https://www.tandfonline.com/doi/abs/10.1080/03637757109375689?journalCode=rcmm19 (Heart rate as an index of speech anxiety)
      - https://psycnet.apa.org/record/1962-03143-001 (Human heart rate responses during experimentally induced anxiety)
    - **Therapy**
      - https://www.ncbi.nlm.nih.gov/pmc/articles/PMC5072238/ (The Effects of Music Therapy on Anxiety and Depression of Cancer)
      - https://www.sciencedirect.com/science/article/pii/S0197455615000064 (Music therapy in generalized anxiety disorder)
      - https://www.sciencedirect.com/science/article/pii/S0147956398900048 (Effectiveness of a music therapy intervention on relaxation and anxiety for patients receiving ventilatory assistance)
      - https://www.liebertpub.com/doi/abs/10.1089/jpm.2007.0193 (The Effect of Music Therapy on Anxiety in Patients who are Terminally Ill)
      - https://www.sciencedirect.com/science/article/abs/pii/S002239999700202X (Autonomic balance revisited: Panic anxiety and heart rate variability)

  
  
