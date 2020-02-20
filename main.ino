#if defined(min)
#undef min
#endif

#if defined(max)
#undef max
#endif

#define RX1 0
#define TX1 1
#define LOMINUS 10
#define LOPLUS 9
#define RED 7
#define GREEN 6
#define BLUE 5

#include <SoftwareSerial.h> 

#include <TensorFlowLite.h>
#include "tensorflow/lite/experimental/micro/kernels/micro_ops.h"
#include "tensorflow/lite/experimental/micro/micro_error_reporter.h"
#include "tensorflow/lite/experimental/micro/micro_interpreter.h"
#include "tensorflow/lite/experimental/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/experimental/micro/kernels/all_ops_resolver.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"
#include "model1.h"
#include "model2.h" //note: model1 is defined as "model1" in this header file, not "model"

SoftwareSerial BLE(1,0);

#include "functions.h"

tflite::ErrorReporter* error_reporter = nullptr;
const tflite::Model* model = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;
TfLiteTensor* input = nullptr;
TfLiteTensor* output = nullptr;
int inference_count = 0;

// Create an area of memory to use for input, output, and intermediate arrays.
// Finding the minimum value for your model may require some trial and error.
constexpr int kTensorArenaSize = 150 * 1024;
uint8_t tensor_arena[kTensorArenaSize];

int red_light_pin= 7;
int green_light_pin = 6;
int blue_light_pin = 5;
int button_pin = 4; 

int numSamples = 3;
int samplesRead = 0;
char recvChar;
int counter = 0;
  
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(RX1, INPUT);
  pinMode(TX1, OUTPUT);
  Serial.begin(9600);
  setupBleConnection();
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
  //TfLiteStatus invokeStatus = interpreter->Invoke();
  RGB_Color(139, 0, 0); // Dark Red
}

void loop() {
while(samplesRead < numSamples){
  BLE.print(readECG());
  Serial.println(readECG());
  recvChar = BLE.read(); //can be either HIGH or LOW
  if(recvChar = 'c'){
    RGB_Color(0, 255, 255); //Cyan
  }
  if(recvChar = 's'){
    //Artemis_Deep_Sleep();
    RGB_Color(0, 0, 0);
  }
  input->data.f[samplesRead] = (readECG() - 200)/700;
  //Serial.println("input:");
  //Serial.println((readECG() - 200)/700);
  samplesRead++;
  counter++;
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
        };
   delay(50);
   if (counter == 40){
    delay(10);
    counter = 0;
    BLE.print("i"); 
    BLE.print(abs(output->data.f[0])/1.25); 
    Serial.print("i");
    Serial.println(abs(output->data.f[0])/1.25); 
    delay(10);
   }
  

  }
  
  }
