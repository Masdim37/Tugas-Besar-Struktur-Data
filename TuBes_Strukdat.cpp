#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int TableSize = 100;

class HashNode
{
public:
    string Kategori;
    string Nama;
    double Harga;
    int Stok;

    HashNode(string KategoriProduk, string NamaProduk, double HargaProduk, int StokProduk)
    {
        this->Kategori = KategoriProduk;
        this->Nama = NamaProduk;
        this->Harga = HargaProduk;
        this->Stok = StokProduk;
    }
};

class HashMap
{
private:
    vector<HashNode *> TableHash[TableSize];

public:
    int HashFunc(string key)
    {
        int HashValue = 0;
        for (char c : key)
        {
            HashValue += c;
        }
        return HashValue % TableSize;
    }

    bool isEmpty()
    {
        for (int i = 0; i < TableSize; i++)
        {
            if (!TableHash[i].empty())
            {
                return false;
            }
        }
        return true;
    }

    void TambahProduk(string KategoriProduk, string NamaProduk, double HargaProduk, int StokProduk)
    {
        int HashValue = HashFunc(NamaProduk);

        for (auto node : TableHash[HashValue])
        {
            if (node->Nama == NamaProduk)
            {
                node->Kategori = KategoriProduk;
                node->Harga = HargaProduk;
                node->Stok = StokProduk;
                return;
            }
        }
        TableHash[HashValue].push_back(new HashNode(KategoriProduk, NamaProduk, HargaProduk, StokProduk));
    }

    bool CekNamaProduk(string NamaProduk)
    {
        int HashValue = HashFunc(NamaProduk);
        bool ketemu = false;

        for (auto node : TableHash[HashValue])
        {
            if (node->Nama == NamaProduk)
            {
                ketemu = true;
                break;
            }
        }
        if (!ketemu)
        {
            cout << "Produk " << NamaProduk << " tidak ditemukan!" << endl;
            cout << endl;
        }

        return ketemu;
    }

    void UpdateProduk(string KategoriProduk, string NamaProduk, double HargaProduk, int StokProduk)
    {
        int HashValue = HashFunc(NamaProduk);
        bool ketemu = false;

        for (auto node : TableHash[HashValue])
        {
            if (node->Nama == NamaProduk)
            {
                node->Kategori = KategoriProduk;
                node->Harga = HargaProduk;
                node->Stok = StokProduk;
                ketemu = true;
                return;
            }
        }
        if (!ketemu)
        {
            cout << "Produk " << NamaProduk << " tidak ditemukan" << endl;
        }
    }

    double TambahHargaProduk(string NamaProduk)
    {
        double Harga;
        int HashValue = HashFunc(NamaProduk);

        for (auto node : TableHash[HashValue])
        {
            if (node->Nama == NamaProduk)
            {
                Harga = node->Harga;
            }
        }

        return Harga;
    }

    void HapusProduk(string NamaProduk)
    {
        int HashValue = HashFunc(NamaProduk);

        for (auto node = TableHash[HashValue].begin(); node != TableHash[HashValue].end(); node++)
        {
            if ((*node)->Nama == NamaProduk)
            {
                TableHash[HashValue].erase(node);
                return;
            }
            else
            {
                cout << "Produk " << NamaProduk << " tidak ditemukan" << endl;
                cout << endl;
            }
        }
    }

    void SearchByPrice(double HargaMin, double HargaMax)
    {
        bool ketemu = false;
        int nomor = 1;

        cout << " --- RENTANG HARGA " << HargaMin << " - " << HargaMax << " ---" << endl;
        for (int i = 0; i < TableSize; i++)
        {
            for (auto node : TableHash[i])
            {
                if (node->Harga >= HargaMin && node->Harga <= HargaMax)
                {
                    cout << nomor << ". " << "(" << node->Kategori << ") " << node->Nama << right << setw(10) << "Rp." << node->Harga << endl;
                    nomor++;
                    ketemu = true;
                }
            }
        }
        cout << endl;
        if (!ketemu)
        {
            cout << "Produk dengan rentang harga " << HargaMin << " - " << HargaMax << " tidak ditemukan" << endl;
            cout << endl;
        }
    }

    void SearchByProductName(string NamaProduk)
    {
        bool ketemu = false;
        int nomor = 1;

        cout << "--- PENCARIAN NAMA PRODUK ---" << endl;
        for (int i = 0; i < TableSize; i++)
        {
            for (auto node : TableHash[i])
            {
                if (node->Nama == NamaProduk)
                {
                    cout << nomor << ". " << node->Nama << " (" << node->Kategori << ")" << '\t' << '\t' << "Rp." << node->Harga << endl;
                    nomor++;
                    ketemu = true;
                }
            }
        }
        cout << endl;
        if (!ketemu)
        {
            cout << "Produk dengan nama " << NamaProduk << " tidak ditemukan" << endl;
            cout << endl;
        }
    }

    void TampilProdukAdmin()
    {
        cout << "-----------------------------------------------------------------" << endl;
        cout << "|" << left << setw(15) << "Kategori" << "|" << left << setw(20) << "Nama" << "|" << left << setw(15) << "Harga" << "|" << left << setw(10) << "Stok" << "|" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        for (int i = 0; i < TableSize; i++)
        {
            for (auto node : TableHash[i])
            {
                cout << "|" << left << setw(15) << node->Kategori << "|" << left << setw(20) << node->Nama << "|" << "Rp. " << left << setw(11) << node->Harga << "|" << left << setw(10) << node->Stok << "|" << endl;
            }
        }
        cout << "-----------------------------------------------------------------" << endl;
        cout << endl;
    }

    void TampilProdukCustomer()
    {
        cout << "------------------------------------------------------" << endl;
        cout << "|" << left << setw(15) << "Kategori" << "|" << left << setw(20) << "Nama" << "|" << left << setw(15) << "Harga" << "|" << endl;
        cout << "------------------------------------------------------" << endl;
        for (int i = 0; i < TableSize; i++)
        {
            for (auto node : TableHash[i])
            {
                cout << "|" << left << setw(15) << node->Kategori << "|" << left << setw(20) << node->Nama << "|" << "Rp. " << left << setw(11) << node->Harga << "|" << endl;
            }
        }
        cout << "------------------------------------------------------" << endl;
        cout << endl;
    }

    // Metode untuk mendapatkan informasi produk berdasarkan nama
    HashNode *GetProdukByName(string NamaProduk)
    {
        int HashValue = HashFunc(NamaProduk);
        for (auto node : TableHash[HashValue])
        {
            if (node->Nama == NamaProduk)
            {
                return node;
            }
        }
        return nullptr; // Mengembalikan nullptr jika produk tidak ditemukan
    }
};

bool LoginUserAdmin(string UsernameAdmin, string PasswordAdmin, bool &PasswordAdminValid, bool &UsernameAdminValid)
{
    UsernameAdminValid = true;
    PasswordAdminValid = true;
    if (UsernameAdmin == "AdminToko1")
    {
        if (PasswordAdmin == "AdminPakaian1")
        {
            cout << "Anda login sebagai AdminToko1" << endl;
            cout << endl;
        }
        else
        {
            cout << "Username atau password yang anda masukkan salah!" << endl;
            cout << "Silahkan login kembali" << endl;
            cout << endl;
            PasswordAdminValid = false;
        }
    }
    else if (UsernameAdmin == "AdminToko2")
    {
        if (PasswordAdmin == "AdminPakaian2")
        {
            cout << "Anda login sebagai AdminToko2" << endl;
            cout << endl;
        }
        else
        {
            cout << "Username atau password yang anda masukkan salah!" << endl;
            cout << "Silahkan login kembali" << endl;
            cout << endl;
            PasswordAdminValid = false;
        }
    }
    else
    {
        cout << "Username tidak terdaftar!" << endl;
        cout << endl;
        UsernameAdminValid = false;
    }
    return UsernameAdminValid && PasswordAdminValid;
}

bool LoginUserCustomer(string UsernameCustomer, string PasswordCustomer, bool &PasswordCustomerValid, bool &UsernameCustomerValid)
{
    UsernameCustomerValid = true;
    PasswordCustomerValid = true;
    if (UsernameCustomer == "Joshua")
    {
        if (PasswordCustomer == "2311102133")
        {
            cout << "Selamat datang Joshua!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Username atau password yang anda masukkan salah!" << endl;
            cout << "Silahkan login kembali" << endl;
            cout << endl;
            PasswordCustomerValid = false;
        }
    }
    else if (UsernameCustomer == "Nanda")
    {
        if (PasswordCustomer == "2311102147")
        {
            cout << "Selamat datang Nanda!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Username atau password yang anda masukkan salah!" << endl;
            cout << "Silahkan login kembali" << endl;
            cout << endl;
            PasswordCustomerValid = false;
        }
    }
    else if (UsernameCustomer == "Dhimas")
    {
        if (PasswordCustomer == "2311102151")
        {
            cout << "Selamat datang Dhimas!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Username atau password yang anda masukkan salah!" << endl;
            cout << "Silahkan login kembali" << endl;
            cout << endl;
            PasswordCustomerValid = false;
        }
    }
    else
    {
        cout << "Username anda tidak terdaftar" << endl;
        cout << endl;
        UsernameCustomerValid = false;
    }
    return UsernameCustomerValid && PasswordCustomerValid;
}

double HargaDiskon(double TotalHarga) {
    double HargaDiskon;
    HargaDiskon = TotalHarga * 0.15;
    
    return HargaDiskon;
}


int main()
{
    HashMap Produk;
    int pilih;
    bool PasswordAdminValid = true;
    bool UsernameAdminValid = true;
    bool PasswordCustomerValid = true;
    bool UsernameCustomerValid = true;

    do
    {
    MenuLogin:
        cout << "================================================" << endl;
        cout << "|                 LOGIN                        |" << endl;
        cout << "================================================" << endl;
        cout << "| 1. Admin                                     |" << endl;
        cout << "| 2. Customer                                  |" << endl;
        cout << "| 3. Keluar                                    |" << endl;
        cout << "================================================" << endl;
        cout << "Pilih = ";
        cin >> pilih;
        cout << endl;

        switch (pilih)
        {
        case 1:
            do
            {
                string UsernameAdmin;
                string PasswordAdmin;
                cout << "Username = ";
                cin >> UsernameAdmin;
                cout << "Password = ";
                cin >> PasswordAdmin;

                if (LoginUserAdmin(UsernameAdmin, PasswordAdmin, PasswordAdminValid, UsernameAdminValid))
                {
                    int pilihAdmin;
                    do
                    {
                        cout << "================================================" << endl;
                        cout << "|                 ADMIN MENU                   |" << endl;
                        cout << "================================================" << endl;
                        cout << "| 1. Tambah Produk                             |" << endl;
                        cout << "| 2. Update Produk                             |" << endl;
                        cout << "| 3. Hapus Produk                              |" << endl;
                        cout << "| 4. Tampilkan Semua Produk                    |" << endl;
                        cout << "| 5. Logout                                    |" << endl;
                        cout << "================================================" << endl;
                        cout << "Pilih = ";
                        cin >> pilihAdmin;
                        cout << endl;

                        switch (pilihAdmin)
                        {
                        case 1:
                        {
                            string kategori, nama;
                            double harga;
                            int stok;
                            char Yakin;
                            cout << "Kategori Produk = ";
                            cin >> kategori;
                            cout << "Nama Produk = ";
                            cin.ignore();
                            getline(cin, nama);
                            cout << "Harga Produk = ";
                            cin >> harga;
                            cout << "Stok Produk = ";
                            cin >> stok;
                            cout << "Apakah anda yakin ingin menambahkan produk " << nama << "? [y/n] = ";
                            cin >> Yakin;
                            if (Yakin == 'Y' || Yakin == 'y')
                            {
                                Produk.TambahProduk(kategori, nama, harga, stok);
                                cout << "Produk " << nama << " berhasil ditambahkan!" << endl;
                                cout << endl;
                            }
                            else if (Yakin == 'N' || Yakin == 'n')
                            {
                                cout << "Aksi dibatalkan!" << endl;
                                cout << endl;
                            }
                            break;
                        }
                        case 2:
                        {
                            if (Produk.isEmpty() == false)
                            {
                                string kategori, nama;
                                double harga;
                                int stok;
                                char Yakin;
                            UpdateProduk:
                                cout << "Nama Produk yang akan di-update = ";
                                cin.ignore();
                                getline(cin, nama);
                                cout << endl;
                                if (Produk.CekNamaProduk(nama))
                                {
                                    cout << "Silahkan masukkan data yang ingin diupdate!" << endl;
                                    cout << "Kategori Produk = ";
                                    cin >> kategori;
                                    cout << "Harga Produk = ";
                                    cin >> harga;
                                    cout << "Stok Produk = ";
                                    cin >> stok;
                                    cout << "Apakah data yang dimasukkan sudah benar? [y/n] = ";
                                    cin >> Yakin;
                                    if (Yakin == 'Y' || Yakin == 'y')
                                    {
                                        Produk.UpdateProduk(kategori, nama, harga, stok);
                                        cout << "Data produk " << nama << " berhasil diupdate!" << endl;
                                        cout << endl;
                                    }
                                    else if (Yakin == 'N' || Yakin == 'n')
                                    {
                                        cout << "Silahkan masukkan ulang data yang ingin diupdate!" << endl;
                                        cout << endl;
                                        goto UpdateProduk;
                                    }
                                }
                            }
                            else
                            {
                                cout << "List produk masih kosong!" << endl;
                                cout << "Tambahkan produk terlebih dahulu!" << endl;
                                cout << endl;
                            }
                            break;
                        }
                        case 3:
                        {
                            if (Produk.isEmpty() == false)
                            {
                                string nama;
                                char Yakin;
                                cout << "Nama Produk yang akan dihapus = ";
                                cin.ignore();
                                getline(cin, nama);
                                if (Produk.CekNamaProduk(nama) == true)
                                {
                                    cout << "Apakah anda yakin ingin menghapus produk " << nama << "? [y/n] = ";
                                    cin >> Yakin;
                                    if (Yakin == 'Y' || Yakin == 'y')
                                    {
                                        Produk.HapusProduk(nama);
                                        cout << "Produk " << nama << " berhasil dihapus!" << endl;
                                        cout << endl;
                                    }
                                    else if (Yakin == 'N' || Yakin == 'n')
                                    {
                                        cout << "Aksi dibatalkan!" << endl;
                                        cout << endl;
                                    }
                                }
                            }
                            else
                            {
                                cout << "List produk masih kosong!" << endl;
                                cout << "Tambahkan produk terlebih dahulu!" << endl;
                                cout << endl;
                            }
                            break;
                        }
                        case 4:
                            if (Produk.isEmpty() == false)
                            {
                                Produk.TampilProdukAdmin();
                            }
                            else
                            {
                                cout << "List produk masih kosong!" << endl;
                                cout << "Tambahkan produk terlebih dahulu!" << endl;
                                cout << endl;
                            }
                            break;
                        case 5:
                            cout << "Logout berhasil." << endl;
                            cout << endl;
                            goto MenuLogin;
                            break;
                        default:
                            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                            cout << endl;
                        }
                    } while (pilihAdmin != 5);
                }
            } while (!PasswordAdminValid || !UsernameAdminValid);
            break;
        case 2:
            do
            {
                string UsernameCustomer;
                string PasswordCustomer;
                cout << "Username = ";
                cin >> UsernameCustomer;
                cout << "Password = ";
                cin >> PasswordCustomer;

                if (LoginUserCustomer(UsernameCustomer, PasswordCustomer, PasswordCustomerValid, UsernameCustomerValid))
                {
                    int pilihCustomer;
                    do
                    {
                        cout << "================================================" << endl;
                        cout << "|                CUSTOMER MENU                 |" << endl;
                        cout << "================================================" << endl;
                        cout << "| 1. Lihat Semua Produk                        |" << endl;
                        cout << "| 2. Cari Produk Berdasarkan Harga             |" << endl;
                        cout << "| 3. Cari Produk Berdasarkan Nama              |" << endl;
                        cout << "| 4. Beli Produk                               |" << endl;
                        cout << "| 5. Logout                                    |" << endl;
                        cout << "================================================" << endl;
                        cout << "Pilih = ";
                        cin >> pilihCustomer;
                        cout << endl;

                        switch (pilihCustomer)
                        {
                        case 1:
                            Produk.TampilProdukCustomer();
                            break;
                        case 2:
                        {
                            double hargaMin, hargaMax;
                            cout << "Masukkan harga minimum = ";
                            cin >> hargaMin;
                            cout << "Masukkan harga maksimum = ";
                            cin >> hargaMax;
                            cout << endl;
                            Produk.SearchByPrice(hargaMin, hargaMax);
                            break;
                        }
                        case 3:
                        {
                            string nama;
                            cout << "Masukkan nama produk = ";
                            cin.ignore();
                            getline(cin, nama);
                            cout << endl;
                            if (Produk.CekNamaProduk(nama) == true)
                            {
                                Produk.SearchByProductName(nama);
                            }
                            break;
                        }
                        case 4:
                        {
                            string nama, KodeVoucher;
                            int i = 0;
                            int jumlah;
                            char Yakin, YakinVoucher;
                            string NamaProdukBeli[100];
                            int HargaProdukBeli[100];
                            int TotalHarga;
                            int JumlahProdukBeli[100];
                            string DataPribadi[3];
                            HashNode *beliproduk;

                            cout << "Sebelum membeli barang, isi data pribadi anda terlebih dahulu!" << endl;
                            cout << "Nama = ";
                            cin.ignore();
                            getline(cin, DataPribadi[0]);
                            cout << "Nomor telepon = ";
                            cin >> DataPribadi[1];
                            cout << "Email = ";
                            cin >> DataPribadi[2];
                            cout << endl;

                            bool stop = false;
                            Produk.TampilProdukCustomer();
                            while(stop == false){
                                InputBelanjaan:
                                cout << "Masukkan nama produk yang ingin dibeli = ";
                                cin.ignore();
                                getline(cin, nama);
                                if (Produk.CekNamaProduk(nama) == true)
                                {
                                    cout << "Masukkan jumlah produk yang ingin dibeli = ";
                                    cin >> jumlah;
                                    beliproduk = Produk.GetProdukByName(nama);
                                    NamaProdukBeli[i] = beliproduk->Nama;
                                    HargaProdukBeli[i] = beliproduk->Harga * jumlah;
                                    JumlahProdukBeli[i] = jumlah;
                                    cout << "Apakah anda ingin membeli produk lain? [y/n] = ";
                                    cin >> Yakin;
                                    if (Yakin == 'Y' || Yakin == 'y')
                                    {
                                        i++;
                                    }
                                    else if (Yakin == 'N' || Yakin == 'n')
                                    {
                                        stop = true;
                                    }
                                    cout << endl;
                                } else {
                                    cout << "Silahkan masukkan kembali produk yang ingin dibeli" << endl;
                                    goto InputBelanjaan;
                                }
                            }

                            int JumlahProdukYangDibeli = sizeof(NamaProdukBeli) / sizeof(*NamaProdukBeli);
                            cout << "-----------------------------------------------" << endl;
                            cout << "|              RINCIAN PEMBELIAN              |" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "Pesanan anda =                                 " << endl;
                            for (int i = 0; i < JumlahProdukYangDibeli && !NamaProdukBeli[i].empty(); i++)
                            {
                                cout << "  " << NamaProdukBeli[i] << " x " << JumlahProdukBeli[i] << endl;
                                cout << "  " << '\t' << "Total = Rp. " << HargaProdukBeli[i] << endl;
                                TotalHarga += HargaProdukBeli[i];
                            }
                            cout << "-----------------------------------------------" << endl;
                            cout << "  TOTAL = " << TotalHarga << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "Apakah anda memiliki kode voucher? [y/n] = ";
                            cin >> YakinVoucher;
                            if(YakinVoucher == 'Y' || YakinVoucher == 'y'){
                                cout << "Masukkan kode voucher = ";
                                cin >> KodeVoucher;
                                if(KodeVoucher == "IF11D"){
                                    cout << "Selamat anda mendapat diskon 15%" << endl;
                                } else {
                                    cout << "Kode voucher salah, anda tidak mendapat diskon" << endl;
                                }
                            } else if(YakinVoucher == 'N' || YakinVoucher == 'n'){
                                cout << "Anda tidak mendapat diskon" << endl;
                            }
                            cout << endl;
                            
                            cout << "-----------------------------------------------" << endl;
                            cout << "|                   KWITANSI                  |" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "Nama = " << setw(13) << left << DataPribadi[0] << endl;
                            cout << "Nomor telepon = " << DataPribadi[1] << endl;
                            cout << "Email = " << setw(11) << left << DataPribadi[2] << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "Pesanan anda = " << endl;
                            for (int i = 0; i < JumlahProdukYangDibeli && !NamaProdukBeli[i].empty(); i++)
                            {
                                cout << "  " << NamaProdukBeli[i] << " x " << JumlahProdukBeli[i] << endl;
                                cout << "  " << '\t' << "Total = Rp. " << HargaProdukBeli[i] << endl;
                            }
                            cout << "-----------------------------------------------" << endl;
                            if(KodeVoucher == "IF11D"){
                                cout << "Anda mendapat diskon 15%" << endl;
                                cout << "TOTAL = Rp. " << TotalHarga - HargaDiskon(TotalHarga) << endl;
                                cout << "-----------------------------------------------" << endl;
                                cout << "         TERIMAKASIH TELAH BERBELANJA          " << endl;
                                cout << "-----------------------------------------------" << endl;
                            } else {
                                cout << "TOTAL = Rp. " << TotalHarga << endl;
                                cout << "-----------------------------------------------" << endl;
                                cout << "         TERIMAKASIH TELAH BERBELANJA          " << endl;
                                cout << "-----------------------------------------------" << endl;
                            }
                            return 0;
                            break;
                        }
                        case 5:
                            cout << "Logout berhasil." << endl;
                            cout << endl;
                            goto MenuLogin;
                            break;
                        default:
                            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                            cout << endl;
                        }
                    } while (pilihCustomer != 6);
                }
            } while (!PasswordCustomerValid || !UsernameCustomerValid);
            break;
        case 3:
            char Yakin;
            cout << "Apakah anda yakin ingin keluar dari aplikasi? [y/n] = ";
            cin >> Yakin;
            if (Yakin == 'Y' || Yakin == 'y')
            {
                cout << "Terima kasih! Sampai jumpa lagi." << endl;
            }
            else if (Yakin == 'N' || 'n')
            {
                cout << "Aksi dibatalkan" << endl;
                cout << endl;
                goto MenuLogin;
            }
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilih != 3);

    return 0;
}