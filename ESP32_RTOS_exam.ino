int globalIntVar = 5;
 
void setup() {
 
  Serial.begin(112500);
  delay(1000);
  TaskHandle_t myTask;
 xTaskCreatePinnedToCore(
                    coreTask,   /* Function to implement the task */
                    "coreTask", /* Name of the task */
                    10000,      /* Stack size in words */
                    (void*)&globalIntVar,       /* Task input parameter */
                    0,          /* Priority of the task */
                    &myTask,       /* Task handle. */
                    0);  /* Core where the task should run */

                    
Serial.print("Setup: created Task priority = ");
  Serial.println(uxTaskPriorityGet(myTask));
 
}
 
void loop() {
  String taskMessage = "Task main running on core ";
    taskMessage = taskMessage + xPortGetCoreID();
    Serial.println(taskMessage);
  delay(1000);
}

void coreTask( void * pvParameters ){
     Serial.print("globalIntTask: ");
    Serial.println(*((int*)pvParameters));  
    String taskMessage = "Task running on core ";
    taskMessage = taskMessage + xPortGetCoreID();
 
    while(true){
        Serial.println(taskMessage);
        delay(1000);
    }
 
}
