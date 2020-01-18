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
#include "model1.h"
#include "model2.h" //note: model1 is defined as "model1" in this header file, not "model"

#define RX1 0
#define TX1 1
#define LOMINUS 10
#define LOPLUS 9
#define RED 7
#define GREEN 6
#define BLUE 5
#define BUTTON_PIN 4


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
  if(buttonState == HIGH){
    power_adc_disable();

  // Initialize for low power in the power control block
  am_hal_pwrctrl_low_power_init();

  // Stop the XTAL.
  am_hal_clkgen_control(AM_HAL_CLKGEN_CONTROL_XTAL_STOP, 0);

  // Disable the RTC.
  am_hal_rtc_osc_disable();

  // The default Arduino environment runs the System Timer (STIMER) off the 48 MHZ HFRC clock source.
  // The HFRC appears to take over 60 uA when it is running, so this is a big source of extra
  // current consumption in deep sleep.
  // For systems that might want to use the STIMER to generate a periodic wakeup, it needs to be left running.
  // However, it does not have to run at 48 MHz. If we reconfigure STIMER (system timer) to use the 32768 Hz
  // XTAL clock source instead the measured deepsleep power drops by about 64 uA.
  am_hal_stimer_config(AM_HAL_STIMER_CFG_CLEAR | AM_HAL_STIMER_CFG_FREEZE);

  // This option selects 32768 Hz via crystal osc. This appears to cost about 0.1 uA versus selecting "no clock"
  am_hal_stimer_config(AM_HAL_STIMER_XTAL_32KHZ);

  // This option would be available to systems that don't care about passing time, but might be set
  // to wake up on a GPIO transition interrupt.
  // am_hal_stimer_config(AM_HAL_STIMER_NO_CLK);

  // Turn OFF Flash1
  if (am_hal_pwrctrl_memory_enable(AM_HAL_PWRCTRL_MEM_FLASH_512K))
  {
    while (1);
  }

  // Power down SRAM
  PWRCTRL->MEMPWDINSLEEP_b.SRAMPWDSLP = PWRCTRL_MEMPWDINSLEEP_SRAMPWDSLP_ALLBUTLOWER32K;

  Serial.println("Going to sleep...");
  delay(100); //Wait for print to complete

  Serial.end(); //Disable Serial

  am_hal_sysctrl_sleep(AM_HAL_SYSCTRL_SLEEP_DEEP);
  }
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
//TODO: retrain model, make sure code is consistent
