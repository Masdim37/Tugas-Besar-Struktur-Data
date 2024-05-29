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
        cout << "|" << left << setw(10) << "Kategori" << "|" << left << setw(10) << "Nama" << "|" << left << setw(10) << "Harga" << "|" << left << setw(10) << "Stok" << "|" << endl;
        cout << "--------------------------------------------------" << endl;
        for(int i = 0; i < TableSize; i++){
            for(auto node : TableHash[i]){
               cout << "|" << left << setw(10) << node->Kategori << "|" << left << setw(10) << node->Nama << "|" << left << setw(10) << node->Harga << "|" << left << setw(10) << node->Stok << "|" << endl; 
            }
        }
        cout << "--------------------------------------------------" << endl;
    }

    void TampilProdukCustomer()
    {
        cout << "----------------------------------------" << endl;
        cout << "|" << left << setw(10) << "Kategori" << "|" << left << setw(10) << "Nama" << "|" << left << setw(10) << "Harga" << "|" << endl;
        cout << "----------------------------------------" << endl;
        for(int i = 0; i < TableSize; i++){
            for(auto node : TableHash[i]){
               cout << "|" << left << setw(10) << node->Kategori << "|" << left << setw(10) << node->Nama << "|" << left << setw(10) << node->Harga << "|" << endl; 
            }
        }
        cout << "----------------------------------------" << endl;
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

int main()
{
    int PilihanLogin, i, PilihanMenuAdmin;
    string UsernameAdmin, PasswordAdmin;
    string UsernameCustomer, PasswordCustomer;
    bool UsernameAdminValid = true;
    bool PasswordAdminValid = true;
    bool UsernameCustomerValid = true;
    bool PasswordCustomerValid = true;
    string NamaProduk, KategoriProduk;
    double HargaProduk;
    int StokProduk;
    char Yakin;
    HashMap HashtableProduk;

    MenuLogin:
    cout << "----- TOKO PAKAIAN [.....] -----" << endl;
    cout << "Menjual ..., ..., ..., ..." << endl;
    cout << endl;
    cout << "Login sebagai : " << endl;
    cout << "1. Customer" << endl;
    cout << "2. Admin" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilihan anda [1 - 3] = ";
    cin >> PilihanLogin;
    cout << endl;

    if (PilihanLogin == 2)
    {
    MasukkanUsernameAdmin:
        cout << "Masukkan username = ";
        cin >> UsernameAdmin;
    MasukkanPasswordAdmin:
        cout << "Masukkan password = ";
        cin >> PasswordAdmin;
        LoginUserAdmin(UsernameAdmin, PasswordAdmin, PasswordAdminValid, UsernameAdminValid);

        if (!PasswordAdminValid)
        {
            for (i = 2; i >= 0; i--)
            {
                cout << "Tersisa " << i << " kesempatan untuk login kembali" << endl;
                cout << endl;
                goto MasukkanPasswordAdmin;
            }
            if (i == 0)
            {
                cout << "Anda telah gagal 3 kali untuk login sebagai admin" << endl;
                cout << "Silahkan buka ulang aplikasi" << endl;
                return 0;
            }
        }
        else if (!UsernameAdminValid)
        {
            goto MasukkanUsernameAdmin;
        }

        cout << endl;
        if (UsernameAdminValid && PasswordAdminValid)
        {
            do
            {
                cout << "--- ADMIN MENU ---" << endl;
                cout << "1. Tambah Produk" << endl;
                cout << "2. Update Produk" << endl;
                cout << "3. Hapus Produk" << endl;
                cout << "4. Tampilkan Produk dan Stoknya" << endl;
                cout << "5. Kembali ke menu login" << endl;
                cout << "Masukkan pilihan [1 - 5] = ";
                cin >> PilihanMenuAdmin;
                cout << endl;

                switch (PilihanMenuAdmin)
                {
                case 1:
                    cout << "--- TAMBAH PRODUK ---" << endl;
                    cout << "Masukkan kategori produk yang ingin ditambahkan = ";
                    cin.ignore();
                    cin >> KategoriProduk;
                    cout << "Masukkan nama produk yang ingin ditambahkan = ";
                    cin.ignore();
                    getline(cin, NamaProduk);
                    cout << "Masukkan harga produk = ";
                    cin >> HargaProduk;
                    cout << "Masukkan stok produk = ";
                    cin >> StokProduk;
                    HashtableProduk.TambahProduk(KategoriProduk, NamaProduk, HargaProduk, StokProduk);
                    cout << "Produk " << NamaProduk << " berhasil ditambahkan!" << endl;
                    cout << endl;
                    break;
                case 2:
                    if (HashtableProduk.isEmpty() == false)
                    {
                        cout << "--- UPDATE PRODUK ---" << endl;
                        cout << "Masukkan nama produk yang ingin diupdate = ";
                        cin.ignore();
                        getline(cin, NamaProduk);
                        if(HashtableProduk.CekNamaProduk(NamaProduk) == true){
                            cout << "Masukkan detail produk (ketik ulang jika tidak ingin mengubah)" << endl;
                            cout << "Masukkan kategori produk = ";
                            cin >> KategoriProduk;
                            cout << "Masukkan harga produk = ";
                            cin >> HargaProduk;
                            cout << "Masukkan stok produk = ";
                            cin >> StokProduk;
                            HashtableProduk.UpdateProduk(KategoriProduk, NamaProduk, HargaProduk, StokProduk);
                            cout << "Detail produk " << NamaProduk << " berhasil diupdate!" << endl;
                            cout << endl;
                        }
                        else
                        {
                            cout << "Produk tidak ditemukan!" << endl;
                            cout << endl;
                        }
                    }
                    else
                    {
                        cout << "List produk masih kosong!" << endl;
                        cout << "Tambahkan produk terlebih dahulu!" << endl;
                        cout << endl;
                    }
                    break;
                case 3:
                    if (HashtableProduk.isEmpty() == false)
                    {
                        cout << "--- HAPUS PRODUK ---" << endl;
                        cout << "Masukkan nama produk yang ingin dihapus = ";
                        cin.ignore();
                        getline(cin, NamaProduk);
                        if(HashtableProduk.CekNamaProduk(NamaProduk) == true){
                            cout << "Apakah anda yakin ingin menghapus produk " << NamaProduk << "? [y/n] = ";
                            cin >> Yakin;
                            if (Yakin == 'Y' || Yakin == 'y')
                            {
                                HashtableProduk.HapusProduk(NamaProduk);
                                cout << "Produk berhasil dihapus!" << endl;
                                cout << endl;
                            }
                            else if (Yakin == 'N' || Yakin == 'n')
                            {
                                cout << "Aksi dibatalkan!" << endl;
                                cout << endl;
                            }
                        } else {
                            cout << "Produk tidak ditemukan!" << endl;
                            cout << endl;
                        }
                    } else {
                        cout << "List produk masih kosong!" << endl;
                        cout << "Tambahkan produk terlebih dahulu!" << endl;
                        cout << endl;
                    }
                    break;
                case 4:
                    if(HashtableProduk.isEmpty() == false){
                        cout << "--- TAMPILKAN PRODUK ---" << endl;
                        HashtableProduk.TampilProdukAdmin();
                        cout << endl;
                    } else {
                        cout << "List produk masih kosong!" << endl;
                        cout << "Tambahkan produk terlebih dahulu!" << endl;
                        cout << endl;
                    }
                    break;
                case 5:
                    goto MenuLogin;
                    break;
                default:
                    cout << "Pilihan yang anda masukkan tidak valid!" << endl;
                    cout << endl;
                    break;
                }
            } while (PilihanMenuAdmin >= 0);
        }
    }
    else if (PilihanLogin == 1)
    {
    MasukkanUsernameCustomer:
        cout << "Masukkan username anda = ";
        cin >> UsernameCustomer;
    MasukkanPasswordCustomer:
        cout << "Masukkan password = ";
        cin >> PasswordCustomer;
        LoginUserCustomer(UsernameCustomer, PasswordCustomer, PasswordCustomerValid, UsernameCustomerValid);

        if (!PasswordCustomerValid)
        {
            goto MasukkanPasswordCustomer;
        }
        else if (!UsernameCustomerValid)
        {
            goto MasukkanUsernameCustomer;
        }

        
    } else if(PilihanLogin == 3){
        cout << "Apakah anda yakin ingin keluar dari aplikasi? [y/n] = ";
        cin >> Yakin;
        if(Yakin == 'Y' || Yakin == 'y'){
            cout << "Anda keluar dari aplikasi" << endl;
            return 0;
        } else if(Yakin == 'N' || Yakin == 'n'){
            cout << "Aksi dibatalkan" << endl;
            cout << endl;
            goto MenuLogin;
        }

    } else {
        cout << "Pilihan anda tidak valid!" << endl;
        goto MenuLogin;
    }

    return 0;
}