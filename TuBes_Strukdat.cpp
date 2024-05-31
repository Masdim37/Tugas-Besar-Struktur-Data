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
            }
        }
    }

    void SearchByCategory(string KategoriProduk)
    {
        bool ketemu = false;
        int nomor = 1;

        cout << "--- KATEGORI " << KategoriProduk << " ---" << endl;
        for (int i = 0; i < TableSize; i++)
        {
            for (auto node : TableHash[i])
            {
                if (node->Kategori == KategoriProduk)
                {
                    cout << nomor << ". " << node->Nama << '\t' << "Rp." << node->Harga << endl;
                    nomor++;
                    ketemu = true;
                }
            }
        }
        if (!ketemu)
        {
            cout << "Produk dalam kategori " << KategoriProduk << " tidak tersedia" << endl;
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
                    cout << nomor << ". " << node->Nama << '\t' << "Rp." << node->Harga << " - " << node->Kategori << endl;
                    nomor++;
                    ketemu = true;
                }
            }
        }
        if (!ketemu)
        {
            cout << "Produk dengan rentang harga " << HargaMin << " - " << HargaMax << " tidak ditemukan" << endl;
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
                    cout << nomor << ". " << node->Nama << '\t' << "Rp." << node->Harga << " - " << node->Kategori << endl;
                    nomor++;
                    ketemu = true;
                }
            }
        }
        if (!ketemu)
        {
            cout << "Produk dengan nama " << NamaProduk << " tidak ditemukan" << endl;
        }
    }

    void TampilProdukAdmin()
    {
        cout << "--------------------------------------------------" << endl;
        cout << "|" << left << setw(15) << "Kategori" << "|" << left << setw(20) << "Nama" << "|" << left << setw(15) << "Harga" << "|" << left << setw(10) << "Stok" << "|" << endl;
        cout << "--------------------------------------------------" << endl;
        for (int i = 0; i < TableSize; i++)
        {
            for (auto node : TableHash[i])
            {
                cout << "|" << left << setw(15) << node->Kategori << "|" << left << setw(20) << node->Nama << "|" << left << setw(15) << "Rp. " + to_string(node->Harga) << "|" << left << setw(10) << node->Stok << "|" << endl;
            }
        }
        cout << "--------------------------------------------------" << endl;
    }

    void TampilProdukCustomer()
    {
        cout << "-----------------------------------------------" << endl;
        cout << "|" << left << setw(15) << "Kategori" << "|" << left << setw(20) << "Nama" << "|" << left << setw(15) << "Harga" << "|" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < TableSize; i++)
        {
            for (auto node : TableHash[i])
            {
                cout << "|" << left << setw(15) << node->Kategori << "|" << left << setw(20) << node->Nama << "|" << left << setw(15) << "Rp. " + to_string(node->Harga) << "|" << endl;
            }
        }
        cout << "-----------------------------------------------" << endl;
    }

    // Metode untuk mendapatkan informasi produk berdasarkan nama
    HashNode* GetProdukByName(string NamaProduk)
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
        }
        else
        {
            cout << "Password yang anda masukkan salah!" << endl;
            PasswordAdminValid = false;
        }
    }
    else if (UsernameAdmin == "AdminToko2")
    {
        if (PasswordAdmin == "AdminPakaian2")
        {
            cout << "Anda login sebagai AdminToko2" << endl;
        }
        else
        {
            cout << "Password yang anda masukkan salah!" << endl;
            PasswordAdminValid = false;
        }
    }
    else
    {
        cout << "Username tidak terdaftar!" << endl;
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
        }
        else
        {
            cout << "Password yang anda masukkan salah!" << endl;
            PasswordCustomerValid = false;
        }
    }
    else if (UsernameCustomer == "Nanda")
    {
        if (PasswordCustomer == "2311102147")
        {
            cout << "Selamat datang Nanda!" << endl;
        }
        else
        {
            cout << "Password yang anda masukkan salah!" << endl;
            PasswordCustomerValid = false;
        }
    }
    else if (UsernameCustomer == "Dhimas")
    {
        if (PasswordCustomer == "2311102151")
        {
            cout << "Selamat datang Dhimas!" << endl;
        }
        else
        {
            cout << "Password yang anda masukkan salah!" << endl;
            PasswordCustomerValid = false;
        }
    }
    else
    {
        cout << "Username anda tidak terdaftar" << endl;
        UsernameCustomerValid = false;
    }
    return UsernameCustomerValid && PasswordCustomerValid;
}

void CetakKwitansi(string NamaProduk, int jumlah, double Harga)
{
    double totalHarga = jumlah * Harga;
    cout << "-----------------------------------------------" << endl;
    cout << "|                   KWITANSI                  |" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "| Nama Produk  : " << setw(28) << left << NamaProduk << "|" << endl;
    cout << "| Jumlah       : " << setw(28) << left << jumlah << "|" << endl;
    cout << "| Harga Satuan : " << setw(28) << left << "Rp. " + to_string(Harga) << "|" << endl;
    cout << "|---------------------------------------------|" << endl;
    cout << "| Total Harga  : " << setw(28) << left << "Rp. " + to_string(totalHarga) << "|" << endl;
    cout << "-----------------------------------------------" << endl;
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
        cout << "================================================" << endl;
        cout << "|                 LOGIN                        |" << endl;
        cout << "================================================" << endl;
        cout << "| 1. Admin                                     |" << endl;
        cout << "| 2. Customer                                  |" << endl;
        cout << "| 3. Keluar                                    |" << endl;
        cout << "================================================" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            do
            {
                string UsernameAdmin;
                string PasswordAdmin;
                cout << "Username : ";
                cin >> UsernameAdmin;
                cout << "Password : ";
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
                        cout << "Pilih : ";
                        cin >> pilihAdmin;

                        switch (pilihAdmin)
                        {
                        case 1:
                        {
                            string kategori, nama;
                            double harga;
                            int stok;
                            cout << "Kategori Produk : ";
                            cin >> kategori;
                            cout << "Nama Produk : ";
                            cin >> nama;
                            cout << "Harga Produk : ";
                            cin >> harga;
                            cout << "Stok Produk : ";
                            cin >> stok;
                            Produk.TambahProduk(kategori, nama, harga, stok);
                            break;
                        }
                        case 2:
                        {
                            string kategori, nama;
                            double harga;
                            int stok;
                            cout << "Nama Produk yang akan di-update: ";
                            cin >> nama;
                            if (Produk.CekNamaProduk(nama))
                            {
                                cout << "Kategori Produk : ";
                                cin >> kategori;
                                cout << "Harga Produk : ";
                                cin >> harga;
                                cout << "Stok Produk : ";
                                cin >> stok;
                                Produk.UpdateProduk(kategori, nama, harga, stok);
                            }
                            break;
                        }
                        case 3:
                        {
                            string nama;
                            cout << "Nama Produk yang akan dihapus: ";
                            cin >> nama;
                            Produk.HapusProduk(nama);
                            break;
                        }
                        case 4:
                            Produk.TampilProdukAdmin();
                            break;
                        case 5:
                            cout << "Logout berhasil." << endl;
                            break;
                        default:
                            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
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
                cout << "Username : ";
                cin >> UsernameCustomer;
                cout << "Password : ";
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
                        cout << "| 2. Cari Produk Berdasarkan Kategori          |" << endl;
                        cout << "| 3. Cari Produk Berdasarkan Harga             |" << endl;
                        cout << "| 4. Cari Produk Berdasarkan Nama              |" << endl;
                        cout << "| 5. Beli Produk                               |" << endl;
                        cout << "| 6. Logout                                    |" << endl;
                        cout << "================================================" << endl;
                        cout << "Pilih : ";
                        cin >> pilihCustomer;

                        switch (pilihCustomer)
                        {
                        case 1:
                            Produk.TampilProdukCustomer();
                            break;
                        case 2:
                        {
                            string kategori;
                            cout << "Masukkan kategori: ";
                            cin >> kategori;
                            Produk.SearchByCategory(kategori);
                            break;
                        }
                        case 3:
                        {
                            double hargaMin, hargaMax;
                            cout << "Masukkan harga minimum: ";
                            cin >> hargaMin;
                            cout << "Masukkan harga maksimum: ";
                            cin >> hargaMax;
                            Produk.SearchByPrice(hargaMin, hargaMax);
                            break;
                        }
                        case 4:
                        {
                            string nama;
                            cout << "Masukkan nama produk: ";
                            cin >> nama;
                            Produk.SearchByProductName(nama);
                            break;
                        }
                        case 5:
                        {
                            string nama;
                            int jumlah;
                            cout << "Masukkan nama produk yang ingin dibeli: ";
                            cin >> nama;
                            if (Produk.CekNamaProduk(nama))
                            {
                                double harga;
                                cout << "Masukkan jumlah produk yang ingin dibeli: ";
                                cin >> jumlah;

                                HashNode* produk = Produk.GetProdukByName(nama);
                                if (produk != nullptr)
                                {
                                    harga = produk->Harga;
                                    CetakKwitansi(nama, jumlah, harga);
                                }
                                else
                                {
                                    cout << "Produk tidak ditemukan!" << endl;
                                }
                            }
                            break;
                        }
                        case 6:
                            cout << "Logout berhasil." << endl;
                            break;
                        default:
                            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                        }
                    } while (pilihCustomer != 6);
                }
            } while (!PasswordCustomerValid || !UsernameCustomerValid);
            break;
        case 3:
            cout << "Terima kasih! Sampai jumpa lagi." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilih != 3);

    return 0;
}