# Sistem Pintu Otomatis Berbasis RFID Menggunakan Arduino Uno

## Deskripsi
Proyek ini merupakan sistem pintu otomatis berbasis RFID yang dikembangkan menggunakan Arduino Uno. Sistem ini dibuat untuk mengatur akses masuk suatu ruangan dengan memanfaatkan kartu RFID yang telah terdaftar. Dengan adanya sistem ini, proses pembukaan pintu menjadi lebih praktis serta dapat meningkatkan keamanan ruangan.

## Komponen yang Digunakan
- Arduino Uno  
- Modul RFID MFRC522  
- Relay  
- LED hijau dan LED merah  
- Kabel jumper dan breadboard  
- Power supply  

## Cara Kerja Sistem
1. Kartu RFID didekatkan ke modul pembaca RFID.
2. Sistem membaca UID dari kartu RFID.
3. UID kartu dibandingkan dengan data kartu yang telah terdaftar.
4. Jika kartu terdaftar, relay akan aktif dan pintu terbuka secara otomatis.
5. Jika kartu tidak terdaftar, akses akan ditolak dan LED merah menyala sebagai indikator.

## Bahasa dan Teknologi
- Bahasa pemrograman: C/C++ (Arduino IDE)  
- Platform: Arduino Uno  
- Library: SPI dan MFRC522  

## Proses Pengerjaan
Pengerjaan proyek dimulai dengan perancangan konsep sistem pintu otomatis berbasis RFID. Selanjutnya dilakukan perakitan perangkat keras dan pemrograman Arduino untuk membaca kartu RFID, mengontrol relay, serta menampilkan status akses menggunakan LED. Tahap terakhir adalah pengujian sistem untuk memastikan seluruh komponen dapat bekerja sesuai dengan fungsinya.
