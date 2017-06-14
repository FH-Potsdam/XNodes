#include <XNode.h>
// This is an simple example to wire the XNodes
// 1. an input has to be connected to another nodes output
// 2. an input viurs as to be connected to anothers node output virus
// 3. all xnodes need to share a common ground to make this work
// 4. To reset the xnodes you could connect the RST pin to a button that
//   is connected to GND
//
//
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
// | GPIO pin | is able to pull up? | Used by           |
// | :--      | :--                 |                   |
// | #0       | No                  |                   |
// | #2       | Yes                 | output virus pin  |
// | #4       | Yes                 | input pin         |
// | #5       | Yes                 | input virus pin   |
// | #12      | Yes                 | action led*       |
// | #13      | Yes                 | external button** |
// | #14      | Yes                 | output pin        |
// | #15      | No                  |                   |
// | #16      | No                  |                   |
// |          |                     |                   |
//
//
// * action led is just a representation
// ** external button used to trigger the the information flow

// the communication pins for the xnodes
// use an all xnodes the same pins
int output_pin = 14;
int output_virus_pin = 2;
int input_pin = 4;
int input_virus_pin = 5;

// these are additional pins for testing
// the button connected to pin 13 and GND
// is used to trigger the process
int externalbutton = 13;
// the led on pin 12 is used as an indicator that the
// xnode is in action
int actionled = 12;

// setup the node
XNode node(input_pin, output_pin, input_virus_pin, output_virus_pin);

// we use this boolean to define if we are in an action or not
// if you set this to true on startup the xnode
// will immediately do its action
boolean action = false;

void setup (){
  // the serial communication for debugging
  Serial.begin(115200);
  // set the additional pins
  pinMode(actionled, OUTPUT);
  pinMode(externalbutton, INPUT_PULLUP);

  // initialize the node as the last thing  in the setup
  node.init();
  // nothing else here please execept functions of the node
  // node.setInterval(2000); // sets the length of the output signal
  // node.setInfection(true); // sets the internal flag of the infection
  // node.toggleInfection(); // reverses the current infection state to its opposite
} // end of loop

void loop() {

  // this is the node listening for an signal on its input pin
  // we use the action boolean to not trigger an action while in action
  if(node.listen() == true && action == false){
    action = true;
  }

  // not yet implemented if the other node is "infected"
  // you can listen here for the signal
  // and trigger an action for that
  if(node.listenForVirus() == true){
    // if this is true we are getting a virus from another box
    //
    // if you want you can infect this node yourself
    // node.setInfection(true);
  }

  // we can also ask if the node is infected
  if(node.isInfected() == true){
    // your box is infected
    // lets send our virus out
    node.sendVirus();
  }

  // this is where the action should happen
  // you could also have the node do things all the time
  // it is up to you. If you want the node only to react to
  // other nodes do your action inside of the following block
  if(action == true){
    // do something fancy here
    // blink
    // whatever
    blinkAction(); // this is just for testing
    // after you are done with your action you can
    // send a signal to the next xnode
    // the length of the signal depends in the value of
    // node.setInterval(1000); // in milliseconds  the default is 50
    //
    node.send();
    action = false;
  }

  // this is also for testing only
  // we can trigger the process from this external button
  // if the pull up button is pressed
  if(digitalRead(externalbutton) == LOW){
    // it is connected to the ground
    // so we send out an signal
    node.send();
  }
} // end of loop

// this is just a random action we perform
// it could be anything
// the lights turning on
// a motor moving
// something fancy
void blinkAction(){
  digitalWrite(actionled, HIGH);
  delay(2000);
  digitalWrite(actionled, LOW);
  delay(2000);
}