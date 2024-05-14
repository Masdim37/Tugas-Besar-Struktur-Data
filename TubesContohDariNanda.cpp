#include <iostream>
#include <unordered_map>
#include <string>
#include <list>

using namespace std;

// Struktur data untuk barang
struct Barang {
    string nama;
    int harga;
    int stok;
};

// Struktur data untuk transaksi
struct Transaksi {
    string namaPelanggan;
    string namaBarang;
    int jumlah;
    int totalHarga;
    string tanggalPembelian;
    int uangDibayar; // Tambahkan uang yang dibayar pelanggan
    int kembalian;   // Tambahkan kembalian
};

int main() {
    int opsi;
    string namaBarang;
    int jumlahBarang;
    string namaPelanggan;
    bool ditemukan = false;
    char tambahPelanggan;
    bool barangDitemukan = false;
    int totalHarga;
    int uangDibayar;
    int kembalian;
    // Hash table untuk data pelanggan
    unordered_map<string, string> pelanggan;

    // Linked list untuk data barang
    list<Barang> daftarBarang;

    // Array untuk menyimpan transaksi
    const int MAX_TRANSAKSI = 100;
    Transaksi transaksi[MAX_TRANSAKSI];
    int jumlahTransaksi = 0;

    while (true) {
        
        cout << "\nMenu Utama\n";
        cout << "1. Tampilkan daftar barang\n";
        cout << "2. Cari barang\n";
        cout << "3. Proses pembelian\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> opsi;
        
        switch(opsi){
            case 1:
                // Tampilkan daftar barang
                cout << "\nDaftar Barang:\n";
                for (const auto& barang : daftarBarang) {
                    cout << "Nama: " << barang.nama << ", Harga: " << barang.harga << ", Stok: " << barang.stok << endl;
                }
                break;
            case 2:
                // Cari barang
                cout << "Masukkan nama barang yang ingin dicari: ";
                cin >> namaBarang;
                for (const auto& barang : daftarBarang) {
                    if (barang.nama == namaBarang) {
                        cout << "Detail Barang:\n";
                        cout << "Nama: " << barang.nama << ", Harga: " << barang.harga << ", Stok: " << barang.stok << endl;
                        ditemukan = true;
                        break;
                    }
                }
                if (!ditemukan) {
                    cout << "Barang tidak ditemukan.\n";
                }
                break;
            case 3:
                // Proses pembelian
                cout << "Masukkan nama pelanggan: ";
                cin >> namaPelanggan;
                if (pelanggan.find(namaPelanggan) == pelanggan.end()) {
                    cout << "Pelanggan tidak ditemukan. Tambahkan pelanggan baru? (y/n): ";
                    cin >> tambahPelanggan;
                    if (tambahPelanggan == 'y' || tambahPelanggan == 'Y') {
                        pelanggan[namaPelanggan] = namaPelanggan;
                        cout << "Pelanggan baru berhasil ditambahkan.\n";
                    } else {
                        cout << "Proses pembelian dibatalkan.\n";
                        break;
                    }
                }
                // Deklarasi variabel di sini
                cout << "Pilih barang yang ingin dibeli:\n";
                cout << "Nama barang: ";
                cin >> namaBarang;
                for (auto& barang : daftarBarang) {
                    if (barang.nama == namaBarang) {
                        barangDitemukan = true;
                        cout << "Jumlah barang: ";
                        cin >> jumlahBarang;
                        if (barang.stok >= jumlahBarang) {
                            totalHarga = barang.harga * jumlahBarang;
                            barang.stok -= jumlahBarang;
                            cout << "Total harga: " << totalHarga << endl;
                            cout << "Jumlah uang yang dibayarkan: ";
                            cin >> uangDibayar;
                            if (uangDibayar >= totalHarga) {
                                kembalian = uangDibayar - totalHarga;
                                cout << "Kembalian: " << kembalian << endl;
                                // Tambahkan transaksi
                                transaksi[jumlahTransaksi++] = {namaPelanggan, namaBarang, jumlahBarang, totalHarga, "tanggal", uangDibayar, kembalian};
                            } else {
                                cout << "Uang yang dibayarkan tidak mencukupi.\n";
                            }
                        } else {
                            cout << "Stok barang tidak mencukupi.\n";
                        }
                        break; // Keluar dari loop setelah menemukan barang
                    }
                }
                if (!barangDitemukan) {
                    cout << "Barang tidak ditemukan.\n";
                }
                break;
            case 4:
                // Keluar
                return 0;
            default:
                cout << "Opsi tidak valid.\n";
                break;
        }
    }

    return 0;
}