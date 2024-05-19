#include<iostream>
#include<string>

using namespace std;

void LoginUserAdmin(string UsernameAdmin, string PasswordAdmin, int &KesempatanLogin, bool &AdminBerhasilLogin) {
    if (UsernameAdmin == "AdminToko1") {
        if (PasswordAdmin == "AdminPakaian1") {
            cout << "Anda login sebagai AdminToko1" << endl;
            AdminBerhasilLogin = true;
        } else {
            cout << "Password yang anda masukkan salah!" << endl;
            KesempatanLogin--;
        }
    } else if (UsernameAdmin == "AdminToko2") {
        if (PasswordAdmin == "AdminPakaian2") {
            cout << "Anda login sebagai AdminToko2" << endl;
            AdminBerhasilLogin = true;
        } else {
            cout << "Password yang anda masukkan salah!" << endl;
            KesempatanLogin--;
        }
    } else {
        cout << "Username tidak terdaftar!" << endl;
        cout << "Silahkan masukkan username kembali" << endl;
        KesempatanLogin--;
    }
}

void LoginUserCustomer(string UsernameCustomer, string PasswordCustomer, bool &CustomerBerhasilLogin) {
    if (UsernameCustomer == "Joshua") {
        if (PasswordCustomer == "2311102133") {
            cout << "Selamat datang Joshua!" << endl;
            CustomerBerhasilLogin = true;
        } else {
            cout << "Password yang anda masukkan salah!" << endl;
        }
    } else if (UsernameCustomer == "Nanda") {
        if (PasswordCustomer == "2311102147") {
            cout << "Selamat datang Nanda!" << endl;
            CustomerBerhasilLogin = true;
        } else {
            cout << "Password yang anda masukkan salah!" << endl;
        }
    } else if (UsernameCustomer == "Dhimas") {
        if (PasswordCustomer == "2311102151") {
            cout << "Selamat datang Dhimas!" << endl;
            CustomerBerhasilLogin = true;
        } else {
            cout << "Password yang anda masukkan salah!" << endl;
        }
    } else {
        cout << "Username anda tidak terdaftar" << endl;
    }
}

int main() {
    int PilihanLogin;
    string UsernameAdmin, PasswordAdmin;
    string UsernameCustomer, PasswordCustomer;
    int KesempatanLogin = 3;
    bool AdminBerhasilLogin = false;
    bool CustomerBerhasilLogin = false;

    cout << "----- TOKO PAKAIAN [.....] -----" << endl;
    cout << "Menjual ..., ..., ..., ..." << endl;
    cout << endl;
    cout << "Login sebagai : " << endl;
    cout << "1. Customer" << endl;
    cout << "2. Admin" << endl;
    cout << "Pilihan anda [1/2] = ";
    cin >> PilihanLogin;
    cout << endl;

    if (PilihanLogin == 2) {
        while (KesempatanLogin > 0 && !AdminBerhasilLogin) {
            cout << "Masukkan username = ";
            cin >> UsernameAdmin;
            cout << "Masukkan password = ";
            cin >> PasswordAdmin;
            LoginUserAdmin(UsernameAdmin, PasswordAdmin, KesempatanLogin, AdminBerhasilLogin);
            if (!AdminBerhasilLogin) {
                if (KesempatanLogin > 0) {
                    cout << "Tersisa " << KesempatanLogin << " kesempatan untuk login kembali." << endl;
                } else {
                    cout << "Anda telah gagal 3 kali untuk login sebagai admin." << endl;
                    cout << "Silahkan buka ulang aplikasi." << endl;
                    return 0;
                }
            }
        }
    } else if (PilihanLogin == 1) {
        while (!CustomerBerhasilLogin) {
            cout << "Masukkan username anda = ";
            cin >> UsernameCustomer;
            cout << "Masukkan password = ";
            cin >> PasswordCustomer;
            LoginUserCustomer(UsernameCustomer, PasswordCustomer, CustomerBerhasilLogin);
            if (!CustomerBerhasilLogin) {
                cout << "Username atau password salah, silahkan coba lagi." << endl;
            }
        }
    }

    return 0;
}
