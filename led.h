
#define PIN_RED 4     // GIOP23
#define PIN_GREEN 16  // GIOP22
#define PIN_BLUE 17   // GIOP21

#define RPWMRES 8
#define GPWMRES 8
#define BPWMRES 8

int br = 0;

void ledSetup() {
  ledcSetup(0, 12000, RPWMRES);
  ledcSetup(1, 12000, GPWMRES);
  ledcSetup(2, 12000, BPWMRES);
  ledcAttachPin(4, 0);
  ledcAttachPin(16, 1);
  ledcAttachPin(17, 2);
}

void setLedBrightness(int brightness) {
  br = map(brightness, 0, 4095, 255, 0);
}

void setColor(uint8_t r, uint8_t g, uint8_t b) {
  ledcWrite(0, map(map(r, 255, 0, 100, 0), 0, 255, 255, br));
  ledcWrite(1, map(g, 0, 255, 255, br));
  ledcWrite(2, map(map(b, 255, 0, 150, 0), 0, 255, 255, br));
  // ledcWrite(0, map(map(r, 255, 0, 100, 0), 0, 255, 255, br));
  // ledcWrite(1, map(g, 0, 255, 255, br));
  // ledcWrite(2, map(map(b, 255, 0, 150, 0), 0, 255, 255, br));
}