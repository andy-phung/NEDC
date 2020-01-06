#if defined(min)
#undef min
#endif

#if defined(max)
#undef max
#endif

#include <TensorFlowLite.h>
#include "tensorflow/lite/experimental/micro/kernels/micro_ops.h"
#include "tensorflow/lite/experimental/micro/micro_error_reporter.h"
#include "tensorflow/lite/experimental/micro/micro_interpreter.h"
#include "tensorflow/lite/experimental/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/experimental/micro/kernels/all_ops_resolver.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"
#include "model1.h" //note: model1 is defined as "model1" in this header file, not "model"
//#include "model2.h"
namespace {
constexpr int tensorArenaSize1 = 10 * 1024;
uint8_t tensorArena1[tensorArenaSize1];

tflite::MicroErrorReporter tflErrorReporter;
tflite::ops::micro::AllOpsResolver tflOpsResolver;

const tflite::Model* tflModel1 = nullptr;
tflite::MicroInterpreter* tflInterpreter1 = nullptr;
TfLiteTensor* tflInputTensor1 = nullptr;
TfLiteTensor* tflOutputTensor1 = nullptr;
//const tflite::Model* tflModel2 = nullptr;
//tflite::MicroInterpreter* tflInterpreter2 = nullptr;
//TfLiteTensor* tflInputTensor2 = nullptr;
// TfLiteTensor* tflOutputTensor2 = nullptr;
// Create a static memory buffer for TFLM, the size may need to be adjusted based on the size of the model

//constexpr int tensorArenaSize2 = 19 * 1024;

//byte tensorArena2[tensorArenaSize2];
}
int numSamples = 200;
int samplesRead = 0;

int readECG()
{
  if((digitalRead(9) == 1)||(digitalRead(10) == 1)){
    return 0;
  }
  else {
    // send the value of analog input 0:
      int read = analogRead(A0);
      return read;
  }
}
  
void setup() {
  Serial.begin(9600);
  Serial.println("cp 1");
  
//get the TFL representation of the model byte array for both models
  
  tflModel1 = tflite::GetModel(model1);
  if (tflModel1->version() != TFLITE_SCHEMA_VERSION) {
    Serial.println("Model schema mismatch!");
    //while (1);
  }
  Serial.println("cp 2");
  
  /*
  tflModel2 = tflite::GetModel(model2);
  if (tflModel2->version() != TFLITE_SCHEMA_VERSION) {
    Serial.println("Model schema mismatch!");
    while (1);
  }
  */


  // Create an interpreter to run the model
  tflInterpreter1 = new tflite::MicroInterpreter(tflModel1, tflOpsResolver, tensorArena1, tensorArenaSize1, &tflErrorReporter);
  //tflInterpreter2 = new tflite::MicroInterpreter(tflModel2, tflOpsResolver, tensorArena2, tensorArenaSize2, &tflErrorReporter);
  // Allocate memory for the model's input and output tensors
  tflInterpreter1->AllocateTensors();
  //tflInterpreter2->AllocateTensors();
  Serial.println("cp 3");
  // Get pointers for the model's input and output tensors
  tflInputTensor1 = tflInterpreter1->input(0);
  tflOutputTensor1 = tflInterpreter1->output(0);
  //tflInputTensor2 = tflInterpreter2->input(0);
  //tflOutputTensor2 = tflInterpreter2->output(0);
  Serial.print("we've reached point 2");

  
}

void loop() {
while (samplesRead < numSamples){
  tflInputTensor1->data.f[samplesRead] = (readECG() - 200)/700;
  samplesRead++;
  if (samplesRead == numSamples) {
        // Run inferencing
        TfLiteStatus invokeStatus1 = tflInterpreter1->Invoke();
        if (invokeStatus1 != kTfLiteOk) {
          Serial.println("Invoke failed!");
          while (1);
          return;
        }
        for (int i = 0; i < 1; i++) {
          Serial.print(tflOutputTensor1->data.f[i]);
          Serial.print(" ");
        }
        Serial.print("\n");
   }
  }
 }
