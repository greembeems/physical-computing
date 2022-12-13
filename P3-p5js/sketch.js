var fft;
let serial;
let data = "waiting for data input";
let equalizer = [];

function setup() {
  createCanvas(256, 256);
  colorMode(HSB);
  angleMode(DEGREES);
  fft = new p5.FFT(0.9, 64);
  for (let i = 0; i < 256; i++){
    equalizer[i] = [0, 0];
  }
  serial = new p5.SerialPort();
  serial.list();
  serial.open('COM3'); //connects to the serial port, if it can't connect, recode this to match the port name
  //serial.open("/COM3")  Unsure if something like this works better
  //calls the functions based on the info recieved from the serial port
  serial.on('connected', serverConnected);
  serial.on('list', gotList);
  serial.on('error', gotError);
  serial.on('open', gotOpen);
  serial.on('close', gotClose);
  serial.on('data', gotData);
  console.log(data);
}

function draw() {
  //console.log("Top of draw");
  background(0);
  var spectrum = fft.analyze();
  noStroke();
  var w = width / 64;

//unsure which of the following for loops will work to create the design, and I will cry if neither of them work

  /*for (var i = 0; i < equalizer.length; i++) {
    var amp = equalizer[i];
    var y = map(amp, 0, 256, height, 0);
    fill(i, 255, 255);
    rect(i * w, y, w, height - y);
  }*/

  /*for (let i = 0; i < equalizer.length; i++) {
    fill(i, 255, 255);
    let x = (4 * i) + 10;
    stroke(53, 100);
    line(x, -equalizer[i][0], x, 0);
    stroke(153,100, 0, 100);
    line(x, -equalizer[i][1], x, 0);
  }*/

  //try the other two first, and try this one if none of them work
  for (var i = 0; i < spectrum.length; i++) {
    var amp = spectrum[i];
    var y = map(amp, 0, 256, height, 0);
    fill(i, 255, 255);
    rect(i * w, y, w, height - y);
  }

  stroke(255);
  noFill();
}

function gotData(){
  console.log("top of GotData");
let current = serial.readLine();
trim(current);
if(!current) return;
data = current;
let coords = current.split(",");

if (coords.length == 3) {
  let i = int(coords[0]);
  equalizer[i][0] = float(coords[1]);
  equalizer[i][1] = float(coords[2]);
}

console.log(data);
console.log("Reached the end of GotData");
}

function serverConnected(){
  data = "Connected";
  console.log(data);
}

function gotList(portList){
  data = "List of ports:";
  console.log(data);
  for (let i = 0; i < portList.length; i++) {
    print(i + " " + portList[i]);
  }
}

function gotOpen(){
  data = "Port is open";
  console.log(data);
}

function gotClose(){
  data = "Port is close";
  console.log(data);
}

function gotError(theError){
  data = "Error occurred: ";
  console.log(data + theError);
}