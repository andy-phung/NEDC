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
//#include "model1.h"
#include "model2.h" //note: model1 is defined as "model1" in this header file, not "model"


tflite::ErrorReporter* error_reporter = nullptr;
const tflite::Model* model = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;
TfLiteTensor* input = nullptr;
TfLiteTensor* output = nullptr;
int inference_count = 0;

// Create an area of memory to use for input, output, and intermediate arrays.
// Finding the minimum value for your model may require some trial and error.
constexpr int kTensorArenaSize = 290 * 1024;
uint8_t tensor_arena[kTensorArenaSize];

int red_light_pin= 4;
int green_light_pin = 3;
int blue_light_pin = 2;
int button_pin

int numSamples = 3;
int samplesRead = 0;

float readECG()
{
  if((digitalRead(9) == 1)||(digitalRead(10) == 1)){
    return 0;
  }
  else {
    // send the value of analog input 0:
      float read = analogRead(A0);
      return read;
  }
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

  
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(button_pin, OUTPUT);
  Serial.begin(9600);
  static tflite::MicroErrorReporter micro_error_reporter;
  error_reporter = &micro_error_reporter;

  // Map the model into a usable data structure. This doesn't involve any
  // copying or parsing, it's a very lightweight operation.
  model = tflite::GetModel(model2);
  if (model->version() != TFLITE_SCHEMA_VERSION) {
    error_reporter->Report(
        "Model provided is schema version %d not equal "
        "to supported version %d.",
        model->version(), TFLITE_SCHEMA_VERSION);
    return;
  }

  // This pulls in all the operation implementations we need.
  // NOLINTNEXTLINE(runtime-global-variables)
  static tflite::ops::micro::AllOpsResolver resolver;
  
  // Build an interpreter to run the model with.

  static tflite::MicroInterpreter static_interpreter(
      model, resolver, tensor_arena, kTensorArenaSize, error_reporter);
  
  interpreter = &static_interpreter;

   //interpreter = new tflite::MicroInterpreter(model, resolver, tensor_arena, kTensorArenaSize, &micro_error_reporter);
  
  // Allocate memory from the tensor_arena for the model's tensors.
  TfLiteStatus allocate_status = interpreter->AllocateTensors();
  if (allocate_status != kTfLiteOk) {
    error_reporter->Report("AllocateTensors() failed");
    return;
  }
  
  // Obtain pointers to the model's input and output tensors.
  input = interpreter->input(0);
  output = interpreter->output(0);
  Serial.println(0);
  Serial.println(0.25);
  //TfLiteStatus invokeStatus = interpreter->Invoke();
  
}

void loop() {
while(samplesRead < numSamples){
  buttonState = digitalRead(buttonPin); //can be either HIGH or LOW
  input->data.f[samplesRead] = (readECG() - 200)/700;
  //Serial.println("input:");
  //Serial.println((readECG() - 200)/700);
  samplesRead++;
  if (samplesRead == numSamples) {
        // Run inferencing
        //TfLiteStatus invokeStatus = interpreter->Invoke();
       /*
        if (invokeStatus != kTfLiteOk) {
          Serial.println("Invoke failed!");
          while (1);
        }
*/
        samplesRead = 0;
        Serial.println("output:");
        Serial.println(abs(output->data.f[0])); 
        }
  delay(2000);
  }
  }
