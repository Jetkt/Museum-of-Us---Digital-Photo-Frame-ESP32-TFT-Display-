# 🖼️ Museum of Us - Digital Photo Frame (ESP32 & TFT Display)

Proyek galeri foto digital pribadi (**"Museum of Us"**) berbasis mikrokontroler **ESP32** yang terintegrasi dengan **TFT LCD Display** dan penyimpanan internal **SPIFFS**. Perangkat ini dirancang untuk menampilkan tayangan *slideshow* foto kenangan secara otomatis, mulus, dan terus-menerus (*looping*).

---

## 📌 Deskripsi Proyek

Proyek ini memanfaatkan memori internal ESP32 (SPIFFS) untuk menyimpan dan membaca sekumpulan file gambar berformat JPEG. Menggunakan pustaka **TFT_eSPI** untuk performa grafis yang cepat dan **TJpg_Decoder** untuk mendekode gambar JPG secara efisien, perangkat ini dapat menampilkan foto secara bergantian setiap beberapa detik secara otomatis menggunakan fungsi *non-blocking timer* (`millis()`).

---

## ⚙️ Fitur Utama

- **Tampilan Galeri Otomatis (*Slideshow*):** Menampilkan daftar foto secara berurutan dan melakukan *looping* kembali ke foto awal secara otomatis.
- **Dekoder JPEG Efisien (`TJpg_Decoder`):** Memungkinkan decoding file JPEG berukuran besar agar dapat dirender dengan cepat pada layar TFT.
- **Penyimpanan Internal SPIFFS:** Membaca file gambar (`/gambar1.jpg`, `/gambar2.jpg`, dst.) langsung dari memori Flash ESP32.
- **Sistem Non-Blocking (`millis`):** Pergantian slide foto diatur menggunakan pewaktu internal tanpa menggunakan fungsi `delay()`, sehingga sistem tetap responsif.
- **Pembersihan Layar Dinamis:** Membersihkan layar secara otomatis setiap kali transisi foto baru dimuat (`tft.fillScreen`).

---

## 🛠️ Perangkat Keras & Komponen (Hardware)

- **Mikrokontroler:** ESP32 DevKit V1
- **Display:** TFT LCD Display (kompatibel dengan driver `TFT_eSPI`)
- **Penyimpanan:** SPIFFS (Flash Memory internal ESP32)
- **Kabel Jumper & Breadboard**

---

## 📁 Struktur Repositori

```text
├── data/                    # Folder berisi file gambar .jpg (gambar1.jpg - gambar12.jpg)
├── museum_of_us.ino         # Program utama ESP32 (Slideshow, SPIFFS, & TJpg_Decoder)
└── README.md                # Dokumentasi resmi proyek
