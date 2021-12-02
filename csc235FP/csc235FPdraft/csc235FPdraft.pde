import processing.serial.*;

int val1 = 0;
int val2 = 200;
int val3 = 150;
int val4 = 1;

String outMessage;


String portname = "/dev/cu.usbserial-1410";
Serial port = new Serial(this, portname, 9600);


void setup() {
  //port = new Serial(this, portname, 9600);
}

void draw() {
  
  
}



void send() {
  char startChar = '?';
  char endChar = '!';

  port.write(startChar + str(val1) + "," + str(val2) + "," + str(val3) + "," + str(val4) + "," + str(val4) + endChar);
  println(startChar + str(val1) + "," + str(val2) + "," + str(val3) + "," + str(val4) + endChar);
}

void keyPressed() {
  
  if (key == 'w') {
    val3 += 255;
  }
  
  if (val3 > 255) {
    val3 = 255;
  }
  
  if (key == 's') {
    val3 -= 255;
    //interval = startTime;
  }
  
  if (val3 < 0) {
    val3 = 0;
  }
  
  if (key == 'd') {
    val4 += 1;
  }
  
  if (val4 > 6) {
    val4 = 1;
  }
  
  //CASE TEST
  /*
  if (key == 'a'){
   val1 += 1;
   }
   if(val1 > 1){
   val1 = 0;
   }*/
   if (key == 'x') {
    val1 = 0;
  }
  if (key == 'c') {
    val1 = 1;
  }
  if (key == 'v') {
    val1 = 2;
  }
  if (key == 'b') {
    val1 = 3;
  }
  if (key == 'n') {
    val1 = 4;
  }
  if (key == 'm') {
    val1 = 5;
  }
  //test
  //if(key == 'p'){
  //  val1 = 7;
  //}
  
  send();
}
