#include <iostream>

using namespace std;

string datadiri[5]; //array untuk menyimpan datadiri
string PesananBeef[50], PesananChicken[50], PesananFish[50], PesananDrinks[50]; //array untuk menyimpan pesanan
int TotalBeef = sizeof(PesananBeef)/sizeof(*PesananBeef); //bersisi nilai dari besaran aray PesananBeef
int TotalChicken = sizeof(PesananChicken)/sizeof(*PesananChicken); //bersisi nilai dari besaran aray PesananChicken
int TotalFish = sizeof(PesananFish)/sizeof(*PesananFish); //bersisi nilai dari besaran aray PesananFish
int TotalDrinks = sizeof(PesananDrinks)/sizeof(*PesananDrinks); //bersisi nilai dari besaran aray PesananDrinks
int JmlPesananBeef[50], JmlPesananChicken[50], JmlPesananFish[50], JmlPesananDrinks[50]; //array untuk menyimpan jumlah pesanan
int HargaBeef[50], HargaChicken[50], HargaFish[50], HargaDrinks[50]; //array untuk menyimpan harga pesanan
int TotalHarga, TotalHargaBeef, TotalHargaChicken, TotalHargaFish, TotalHargaDrinks; //variabel untuk menghitung total harga setiap variasi olahan
float HargaDiskon; //variabel untuk menyimpan besaran diskon
string CekVoucher, InputVoucher; //variabel yang digunakan pada saat input voucher
int CekMenuAwal, CekOlahan, PilihBeef, PilihChicken, PilihFish, PilihDrinks; //variabel yang digunakan sebagai ekspresi switchcase

// dhimas
void Kwitansi() {
    string *a = &datadiri[0]; //variabel pointer a menyimpan alamat array datadiri[0]
    string *b = &datadiri[2]; //variabel pointer b menyimpan alamat array datadiri[2]
    string *c = &datadiri[4]; //variabel pointer c menyimpan alamat array datadiri[4]
    string Nama = *a; //variabel Nama mengambil nilai array datadiri[0] melalui pointer a
    string NoTelp = *b; //variabel NoTelp mengambil nilai array datadiri[2] melalui pointer b
    string Alamat = *c; //variabel Alamat mengambil nilai array datadiri[4] melalui pointer c
    cout << "===========================================================" << endl;
    cout << "=======================JAVASTEAK APP=======================" << endl;
    cout << "===============PESAN STEAK SEMUDAH SATU KLIK===============" << endl;
    cout << endl;
    cout << "---------------------KWITANSI PESANAN----------------------" << endl;
    cout << endl;
    cout << "Nama = " << Nama << endl;
    cout << "No. Telp = " << NoTelp << endl;
    cout << "Alamat Pengantaran = " << Alamat << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Pesanan Kamu = " << endl;
    cout << endl;
    // Cetak pesanan beef
    for (int i = 0; i < TotalBeef && !PesananBeef[i].empty(); i++) {
        cout << PesananBeef[i] << " x " << JmlPesananBeef[i] << endl;
        cout << "      " << HargaBeef[i] << " x " << JmlPesananBeef[i] << endl;
        TotalHargaBeef += HargaBeef[i] * JmlPesananBeef[i];
    }
    // Cetak pesanan chicken
    for (int j = 0; j < TotalChicken && !PesananChicken[j].empty(); j++) {
        cout << PesananChicken[j] << " x " << JmlPesananChicken[j] << endl;
        cout << "      " << HargaChicken[j] << " x " << JmlPesananChicken[j] << endl;
        TotalHargaChicken += HargaChicken[j] * JmlPesananChicken[j];
    }
    // Cetak pesanan fish
    for (int k = 0; k < TotalFish && !PesananFish[k].empty(); k++) {
        cout << PesananFish[k] << " x " << JmlPesananFish[k] << endl;
        cout << "      " << HargaFish[k] << " x " << JmlPesananFish[k] << endl;
        TotalHargaFish += HargaFish[k] * JmlPesananFish[k];
    }
    // Cetak pesanan drinks
    for (int l = 0; l < TotalDrinks && !PesananDrinks[l].empty(); l++) {
        cout << PesananDrinks[l] << " x " << JmlPesananDrinks[l] << endl;
        cout << "      " << HargaDrinks[l] << " x " << JmlPesananDrinks[l] << endl;
        TotalHargaDrinks += HargaDrinks[l] * JmlPesananDrinks[l];
    }
    // Hitung total harga keseluruhan
    cout << endl;
    TotalHarga = TotalHargaBeef + TotalHargaChicken + TotalHargaFish + TotalHargaDrinks;
    cout << "Total Harga = " << TotalHarga << endl;
    cout << "-----------------------------------------------------------" << endl;
}
//end dhimas

//farrel#1
void Harga_Setelah_Diskon() {
    HargaDiskon = TotalHarga * 0.15;
    cout << "Diskon = " << TotalHarga << " x 15%" << endl;
    cout << "       = " << HargaDiskon << endl;
    TotalHarga = TotalHarga - HargaDiskon;
    cout << "Total Harga = " << TotalHarga << endl;
}
//end farrel#1

int main() {
    int i = 0; //sebagai indeks untuk array PesananBeef[]
    int j = 0; //sebagai indeks untuk array PesananChicken[]
    int k = 0; //sebagai indeks untuk array PesananFish[]
    int l = 0; //sebagai indeks untuk array PesananDrinks[]

    //naufal
    MenuUtama:
    cout << "===========================================================" << endl;
    cout << "=======================JAVASTEAK APP=======================" << endl;
    cout << "===============PESAN STEAK SEMUDAH SATU KLIK===============" << endl;
    cout << "| 1. Lihat Menu Makanan                                   |" << endl;
    cout << "| 2. Transaksi                                            |" << endl;
    cout << "| 3. Keluar                                               |" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Pilihanmu [1-3] = ";
    cin >> CekMenuAwal;
    cout << endl;

    switch(CekMenuAwal) {
        case 1:
            MenuVarianOlahan:
            cout << "------------------------------------" << endl;
            cout << "|          VARIAN OLAHAN           |" << endl;
            cout << "|                                  |" << endl;
            cout << "| 1. Beef                          |" << endl;
            cout << "| 2. Chicken                       |" << endl;
            cout << "| 3. Fish                          |" << endl;
            cout << "| 4. Drinks                        |" << endl;
            cout << "| 5. Kembali ke Menu Utama         |" << endl;
            cout << "------------------------------------" << endl;
            cout << "Mau makan apa? [1-5] = ";
            cin >> CekOlahan;
            cout << endl;
            switch (CekOlahan){
                case 1:
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "|                               BEEF MENU                               |" << endl;
                    cout << "|                                                                       |" << endl;
                    cout << "| 1. Sirloin Lokal                                     = Rp. 70.000     |" << endl;
                    cout << "|    Daging sapi lokal has luar yang mengandung lemak                   |" << endl;
                    cout << "| 2. Sirloin Aussie                                    = Rp. 85.000     |" << endl;
                    cout << "|    Daging sapi impor has luar yang mengandung lemak                   |" << endl;
                    cout << "| 3. Rib Eye Aussie                                    = Rp. 88.000     |" << endl;
                    cout << "|    Daging sapi yang berasal dari tulang iga dan mengandung urat       |" << endl;
                    cout << "| 4. Secondary Cut Wagyu                               = Rp. 97.000     |" << endl;
                    cout << "|    Daging sapi jepang (black angus) berkualitas dan bertekstur lembut |" << endl;
                    cout << "| 5. Kembali ke Menu Varian Olahan                                      |" << endl;
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "Pilihanmu [1-5] = ";
                    cin >> PilihBeef;
                    if (PilihBeef == 1){
                        PesananBeef[i] = "Sirloin Lokal";
                        HargaBeef[i] = 70000;
                        cout << "Anda memilih Sirloin Lokal" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananBeef[i];
                        cout << endl;
                        i++;
                    } else if (PilihBeef == 2){
                        PesananBeef[i] = "Sirloin Aussie";
                        HargaBeef[i] = 85000;
                        cout << "Anda memilih Sirloin Aussie" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananBeef[i];
                        cout << endl;
                        i++;
                    } else if (PilihBeef == 3){
                        PesananBeef[i] = "Rib Eye Aussie";
                        HargaBeef[i] = 88000;
                        cout << "Anda memilih Rib Eye Aussie" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananBeef[i];
                        cout << endl;
                        i++;
                    } else if (PilihBeef == 4){
                        PesananBeef[i] = "Secondary Cut Wagyu";
                        HargaBeef[i] = 97000;
                        cout << "Anda memilih Secondary Cut Wagyu" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananBeef[i];
                        cout << endl;
                        i++;
                    } else if (PilihBeef == 5){
                        goto MenuVarianOlahan;
                    } else {
                        cout << "Pilihan anda tidak tersedia" << endl;
                        cout << endl;
                    }
                    goto MenuVarianOlahan;
                    break;
                case 2:
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "|                              CHICKEN MENU                             |" << endl;
                    cout << "|                                                                       |" << endl;
                    cout << "| 1. Chicken Burger                                    = Rp. 20.000     |" << endl;
                    cout << "|    Burger ayam lengkap dengan french fries                            |" << endl;
                    cout << "| 2. Chicken Steak                                     = Rp. 40.000     |" << endl;
                    cout << "|    Potongan dada ayam bermutu tanpa tepung                            |" << endl;
                    cout << "| 3. Chicken Schnitzel                                 = Rp. 45.000     |" << endl;
                    cout << "|    Potongan dada ayam bermutu dilapisi tepung panir                   |" << endl;
                    cout << "| 4. Chicken Gordon Blue                               = Rp. 50.000     |" << endl;
                    cout << "|    Daging ayam berisikan daging sapi dan keju                         |" << endl;
                    cout << "| 5. Kembali ke Menu Varian Olahan                                      |" << endl;
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "Pilihanmu [1-5] = ";
                    cin >> PilihChicken;
                    if (PilihChicken == 1){
                        PesananChicken[j] = "Chicken Burger";
                        HargaChicken[j] = 20000;
                        cout << "Anda memilih Chicken Burger" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananChicken[j];
                        cout << endl;
                        j++;
                    } else if (PilihChicken == 2){
                        PesananChicken[j] = "Chicken Steak";
                        HargaChicken[j] = 40000;
                        cout << "Anda memilih Chicken Steak" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananChicken[j];
                        cout << endl;
                        j++;
                    } else if (PilihChicken == 3){
                        PesananChicken[j] = "Chicken Schnitzel";
                        HargaChicken[j] = 45000;
                        cout << "Anda memilih Chicken Schnitzel" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananChicken[j];
                        cout << endl;
                        j++;
                    } else if (PilihChicken == 4){
                        PesananChicken[j] = "Chicken Gordon Blue";
                        HargaChicken[j] = 50000;
                        cout << "Anda memilih Chicken Gordon Blue" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananChicken[j];
                        cout << endl;
                        j++;
                    } else if (PilihChicken == 5){
                        goto MenuVarianOlahan;
                    } else {
                        cout << "Pilihan anda tidak tersedia" << endl;
                        cout << endl;
                    }
                    goto MenuVarianOlahan;
                    break;
                case 3:
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "|                               FISH MENU                               |" << endl;
                    cout << "|                                                                       |" << endl;
                    cout << "| 1. Fish and Chips (dory)                             = Rp. 47.000     |" << endl;
                    cout << "|    Filet ikan dory yang digoreng tepung                               |" << endl;
                    cout << "| 2. Marlin Steak                                      = Rp. 50.000     |" << endl;
                    cout << "|    Filet ikan marlin kaya akan omega 3 dan DHA                        |" << endl;
                    cout << "| 3. Salmon Steak                                      = Rp. 85.000     |" << endl;
                    cout << "|    Filet ikan salmon berbumbu yang dipanggang                         |" << endl;
                    cout << "| 4. Kembali ke Menu Varian Olahan                                      |" << endl;
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "Pilihanmu [1-4] = ";
                    cin >> PilihFish;
                    if (PilihFish == 1){
                        PesananFish[k] = "Fish and Chips";
                        HargaFish[k] = 47000;
                        cout << "Anda memilih Fish and Chips" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananFish[k];
                        cout << endl;
                        k++;
                    } else if (PilihFish == 2){
                        PesananFish[k] = "Marlin Steak";
                        HargaFish[k] = 50000;
                        cout << "Anda memilih Marlin Steak" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananFish[k];
                        cout << endl;
                        k++;
                    } else if (PilihFish == 3){
                        PesananFish[k] = "Salmon Steak";
                        HargaFish[k] = 85000;
                        cout << "Anda memilih Salmon Steak" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananFish[k];
                        cout << endl;
                        k++;
                    } else if (PilihFish == 4){
                        goto MenuVarianOlahan;
                    } else {
                        cout << "Pilihan anda tidak tersedia" << endl;
                        cout << endl;
                    }
                    goto MenuVarianOlahan;
                    break;
                case 4:
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "|                              DRINKS MENU                              |" << endl;
                    cout << "|                                                                       |" << endl;
                    cout << "| 1. Hot Tea                                           = Rp. 3.000      |" << endl;
                    cout << "| 2. Iced Tea                                          = Rp. 5.000      |" << endl;
                    cout << "| 3. Chocolate Milkshake                               = Rp. 10.000     |" << endl;
                    cout << "| 4. Iced Cola                                         = Rp. 10.000     |" << endl;
                    cout << "| 5. Coffee Mocchachino                                = Rp. 15.000     |" << endl;
                    cout << "| 6. Coffee Vanilla Latte                              = Rp. 15.000     |" << endl;
                    cout << "| 7. Kembali ke Menu Varian Olahan                                      |" << endl;
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "Pilihanmu [1-7] = ";
                    cin >> PilihDrinks;
                    if (PilihDrinks == 1){
                        PesananDrinks[l] = "Hot Tea";
                        HargaDrinks[l] = 3000;
                        cout << "Anda memilih Hot Tea" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananDrinks[l];
                        cout << endl;
                        l++;
                    } else if (PilihDrinks == 2){
                        PesananDrinks[l] = "Iced Tea";
                        HargaDrinks[l] = 5000;
                        cout << "Anda memilih Iced Tea" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananDrinks[l];
                        cout << endl;
                        l++;
                    } else if (PilihDrinks == 3){
                        PesananDrinks[l] = "Chocolate Milkshake";
                        HargaDrinks[l] = 10000;
                        cout << "Anda memilih Chocolate Milkshake" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananDrinks[l];
                        cout << endl;
                        l++;
                    } else if (PilihDrinks == 4){
                        PesananDrinks[l] = "Iced Cola";
                        HargaDrinks[l] = 10000;
                        cout << "Anda memilih Iced Cola" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananDrinks[l];
                        cout << endl;
                        l++;
                    } else if (PilihDrinks == 5){
                        PesananDrinks[l] = "Coffee Mocchachino";
                        HargaDrinks[l] = 15000;
                        cout << "Anda memilih Coffee Mocchachino" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananDrinks[l];
                        cout << endl;
                        l++;
                    } else if (PilihDrinks == 6){
                        PesananDrinks[l] = "Chocolate Vanilla Latte";
                        HargaDrinks[l] = 15000;
                        cout << "Anda memilih Chocolate Vanilla Latte" << endl;
                        cout << "Jumlah pesanan = ";
                        cin >> JmlPesananDrinks[l];
                        cout << endl;
                        l++;
                    } else if (PilihDrinks == 7){
                        goto MenuVarianOlahan;
                    } else {
                        cout << "Pilihan anda tidak tersedia" << endl;
                        cout << endl;
                    }
                    goto MenuVarianOlahan;
                    break;
                case 5:
                    goto MenuUtama;
            default:
                cout << "Pilih kategori makanan yang tersedia" << endl;
                goto MenuVarianOlahan;
                break;
            }
            //end naufal

        //farrel#2
        case 2:
            if (PesananBeef[0].empty() && PesananChicken[0].empty() && PesananFish[0].empty() && PesananDrinks[0].empty()) {
                cout << "Anda belum memilih pesanan" << endl;
                cout << endl;
                goto MenuUtama;
            } else {
                cout << "Sebelum mulai transaksi, yuk masukin data diri kamu!" << endl;
                cout << "Nama = "; cin.ignore(); getline(cin, datadiri[0]);
                cout << "Tanggal Lahir (dd/mm/yyyy) = "; getline(cin, datadiri[1]);
                cout << "Nomor Telepon = "; getline(cin, datadiri[2]);
                cout << "Email = "; getline(cin, datadiri[3]);
                cout << "Alamat = "; getline(cin, datadiri[4]);
                cout << "Sip, data diri kamu sudah tersimpan!" << endl;
                cout << endl;
                Kwitansi();
                cout << "Apakah anda memiliki kode voucher? [y/n] = ";
                cin >> CekVoucher;
                if (CekVoucher == "y" || CekVoucher == "Y") {
                    cout << "Masukkan kode voucher = ";
                    cin >> InputVoucher;
                    if (InputVoucher == "ifd03alpro") {
                        cout << "Anda Mendapatkan Diskon 15%!" << endl;
                        Harga_Setelah_Diskon();
                        cout << "-----------------------------------------------------------" << endl;
                        cout << "Silahkan bayar Rp." << TotalHarga << " saat kurir sampai di lokasi anda" << endl;
                        cout << "Terima kasih telah membeli makanan di JAVASTEAK APP" << endl;
                        cout << "--------------------SELAMAT MENIKMATI!---------------------" << endl;
                    } else {
                        cout << "Voucher yang anda masukkan salah" << endl;
                        cout << "-----------------------------------------------------------" << endl;
                        cout << "Silahkan bayar Rp." << TotalHarga << " saat kurir sampai di lokasi anda" << endl;
                        cout << "Terima kasih telah membeli makanan di JAVASTEAK APP" << endl;
                        cout << "--------------------SELAMAT MENIKMATI!---------------------" << endl;
                    }
                } else if (CekVoucher == "n" || CekVoucher == "N") {
                    cout << "-----------------------------------------------------------" << endl;
                    cout << "Silahkan bayar Rp." << TotalHarga << " saat kurir sampai di lokasi anda" << endl;
                    cout << "Terima kasih telah membeli makanan di JAVASTEAK APP" << endl;
                    cout << "--------------------SELAMAT MENIKMATI!---------------------" << endl;
                }
            }
            break;
            //end farrel#2
            //naufal#2
        case 3:
            cout << "Anda keluar dari program" << endl;
            break;
        default:
            cout << "Pilih menu yang tersedia" << endl;
            goto MenuUtama;
            break;
        //end naufal#2
    }

    return 0;
}
