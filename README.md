# 🐟 AutoFishFeeder – Arduino-Based Automatic Fish Feeder with RTC & LCD

**AutoFishFeeder** adalah alat pemberi makan ikan otomatis berbasis Arduino yang dirancang untuk menjadwalkan waktu makan ikan secara rutin. Sistem ini menggunakan modul **RTC DS3231** untuk akurasi waktu, menampilkan jam dan status di **LCD I2C**, serta menggerakkan servo motor untuk mengeluarkan pakan.

---

## 🔧 Fitur Utama

- 🕒 Penjadwalan makan **dua kali sehari** (pagi & sore)
- 📟 Informasi waktu dan status makan di **LCD 16x2**
- 🎯 Akurasi tinggi dengan modul **RTC DS3231**
- 🐠 Pakan keluar otomatis dengan **servo motor**
- 🔁 Reset otomatis status makan setiap tengah malam

---

## 🧰 Komponen yang Dibutuhkan

- Arduino Uno/Nano
- Modul RTC DS3231
- LCD 16x2 I2C
- Servo Motor (SG90 atau sejenis)
- Kabel jumper
- Breadboard / PCB

---

## ⚙️ Cara Kerja

1. Waktu saat ini ditampilkan di LCD secara real-time.
2. Ketika waktu makan tiba (default: **08:00** dan **17:00**), servo akan berputar untuk menjatuhkan pakan.
3. Status "sudah makan" disimpan agar tidak memberi makan dua kali.
4. Sistem di-reset otomatis setiap pukul **00:00**.

---

## 📦 Instalasi dan Pemakaian

### 1. Upload kode
Buka file `fish_feeder.ino` di Arduino IDE dan upload ke board Arduino kamu.

### 2. Set waktu RTC *(jika perlu pertama kali)*

```cpp
// Aktifkan ini sekali untuk set waktu RTC, lalu komentari kembali
// rtc.adjust(DateTime(2025, 5, 29, 8, 0, 0));
