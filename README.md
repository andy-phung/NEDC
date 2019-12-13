# MESA NEDC 
**Project Outline** 
  - **Title**: DeepEmpathy: End-to-end Deep Learning for General Anxiety Detection and Biofeedback Therapy 
  - **Need to be addressed**: General Anxiety Disorder
  - **Hardware**: 
    - Sparkfun Redboard Artemis (data collection and bluetooth)
    - Single-Lead Heart Rate Monitor (https://learn.sparkfun.com/tutorials/ad8232-heart-rate-monitor-hookup-guide?_ga=2.1023345.1508289744.1574994308-515690866.1572804905)
      - output: .csv or .txt files
      - sampling rate: 400 hz (?)
    - Biomedical Sensor Pads + Sensor Cables
  - **Software/Libraries**: 
    - py-ecg-detectors (https://pypi.org/project/py-ecg-detectors/) (data generation)
    - Arduino/Processing IDE
    - Tensorflow/Tensorflow Lite (model training)
    - Google Colab/Azure Notebook (model training) (free tier: https://cloud.google.com/free/)
    - Matplotlib (data visualization)
  - **Approach**
    - **Synthetic Data Generation**
      - generate an anxiety index based on an ecg input through an algorithmic process
      - https://colab.research.google.com/drive/1fZexwRJII4A70Wt9Gmr7ArgXaMpJ-biU#scrollTo=TbI-_FbOUj3f
      - https://docs.google.com/presentation/d/1D1ASKCW0OqJtmsLNdJZ25GOwJVfOkWi5i0AdKmTHXRs/edit#slide=id.p (Flowchart)
    - **Neural Network**
      - use an ANN to translate ecg sensor output into an anxiety index, if a certain threshold is reached, then use biofeedback therapy (bluetooth -> an app) and/or auditory therapy 
        - input: .csv or .tsv file representing an X minute ECG 
        - post end-to-end output: parasympathetic and sympathetic power, two floats
        - final output: anxiety index, on a scale of 0-1
        - data is stored such that privacy is not compromised
        - trained and implemented via bluetooth lite
      - issue: model size
      - issue: interfacing between the sparkfun AD8232's output and the neural net
    - **Therapy**
      - **Android App**

  - **Criteria**
    - **Neural Network**
      - \>98% accuracy in recognizing panic attacks based on biofeedback sensor data (test set)
        - \>99% accuracy on the training and dev sets
        - ECG denoising should be incorporated
        - the neural network has not overfitted to its training data/has low bias
        - the neural net has low variance
        - optimization techniques were applied
        - hyperparameter tuning was used
        - the most optimal neural architecture was used
        - program/model size needs to be under 1MB
    - **Data Generation**
      - 
    - **Therapy**
      - provides real-time, adaptive, and noninvasive therapy
      - have a pronounced effect on the user's panic attacks/anxiety the longer the user uses this (use existing biofeedback methods for anxiety/panic disorder to support this)
      - uses music therapy to support the biofeedback process
        - **App*
          - http://users.csc.calpoly.edu/~jdalbey/SWE/QA/UICriteria.html
          - the client can manually adjust the system to fit their needs
          - encrypts and stores the user's data for future medical analysis (not necessary)
    - **System**
      - the cost should be below a certain threshold
      - system lifetime and replacement intervals
      - battery life, if applicable
      - biofeedback sensors are noninvasive and are resistant to movement artifact
      - biofeedback sensors can be worn comfortably on a daily basis and are unobtrusive
      - the user's privacy is not compromised
      
  - **Design Process**
        
  - **Competitors**:
    - **Advantages over competitors**:
    
**Logistics**
  - Registration: January 17
  - Project Report, Pitch Presentation, and Technical Presentation Submission: February 19
  - Members: Andy, Louie, Nathan, Suryabhan
  - **Work Distribution**
    - Andy:
    - Louie: 
    - Nathan:
    - Suryabhan: 
    
 **TODO**
 - **Project**
  1. implement synthetic data generation algorithm
  2. gather baseline ECG data
  3. implement interfacing between the single-lead heart rate monitor's serial output and the neural net
  4. train neural network (input: output of the data generation algorithm)
  5. implement neural net
  6. implement interfacing between the redboard artemis and android via bluetooth (BLE)
  7. create an android app to allow for biofeedback and/or auditory therapy
  8. design and 3d print an enclosure
 - **Competition**
  1. find updated rules
  2. project report
  3. poster
  4. technical presentation
  5. pitch presentation
  
**Resources**
  - **Rules**
    - https://static1.squarespace.com/static/5c9a89a5b10f2543fc85dacd/t/5d6ed734fa8349000138bbe0/1567545146608/NEDC+19-20+Specifications+w_CA+addendum.pdf
    - https://docs.google.com/document/d/1nAW40ddnQ9bKP-cwnOATC5p0L5kLmP52kOVH_K2hPZ0/edit (official resources doc)
    - https://drive.google.com/folderview?id=1Corclv49kplbJnT_kUKaY4hlH4KG475a (changes and insights)
  - **Papers** (use researchgate to find free versions of articles)
    - **Detection**
      - http://pdfs.semanticscholar.org/a863/6974c07949af64048d97b2b7dfdd098a1f7a.pdf- 
    - **Therapy**
      - https://www.ncbi.nlm.nih.gov/pmc/articles/PMC5072238/ (The Effects of Music Therapy on Anxiety and Depression of Cancer)
      - https://www.sciencedirect.com/science/article/pii/S0197455615000064 (Music therapy in generalized anxiety disorder)
      - https://link.springer.com/article/10.1007/s10484-007-9046-6 
      - https://link.springer.com/article/10.1007/s10484-007-9046-6

  
  
