#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C dan ukuran LCD
RTC_DS3231 rtc;  // Objek RTC
Servo servo;     // Objek servo

// Waktu makan (jam dan menit)
const int pagiJam = 18;
const int pagiMenit = 12;
const int soreJam = 17;
const int soreMenit = 0;

// Status sudah memberi makan
bool sudahMakanPagi = false;
bool sudahMakanSore = false;

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  servo.attach(9);  // Sambungkan ke pin 9 Arduino

  if (!rtc.begin()) {
    lcd.print("RTC Error");
    while (1);
  }

  // Atur posisi awal servo
  servo.write(0);

  // // UNCOMMENT sekali saja untuk atur waktu, lalu KOMENTAR lagi
  // rtc.adjust(DateTime(2025, 5, 29, 8, 0, 0));  // Tahun, bulan, tanggal, jam, menit, detik

  lcd.setCursor(0, 0);
  lcd.print("Set 1: 02:00");
  lcd.setCursor(0, 1);
  lcd.print("Set 2: 17:00");
  delay(2000);
  lcd.clear();
}

void loop() {
  static int lastSecond = -1;
  DateTime now = rtc.now();

  if (now.second() != lastSecond) {
    lastSecond = now.second();

    // Tampilkan waktu
    lcd.setCursor(0, 0);
    char buf[16];
    sprintf(buf, "Waktu: %02d:%02d:%02d", now.hour(), now.minute(), now.second());
    lcd.print(buf);

    // Reset status harian saat tengah malam
    if (now.hour() == 0 && now.minute() == 0 && now.second() == 0) {
      sudahMakanPagi = false;
      sudahMakanSore = false;
    }

    // Pemberian makan pagi
    if (now.hour() == pagiJam && now.minute() >= pagiMenit && now.minute() <= pagiMenit + 1 && !sudahMakanPagi) {
      lcd.setCursor(0, 1);
      lcd.print("Makan Pagi!     ");
      beriMakan();
      sudahMakanPagi = true;
    }
    // Pemberian makan sore
    else if (now.hour() == soreJam && now.minute() >= soreMenit && now.minute() <= soreMenit + 1 && !sudahMakanSore) {
      lcd.setCursor(0, 1);
      lcd.print("Makan Sore!     ");
      beriMakan();
      sudahMakanSore = true;
    }
    else {
      lcd.setCursor(0, 1);
      lcd.print("Bukan Wkt Makan ");
    }
  }
}

// Fungsi untuk memberi makan (servo bergerak)
void beriMakan() {
  servo.write(90);  // Gerakkan servo ke 90 derajat
  delay(1000);      // Tunggu 1 detik
  servo.write(0);   // Kembali ke posisi awal
}
