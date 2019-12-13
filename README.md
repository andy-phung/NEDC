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
      - https://docs.google.com/presentation/d/1D1ASKCW0OqJtmsLNdJZ25GOwJVfOkWi5i0AdKmTHXRs/edit#slide=id.p 
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
      
  - **Competitors**:
    - **Advantages over competitors**:
    
  - **Design Process**
  
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
  3. im
  4. train neural network (input: output of the data generation algorithm)
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

  
  
