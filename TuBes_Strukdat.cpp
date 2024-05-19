#include<iostream>
#include<string>

using namespace std;

bool LoginUserAdmin(string UsernameAdmin, string PasswordAdmin, bool &PasswordValid, bool &UsernameValid) {
    UsernameValid = true;
    PasswordValid = true;
    if (UsernameAdmin == "AdminToko1") {
        if (PasswordAdmin == "AdminPakaian1") {
            cout << "Anda login sebagai AdminToko1" << endl;
        } else {
            cout << "Password yang anda masukkan salah!" << endl;
            PasswordValid = false;
        }
    } else if (UsernameAdmin == "AdminToko2") {
        if (PasswordAdmin == "AdminPakaian2") {
            cout << "Anda login sebagai AdminToko2" << endl;
        } else {
            cout << "Password yang anda masukkan salah!" << endl;
            PasswordValid = false;
        }
    } else {
        cout << "Username tidak terdaftar!" << endl;
        UsernameValid = false;
    }
    return UsernameValid && PasswordValid;
}

bool LoginUserCustomer(string UsernameCustomer, string PasswordCustomer, bool &PasswordValid, bool &UsernameValid) {
    UsernameValid = true;
    PasswordValid = true;
    if (UsernameCustomer == "Joshua") {
        if (PasswordCustomer == "2311102133") {
            cout << "Selamat datang Joshua!" << endl;
        } else {
            cout << "Password yang anda masukkan salah!" << endl;
            PasswordValid = false;
        }
    } else if (UsernameCustomer == "Nanda") {
        if (PasswordCustomer == "2311102147") {
            cout << "Selamat datang Nanda!" << endl;
        } else {
            cout << "Password yang anda masukkan salah!" << endl;
            PasswordValid = false;
        }
    } else if (UsernameCustomer == "Dhimas") {
        if (PasswordCustomer == "2311102151") {
            cout << "Selamat datang Dhimas!" << endl;
        } else {
            cout << "Password yang anda masukkan salah!" << endl;
            PasswordValid = false;
        }
    } else {
        cout << "Username anda tidak terdaftar" << endl;
        UsernameValid = false;
    }
    return UsernameValid && PasswordValid;
}

int main() {
    int PilihanLogin, i;
    string UsernameAdmin, PasswordAdmin;
    string UsernameCustomer, PasswordCustomer;
    bool UsernameValid = true;
    bool PasswordValid = true;
    
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
        MasukkanUsernameAdmin:
        cout << "Masukkan username = ";
        cin >> UsernameAdmin;
        MasukkanPasswordAdmin:
        cout << "Masukkan password = ";
        cin >> PasswordAdmin;
        LoginUserAdmin(UsernameAdmin, PasswordAdmin, PasswordValid, UsernameValid);
        
        if (!PasswordValid) {
            for (i = 2; i > 0; i--) {
                cout << "Tersisa " << i << " kesempatan untuk login kembali" << endl;
                goto MasukkanPasswordAdmin;
            }
            if (i == 0) {
                cout << "Anda telah gagal 3 kali untuk login sebagai admin" << endl;
                cout << "Silahkan buka ulang aplikasi" << endl;
                return 0;
            }
        } else if (!UsernameValid) {
            goto MasukkanUsernameAdmin;
        }
    } else if (PilihanLogin == 1) { 
        MasukkanUsernameCustomer:
        cout << "Masukkan username anda = ";
        cin >> UsernameCustomer;
        MasukkanPasswordCustomer:
        cout << "Masukkan password = ";
        cin >> PasswordCustomer;
        LoginUserCustomer(UsernameCustomer, PasswordCustomer, PasswordValid, UsernameValid);
        
        if (!PasswordValid) {
            goto MasukkanPasswordCustomer;
        } else if (!UsernameValid) {
            goto MasukkanUsernameCustomer;
        }
    }

    return 0;
}