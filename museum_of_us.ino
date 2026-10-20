#include <TFT_eSPI.h>
#include <TJpg_Decoder.h>
#include "FS.h"
#include "SPIFFS.h"

TFT_eSPI tft = TFT_eSPI();

// ======================
// LIST FOTO JPG
// ======================
const char* images[] =
{
  "/gambar1.jpg",
  "/gambar2.jpg",
  "/gambar3.jpg",
  "/gambar4.jpg",
  "/gambar5.jpg",
  "/gambar6.jpg",
  "/gambar7.jpg",
  "/gambar8.jpg",
  "/gambar9.jpg",
  "/gambar10.jpg",
  "/gambar11.jpg",
  "/gambar12.jpg"
};

// ======================
// TOTAL FOTO
// ======================
const int totalImages =
sizeof(images) / sizeof(images[0]);

// ======================
int currentImage = 0;

// ======================
// TIMER
// ======================
unsigned long previousMillis = 0;
const long slideInterval = 4000;

// ======================
// CALLBACK JPEG
// ======================
bool tft_output(
  int16_t x,
  int16_t y,
  uint16_t w,
  uint16_t h,
  uint16_t* bitmap
)
{
  if(y >= tft.height())
    return 0;

  tft.pushImage(
    x,
    y,
    w,
    h,
    bitmap
  );

  return 1;
}

// ======================
// SHOW IMAGE
// ======================
void showImage(int index)
{
  tft.fillScreen(TFT_BLACK);

  TJpgDec.drawFsJpg(
    0,
    0,
    images[index]
  );

  Serial.println(
    images[index]
  );
}

// ======================
// SETUP
// ======================
void setup()
{
  Serial.begin(115200);

  tft.init();
  tft.setRotation(0);

  if(!SPIFFS.begin(true))
  {
    Serial.println("SPIFFS ERROR");
    while(1);
  }

  TJpgDec.setCallback(
    tft_output
  );

  TJpgDec.setJpgScale(0);

  showImage(currentImage);
}

// ======================
// LOOP
// ======================
void loop()
{
  unsigned long currentMillis =
  millis();

  if(currentMillis - previousMillis >= slideInterval)
  {
    previousMillis =
    currentMillis;

    currentImage++;

    // LOOPING
    if(currentImage >= totalImages)
    {
      currentImage = 0;
    }

    showImage(currentImage);
  }
}