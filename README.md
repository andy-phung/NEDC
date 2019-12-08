# MESA NEDC (Round 2)
**Project Outline** (this project will be centered around only the detection of *general* anxiety with end-to-end deep learning for medical use (e.g. generating a medical report) and auditory therapy, fabricate a design process)
  - **Title**: DeepEmpathy: End-to-end Deep Learning for General Anxiety Detection and Biofeedback Therapy 
  - **Need to be addressed**: General Anxiety Disorder
  - **Hardware**: 
    - Sparkfun Redboard Artemis (data collection and bluetooth)
    - Single-Lead Heart Rate Monitor (https://learn.sparkfun.com/tutorials/ad8232-heart-rate-monitor-hookup-guide?_ga=2.1023345.1508289744.1574994308-515690866.1572804905)
      - output: .csv or .txt files
      - sampling rate: 400 hz
    - Biomedical Sensor Pads + Sensor Cables
    - Earbuds (Music Therapy)
    - Custom PCB (to reduce size)
  - **Software/Libraries**: 
    - Python (Language)
    - pyHRV (data generation): https://pypi.org/project/pyhrv/
    - BioSPPy (data generation): https://biosppy.readthedocs.io/en/stable/tutorial.html
    - HeartPy (data generation): https://github.com/paulvangentcom/heartrate_analysis_python
    - PyWavelets (data generation): https://pywavelets.readthedocs.io/en/latest/
    - Arduino/Processing IDE
    - Tensorflow/Tensorflow Lite (model training)
    - Google Colab/Azure Notebook (model training) (free tier: https://cloud.google.com/free/)
    - Matplotlib (data visualization)
  - **Approach**
    - **Ideas**
      - use a CNN/ANN to translate ecg sensor output into an anxiety index, if a certain threshold is reached, then use biofeedback therapy (bluetooth + an app) + auditory therapy + document for medical analysis
      - data is stored such that privacy is not compromised
      - (see "experiments" and "affect detection") http://pdfs.semanticscholar.org/a863/6974c07949af64048d97b2b7dfdd098a1f7a.pdf
      - https://sci-hub.tw/10.1016/s0022-3999(97)00202-x
      - a panic attack index will only be generated if the system projects a high likelihood of a relevant panic attack index to prevent unnecessary computation through the use of another network
      - dataset: MIT-BIH Arrhythmia Database
      - input: an X minute .csv or .txt file
      - post end-to-end output: parasympathetic and sympathetic power, two floats
      - final output: anxiety index, on a scale of 0-1
      - wavelet filter: db5
      - encoder sampling rate: 1000 Hz (in the first paper), ??? Hz (when recording with the AD8232 HRM)
      - issue: model size, therefore use a smaller end-to-end model
      - ecg datasets: https://www.kaggle.com/shayanfazeli/heartbeat
    - synthetic training data generation: https://docs.google.com/presentation/d/1D1ASKCW0OqJtmsLNdJZ25GOwJVfOkWi5i0AdKmTHXRs/edit#slide=id.p
    - therapy: 
  - **Competitors**:
    - **Advantages over competitors**:
  - **Design Process**
  
**Logistics**
  - Registration: January 17
  - Project Report, Pitch Presentation, and Tech. Presentation Submission: February 19
  - Members: Andy Phung, Louie Cabrera, ______________
      
**Things to consider**
  - what other methods could be used to reduce anxiety?
  - microphone placement and quality
  - looking over the other high school projects from 2019
  - The possible fact that those who suffer from anxiety disorders could tend to not speak as often as others (this project is essentially "exploit the relationship between [biometric data] with [disorder] to administer [treatment/therapy])
  - the arduino could run a tensorflow neural net or use cloud processing (the former would be more difficult to present in a positive light due to the cost of cloud computing
  - transfer learning: speech recognition -> anxiety detection based on speech
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
  2. fabricate design process
  
**Resources**
  - **Rules**
    - https://static1.squarespace.com/static/5c9a89a5b10f2543fc85dacd/t/5d6ed734fa8349000138bbe0/1567545146608/NEDC+19-20+Specifications+w_CA+addendum.pdf
    - https://docs.google.com/document/d/1nAW40ddnQ9bKP-cwnOATC5p0L5kLmP52kOVH_K2hPZ0/edit (official resources doc)
    - https://drive.google.com/folderview?id=1Corclv49kplbJnT_kUKaY4hlH4KG475a (changes and insights)
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

  
  
