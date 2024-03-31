#include <iostream>
#include <string>
#include <cctype>

using namespace std;
// Nama Pasien
// Nomor rekam medis / identitas yang dapat digunakan
// Alamat lengkap pasien tinggal sdh
// Data kelahiran pasien (tanggal, bulan, tahun, dan kota) sdh
// Jenis gender pasien sdh
// Kontak keluarga terdekat pasien
// string nama_pasien[1000] = {"Muhammad azam", "Raihan fitri", "Vicky Ahmad"},alamat_pasien[1000] = {"Kutai Barat", "Samarinda Sebrang", "Samarinda"},
// tanggal_lahir[1000] = {"21 Mei 2005", "12 Oktober 2004", "29 Februari 2005"},gender_pasien[1000] = {"Laki-Laki", "Laki-Laki", "Laki-Laki"}, tempat_lahir[1000] = {"Kutai Barat", "Samarinda Sebrang", "Samarinda"};
// string gender;
// string choose;
// int nomor_medis_pasien[1000] = {1,2,3},kontak_keluarga[1000] = {234234,45345,235462},

int ukuran = 3;
string gender, choose;

struct kelahiran{ //Nested Struct
    string tanggal_lahir;
    string tempat_lahir;
};

struct pasien{
    string nama_pasien;
    int nomor_medis_pasien;
    string alamat_pasien;
    kelahiran kelahiran_pasien;// Nested struct
    string gender_pasien;
    string kontak_keluarga;
};

int inputInteger(string pesan) {
    int num;
    string input;

    while (true) {
        cout << pesan;
        cin >> input;

        try {
            num = stoi(input);
            break;
        } catch (const invalid_argument& e) {
            cout << "Jangan memasukan nilai selain integer!!!.\n";
        }
    }
    return num;
}

string inputString(string pesan, bool releaseBuff) {
    string hasil;

    if(releaseBuff) {
        fflush(stdin);
    }

    do {
        cout << pesan;
        getline(cin, hasil);

        if(hasil == "") {
            cout << "Input tidak boleh kosong!!!\n";
        } else if(hasil == " "){
            cout << "Input tidak boleh kosong!!!\n";
        }
    } while(hasil == "" || hasil == " ");

    return hasil;
}

pasien data_pasien[1000] = { // Array of struct
    {"Muhammad Shandy", 1, "Kutai Barat", "Kutai Barat","21 Mei 2005","Laki-Laki", "081253342720"},
    {"Raihan fitri", 2 , "Samarinda Sebrang", "Samarinda Sebrang", "12 Oktober 2004", "Laki-Laki", "081263637474" },
    {"Vicky Ahmad", 3, "Samarinda", "Samarinda","29 Februari 2005","Laki-Laki", "081253536464" }
};

string jenis_kelamin(){
    x:
    cout << "Gender Pasien [ L/W ] : ";
    cin >> gender;
    if(gender == "L" || gender == "l"){
        return "Laki - Laki";
    } else if(gender == "W" || gender == "w"){
        return "Wanita";
    } else {
        cout << "Anda Salah Input" << endl;
        goto x;
    }
}

bool login(){
    string nama,nim;
    
    nama  = inputString("NAMA : ", true);
    nim   = inputString("NIM  : ", false);

    if((nama == "Shandy" ) && (nim == "2309106106")){
        return true;
    } else{
        return false;
    }

}

void tambah(){ //Rekursif
    data_pasien[ukuran].nama_pasien                    = inputString("Nama Pasien : ",               true);
    data_pasien[ukuran].nomor_medis_pasien             = inputInteger("Nomor Rekam Medis Pasien : ");
    data_pasien[ukuran].alamat_pasien                  = inputString("Alamat Pasien : ",             true);
    data_pasien[ukuran].kelahiran_pasien.tempat_lahir  = inputString("Tempat Lahir Pasien : ", false);
    data_pasien[ukuran].kelahiran_pasien.tanggal_lahir = inputString("Tanggal Lahir Pasien :",       false);
    data_pasien[ukuran].gender_pasien                  = jenis_kelamin();
    data_pasien[ukuran].kontak_keluarga                = inputString("Kontak Keluarga Pasien : ", true);

    ukuran++;
    p:
    cout << "Apakah ingin menambahkan data pasien lagi [ Y/N ] ? ";
    cin >> choose;
    if (choose == "Y" || choose == "y") {
        tambah();
    } else if (choose == "n" || choose == "N") {
    } else {
        cout << "Anda Salah Input" << endl;
        goto p;
    }
}

// void tampil(){ //Prosedur
//     for(int i = 0; i < ukuran; i++){
//         cout << "Nama Pasien : "               << data_pasien[i].nama_pasien << endl;
//         cout << "Nomor Pasien : "              << data_pasien[i].nomor_medis_pasien << endl;
//         cout << "Alamat Pasien : "             << data_pasien[i].alamat_pasien << endl;
//         cout << "tempat_lahir Lahir Pasien : " << data_pasien[i].kelahiran_pasien.tempat_lahir << endl;
//         cout << "Tanggal Lahir Pasien : "      << data_pasien[i].kelahiran_pasien.tanggal_lahir << endl;
//         cout << "Gender Pasien : "             << data_pasien[i].gender_pasien << endl;
//         cout << "Kontak Keluarga Pasien : "    << data_pasien[i].kontak_keluarga << endl;
//         cout << endl;
//     }
//     system("pause");
// }

void tampilkanDataPasien(pasien *ptr_pasien) {
    cout << "Nama Pasien : " << ptr_pasien->nama_pasien << endl;
    cout << "Nomor Pasien : " << ptr_pasien->nomor_medis_pasien << endl;
    cout << "Alamat Pasien : " << ptr_pasien->alamat_pasien << endl;
    cout << "Tempat Lahir Pasien : " << ptr_pasien->kelahiran_pasien.tempat_lahir << endl;
    cout << "Tanggal Lahir Pasien : " << ptr_pasien->kelahiran_pasien.tanggal_lahir << endl;
    cout << "Gender Pasien : " << ptr_pasien->gender_pasien << endl;
    cout << "Kontak Keluarga Pasien : " << ptr_pasien->kontak_keluarga << endl;
    cout << endl;
}

void tampil(pasien *ptr_data_pasien, int ukuran) {
    for(int i = 0; i < ukuran; i++) {
        tampilkanDataPasien(&ptr_data_pasien[i]);
    }
    system("pause");
}


void ubah(){ //Prosedur
    int cari = inputInteger("Nomor Pasien : ");
    for(int i = 0; i < ukuran; i++){
        if(cari == data_pasien[i].nomor_medis_pasien){
            data_pasien[i].nama_pasien                    = inputString("Nama Pasien : ", true);
            data_pasien[i].nomor_medis_pasien             = inputInteger("Nomor Rekam Medis Pasien : ");
            data_pasien[i].alamat_pasien                  = inputString("Alamat Pasien : ", true);
            data_pasien[i].kelahiran_pasien.tempat_lahir  = inputString("Tempat Lahir Pasien : ", false);
            data_pasien[i].kelahiran_pasien.tanggal_lahir = inputString("Tanggal Lahir Pasien :", false);
            data_pasien[i].gender_pasien                  = jenis_kelamin();
            data_pasien[i].kontak_keluarga                = inputString("Kontak Keluarga Pas1ien : ", true);
            break;
        }
    }
}

void hapus(){//Prosedur
    int hapus = inputInteger("Nomor Pasien : ");
    for(int i = 0; i < ukuran; i++){
        if(hapus == data_pasien[i].nomor_medis_pasien){
            for(int j = i; j < ukuran; j++){
                data_pasien[j].nama_pasien                     = data_pasien[j+1].nama_pasien;
                data_pasien[j].nomor_medis_pasien              = data_pasien[j+1].nomor_medis_pasien;
                data_pasien[j].alamat_pasien                   = data_pasien[j+1].alamat_pasien;
                data_pasien[j].kelahiran_pasien.tempat_lahir   = data_pasien[j+1].kelahiran_pasien.tempat_lahir;
                data_pasien[j].kelahiran_pasien.tanggal_lahir  = data_pasien[j+1].kelahiran_pasien.tanggal_lahir;
                data_pasien[j].gender_pasien                   = data_pasien[j+1].gender_pasien;
                data_pasien[j].kontak_keluarga                 = data_pasien[j+1].kontak_keluarga;
            }
            ukuran -= 1;
        }
    }
}

int main(){
    while(1){
        system("cls");
        cout << "=======================" << endl;
        cout << "::   HALAMAN LOGIN   ::" << endl;
        cout << "=======================" << endl;
        cout << ":: [ 1 ] LOGIN       ::" << endl;
        cout << ":: [ 2 ] KELUAR      ::" << endl;
        cout << "=======================" << endl;

        int tanya = inputInteger("PILIH : ");
        if(tanya == 1){
            for(int i = 0 ; i <= 3 ; i++){
                if(i == 3){
                    exit(1);
                }
                system("cls");
                cout << "=======================" << endl;
                cout << "::   HALAMAN LOGIN   ::" << endl;
                cout << "=======================" << endl;
                if(login()){
                    system("cls");
                    menu:
                    cout << "==================================" << endl;
                    cout << "::           MENU USER          ::" << endl;
                    cout << "==================================" << endl;
                    cout << ":: [ 1 ] MASUKKAN DATA PASIEN   ::" << endl;
                    cout << ":: [ 2 ] TAMPILKAN DATA PASIEN  ::" << endl;
                    cout << ":: [ 3 ] UBAH DATA PASIEN       ::" << endl;
                    cout << ":: [ 4 ] HAPUS DATA PASIEN      ::" << endl;
                    cout << ":: [ 5 ] KELUAR                 ::" << endl;
                    cout << "==================================" << endl;
                    enum opsi{CREATE = 1, READ, UPDATE, DELETE, KELUAR};

                    int pilih = inputInteger("PILIH : ");
                    switch(pilih){
                        case CREATE:
                            tambah();
                            system("cls");
                            goto menu;
                            break;
                        case READ:
                            tampil(data_pasien,ukuran);
                            system("cls");
                            goto menu;
                            break;
                        case UPDATE:
                            ubah();
                            system("cls");
                            goto menu;
                            break;
                        case DELETE:
                            hapus();
                            system("cls");
                            goto menu;
                            break;
                        case KELUAR:
                            break;
                            system("cls");
                        default:
                            cout << "Anda Salah Input" << endl;
                            system("pause");
                            goto menu;
                    }
                }else{
                    cout << "Anda Salah Input" << endl;
                    system("pause");
                    continue;
                }
                break;
            }
        } else if (tanya == 2){
            exit(1);
            system("cls");
        } else {
            cout << "Anda Salah Input" << endl;
            system("pause");
            system("cls");
        }
    }
    return 0;
}