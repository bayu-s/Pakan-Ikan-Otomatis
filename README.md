# 🐾 SmartPetFeeder – Arduino-Based Automatic Feeder with RTC & LCD

**SmartPetFeeder** adalah sistem pemberi makan otomatis untuk hewan peliharaan yang dijalankan menggunakan Arduino. Sistem ini menggunakan **RTC DS3231** untuk penjadwalan waktu, **LCD I2C** untuk menampilkan informasi waktu, dan **servo motor** untuk menggerakkan tempat makanan secara otomatis.

---

## 🔧 Fitur Utama

- ⏰ Penjadwalan makan **dua kali sehari** (pagi dan sore)
- 📟 Tampilan waktu dan status makan di **LCD 16x2 I2C**
- 🔋 Menggunakan **RTC DS3231** untuk akurasi waktu tinggi
- 🦴 Pengeluaran makanan otomatis dengan **servo motor**
- 🔁 Reset status makan setiap tengah malam

---

## 🧰 Komponen yang Dibutuhkan

- Arduino Uno/Nano
- RTC DS3231 Module
- LCD 16x2 I2C
- Servo Motor (SG90 atau sejenis)
- Kabel jumper
- Breadboard atau PCB

---

## 📦 Instalasi dan Pemakaian

### 1. Upload kode
Buka file `auto_feeder.ino` di Arduino IDE dan upload ke board Arduino kamu.

### 2. Set waktu RTC *(opsional)*

```cpp
// Uncomment baris ini sekali untuk set waktu lalu komentari lagi
// rtc.adjust(DateTime(2025, 5, 29, 8, 0, 0));
