#include <XNode.h>
// The Input pins need to be pullup pins
// to simplify the circuit
//
// Which pins are able to be used with an internal
// pull up resistor on the Adafruit Feather Huzzah ESP8266?
//
// There has been some confusion around.
// https://forums.adafruit.com/viewtopic.php?f=19&t=86182
// http://www.esp8266.com/viewtopic.php?f=32&t=11614
// so this is a table of the test
//
// | GPIO pin | is able to pull up? |
// | :--      | :--                 |
// | #0       | No                  |
// | #2       | Yes                 |
// | #4       | Yes                 |
// | #5       | Yes                 |
// | #12      | Yes                 |
// | #13      | Yes                 |
// | #14      | Yes                 |
// | #15      | No                  |
// | #16      | No                  |
//

int output_pin = 0;
int output_virus_pin = 2;
int input_pin = 4;
int input_virus_pin = 5;
int counter = 0;
XNode node(input_pin, output_pin, input_virus_pin, output_virus_pin);

boolean action = false;
void setup (){
  node.init();
  // setup all the other pins you need
}

void loop(){

  counter++;
  if(counter == 1000){
    node.toggleInfection();
    counter = 0;
  }

  if(node.listen() == true && action == false){
    action = true;
  }



  if(node.listenForVirus() == true){
    // if this is true we are getting a virus from another box
    //
    //
  }


  if(node.isInfected() == true){
    // your box is infected
    // lets send our virus out
    node.sendVirus();
  }


  if(action == true){
    // do something fancy here
    // delay(2000);
    // blink
    // whatever
    node.send();
    action = false;
  }
}